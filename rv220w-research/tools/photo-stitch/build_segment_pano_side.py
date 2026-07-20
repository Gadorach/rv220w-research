from PIL import Image,ImageOps
import cv2,numpy as np,os,json,sys
src='/mnt/data/rv220w_photos';work='/mnt/data/rv220w_stitch';os.makedirs(work,exist_ok=True)
side,name,a,b,r=sys.argv[1],sys.argv[2],int(sys.argv[3]),int(sys.argv[4]),float(sys.argv[5])
adj=json.load(open(work+f'/{side}_adjacent.json'));files=adj['files'];sold=adj['scale'];E={e['from_index']:e for e in adj['edges'] if 'H_scaled' in e}
def efull(i):
 e=E[i];S=np.diag([sold,sold,1.]);return np.linalg.inv(S)@np.array(e['H_scaled'])@S
def load(f):return np.array(ImageOps.exif_transpose(Image.open(os.path.join(src,f))).convert('RGB'))
P={a:np.eye(3)}
for i in range(a+1,b+1):P[i]=P[i-1]@efull(i)
allc=[]
for i in range(a,b+1):
 im=load(files[i]);h,w=im.shape[:2];c=np.float32([[0,0],[w,0],[w,h],[0,h]]).reshape(-1,1,2);allc.append(cv2.perspectiveTransform(c,P[i]).reshape(-1,2))
allc=np.vstack(allc);mn=allc.min(0);mx=allc.max(0);margin=100;T=np.array([[1,0,-mn[0]+margin],[0,1,-mn[1]+margin],[0,0,1.]],float)
W=int(np.ceil((mx[0]-mn[0]+2*margin)*r));H=int(np.ceil((mx[1]-mn[1]+2*margin)*r));print('canvas',W,H,flush=True)
canvas=np.zeros((H,W,3),np.float32);weight=np.zeros((H,W),np.float32);Sr=np.diag([r,r,1.]);iSr=np.linalg.inv(Sr)
for i in range(a,b+1):
 im=load(files[i]);ims=cv2.resize(im,(0,0),fx=r,fy=r,interpolation=cv2.INTER_AREA);M=Sr@T@P[i]@iSr
 wim=cv2.warpPerspective(ims,M,(W,H));mask=cv2.warpPerspective(np.ones(ims.shape[:2],np.uint8)*255,M,(W,H),flags=cv2.INTER_NEAREST)
 dist=cv2.distanceTransform((mask>0).astype(np.uint8),cv2.DIST_L2,5);alpha=np.clip(dist/40,0,1).astype(np.float32);sel=alpha>0
 canvas[sel]=(canvas[sel]*weight[sel,None]+wim[sel].astype(np.float32)*alpha[sel,None])/(weight[sel,None]+alpha[sel,None]+1e-6);weight[sel]+=alpha[sel]
out=np.clip(canvas,0,255).astype(np.uint8);Image.fromarray(out).save(work+f'/{name}_pano.png');Image.fromarray((weight>0).astype(np.uint8)*255).save(work+f'/{name}_mask.png');np.save(work+f'/{name}_T.npy',T);json.dump({'side':side,'name':name,'a':a,'b':b,'r':r,'files':[files[i] for i in range(a,b+1)]},open(work+f'/{name}.json','w'),indent=2)

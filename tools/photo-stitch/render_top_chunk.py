from PIL import Image,ImageOps
import cv2,numpy as np,os,json,sys
src='/mnt/data/rv220w_photos';work='/mnt/data/rv220w_stitch'
chunk=sys.argv[1]
allsegments=[('topA',0,4),('topB',5,9),('topC',10,20),('topD1',21,24),('topD2',25,29),('topD3',30,35),('topE',36,38),('topF',39,40),('topG',41,44)]
ranges={'AB':(0,2),'C':(2,3),'D':(3,6),'EFG':(6,9)}
sa,sb=ranges[chunk];segments=allsegments[sa:sb]
adj=json.load(open(work+'/top_adjacent.json'));files=adj['files'];sold=adj['scale'];E={e['from_index']:e for e in adj['edges'] if 'H_scaled' in e}
def e_full(i):
 e=E[i];S=np.diag([sold,sold,1.]);return np.linalg.inv(S)@np.array(e['H_scaled'])@S
def load(f):return np.array(ImageOps.exif_transpose(Image.open(os.path.join(src,f))).convert('RGB'))
src_quad=np.float32([[570,470],[3500,470],[3510,2870],[480,2870]])
out_w,out_h=7000,5600;dst_quad=np.float32([[180,180],[6820,180],[6820,5420],[180,5420]])
R=cv2.getPerspectiveTransform(src_quad,dst_quad)
prev={'AB':None,'C':'logic_top_stage_AB.png','D':'logic_top_stage_C.png','EFG':'logic_top_stage_D.png'}[chunk]
if prev:
 comp=np.array(Image.open(work+'/'+prev).convert('RGB')).astype(np.float32)
else:
 base=load('IMG_20260719_194149.jpg');comp=cv2.warpPerspective(base,R,(out_w,out_h),flags=cv2.INTER_CUBIC,borderValue=(245,245,245)).astype(np.float32)
valid=np.zeros((out_h,out_w),np.uint8);cv2.fillConvexPoly(valid,dst_quad.astype(np.int32),255)
alpha_cache={}
for name,a,b in segments:
 meta=json.load(open(work+f'/{name}.json'));r=meta['r'];T=np.load(work+f'/{name}_T.npy');Hp=np.load(work+f'/{name}_H_pano_base.npy')
 P={a:np.eye(3)}
 for i in range(a+1,b+1):P[i]=P[i-1]@e_full(i)
 Sr=np.diag([r,r,1.])
 for i in range(a,b+1):
  im=load(files[i]);h,w=im.shape[:2]
  if (h,w) not in alpha_cache:
   yy=np.minimum(np.arange(h),np.arange(h)[::-1])[:,None];xx=np.minimum(np.arange(w),np.arange(w)[::-1])[None,:]
   alpha_cache[(h,w)]=np.clip(np.minimum(yy,xx)/180.0,0,1).astype(np.float32)
  Hfinal=R@(Hp@Sr@T@P[i]);corners=np.float32([[0,0],[w,0],[w,h],[0,h]]).reshape(-1,1,2);tc=cv2.perspectiveTransform(corners,Hfinal).reshape(-1,2)
  x0=max(0,int(np.floor(tc[:,0].min()))-3);x1=min(out_w,int(np.ceil(tc[:,0].max()))+3);y0=max(0,int(np.floor(tc[:,1].min()))-3);y1=min(out_h,int(np.ceil(tc[:,1].max()))+3)
  if x1<=x0 or y1<=y0:continue
  L=np.array([[1,0,-x0],[0,1,-y0],[0,0,1.]],float)@Hfinal
  warped=cv2.warpPerspective(im,L,(x1-x0,y1-y0),flags=cv2.INTER_LINEAR,borderValue=0);aw=cv2.warpPerspective(alpha_cache[(h,w)],L,(x1-x0,y1-y0),flags=cv2.INTER_LINEAR,borderValue=0);aw*=valid[y0:y1,x0:x1].astype(np.float32)/255.0
  sel=aw>0.01;region=comp[y0:y1,x0:x1];region[sel]=region[sel]*(1-aw[sel,None])+warped[sel].astype(np.float32)*aw[sel,None];comp[y0:y1,x0:x1]=region
  print(chunk,name,i,flush=True)
out=np.clip(comp,0,255).astype(np.uint8)
outname={'AB':'logic_top_stage_AB.png','C':'logic_top_stage_C.png','D':'logic_top_stage_D.png','EFG':'logic_top_stitched_rectified.png'}[chunk]
Image.fromarray(out).save(work+'/'+outname,compress_level=1)
if chunk=='EFG':Image.fromarray(out).resize((1750,1400),Image.Resampling.LANCZOS).save(work+'/logic_top_stitched_rectified_preview.jpg',quality=92)
print('saved',outname)

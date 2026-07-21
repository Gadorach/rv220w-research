from PIL import Image
import cv2,numpy as np,os,sys,json
work='/mnt/data/rv220w_stitch';src='/mnt/data/rv220w_photos'
name=sys.argv[1]; x0,y0,x1,y1=map(int,sys.argv[2:6])
pano=np.array(Image.open(work+f'/{name}_pano.png').convert('RGB'));mask=np.array(Image.open(work+f'/{name}_mask.png'))
base=np.array(Image.open(src+'/IMG_20260719_194149.jpg').convert('RGB'));crop=base[y0:y1,x0:x1]
sift=cv2.SIFT_create(nfeatures=12000,contrastThreshold=.003,edgeThreshold=30)
kp,dp=sift.detectAndCompute(cv2.cvtColor(pano,cv2.COLOR_RGB2GRAY),mask)
kc,dc=sift.detectAndCompute(cv2.cvtColor(crop,cv2.COLOR_RGB2GRAY),None)
good=[m for m,n in cv2.BFMatcher().knnMatch(dp,dc,k=2) if m.distance<.72*n.distance]
sp=np.float32([kp[m.queryIdx].pt for m in good]).reshape(-1,1,2);dd=np.float32([kc[m.trainIdx].pt for m in good]).reshape(-1,1,2)
A,am=cv2.estimateAffinePartial2D(sp,dd,method=cv2.RANSAC,ransacReprojThreshold=4,maxIters=50000,confidence=.999,refineIters=100)
if A is None: raise RuntimeError('affine failed')
sel=am.ravel()>0
H,hm=cv2.findHomography(sp[sel],dd[sel],cv2.RANSAC,3.5)
if H is None: H=np.vstack([A,[0,0,1.]])
T=np.array([[1,0,x0],[0,1,y0],[0,0,1.]],float);Hb=T@H
w=cv2.warpPerspective(pano,Hb,(base.shape[1],base.shape[0]));wm=cv2.warpPerspective(mask,Hb,(base.shape[1],base.shape[0]));ov=base.copy();s=wm>0;ov[s]=(ov[s]*.5+w[s]*.5).astype(np.uint8)
Image.fromarray(ov).save(work+f'/{name}_align_preview.jpg',quality=93);np.save(work+f'/{name}_H_pano_base.npy',Hb)
json.dump({'name':name,'roi':[x0,y0,x1,y1],'features':[len(kp),len(kc)],'good':len(good),'affine_inliers':int(sel.sum()),'homography_inliers':int(hm.sum()) if hm is not None else 0},open(work+f'/{name}_align.json','w'),indent=2)
print(name,'good',len(good),'aff',int(sel.sum()),'hom',int(hm.sum()) if hm is not None else 0)

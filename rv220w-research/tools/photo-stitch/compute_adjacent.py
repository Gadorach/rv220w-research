from PIL import Image,ImageOps
import cv2,numpy as np,os,json,sys
src='/mnt/data/rv220w_photos'; out='/mnt/data/rv220w_stitch'; os.makedirs(out,exist_ok=True)
side=sys.argv[1]
if side=='top': files=sorted([f for f in os.listdir(src) if f.endswith('.jpg') and f>='IMG_20260719_194500.jpg'])
elif side=='bottom': files=sorted([f for f in os.listdir(src) if f.endswith('.jpg') and 'IMG_20260719_194339.jpg'<=f<='IMG_20260719_194445.jpg'])
else: raise SystemExit()
scale=.18
orb=cv2.ORB_create(5000, fastThreshold=7)
matcher=cv2.BFMatcher(cv2.NORM_HAMMING)
features=[]
for f in files:
 im=np.array(ImageOps.exif_transpose(Image.open(os.path.join(src,f))).convert('RGB'))
 sm=cv2.resize(im,(0,0),fx=scale,fy=scale)
 kp,des=orb.detectAndCompute(cv2.cvtColor(sm,cv2.COLOR_RGB2GRAY),None)
 features.append((kp,des,list(im.shape[:2])))
res=[]
for i in range(1,len(files)):
 ka,da,_=features[i-1]; kb,db,_=features[i]
 good=[] if db is None or da is None else [m for m,n in matcher.knnMatch(db,da,k=2) if m.distance<.78*n.distance]
 e={'from':files[i],'to':files[i-1],'good':len(good),'from_index':i,'to_index':i-1}
 if len(good)>=10:
  sp=np.float32([kb[m.queryIdx].pt for m in good]).reshape(-1,1,2)
  dp=np.float32([ka[m.trainIdx].pt for m in good]).reshape(-1,1,2)
  H,mask=cv2.findHomography(sp,dp,cv2.RANSAC,4.0)
  if H is not None and mask is not None:
   e['inliers']=int(mask.sum()); e['H_scaled']=H.tolist()
 res.append(e); print(i,files[i-1],'<-',files[i],len(good),e.get('inliers',0),flush=True)
json.dump({'side':side,'scale':scale,'files':files,'edges':res},open(os.path.join(out,f'{side}_adjacent.json'),'w'),indent=2)

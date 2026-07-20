from PIL import Image,ImageOps
import cv2,numpy as np,os
src='/mnt/data/rv220w_photos';work='/mnt/data/rv220w_stitch'
def load(f):return np.array(ImageOps.exif_transpose(Image.open(os.path.join(src,f))).convert('RGB'))
def align_to_base(base,im,scale=.25):
 sift=cv2.SIFT_create(nfeatures=7000,contrastThreshold=.005,edgeThreshold=25)
 bs=cv2.resize(base,(0,0),fx=scale,fy=scale);ims=cv2.resize(im,(0,0),fx=scale,fy=scale)
 kb,db=sift.detectAndCompute(cv2.cvtColor(bs,cv2.COLOR_RGB2GRAY),None);ki,di=sift.detectAndCompute(cv2.cvtColor(ims,cv2.COLOR_RGB2GRAY),None)
 good=[m for m,n in cv2.BFMatcher().knnMatch(di,db,k=2) if m.distance<.75*n.distance]
 sp=np.float32([ki[m.queryIdx].pt for m in good]).reshape(-1,1,2);dp=np.float32([kb[m.trainIdx].pt for m in good]).reshape(-1,1,2)
 H,mask=cv2.findHomography(sp,dp,cv2.RANSAC,3.5);print('good',len(good),'in',int(mask.sum()))
 S=np.diag([scale,scale,1.]);return np.linalg.inv(S)@H@S
def render(group,base_file,files,src_quad,dst_quad,size,outname):
 base=load(base_file);R=cv2.getPerspectiveTransform(np.float32(src_quad),np.float32(dst_quad));comp=cv2.warpPerspective(base,R,size,flags=cv2.INTER_CUBIC,borderValue=(245,245,245)).astype(np.float32)
 for f in files:
  if f==base_file:continue
  im=load(f);H=align_to_base(base,im);M=R@H;h,w=im.shape[:2]
  yy=np.minimum(np.arange(h),np.arange(h)[::-1])[:,None];xx=np.minimum(np.arange(w),np.arange(w)[::-1])[None,:];a=np.clip(np.minimum(yy,xx)/180.,0,1).astype(np.float32)
  wi=cv2.warpPerspective(im,M,size,flags=cv2.INTER_LINEAR,borderValue=0);aw=cv2.warpPerspective(a,M,size,flags=cv2.INTER_LINEAR,borderValue=0);sel=aw>0.01;comp[sel]=comp[sel]*(1-aw[sel,None])+wi[sel].astype(np.float32)*aw[sel,None]
 out=np.clip(comp,0,255).astype(np.uint8);Image.fromarray(out).save(work+'/'+outname,compress_level=1);Image.fromarray(out).resize((1250,875),Image.Resampling.LANCZOS).save(work+'/'+outname.replace('.png','_preview.jpg'),quality=92)
# top
render('top','IMG_20260719_194127.jpg',['IMG_20260719_194127.jpg','IMG_20260719_194130.jpg','IMG_20260719_194130~2.jpg'],
       [[560,900],[2700,900],[2700,2550],[560,2550]],[[120,120],[4880,120],[4880,3380],[120,3380]],(5000,3500),'wifi_top_stitched_rectified.png')
# bottom rotate CCW to same orientation as top
TL=[120,120];TR=[4880,120];BR=[4880,3380];BL=[120,3380]
render('bottom','IMG_20260719_194325.jpg',['IMG_20260719_194319.jpg','IMG_20260719_194320.jpg','IMG_20260719_194325.jpg','IMG_20260719_194326.jpg'],
       [[650,450],[2350,450],[2350,2700],[650,2700]],[BL,TL,TR,BR],(5000,3500),'wifi_bottom_stitched_rectified.png')

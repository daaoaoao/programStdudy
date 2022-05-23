# 图片格式转换, Jpg转Png

# 方法①
from PIL import Image

img = Image.open('test.jpg')
img.save('test1.png')


# 方法②

# from cv2 import imread, imwrite

# image = imread("test.jpg", 1)
# imwrite("test2.png", image)
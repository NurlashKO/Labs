import urllib
import io
from PIL import Image

def imageURL(URL):
    print(URL)
    fd = urllib.request.urlopen(URL)
    image_file = io.BytesIO(fd.read())
    im = Image.open(image_file)
    im.show()

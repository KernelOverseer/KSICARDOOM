from PIL import Image
import sys
#im = Image.open(input("enter image path : ")) # Can be many different formats.
#outfile = open(input("enter output texture : "), "wb")
im = Image.open(sys.argv[1]);
im = im.convert("RGBA")
pix = im.load()
print (im.size)  # Get the width and hight of the image for iterating over
outfile = open(sys.argv[2], "wb");
outfile.write((im.size[0]).to_bytes(4, byteorder="little"));
outfile.write((im.size[1]).to_bytes(4, byteorder="little"));
print (pix[0,0]);
for y in range(im.size[1]):
    for x in range(im.size[0]):
        outfile.write((pix[x,y][2]).to_bytes(1, byteorder="little"));
        outfile.write((pix[x,y][1]).to_bytes(1, byteorder="little"));
        outfile.write((pix[x,y][0]).to_bytes(1, byteorder="little"));
        outfile.write((pix[x,y][3]).to_bytes(1, byteorder="little"));

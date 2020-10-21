import re
fname= input('Enter file name: ')
fhand=open(fname)
x=list()
for line in fhand:
    y= re.findall('[0-9]+',line)
    x=y+x

sum=0
for z in x:
    sum = sum + int(z)

print(sum)

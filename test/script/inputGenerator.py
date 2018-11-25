#!/bin/python3

FCNAME="./common/cmd.txt"
FPNAME="./common/cmdpy.txt"
ENDMSG="Q"
MAX_X=127
MAX_Y=127
MAX_XD=MAX_X
MAX_YD=MAX_Y
import random
import string

def noiseGenerator(out):
    time=random.randint(0,MAX_X)
    i=0
    while i < time:
        char=random.choice(string.printable)
        if char != 'Q':
            out.write(char)
        i+=1

x = int(input('How many command do you want to create?'))
a=0
cmd= None
f=open(FCNAME,"w")
fp=open(FPNAME,"w")
while a < x :
    func=random.randint(0,2)
    mode=random.randint(0,2)
    x1=random.randint(0,MAX_X)
    y1=random.randint(0,MAX_Y)
    if func == 0 :
        cmd='P'+('{0:03d}'.format(x1))+('{0:03d}'.format(y1))+str(mode)+'\n'
    elif func == 1 :
        x2=random.randint(0,MAX_X)
        y2=random.randint(0,MAX_Y)
        cmd='L'+('{0:03d}'.format(x1))+('{0:03d}'.format(y1))+('{0:03d}'.format(x2))+('{0:03d}'.format(y2))+str(mode)+'\n'
    elif func == 2 :
        xd=random.randint(1,MAX_XD)
        yd=random.randint(1,MAX_YD)
        cmd='E'+('{0:03d}'.format(x1))+('{0:03d}'.format(y1))+('{0:03d}'.format(xd))+('{0:03d}'.format(yd))+str(mode)+'\n'
    f.write(cmd)
    fp.write(cmd)
    noise=random.randint(0,2)
    if noise == 0:
        noiseGenerator(f)
    a+=1
f.write(ENDMSG)
fp.write(ENDMSG)
f.close
fp.close
    

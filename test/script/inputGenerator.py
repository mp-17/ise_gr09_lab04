#!/bin/python3

FNAME="./common/cmd.txt"
ENDMSG="Q"
MAX_X=127
MAX_Y=127
MAX_XD=MAX_X
MAX_YD=MAX_Y
import random

x = int(input('How many command do you want to create?'))
a=0
cmd= None
f=open(FNAME,"w")
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
        xd=random.randint(0,MAX_XD)
        yd=random.randint(0,MAX_YD)
        cmd='E'+('{0:03d}'.format(x1))+('{0:03d}'.format(y1))+('{0:03d}'.format(xd))+('{0:03d}'.format(yd))+str(mode)+'\n'
    f.write(cmd)    
    a+=1
f.write(ENDMSG)
f.close
    

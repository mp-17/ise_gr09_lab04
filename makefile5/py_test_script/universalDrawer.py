#!/bin/python
MDIM=127
CMDFILE="common/cmd.txt"
frameBuffer=[[0 for x in range(MDIM)] for y in range(MDIM)]
FILE.open(CMDFILE)
for line in FILE:
    if line[0] == 'P':
        x1=100*int(line[1])+10*int(line[2])+int(line[3])
        y1=100*int(line[4])+10*int(line[5])+int(line[6])
        mode=int(line[7])
        if mode==0:
            frameBuffer[y1][x1]=0
        elif mode==1:
            frameBuffer[y1][x1]=1
        elif mode==2:
            if frameBuffer[y1][x1]==1:
                frameBuffer[y1][x1]=0
            else:
                frameBuffer[y1][x1]=1
                
    elif line[0] == 'L':

    elif line[0] == 'E':


#!/bin/python
MDIM=128
rowsFrame=128
CMDFILE="common/cmd.txt"
OUTFILE="common/py_matrix.txt"
frameBuffer=[[0 for x in range(MDIM)] for y in range(MDIM)]
FILEC=open(CMDFILE,"r")

def drawPoint(x1,y1,mode):
    row=127-y1
    if mode==0:
        frameBuffer[row][x1]=0
    elif mode==1:
        frameBuffer[row][x1]=1
    elif mode==2:
        if frameBuffer[row][x1]==1:
            frameBuffer[row][x1]=0
        else:
            frameBuffer[row][x1]=1


for line in FILEC:
    if line[0] == 'P':
        x1=100*int(line[1])+10*int(line[2])+int(line[3])
        y1=100*int(line[4])+10*int(line[5])+int(line[6])
        mode=int(line[7])
        drawPoint(x1,y1,mode)  
    elif line[0] == 'L':
        x1=100*int(line[1])+10*int(line[2])+int(line[3])
        y1=100*int(line[4])+10*int(line[5])+int(line[6])
        x2=100*int(line[7])+10*int(line[8])+int(line[9])
        y2=100*int(line[10])+10*int(line[11])+int(line[12])
        mode=int(line[13])
        #algorithm
        dj=abs(x2-x1)
        di=abs(y2-y1)
        eps=di-dj
        if x1 > x2:
            maxX=x1
            j=x2
            i=y2
            startPoint=2
        else:
            maxX=x2
            j=x1
            i=y1
            startPoint=1
        while j < (maxX+1):
            drawPoint(j,i,mode)
            if eps >= 0:
                if startPoint == 1:
                    if y1 > y2:
                        i-=1
                    else:
                        i+=1
                else:
                    if y2 > y1:
                        i-=1
                    else:
                        i+=1
                eps-=dj
            j+=1
            eps+=di
    elif line[0] == 'E':
        xc=100*int(line[1])+10*int(line[2])+int(line[3])
        yc=100*int(line[4])+10*int(line[5])+int(line[6])
        dx=100*int(line[7])+10*int(line[8])+int(line[9])
        dy=100*int(line[10])+10*int(line[11])+int(line[12])
        m=int(line[13])
        #algorithm -start
        #--vertical part
        x=0
        y=dx//2
        sigma = 2*(dx//2 * dx//2)+(dy//2 * dy//2)*(1-2*dx//2)
        while (dx//2 * dx//2)*x <= (dy//2 * dy//2)*y :
            if ((rowsFrame-1-yc+x)>=0 and (rowsFrame-1-yc+x)<=rowsFrame-1):
                if ((xc+y)>=0 and (xc+y)<=rowsFrame-1):
                    if ((yc+x) != (yc-x)):
                        drawPoint(xc+y, yc-x, m)
            if ((rowsFrame-1-yc-x)>=0 and (rowsFrame-1-yc-x)<=rowsFrame-1):
                if ((xc+y)>=0 and (xc+y)<=rowsFrame-1):
                    drawPoint(xc+y, yc+x, m)
            if ((rowsFrame-1-yc+x)>=0 and (rowsFrame-1-yc+x)<=rowsFrame-1):
                if ((xc-y)>=0 and (xc-y)<=rowsFrame-1):
                    if ((yc-x) != (yc+x)):
                        drawPoint(xc-y, yc-x, m)
            if ((rowsFrame-1-yc-x)>=0 and (rowsFrame-1-yc-x)<=rowsFrame-1):
                if ((xc-y)>=0 and (xc-y)<=rowsFrame-1):
                    drawPoint(xc-y, yc+x, m)
            x_last = x
            y_last = y
            if (sigma >= 0):
                sigma += 4 * (dy//2 * dy//2) * (1 - y)
                y=y-1
            sigma += (dx//2 * dx//2) * ((4 * x) + 6)
            x=x+1
        #---horizontal part
        x=dy//2
        y=0
        sigma = 2*(dy//2 * dy//2)+(dx//2 * dx//2)*(1-2*dy//2)
        while (dy//2 * dy//2)*y <= (dx//2 * dx//2)*x :
            if (x!=x_last or y!=y_last):
                if ((rowsFrame-1-yc+x)>=0 and (rowsFrame-1-yc+x)<=rowsFrame-1):
                    if ((xc+y)>=0 and (xc+y)<=rowsFrame-1):
                        if ((xc+y) != (xc-y)):
                            drawPoint(xc+y, yc-x, m)
                if ((rowsFrame-1-yc-x)>=0 and (rowsFrame-1-yc-x)<=rowsFrame-1):
                    if ((xc+y)>=0 and (xc+y)<=rowsFrame-1):
                        if ((xc+y) != (xc-y)):
                            drawPoint(xc+y, yc+x, m)
                if ((rowsFrame-1-yc+x)>=0 and (rowsFrame-1-yc+x)<=rowsFrame-1):
                    if ((xc-y)>=0 and (xc-y)<=rowsFrame-1):
                        drawPoint(xc-y, yc-x, m)
                if ((rowsFrame-1-yc-x)>=0 and (rowsFrame-1-yc-x)<=rowsFrame-1):
                    if ((xc-y)>=0 and (xc-y)<=rowsFrame-1):
                        drawPoint(xc-y, yc+x, m)
            if (sigma >= 0):
                sigma += 4 * (dx//2 * dx//2) * (1 - x)
                x=x-1
            sigma += (dy//2 * dy//2) * ((4 * y) + 6)
            y=y+1
        #algorithm -end
    elif line[0] == 'Q':
        FILEO=open(OUTFILE,"w")
        for row in range(MDIM):
            for coloumn in range(MDIM):
                FILEO.write(str(frameBuffer[row][coloumn]))
            FILEO.write("\n")
        FILEO.close()
FILEC.close()

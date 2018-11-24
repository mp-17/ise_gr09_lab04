#!/bin/bash


DIR_COMMANDSFILE='./common/cmd.txt'
PATH_EXE='../ciao'
MAIN_OUT_FILE='./outmain'
KNOWN_OUT='./knowout'
DIR_UNIVERSALDRAWER_PYTHON='./universalDrawer.py'
DIR_COMMANDSGENERATOR_PYTHON='./inputGenerator.py'

python3 $DIR_COMMANDSGENERATOR_PYTHON
while read command
do
    var1=$var1$command
done < $DIR_COMMANDSFILE
python3 $DIR_UNIVERSALDRAWER_PYTHON
echo $var1 #| ./$PATH_EXE
#diff -s $MAIN_OUT_FILE $KNOWN_OUT

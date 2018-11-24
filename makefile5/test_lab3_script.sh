#!/bin/bash


DIR_COMMANDSFILE='./file_commands.txt'
PATH_EXE='../ciao'
MAIN_OUT_FILE='./outmain'
KNOWN_OUT='./knowout'
DIR_UNIVERSALDRAWER_PYTHON='./py_test_script/universalDrawer.py'

while read command
do
    var1=$var1$command
done < $DIR_COMMANDSFILE
python $DIR_UNIVERSALDRAWER_PYTHON
echo $var1 #| ./$PATH_EXE
#diff -s $MAIN_OUT_FILE $KNOWN_OUT

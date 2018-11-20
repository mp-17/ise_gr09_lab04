#include <stdio.h>
#include "read.h"
#include "draw.h"

// main drawOnCmd function
// it instantiates a location in memory for cmdStruct, in which each command is stored.
// readChar() reads from the peripheral interface, the cmdBuffer is updated 
// and readCommand() decodes the command and updates cmdStruct if the command is valid.
// three different functions can draw a point, a line or an ellipsis in a 128 bits x 128 bits memory.
// there is a special command to quit the program.
// main returns 0 if no errors occured, otherwise it returns 1

int main(int argc, char** argv)
{
	// variable definitions
	basicCmd cmdStruct;

	// memory and buffer array have already been reset because they are global variable 

	// main reading loop
	while (1) {
		// if there is a valid command in the buffer, execute it. Otherwise, loop
		if ( readCommand(&cmdStruct) ) {
			switch (cmdStruct.cmd) {
		  	case POINT:
		  		drawPoint(cmdStruct.x1, cmdStruct.y1, cmdStruct.m);
		  	break;
		  	case LINE:
		  		drawLine(cmdStruct.x1, cmdStruct.y1, cmdStruct.x2, cmdStruct.y2, cmdStruct.m);
		  	break;
		  	case ELLIPSE:
		  		drawEllipse(cmdStruct.x1, cmdStruct.y1, cmdStruct.dx, cmdStruct.dy, cmdStruct.m);
		  	break;
		  	default:
		  		// error: the readCommand has returned a boolean 1 but the cmd field in the struct 
		  		// is not coherent with a valid command
		  		return 1;
		  	break;
		  	} 
		}
	}

	return 0;
}

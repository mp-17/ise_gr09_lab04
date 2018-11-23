#include <stdio.h>
#include "read.h"

// array in which will be saved new characters. It will be controlled for command parsing
static unsigned int cmdBuffer[maxCmdLength]; 

// readChar(void) 
// reads from a peripheral input and returns the char casted to an unsigned int
//
// OUTPUT
// returns one read char cast to unsigned int (-1 in case of EOF or error)
// CALLED FUNCTIONS
// - getc
// MEMORY MODIFICATION
// no memory modification
int readChar(void) {
	return getc(stdin);
}

// ascii2digit(unsigned int asciiInt) 
// reads from input an ASCII char and returns the corresponding digit in unsigned int format. If the char was not representing 
// a digit, then it returns a number greater than 9
//
// OUTPUT
// if the asciiInt in input is a ASCII code of a digit, the function returns the digit itself (unsigned int form)
// CALLED FUNCTIONS
// no function is called
// MEMORY NEEDS
// no memory needs
// MEMORY MODIFICATION
// no memory modification
unsigned int ascii2digit(unsigned int asciiInt) {
	return asciiInt - (unsigned int)'0';
}

// readCommand(basicCmd* cmdStruc_pt)
// it reads an array in which a command can be present. If a valid command is recognized then the data structure is updated coherently
//
// INPUT
// - cmdStruc_pt: pointer to basicCommand struct type (this struct has to be instantiated by the caller).
// OUTPUT
// - returns a 0 if a valid command is read, otherwise it returns -1
// CALLED FUNCTIONS
// - readChar()
// MEMORY NEEDS
// it needs space for a definition of an int variable and a byte for a _Bool
// MEMORY MODIFICATION
// - cmdBuffer shift and storing a new char in last position
// - *basicCommand memory locations: apart from the "cmd" field, the others are modificated even if the command is not valid
int readCommand(basicCmd* cmdStruc_pt) {

	_Bool valid = 0;
	unsigned int temp;

	// read the new character
	cmdBuffer[maxCmdLength-1] = readChar();

	if (cmdBuffer[minCmdOffset] == POINT) {
		if ((temp = ascii2digit(cmdBuffer[minCmdOffset+1])) < 10) {
			(*cmdStruc_pt).x1 = temp*100;
			if ((temp = ascii2digit(cmdBuffer[minCmdOffset+2])) < 10) {
				(*cmdStruc_pt).x1 += temp*10;
				if ((temp = ascii2digit(cmdBuffer[minCmdOffset+3])) < 10) {
					(*cmdStruc_pt).x1 += temp;
					if ((temp = ascii2digit(cmdBuffer[minCmdOffset+4])) < 10) {
						(*cmdStruc_pt).y1 = temp*100;
						if ((temp = ascii2digit(cmdBuffer[minCmdOffset+5])) < 10) {
							(*cmdStruc_pt).y1 += temp*10;
							if ((temp = ascii2digit(cmdBuffer[minCmdOffset+6])) < 10) {
								(*cmdStruc_pt).y1 += temp;
								(*cmdStruc_pt).m = ascii2digit(cmdBuffer[minCmdOffset+7]);
								if ( (unsigned int)(*cmdStruc_pt).x1 <= xMax && (unsigned int)(*cmdStruc_pt).y1 <= yMax && (unsigned int)(*cmdStruc_pt).m < 3) {
									(*cmdStruc_pt).cmd = cmdBuffer[minCmdOffset];
									valid = 1;
								}
							}
						}
					}
				}
			}
		}
	}
	//  added part for test - begin
	else if (cmdBuffer[maxCmdLength-1] == QUIT) {
		(*cmdStruc_pt).cmd = QUIT;
		valid = 1;
	}
	// added part for test - end
	else {
		switch (cmdBuffer[0]) {
			case LINE:
				if ((temp = ascii2digit(cmdBuffer[1])) < 10) {
				(*cmdStruc_pt).x1 = temp*100;
					if ((temp = ascii2digit(cmdBuffer[2])) < 10) {
					(*cmdStruc_pt).x1 += temp*10;
						if ((temp = ascii2digit(cmdBuffer[3])) < 10) {
						(*cmdStruc_pt).x1 += temp;
							if ((temp = ascii2digit(cmdBuffer[4])) < 10) {
							(*cmdStruc_pt).y1 = temp*100;
								if ((temp = ascii2digit(cmdBuffer[5])) < 10) {
								(*cmdStruc_pt).y1 += temp*10;
									if ((temp = ascii2digit(cmdBuffer[6])) < 10) {
									(*cmdStruc_pt).y1 += temp;
										if ((temp = ascii2digit(cmdBuffer[7])) < 10) {
										(*cmdStruc_pt).x2 = temp*100;
											if ((temp = ascii2digit(cmdBuffer[8])) < 10) {
											(*cmdStruc_pt).x2 += temp*10;
												if ((temp = ascii2digit(cmdBuffer[9])) < 10) {
												(*cmdStruc_pt).x2 += temp;
													if ((temp = ascii2digit(cmdBuffer[10])) < 10) {
													(*cmdStruc_pt).y2 = temp*100;
														if ((temp = ascii2digit(cmdBuffer[11])) < 10) {
														(*cmdStruc_pt).y2 += temp*10;
															if ((temp = ascii2digit(cmdBuffer[12])) < 10) {
															(*cmdStruc_pt).y2 += temp;
															(*cmdStruc_pt).m = ascii2digit(cmdBuffer[13]);
																if ( (unsigned int)(*cmdStruc_pt).x1 <= xMax && (unsigned int)(*cmdStruc_pt).y1 <= yMax && (unsigned int)(*cmdStruc_pt).x2 <= xMax && (unsigned int)(*cmdStruc_pt).y2 <= yMax && (unsigned int)(*cmdStruc_pt).m < 3) {
																	(*cmdStruc_pt).cmd = cmdBuffer[0];
																	valid = 1;
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
				break;
			case ELLIPSE:
				if ((temp = ascii2digit(cmdBuffer[1])) < 10) {
				(*cmdStruc_pt).x1 = temp*100;
					if ((temp = ascii2digit(cmdBuffer[2])) < 10) {
					(*cmdStruc_pt).x1 += temp*10;
						if ((temp = ascii2digit(cmdBuffer[3])) < 10) {
						(*cmdStruc_pt).x1 += temp;
							if ((temp = ascii2digit(cmdBuffer[4])) < 10) {
							(*cmdStruc_pt).y1 = temp*100;
								if ((temp = ascii2digit(cmdBuffer[5])) < 10) {
								(*cmdStruc_pt).y1 += temp*10;
									if ((temp = ascii2digit(cmdBuffer[6])) < 10) {
									(*cmdStruc_pt).y1 += temp;
										if ((temp = ascii2digit(cmdBuffer[7])) < 10) {
										(*cmdStruc_pt).dx = temp*100;
											if ((temp = ascii2digit(cmdBuffer[8])) < 10) {
											(*cmdStruc_pt).dx += temp*10;
												if ((temp = ascii2digit(cmdBuffer[9])) < 10) {
												(*cmdStruc_pt).dx += temp;
													if ((temp = ascii2digit(cmdBuffer[10])) < 10) {
													(*cmdStruc_pt).dy = temp*100;
														if ((temp = ascii2digit(cmdBuffer[11])) < 10) {
														(*cmdStruc_pt).dy += temp*10;
															if ((temp = ascii2digit(cmdBuffer[12])) < 10) {
															(*cmdStruc_pt).dy += temp;
															(*cmdStruc_pt).m = ascii2digit(cmdBuffer[13]);
																if ( (unsigned int)(*cmdStruc_pt).x1 <= xMax && (unsigned int)(*cmdStruc_pt).y1 <= yMax && (unsigned int)(*cmdStruc_pt).dx != 0 && (unsigned int)(*cmdStruc_pt).dx <= xMax && (unsigned int)(*cmdStruc_pt).dy != 0 && (unsigned int)(*cmdStruc_pt).dy <= yMax && (*cmdStruc_pt).m < 3) {
																	(*cmdStruc_pt).cmd = cmdBuffer[0];
																	valid = 1;
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
			default: 
				break;
		}
	}

	// right shift the elements of the buffer
	for (int i = 1; i < maxCmdLength; i++) {
		cmdBuffer[i-1] = cmdBuffer[i];
	}

	if (valid) { 
		return 0; 
	}
	else { 
		return 1;
	}
}
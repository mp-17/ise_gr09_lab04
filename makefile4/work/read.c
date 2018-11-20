#include <stdio.h>
#include "read.h"

// readChar(void) 
// reads from a peripheral input and returns a single char
//
// OUTPUT
// returns one read char
// CALLED FUNCTIONS
// - getc
// MEMORY MODIFICATION
// no memory modification
char readChar(void) {
	return getc(stdin);
};

// char2int(char charIn) 
// reads from input an ASCII/UTF char and returns the corresponding digit in short int format. If the char was not representing 
// a digit, it returns 10
//
// OUTPUT
// returns the digit which was represented in ASCII/UTF. If something goes wrong (i.e. the char was not a digit), 
// it returns 10 
// CALLED FUNCTIONS
// no function is called
// MEMORY NEEDS
// it needs 16 bits for a short int variable
// MEMORY MODIFICATION
// no memory modification
int char2int(char charIn) {

	unsigned int digitOut = 0;

	digitOut = (int)charIn - '0';

	if (digitOut > 9) {
		return 10;
	}

	return digitOut;
}

// readCommand(char* cmdBuffer, basicCmd* cmdStruc_pt)
// it reads an array in which a command can be present. If a valid command is recognized then the data structure is updated coherently
//
// INPUT
// - cmdBuffer: the buffer array in which char from input peripheral are stored. The length of cmdBuffer allows it to contain a valid command.
// - cmdStruc_pt: pointer to basicCommand struct type (this struct has to be instantiated by the caller).
// OUTPUT
// - returns a 1 if a valid command is read, otherwise it returns a 0
// CALLED FUNCTIONS
// - readChar()
// MEMORY NEEDS
// it needs space for a definition of an int variable and a byte for a _Bool
// MEMORY MODIFICATION
// - *basicCommand memory locations: apart from the "cmd" field, the others are modificated even if the command is not valid
int readCommand(char* cmdBuffer, basicCmd* cmdStruc_pt) {

	_Bool valid = 0;
	unsigned int temp;

	if ((int)cmdBuffer[minCmdOffset] == POINT) {
		if ((temp = char2int(cmdBuffer[minCmdOffset+1])) != 10) {
			(*cmdStruc_pt).x1 = temp*100;
			if ((temp = char2int(cmdBuffer[minCmdOffset+2])) != 10) {
				(*cmdStruc_pt).x1 += temp*10;
				if ((temp = char2int(cmdBuffer[minCmdOffset+3])) != 10) {
					(*cmdStruc_pt).x1 += temp;
					if ((temp = char2int(cmdBuffer[minCmdOffset+4])) != 10) {
						(*cmdStruc_pt).y1 = temp*100;
						if ((temp = char2int(cmdBuffer[minCmdOffset+5])) != 10) {
							(*cmdStruc_pt).y1 += temp*10;
							if ((temp = char2int(cmdBuffer[minCmdOffset+6])) != 10) {
								(*cmdStruc_pt).y1 += temp;
								(*cmdStruc_pt).m = char2int(cmdBuffer[minCmdOffset+7]);
								if ( (unsigned int)(*cmdStruc_pt).x1 <= xMax && (unsigned int)(*cmdStruc_pt).y1 <= yMax && (unsigned int)(*cmdStruc_pt).m < 3) {
									(*cmdStruc_pt).cmd = (int)cmdBuffer[minCmdOffset];
									valid = 1;
								}
							}
						}
					}
				}
			}
		}
	}
	else {
		switch ((int)cmdBuffer[0]) {
			case LINE:
				if ((temp = char2int(cmdBuffer[1])) != 10) {
				(*cmdStruc_pt).x1 = temp*100;
					if ((temp = char2int(cmdBuffer[2])) != 10) {
					(*cmdStruc_pt).x1 += temp*10;
						if ((temp = char2int(cmdBuffer[3])) != 10) {
						(*cmdStruc_pt).x1 += temp;
							if ((temp = char2int(cmdBuffer[4])) != 10) {
							(*cmdStruc_pt).y1 = temp*100;
								if ((temp = char2int(cmdBuffer[5])) != 10) {
								(*cmdStruc_pt).y1 += temp*10;
									if ((temp = char2int(cmdBuffer[6])) != 10) {
									(*cmdStruc_pt).y1 += temp;
										if ((temp = char2int(cmdBuffer[7])) != 10) {
										(*cmdStruc_pt).x2 = temp*100;
											if ((temp = char2int(cmdBuffer[8])) != 10) {
											(*cmdStruc_pt).x2 += temp*10;
												if ((temp = char2int(cmdBuffer[9])) != 10) {
												(*cmdStruc_pt).x2 += temp;
													if ((temp = char2int(cmdBuffer[10])) != 10) {
													(*cmdStruc_pt).y2 = temp*100;
														if ((temp = char2int(cmdBuffer[11])) != 10) {
														(*cmdStruc_pt).y2 += temp*10;
															if ((temp = char2int(cmdBuffer[12])) != 10) {
															(*cmdStruc_pt).y2 += temp;
															(*cmdStruc_pt).m = char2int(cmdBuffer[13]);
																if ( (unsigned int)(*cmdStruc_pt).x1 <= xMax && (unsigned int)(*cmdStruc_pt).y1 <= yMax && (unsigned int)(*cmdStruc_pt).x2 <= xMax && (unsigned int)(*cmdStruc_pt).y2 <= yMax && (unsigned int)(*cmdStruc_pt).m < 3) {
																	(*cmdStruc_pt).cmd = (int)cmdBuffer[0];
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
				if ((temp = char2int(cmdBuffer[1])) != 10) {
				(*cmdStruc_pt).x1 = temp*100;
					if ((temp = char2int(cmdBuffer[2])) != 10) {
					(*cmdStruc_pt).x1 += temp*10;
						if ((temp = char2int(cmdBuffer[3])) != 10) {
						(*cmdStruc_pt).x1 += temp;
							if ((temp = char2int(cmdBuffer[4])) != 10) {
							(*cmdStruc_pt).y1 = temp*100;
								if ((temp = char2int(cmdBuffer[5])) != 10) {
								(*cmdStruc_pt).y1 += temp*10;
									if ((temp = char2int(cmdBuffer[6])) != 10) {
									(*cmdStruc_pt).y1 += temp;
										if ((temp = char2int(cmdBuffer[7])) != 10) {
										(*cmdStruc_pt).dx = temp*100;
											if ((temp = char2int(cmdBuffer[8])) != 10) {
											(*cmdStruc_pt).dx += temp*10;
												if ((temp = char2int(cmdBuffer[9])) != 10) {
												(*cmdStruc_pt).dx += temp;
													if ((temp = char2int(cmdBuffer[10])) != 10) {
													(*cmdStruc_pt).dy = temp*100;
														if ((temp = char2int(cmdBuffer[11])) != 10) {
														(*cmdStruc_pt).dy += temp*10;
															if ((temp = char2int(cmdBuffer[12])) != 10) {
															(*cmdStruc_pt).dy += temp;
															(*cmdStruc_pt).m = char2int(cmdBuffer[13]);
																if ( (unsigned int)(*cmdStruc_pt).x1 <= xMax && (unsigned int)(*cmdStruc_pt).y1 <= yMax && (unsigned int)(*cmdStruc_pt).dx != 0 && (unsigned int)(*cmdStruc_pt).dx <= xMax && (unsigned int)(*cmdStruc_pt).dy != 0 && (unsigned int)(*cmdStruc_pt).dy <= yMax && (*cmdStruc_pt).m < 3) {
																	(*cmdStruc_pt).cmd = (int)cmdBuffer[0];
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

	if (valid) { 
		return 1; 
	}
	else { 
		return 0;
	}
}
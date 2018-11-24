#define POINT (unsigned int)'P'
#define LINE (unsigned int)'L'
#define ELLIPSE (unsigned int)'E'
#define QUIT (unsigned int)'Q'
#define minCmdLength 8
#define maxCmdLength 14
#define minCmdOffset 6 // maxCmdLength-minCmdLength
#define xMax 127
#define yMax 127

// basicCmd contains
// - cmd: the letter which encodes the command
// - x1: first coordinate on the independent axis
// - x2: second coordinate on the independent axis
// - y1: first coordinate on the dependent axis
// - y2: second coordinate on the dependent axis
// - dx: length of the main axis (for ellipse)
// - dy: legth of the secondary axis (for ellipse)
// - m: specification for the command
typedef struct{
  int cmd;
  int x1;
  int x2;
  int y1;
  int y2;
  int dx;
  int dy;
  int m;
} basicCmd;

// readChar(void) 
// reads from a peripheral input and returns the char casted to an unsigned int
//
// OUTPUT
// returns one read char cast to unsigned int (-1 in case of EOF or error)
// CALLED FUNCTIONS
// - getc
// MEMORY MODIFICATION
// no memory modification
int readChar(void);

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
unsigned int ascii2digit(unsigned int asciiInt);

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
int readCommand(basicCmd* cmdStruc_pt);

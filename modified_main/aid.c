#include "aid.h"
#include "shared.h"

const static char* fOutPath = "./drawnMtx.txt";

/* 
void printFMtx(void)
it opens a file (fOutPath) and prints on it the frameBuffer. Then it closes the file.
If there is some problem, it returns -1. Otherwise, it returns 0
INPUT
OUTPUT
CALLED FUNCTIONS
- fopen
- fclose
MEMORY NEEDS
MEMORY MODIFICATION
*/
int printFMtx(void) {
	FILE* fID = fopen(fOutPath, "w");

	if (fID == NULL) {
		return -1;
	}

	for (int i = 0; i < rowsFrame; i++) {
		for (int j = 0; j < colsFrame; j++) {
			for (int pos = 7; pos >= 0; pos--) {
				fprintf(fID, "%d", (frameBuffer[i][j] >> pos) & 0x01);	
			}
		}
		if (i != rowsFrame-1) {
			fprintf(fID, "\n");
		}
	}

	fclose(fID);

	return 0;
}
//============================================================================
/* Section 6.2: Basic String Processing Skills*/

/* Description
 * The given text file has one more line after a line
 * that starts with ‘.......’ but the
 * length of this last line is not constrained.
 * Your task is to count how many characters
 * there are in the last line. How to read a string
 * if its length is not known in advance?
 */
//============================================================================

#include <iostream>
#include <string.h>

using namespace std;



int main() {

	char line[30+50];
	int numChars; //to count the chars of the last line;
	char c;

	/*read input line by line*/
	//1) it can be unsafe because it does not perform bounds checking on input size
	gets(line);
	//2)
	//fgets(line,40,stdin);

	while(1){
		/*check if the line begins with seven dots "......" */
		if(strncmp(line, ".......", 7)==0) break;
		gets(line);
	}

	//Now, read the last line char by char, as it is not constrained!
	numChars = 0;
	c = getchar();
	while(c!='\n'){
		numChars++;
		c = getchar();
	}

	printf("The number of chars of the last line: %d", numChars);
	return 0;
}

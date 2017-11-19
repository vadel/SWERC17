//============================================================================
/* Section 6.2: Basic String Processing Skills*/

/* Description:
 * Given a text file that contains only
 * alphabet characters [A-Za-z], digits [0-9], space,
 * and period (‘.’), write a program to read this text file line by line until we encounter
 * a line that starts with seven periods (‘‘.......’’). Concatenate (combine) each line
 * into one long string T. When two lines are combined, give one space between them so
 * that the last word of the previous line is separated from the first word of the current
 * line. There can be up to 30 characters per line and no more than 10 lines for this input
 * block. There is no trailing space at the end of each line and each line ends with a
 * newline character
 */
//============================================================================

#include <iostream>
#include <string.h>

using namespace std;



int main() {

	char concat[30*10+50];
	char line[30+50];

	strcpy(concat, "");

	/*read input line by line*/
	//1) it can be unsafe because it does not perform bounds checking on input size
	gets(line);
	//2)
	//fgets(line,40,stdin);

	while(1){
		/*check if the line begins with seven dots "......" */
		if(strncmp(line, ".......", 7)==0) break;

		//concatenate the stringssss
		if(strlen(concat)!=0) strcat(concat, " ");
		strcat(concat, line);
		gets(line);
	}

	printf("Full line: \n");
	printf("%s\n", concat);
	return 0;
}

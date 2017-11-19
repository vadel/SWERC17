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
#include <regex>

using namespace std;



int main() {


	string concat;
	string line;

	regex r("\\.{7}");

	concat = "";

	getline(cin, line);
	while(!regex_match(line.begin(), line.begin()+7,r)){
		if(concat!="") concat += " ";
		concat += line;
		getline(cin, line);
	}

	cout << "full line: " << endl;
	cout << concat << endl;
	return 0;
}

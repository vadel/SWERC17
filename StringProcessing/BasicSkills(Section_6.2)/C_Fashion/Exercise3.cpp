//============================================================================
/* Section 6.2: Basic String Processing Skills*/

/* Description:
Suppose that we have one long string T. We want to check if another string P can
be found in T. Report all the indices where P appears in T or report -1 if P cannot
be found in T. For example, if T = ‘‘I love CS3233 Competitive Programming. i
also love AlGoRiThM’’ and P = ‘I’, then the output is only {0} (0-based indexing).
If uppercase ‘I’ and lowercase ‘i’ are considered different, then the character ‘i’ at
index {39} is not part of the output. If P = ‘love’, then the output is {2, 46}.
If P = ‘book’, then the output is {-1}.
 */
//============================================================================

#include <iostream>
#include <string.h>
#include <ctype.h> //tolower()/toupper()

using namespace std;



int main() {

	char T[30*10+50];
	char t[30*10+50]; //The T string in lowercase :)
	char c;
	int vowels = 0;
	int consonants = 0;

	//A long line
	strcpy(T, "AEIOU abcdefghijklmnopqrstuvwxyz");

	//find the substring
	for(int i=0; i<strlen(T); i++){
		c = tolower(T[i]);
		if( c=='a' || c=='e' || c=='i' || c=='o' || c=='u'){
			vowels++;
		}
		else if(c!=' '){
			consonants ++;
		}
		t[i] = c;
	}

	printf("The input string:\n");
	printf("%s\n\n", T);
	printf("Vowels: %d, Consonants: %d\n\n", vowels, consonants);
	printf("Input in lowercase:\n");
	printf("%s\n", t);
	return 0;
}

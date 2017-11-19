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

	string T = "";
	string t = ""; //The T string in lowercase :)
	char c;
	int vowels = 0;
	int consonants = 0;

	//A long line
	T = "AEIOU abcdefghijklmnopqrstuvwxyz";

	//find the substring
	for(int i=0; i<T.size(); i++){
		c = tolower(T[i]);
		if( c=='a' || c=='e' || c=='i' || c=='o' || c=='u'){
			vowels++;
		}
		else if(c!=' '){
			consonants ++;
		}
		t += c;
	}

	cout << "The input string:" << endl;
	cout << T << endl << endl;
	cout << "Vowels: " << vowels << " , Consonants; " << consonants << endl << endl;
	cout << "Input in lowercase" << endl;
	cout << t << endl;

	return 0;
}

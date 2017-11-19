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
#include <algorithm> //std::find

using namespace std;



int main() {

	string T;
	string P;
	int pos;

	//A long line
	T =  "I love CS3233 Competitive Programming. i also love AlGoRiThM";
	//Substring that we want to find
	P = "love";

	//find the substring
	pos = T.find(P);
	while(pos!=string::npos){
		cout << P <<  " found in the pos " << pos << endl;
		//try to find the substring from the recently found pos+1
		pos = T.find(P, pos+1);
	}

	return 0;
}

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

using namespace std;



int main() {

	char T[30*10+50];
	char P[30];
	int pos;

	//A long line
	//1)
	strcat(T, "I love CS3233 Competitive Programming. i also love AlGoRiThM");
	//2)
	//strcpy(T, "I love CS3233 Competitive Programming. i also love AlGoRiThM");

	//Substring that we want to find
	strcat(P,"love");

	//find the substring
	char * p = strstr(T,P);
	while(p!=NULL){
		pos = p-T; //the position of the ocurrence (points to the begin)
		printf("'%s' found in the pos %d\n", P, pos);
		//try to find the substring from the recently found pos+1
		p = strstr(T+pos+1,P);
	}

	printf("%s\n", T);
	return 0;
}

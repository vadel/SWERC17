//============================================================================
/* Section 6.2: Basic String Processing Skills*/

/* Description:
Next, we want to break this one long string T into tokens (substrings) and store them
into an array of strings called tokens. For this mini task, the delimiters of these tokens
are spaces and periods (thus breaking sentences into words). For example, if we tokenize
the string T (in lowercase), we will have these tokens = {‘i’, ‘love’, ‘cs3233’,
‘competitive’, ‘programming’, ‘i’, ‘also’, ‘love’, ‘algorithm’}. Then, we
want to sort this array of strings lexicographically 3 and then find the lexicograph-
ically smallest string. That is, we have sorted tokens: {‘algorithm’, ‘also’,
‘competitive’, ‘cs3233’, ‘i’, ‘i’, ‘love’, ‘love’, ‘programming’}. Thus,
the lexicographically smallest string for this example is ‘algorithm’.
 */
//============================================================================

#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

/*THIS SOLUTION COMBINES C AND C++!!!*/

int main() {

	char T[] = "i love cs3233 competitive programming. i also love algorithm";
	char * token;
	vector<string> tokens;

	//On a first call, the function expects a C string
	//as argument for str, whose first character is used
	//as the starting location to scan for tokens.
	token = strtok (T," .");

	while (token != NULL){
		//printf ("%s\n",token);
		tokens.push_back(string(token));
		//In subsequent calls, the function expects a
		//null pointer and uses the position right after
		//the end of the last token as the new starting location for scanning.
		token = strtok (NULL, " .");
	}

	sort(tokens.begin(), tokens.end());

	for(int i=0; i<tokens.size(); i++){
		printf("%s\n", tokens[i].c_str());
	}
	return 0;
}

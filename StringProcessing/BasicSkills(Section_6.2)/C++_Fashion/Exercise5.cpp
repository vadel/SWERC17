//============================================================================
/* Section 6.2: Basic String Processing Skills*/

/* Description:
 * Now, identify which word appears the most in T.
 * In order to answer this query, we need to count the
 * frequency of each word. For T, the output is either ‘i’ or ‘love’,
 * as both appear twice. Which data structure should be used
 * for this mini task?
 */
//============================================================================

#include <iostream>
#include <string.h>
#include <map>

using namespace std;

/*THIS SOLUTION COMBINES C AND C++!!!*/

int main() {

	char T[]= "i love cs3233 competitive programming. i also love algorithm";
	char *token;
	map<string, int> tokens;
	map<string,int>::iterator it;
	map<string,int>::iterator mostFrequent;
	int max;


	token = strtok(T, " .");
	while (token != NULL){
		tokens[string(token)]++;
		//In subsequent calls, the function expects a
		//null pointer and uses the position right after
		//the end of the last token as the new starting location for scanning.
		token = strtok (NULL, " .");
	}

	//Determine which is the most frequent token
	max = 0;
	for(it=tokens.begin(); it!=tokens.end(); it++){
		if(max < it->second){
			mostFrequent = it;
			max = it->second;
		}
	}

	cout << "The most frequent token is: '" << mostFrequent->first << "'" << endl;
	return 0;
}

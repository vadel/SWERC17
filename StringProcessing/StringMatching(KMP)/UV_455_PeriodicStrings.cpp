//============================================================================
// ACCEPTED! :D --- Runtime: 0.000
/* SOLUTION:
 * Aplicando el algoritmo de string matching KMP, si Pattern es periodico,
 * sabiendo el ultimo elemento del vector b (el valor de j al acabar
 * el preproceso) podemos saber si hay periodo, que en caso de ser,
 * seria : m - j (siendo m==Pattern.size() y j el ultimo numero del vector b).
 * Si el m%(m-j)==0 (m es multiplo del periodo), entonces sabemos que es realmente el periodo!
 */
//============================================================================

#include <iostream>
#include <string.h>
#include <regex>

using namespace std;

#define MAX_N 90

string T, P; //mas facil de manjar.. como es un programa simple, no importa el tiempo extra que suponga
//char T[MAX_N], P[MAX_N]; // T = text, P = pattern
int b[MAX_N], n, m;  // b = back table, n = length of T, m = length of P


//call this before calling kmpSearch()
int kmpPreprocess() {
	int i = 0, j = -1; b[0] = -1;
	while (i < m) {
		while (j >= 0 && P[i] != P[j]) j = b[j];
		i++; j++;
		b[i] = j;
	}
	return j;
}



int main() {

	int cases;
	int periodo;
	string blank;

	cin >> cases;
	getline(cin,blank); //read the new line
	getline(cin, blank); //read blank line

	while(cases--){
		getline(cin,P);
		if(cases!=0) getline(cin, blank);
		m = P.size();
		periodo = kmpPreprocess();

		//si el periodo que nos da no es multiplo, ya sabemos que mal!
		if(m%(m-periodo)!=0){
			cout << m << endl;
		}
		else cout << m-periodo << endl;
		if(cases!=0) cout << endl;
	}

	return 0;
}

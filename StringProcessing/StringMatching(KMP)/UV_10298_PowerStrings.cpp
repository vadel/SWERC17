//============================================================================
// ACCEPTED! :D --- Runtime: 0.000
/* SOLUTION:
 * Aplicando el algoritmo de string matching KMP, si Pattern es periodico,
 * sabiendo el ultimo elemento del vector b (el valor de j al acabar
 * el preproceso) podemos saber si hay periodo, que en caso de ser,
 * seria : m - j (siendo m==Pattern.size() y j el ultimo numero del vector b).
 * Si el m%(m-j)==0 (m es multiplo del periodo), entonces sabemos que es realmente el periodo!
 * Por tanto, es simplemente saber cuantas veces aparece ese periodo, dividiendo m/j :)
 */
//============================================================================

#include <iostream>
#include <string.h>
#include <regex>

using namespace std;

#define MAX_N 1000010

//string T, P;
char P[MAX_N]; // T = text, P = pattern
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

	int periodo;

	scanf("%s", P);

	while(strlen(P)!=1 || P[0]!='.'){
		m = strlen(P);
		periodo = kmpPreprocess();

		//si el periodo que nos da no es multiplo, ya sabemos que mal!
		if(m%(m-periodo)!=0){
			printf("1\n");
		}
		printf("%d\n", m/(m-periodo));
		scanf("%s", P);
	}

	return 0;
}

/*
 *  Created on: Dec 28, 2016
 *      Author: jon
 *
 *
 * ACCEPTED!!! :D -- Runtime: 0.03
 */


#include <stdio.h>
#include <cstdio>
#include <iostream>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <vector>
#include <map>
#include <set>
#include <math.h>
#include <cmath>
#include <algorithm>
#include <sstream>
#include <queue>
#include <stack>



using namespace std;



int main(){

	string A;
	string B;
	int N; //length of A
	int M; //length of B


	int SA[25][25]; //Table to calculate String Alignment

	int op1;
	int op2;
	int op3;

	cin >> A;

	while(A!="#"){

		cin >> B;

		N = A.size();
		M = B.size();

		//Fill String Alignment table
		memset(SA, 0, sizeof(SA)); //initialize table with 0

		//base case 1
		SA[0][0] = 0;

		//base case 2 (length of B==0)
		for(int k=1; k<N+1; k++){
			SA[k][0] = SA[k-1][0]-1;
		}

		//base case 3 (length of A==0)
		for(int k=1; k<M+1; k++){
			SA[0][k] = SA[0][k-1]-1;
		}

		//Recurrences
		for(int k=1; k<N+1; k++){
			for(int l=1; l<M+1; l++){
				//option 1 - consider both
				op1 = SA[k-1][l-1];
				if(A[k-1]==B[l-1]) op1 = op1 + 2; //if match
				else		   op1 = op1 - 1; //if mismatch

				//option 2 - delete A[i]
				op2 = SA[k-1][l] - 1;

				//option 3 - insert B[j]
				op3 = SA[k][l-1] - 1;

				SA[k][l] = max(op1,max(op2,op3));
			}
		}

		//Reconstruct the solution
		int i=N;
		int j=M;

		string prog = "E";
		string lag = "";
		while(i!=0 and j!=0){

			lag = "";
			if(SA[i][j]==SA[i-1][j-1]+2 and A[i-1]==B[j-1]){ //dejar como esta (copy)
				i--;
				j--;
				continue;
			}
			else if(SA[i][j]==SA[i-1][j-1]-1){ //change
				lag = "C";
				lag += B[j-1];
				if(j<10){
					lag += "0";
					lag += to_string(j);
				}
				else{
					lag += to_string(j);
				}
				i--;
				j--;
			}
			else if(SA[i][j]==SA[i-1][j]-1){ //delete
				lag = "D";
				lag += A[i-1];
				if(j+1<10){
					lag += "0";
					lag += to_string(j+1);
				}
				else{
					lag += to_string(j+1);
				}
				i--;
			}
			else if(SA[i][j]==SA[i][j-1]-1){//insert
				lag = "I";
				lag += B[j-1];
				if(j<10){
					lag += "0";
					lag += to_string(j);
				}
				else{
					lag += to_string(j);
				}
				j--;
			}
			prog = lag + prog;
		}

		//delete the rest
		while(i>0){
			lag = "D";
			lag += A[i-1];
			if(j+1<10){
				lag += "0";
				lag += to_string(j+1);
			}
			else{
				lag += to_string(j+1);
			}
			prog = lag + prog;
			i--;
		}

		//insert the rest
		while(j>0){
			lag = "I";
			lag += B[j-1];
			if(j<10){
				lag += "0";
				lag += to_string(j);
			}
			else{
				lag += to_string(j);
			}
			prog = lag + prog;
			j--;
		}
		cout << prog << endl;
		//printf("Optimum alignment %d\n", SA[N][M]);

		cin >> A;
	}


	return 0;
}






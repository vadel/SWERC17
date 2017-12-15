#include <stdio.h>
#include <iostream>
using namespace std;


int prices[100][20];
int x[100];
int y[100];
//3garren dimentsioa 120 jarrita ondo dabil bestela ez
int DP[100][20][120];
int C,R,B;

const int inf =9999999;

//Calculate Manhattan distance
int calculateDistance(int i1, int i2, int j1, int j2){
    return abs(i1-i2)+abs(j1-j2);
}


int fillDP(int rest, int meal, int money){

    if(DP[rest][meal][money]!=-1){
        return DP[rest][meal][money];
    }

    //If not money remaining not feasible
    if(money<0)
        return inf;

    if(meal==C)
        return 0;

    //If it is possible to eat in current rest just eat
    int minCost = inf;
    if(prices[rest][meal]!=0 && prices[rest][meal]<=money)
    	minCost = fillDP(rest, meal+1,money-prices[rest][meal]);

    //Go to all other possible restaurants and eat
    for(int i=0;i<R;i++){
        if(i==rest)
            continue;
    	if(prices[i][meal]==0)
    	    continue;
        int lag = calculateDistance(x[i],x[rest], y[i], y[rest])
                  + fillDP(i, meal+1, money-prices[i][meal]);
        if(lag<minCost)
            minCost=lag;
    }
    DP[rest][meal][money] = minCost;
    return minCost;

}



int main(){
    cin >> C >> R >> B;
    for(int i=0;i<R;i++){
        cin >> x[i];
        cin >> y[i];
        for(int j=0;j<C;j++){
            cin >> prices[i][j];
        }
    }
    memset(DP, -1, sizeof DP);
    int min=inf;
    //Start from every possible restaurant
    for(int i=0;i<R;i++){
    	if(prices[i][0]==0){
    		continue;
        }
        int lag=fillDP(i,0,B);
        if(lag<min)
        	min=lag;
    }
    if(min>=inf)
        cout << -1 << endl;
    else
        cout << min << endl;
}

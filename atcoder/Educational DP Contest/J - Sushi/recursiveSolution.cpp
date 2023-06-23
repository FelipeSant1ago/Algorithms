#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vii vector<vector<int>>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;



int N;

vector<int>freq;
vector<vector<vector<double>>>dp;

double solve(int x1, int x2, int x3){
    if(x1 + x2 + x3 == 0) return 0; 
    if(dp[x1][x2][x3] != -1) return dp[x1][x2][x3];

    double res = 0;


    if(x1 >= 1){
        res += x1*1.0/N *(1 + solve(x1-1,x2,x3));  
    }
    if(x2 >= 1){
        res += x2*1.0/N *(1 + solve(x1+1,x2-1,x3));   
    }
    if(x3 >= 1){
        res += x3*1.0/N *(1 + solve(x1,x2+1,x3-1));   
    }
    res += (N-x1-x2-x3)*1.0/N;
    res = res/(1.0 - (N-x1-x2-x3)*1.0/N);
    return dp[x1][x2][x3] = res;
}




int main(){


    cin >> N;

    freq.resize(4,0);
    dp.resize(N+1, vector<vector<double>>(N+1, vector<double>(N+1,-1)));

    for(int i = 0; i < N; i++){
        int aux;
        cin >> aux;
        freq[aux]++;
    }

    int x1 = freq[1];
    int x2 = freq[2];
    int x3 = freq[3];


    cout << setprecision(12) <<  solve(x1,x2,x3) << endl;

    


 




}
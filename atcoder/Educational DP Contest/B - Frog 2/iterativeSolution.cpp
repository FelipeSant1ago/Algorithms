#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vii vector<vector<int>>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;

int N, K;
vi heights;
int dp[100000];



int main(){

    cin >> N >> K;

    heights.resize(N);

    for(auto &e : heights) cin >> e;
    N--;
    dp[N] = 0;
    for(int indice = N-1; indice >= 0;indice--){
        dp[indice] = 1e9+1;
        for(int i = 1; i <= K; i++){
            if(indice + i <= N){
                dp[indice] = min(dp[indice],
                dp[indice+i] + abs(heights[indice] - heights[indice+i]));
            }
        }

    }


    cout << dp[0] << endl;


   
    

}
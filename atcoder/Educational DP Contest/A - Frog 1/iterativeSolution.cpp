#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vii vector<vector<int>>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;
int N;
vi heights;
int dp[100000];




int main(){

    optimize;

    cin >> N;

    heights.resize(N);

    for(auto &e : heights) cin >> e;

    N--;
    dp[N] = 0;
    dp[N-1] = abs(heights[N] - heights[N-1]);

    for(int indice = N-2; indice >= 0; indice--){
        dp[indice] = min(dp[indice+1] + abs(heights[indice] - heights[indice+1]),
        dp[indice+2] + abs(heights[indice] - heights[indice+2]));
        

    }

    cout << dp[0] << endl;
   


}
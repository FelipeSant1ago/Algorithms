#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vii vector<vector<int>>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;





int main(){

    string s, t;

    cin >> s >> t;
    int n , m;

    n = s.size();
    m = t.size();

    vector<vector<int>>dp(n+1, vector<int>(m+1,0));

    for(int i = 1; i <= n; i++){
        for(int k = 1; k <= m; k++){
            int match = dp[i-1][k-1];
            if(s[i-1] == t[k-1]) match++;
            dp[i][k] = max(match, max(dp[i-1][k],dp[i][k-1]));
        }
    }

    int x = n;
    int y = m;
    string res = "";

    while(x != 0 && y != 0){
        if(dp[x-1][y] == dp[x][y])x--;
        else if(dp[x][y-1] == dp[x][y])y--;
        else if(dp[x-1][y-1] == dp[x][y]-1 && s[x-1] == t[y-1]){
            res = s[x-1] + res;
            x--;
            y--;
             
        }


    }


    cout << res << endl;



    

   

    


   
}
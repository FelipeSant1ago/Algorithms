#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vii vector<vector<int>>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;






int main(){

    optimize;
    string s,t;
    cin >> s >> t;
    int ss = s.size(), st = t.size();
    vii dp(ss+1, vi(st+1,0));

    for(int row = 1; row <= ss; row++){
        for(int col = 1; col <= st; col++){
            if(s[row-1] == t[col-1]) dp[row][col] = dp[row-1][col-1] + 1;
            else dp[row][col] = max(dp[row][col-1], dp[row-1][col]);
        }
    }


    int row = ss, col = st;
    string res = "";

   

    while(row != 0 && col != 0){

    if(dp[row-1][col] == dp[row][col])row--;
    else if(dp[row][col-1] == dp[row][col])col--;
    else{
        res = s[row-1] + res;
        row--;
        col--;
        
    } 

    }

    cout << res << endl;
    


   

   

   
   
}
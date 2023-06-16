#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vii vector<vector<int>>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;



int main(){

    optimize;

   int N;
   cin >> N;

   vii atividades(N, vi(3));

   for(int i = 0; i < N; i++){
    cin >> atividades[i][0];
    cin >> atividades[i][1];
    cin >> atividades[i][2];
   }

   vii dp(N, vi (3));
   dp[0][0] = atividades[0][0];
   dp[0][1] =  atividades[0][1];
   dp[0][2] =  atividades[0][2];


   for(int i = 1; i < N; i++){
    for(int atividade = 0; atividade < 3; atividade++){
        int a;
        if(atividade == 0) a = max(dp[i-1][1], dp[i-1][2]);
        if(atividade == 1) a = max(dp[i-1][0], dp[i-1][2]);
        if(atividade == 2) a = max(dp[i-1][1], dp[i-1][0]);
        dp[i][atividade]= atividades[i][atividade] + a;
    }

   }


   cout << max(dp[N-1][0], max(dp[N-1][1], dp[N-1][2])) << endl;
  

}
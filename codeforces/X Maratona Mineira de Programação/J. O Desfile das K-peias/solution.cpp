#include<bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define pii pair<int,int>
#define MAXN 1000000
#define INF 1000000007
using namespace std;

vector<vector<pii>>problemas;

unordered_map<int,unordered_map<int,ll>> dp;

ll solve(int problema,int indice, int capacidade){
    if(indice >= problemas[problema].size()) return 0;
    if(dp[indice].count(capacidade) != 0) return dp[indice][capacidade];
    int custo = problemas[problema][indice].first;
    int majestosidade = problemas[problema][indice].second;

    ll notTake = solve(problema, indice+1,capacidade);
    ll take = 0;
    if(capacidade - custo >= 0){
        take = solve(problema,indice+1,capacidade - custo) + majestosidade;
    }

    return dp[indice][capacidade] =  max(take, notTake);
    //return  max(take, notTake);
}




int main(){
    optimize;
    int N, T;
    cin >> N >> T;
    problemas.resize(T+1);
    

    int qtdPes, tamSapato, majestosidade;
    for(int i = 0; i < N; i++){
        cin >> qtdPes >> tamSapato >> majestosidade;
        problemas[tamSapato].push_back({qtdPes/2,majestosidade});

    }

    int guardaRoupa[T+1];
    ll res = 0;
    int e, d;
    for(int i = 1; i <= T; i++){
        cin >> e >> d;
        guardaRoupa[i] = min(e,d);
        res += solve(i,0, guardaRoupa[i]);
        dp.clear();
        
    }


    cout << res << endl;

    
    


}
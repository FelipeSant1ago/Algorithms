#include<bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define pii pair<int,int>
#define MAXN 1000000
#define INF 1000000007



using namespace std;


int n,l,r,x;
vi dificuldades;
int solve(int indice,int menor, int maior,int total, int qtd){
    if(indice >= n){
        if(maior - menor < x) return 0;
        if(total < l || total > r) return 0;
        if(qtd < 2) return 0;
        return 1;
    }


    int notTake = solve(indice+1,menor,maior,total,qtd);
    menor = min(menor,dificuldades[indice]);
    maior = max(maior,dificuldades[indice]);
    total = total + dificuldades[indice];
    int take = solve(indice+1,menor,maior,total,qtd+1);

    return take + notTake;
}


int main(){
    optimize;

    cin >> n >> l >> r >> x;

    dificuldades.resize(n);
    for(auto &e : dificuldades) cin >> e;

    cout << solve(0,1e9,-1,0,0) << endl;

    

}
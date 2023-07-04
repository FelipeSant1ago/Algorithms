#include<bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define pii pair<int,int>
#define MAXN 1000000
#define INF 1000000007



using namespace std;
vvi dp(101, vi(1001,-1));
int solve(string& n, int indice, int qtd, string num){
    int numero = 1000;
    if(qtd >= 1) numero = stoi(num);
    if(indice >= n.size() || qtd == 3){
        if(qtd == 0) return -2;
        if(numero%8 == 0) return numero;
        else return -2;
    }
    if(dp[indice][numero] != -1) return dp[indice][numero];

    
    int notTake = solve(n,indice+1,qtd,num);
    num += n[indice];
    int take = solve(n,indice+1,qtd+1,num);


    return dp[indice][numero] = max(take,notTake);
    
    
}



int main(){

    optimize;


    string n;
    cin >> n;
    string aux = "";
    int res = solve(n,0,0,aux);
    if(res == -2) cout << "NO" << endl;
    else{
        cout << "YES" << endl;
        cout << res << endl;

    } 



}
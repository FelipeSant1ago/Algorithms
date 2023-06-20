#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vii vector<vector<int>>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;



int main(){

    optimize;

    ll n, m;

    cin >> n >> m;
    ll s;
    cin >> s;

    vector<pair<pair<int,int>,int>>sensores(s);
    ll total = 0;
    for(int i = 0; i < s; i++){
        ll x, y, r;
        cin >> x >> y >> r;
        ll linhas, colunas;
        ll aux1,aux2;
        if(x + r >= n) aux1 = n-1LL;
        else aux1 = x+r;
        if(x-r <= 0) aux2 = 0;
        else aux2 = x-r;
        linhas = aux1 - aux2 + 1LL;


        if(y + r >= m) aux1 = m-1LL;
        else aux1 = y+r;
        if(y-r <= 0) aux2 = 0;
        else aux2 = y-r;
        colunas = aux1 - aux2 + 1LL;
        total += linhas * colunas;
       
    }
    total = total /(n*m);

    cout << total << endl;

  

}
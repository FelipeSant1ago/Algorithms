#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vii vector<vector<int>>
using namespace std;


int main(){

    int n;

    cin >> n;

    vi beauty(n);

    for(int i = 0; i < n; i++)cin >> beauty[i];

    sort(beauty.begin(),beauty.end());
    int menor = beauty[0];
    int maior = beauty.back();

    ll qtdmenor = upper_bound(beauty.begin(),beauty.end(),menor) -lower_bound(beauty.begin(),beauty.end(),menor);
    ll qtdmaior = upper_bound(beauty.begin(),beauty.end(),maior) -lower_bound(beauty.begin(),beauty.end(),maior);
    ll res = qtdmenor * qtdmaior;
    if(menor == maior) res = qtdmaior * (qtdmenor - 1)/2;
    cout << maior - menor << " " << res << endl;
}
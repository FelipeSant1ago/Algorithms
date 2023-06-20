#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vii vector<vector<int>>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;



int main(){

    optimize;

    ll n, jogadaBob;

    cin >> n >> jogadaBob;

    vector<long long> numeros;

    for(ll i = 1; i <= 2*n; i++){
        ll aux = i*i;
        numeros.push_back(aux);
    }

    vector<long long> respostas;

    for(int i = 0; i < 2*n; i++){
        ll aux = abs(numeros[i] - jogadaBob);
        if(aux%(2LL*n +1LL) == 0 && numeros[i] != jogadaBob)respostas.push_back(numeros[i]);
    }

    ll a = respostas.back();
   
    cout << a << endl;
   

}
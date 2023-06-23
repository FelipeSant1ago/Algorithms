#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vii vector<vector<int>>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;




int main(){

    optimize;

    int n, saldoInicial;
    int menorSaldo;

    cin >> n >>  saldoInicial;

    menorSaldo = saldoInicial;

    for(int i = 0; i < n; i++){
        int movimentacao;
        cin >> movimentacao;

        saldoInicial += movimentacao;
        if(saldoInicial < menorSaldo) menorSaldo = saldoInicial;
    }

    cout << menorSaldo << endl;

   
    

    





}
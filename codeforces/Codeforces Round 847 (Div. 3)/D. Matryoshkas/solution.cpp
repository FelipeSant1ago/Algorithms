#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vii vector<vector<int>>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;


int main(){

    optimize;


    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        vi bonecas(n);

        for(int i = 0; i < n; i++)cin >> bonecas[i];

        sort(bonecas.begin(),bonecas.end());
        int res = 0;
        int anterior = bonecas[0] - 1;
        int frequenciaAnterior = 0;
        int atual = bonecas[0], frequenciaAtual = 0;
        
        for(int i = 0; i < n; i++){
            if(bonecas[i] != atual){
                frequenciaAnterior = frequenciaAtual;
                anterior = atual;
                atual = bonecas[i];
                frequenciaAtual = 0;

            }
            if(bonecas[i] == atual){
                frequenciaAtual++;
                if(frequenciaAtual > frequenciaAnterior || anterior != atual - 1)res++;
            }
           
            

        }

        cout  <<  res << endl;

    }

}
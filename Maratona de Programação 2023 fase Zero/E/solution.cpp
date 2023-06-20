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

    vi palpites(N);
    unordered_map<int,int>erros;

    for(int i = 0; i < N; i++){
        cin >> palpites[i];
    }
    int x;
    int maiorErro = 0;
    for(int i = 0; i < N; i++){
       cin >> x;
       if(x > maiorErro) maiorErro = x;

       erros[x]++;
    }


    int menorPalpite = 1e9;
    int maiorPalpite = 0;

    for(int i = 0; i < N; i++){
        if(palpites[i] > maiorPalpite) maiorPalpite = palpites[i];
        if(palpites[i] < menorPalpite) menorPalpite = palpites[i];
    }
    
    vi resposta(4);
    vi possivel(4,1);

    resposta[0] = menorPalpite + maiorErro;
    resposta[1] = menorPalpite - maiorErro;
    resposta[2] = maiorPalpite + maiorErro;
    resposta[3] = maiorPalpite - maiorErro;
    sort(resposta.begin(), resposta.end());


    for(int i = 0; i < N; i++){
        for(int j = 0; j < 4; j++){
            if(erros[abs(resposta[j] - palpites[i])] == 0)possivel[j] = 0;
        }


    }

    
    set<int>s;

    for(int i = 3; i >= 0; i--){
        if(possivel[i] == 1) s.insert(resposta[i]);
    }

    for(int x : s) cout << x << endl;
    


    

  



    






}
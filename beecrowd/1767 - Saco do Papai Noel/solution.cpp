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

    while(N--){
        int Pac;
        

        cin >> Pac;
        vector<pair<int,int>>pacotes;

        for(int i = 0; i < Pac; i++){
            int qtd, peso;
            cin >> qtd >> peso;
            

            pacotes.push_back({qtd,peso});
        }

        vii dp(Pac, vi(51,0));


        int x = pacotes[0].second;

        for(int peso = x;  peso <= 50; peso++){
            dp[0][peso] = pacotes[0].first;
        }


        for(int peso = 1; peso <= 50; peso++){
            for(int indice = 1; indice < Pac; indice++){
                int notTake = dp[indice-1][peso];
                int take = -1;
                if(peso - pacotes[indice].second >= 0){
                    take = dp[indice-1][peso-pacotes[indice].second] + pacotes[indice].first; 
                }

                dp[indice][peso] = max(take,notTake);
            }

            
        }
        int PacotesSobrados = Pac;
        int pesoTotal = 0;
        int a = 50;
        int ans =  dp[Pac-1][a];
        for(int indice = Pac-1; indice >= 1; indice--){
            if( a - pacotes[indice].second >= 0 &&  dp[indice-1][a] < ans){

                PacotesSobrados--;
                pesoTotal += pacotes[indice].second;
                ans -= pacotes[indice].first;
                a -= pacotes[indice].second;
            }



        }
        if(ans >= pacotes[0].first && pesoTotal + pacotes[0].second <= 50 ){
            PacotesSobrados--;
            pesoTotal += pacotes[0].second;
        }

        
        

        cout  << dp[Pac-1][50] << " brinquedos" << endl;
        cout << "Peso: " <<pesoTotal  << " kg" << endl;
        cout << "sobra(m) " <<PacotesSobrados <<" pacote(s)" << endl;
        cout << endl;

       

    }


  





}
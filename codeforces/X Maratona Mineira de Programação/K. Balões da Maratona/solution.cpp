#include<bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define pii pair<int,int>
#define MAXN 1000000
#define INF 1000000007
using namespace std;
vvi rgb;




int main(){
    optimize;

    int n;
    cin >> n;
    rgb.resize(n,vi(3));
    for(int i = 0; i < n; i++){
        cin >> rgb[i][0] >> rgb[i][1] >> rgb[i][2];
    }


    int res[3];
    int maiorMenorDistancia = 0;
    int distancia;
    int menorDistancia;

    for(int r = 0; r <= 255; r++){
        for(int g = 0; g <= 255; g++){
            for(int b = 0; b <= 255; b++){
                menorDistancia = 765;
                for(int i = 0; i < n; i++){
                    distancia = abs(r-rgb[i][0]) + abs(g-rgb[i][1]) + abs(b-rgb[i][2]);
                    if(distancia < menorDistancia){
                        menorDistancia = distancia;
                        
                    }
                }
                if(menorDistancia > maiorMenorDistancia){
                    maiorMenorDistancia = menorDistancia;
                    res[0] = r;
                    res[1] = g;
                    res[2] = b;

                }
                

            }
        }
    }


    cout << res[0] << " " << res[1] << " " << res[2] << endl;

    



}
#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vii vector<vector<int>>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;

int N;
vii atividades;

int dp[100000][3];



int main(){

    cin >> N;

    atividades.resize(N, vi(3));

    for(int i = 0; i < N; i++){
        cin >> atividades[i][0] >>  atividades[i][1] >>  atividades[i][2];
    }
    N--;
    
    for(int cantPick = 0; cantPick <= 2; cantPick++){
        dp[N][cantPick] = 0;
        for(int act = 0; act <= 2; act++){
            if(act != cantPick){
                dp[N][cantPick] = max(dp[N][cantPick],atividades[N][act]);
            }
        }
    }

    // for(int cantPick = 0; cantPick <= 2; cantPick++){
    //     dp[N][cantPick] = atividades[N][cantPick];
      
    // }


    for(int dia = N-1; dia >= 0; dia--){
        for(int cp = 0; cp <= 2; cp++){
            dp[dia][cp] = 0;
            for(int act = 0; act <= 2; act++){
                if(act != cp){
                    dp[dia][cp] = max(dp[dia][cp],
                    atividades[dia][act] + dp[dia+1][act]);
                }
            }
        }
    }

   



    cout << max(dp[0][0], max(dp[0][1],dp[0][2]));





}
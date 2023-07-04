#include<bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define pii pair<int,int>
#define MAXN 1000000
#define INF 1000000007



using namespace std;

vi num;
int dp[100][8];




int main(){
    optimize;

    string n;

    

    cin >> n;
    num.resize(n.size());

    for(int i = 0; i < n.size(); i++){
        int x = n[i] - '0';
        num[i] = x;
    }

    dp[0][num[0]%8] = true;
    vvi prev(100, vi(8,-1));
    for(int indice = 1; indice < n.size(); indice++){
        dp[indice][num[indice]%8] = true;
        for(int resto = 0; resto < 8; resto++){
            if(dp[indice-1][resto] == true){
                dp[indice][resto] = true;
                prev[indice][resto] = resto;
                dp[indice][(resto*10 + num[indice])%8] = true;
                prev[indice][(resto*10 + num[indice])%8] = resto;
                
            }
            
        }
    }
    string  res = "NO";
    string  resposta = "";
    for(int indice = 0; indice < n.size(); indice++){
        if(dp[indice][0] == true){
            res = "YES";
            int resto = 0;
            for(int i = indice; i >= 0; i--){
                if(prev[i][resto] == -1){
                    resposta = n[i] + resposta;
                    break;
                }
                if(prev[i][resto] == -1 || prev[i][resto] != resto){
                    resposta = n[i] + resposta;

                }
                resto = prev[i][resto];
            }

            break;
        }
    }

    cout << res << endl;
    if(res == "YES") cout << resposta << endl;

}
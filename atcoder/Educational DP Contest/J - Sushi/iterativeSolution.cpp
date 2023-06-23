#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vii vector<vector<int>>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;

int N;

vector<int>freq;

int main(){
    

    optimize;

    
    cin >> N;

    freq.resize(4,0);

    for(int i = 0; i < N; i++){
        int aux;
        cin >> aux;
        freq[aux]++;
    }

    int x1 = freq[1];
    int x2 = freq[2];
    int x3 = freq[3];
    double dp[N+2][N+2][N+2];
    
    for(int c = 0; c <= N; c++){
        for(int b = 0; b <= N; b++){
            for(int a = 0; a <= N; a++){
                if(a + b + c == 0){
                    dp[a][b][c] = 0;
                    continue;
                }
                double res = 0;
                if(a >= 1){
                    res += a*1.0/N *(1 + dp[a-1][b][c]);  
                }
                if(b >= 1){
                    res += b*1.0/N *(1 + dp[a+1][b-1][c]);   
                }
                if(c >= 1){
                    res += c*1.0/N *(1 + dp[a][b+1][c-1]);   
                }
                res += (N-a-b-c)*1.0/N;
                res = res/(1.0 - (N-a-b-c)*1.0/N);
                dp[a][b][c] = res;
            }
            
        }
        
    }

    cout <<setprecision(12) << dp[x1][x2][x3] << endl;



}
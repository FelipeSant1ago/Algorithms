#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vii vector<vector<int>>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;

vector<ll> prefixSum;
vi sequencia;

int N, K;





int main(){

    optimize;

    cin >> N >> K;

    sequencia.resize(N);
    prefixSum.resize(N + 1);
    prefixSum[0] = 0;
    ll total = 0;

    for(int i = 0; i < N; i++){
        cin >> sequencia[i];
        total += sequencia[i];
        prefixSum[i+1] = total;
    }

    if(K == 0){
        ll cont = 0;
        ll res = 0;
        for(int i = 0; i < N; i++){
            if(sequencia[i] == 0){
                cont++;
            }
            else if(cont >= 1){
                res += ((1LL + cont)*cont)/2LL;
                cont = 0;
            }
        }

        if(cont >= 1){
            res += ((1LL + cont)*cont)/2LL;
            cont = 0;

        }

        cout << res << endl;
    }
    else{
        ll res = 0;

        for(int i = 1; i <= N; i++){
            int procurado = prefixSum[i] - K;
            auto x = upper_bound(prefixSum.begin(),prefixSum.end(),procurado);
            auto y = lower_bound(prefixSum.begin(),prefixSum.end(),procurado);
            res += x - y;
        }


        cout << res << endl;
    }

   


  

   




}
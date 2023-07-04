#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vii vector<vector<int>>
using namespace std;


int main(){
   
   
    int N;
    cin >> N;
    string s;
    vi freq(N);
    vi paridade(N);

    for(int i = 0; i < N; i++){
        cin >> s;
        int tam = s.size();
        freq[i] =  0;
        paridade[i] = 0;
        for(int j = 0; j < tam; j++){
            freq[i] |= (1 << (s[j] - 'a'));
            paridade[i] ^= (1 << (s[j] - 'a'));
        }
    }
    ll res = 0;
    for(char letra = 'a'; letra <= 'z'; letra++){
        unordered_map<int,int>mapa;
        for(int i = 0; i < N; i++){
            if((freq[i] & (1<< (letra-'a'))) == 0){
                int paridadeProcurada = (paridade[i]^((1 << 26) - 1));
                paridadeProcurada ^= (1 << (letra-'a'));
                res  += mapa[paridadeProcurada];
                mapa[paridade[i]]++;

            }
        }
    }

    cout << res << endl;




}
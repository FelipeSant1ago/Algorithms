#include<bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define pii pair<int,int>
#define MAXN 1000000
#define INF 1000000007
using namespace std;



int main(){
    optimize;
    int N;
    string S;
    char valor[26];
    int cont = 0;
    for(char letra = 'b'; letra <= 'z'; letra++){
        if(letra == 'e' ||letra == 'i' ||letra == 'o' ||letra == 'u' ||letra == 'y')
            continue;
        valor[letra-'a'] = cont++;

    }
    cin >> N >> S;
    vi freq((1<<20) - 1);
    int mask = 0;
    freq[0] = 1;
    ll res = 0;
    for(int i = 0; i < N; i++){
        mask ^= (1 << (valor[S[i]-'a']));
        res += freq[mask];
        for(int k = 0; k < 20; k++) res += freq[mask^(1 << k)];
        freq[mask]++;
    }

    cout << res << endl;
    


    
  
   
  

}
#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vii vector<vector<int>>
using namespace std;


int main(){
    int n;

    cin >> n;

    string palavras[n];
    vi a(n,0);
    vi b(n,0);

    for(int i = 0; i < n; i++){
        cin >> palavras[i];
        for(char c : palavras[i]){
            a[i] = a[i] | (1 << (c - 'a'));
            b[i] = b[i]^(1 << (c - 'a'));
        }

    }

    vi bsorted = b;
    sort(bsorted.begin(),bsorted.end());



    ll res = 0;
    for(int letraFixa = 0; letraFixa < 26; letraFixa++){
        unordered_map<int,int>freq;
        for(int i = 0; i < n; i++){
            if((a[i] & (1 << letraFixa)) == 0){
                int bProcurado = (b[i]^((1 << 26) - 1));
                bProcurado ^= (1 << letraFixa);
                //res += upper_bound(bsorted.begin(),bsorted.end(), bProcurado) - lower_bound(bsorted.begin(),bsorted.end(), bProcurado);
                res += freq[bProcurado];
                freq[b[i]]++;
            }

        }
        
    }

    cout << res << endl;

    


    

}
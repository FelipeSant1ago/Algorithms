#include<bits/stdc++.h>
#define vi vector<int>
#define vvi vector<vector<int,int>>
#define pii pair<int,int>
#define ll long long


using namespace std;

int main(){
   

    int n;

    cin >> n;

    while(n--){
        string s;
        cin >> s;
        vi freq(26, 0);
        int tamanho = s.size();
        for(int i = 0; i < tamanho; i++){
            int indice = s[i] - 'a';
            freq[indice]++;
        }
        int res = 1e7;
        for(char letra = 'a'; letra <= 'z'; letra++){
            int remover = tamanho - freq[letra];
            int resParcial = 0;
            for(int i = 0; i < tamanho; i++){
                if(s[i] != letra){
                    int cont = 1;
                    i++;
                    while(i < tamanho && s[i] != letra){
                        cont++;
                        i++;

                    }
                    int aux = 0;
                    while(cont > 0){
                        cont/= 2;
                        aux++;
                    }
                    resParcial = max(resParcial,aux);


                }
            }
            res = min(res, resParcial);


        }


        cout << res << endl;
    }








}
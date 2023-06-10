#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vii vector<vector<int>>
using namespace std;


int main(){

    int t;

    cin >> t;

    while(t--){
        int n, k;
        cin >> n >>  k;

        string original, maldicao;

        cin >> original >> maldicao;

        bool res = true;

        vi letrasO(26,0);
        for(int i = 0; i < n; i++){
            letrasO[original[i] - 'a']++;
        }
         for(int i = 0; i < n; i++){
            letrasO[maldicao[i] - 'a']--;
            if(letrasO[maldicao[i] - 'a'] < 0){
                res = false;
                break;
            } ;
        }

        if(res == true && n <= 5){
            for(int i = 0; i < n; i++){
                if( i - 3 < 0 && i + 3 >= n){
                    if(original[i] != maldicao[i]){
                        res = false;
                        break;
                    }
                }
            }

        }


        if(res) cout << "YES" << endl;
        else cout << "NO" << endl;


    }

}
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
        cin >> n >> k;
        vi minusculos(26,0);
        vi maiusculos(26,0);
       
        for(int i = 0; i < n; i++){
            char x;
            cin >> x;
            if(isupper(x)) maiusculos[x - 'A']++;
            else if(islower(x)) minusculos[x - 'a']++;
            
            
        }
        int res = 0;


        for(int i = 0; i < 26; i++){
            int frequenciam = minusculos[i];
            int frequenciaM = maiusculos[i];

            if(frequenciam > frequenciaM) swap(frequenciaM,frequenciam);

            while(k > 0 && frequenciam < frequenciaM - 1){
                k--;
                frequenciaM--;
                frequenciam++;
            }

            res += min(frequenciaM,frequenciam);
        }
        

    
        cout << res << endl;

        

    }

}
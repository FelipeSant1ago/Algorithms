#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vii vector<vector<int>>
using namespace std;


int main(){

    int t;

    cin >> t;


    while(t--){
        int n, s, r;


        cin >> n >> s >> r;

        int dadoRoubado = s - r;
        cout << dadoRoubado ;
        n--;
        int media = r/n;
        int restante = r%n;
        while(restante > 0){
            if(restante + media <= dadoRoubado){
                cout <<" " << media + restante;
                n--;
                break;
            }
            else{
                cout << " " << dadoRoubado;
                restante -= (dadoRoubado-media);
                n--;
            }
        }
        while(n--){
            cout << " " <<  media;

        }
        cout << endl;

    }

}
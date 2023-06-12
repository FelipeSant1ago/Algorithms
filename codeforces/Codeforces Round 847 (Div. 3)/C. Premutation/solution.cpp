#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vii vector<vector<int>>
using namespace std;


int main(){

    int t;
    cin >> t;

    while(t--){
        int n,aux;
        cin >> n;
        vii pm(n);
        for(int i = 0; i < n; i++){
            for(int  j = 0; j  < n-1; j++){
                cin >> aux;
                pm[i].push_back(aux);
            }


        }
        int p0 = 0;
        int p1 = 0;
        int p2 = 0;
        for(int i = 0; i < n; i++){
            if(pm[0][p0] == pm[1][p1] && pm[1][p1] == pm[2][p2]){
                cout << pm[0][p0] << " ";
                p0++;
                p1++;
                p2++;

            }
            else if(pm[0][p0] == pm[1][p1]){
                cout << pm[0][p0] << " ";
                p0++;
                p1++;
            }
            else if(pm[0][p0] == pm[2][p2]){
                cout << pm[0][p0] << " ";
                p0++;
                p2++;
            }
            else if(pm[1][p1] == pm[2][p2]){
                cout << pm[1][p1] << " ";
                p1++;
                p2++;
            }

        }

        cout << endl;
    }

}
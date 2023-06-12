#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vii vector<vector<int>>
using namespace std;


int main(){

    int t;
    cin >> t;

    while(t--){
        ll x;
        ll a = 0,b = 0;
        cin >> x;
        ll falta = x;
        for(ll i = 31; i >= 0 ; i--){
            if((x & (1ll << i)) == (1ll << i)){
                a += (1ll << i);
            }
            else{
                ll vsfd = (1ll << (i+1ll));
                if( falta >= vsfd){
                    ll vsfd2 = (1ll << i);
                    a += vsfd2;
                    b += vsfd2;
                    falta -= vsfd;
                }
            }

        }

        if(falta != 0) cout << -1 << endl;
        else cout << a << " " << b << endl;




    }

}
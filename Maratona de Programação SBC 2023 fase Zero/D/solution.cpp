#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vii vector<vector<int>>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;




int main(){

    optimize;

    ll x;
    cin >> x;
    cout << x << endl;
    
        while(x > 9){

            ll aux = x/10LL;
            ll resto = x%10LL;
            x = aux * 3LL + resto; 
            cout << x << endl;

        }

    
    



}
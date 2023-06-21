#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vii vector<vector<int>>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;


bool ok (ll numConselhos,int k, vector<long long>& grupos){
    int aux = grupos.size()-k-1;
    ll total = 0;
    for(int i = 0; i <= aux; i++){
        total += grupos[i];

    }
    for(int indice = grupos.size()-k; indice < grupos.size(); indice++){
        ll quantofalta = 0;
        if(numConselhos > grupos[indice]){
            quantofalta = numConselhos - grupos[indice];
        }

        if(total  >= quantofalta){
            total -= quantofalta;
        }
        else return false;
        

    }


    return true;


    
    



}



int main(){

    int n;

    int k;

    cin >> k >> n;

    vector<ll> grupos(n);

    for(auto &e : grupos) cin >> e;

    sort(grupos.begin(),grupos.end());

    ll l = 0;
    ll r = 50000000000;
    ll res = 0;
    while(l <= r){
        ll mid = (l+r)/2LL;

        if(ok(mid,k,grupos)){
            res = mid;
            l = mid + 1;

        }
        else{
            r = mid - 1;
        }
    }

    cout << res << endl;

    

    

}
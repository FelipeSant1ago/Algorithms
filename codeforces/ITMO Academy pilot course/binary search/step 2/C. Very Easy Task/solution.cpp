#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vii vector<vector<int>>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;

bool check(ll x, ll y,ll copias, ll tempo){
    ll res = 0;

    res += tempo/x + tempo/y;

    if(res >= copias) return true;
    return false;

}



int main(){

    optimize;

    ll n, x, y;

    cin >> n >> x >> y;

    ll res = 0;

    n--;

    res += min(x,y);

    ll l = 0;
    ll r = 2e9;
    ll minimo = 0;
    while(l <= r){
        ll mid = (l+r)/2LL;

        if(check(x,y,n,mid)){
            minimo = mid;
            r = mid - 1;

        }
        else{
            l = mid + 1;
        }
    }

    res += minimo;

    cout << res << endl;



    

}
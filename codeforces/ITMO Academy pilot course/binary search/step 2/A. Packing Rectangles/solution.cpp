#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vii vector<vector<int>>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;

bool check(ll n, ll h, ll w, ll l){
    if( (l/w) * (l/h) >= n) return true;

    return false;
}



int main(){



    ll w, h, n;

    cin >> w >> h >> n;

    ll l = 1LL;
   
    ll r =1;
    while(!check(n,h,w,r))  r*= 2;
    ll res = 1e18;

    while(l <= r){
        ll mid = (l + r)/2LL;

        if(check(n,h,w,mid)){
            res = mid;
            r = mid - 1;
        }
        else{
            l = mid + 1;
        }
    }


    cout << res << endl;

    

}
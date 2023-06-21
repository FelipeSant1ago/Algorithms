#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vii vector<vector<int>>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;

bool check(int n, int k, double x, vector<double>& ropes){
    ll res = 0;

    for(double rope : ropes){
        res += rope/x;
    }

    if(res >= k) return true;
    return false;

}




int main(){

    optimize;

    int n , k;

    cin >> n >> k;
    vector<double>ropes(n);

    for(auto &e : ropes) cin >> e;
    double res = 0;
    double l = 0;
    double r = 10000000;
    while(abs(l-r) >= 0.000001){
        double mid = (l+r)/2.0;
        if(check(n,k,mid, ropes)){
            res = mid;
            l = mid;

        }
        else{
            r = mid;
        }

    }


    cout << fixed << setprecision(6) << res << endl;


    

}
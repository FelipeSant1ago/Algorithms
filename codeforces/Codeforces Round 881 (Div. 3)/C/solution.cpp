#include<bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define pii pair<int,int>
#define MAXN 1000000
#define INF 1000000007



using namespace std;



int main(){

    optimize;

    int t;
    cin >> t;


    while(t--){
        ll n;
        cin >> n;
        ll res = 0;
        while(n >= 1){
            res += n;
            n/= 2;
        }

        cout << res << endl;
    }



}
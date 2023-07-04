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
    int n;
    cin >> n;

    int res = 2;

    int u,v;

    while(n--){
        cin >> u >> v;
        if(u == res) res = v;
        else if (v == res) res = u;
    }

    cout << res << endl;
    

}
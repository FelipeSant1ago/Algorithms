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
    int res = 0;
    int calorias[5];
    for(int i = 1; i <= 4; i++) cin >> calorias[i];
    string s;
    cin >> s;
    for(int i = 0; i < s.size(); i++){
        res += calorias[s[i] - '0'];
    }

    cout << res << endl;


}
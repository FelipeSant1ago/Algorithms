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
        int n;
        cin >> n;

        vi arr(n);

        for(int i = 0; i < n; i++) cin >> arr[i];

        sort(arr.begin(),arr.end());

        int res = 0;

        int l = 0, r = arr.size()-1;

        while(l < r){
            res += arr[r] - arr[l];
            r--;l++;
        }

        cout << res << endl;
    }

}
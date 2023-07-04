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
        long long total = 0;
        for(int i = 0; i < n; i++){
            cin >> arr[i];
            total += abs(arr[i]);
        }

        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(arr[i] < 0){
                cnt++;
                while(i < n && arr[i] <= 0){
                    i++;

                }

            }
            
        }

        cout << total << " " << cnt << endl;

    }

}
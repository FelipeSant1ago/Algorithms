#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vii vector<vector<int>>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;



int main(){

    optimize;

    int n, m, k;

    cin >> n >> m >> k;

    vector<vector<string>>input(k+1, vector<string>(n));
    for(int i = 0; i <= k; i++){
        for(int j = 0; j < n; j++){
            cin >> input[i][j];

        }
    }


}
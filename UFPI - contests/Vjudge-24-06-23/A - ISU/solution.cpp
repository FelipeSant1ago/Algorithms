#include<bits/stdc++.h>
#define vi vector<int>
#define vvi vector<vector<int,int>>
#define pii pair<int,int>
#define ll long long


using namespace std;

int main(){

    int x,y,z;

    cin >> x >> y >> z;

    int res = 0;

    x -= z;

    res = x/(y+z);

    cout << res << endl;





}
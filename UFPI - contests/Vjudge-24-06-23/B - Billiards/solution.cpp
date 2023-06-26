#include<bits/stdc++.h>
#define vi vector<int>
#define vvi vector<vector<int,int>>
#define pii pair<int,int>
#define ll long long


using namespace std;

int main(){

    double sx,sy,gx,gy;

    cin >> sx >> sy >> gx >> gy;

    double x = sy*gx + gy*sx;
    x = x/(gy+sy);

    cout << setprecision(9) << x << endl;






}
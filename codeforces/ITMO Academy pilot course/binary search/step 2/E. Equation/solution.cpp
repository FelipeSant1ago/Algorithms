#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vii vector<vector<int>>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;




int main(){

    optimize;
    double c;

    cin >> c;

    double l = 0, r = 10000000000;
    double res = 0;
    while(abs(l - r) >= 0.0000001){
        double mid = (l+r)/2.0;
        double aux = pow(mid,2) + sqrt(mid);
        if(aux == c){
            res = mid;
            break;

        }
        else if(aux > c){
            r = mid ;
        }
        else{
            l = mid ;
        }
        res = mid;
    }

    cout << fixed << setprecision(6) << res << endl;

   

    

}
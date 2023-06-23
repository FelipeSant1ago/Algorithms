#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vii vector<vector<int>>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;

double check(double x, int A, vi& tiras){
    double areaTotal = 0;

    for(int altura : tiras){
        double aux = altura - x;
        if(aux < 0) aux = 0;
        areaTotal += aux;
    }

    return areaTotal;

}


int main(){

    optimize;

    while(true){
        double N, A;
        cin >> N >> A;
        if(N == 0 && A == 0) break;

        vi tiras(N);

        for(auto &e : tiras) cin >> e;
        int total = 0;
        for(int x : tiras) total += x;

        double l = 0, r = 1e4;
        double res = -1;
        while(abs(l - r) >= 0.000001){
            double mid = (l+r)/2.0;
            if(abs(check(mid,A,tiras) - A) <= 0.00001){
                res = mid;
                break;
            }
            else if(check(mid,A,tiras) > A){
                l = mid ;
            }
            else r = mid ;

            res = mid;
        }


        if(total == A) cout << ":D" << endl;
        else if(total < A) cout << "-.-" << endl;
        else cout << fixed <<  setprecision(4) << res << endl;
    }





}
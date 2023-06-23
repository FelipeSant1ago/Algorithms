#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vii vector<vector<int>>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;



int main(){

    optimize;


    int N , Q;

    int caso = 1;

    while(true){
        cin >> N  >> Q;

        if(N == 0 && Q == 0) break;

        cout << "CASE# " << caso <<":"<< endl;
        caso++;
        vi numeros(N);

        for(auto &e : numeros) cin >> e;

        sort(numeros.begin(),numeros.end());

        while(Q--){
            int x;
            cin >> x;

            auto res = lower_bound(numeros.begin(),numeros.end(),x);
            if(res != numeros.end() && *res == x){
                cout << x << " found at " << (res - numeros.begin() + 1) << endl;
            }
            else cout << x << " not found" << endl;
        }


    }





}
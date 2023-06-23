#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vii vector<vector<int>>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;
int N, F;

vi capsulas;


bool check(int dias){
    ll moedasProduzidas = 0;


    for(int x : capsulas){
        ll aux = dias;
        aux /=  x;

        moedasProduzidas += aux;
    }


    if(moedasProduzidas >= F) return true;

    return false;

}

int main(){

    optimize;

    cin >> N >> F;

    capsulas.resize(N);

    for(auto &e : capsulas) cin >> e;


    int l = 0;
    int r = 1e8;
    int res = 0;
    while(l <= r){
        int mid = (l+r)/2;

        if(check(mid)){
            res = mid;
            r = mid - 1;

        }
        else{
            l = mid + 1;
        }
    }

    cout << res << endl;


  

   
    

    





}
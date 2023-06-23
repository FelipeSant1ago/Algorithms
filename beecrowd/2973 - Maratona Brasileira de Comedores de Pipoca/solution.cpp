#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vii vector<vector<int>>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;
int N,C,T,total;
vi pipocas;

bool check(int tempo){

    int pipocasComidas = 0;
    ll a = T;
    a *= tempo;
    int competidores = C;
    for(int x : pipocas){

        if(a < x){
            a = T ;
            a*= tempo;
            competidores--;
            if( a < x) return false;
            if(competidores == 0) return false;

        }
        a -= x;
        pipocasComidas += x;

        
    

    }

    return true;

    
}


int main(){

    optimize;
    cin >> N >> C >> T;

    pipocas.resize(N);

    for(auto &e : pipocas) cin >> e;
    total = 0;
    for(int x : pipocas) total += x;


    int l = 0;
    int r = 1e9;
    int res = 0;
    while(l <= r){
        int mid = (l + r)/2;
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
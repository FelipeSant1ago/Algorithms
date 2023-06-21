#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vii vector<vector<int>>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;

bool check(ll x, ll dinheiro, vi& custo, vi& freqIngredientes,vector<ll>& qtdIngredientes){
    

    for(int i = 0; i <= 2; i++){
        if( qtdIngredientes[i] < x*freqIngredientes[i]){
            ll falta = x*freqIngredientes[i] - qtdIngredientes[i];
            if(dinheiro >= falta*custo[i]){
                dinheiro -= falta*custo[i];
            }
            else return false;
        
        }
    }

    return true;

    
}



int main(){

    optimize;

    string s;

    vi freqIngredientes(3,0);

    cin >> s;

    for(int i = 0; i < s.size(); i++){
        if(s[i] == 'B')freqIngredientes[0]++;
        else if(s[i] == 'C')freqIngredientes[2]++;
        else freqIngredientes[1]++;
    }
    vector<ll> qtdIngredientes(3);
    vi custos(3);
    cin >> qtdIngredientes[0] >> qtdIngredientes[1] >> qtdIngredientes[2];
    cin >> custos[0] >> custos[1] >> custos[2];

    ll dinheiro;
    cin >> dinheiro;
    ll l = 0;

    ll r = 1e13;
    ll res = 0;
    while(l <= r){
        ll mid = (l+r)/2LL;

        if(check(mid,dinheiro,custos,freqIngredientes,qtdIngredientes)){
            res = mid;
            l = mid + 1;
        }
        else{
            r = mid - 1;
        }

    }


    cout << res << endl;

   

    

}
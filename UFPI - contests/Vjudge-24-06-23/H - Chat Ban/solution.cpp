#include<bits/stdc++.h>
#define vi vector<int>
#define vvi vector<vector<int,int>>
#define pii pair<int,int>
#define ll long long


using namespace std;

ll check(ll aux){
    ll pa = (1ll+aux)*aux/2LL;

    return pa;

}

ll check2(ll aux, ll k){
    ll pa = (k-1LL + aux)*(k-aux)/2LL;


    return pa;
}

int main(){

    int t;
   // cout << check(1000000000LL) + check2(1,1000000000LL) << endl;
    
    ll maximo = 0;

    cin >> t;
    ll res = 0;
    while(t--){
        res = 0;
        ll x,k;
        cin >> k >> x;
        ll emotesSpamados = 0;
        ll metade = (1LL+k)*k/2LL;
        if(x >= check(k) + check2(1,k)){
            res = 2LL*k -1LL;
        }
        else if(metade < x){
            emotesSpamados = metade;
            res = k;

            ll restante = x - emotesSpamados;

            ll finall = k*(k-1LL)/2LL;
    
            
            ll temp = 0;
            ll l = 1LL;
            ll r = k-1;
            ll ateOnde = 0;
            
        
            while(l<=r){
                ll mid = (l+r)/2;
                ll aux =check2(mid,k);
                //cout << "aux = " << aux << endl;

                if(aux >= restante){
                    l = mid+1;
                }
                else if(aux < restante){
                    r = mid-1;
                    
                    if(ateOnde < aux) {
                        ateOnde = aux;
                        temp = abs(k-1  - mid) + 1;
                    }
                    
                }
                

                    

                }
                
                //cout << ateOnde << " " << res << endl;
                res += temp;
                if(ateOnde < restante ){
                    res++;

                    emotesSpamados += ateOnde + res;
                }
                else emotesSpamados += ateOnde;


                //==============

            
            

        }
        else{
            ll l = 0;
            ll r = k;
            ll ateOnde = 0;
            
            while(l<=r){
                ll mid = (l+r)/2;
                ll aux =check(mid);
                //cout << "aux = " << aux << endl;

                if(aux >= x){
                    r = mid-1;
                }
                else if(aux < x){
                    l = mid+1;
                    
                    if(ateOnde < aux) ateOnde = aux;
                    res = mid;
                }
              

                

            }
            
            //cout << ateOnde << " " << res << endl;
            if(ateOnde < x){
                res++;
                emotesSpamados = ateOnde + res;
            }
            else emotesSpamados = ateOnde;

        }

        cout << res << endl;

    }




}
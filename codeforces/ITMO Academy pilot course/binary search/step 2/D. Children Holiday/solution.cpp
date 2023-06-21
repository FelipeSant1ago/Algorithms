#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vii vector<vector<int>>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;

bool check(int baloes,int tempoMeta,int numAssistentes,vii& assistentes,vi& aux){
   int baloesEnchidos = 0;

    for(int i = 0; i < numAssistentes; i++){
        if( baloesEnchidos >= baloes) break;
        int tempo = tempoMeta;
        while(tempo >= assistentes[i][0]*assistentes[i][1] && baloesEnchidos + assistentes[i][1] <= baloes){
            baloesEnchidos += assistentes[i][1];
            tempo -= (assistentes[i][0]*assistentes[i][1] + assistentes[i][2]);
        }
        if(tempo >= 0 && baloesEnchidos < baloes) baloesEnchidos += min(tempo/assistentes[i][0],baloes-baloesEnchidos);
        
       

    }

    if(baloesEnchidos >= baloes) return true;

    return false;
}


bool check2(int baloes,int tempoMeta,int numAssistentes,vii& assistentes,vi& aux){
    int baloesEnchidos = 0;
    int curr = 0;
    

for(int i = 0; i < numAssistentes; i++){
    curr = baloesEnchidos;
    if( baloesEnchidos >= baloes) break;
    int tempo = tempoMeta;
    while(tempo >= assistentes[i][0]*assistentes[i][1] && baloesEnchidos + assistentes[i][1] <= baloes){
        baloesEnchidos += assistentes[i][1];
        tempo -= (assistentes[i][0]*assistentes[i][1] + assistentes[i][2]);
    }
    if(tempo >= 0 && baloesEnchidos < baloes) baloesEnchidos += min(tempo/assistentes[i][0],baloes-baloesEnchidos);
    curr = baloesEnchidos - curr;
    aux[i] = curr;
    

}

if(baloesEnchidos >= baloes) return true;

return false;
}



int main(){

    optimize;

    int meta, numAssistentes;

    cin >> meta >> numAssistentes;
    // t, z, y
    vii assistentes(numAssistentes, vi(3));

    
    for(int i = 0; i < numAssistentes; i++){
        cin >> assistentes[i][0] >> assistentes[i][1] >> assistentes[i][2];

    }
    vi aux(numAssistentes,0);
    int l = 0;
    int r = 30000000;
    int res;
    while(l <= r){
        int mid = (l + r)/2;
        if(check(meta,mid,numAssistentes,assistentes,aux)){
            res = mid;
            r = mid - 1;
        }
        else{
            //cout << "nao deu certo com " << mid << endl;
            l = mid + 1;
        }
    }

    cout << res << endl;
    check2(meta,res,numAssistentes,assistentes,aux);

    for(int x : aux) cout << x << " ";
    cout << endl;

   

    

}
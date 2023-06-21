#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vii vector<vector<int>>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;


bool possoApagar(int indice, vi& permutation, string s, string& t){

    for(int i = 0; i <= indice; i++){
        s[permutation[i] - 1] = '.';
    }
    int aux = 0;
    for(int i = 0; i < s.size(); i++){
        if(aux == t.size())break;
        if(s[i] == t[aux])aux++;

    }

    if(aux == t.size()) return true;

    return false;

    

}


int main(){
    
   


    string s, t;

    cin >> s >> t;

    vi permutation(s.size());

    for(auto &e : permutation) cin >> e;

    int l = 0;

    int r = permutation.size()-1;

    int res = 0;
    while(l <= r){
        int mid = (l+r)/2;

        if(possoApagar(mid,permutation,s,t)){
            //cout << "posso apagar ate indice " <<mid << endl;
            res = mid + 1;
            l = mid + 1;

        }
        else{
            //cout << "nao posso apagar o indice " << mid << endl;
            r = mid - 1;
        }
    }


    cout << res << endl;

    



    

    

    

}
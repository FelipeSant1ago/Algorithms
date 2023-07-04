#include<bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define pii pair<int,int>
#define MAXN 1000000
#define INF 1000000007



using namespace std;

bool check(vector<pii>&segments, vi& changes, int x, int tamanhoArr){
    vi arr(tamanhoArr, 0);
    vi prefixSum(tamanhoArr);
    int cont = 0;
    for(int i = 0; i < x; i++){
        if(arr[changes[i]] == 0){
            cont++;
        } 
        arr[changes[i]] = 1;
    }
    int aux = 0;

    for(int i = 0; i < arr.size(); i++){
        if(arr[i] == 1) aux++;
        prefixSum[i] = aux;

    }

    for(auto it : segments){
        int l = it.first;
        int r = it.second;
        int qtd = r - l + 1;
        if(l == 0){
            if(prefixSum[r] >= qtd/2 + 1) return true;

        }
        else{
            if(prefixSum[r] - prefixSum[l-1] >= qtd/2 + 1) return true;

        }
    }


    return false;
    


}



int main(){

    optimize;

    int t;

    cin >> t;

    while(t--){
        int tamArr, qtdSegmentos;

        cin >> tamArr >> qtdSegmentos;
        vector<pii> segments(qtdSegmentos);

        for(int i = 0; i < qtdSegmentos; i++){
            int l, r;
            cin >> l >> r;
            l--;r--;
            segments[i] = {l,r};
        }


        int qtdChanges;
        cin >> qtdChanges;

        vi changes(qtdChanges);

        for(int i = 0; i < qtdChanges; i++){
            cin >> changes[i];
            changes[i]--;
        }
        int res = -1;
        int l = 1;
        int r = qtdChanges;

        while(l <= r){
            int mid = (l+r)/2;
            if(check(segments,changes,mid,tamArr)){
                res = mid;
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }


        cout  << res << endl;


    }

    

}
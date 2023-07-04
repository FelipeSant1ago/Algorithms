#include<bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define pii pair<int,int>
#define MAXN 1000000
#define INF 1000000007
using namespace std;


bool cortePraEsquerda(int l,int h, int xi){
    if(xi - h >= l) return true;
    return false;
}

bool cortePraDireita(int r,int h, int xi){
    if(xi + h <= r) return true;
    return false;
}



int main(){
    optimize;

    int n;
    cin >> n;
    vector<pii>ordemArvores(n);
    vector<int>cortadas(n);

    int xi,h;
    for(int i = 0; i < n; i++){
        cin >> xi >> h;
        ordemArvores[i] =  {xi,h};
        cortadas[i] = 0;
    }

    cortadas[0] = -1;
    cortadas[n-1] = 1;
    int res = 2;

    for(int i = 1; i < n-1; i++){
        int h = ordemArvores[i].second;
        int xi = ordemArvores[i].first;
        int l = ordemArvores[i-1].first+1;
        int r = ordemArvores[i+1].first-1;
        if(cortadas[i-1] ==  1 ){
            l = l + ordemArvores[i-1].second; 
        }
        if(cortadas[i+1] ==  -1 ){
            r = r - ordemArvores[i+1].second; 
        }
        if(cortePraEsquerda(l,h,xi)){
            res++;
            cortadas[i] = -1;
        }
        else if(cortePraDireita(r,h,xi)){
            res++;
            cortadas[i]= 1;
        }
        

    }
    if(n == 1) res = 1;
    cout << res << endl;
    




}
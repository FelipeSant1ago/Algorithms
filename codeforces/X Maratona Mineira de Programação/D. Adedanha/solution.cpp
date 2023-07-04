#include<bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define pii pair<int,int>
#define MAXN 1000000
#define INF 1000000007
using namespace std;



int main(){
    optimize;

    int N;
    cin >> N;
    int total = 0;
    int aux;
    for(int i = 0; i < N-1; i++){
        cin >> aux;
        total += aux;
    }
    if(N == 1){
        cout << 0 << endl;
    }
    else{
        int parei = 1 + total%N;
        for(int i = 1; i <= N; i++){
            if(i > parei && i - parei > 20 ) cout << -1 << endl;
            else if(i < parei && (i + N-parei > 20)) cout << -1 << endl;
            else{
                if(i >= parei) cout << i - parei << endl;
                else cout << i + N-parei << endl;
                
            }
        }

    }

    

}
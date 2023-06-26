#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define pii pair<int,int>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)


using namespace std;



int main(){

    optimize;

    int N, M;

    cin >> N >> M;
    set<int> visitados;
    queue<pii>q;
    q.push({N,0});
    visitados.insert(N);
    int res = 0;
    vi a(6);
    while(!q.empty()){
        int numero = q.front().first;
        int ops = q.front().second;
        q.pop();
        if(numero == M){
            res = ops;
            break;
        }
        a[0] = numero*2;
        a[1] = numero*3;
        a[2] = numero/2;
        a[3] = numero/3;
        a[4] = numero + 7;
        a[5] = numero - 7;
        for(int x : a){
            
            if(visitados.count(x) == 0){
                q.push({x,ops+1});
                visitados.insert(x);
            }
            
            
        }
        

        

    }

    cout << res << endl;


}
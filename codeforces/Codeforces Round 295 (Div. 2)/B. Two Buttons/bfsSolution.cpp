#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vii vector<vector<int>>
using namespace std;



//solution 3 : usando bfs;

int main(){
    int original, target;

    cin >> original >> target;

    queue<pair<int,int>>q;
    vector<bool> visitados(20001,false);
    q.push({original,0});
    visitados[original] = true;

    while(!q.empty()){
        int n = q.front().first;
        int res = q.front().second;
        q.pop();
        if(n-1 == target || (n*2 == target)){
            cout << res + 1 << endl;
            break;
        }

        if( n-1 >= 1 && !visitados[n-1]){
            q.push({n-1,res+1});
            visitados[n-1] = true;
        }
        if( n*2 <=  20000 &&  !visitados[n*2]){
            q.push({n*2,res+1});
            visitados[n*2] = true;
        }
    }
}
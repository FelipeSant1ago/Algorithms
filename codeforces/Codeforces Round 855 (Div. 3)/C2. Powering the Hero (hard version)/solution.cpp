#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vii vector<vector<int>>
using namespace std;


int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        int aux;
        ll res = 0;
        priority_queue<int>pq;
        for(int i = 0; i < n; i++){
            cin >> aux;
            if(aux != 0) pq.push(aux);
            else if(!pq.empty()){
                int aux = pq.top();
                pq.pop();
                res += aux;
            }
        }


        cout << res << endl;


    }

}
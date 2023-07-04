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

    int t;

    cin >> t;

    while(t--){
        int n;
        cin >> n;
        int cont = 2;
        vector<pii>global(n+10);
        vector<pii>local(n+10);
        local[1] = {0,1};
        global[1] = {0,1};
         
        while(n--){
            char op;
            cin >> op;
            if(op == '+'){
                int no, peso;
                cin >> no >> peso;
                local[cont].first = min(local[no].first + peso,min(peso,0));
                local[cont].second = max(local[no].second + peso,max(peso,0));
                global[cont].first = min(local[cont].first, global[no].first);
                global[cont].second = max(local[cont].second, global[no].second);
                cont++;

            }
            else{
                int u, v, x;
                cin >> u >> v >> x;
                if(x <= global[v].second && x >= global[v].first){
                    cout << "YES"  << endl;
                }
                else cout << "NO" << endl;

            }
        }
    }

}
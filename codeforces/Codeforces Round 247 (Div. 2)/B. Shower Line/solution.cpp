#include<bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define pii pair<int,int>
#define MAXN 1000000
#define INF 1000000007
using namespace std;

int grid[5][5];


ll alegria(string& combinacao){
    ll res = 0;
    while(combinacao.size() > 1){
        for(int i = 0; i < combinacao.size()-1; i+=2){
            int g = combinacao[i] - '1';
            int j = combinacao[i+1] - '1';
            res += grid[g][j] + grid[j][g];
        }
        combinacao.erase(0,1);
    }

    return res;
}
vector<string>permutacoes;

void allPermuatations(string x){
    while(next_permutation(x.begin(),x.end())){
        permutacoes.push_back(x);

    }
}



int main(){
    optimize;
    string x = "12345";
    permutacoes.push_back(x);
    allPermuatations(x);



    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            cin >> grid[i][j];
        }
    }

    ll res = 0;
    for(string x : permutacoes){
        res = max(res, alegria(x));
    }

    cout << res << endl;

}
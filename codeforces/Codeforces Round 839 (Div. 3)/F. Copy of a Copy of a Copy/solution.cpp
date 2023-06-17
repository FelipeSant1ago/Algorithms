#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vii vector<vector<int>>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;


void operacoes(int possivelPrimeiro,  vector<vector<string>>& input, vector<pair<int,int>>&ops){
    int n = input[0].size();
    int m = input[0][0].size();
    int dx[] = {1,0,-1,0};
    int dy[] = {0,1,0,-1};
    for(int row = 1; row < n-1; row++){
        for(int col = 1; col < m-1; col++){
            char corProcurada = '0';
            if(input[possivelPrimeiro][row][col] == '1') corProcurada = '1';
            int cont = 0;
            //cout << "(row,col) -> cont  " << endl;
            for(int i = 0; i < 4; i++){
                int nr = row + dx[i];
                int nc = col + dy[i];
                if(input[possivelPrimeiro][nr][nc] != corProcurada) break;
                else cont++;
            }
            //cout << "(" << row << "," << col << ") -> " << cont  << endl;
            if(cont == 4){ ops.push_back({row,col}); 
            //cout << "achei um" << endl;
            }

        }
    }


}

void operacoes2(int possivelPrimeiro,  vector<vector<string>>& input, vector<pair<int,int>>&ops){
    int n = input[0].size();
    int m = input[0][0].size();
    int dx[] = {1,0,-1,0};
    int dy[] = {0,1,0,-1};
    for(int row = 1; row < n-1; row++){
        for(int col = 1; col < m-1; col++){
            char corProcurada = '1';
            if(input[possivelPrimeiro][row][col] == '1') corProcurada = '0';
            int cont = 0;
            //cout << "(row,col) -> cont  " << endl;
            for(int i = 0; i < 4; i++){
                int nr = row + dx[i];
                int nc = col + dy[i];
                if(input[possivelPrimeiro][nr][nc] != corProcurada) break;
                else cont++;
            }
            //cout << "(" << row << "," << col << ") -> " << cont  << endl;
            if(cont == 4){ ops.push_back({row,col}); 
            //cout << "achei um" << endl;
            }

        }
    }


}

int main(){

    optimize;

    int n, m, k;

    cin >> n >> m >> k;

    vector<vector<string>>input(k+1, vector<string>(n));
    for(int i = 0; i <= k; i++){
        for(int j = 0; j < n; j++){
            cin >> input[i][j];

        }
    }



    vector<pair<int,int>> ops;
    operacoes(0,input,ops);
    int possivelPrimeiro = 0;
    

    for(int i = 1; i < k+1; i++){
        for(int j = 0; j < ops.size(); j++){
            int row = ops[j].first;
            int col = ops[j].second;
            if(input[i][row][col] != input[possivelPrimeiro][row][col]){
                possivelPrimeiro = i;
                ops.clear();
                operacoes(possivelPrimeiro,input,ops);
            }

        }

    }

    cout  << possivelPrimeiro + 1 << endl;
    ops.clear();
    set<pair<int,int>>s;
    vector<pair<int,int>>a;
    operacoes2(possivelPrimeiro,input,ops);
    int total = 0;
    //for(auto x : ops) cout <<"ops = " <<  x.first << " "<< x.second << endl;
    for(int i = 0; i < input.size(); i++){
        if(i != possivelPrimeiro){
            int qtd = 0;
            for(int j = 0; j < ops.size(); j++){
                int row = ops[j].first;
                int col = ops[j].second;
                if(input[i][row][col] != input[possivelPrimeiro][row][col]){
                    qtd++;
                }
            }
            s.insert({qtd,i});
            if(qtd > total) total = qtd;
        }
    }

    int feito = 0;
    cout << total + k << endl;
    while(!s.empty()){
        auto x = *(s.begin());
        s.erase(s.begin());
        //cout << "feito, x.first = " << feito << " " << x.first << endl;
        while(feito < x.first){
            for(int i = 0; i < ops.size(); i++){
                int row = ops[i].first;
                int col = ops[i].second;
                if(input[possivelPrimeiro][row][col] != input[x.second][row][col]){
                    feito++;
                    cout << 1 << " " << row + 1 << " " << col + 1 << endl;
                    input[possivelPrimeiro][row][col] = input[x.second][row][col];
                }
            }

        }
        cout << 2 << " " << x.second + 1 << endl;

    }




}
#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vii vector<vector<int>>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;


//wrong answer
bool asd(string& s,int indice){

    if(indice + 2 >= s.size()) return true;
    char x1 = s[indice+1];
    char x2 = s[indice+2];

    if((x1 == '.' || x1 == ',' || x1 == ' ') && (x2 == '.' || x2 == ',' || x2 == ' ')) return false;


    return true;
}


bool asd2(string& s, int indice){
    for(int i = indice - 1; i >= 0; i--){
        if(isalpha(s[i])) return false;
        if(!isdigit(s[i]) && !isalpha(s[i])) return true;
    }

    return true;
}


int main(){
    //cout << isdigit(' ') << endl;

    optimize;
  
    int n;

    cin >> n;
    string aux;

    vector<string>linhas(n);
    getline(cin,linhas[0]);
    for(int i = 0; i < n; i++){
        getline(cin,linhas[i]);
    }

    // cout << "sfkasmflkafmkadsmkfads == " << endl;

    // for(int i = 0; i < n; i++){
    //     cout <<"linha " << i << " igual a = "  << linhas[i] << endl;
    // }
    bool res = false;
    ll y = -1, y1 = -1, y2 = -1;
    bool quebralinha = false;
    int tamanho;
    long long resto = 0;
    for(int j = 0; j < n; j++){
        string s = linhas[j];

        for(int i = 0; i < s.size(); i++){
            if(isdigit(s[i]) && ( i == 0 ||  asd2(s,i))){
                //cout << "possivel comeco de numero na linha " << j << ", posicao " << i << endl;
                char x[15] ;
                int j = 0;
                while(i + 1 < s.size() && !isalpha(s[i+1]) && (asd(s,i))){
                    if(isdigit(s[i])){
                        x[j++] = s[i];
                        // cout << "o digito" << s[i] << " foi colocado" << endl;
                    }
                    i++;
                }
                if((!asd(s,i) || i + 1 == s.size()) && isdigit(s[i]))x[j++] = s[i];

                if(i + 1 == s.size()){
                    quebralinha = true;
                    
                }
                if((s[i] == ',' || s[i] == '.' || s[i] == ' ') || (i + 2 < s.size() && asd(s,i) == false)){
                    ll num = atoll(x);
                    cout << "achamos o num = " << num << endl;
                    if(y == -1) y = num;
                    else if(y1 == -1){
                        if(num == y + 1){
                            y1 = num;
                        }
                        else{
                            y = num;
                        }
                    }
                    else if(y2 == -1){
                        if(num == y1 + 1){
                            res = true;
                            break;
                        }
                        else{
                            y = num;
                            y1 = -1;
                        }
                    }
                   
                }

                
                

            }
            
        }

        if(res == true) break;
    }

  
    

    if(res == true) cout << "123" << endl;
    else cout << ":)" << endl;

}
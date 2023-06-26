#include<bits/stdc++.h>
#define vi vector<int>
#define vvi vector<vector<int,int>>
#define pii pair<int,int>
#define ll long long


using namespace std;
bool  ehCaixaAlta(char x){
    int z = x;

    if(z <= 90) return true;

    return false;
   

}
char para_CaixaAlta(char x){
    int y = x - 'a';


    char res = 'A' + y;

    return res;

}


// a == 97 z == 122 A == 65 Z == 90

int main(){
   
   

    int numPalavras;

    cin >> numPalavras;
    string palavrao = "";
    string aux;
    for(int i = 0; i < numPalavras;i++){
       
        cin >> aux;
        palavrao += aux;
        if(i < numPalavras-1) palavrao += " ";

    }

    int ops;
    cin >> ops;
    string digitado = "";
    

   
    bool lc = true; 
    string x;
    string z = "";
    for(int i = 0; i < ops; i++){
       
        cin >> x;
        if(x == "Space"){
           
            digitado += " ";
        }
        else  if(x == "CapsLock"){
                if(lc) lc = false;
                else lc = true;
        }
        else if(x == "Backspace" && digitado.size()>=1){
            z = "";
            for(int i = 0; i < digitado.size()-1;i++){
                z += digitado[i];
            }
            digitado = z;
            
        }
        else if(x.size() == 1){
            char aux = x[0];
            if(!lc &&  !ehCaixaAlta(aux)){
                aux = para_CaixaAlta(aux);

            }
            digitado += aux;
        }


    }
    bool res = true;
    if(digitado != palavrao) res = false;
   
    // for(int i = 0; i < digitadas.size(); i++) cout << digitadas[i] << " ";
    // cout << endl;

    // for(int i = 0; i < palavras.size(); i++) cout << palavras[i] << " ";
    // cout << endl;


    if(res) cout << "Correct" << endl;
    else  cout << "Incorrect" << endl;
    




}
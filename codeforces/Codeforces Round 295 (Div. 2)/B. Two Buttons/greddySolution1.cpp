#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vii vector<vector<int>>
using namespace std;

//solução greedy
int main(){

    int original, target;
    int res = 0;
    cin >> original >> target;
    if(original > target) res += original - target;
    else{
        int passosr = 0, passosl = 0;
        int l = 0;
        int r = 0;
        int aux = target;
        while(aux > original){
            passosl++;
            if(aux %2 == 1){
                aux++;
                passosl++;
                if(aux/2 <= original){
                    passosr--;
                    r--;
                }
            }
            aux/= 2;
            
        }
        passosr  += passosl - 1;
        l = aux;
        r += aux * 2;
        res = min(original - l + passosl, original*2 - r + 1 + passosr);
       

    }


    cout << res << endl;

}


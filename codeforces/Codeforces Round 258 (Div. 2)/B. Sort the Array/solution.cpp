#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vii vector<vector<int>>
using namespace std;


int main(){

    int n;
    cin >> n;
    vi a(n);

    for(int i = 0; i < n; i++)cin >> a[i];
    vi emOrdem = a;

    sort(emOrdem.begin(),emOrdem.end());
    int l = 0;
    int r = 0;

    bool diferente = false;
    bool res = true;
    for(int i = 0; i < n; i++){
        if(a[i] != emOrdem[i] && diferente == true){
            res = false;
            break;
        }
        if(a[i] != emOrdem[i] && diferente == false){
            l = i;
            diferente = true;
            for(int j = i; j < n - 1; j++){
                if(a[j] < a[j + 1]){
                    r = j;
                    i = j;
                    break;
                }
                if(j == n - 2){
                    r = n - 1;
                    i = n;
                }
            }

        }
        
    }
    l++;r++;
    if(res == true ) cout << "yes " << l << " " << r << endl;
    else cout << "no" << endl; 


}
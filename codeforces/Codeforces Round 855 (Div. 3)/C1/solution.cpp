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
       vi nums(n);

       for(int i = 0; i < n; i++) cin >> nums[i];

       int maximo = 0;
       int indice = 0;
       ll res = 0;

       for(int i = 0; i < n; i++){
        if(nums[i] == 0){
            maximo = 0;
            for(int j = 0; j < i; j++){
                if(nums[j] > maximo){
                    maximo = nums[j];
                    indice = j;
                }
            }

            nums[indice] = 0;

            res += maximo;

        }
       }

       cout << res << endl;
    }

}
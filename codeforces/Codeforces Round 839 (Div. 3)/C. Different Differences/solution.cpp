#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vii vector<vector<int>>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;



int main(){

    optimize;


    int t;

    cin >> t;

    while(t--){
        int k,n;

        cin >> k >> n;

        int proximo = 1;
        int aux = 1;
        int num = 0;

        vector<int>res;

        while(num != k){
            res.push_back(proximo);
            num++;
            if(n - (proximo + aux)  + 1 >= k - num){
                proximo += aux;
                aux++;
            }
            else{
                proximo++;
            }

            
        }

        for(int x : res) cout << x << " ";

        cout << endl;


    }

}
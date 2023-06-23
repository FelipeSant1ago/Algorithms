#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vii vector<vector<int>>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;

string A, B;

bool check(int x){

    int cont = 0;
    for(int i = 0; i < B.size(); i++){
        int procurado = x;
        for(int j = cont; j < A.size(); j++){
            if(A[j] == B[i])procurado--;
            cont = j+1;
            if(procurado == 0) break;
        }
        if(procurado > 0) return false;

        
    }


    return true;

}


int main(){

    optimize;

    int t;
    cin >> t;

    while(t--){
        

        cin >> A >> B;


        int l = 0, r = 1e5;
        int res = 0;
        while(l <= r){
            int mid = (l + r)/2;
            if(check(mid)){
                res = mid;
                l = mid + 1;

            }
            else{
                r = mid - 1;
            }
        }


        cout << res << endl;
    }
    

    





}
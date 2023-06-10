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

        string s;

        cin >> s;
        int res = 1;
        char x1 = s[0] ,x2 = s[1];

        for(int i = 1; i < n-1; i++){
            res++;
            if((s[i] == x1 && s[i+1] == x2) || (s[i] == x2 && s[i+1] == x1)){
                res--;
            }

            x1 = s[i+1];
            x2 = s[i];

        }


        cout << res << endl;
    }
    


}
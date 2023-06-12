#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vii vector<vector<int>>
using namespace std;


int main(){
    string pi = "314159265358979323846264338327";

    int t;
    cin >> t;

    while(t--){
    
        int res = 0;
        string s;
        cin >> s;

        for(int i = 0; i < s.size();i++){
            if(s[i] == pi[i])res++;
            else break;
        }

        cout << res << endl;
    }

}
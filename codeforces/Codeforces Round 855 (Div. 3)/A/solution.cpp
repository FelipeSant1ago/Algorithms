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
        for(int i = 0; i < n; i++){
            s[i] = tolower(s[i]);
        }

        s.erase(unique(s.begin(),s.end()),s.end());
        if(s == "meow") cout << "YES" << endl;
        else cout << "NO" << endl;
    
            
            

        

    }

}
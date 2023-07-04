#include<bits/stdc++.h>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ll long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define pii pair<int,int>
#define MAXN 1000000
#define INF 1000000007
using namespace std;



int main(){
    optimize;


    unordered_map<int,int>freq;
    int aux;

    for(int i = 1; i <= 4; i++){
        cin >> aux;
        freq[i-aux]++;
        freq[i+aux]++;

    }

    for(auto it : freq){
        if(it.second == 3){
            cout << it.first << endl;
            break;
        }
    }



}
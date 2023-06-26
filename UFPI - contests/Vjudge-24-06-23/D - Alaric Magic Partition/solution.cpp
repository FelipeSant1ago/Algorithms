#include<bits/stdc++.h>
#define vi vector<int>
#define vvi vector<vector<int,int>>
#define pii pair<int,int>
#define ll long long


using namespace std;

int main(){


    int k;

    cin >> k;

    int res = 0;

    while(k--){
        char x;
        cin >> x;
        if(x == '1' || x =='2' || x=='3' ||x=='4'|| x=='5' || x=='7' || x=='9'){
            res++;
        }
    }


    cout << res << endl;






}
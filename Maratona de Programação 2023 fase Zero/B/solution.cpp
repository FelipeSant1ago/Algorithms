#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vii vector<vector<int>>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;



int main(){

    optimize;

    ll A, B, C;

    cin >> A >> B >> C;

    char procurado;
    cin >> procurado;

    if(procurado == 'A'){
        A += (3LL*B + 5LL*C)/2LL;
        cout << A << endl;
    }
    else if(procurado == 'B'){
        B += (A*2LL + 5LL*C)/3LL;
        cout << B << endl;
    }
    else if(procurado == 'C'){
        C += (2LL*A + 3LL*B)/5LL;
        cout << C << endl;
    }

}
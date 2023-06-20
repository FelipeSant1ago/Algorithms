#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vii vector<vector<int>>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;



int main(){

    optimize;

    char x1,x2,x3;

    cin >> x1 >> x2 >> x3;

    int contO = 0, contX = 0;
    if(x1 == 'X') contX++;
    else contO++;
    if(x2 == 'X') contX++;
    else contO++;
    if(x3 == 'X') contX++;
    else contO++;

    if(contX >= 3 || contO >= 2){
        cout << "?" << endl;
    }
    else if(x2 == 'O') cout << '*' << endl;
    else cout << "Alice" << endl;
    


}
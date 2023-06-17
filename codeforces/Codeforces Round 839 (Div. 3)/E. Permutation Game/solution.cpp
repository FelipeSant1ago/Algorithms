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
        int n;
        cin >> n;

        int p1 = 0,p2 = 0,emcomum = 0;

        for(int i = 1; i <= n; i++){
            int aux;
            cin >> aux;
            if(aux != i &&  aux != n-i+1){
                emcomum++;
                p1++;
                p2++;
            }
            else if(aux != i){
                p1++;
            }
            else if(aux != n-i+1){
                p2++;
            }
        }

        while(p1 >=1 && p2>=1){
            if(p1 > emcomum)p1--;
            else if(p2-1 > 0){
                emcomum--;
                p1--;
                p2--;
            }
            if(p1 == 0){
                cout << "First" << endl;
                break;
            }

            if(p2 > emcomum)p2--;
            else if(p1-1 > 0){
                emcomum--;
                p1--;
                p2--;
            }

            
            if(p2 == 0){
                cout << "Second" << endl;
                break;
            }

            if(p1 <= emcomum && p2 <= emcomum && p2-1 == 0 && p1-1 == 0){
                cout << "Tie" << endl;
                break;
            }
        }


    }

}
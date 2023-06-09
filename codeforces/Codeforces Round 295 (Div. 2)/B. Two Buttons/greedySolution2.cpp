#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vii vector<vector<int>>
using namespace std;



//solution 2 : partindo de m e usando +1 ou /2 para chegar em n;
int main(){
    int original, target;
    cin >> original >> target;
    swap(original,target);

    int res = 0;
    if(original < target) res = target - original;
    else{
        while(original != target){
            if(original < target){
                res += target - original;
                original = target;
            }else{
                if(original %2 == 0){
                    res++;
                    original /= 2;
                }
                else{
                    res += 2;
                    original++;
                    original/=2;
                }
            }
        }
    }


    cout << res << endl;
}




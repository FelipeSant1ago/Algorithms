#include<bits/stdc++.h>


using namespace std;







int main(int argc, char const *argv[]){
    string s;

    cin >> s;
    bool ab = false, ba = false;
    for(int i = 0; i < s.size() - 1; i++){
        if(ab == false && s[i] == 'A' && s[i + 1] == 'B' ) {ab = true; i++;}
        else if(ab == true && s[i] == 'B' && s[i + 1] == 'A'){
            ba = true;
            break;
            
        }

    }
   
    if(ab && ba) cout << "YES" << endl;
    else{
        ab = false;
        ba = false;


        for(int i = 0; i < s.size() - 1; i++){
        if(ba == false && s[i] == 'B' && s[i + 1] == 'A') {ba = true;i++;}
        else if(ba == true && s[i] == 'A' && s[i + 1] == 'B'){
            ab = true;
            break;
            
        }

    }
    if(ab && ba) cout << "YES" << endl;
    else cout << "NO" << endl;

    }
    
    return 0;
}

#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vii vector<vector<int>>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;

bool ehBonitorow(int x1,int x2,int y1,int y2){
    if(x1 < x2 && y1 < y2) return true;

    return false;
}

bool ehBonitocol(int x1,int x2,int y1,int y2){
    if(x1 < y1 && x2 < y2) return true;

    return false;
}

int main(){

    optimize;

    int t;

    cin >> t;
    while(t--){
        bool res = false;
        int x1,x2,y1,y2;

        cin >> x1 >> x2 >> y1 >> y2;

        if(ehBonitorow(x1,x2,y1,y2) &&  ehBonitocol(x1,x2,y1,y2)) res = true;
        if(ehBonitorow(y2,y1,x2,x1) && ehBonitocol(y2,y1,x2,x1)) res = true;
        if(ehBonitorow(y1,x1,y2,x2) && ehBonitocol(y1,x1,y2,x2)) res = true;
        if(ehBonitorow(x2,y2,x1,y1)&& ehBonitocol(x2,y2,x1,y1)) res = true;


        if(res) cout << "YES" << endl;
        else cout << "NO" << endl;


        


    }

}
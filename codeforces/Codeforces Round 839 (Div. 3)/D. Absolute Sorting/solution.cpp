#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vii vector<vector<int>>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;


int ehPico(vi& arr, int n){

    int l = 0;

    while(l < n-1 && arr[l+1] >= arr[l])l++;
    int pico = arr[l];
    if(l == 0) return -1;
    while(l < n-1 && arr[l] >= arr[l+1])l++;
    if(l != n-1) return -1;

    return pico;



}



int main(){

    optimize;

    int t;
    cin >> t;

    while(t--){
        int n;

        cin >> n;

        int prev, curr;
        cin >> prev;
        int left = 0, right = 1e9;

        for(int i = 1; i < n; i++){
            cin >> curr;

            if(prev < curr){
                right = min(right, int(floor((prev+curr)/2.0)));
            }
            else if (prev > curr){
                left = max(left, int(ceil((prev + curr)/2.0)));
            }

            prev = curr;

        }


        if(left <= right) cout << left << endl;
        else cout << -1 << endl;


       

    }

}
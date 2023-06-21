#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vii vector<vector<int>>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;

int binarySearch(vi& arr, int x){
    int l = 0;
    int r = arr.size()-1;
    int res = arr.size() ;
    int mid;

    while(l <= r){
        mid = (l + r)/2;

        if(arr[mid] == x){
            if( mid < res) res = mid;
            r = mid - 1;
        }
        else if(arr[mid] > x){
            r = mid - 1;
            if( mid < res) res = mid;

        }
        else{
            l = mid + 1;
        }
    }

    return res  + 1;
}



int main(){

    optimize;

    int n, q;

    cin >> n >> q;

    vi arr(n);

    for(int i = 0; i < n; i++) cin>> arr[i];

    for(int i = 0; i < q; i++){
        int x;
        cin >> x;
       cout << binarySearch(arr,x) << endl;
    }

    

}
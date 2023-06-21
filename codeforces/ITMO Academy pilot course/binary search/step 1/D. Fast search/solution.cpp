#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vii vector<vector<int>>
#define optimize ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;

int lowerBound(vi& arr, int x){
    int l = 0;
    int r = arr.size()-1;
    int res = arr.size();
    int mid;

    while(l <= r){
        mid = (l + r)/2;
        if(arr[mid] == x){
            if(mid < res) res = mid;
            r = mid - 1;
        }
        else if(arr[mid] < x){
            l = mid + 1;
        }
        else{
            if(mid < res) res = mid;
            r = mid - 1;
        }
    }

    

    return res;
}


int upperBound(vi& arr, int x){
    
    x++;
    int l = 0;
    int r = arr.size()-1;
    int res = arr.size();
    int mid;

    while(l <= r){
        mid = (l + r)/2;
        if(arr[mid] == x){
            if(mid < res) res = mid;
            r = mid - 1;
        }
        else if(arr[mid] < x){
            l = mid + 1;
        }
        else{
            if(mid < res) res = mid;
            r = mid - 1;
        }
    }

    

    return res;
}



int main(){

    optimize;
    int n, q;
    

    cin >> n ;

    vi arr(n);

    for(int i = 0; i < n; i++) cin>> arr[i];
    cin >> q;
    sort(arr.begin(),arr.end());
    for(int i = 0; i < q; i++){
        int l,r;
        cin >> l >> r;
        int ub = upperBound(arr,r);
        int lb = lowerBound(arr,l);
        if(lb == ub) cout << 0 << " ";
        else cout << ub - lb << " ";
       
    }
    cout << endl;

    

}
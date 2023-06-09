#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
#define vii vector<vector<int>>
using namespace std;

bool ehPrimo(int n){
    for(int i = 2; i*i <= n; i++){
        if(n%i == 0)return false;

    }
    return true;
}



int main(){

    vector<long long>Tprimos;


    int n;
    cin >> n;
    ll aux;

    vector<ll> nums(n);

    for(int i = 0; i < n; i++) cin>> nums[i];

    //Calculando os números primos de 2 até 10^6 O(nsqrt(n))
    // for(int i = 2; i < 1000000; i++){
    //     if(ehPrimo(i)){
    //         aux = i;
    //         aux *= aux;
    //         Tprimos.push_back(aux);
    //     }
    // }

    //Usando sieve of Eratosthenes O(n log log n)
    vector<bool>erathostenes(1000001,true);
    for(int i = 2; i*i <= 1000000; i++){
        if(erathostenes[i]){
            for(int j = i*i; j <= 1000000;j+=i){
                erathostenes[j] = false;
            }
        }

    }
    for(int i = 2; i <= 1000000; i++){
        if(erathostenes[i]){
            aux = i;
            aux *= aux;
            Tprimos.push_back(aux);
        }
    }

    for(ll x : nums){
        auto it = lower_bound(Tprimos.begin(),Tprimos.end(),x);
        if(it != Tprimos.end() && *it == x) cout << "YES" << endl;
        else cout << "NO" << endl;
    }






}
#include<bits/stdc++.h>
using namespace std ;

const int N = 10e6+1 ; 
vector <int> sum (N) , prime ; 
// for optimization 
bitset <N> sieve ; 

void eratosthenes(){
    for ( int i = 3 ; i*i <N ; i+=2)
        if (!sieve[i])
        // for optimization 
            for ( int j = i*i ; j < N ; j+=i )
                sieve[j] = true ; 
    
    for ( int i = 3 ; i < N ; i+=2)
        if (!sieve[i])
        // for optimization 
            prime.push_back(i) ; 
}

void precalc(){
    // if there is tuple then increase value at cth index by 1 
    for ( auto x : prime)
        if ( x+2 < N and !sieve[x+2])
            ++sum[x+2] ; 
    // keep adding all numbers for precalculating purpose 
    for ( int i = 1 ; i< N ; ++i)
        sum[i]+=sum[i-1] ; 
    
}

void test_case(){
    int n ; cin >> n ; 
    cout << sum[n] << endl ; 
}
 int32_t main(){
     ios_base :: sync_with_stdio(false) ; 
     cin.tie(nullptr) ; 
     cout.tie(nullptr) ; 
     eratosthenes() ; 
     precalc() ; 
     int t ; cin >> t ;
     while(t--){
         test_case()  ; 
     }
 }
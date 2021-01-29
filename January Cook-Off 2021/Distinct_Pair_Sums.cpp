#include<iostream>
using namespace std ;
int main(){
    int t ; cin >> t ; 
    while(t--){
        int l , r ; cin >> l >> r ; 
        int n = r-l ; 
        if ( l == r)
            cout << 1 << endl ; 
        else 
            cout << 2*(n)+1 << endl ; 
    }
    return 0 ; 
}
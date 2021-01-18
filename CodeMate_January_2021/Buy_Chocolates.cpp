#include<bits/stdc++.h>
using namespace std ;
#define end '\n'
#define int int64_t 
#define ll long long int 
#define pb push_back
#define T() int t ; cin >> t ; while(t--) 
#define IFS  ios_base :: sync_with_stdio(false) ; cin.tie(NULL) ; cout.tie(NULL) ;
int32_t main(void){
    IFS ; 
    T(){
        int x , y ,z ; cin >> x >> y >> z ; 
        int ans = x/z+y/z; 
        x%=z ;
        y%=z ;
        if ( (x +y) >= z)
            cout << ans +1 << ' ' <<  z - max(x,y) << endl ;
        else 
            cout << ans << ' ' << 0 << endl ; 
    }
    return 0 ; 
}
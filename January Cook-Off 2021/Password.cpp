#include<iostream>
using namespace std ;
#define ll long long 
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
void go(){
    string s ; cin >> s ; 
    bool len = 0 , small  = 0 , large = 0 , num = 0 , sym = 0 ; 
    int n = s.size() ; 
    if ( n>=10)
        len =1  ; 
    for ( int i = 0 ; i < n ; i++){
        if (s[i]>='a' and s[i]<='z')
            small = 1 ;
        if (i!=0 and i!=n-1){
            if (s[i]>='A' and s[i]<='Z')
                large = 1 ; 
            if (s[i]>='0' and s[i]<='9')
                num = 1 ;
            if (s[i] == '@' or s[i] == '#' or s[i]=='&' or s[i] == '?' or s[i] == '%')
                sym = 1 ;
        }
    }
    if ( len and small and large and num and sym )
        cout << "YES\n" ;
    else 
        cout << "NO\n" ; 
}

int main(){
    FAST ; 
    int t ; cin >> t ; 
    while(t--) {
    go() ; 
    }
    return 0 ; 
}
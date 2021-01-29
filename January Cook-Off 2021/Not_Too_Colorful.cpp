#include<bits/stdc++.h>
using namespace std ;
#define ll long long  

int main(){ 
    ios :: sync_with_stdio(false) ; 
    cin.tie(nullptr) ; 
    cout.tie(nullptr) ; 
    int t ; cin >> t ; while(t--){
        // declaring variables 
        ll n , m , r , g , b , i , j ; cin >> n >> m >> r >> g >> b ;

        char grid[n][m] ;
        // for keeping track of left over cells for max tiles 
        for ( i  = 0 ; i < n ; i++)
            for ( j = 0 ; j < m ;j++)
                grid[i][j] = '*' ;  

        // creating vector for tracking min and max tiles 
        vector <pair <ll , char>> col ; 
        col.push_back({r , 'R'}) ; 
        col.push_back({g , 'G'}) ; 
        col.push_back({b , 'B'}) ; 
        sort ( col.begin() , col.end()) ; 

        // distributing first min color tiles at even parity cells 
        ll count = col[0].first ; 
        for ( i = 0 ; i < n ; i++ )
            for ( j = 0 ; j < m ; j++)
                if ( (i+j)%2 == 0 and count != 0 ){
                    grid[i][j] = col[0].second ; 
                    count-- ; 
                }
        
        // distributing second min colors tiles at odd parity celss 
        count = col[1].first ; 
        for ( i = 0 ; i < n ; i++)
            for ( j = 0 ; j < m ; j++)
                if ((i+j)%2 != 0 and count !=0){
                    grid[i][j] = col[1].second ; 
                    count-- ; 
                }
        
        // distributing rest of the tiles 
        count = col[2].first ; 
        for ( i = 0 ; i < n ; i++)
            for ( j = 0 ; j < m ; j++)
                if (grid[i][j] == '*' and count != 0 ){
                    grid[i][j] = col[2].second ;
                    count-- ;  
                }
        // outputing the grid 
        for ( i = 0 ; i < n ; i++){
            for ( j = 0 ; j < m ; j++)
                cout << grid[i][j] ; 
            cout << endl ; 
            }

    }
    return 0 ; 
}
#include<bits/stdc++.h>
using namespace std ;
#define end '\n'
#define int int64_t 
// dfs 
void dfs( int u , vector <vector <int>> &graph , vector <bool> &visited){
    visited[u] = true ; 
    for ( int v : graph[u]){
        if (!visited[v])
            dfs(v,graph , visited) ; 
    }
}
int32_t main(){
    ios :: sync_with_stdio(false) ; 
    cin.tie(NULL) ;
    cout.tie(NULL) ; 
    int n , m ; cin >> n >> m ; 
    int a , b ;  cin >> a >> b ; 
    // declaring graph dynamically - cache friendly as compared to static array
    vector <vector <int>> graph(n+1) ; 
    // adding edges
    for ( int i = 0 , u , v ; i < m ; ++i){
        cin >> u >> v ; 
        graph[u].push_back(v) ; 
        graph[v].push_back(u) ; 
    }
    // c  - total cost of anti virus 
    int c = 0 ; 
    vector <bool> visited(n+1, false) ; 
    /*
    instead of declaring dfs function outside the main function
    we can use 
    function <void(int)> dfs = [&](int u) {
        visited [u] = true ; 
        for ( int v : graph[u]){
            if (!visited[v]) 
                dfs(v) ; 
        }
    })
    */
    // bool for visiting the array 
    for ( int i = 1 ; i <= n ; ++i){
        if (!visited[i]){
            dfs(i , graph , visited) ; 
            ++c ; 
        }
    }
    // getting total price of antivirus 
    int ans = c*a;
    // w - number of wires 
    int w = 0 ; 
    // getting min cost while considering wire as well 
    // eg suppose networ needs 2 antivirus . Will 1 antivirus and 1 wire  cost us cheaper than price of 2 antivirus . 
    while(c !=1 ){ 
        ++w ;
        --c ; 
        ans = min(ans , w*b + c*a) ;  
    } 
    // output the min cost required 
    cout << ans << endl ; 
    return 0 ;
}
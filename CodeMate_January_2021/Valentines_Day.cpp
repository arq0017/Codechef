#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> vii;
typedef map<int,int> mii;
typedef pair<int,int> pii;
#define ll long long 
#define f(i,a,b) for(int i = (int)a;i<(int)b;i++)
#define loop(a) for ( int i = 0 ; i < a ; i++)
#define rev(i,n) for(int i=n-1;i>=0;i--)
#define endl "\n"
#define T() int t ; cin >> t ; while(t--)
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
unsigned long long M=1000000007 ; 
// using kadane's algorithm 
int main(){
   T(){
      int n ;cin >> n ;
      int arr[n] ; 
      loop(n) cin >> arr[i] ;
      int max = 0 ; 
      int store = 0 ; 
      loop(n){
         max +=arr[i] ; 
         if ( max > store)
            store = max ; 
         if ( max < 0 )
            max = 0 ; 
      }
      cout << store << endl ; 
   }
   return 0 ; 
}
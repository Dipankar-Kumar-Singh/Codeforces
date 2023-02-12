#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases   int _test {1} ; cin >> _test ; while(_test--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 


void solve()
{
   int x , y ; cin >> x >> y ;
   if(y<x or (y%x!=0))
   {
       cout << "0 0\n" ;    
       return ;
   }

   cout << 1 << " " << (y/x) << "\n" ;
 

}

signed main()
{   FAST  

    TestCases  
    solve() ;  

}


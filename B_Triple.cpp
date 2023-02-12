#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases   int _test {1} ; cin >> _test ; while(_test--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 


void solve()
{
   map<int,int> m ;
   int n;  cin>>n ;

   int ans = -1 ;

   for (int i = 0; i < n; i++)
   {
       int x;
       cin >> x;
       m[x]++;
       if (m[x] >= 3)
       {
           ans = x ;
       }
   }
   
   cout << ans << nl ;
}

signed main()
{   FAST  

    TestCases  
    solve() ;  
}


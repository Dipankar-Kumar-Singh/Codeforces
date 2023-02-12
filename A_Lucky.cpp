#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases   int _test {1} ; cin >> _test ; while(_test--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 


void solve()
{
   string s ; cin >> s ;
   int s1 = 0 , s2 = 0 ;
   for(int i = 0 ; i < 3 ; i++) s1 += (s[i]-'0') ;
   for(int i = 3 ; i < 6 ; i++) s2 += (s[i]-'0') ;


   cout << ((s1==s2)  ? "YES"  : "NO") << nl ;

}

signed main()
{   FAST  

    TestCases  
    solve() ;  

}


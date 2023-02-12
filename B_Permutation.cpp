#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases   int _test {1} ; cin >> _test ; while(_test--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 


void solve()
{
   int n ; cin >> n ;
   vector<int> v  ; 

   cout << 2 << nl ;

   set<int> s ; 

   for(int i = 1 ; i <= n ; i++) 
    s.insert(i) ;

   while(s.size())
   {
        int x = *s.begin(); 

 
        for(int i = x ; i <= n ; i += i)
        {
            auto it = s.find(i) ;
            if(it == s.end()) 
            {
                break ; 
            }
            v.push_back(*it) ;
            s.erase(it) ;      
        }
   }
   

   for(auto x : v) cout << x << " " ;
   cout << nl ;


}
signed main()
{   
    
    FAST  

    // pr

    TestCases      
    solve() ; 


    }

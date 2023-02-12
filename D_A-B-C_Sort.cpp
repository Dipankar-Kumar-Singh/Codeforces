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
   vector<int> v(n) ;
   for(auto &x : v)  cin >> x ;

   for (int i = n-1 ; i - 1 >= 0 ; i-=2)
       if (v[i-1] > v[i])
           swap(v[i], v[i - 1]);

    for (int i = 0; i + 1 < n; i++)
        if (v[i] > v[i + 1])
        {
            cout << "NO\n";
            return;
        }

   cout << "YES\n";


}

signed main()
{   FAST  

    TestCases  
    solve() ;  

}


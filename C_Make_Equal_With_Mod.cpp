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

   for(auto &x : v) cin >> x ;

   set<int> s(all(v)) ;

    if(s.size()==1)
    {
        cout << "YES\n" ;
        return ;
    }


    if(s.count(1))
    {
        if(s.count(2) or s.count(0))
        {
            cout << "NO\n" ;
            return ;
        }


        v.clear() ;

        for(auto &x : s) v.push_back(x) ;

        sort(all(v)) ;
        reverse(all(v)) ;


        for(int i = 0 ; i + 1 < v.size() ; i++)
        {

            int x = v[i] - 1 ;
            if(x<2) break;

            v[i] = (v[i] % x);

            if (i + 1 < n)
                v[i + 1] = (v[i + 1] % x);
        }


        set<int> ss(all(v)) ;
        if(ss.size()==1)
        {
            cout << "YES\n" ;  return ;
        }
        else 
        {
            cout << "NO\n" ; return ;
        }
    }

    else 
    {
        // 0 , 2 , 3 , 4 
        cout << "YES\n" ;
        
    }

}

signed main()
{   FAST  

    TestCases  
    solve() ;  

}


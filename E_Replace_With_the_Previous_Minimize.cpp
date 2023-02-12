#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases   int _test {1} ; cin >> _test ; while(_test--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 



void solve()
{
    int n , k ; cin >> n >> k ;
    vector<char> v(n);
    for(int i = 0 ; i < n ; i++)
    {
        cin >> v[i] ;
    }

    char best = 'a' ;

    for(int i = 0 ; i < n ; i++)
    {
        best = ((v[i] - 'a' <= k) ? max(best, v[i]) : best);
    }

    for(int i = 0 ; i < n ; i++)
    {
        if(v[i]<=best) v[i] = 'a' ;
    }

    k -= (best-'a') ;

    for(int i = 0 ; i < n ; i++)
    {
        if(v[i]>'a' and k>0)
        {
            while(v[i]>'a' and  k>0)
            {
                auto cur = v[i] ;
                for(int j = i ; j< n ; j++)
                {
                   if(v[j]-1>'a'){ v[j]--;}
                }
                k-- ;
            }
        }
    }

    for(int i = 0 ; i < n ; i++)
    {
        cout << v[i]  ;
    }

    cout << nl ;


}

signed main()
{   FAST  

    TestCases  
    solve() ;  

}


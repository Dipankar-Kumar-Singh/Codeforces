#include <bits/stdc++.h>
using namespace std;
#define TestCases   int _test {1} ; cin >> _test ; while(_test--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);

void solve()
{
    int n; cin >> n ;
    vector<int> a(n) , b(n);
    for(auto &x : a) cin >> x ;
    for(auto &x : b) cin >> x ;

    int curr = a.front() ;
    for(int i = 0 ; i < n ;i++)
    {
        int d = 0 ;

        if(a[i]<curr) 
        {
            d =  b[i] - curr  ;
            curr = b[i] ;
        }

        else 
        {
            d = b[i] - a[i] ;
            curr = b[i] ;
        }
 
        cout << d << " " ;
    }

    cout <<  "\n" ;

}

signed main(){   FAST      TestCases      solve() ;  }

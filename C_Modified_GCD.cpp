#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases   int _test {1} ; cin >> _test ; while(_test--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 

int a , b ;
set<int> s ;

void solve()
{
    int l, r;
    cin >> l >> r;

    auto it = s.upper_bound(r) ;
    --it ;

    int num = *it ;

    if(num>=l and num<=r)
    {
        cout << num  << nl ;
    }

    else cout << -1 << nl ;
}

signed main()
{
    FAST

    cin >> a >> b;

    int x = gcd(a,b) ;
    int curr = x ;
    for(int i = 1 ; i*i <= x ; i++)
    {
        if (x % i == 0)
            s.insert(i),
                s.insert(x / i);
    }

    TestCases  
    solve() ;  

}


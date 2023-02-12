#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCase   int _test {1} ; cin >> _test ; while(_test--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n"  

void solve() 
{
    multiset<int> s ;
    int ans = 0 , n, k;  cin >> n >> k;
    
    for(int i = 0  ; i < n ; i++)
    {
        int x ; cin >> x ; s.insert(x) ;
    }

    while (!s.empty())
    {
        auto num  = *(s.begin()) ;   s.erase(s.begin()) ;
        int f = (num*k) ;
        if(s.count(f))   s.erase(s.find(f)) ; 
        else  ans++ ;
    }
    
    cout << ans << nl ;
}

signed main(){   FAST      TestCase      solve() ;  }


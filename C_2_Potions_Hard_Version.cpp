#include <bits/stdc++.h>
using namespace std;
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);

void solve()
{
    int n ; cin >> n ;
    vector<int> v(n) ; 
    for(auto &x : v) cin >> x ;
    
    multiset<int> s  ;
    long long sum = 0 ; 
    
    for(auto x : v) 
    {
        sum += x ;
        s.insert(x) ;
        while(sum < 0)
        {   
            sum -= (*s.begin()) ;
            s.erase(s.begin()) ;
        }
    }

    cout << s.size() << endl  ;
}
signed main(){   FAST     solve() ;  }




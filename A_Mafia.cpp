#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
long long ceil(long long a, long long b) {    if (a == 0) return 0;    return (a - 1)/b + 1;}

signed main()
{   FAST  

    int n ; cin >> n ;
    vector<int> v(n) ;
    for(auto &x : v) cin >> x ;

    int ans = ceil(accumulate(all(v),0LL) , n-1) ;
    cout << max(ans, *max_element(all(v))) ;
    
}


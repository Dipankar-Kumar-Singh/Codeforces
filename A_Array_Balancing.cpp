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
    vector<int> a(n) , b(n) ;
    for(auto &x : a) cin >> x ;
    for(auto &x : b) cin >> x ;
    
    int s = 0 ; 

    for(int i = 0 ; i + 1 < n ; i++)
    {
        int t1 = abs(a[i] - a[i+1]) + abs(b[i]-b[i+1]) ;
        int t2 = abs(b[i]-a[i+1]) + abs(a[i] - b[i+1]) ;

        s += min(t1 ,t2) ;
        if(t2 < t1) swap(a[i],b[i]) ;
    }

    cout << s << nl ;
    



}

signed main()
{   FAST  

    TestCases  
    solve() ;  

}


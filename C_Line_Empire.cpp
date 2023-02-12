// Problem: C. Line Empire
// Contest: Codeforces - Codeforces Round #782 (Div. 2)
// URL: https://codeforces.com/contest/1659/problem/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases   int _test {1} ; cin >> _test ; while(_test--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 
int const INF = LONG_LONG_MAX ;

int BEST = INF ;

int curr_cost( vector<int> &v , int a , int b , int loc)
{
    if(loc<0) loc = 0 ; 
    if(loc>=v.size()) loc = v.size() -1 ;

    int cap = 0 ;
    int res = 0 ;

    for(int i = 0 ; i <= loc ; i++)
    {
        int d = abs(cap-v[i]) ;
        res += d*b ;
        res += d*a ;
        cap = v[i] ; 
    }

    for(int i = loc+1 ; i < v.size() ; i++)
    {
        int d = abs(cap- v[i]) ;
        res += d*b ;
    }

    BEST = min(BEST , res) ;
    cerr << res << nl ;
    return res ;
}


double ternary_search(vector<int> &v , int a, int b ,double l, double r) {
    double eps = 1e-9;              //set the error limit here
    while (r - l > eps) {
        double m1 = l + (r - l) / 3;
        double m2 = r - (r - l) / 3;
        double f1 = curr_cost(v,a,b,m1);      //evaluates the function at m1
        double f2 = curr_cost(v,a,b,m2);      //evaluates the function at m2
        if (f1 < f2)
            l = m1;
        else
            r = m2;
    }
    return curr_cost(v,a,b,l);                    //return the maximum of f(x) in [l, r]
}

void solve()
{
    BEST = INF ;
   int n; cin >> n;
   int a, b  ; cin >> a >> b ;
   
   vector<int> v(n) ;
   
   for(auto &x : v) cin >> x  ;

x
   
   int ans = INF ;

   int l = 0 , r = n  ;

    while(r-l>1)
    {
        int mid = (l+r)/2 ;
        int M = curr_cost(v,a,b,mid) ;
        
        if(M<=ans) {r = mid ;}
        else l = mid ; 

        ans = min(ans,M) ;
    }

    cout << curr_cost(v,a,b,r) <<nl ; return ;

//    while(r-l>1)
//    {
//        int mid = (r+l)/2 ;
//        int M = curr_cost(v,a,b,mid) ;
//        int L = curr_cost(v,a,b,mid-1) ;
//        int R = curr_cost(v,a,b,mid+1) ;

//        if(L < M < R)
//        {
//            r = mid ;
//        }

//        else if(L > M > R)
//        {
//            l = mid ;
//        }

//        else if( L >= M and M <= R)
//        {
//            l = r = mid ;
//        }
//    }

//     cout << BEST << nl ;
//     return ;

//    cout << curr_cost(v,a,b,l) << nl ;




   
   


}

signed main()
{   FAST  

    TestCases  
    solve() ;  

}


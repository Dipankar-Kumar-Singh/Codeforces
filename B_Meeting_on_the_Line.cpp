#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases   int total ; cin >> total ;  for(test = 1 ; test <=  total ; test++)
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n"  
#define print(ans) cout << "Case #" << test << ": " << ans << "\n" ;


int const INF  = 1e18 ;
int test = 0 ;

int n ;
vector<int> v , t ;

bool f(double p)
{   
    int maxTime = 0 ;
    for(int i = 0 ; i < n ; i++)
    {
        
    }
}

double ternary_search(double l, double r) {
    double eps = 1e-9;              //set the error limit here
    while (r - l > eps) {
        double m1 = l + (r - l) / 3;
        double m2 = r - (r - l) / 3;
        double f1 = f(m1);      //evaluates the function at m1
        double f2 = f(m2);      //evaluates the function at m2
        if (f1 < f2)
            l = m1;
        else
            r = m2;
    }
    return f(l);                    //return the maximum of f(x) in [l, r]
}



void solve()
{
    int ans = 0 ; 
    int n ; cin >> n ;
    vector<int> v(n) ; for(auto &x : v) cin >> x ; 
    vector<int> t(n) ; for(auto &x : t) cin >> x ;

    double sum = accumulate(all(v),0) ; 
    int time = accumulate(all(t),0)   ;
    double p = (sum/n)  ; 
    cout << p << nl ;
    
    

    

}

signed main(){  FAST    TestCases    solve() ; }
#include <bits/stdc++.h>
using namespace std;
#define int     long long
#define all(x)  begin(x) , end(x)
#define nl      "\n" 
#include"/home/dk/debugging.h"

//  g++ 1.cpp && ./a.out


double first3(vector<int> &v) {
    double ans = (v[0]*1LL  + v[2]*1LL) / 2.0 ;
    return ans ;
}
double last3(vector<int> &v) {
    double ans = (v[v.size()-1]*1LL  + v[v.size()-3]*1LL) / 2.0 ;
    return ans ;
}

double first2(vector<int> &v) {
    double ans = (v[0]*1LL  + v[1]*1LL) / 2.0 ;
    return ans ;
}
double last2(vector<int> &v) {
    double ans = (v[v.size()-1]*1LL  + v[v.size()-2]*1LL) / 2.0 ;
    return ans ;
}


void solve(int& __case__)
{   
    cout << "Case #" << __case__ << ": " ;

    cout << setprecision(10) ;

    int n; cin >> n ;
    vector<int> v (n) ;
    for(auto &x : v) cin >> x ;
    sort(all(v)) ;

    if(n == 5) {
        double ans = 0 ;
        double ans1 =  last3(v) - first2(v) ;
        double ans2 =  last2(v) - first3(v) ;
        ans = max(ans1,ans2) ;
        cout << ans << nl ;
        return ; 
    }

    double ans = last2(v) - first2(v) ;
    cout << ans << nl ;

}

signed main()
{   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    freopen("input.txt", "r+", stdin);
    freopen("output.txt", "w+", stdout);
    int testCases = 1 , case_ = 1;     
    cin >> testCases; for (int case_ = 1; case_ <= testCases; case_++) 
        solve(case_);
}

#include <bits/stdc++.h>
using namespace std;
#define int     long long
#define all(x)  begin(x) , end(x)
#define nl      "\n" 
// #include"/home/dk/debugging.h"

void solve(int& __case__)
{
    int n; cin >> n ;
    vector<int> v(n) ;
    for(auto &x : v) cin >> x ;
    int k ; cin >> k ; 

    vector<int> ans(n) ;

    int mn = *min_element(begin(v),end(v)) ;
    for(int i = n - 1 ; i >= 0 ; i--) {
        
        int x = v[i] ; 

        if(x == mn) {

            int divd = k / x ;

            if(divd == 0 ) {
                break;
            }

            if(divd * x == k){
                for(int j = 0 ; j <= i ; j++){
                    ans[j] = divd ;
                }

            } else {

                int rem = k - divd * x ;
                divd-- ;
                rem += x ;

                for(int t = 0 ; t <= i ; t++){
                    ans[t] += divd ;
                }

                for(int j = n - 1 ; j >= 0 ; j--) {
                    if(v[j] <= rem) {
                        rem -= v[j] ; 
                        for(int t = 0 ; t <= j ; t++){
                            ans[t]++ ;
                        }
                        break;
                    }
                }
            }

            break;
        }
    }

    for(auto x : ans) {
        cout << x << " " ; 
    } cout << nl ;

}

signed main()
{   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int testCases = 1 , case_ = 1;     
    cin >> testCases; for (int case_ = 1; case_ <= testCases; case_++) 
        solve(case_);
}

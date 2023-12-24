#include <bits/stdc++.h>
using namespace std;
#define int     long long
#define all(x)  begin(x) , end(x)
#define nl      "\n" 
// #include"/home/dk/debugging.h"

void solve(int& __case__)
{
    int n; cin >> n ;
    vector<int> v ;
    for(int i = 0 ; i < n ; i++){
        int x; cin >> x ;
        if(v.empty() or v.back()==0 or x == 0 ) v.push_back(x) ;
        else v.back() = max(x , v.back()) ;
    } 

    n = v.size() ;
    vector<int> red(v.size()) ;
    int ans = 0 ;

    for(int i = 0 ; i < v.size() ; i++){
        if(v[i]) {
            ans++ ;
            red[i] = 1 ;
        }
    }

    for(int i = 0 ; i < v.size() ; i++){
        if(v[i] >= 2){
            if(i > 0) red[i - 1] = 1 ;
            if( i + 1 < v.size() ) red[ i + 1 ] = 1 ;
        }
    }

    for(int i = 0 ; i < v.size() ; i++){
        if(v[i] == 1) {
            if(i > 0 && !red[i - 1]) red[i - 1] = 1 ;
            else if( i + 1 < v.size()&& !red[i + 1] ) red[i + 1] = 1 ;
        }
    }

    for(int i = 0 ; i < v.size() ; i++){
        if(v[i] == 0 && !red[i]) {
            red[i] = 1 ;
            ans++ ;
        }
    }

    cout << ans << nl ;
}

signed main()
{   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int testCases = 1 , case_ = 1;     
        solve(case_);
}

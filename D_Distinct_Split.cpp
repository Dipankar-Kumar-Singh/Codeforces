#include <bits/stdc++.h>
using namespace std;
#define int     long long
#define all(x)  begin(x) , end(x)
#define nl      "\n" 


int f(map<char,int> &m)
{
    int ans = 0 ;
    for (auto &[x, fr ] : m)
        if(fr >= 1) ans++ ;
    return ans;
}


void solve(int& __case__)
{

    int n ; cin >> n ;
    string s; cin >> s ;

    map<char,int> m1 , m2 ;

    for(char c : s) m2[c]++ ;

    int best = -1 ;

    for(int i = 0 ; i < n; i++)
    {
        auto c = s[i] ;

        m1[c]++ ;
        m2[c]-- ;

        if (i == n - 1)
            continue;

        int score = f(m1) + f(m2) ;

        best = max(best,score) ;
    }

    cout << best << nl ;

}

signed main()
{   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int testCases = 1 , case_ = 1;     
    cin >> testCases; for (int case_ = 1; case_ <= testCases; case_++) 
        solve(case_);
}

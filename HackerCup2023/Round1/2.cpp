#include <bits/stdc++.h>
using namespace std;
#define int     long long
#define all(x)  begin(x) , end(x)
#define nl      "\n" 
#include"/home/dk/debugging.h"

//  g++ 2.cpp && ./a.out

vector<int> prime = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41};


void solve(int& __case__)
{   
    int num ; cin >> num; 
    cout << "Case #" << __case__ << ": " ;

    vector<int> factors ;

    for(auto &p : prime) {
        while(num % p == 0) {
            factors.push_back(p) ;
            num /= p ;
        }
    }

    int sumOfFactors = accumulate(all(factors),0LL) ;

    if((sumOfFactors > 41) or (num > 1) ) {
        cout << -1 << nl ;
        return ;
    }

    int ones = 0 ;
    while(accumulate(all(factors),0LL)  < 41) {
        factors.push_back(1) ;
    }

    cout << factors.size() << " " ; 
    for(auto x : factors) cout << x <<  " " ; 
    cout << nl ;


}

signed main()
{   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    freopen("input.txt", "r+", stdin);
    freopen("output.txt", "w+", stdout);
    int testCases = 1 , case_ = 1;     
    cin >> testCases; for (int case_ = 1; case_ <= testCases; case_++) 
        solve(case_);
}

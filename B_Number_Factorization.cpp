#include <bits/stdc++.h>
using namespace std;
#define int     long long
#define all(x)  begin(x) , end(x)
#define nl      "\n" 


const int N = sqrt(1e9 + 1e3);
vector<int> lp(N + 1);
vector<int> pr;

void preCompute()
{
    // Time : O ( n )  -----> Linear Sieve  
    // CP-Algorithm : https://cp-algorithms.com/algebra/prime-sieve-linear.html

    for (int i = 2; i <= N; ++i)
    {
        if (lp[i] == 0) {
            lp[i] = i;
            pr.push_back(i);
        }
        for (int j = 0; i * pr[j] <= N; ++j){
            lp[i * pr[j]] = pr[j];
            if (pr[j] == lp[i]) break;
        }
    }
}

map<int,int> getFactorization(int x)
{
    map<int,int> m ;
    for(auto p : pr)
    {
        while(x % p == 0 )
        {
            m[p]++ ;
            x = x / p ;
        }
    }

    if (x != 1)
        m[x]++;

    return m ;
}

void solve(int& __case__)
{
    int num ; cin >> num ; 
    auto m = getFactorization(num) ;
    int ans = 0  ;
    while(m.size())
    {
        int minF = numeric_limits<int>::max() ;
        for(auto [ x , f] : m)
        {
            minF = min(f,minF) ;
        }

        int sum = 1 ;

        map<int,int> m2 ;

        for(auto [ x , f ] : m)
        {
            sum *= x ;
            f -= minF ;

            if(f != 0)
                m2[x] = f ;
        }

        ans += (sum * minF) ;
        m = m2 ;

    }
    cout << ans << nl ;
    
}

signed main()
{   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int testCases = 1 , case_ = 1;   
    preCompute() ;  
    cin >> testCases; for (int case_ = 1; case_ <= testCases; case_++) 
        solve(case_);
}

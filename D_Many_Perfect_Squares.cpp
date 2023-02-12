#include <bits/stdc++.h>
using namespace std;
#define int     long long
#define all(x)  begin(x) , end(x)
#define nl      "\n" 

auto factorize(int num)
{
    vector<pair<int,int>> v ;
    for(int i = 1 ; i < sqrt(num) ; i++)
    {
        if(num % i == 0 )
        {
            int a = num / i;
            int b = i;

            if( a > b) swap(a , b) ;

            v.push_back({a, b});
        }
    }

    return v ;
}

void solve(int& __case__)
{
    int n ; cin >> n  ;

    vector<int> v(n) ;

    for(auto &x : v) 
        cin >> x ;
    
    sort(all(v)) ;

    int best = 1 ;
    set<int> x_values ;

    for(auto& ai : v) 
    {
        for(auto& aj : v)
        {
            int diff = aj - ai ;
            int num = diff ;

            for (auto &[a, b] : factorize(num))
            {
                int q = (a + b) / 2;
                int p = b - q;

                if ((q - p) * (q + p) == num )
                {
                    int x = (p * p) - ai;

                    if ((x == (q * q) - aj) and (x >= 0))
                        x_values.insert(x) ;
                }
            }
        }
    }

    for(auto &x : x_values ) 
    {
        int count = 0 ;
        for(auto &e : v) 
        {
            int half = sqrt(e + x) ;
            if(half * half  == e + x)
                count++ ;
        }
        best = max(best , count) ;
    }
    
    cout << best << nl ;
}

signed main()
{   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int testCases = 1 , case_ = 1;     
    cin >> testCases; for (int case_ = 1; case_ <= testCases; case_++) 
        solve(case_);
}

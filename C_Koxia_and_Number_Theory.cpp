#include <bits/stdc++.h>
using namespace std;
#define int     long long
#define all(x)  begin(x) , end(x)
#define nl      "\n" 

bool check(vector<int> &v , int x)
{
    int n = v.size() ;

     for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                if (gcd(v[i] + x, v[j] + x) != 1)
                {   
                    return 0 ;
                }
    return 1 ;
}

void solve(int& __case__)
{

    int n ; cin >> n ;
    vector<int> v(n, 10);

    for (auto &x : v)
        cin >> x;
    
    set<int> possible  ;

    int const START =  1e15  ;
    int const END = START - 1e4 ;
    int const MOD = 1e18 ;
    int count = 0 ;

    

    srand(time(0)) ;
    
    for (int x = START ; x <= 10 ; x++ )
    {
        if(check(v,x) == 1) {
            cout << "YES\n" ;
            return ;
        }

    }

    cout << "NO" << nl; 
    
}

signed main()
{   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int testCases = 1 , case_ = 1;     
    cin >> testCases; for (int case_ = 1; case_ <= testCases; case_++) 
        solve(case_);
}

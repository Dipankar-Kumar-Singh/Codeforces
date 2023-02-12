    // Everything in the Universe is Balanced 
    // Every Disappointment you face in life will be balanced with something good for you 
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define TestCases int TOTALTC ; cin >> TOTALTC ; for(__case__ = 1 ; __case__ <=  TOTALTC ; __case__++)
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 
int __case__ = 1 ;

bool kahi_sey_bhi_Sorted(vector<int> v)
{
    if(is_sorted(all(v)) ) return 1 ;
    reverse(all(v)) ;
    if(is_sorted(all(v)) ) return 1 ;
    return 0 ;
}

bool trykar(vector<int> v , int x)
{
    for(auto &e : v) e = abs(e - x) ;

    if(is_sorted(all(v)))
    {
        return 1;
    }

    return 0 ;
}

void solve()
{
    int n ; cin >> n ;
    vector<int> v(n) ;
    for(auto& x : v) cin >> x ;  

    if(kahi_sey_bhi_Sorted(v))
    {
        if(is_sorted(all(v)))
        {
            cout << 0 << nl ;
            return ;
        }

        else 
        {
            cout << v.front() << nl ;
            return ;
        }
    }


    int M = *max_element(all(v)) ;
    int m = *min_element(all(v)) ;


    int x = midpoint(M,m)  ;

    // if ((M + m) & 1)
    // {
    //     cout << - 1 << nl ;
    //     return ;
    // }

    // cout << "Sum " << m + M << nl ; 

    // for (int i = max(0LL, x - 5); i < x + 10; i++)
    // {
    //     if (trykar(v, i))
    //     {
    //         cout << i << nl;
    //         return;
    //     }
    // }

    int delta = M - m ;

    vector<int> sexyPoints = {delta, m + delta, m - delta, M + delta, M - delta, x};


    for(auto& poitns : sexyPoints)
    {
        for(int i = max(0LL , poitns - 10 ) ; i < poitns + 10 ; i++)
        {
            if(trykar(v,i))
            {
                cout << i << nl ;
                return ;
            } 
        }
    }

    cout << -1 << nl ;
    
}

signed main() { FAST TestCases solve(); }

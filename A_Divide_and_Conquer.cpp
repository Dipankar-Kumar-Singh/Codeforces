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

void solve()
{
    int n ; cin >>  n;
    vector<int> v(n) ;

    for(auto &x : v) cin >> x ;

    vector<int> need(n) ;

    for(int i  = 0 ; i < n ; i++)
    {
        int x = v[i] ;

        int parity = (x & 1) ;
        int count = 0 ;
        while(x)
        {
            x /= 2 ;
            count++ ;
            int currParity = (x & 1 ) ;
            if(currParity != parity)
            {
                need[i] = count ;
                break;
            }
        }
    }


    int sum = accumulate(all(v),0LL) ;
    if(sum % 2 == 0 )
    {
        cout << 0 << nl ;
        return ;
    }

    else 
    {
        cout << *min_element(all(need)) << nl  ;
    }
    
}

signed main() { FAST TestCases solve(); }

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
    int n ; cin >> n;
    string  s; cin >> s ;

    int sum = (s.front() == '1') ;

    for(int i = 1 ; i < n ; i++)
    {
        if(s[i] == '0') cout << '+' ;
        else if(s[i] == '1')
        {
            if(sum == 0)
            {
                cout << '+' ;
                sum++ ;
            }

            else 
            {
                cout << '-' ;
                sum-- ;
            }
        }
    }


    cout << nl ;
    
}

signed main() { FAST TestCases solve(); }

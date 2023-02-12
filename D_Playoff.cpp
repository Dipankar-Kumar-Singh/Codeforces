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
    string s ; cin >> s ;

    char const WIN = '1' ;

    int smaller = 0 ; int bigger = 0 ;

    for(char c : s)
    {
        if (c == WIN)
            smaller += 1 + smaller;
        else
            bigger += 1 + bigger;
    }

    int total = 1 << n ;
    int rem = total - bigger ;

    for(int i =  smaller + 1 ; i <= rem ; i++)
        cout << i << " " ;
    

}

signed main() { FAST  solve(); }

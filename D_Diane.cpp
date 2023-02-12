#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases int TOTALTC ; cin >> TOTALTC ; for(_case = 1 ; _case <=  TOTALTC ; _case++)
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 
int _case = 1 ;

void solve()
{
    int n;   cin >> n;

    if(n == 1){ cout << 'a' << nl ; return ;}
    if(n == 2) { cout << "ab" << nl ; return ;}
 
    if((n&1))
    {
        int frontC = n/2 ;
        int i = 0 ;

        for( ; i < frontC ; i++) cout << "c" ;
        cout << "ba" ;  i++ , i++;
        for(;i < n ;i++)   cout << 'c' ;
        cout << nl ;
    }

    else 
    {
        int frontB = n/2 ;
        int i = 0 ;  

        for( ; i < frontB ; i++) cout << "b" ;
        cout << 'a' ; i++ ;
        for( ; i < n ; i++ ) cout << "b" ; 
        cout << nl ; 
    }
}
signed main(){   FAST      TestCases      solve() ;  }




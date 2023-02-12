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
   int last = (1LL<<31)-1LL;

//    last-- ;

   vector<int> v(n,-1) ;

   int first = 0 ;

//    first++ ;

    vector<int> odd , even ;

    for(int i = 0 ; i < n ; i++)
    {
        odd.push_back(first++) ;
        even.push_back(last--) ;

        cerr << (odd[i]^even[i]) << nl ;
    }

    reverse(all(odd)) ;
    reverse(all(even)) ;

    int x = 0 , y = 0 ;

    for(int i = 0 ; i < n ; i++)
    {
        // if((i==(n/2)) and (n&1))
        // {
        //     v[i] = 0 ;
        //     continue;
        // }

        if( (i&1) )
        {
            v[i] = even.back() ;
            even.pop_back() ;
            // odd.pop_back() ;
        }

        else
        {
            v[i] = odd.back();
            odd.pop_back();
        }
    }

   int a = 0 , b = 0 ;

   for(int i = 0 ; i < n ; i+=2) a ^=  v[i] ;
   for(int i = 1 ; i < n ; i+=2) b ^=  v[i] ;

    cerr << nl ;
   for(auto &x : v) cerr << x << " "; cout << nl ;
    cerr << nl ;

   cout << a << "   " << b << nl ;



}
signed main(){   FAST      TestCases      solve() ;  }




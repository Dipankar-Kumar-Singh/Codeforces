#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases int TOTALTC ; cin >> TOTALTC ; for(_case = 1 ; _case <=  TOTALTC ; _case++)
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 
int _case = 1 ;

int f(vector<int> &v)
{
    int x = 0 ; 


    for(auto y : v)
    {
        if(x < y) x += y ;
        else x = 0 ;
    }


    return x ; 
}

void solve()
{
   int n; cin >> n;
   vector<int> v(n-2) ;

   for (int i = 0; i < n - 2 ; i++)
       v[i] = i + 1;

    reverse(all(v)) ;

    if((n-2)%2!=0)
    {
        swap(v[0],v[1]) ;
    }
    
    cout << boolalpha << (f(v) == 0) << nl;

    for (auto x : v)
        cout << x << " ";
    cout << n - 1 << " " << n << nl;


}
signed main(){   FAST      TestCases      solve() ;  }




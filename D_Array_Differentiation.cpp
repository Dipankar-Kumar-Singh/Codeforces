#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases int TOTALTC ; cin >> TOTALTC ; for(_case = 1 ; _case <=  TOTALTC ; _case++)
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 
int _case = 1 ;

bool check(int id , vector<int>&v)
{   
    int n = v.size() ;
    vector<int> a(n)  , b(n);
    for(int i = 0 ; i < n ; i++)
    {
        if (i == id){
            a[i] = v[i];
            continue;
        }

        a[i] = v[id] - v[i] ;
        b[i] = v[id] + v[i] ;
    }


   int curr = v[id] ;
   set<int> s(all(a)) ;
   set<int> s2(all(b)) ;

   for(auto x : a)
   {
        if(s.count(x + curr) or s.count(x - curr)) return 1 ;
   }
    for(auto x : b)
   {
        if(s2.count(x + curr) or s.count(x - curr)) return 1 ;
   }
   
    return 0 ;
}

void solve()
{
    int n;  cin >> n;
    bool pos = 0 , neg = 0 ;
    vector<int> v(n);    for (auto &x : v) cin >> x , pos |= (x>0) , neg |= (x < 0);


    if(n==1)
    {
        if(v[0] == 0 ) cout << "YES" ; 
        else cout << "NO" ;
        cout << nl ;
        return ;
    }

    cout << (pos and neg ? "YES" : "NO") << nl;

    // for (int i = 0; i < n; i++)
    // {
    //     if (check(i, v))
    //     {
    //         cout << "YES\n";
    //         return;
    //     }
    // }

    // cout << "NO\n";
}
signed main(){   FAST      TestCases      solve() ;  }




#include <bits/stdc++.h>
using namespace std;

#include"C:\Users\dipan\OneDrive\ProCode\CP\debugging.h" 
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) { cerr << *it << " = " ; cerr << (a)  << "  " ; err(++it, args...);}
#define dbg error


#define int long long
#define TestCases   int _test {1} ; cin >> _test ; while(_test--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n"

int const A = -1;
int const B = -2 ;

void solve()
{

   int n ; cin >> n ;
   vector<int> v(n) ; for(auto &x : v) cin >> x ;

   int ans = 0 ;
   int f = 0 ;

   int obs = 0 ;

    for(int i = 0 ; i + 1  < n ;i++)
    {
        if (v[i] == v[i + 1])
        { 
            obs++ ; 
        }
    }

    for(int i = 1 ; i + 1  < n ;i++)
    {
        if(obs<=1) {   break; }

        if (v[i] == v[i - 1])
        {
            f = !f ;
            int a = v[i-1] , b = v[i] , c = v[i+1] ;
            ans++ ;
            v[i] = ((f==0) ? A : B) ;
            
            if(a==b and b==c) obs--   ;
            else  ;
            
            v[i+1] = v[i] ;

            if (i + 2 < n)
            {
                int d = v[i + 2];
                if (c == d)
                {
                    obs--;
                }
            }
        }

        if(obs<=1){   break; }
    }

    cout << ans  << nl ;

}

signed main()
{   FAST  

    TestCases  
    solve() ;  

}


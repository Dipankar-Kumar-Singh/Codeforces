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

int a, b, c, x, y, z;

bool check() 
{
    int m1 = x%y ;
    int m2 = y%z ; 
    int m3 = z%x ;

    dbg(m1,m2,m3) ;
    cerr << nl ;
    dbg(a,b,c) ;
    cerr << nl << "----------------------------- " << nl;

    return ((a == m1) and (b == m2) and (c == m3));
}




void solve()
{
   
    cin >> a >> b >> c ;
    x = 1e18 ;
    y = x - a;
    z = c ;

    while (check()==false)
    {
        x-- ;
        y = x - a;
        z = c;
    }
    

    check() ;

}

signed main()
{   FAST  

    TestCases  
    solve() ;  

}


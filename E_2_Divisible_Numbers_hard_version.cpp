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
    int a , b , c , d ; 
    cin >> a >> b >> c >> d ;

    vector<int> fa , fb ;


    for(int i = 1 ; i * i <= a ; i++)
    {
        if (a % i == 0)
        {
            fa.push_back(i);

            if (i * i < a)
                fa.push_back(a / i);
        }
    }

    for(int j = 1 ; j * j <= b ; j++)
    {
        if (b % j == 0)
        {
            fb.push_back(j);
            if (j * j < b)
                fb.push_back(b / j);
        }
    }

    vector<int> f ; 

    for(auto& x : fa) 
        for(auto& y : fb) 
            f.push_back(x*y) ;

    sort(all(f)) ;
    f.erase(unique(all(f)),f.end()) ;

    int P = a * b;

    for(int& x : f)
    {
        // x fixed ..
        int X = (c / x) * x; // closed to c ..

        int minReq = P/gcd(P,x) ;

        int Y = (d/minReq) * minReq ;

        if (X > a and X <= c and Y > b and Y <= d and (X * Y) % P == 0)
        {
            cout << X << " " << Y << nl;
            return ;
        }
    }

    cout << "-1 -1" << nl ;
}
signed main(){   FAST      TestCases      solve() ;  }




#include <bits/stdc++.h>
using namespace std;

#define t_case   int ttt {} ; cin >> ttt ; while(ttt--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 

int n , l , x, y ;

bool underLimit(int x) {   return x >= 0 and x <= l ;}
bool found(int x) {return x==-1;}

signed main()
{
    FAST

    cin >> n >> l >> x >> y ; 
    vector<int> v(n) ; for(int &i : v ) cin>> i  ;
    set<int> points (all(v)) ;

    for(auto p : points)
    {
        int nx = p + x , ny = p + y ;
        if(points.contains(nx) and underLimit(nx) ) x = -1  ;
        if(points.contains(ny) and underLimit(ny) ) y = -1  ;
    }

    if (found(x) and found(y))
    {
        cout << 0;
        exit(0);
    }

    if (found(x) and !found(y))
    {
        cout << 1 << nl << y;
        exit(0);
    }

    if (found(y) and !found(x))
    {
        cout << 1 << nl << x;
        exit(0);
    }

    for (int p : points)
    {
        int p1 = p + x;
        int p2 = p - x;

        int p1a = p1 + y, p1b = p1 - y;
        int p2a = p2 + y, p2b = p2 - y;

        bool isP1 = underLimit(p1) and
                    ((underLimit(p1a) and points.count(p1a)) or
                     (underLimit(p1b) and points.count(p1b)));

        bool isP2 = underLimit(p2) and
                    ((underLimit(p2a) and points.count(p2a)) or
                     (underLimit(p2b) and points.count(p2b)));

        if (isP1)
        {
            cout << 1 << nl;
            cout << p1;
            exit(0);
        }

        if (isP2)
        {
            cout << 1 << nl;
            cout << p2;
            exit(0);
        }
    }

    cout << 2 << nl;
    cout << x << " " << y;
}

#include <bits/stdc++.h>
using namespace std;
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define nl "\n" 

unordered_map<char,int> getDirection(pair<int,int> source , pair<int,int> destination)
{
    auto &[sx,sy] = source ;
    auto &[dx,dy] = destination ;

    unordered_map<char,int> m ;

    m['D'] = max(dy - sy, 0);
    m['U'] = max(sy - dy, 0);
    m['R'] = max(sx - dx, 0);
    m['L'] = max(dx - sx, 0);

    return m ;
}

void solve()
{
    int n;   cin >> n;
    vector<pair<int, int>> v(n);

    int extramoves = 0 ;

    for (auto &[x, y] : v)
        cin >> x >> y, extramoves += ((x != 0) and (y != 0));

    sort
    (   
        begin(v) , end(v) ,
        [&](pair<int,int> P , pair<int,int> Q) 
        {
            auto [x1,y1] = P ; 
            auto [x2,y2] = Q ;

            return abs(x1) + abs(y1) < abs(x2) + abs(y2) ;
        }
    ) ;

    int moves = (2 * extramoves + n * 4);
    cout << moves << nl ;

    for(int i = 0 ; i < n ; i++)
    {
        pair<int,int> source = v[i] ;
        pair<int,int> target = {0,0} ;

        // Going to the bomb cell 
        for(auto &[ c , d ] : getDirection(source,target))
        {
            if( d == 0 ) continue ;
            cout << 1 << " " << d << " " << c << nl ;
        }

        // taking bomb 
        cout << 2 << nl ;


        // going back to origin 
        swap(source , target) ;

        for(auto &[ c , d ] : getDirection(source,target))
        {
            if( d == 0 ) continue ;
            cout << 1 << " " << d << " " << c << nl ;
        }

        cout << 3 << "\n" ;
    }


}
signed main(){   FAST   solve() ;  }




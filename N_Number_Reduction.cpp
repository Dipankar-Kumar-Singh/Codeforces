    // Everything in the Universe is Balanced 
    // Every Disappointment you face in life will be balanced with something good for you 
#include <bits/stdc++.h>
using namespace std;


#define TestCases int TOTALTC ; cin >> TOTALTC ; for(__case__ = 1 ; __case__ <=  TOTALTC ; __case__++)
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 
int __case__ = 1 ;

int const INF = numeric_limits<int>::max() ;


vector<int> v ;
int k ;
vector<vector<int>> loc ;

int getIndex(int id)
{
    id++ ;
    int minDigit = INF ;
    int pointer = 0 ;

    // for(int i = id ; i <= id + k ; i++)
    // {
    //     int x = v[i] ;
    //     if( x < minDigit ) 
    //     {
    //         minDigit = x;
    //         pointer = i ;
    //     }
    // }


    for(int d = 0 ; d < 10 ; d++)
    {
        auto& vec = loc[d] ;
        auto it = lower_bound(all(vec), id );
        if(it == vec.end()) continue;

        if(*it > id + k ) continue;

        pointer = *it ;
        break;
    }

    return pointer ;
}

void solve()
{

    string s ; cin >> s ;
    cin >> k ;

    int n = s.size() ;

    loc = vector<vector<int>>(10);
    v.clear() ;

    int finalSize = s.size() - k ;

    for(auto &c : s ) v.push_back ( c - '0' )  ;

    for (int i = 0; i < v.size(); i++)
        loc[v[i]].push_back(i);

    if(k == 0 ) 
    {
        cout << s << nl ;
        return ;
    }

    vector<int> ans ;
    int minDigit = INF ;
    int pointer = 0 ;

    for (int i = 0; i < k + 1; i++)
    {
        int& x = v[i] ;
        if (x  != 0)
        {
            if( x < minDigit ) {
                minDigit  = x ;
                pointer = i ;
            }
        }
    }

    k -= pointer ;

    ans.push_back(minDigit) ;
    minDigit = INF ;

    while (k > 0)
    {
        if (ans.size() >= finalSize)
            break;

        int oldPtr = pointer;
        pointer = getIndex(pointer);
        ans.push_back(v[pointer]);

        int delta = pointer - oldPtr - 1;
        k -= delta;
    }

    if (k == 0 and pointer < n)
    {
        while (pointer + 1 < n)
        {
            ans.push_back(v[++pointer]);
        }
    }

    for (auto &x : ans)
        cout << x;
    cout << nl;
}

signed main() { FAST TestCases solve(); }

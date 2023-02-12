#include <bits/stdc++.h>
using namespace std;

    // Everything in the Universe is Balanced 
    // Every Disappointment you face in life will be balanced with something good for you 
    // Keep Going, Never Give up .

#define int long long
#define TestCases int TOTALTC ; cin >> TOTALTC ; for(__case__ = 1 ; __case__ <=  TOTALTC ; __case__++)
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 
int __case__ = 1 ;

void solve()
{
    string s;  
    cin >> s ;

    int m ; cin >> m ;
    vector<int> d(m) ;

    for(auto &x : d) cin >> x ;

    string  t( m ,'?') ;

    cout << t << nl ;

    string order = s ;
    sort(all(order) , greater<char>()) ;
    
    int currpt = 0 ;
    char curr = order[currpt] ;

    for(int i = 0 ; i < m ; i++)
    {
        if(d[i] == 0) t[i] = curr ;
    }
    curr = order[++currpt] ;

    int it = 0 ;

    while (t.find('?') == string::npos)
    {
        it++ ;
        if(it > 10 ) break;
        for(int i = 0 ; i < m ; i++)
        {
            if(t[i] != '?' ) continue ;

            int dis = 0 ;
            for(int j = 0 ; j < m ; j++)
            {
                if(t[j] != '?' and t[j] != curr)
                {
                    dis += abs(i - j) ;
                }
            }

            if(dis == d[i])
            {
                t[i] = curr ;
                currpt++ ;
                curr = order[currpt] ;
            }
        }

        cerr << t << nl ;
    }

    cerr << "case " << __case__ << nl ;
    
}

signed main() { FAST TestCases solve(); }

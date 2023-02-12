#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases   int total ; cin >> total ;  for(test = 1 ; test <=  total ; test++)
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n"  
#define print(ans) cout << "Case #" << test << ": " << ans << "\n" ;


int const INF  = 1e18 ;
int test = 0 ;


void solve()
{
    string a , b ; cin >> a >> b ;

    map<char,int> m  ;
    m['M'] = 0 ;
    m['S'] = -1 ;
    m['L'] = 1 ;

    char aa = a.back() ;
    char bb = b.back() ;


    if(m[a.back()]==m[b.back()])
    {
        if(aa=='S')
        {
            if(a.size() == b.size())
            {
                cout << "=" << nl ;
            }

            else if(a.size() < b.size())
            {
                cout << ">" << nl ;
            }

            else if(a.size() > b.size())
            {
                cout << "<" << nl ;
            }

        }

        else if(aa == 'L') 
        {
            if(a.size() < b.size())
            {
                cout << "<" << nl ;
            }

            else if(a.size()==b.size())
            {
                cout << "=" << nl ;
            }

            else if(a.size() > b.size())
            {
                cout << ">" << nl ;
            }
        }

        else if(aa=='M')
        {
            cout << "=" << nl ;
        }
    }

    else if(m[aa] < m[bb])
    {
        cout << "<" << nl ;

    }

    else if(m[aa] > m[bb])
    {
        cout << ">" << nl ;
    }

    
    

}

signed main(){  FAST    TestCases    solve() ; }
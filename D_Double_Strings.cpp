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
    int n;
    cin >> n;
    multiset<string> ms;

    vector<string> v(n) ;

    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        ms.insert(s);
        v[i] = s;
    }

    vector<int> ans(n) ;

    for(int i = 0 ; i < n; i++)
    {
        ms.erase(ms.find(v[i]));
        
        string &s = v[i] ;
        string prefix ;

        for(int k = 0 ; k < s.size() - 1 ; k++)
        {
            prefix += s[k] ;
            auto it = ms.find(prefix)  ;
            if(it!=ms.end())
            {
                string suffix ; 
                for(int j = k + 1 ; j < s.size() ; j++)
                {
                    suffix+=s[j] ;
                }
                if(suffix==prefix)
                {
                    ans[i] = 1 ;
                    break ;
                }
                auto it2 = ms.find(suffix) ;
                if(it2!=ms.end())
                {
                    ans[i] = 1 ;
                    break ;
                }
            }
        }
        ms.insert(v[i]); 
    }

    for(auto x : ans) cout << x ;
    cout << nl ;

}
signed main(){   FAST      TestCases      solve() ;  }




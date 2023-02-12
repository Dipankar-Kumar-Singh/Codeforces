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
    // int ans = 0 ; 
    string s  ; cin >> s ;
    int p ; cin >> p ;

    int n = s.size() ; 


    map<char,vector<int>> mp ;

    for(int i = 0 ; i < n ; i++)
    {
        mp[s[i]].push_back(i) ;
    }

    long long total = 0 ;
    for(auto &c : s ) total += (c-'a'+1) ;

    vector<int> exclude ; 

    for(char c = 'z' ; c >= 'a' ; c--)
    {
        int price = (mp[c].size()) * (c - 'a' + 1);
        if(total - price >= p)
        {
            total-=price ;
            for(auto &i : mp[c])
            {
                exclude.push_back(i) ;
            }
        }

        else if (total - price < p)
        {
            vector<int> v = mp[c];
            int costc = (c - 'a' + 1);

            for (int i = 1; i <= v.size(); i++)
            {
                int index = i - 1;
                if (total - costc >= p)
                {
                    total -= costc;
                    exclude.push_back(v[index]);
                    if (total == p)
                        break;
                }

                else if (total > p)
                {
                    total -= costc;
                    exclude.push_back(v[index]);
                    break;
                }
            }
            break;
        }
    }

    string ans ; 

    set<int> st(all(exclude)) ;
    for(int i = 0 ; i < n ; i++)
    {
        if(st.find(i) == st.end())
        {
            ans.push_back(s[i]) ;
        }
    }
    
    cout << ans << nl;
}

signed main(){  FAST    TestCases    solve() ; }
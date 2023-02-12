#include <bits/stdc++.h>
using namespace std;

#define int long long
#define TestCases int TOTALTC ; cin >> TOTALTC ; for(_case = 1 ; _case <=  TOTALTC ; _case++)
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 
int _case = 1 ;

bool check(vector<pair<int,int>> &v)
{
    vector<int> a ; 
    vector<int> b ;
    for(auto &[x,y] : v)
    {
        a.push_back(x) ;
        b.push_back(y) ; 
    }

    // cout << "\n---\n" ;
    // for(auto &x : a) cout << x << " " ; cout << nl ;
    // for(auto &x : b) cout << x << " " ; cout << nl ;
    // cout << "---\n" ;

    return (is_sorted(all(a)) and is_sorted(all(b))) ;
}

void print(vector<pair<int,int>> &v)
{
    for(auto &[x ,y ] : v) 
    {
        cerr << x << " " << y << nl ;
    }
}

auto solvefor(vector<pair<int,int>> &v)
{
    int n = v.size() ;
    vector<pair<int,int>> ans ;

    // cerr << "before op = " << nl ;
    // print(v) ;
    // cerr << nl; 
  
    

    for(int i = 0 ; i < n; i++)
        {
            for(int j = 0 ; j < i ;j++)
            {
                auto &[x2,y2] = v[i] ; 
                auto &[x1,y1] = v[j] ;

                if (x1 != x2)
                {
                    if(x1 < x2) continue;

                    ans.push_back({i, j});
                    swap(v[i], v[j]);
                }

                else 
                {
                    if((x1==x2) and (y1==y2)) continue;

                    if(y1 < y2) continue;

                    ans.push_back({i, j});
                    swap(v[i], v[j]);
                }
            }
        }
    
    // cerr << "after opration = \n" ;
    // print(v) ;
    // cerr << nl; 

    return ans ;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    vector<int> b(n);    
    for (auto &x : b) cin >> x;

    vector<pair<int, int>> v1(n);
    for (int i = 0; i < n; i++)
    {
        v1[i] = {a[i],b[i]} ;
    }

    vector<pair<int,int>> v2(n) ;
    for (int i = 0; i < n; i++)
    {
        v2[i] = {b[i],a[i]} ;
    }

    sort(all(v1)) ;
    sort(all(v2)) ;

    if (check(v1) == false and check(v2) == false)
    {
        cout << -1 << nl ;
        return ;
    }

    if(is_sorted(all(a)) and is_sorted(all(b))) 
    {
        cout << 0 << nl ;
        return ;
    }

    vector<pair<int,int>> ans ;
    vector<pair<int, int>> v ;

    if(check(v1))
    {
        for (int i = 0; i < n; i++)
        {
            v1[i] = {a[i],b[i]} ;
        }

        v = v1 ;
        ans = solvefor(v);

        cout << ans.size() << "\n";
        for (auto [x, y] : ans)
        {
            cout << ++x  << " " << ++y << nl ;
        }
    }

    else 
    {

        for (int i = 0; i < n; i++)
        {
            v2[i] = {b[i],a[i]} ;
        }

        v = v2 ;
        ans = solvefor(v);

        cout << ans.size() << "\n";
        for (auto [x, y] : ans)
        {
            cout << ++x  << " " << ++y << nl ;
        }
    
    }



    



    // cout << boolalpha << "for a,b = " << check(v1) << nl ;
    // cout << boolalpha << "for B,A = " << check(v2) << nl ;




}
signed main(){   FAST      TestCases      solve() ;  }




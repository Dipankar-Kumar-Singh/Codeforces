    // Everything in the Universe is Balanced 
    // Every Disappointment you face in life will be balanced with something good for you 
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define TestCases int TOTALTC ; cin >> TOTALTC ; for(__case__ = 1 ; __case__ <=  TOTALTC ; __case__++)
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 
int __case__ = 1 ;

vector<vector<int>> rotate(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    vector<vector<int>> rotated(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            rotated[j][n - i - 1] = matrix[i][j];
        }
    }
    return rotated;
}

bool isGood(vector<vector<int>> v)
{
    for (auto r : v)
        if (is_sorted(all(r)) == 0)
            return 0;

    if(v[0][0] > v[1][0] ) return 0 ;
    if(v[0][1] > v[1][1] ) return 0 ;

    return 1 ;
}

void solve()
{
    vector<vector<int>> v(2,vector<int>(2)) ;
    for(auto &r : v)
        for (auto &x : r)
            cin >> x;

    for(int i = 0 ; i < 6 ; i++)
    {
        v = rotate(v) ;
        if(isGood(v))
        {
            cout << "YES" << nl;
            return ;
        }
    }
    
    cout << "NO" << nl ;

}

signed main() { FAST TestCases solve(); }

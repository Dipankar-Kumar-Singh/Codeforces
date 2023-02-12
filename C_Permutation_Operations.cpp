#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases int TOTALTC ; cin >> TOTALTC ; for(_case = 1 ; _case <=  TOTALTC ; _case++)
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 
int _case = 1 ;

int getMax(vector<int> &v , vector<int> &mx , int i)
{
    return max((i > 0 ? mx[i - 1] : -1), v[i]) ;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);

    for (auto &x : v)  cin >> x;
    vector<int> mx(n + 1);

    int apply = 0;
    int itration = 1;

    vector<int> ans;

    for (int i = 0; i < n; i++)
    {
        mx[i] = getMax(v, mx, i);
        while (getMax(v, mx, i) > v[i] + apply)
        {
            apply += (itration);
            itration++ ;
            ans.push_back(i);
        }

        cerr << apply << " " ; cerr << nl ;  
    
        v[i] = v[i] + apply;
        mx[i] = max((i > 0 ? mx[i - 1] : -1), v[i]);
    }

    cout << "----------------vec-------------------" ;
    for(auto x : v) cout << x <<   " " ; cout << nl;
    cout << "-------------------------------------" ; 

    if (ans.size() >= n)
    {
        for(int i = 0 ; i < n ; i++) cout << ans[i] << " " ;
        cout << nl;
    }

    else
    {
        int rem = n ;
        if(ans.size())
            for(int i = 0 ; i < ans.size() ; i++) 
            {
                cout << ans[i] << " " ; 
                rem-- ;
            }
        
        while(rem-- ) cout << 1 << " " ; 
        cout << nl ;
    }
}
signed main(){   FAST      TestCases      solve() ;  }




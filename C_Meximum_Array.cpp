#include <bits/stdc++.h>
using namespace std;
#define t_case      int ttt{};    cin >> ttt;   while (ttt--)
#define FAST        ios_base::sync_with_stdio(0);    cin.tie(NULL);     cout.tie(NULL);

signed main()
{
    FAST
    t_case
    {
        int n;  cin >> n;  int MEX = 0;
        map<int, int> seen ;  set<int> s ; vector<int> ans;
        vector<int> v(n) ;  for (int &x : v) {  cin >> x;   seen[x]++;  }

        for (int i = 0; i < n; i++)
        {  
            seen[v[i]]--;                s.insert(v[i]);    
            while (s.count(MEX)) MEX++ ;
            if (seen[MEX] == 0){        s.clear();    ans.push_back(MEX);      MEX = 0 ;   }
            // if the current mex is present somewhere ahead => then we can get [ new mex = mex+1 ].. thus keep moving ahead 
        }
        cout << ans.size() << "\n";     for (auto &x : ans)cout << x << ' ';    cout << "\n";
    }
}

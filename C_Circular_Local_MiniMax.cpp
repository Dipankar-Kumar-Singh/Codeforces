#include <bits/stdc++.h>
using namespace std;
#define TestCases   int _test {1} ; cin >> _test ; while(_test--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n"

bool valid(int n, vector<int> &v)
{
    for (int i = 1; i + 1 < n; i++)
    {
        if (v[i] > v[i - 1] and v[i] > v[i + 1])        continue;
        else if (v[i] < v[i - 1] and v[i] < v[i + 1])    continue;
        else  return 0;
    }

    bool c1 = ((v[0] > v.back()) and (v[0] > v[1]));
    bool c2 = ((v[0] < v.back()) and (v[0] < v[1]));

    return (c1 or c2);
}

void solve()
{
   int n ; cin >> n;
   vector<int> v(n) ; 
   for(auto &x : v) cin >> x ;
   
   if(n&1)
   {
   		cout << "NO\n" ;
   		return ;
   }
   
   else 
   {
   		sort(all(v)) ; 
   		vector<int> v1(v.begin(),v.begin()+n/2), v2(v.begin()+n/2,v.end()) ;
   		
   		vector<int> ans , ans2 ;
   		for(int i = 0 ; i < v1.size() ; i++)
   		{
   			ans.push_back(v1[i]) ;
   			ans.push_back(v2[i]) ;
   		}
   		
   		if(valid(ans.size(),ans))
   		{
   			cout << "YES" << nl ;
   				for(auto &x : ans) cout << x << ' ' ;
   			cout << nl ;
   			
   			return ;
   		}
   		   		
   		else 
   		{
   			cout << "NO\n" ;
   		}	
   }
}

signed main(){   FAST      TestCases      solve() ; }


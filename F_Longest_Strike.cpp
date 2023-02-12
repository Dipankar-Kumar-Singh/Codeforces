#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases   int _test {1} ; cin >> _test ; while(_test--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 


void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    map<int, int> m;
    for (auto &x : v)
    {
        cin >> x;
         m[x]++;
    }
    sort(all(v));

    v = vector<int>(all(set<int>(all(v)))) ;
    vector<int> a ; 
    
    for(auto x:m)
    {
        if(x.second>=k)
        {
            a.push_back(x.first);
        }
    }
    a.push_back(1e18);
    
    int cnt=1;
    int mx=-1;
    int ansl=-1,ansr=-1;
    if(a.size()==1)
    {
        cout<<-1<<"\n";
        return; 
    }
    for(int i=1;i<a.size();i++)
    {
        if(a[i]==a[i-1]+1)
        {
            cnt++;
        }
        else 
        {
            int l=a[i-1]-cnt+1;
            int r=a[i-1];
            int diff=r-l+1;
            if(diff>mx)
            {
                mx=diff;
                ansl=l;
                ansr=r;
            }
            cnt=1;
        }
    }
    cout<<ansl<<" "<<ansr<<"\n";

}

signed main()
{   FAST  

    TestCases  
    solve() ;  

}


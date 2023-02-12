// Problem: C. Minimum Extraction
// Contest: Codeforces - Codeforces Round #753 (Div. 3)
// URL: https://codeforces.com/problemset/problem/1607/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;

#include"C:\Users\dipan\OneDrive\ProCode\CP\debugging.h" 
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) { cerr << *it << " = " ; cerr << (a)  << "  " ; err(++it, args...);}
#define dbg error



#define int long long
#define TestCases   int _test {1} ; cin >> _test ; while(_test--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 


void solve()
{
	
	int n ; cin >> n;
	vector<int> v(n) ;
	for(auto &x : v) cin >> x ;
	
	vector<int> pos , neg ;
	for(auto x : v) ((x>0 )? pos : neg).push_back(x) ;


	
	int sum = neg.empty() ? 0 : accumulate(all(neg),0) ;
	int mn =  pos.empty() ? 0 : *min_element(all(pos)) ;

    // dbg(pos,neg) ;
	
	cout << mn - sum << nl; 
   

}

signed main()
{   FAST  

    TestCases  
    solve() ;  

}


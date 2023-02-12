#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases   int total ; cin >> total ;  for(test = 1 ; test <=  total ; test++)
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n"  
int const INF  = 1e18 ;
int test = 0 ;

string cal(string &s1 ,string &s2 , int len  , int n)
{
    int start = n - len  ;
    string ans ;

    int ss = 0 ;
    for (int i = 0; i < n; i++)
    {
        if (s1[i] == '1')
        {
            ss = i ;
            break;
        }
    }

    for(int i = ss ; i < start ; i++) ans += s1[i] ;

    for(int i = start , j = 0 ; i < n ; i++ , j++)
    {
        if(s1[i]=='1' or s2[j]=='1') ans += '1' ;
        else ans += '0' ; 
    }

    cerr << ans << nl ;
    return ans ;
}


void solve()
{

    int n ; cin >> n ;
    string s ; cin >> s ;
    int len = 1 ;

    int ss = 0 ;
    for(int i = 0 ; i < n  ; i++)
    {
        if(s[i]=='1')
        {
            ss = i ;
            break; 
        }
    }

    for(int i = ss ; i < n ; i++)
    {
        if(s[i] =='0')
        {
            len = n - i ;
            break;
        }   
    }
    vector<string> possible ;
    for(int i = 0 ; i + len <= n ;i++)
    {
        string t ;
        for(int j = i ; j < i + len ; j++)
        {
            t += s[j] ;
        }
        possible.push_back(cal(s,t,len,n)) ;
    }

    sort(all(possible)) ;
    reverse(all(possible)) ;

    string ans = possible.front() ;

    if (ans.front() == '0')
    {
        cout << 0 << nl;
        return ;
    }

    cout << possible.front() << nl ;

}

signed main(){  FAST    solve() ; }
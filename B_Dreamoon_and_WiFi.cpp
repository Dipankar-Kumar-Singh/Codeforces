#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases   int _test {1} ; cin >> _test ; while(_test--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 

string s1 , s2 ;

vector<int> points ;

void dp(int id , int curr)
{
    if(id==s2.size())
    {
        points.push_back(curr) ;
        return ;
    }
    if(s2[id]=='?')
    {
        int d1 = curr + 1 ;
        int d2 = curr - 1 ;

        dp(id+1,d1) ;
        dp(id+1,d2) ;
    }

    else if(s2[id]=='+') dp(id+1,curr+1) ;
    else dp(id+1,curr-1) ;

}

signed main()
{   FAST  

    cin >> s1 >> s2 ;

    int curr = 0 ;
    for(auto c : s1) if(c=='+') curr++ ; else curr-- ;

    dp(0,0) ;
    sort(all(points)) ;


    // 0 0 0 1 2 3 4 5 6 9 9 9 9 9 9 10 11 12 14 515 525

    auto [s,e] = equal_range(all(points),curr) ;
    int t = e-s ;
    cout << setprecision(12) << fixed <<double(t)/double(points.size()) << nl ;

}


#include <bits/stdc++.h>
using namespace std;
#define int     long long
#define all(x)  begin(x) , end(x)
#define nl      "\n" 


auto BUILD( string &s , map<char,int>& count , map<char,int>& take , int distinct , int fr )
{
    map<char,int> remove ;
    map<char,int> add ;

    for(auto& [c , ct ] : take)
    {
        if(count[c] == 0)
        {
            add[c] = fr ;
        }
    }

    for(auto& [c , ct ] : count)
    {
        if(take[c] == 0)
        {
            remove[c] = ct ;
        }

        else 
        {
            if(ct < fr and take[c])
            {
                add[c] = fr - ct ;
            }

            else 
            {
                remove[c] = ct - fr ;
            }
        }
    }

    return pair{add, remove};
}

void solve(int& __case__)
{
    int n ; cin >> n ; 
    string s ; cin >> s ;

    string allapha ;
    for(auto c = 'a' ; c <= 'z' ; c++) allapha += c ;

    int ans = 1e18 ;
    string ansString ;

    map<char,int> count ; 
    for(auto& c : s) count[c]++ ;

    for(int i = 1 ; i <= 26 ; i++)
    {
        int fr = n / i ;
        int distinct = i ;

        string t = s ; 
        if(fr * distinct != n) continue;

        map<char,int> take ;

        sort(all(allapha) ,[&](char& a , char& b){
            return count[a] > count[b] ;
        }) ;

        for(int j = 0 ; j < distinct ; j++)
            take[allapha[j]] = 1 ;

        auto [add, remove] = BUILD(s, count, take, distinct, fr);

        for (auto& [c, ct] : remove)
        {
            for (auto &x : t)
            {
                if (x == c and ct > 0)
                    x = '#', ct--;
            }
        }

        for(auto &[ c , ct ] : add)
        {
            for(auto &x : t)
            {
                if (x == '#' and ct > 0)
                    x = c, ct--;
            }
        }

        int diffrent = 0 ;
        for(int i = 0 ; i < n ; i++)
            if( s[i] != t[i] ) diffrent++ ;

        if(diffrent < ans)  
        {
            ans = diffrent ;
            ansString = t ;
        }
    }

    cout << ans << nl ;
    cout << ansString << nl ;
    
}

signed main()
{   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int testCases = 1 , case_ = 1;     
    cin >> testCases; for (int case_ = 1; case_ <= testCases; case_++) 
        solve(case_);
}

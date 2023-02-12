#include <bits/stdc++.h>
using namespace std;
#define all(x)  begin(x) , end(x)
#define nl      "\n" 

auto genereateSubset(int K , string &parent)
{
    auto &v = parent ;
    int N = v.size() ;

    vector<string> subsets ;

    for (int b = 0; b < (1 << N); b++)
    {
        if (__builtin_popcount(b) != K)
            continue;
        string subset;
        for (int i = 0; i < N; i++)
            if (b & (1 << i))
                subset.push_back(v[i]);

        subsets.push_back(subset) ;
    }

    return subsets ;
}

long long goodPair(string &a , string &b)
{
    int n = a.size() ;
    long long ans = 0 ;

    for(int i = 0 ; i < n; i++)
    {
        int l = i ;
        int r = i - 1 ;

        if(a[i] != b[i]) continue;

        for(int j = i ; j < n ; j++)
        {
            if(a[j] != b[j])  break;
            r = j ;
        }

        i = r ;

        long long total = r - l + 1 ;
        long long sum = (total * (total + 1)) /2 ;
        ans += sum ;
    }

    return ans ;
} 


long long calculate_ans(string a , string b , map<char,int> &isPresent)
{
    for(int i = 0 ; i < a.size() ; i++)
        if(a[i] != b[i])
            if(isPresent[a[i]] == 1)
                a[i] = b[i] ;

    long long ans = goodPair(a,b) ;
    return ans ;
}

void solve(int& __case__)
{
    long long n , k ;
    cin >> n >> k ;

    string a , b ;
    cin >> a >> b ;


    map<char,int> need ;
    for(int i = 0 ; i < n ; i++)
        need[a[i]] += (a[i] != b[i]) ;
    
    string parent ;

    for(auto& [ c  , fr ] : need)
        parent += c ;

    if(parent.size() <= k)
    {
        cout << ( n * (n + 1LL)) / 2LL << nl ;
        return ;
    }

    long long ans = goodPair(a,b) ;    

    for(auto& s : genereateSubset(k,parent))
    {
        map<char,int> isPresent ;
        for(auto& c : s) isPresent[c]++ ;
        ans = max(ans , calculate_ans(a,b,isPresent)) ;
    }
    
    cout << ans << nl ;

}

signed main()
{   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int testCases = 1 , case_ = 1;     
    cin >> testCases; for (int case_ = 1; case_ <= testCases; case_++) 
        solve(case_);
}

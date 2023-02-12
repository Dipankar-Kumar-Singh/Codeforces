#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases int TOTALTC ; cin >> TOTALTC ; for(_case = 1 ; _case <=  TOTALTC ; _case++)
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 
int _case = 1 ;

string getOrder(string s)
{
    string order ;
    map<char,int> m; 
    reverse(begin(s),end(s)) ;
    for(auto c : s){ if(m[c]==0) order.push_back(c) ; m[c]++ ;}
    reverse(begin(order),end(order)) ;
    return order ;
}

auto get_S_and_Order(string &t)
{
    bool possible = 1 ;
    auto order = getOrder(t) ;

    int lenOfS = 0 ;

    map<char,int> m ; for(auto& c : t) m[c]++ ;

    for(int i = 0 ; i < order.size() ; i++)
    {
        int step = i + 1 ;
        char& c = order[i] ;

        if(m[c]%step!=0) possible = 0 ;

        int org_len_C = m[c]/step ;

        lenOfS += m[c]/step ;
    }

    if(!possible)
    {
        return pair{(string)"#",(string)"#"} ;
    }

    string s ;
    for(int i = 0 ; i < lenOfS ; i++)  s += t[i] ;
    return pair{s,order} ;
}


bool isPossible_to_get_S_from_t(string &t , string s , string order)
{
    string tt ; 
    reverse(begin(order),end(order)) ;

    while (s.size())
    {
        tt += s ;
        string newS  ;
        for(auto& c : s) 
        {
            if(c==order.back()) continue; 
            newS +=  c ;
        }
        order.pop_back() ;
        s = newS ;
    }

    return (tt == t) ;
     
}

void solve()
{
   string t ; cin >> t ;

   auto [s , order ] = get_S_and_Order(t) ;

   if(s == "#" or !isPossible_to_get_S_from_t(t,s,order)) 
   {
        cout << -1 << nl ;
        return ;
   }

   cout << s << " " << order << nl ;

}
signed main() { FAST TestCases solve(); }

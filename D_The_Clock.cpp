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

int getTimeInMinutes(string &s)
{
    string H = s.substr(0,2) ;
    string M = s.substr(3,2) ;

    int time = 0 ;

    time += (stoi(H)*60) ;
    time += stoi(M) ;

    return time ;

}

bool check(int timeInMinutes)
{
    // timeInMinutes  %= 1440 ; 
    int H = timeInMinutes/60 ;
    H%=24;
    int M = timeInMinutes%60 ;

    string s1 , s2 ;

    if(H<10) s1 += '0' ;
    if(M<10) s2 += '0' ;

    s1 += to_string(H) ;
    s2 += to_string(M) ;

    reverse(all(s2)) ;
    return ( s1 == s2 ) ;
}



void solve()
{
   string inputTime ; cin >> inputTime ;
   int delta ; cin >> delta ;

   int currTime = getTimeInMinutes(inputTime) ;
   int endTime = currTime +  ;

   int ans =  0;

   for (; currTime < endTime ; currTime += delta)
   {
        ans += check(currTime) ;
   }




   cout << ans << nl ;
    
}
signed main(){   FAST      TestCases      solve() ;  }

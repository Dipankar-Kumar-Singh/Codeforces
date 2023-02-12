#include <bits/stdc++.h>
using namespace std;

// #include"C:\Users\dipan\OneDrive\ProCode\CP\debugging.h" 
// #define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
// void err(istream_iterator<string> it) {}
// template<typename T, typename... Args>
// void err(istream_iterator<string> it, T a, Args... args) { cerr << *it << " = " ; cerr << (a)  << "  " ; err(++it, args...);}
// #define dbg error


#define int long long
#define TestCases int TOTALTC ; cin >> TOTALTC ; for(_case = 1 ; _case <=  TOTALTC ; _case++)
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 
int _case = 1 ;

int n , m , k ;
// vector<vector<int>> v ;

void solve()
{
   
    cin >> n >> m >> k ; 
    // v = vector<vector<int>>(n,vector<int>(m)) ; 

    int Totalcells = n * m ; 
    int freeCells = Totalcells - 2 ;

    vector<int> source(k) ;
    for(auto &card : source) cin >> card ;

    reverse(all(source)) ;

    int lastCard = 0 ;
    int currNeeded = k ;

    set<int> line ; 

    while (source.size())
    {
        int topcard = source.back() ;
        source.pop_back() ;

        //dbg(currNeeded) ; cerr << "\n" ;

        if(freeCells > 1 and topcard == currNeeded)
        {
            currNeeded-- ;
            while(line.count(currNeeded))
            {
                line.erase(currNeeded) ;
                freeCells++ ;
                currNeeded-- ;
            }
        }

        else if(freeCells > 1 and topcard != currNeeded)
        {
            //cerr << "waiting list : " <<  topcard << nl ;
            freeCells-- ;
            line.insert(topcard) ;
        }

        else if(freeCells <= 1 and topcard != currNeeded)
        {
            cout << "TIDAK\n" ;
            return ;
        }

        else if(freeCells <= 1 and topcard == currNeeded)
        {
            cout << "TIDAK\n" ;
            return ;
        }

        //dbg(currNeeded,freeCells) ; cerr << nl << nl ;
    }


    //cerr << nl << nl << nl ;


    cout << "YA" << nl ;
    

    




}
signed main(){   FAST      TestCases      solve() ;  }




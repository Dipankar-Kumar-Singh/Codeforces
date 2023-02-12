    // Everything in the Universe is Balanced 
    // Every Disappointment you face in life will be balanced with something good for you 
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define TestCases int TOTALTC ; cin >> TOTALTC ; for(__case__ = 1 ; __case__ <=  TOTALTC ; __case__++)
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 
int __case__ = 1 ;


string s ;  

int getWinner(int x , int y , int round){
    return (s[round] == '1' ? max(x,y) : min(x,y)) ; 
}

bool isPossible(vector<int> &players , int round , int hero)
{
    if(players.size() == 1)
    {
        return ( players.front() == hero );
    }

    for (int i = 0; i + 1 < players.size(); i++)
    {
        for(int j = i + 1 ; j <  players.size() ; j++)
        {
            int x = players[i] ;
            int y = players[j] ;
            
            vector<int> vec ;

            for(int k = 0 ; k < players.size() ; k++)
            {
                if(k == i or k == j) continue ;
                vec.push_back(players[k]);
            }
            vec.push_back(getWinner(x, y, round));

            if (isPossible(vec, round + 1 , hero) == 1)
                return 1;
        }
    }

    return 0 ;
}

void solve()
{
    int n ;
    cin >> n ;                                   
    cin >> s;                    
                                 
    vector<int> players ;
    for(int i = 1 ; i <= n             ; i++)
        players.push_back(i) ;
                                                  
    vector<int> winner ;

    for(auto &x : players)
    {
        if(isPossible(players,0,x))
        {
            winner.push_back(x) ;
        }
    }
                                                                                                                                                                             

    cout << "s = " << s << "   n " << n << nl  ;

    cout << "NO of winner " << winner.size() << "   :     ";
    for(auto x : winner) cout << x <<  " " ;
    cout << nl << nl;

}

signed main() { FAST TestCases solve(); }

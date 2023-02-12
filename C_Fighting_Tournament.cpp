#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases int TOTALTC ; cin >> TOTALTC ; for(_case = 1 ; _case <=  TOTALTC ; _case++)
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 
int _case = 1 ;


class segmentTree {
public :
    int N = 5e5 ;
    vector<vector<int>> seg ;
    vector<int> v ;

    segmentTree(vector<int> &vec)
    {
        v = vec ; 
        int n  = v.size() ; N = n ;
        seg = vector<vector<int>>(4*N) ;
        build(0,0,n-1) ;
    }

    void build(int n , int s , int e )
    {
        if(s==e)
        {
            seg[n].push_back(v[s]);
            return ;
        }
        int mid = (s+e)/2 ;

        build(2 * n + 1, s, mid);
        build(2 * n + 2, mid + 1, e);

        merge(  
                begin(seg[2*n+1]) , end(seg[2*n+1]), 
                begin(seg[2*n+2]) , end(seg[2*n+2]), 
                back_inserter(seg[n])
             );
    }

    int query_equalto(int l, int r, int val)
    {
        return query_equalto(0,0,N-1,l,r,val) ;
    }

    int query_equalto(int n, int s, int e, int l, int r, int val)
    {
        if (e < l or s > r)
        {
            return 0;
        }

        if (l <= s and e <= r)
        {
            auto [ps, pe] = equal_range(begin(seg[n]), end(seg[n]), val);
            return pe - ps;
        }

        int mid = (s + e) / 2;

        return (
            query_equalto(2 * n + 1, s, mid, l, r, val) +
            query_equalto(2 * n + 2, mid + 1, e, l, r, val));
    }

};

void solve()
{
    int n , qq ; cin >> n >> qq ;

    int mainPlayer = -1 ;

    vector<int> power(n + 10);

    for (int i = 1; i <= n; i++)
    {
        cin >> power[i];
        if(power[i]==n) mainPlayer= i ;
    }

    queue<int> q;

    for (int i = 1; i <= n; i++)
    {
        q.push(i) ;
    }

    vector<int> vis(n + 10);

    int round = 1 ;

    int player1 = q.front()  , player2 = -1 ;
    q.pop() ;

    vis[player1] = 1 ;

    vector<int> performance(n+1) ;
    vector<int> winnerof (n) ;

    while(1)
    {
        player2 = q.front() ;
        q.pop() ;

        if(vis[player2]) break;
        vis[player2] = 1 ;

        if(power[player1] > power[player2])
        {
            performance[player1]++  ;
            q.push(player1) ;
            winnerof[round] = player1 ;
            player1 = player1 ;
        }

        else 
        {
            performance[player2]++  ;

            q.push(player2) ;
            winnerof[round] = player2 ;
            player1 = player2 ;
        }

        if(player1==mainPlayer) 
        {
            for( ; round <= n - 1 ; round++)
            {
                winnerof[round] = mainPlayer ; 
            }

            break;
        }

        round++ ;
    }

    segmentTree tree(winnerof) ;


    while(qq--)
    {
        round = 0 ;

        int player  ; 
        cin >> player >> round ;

        int ans = 0 ;

        // for(int i = 1 ; i <= min(n-1,round) ; i++)
        // {
        //     if(winnerof[i]==player)
        //     {
        //         ans++ ;
        //     }
        // }

        ans += tree.query_equalto(0,round,player) ;

        if(round >= (n-1))
        {
            if(player == mainPlayer)
            {
                int extra = round - (n-1) ;
                ans += extra ;
            }
        }

        cout << ans << nl ;
        
    }



}
signed main(){   FAST      TestCases      solve() ;  }




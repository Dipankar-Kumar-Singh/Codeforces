#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases int TOTALTC ; cin >> TOTALTC ; for(_case = 1 ; _case <=  TOTALTC ; _case++)
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 
int _case = 1 ;

int dis(int source , int destination , int m)
{
    return min(
                min(source, destination),   (2 * m)
            );
}

class segmentTree_lazy
{
public:
    
    int N = 1e6 + 10;
    vector<int> seg;
    vector<int> lazy;
    vector<int> v;

    segmentTree_lazy(vector<int> &vec)
    {
        v = vec;
        N = vec.size();
        seg.resize(4 * N, 0);
        lazy.resize(4 * N, 0);
        build(0, 0, N - 1);
    }

    int query(int l, int r)
    {
        return query(0, 0, N - 1, l, r);
    }

    void solvelazy(int n, int s, int e)
    {
        seg[n] += lazy[n] ;

        if (s != e)
        {
            lazy[n * 2 + 1] += lazy[n];
            lazy[n * 2 + 2] += lazy[n];
        }

        lazy[n] = 0;
    }

    void build(int n, int s, int e)
    {
        if (s == e)
        {
            seg[n] = v[s];
            return;
        }
        int mid = (s + e) / 2;
        build(n * 2 + 1, s, mid);
        build(n * 2 + 2, mid + 1, e);
        if (s != e)
        {
            seg[n] = min(seg[2 * n + 1], seg[2 * n + 2]);
        }
    }

    void update(int n , int s, int e , int id , int val)
    {
        if(id==s)
        {
            seg[n] = val ;
            return ;
        }

        int mid = midpoint(s,e) ;

        if (id <= mid)
            update(2 * n + 1, s, mid, id, val);
        else
            update(2 * n + 2, mid + 1, e, id, val);

        if(s!=e)
        {
            seg[n] = min(seg[2 * n + 1], seg[2 * n + 2]);
        }
    }

    int query(int n, int s, int e, int l, int r)
    {
        solvelazy(n, s, e);
        if (s > r or e < l)
        {
            return (int)(1e10);
        }
        if (s >= l and e <= r)
        {
            return seg[n];
        }
        int mid = (s + e) / 2;
        int ans = min(query(n * 2 + 1, s, mid, l, r) , query(n * 2 + 2, mid + 1, e, l, r));
        if (s != e)
        {
            seg[n] = min(seg[2 * n + 1], seg[2 * n + 2]);
        }
        return ans;
    }

};


void solve()
{
   int n;   cin >> n;
   int k ; cin >> k ;

   k-- ;
   
   vector<int> v(n);  for (auto &x : v) cin >> x;

   vector<pair<int,int>> vv(n) ;

    for(int i = 0 ; i < n ; i++)
    {
        vv[i] = {v[i],i} ;
    }

   sort(all(vv)) ;

    for(auto &[val,i] : vv)
    {
        if(k==0) break;
        v[i] = 1e9 ;
        k-- ;
        if(k==0) break;
    }

    segmentTree_lazy tree(v) ;

    int m = *min_element(all(v)) ;
    int M = *max_element(all(v)) ;
    int max_pos = max_element(all(v))  - v.begin() ;

 
    int ans = 1 ;

    // for(int i = 0 ; i < n ; i++)
    // {
    //     if(i==max_pos) continue; 
    //     int l = 0 , r = 0 ;

    //     if(max_pos < i) l =  max_pos , r =  i ;
    //     else if(max_pos > i) l =  i , r =  max_pos ;

    //     int localAns =  min(tree.query(l,r),(2 * m)) ;

    //     ans = max(  ans , localAns) ;
    //     int edge = tree.query(l,r) ;
    // }

    // cerr << "max_pos = " << max_pos << nl << nl ;

    // for(int i = 1 ; i < n; i++)
    // {
    //     for(int j = i - 1; j >=0 ; j--)
    //     {
    //         int localAns =  min(tree.query(j,i),(2 * m)) ;
    //         // if(localAns == 6)
    //         // {
    //         //     cerr << "at index : " << nl ;
    //         //     cerr <<  "l = " << j << "   r = " << i << nl ; 
    //         // }
    //         ans = max(ans,localAns) ;
    //     }
    // }

    // for(int i = 0 ; i < n; i++)
    // {
    //     if(v[i]==M)
    //     {
    //         if(i)
    //         {
    //             int path = min((2 * m), min(v[i - 1], v[i]));
    //             ans = max(ans,  path) ;
    //         }

    //         if(i+1 < n )
    //         {
    //             int path = min(2 * m, min(v[i + 1], v[i]));
    //             ans = max(ans,  path) ;
    //         }
    //     }
    // }

    // for(int i = 1 ; i < n ; i++)
    // {
    //     int localBest =  min(2*m,min(v[i] , v[i-1])) ;
    //     ans = max(ans, localBest) ;
    // }


    for(int i = 0 ; i < n ; i++)
    {
        int org = v[i] ; 
        v[i] = 1e9 ;

        tree.update(0,0,n-1,i,1e9) ;
        m = tree.query(0,n-1) ;

        if (i)
        {
            int path = min((2 * m), min(v[i - 1], v[i]));
            ans = max(ans, path);
        }

        if (i + 1 < n)
        {
            int path = min(2 * m, min(v[i + 1], v[i]));
            ans = max(ans, path);
        }

        tree.update(0,0,n-1,i,org) ;
        v[i] = org ;
    }




    cout << ans << nl ;

}
signed main(){   FAST      TestCases      solve() ;  }




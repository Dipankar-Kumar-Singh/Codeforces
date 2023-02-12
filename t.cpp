#include <bits/stdc++.h>
using namespace std;

#define int long long
#define TestCases int TOTALTC ; cin >> TOTALTC ; for(_case = 1 ; _case <=  TOTALTC ; _case++)
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 
int _case = 1 ;


class SegmentTree
{
public:
    int N = 1e6 + 10;
    vector<int> seg;
    vector<int> v;

    void pass(int n)
    {
        seg[n] = max(seg[n * 2 + 1], seg[n * 2 + 2]);
    }

    void clean()
    {
        seg.clear();
        v.clear();
    }

    SegmentTree(vector<int> &vec)
    {
        v = vec;
        N = vec.size();
        seg.resize(4 * N, 0);
        build(0, 0, N - 1);
    }

    void update(int l, int r, int value)
    {
        update(0, 0, N - 1, l, r, value);
    }

    int query(int l, int r)
    {
        return query(0, 0, N - 1, l, r);
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
            pass(n);
        }
    }

    void update(int n, int s, int e, int l, int r, int value)
    {
        if (s > r or e < l)
        {
            return;
        }
        if (s >= l and e <= r)
        {
            seg[n] = value ;
            return;
        }
        int mid = (s + e) / 2;
        update(n * 2 + 1, s, mid, l, r, value);
        update(n * 2 + 2, mid + 1, e, l, r, value);
        if (s != e)
        {
            pass(n);
        }
    }

    int query(int n, int s, int e, int l, int r)
    {
        if (s > r or e < l)
        {
            return -1;
        }
        if (s >= l and e <= r)
        {
            return seg[n];
        }
        int mid = (s + e) / 2;
        int ans = max(query(n * 2 + 1, s, mid, l, r) , query(n * 2 + 2, mid + 1, e, l, r));
        if (s != e)
        {
            pass(n);
        }
        return ans;
    }

};


void solve()
{
   int n ; cin >> n ;
   int m ; cin >> m ;
   vector<int> v(m) ; for (auto &x : v) cin >> x ;

   SegmentTree seg(v) ;

   int q ; cin >> q ;
   while(q--)
   {
        int x , y ; cin >> x >> y ;
        int xx , yy ; cin >> xx >> yy ;
        int k ; cin >> k ;

        x-- , y--, xx-- , yy-- ;
        int s = min(y,yy) ; int e = max(y,yy) ;
        int h = seg.query(s,e) ;
        h-- ;

        if(h==n-1)
        {
            cout << "NO\n" ;
            continue; ;
        }


        if(x>h or xx>h)
        {
            // cout << " H = " << h << "    " ;
            int vertical = abs(max(x,xx) - min(x,xx)) ;
            int hor = e - s ;

            if ((vertical % k) or (hor % k))
            {
                cout << "NO\n" ;
            } 
            else 
            {
                cout << "YES\n" ;
            }
        }

        else 
        {
            int up = abs(h - x) + 1;
            int down = abs(h - xx) + 1 ;
            int hor = abs(e - s) ;

            if ((up % k) or (down % k) or (hor % k))
            {
                int q1 = (h-x)/k ;
                int poss = 0 ;
                while ((++q1* k) + x < n)
                {
                    int Hnew = (q1* k) + x;
                    if(Hnew >= n) break;
                    int newReq2 = Hnew - xx ; 
                    if(Hnew%k==0 and newReq2%k==0 )
                    {
                        poss = 1 ;
                        break;
                    }
                }
                if(poss) {
                    cout << "YES\n";
                }
                else cout << "NO\n" ;
            } 
            else 
            {
                 cout << "YES\n";
            }
        }
   }

   

   


}
signed main(){   FAST       solve() ;  }

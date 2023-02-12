#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases   int total ; cin >> total ;  for(test = 1 ; test <=  total ; test++)
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n"  
#define print(ans) cout << "Case #" << test << ": " << ans << "\n" ;


int const INF  = 1e18 ;
int test = 0 ;


class segmentTreeMIN
{
    public:
    int N = 0;
    vector<int> seg;
    vector<int> v;

    int mergeOP(int &a, int &b)
    {
        return min(a,b) ;
    }

    segmentTreeMIN(vector<int> &vec)
    {
        v = vec;
        N = vec.size();
        seg = vector<int>(4 * N);
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
            seg[n] = mergeOP(seg[n * 2 + 1], seg[n * 2 + 2]);
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
            seg[n] += value;
            return;
        }

        int mid = (s + e) / 2;
        update(n * 2 + 1, s, mid, l, r, value);
        update(n * 2 + 2, mid + 1, e, l, r, value);

        if (s != e)
        {
            seg[n] = mergeOP(seg[n * 2 + 1], seg[n * 2 + 2]);
        }
    }

    int query(int n, int s, int e, int l, int r)
    {
        if (s > r or e < l)
        {
            return INF;
        }
        if (s >= l and e <= r)
        {
            return seg[n];
        }
        int mid = (s + e) / 2;

        int left = query(n * 2 + 1, s, mid, l, r);
        int right = query(n * 2 + 2, mid + 1, e, l, r);

        int ans = mergeOP(left, right);

        if (s != e)
        {
            seg[n] = mergeOP(seg[n * 2 + 1], seg[n * 2 + 2]);
        }

        return ans;
    }
};


class segmentTreeMAX
{

    public:
    int N = 0;
    vector<int> seg;
    vector<int> v;

    int mergeOP(int &a, int &b)
    {
        return max(a,b)  ;
    }

    segmentTreeMAX(vector<int> &vec)
    {
        v = vec;
        N = vec.size();
        seg = vector<int>(4 * N);
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
            seg[n] = mergeOP(seg[n * 2 + 1], seg[n * 2 + 2]);
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
            seg[n] += value;
            return;
        }

        int mid = (s + e) / 2;
        update(n * 2 + 1, s, mid, l, r, value);
        update(n * 2 + 2, mid + 1, e, l, r, value);

        if (s != e)
        {
            seg[n] = mergeOP(seg[n * 2 + 1], seg[n * 2 + 2]);
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

        int left = query(n * 2 + 1, s, mid, l, r);
        int right = query(n * 2 + 2, mid + 1, e, l, r);

        int ans = mergeOP(left, right);

        if (s != e)
        {
            seg[n] = mergeOP(seg[n * 2 + 1], seg[n * 2 + 2]);
        }

        return ans;
    }
};


int check(int l , int r , segmentTreeMIN &mintree , segmentTreeMAX &maxtree)
{
    if(l==r) return 0 ;
    int mid = midpoint(l,r) ;

    if(maxtree.query(l,r) - mintree.query(l,r) > (r-l))return -1 ;

    int minLeft = mintree.query(l,mid) ;
    int maxright =  maxtree.query(mid+1,r) ;

    int leftAns = check(l,mid,mintree,maxtree) ;
    int rightAns = check(mid+1,r,mintree,maxtree) ;

    if (leftAns == -1 or rightAns == -1) return -1;

    int ans = leftAns + rightAns   ;
    ans += (minLeft > maxright);
    return ans ;
}

void solve()
{
    int n ; cin >> n ;
    vector<int> v(n) ; for(auto &x : v) cin >> x ; 

    segmentTreeMAX maxtree(v) ;
    segmentTreeMIN minrtree(v) ;

    int ans = check(0,n-1,minrtree,maxtree) ;
    cout << ans << nl ;
    
}

signed main(){  FAST    TestCases    solve() ; }
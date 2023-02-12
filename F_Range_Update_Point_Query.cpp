#include <bits/stdc++.h>
using namespace std;
#define int     long long
#define all(x)  begin(x) , end(x)
#define nl      "\n" 


class segmentTree
{
    //!  IMPORTANT :
    //TODO : CHANGE THE RETURN VALUE IN QUERY [ for {0,INF} seg out of range ] 

public:
    int N = 1e6 + 10;
    vector<int> seg , lazy , v ;

    int mergeOP(int &a, int &b)
    {
        return a + b;
    }

    segmentTree(vector<int> &vec)
    {
        v = vec;
        N = vec.size();
        seg.resize(4 * N, 0);
        lazy.resize(4 * N, 0);
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

    void solvelazy(int n, int s, int e)
    {
        int rng = e - s + 1;
        //! for assignment or for MIN/MAX ... change this ... to seg[n] +=  lazy[n] ;
        // seg[n] +=  lazy[n] 

        // This is for Addition : 
        seg[n] += lazy[n] * rng;

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
            seg[n] = mergeOP(seg[2 * n + 1], seg[2 * n + 2]);
        }
    }

    void update(int n, int s, int e, int l, int r, int value)
    {
        solvelazy(n, s, e);

        if (s > r or e < l)
        {
            return;
        }

        if (s >= l and e <= r)
        {
            // !! FOR MIN / MAX [ use += ] //
            // !! FOR ASSIGNMENT [ use = ] //

            lazy[n] += value;
            solvelazy(n, s, e);
            return;
        }

        int mid = (s + e) / 2;
        update(n * 2 + 1, s, mid, l, r, value);
        update(n * 2 + 2, mid + 1, e, l, r, value);

        if (s != e)
        {
            seg[n] = mergeOP(seg[2 * n + 1], seg[2 * n + 2]);
        }
    }

    int query(int n, int s, int e, int l, int r)
    {
        solvelazy(n, s, e);
        if (s > r or e < l)
        {
            //! Change Return Type to Counter [ to Nullify effect and Preserve Ans ] 
            //* FOR [ + ,GCD ]  ==> 0 , for MIN ==> INF , for MAX = -INF , 
            //*==> ex ==> for AND --> Give it ==> "111111" all Ones
            
            return 0;
        }
        if (s >= l and e <= r)
        {
            return seg[n];
        }

        int mid = (s + e) / 2;

        if (s != e)
        {
            seg[n] = mergeOP(seg[2 * n + 1], seg[2 * n + 2]);
        }

        int left = query(n * 2 + 1, s, mid, l, r);
        int right = query(n * 2 + 2, mid + 1, e, l, r);
        return mergeOP(left, right);
    }
};

vector<int> relax(vector<int> &v)
{
    vector<int> res ;
    for(auto x : v)
    {
        int sum = 0 ;
        while (x > 0)
        {
            int d = x % 10 ;
            sum += d ;
            x/=10 ;
        }
        
        res.push_back(sum) ;
    }

    return res ;
}


void solve(int& __case__)
{
    int n , q ; cin >> n >> q ;

    vector<int> v(n) ;
    for(auto &x : v) cin >> x ;

    vector<int> layer1 , layer2 , layer3 , layer4 ;

    layer1 = v ;
    layer2 = relax(layer1) ;
    layer3 = relax(layer2) ;
    layer4 = relax(layer3) ;


    vector<int> mask(n) ;
    segmentTree tree(mask) ;
    

    while(q--)
    {
        int t ; cin >> t ;
        if(t==1)
        {
            int l ,r ; 
            cin >> l >> r ;
            l-- , r-- ;
            tree.update(l,r,1) ;
        }
        else 
        {
            int id ;
            cin >> id ;
            id-- ;

            int updateLayer = tree.query(id,id) ;
            updateLayer = min(updateLayer,3LL) ;

            if(updateLayer == 0)
            {
                cout << layer1[id] << nl ;
            }
            else if(updateLayer == 1)
            {
                cout << layer2[id] << nl ;
            }
            else if(updateLayer == 2)
            {
                cout << layer3[id] << nl ;
            }
            else if(updateLayer == 3)
            {
                cout << layer4[id] << nl ;
            }
        }
    }

}

signed main()
{   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int testCases = 1 , case_ = 1;     
    cin >> testCases; for (int case_ = 1; case_ <= testCases; case_++) 
        solve(case_);
}

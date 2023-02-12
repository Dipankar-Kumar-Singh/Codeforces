#include<bits/stdc++.h>
using namespace std ;

class segmentTree
{
    //!  IMPORTANT :
    //TODO : CHANGE THE RETURN VALUE IN QUERY [ for {0,INF} seg out of range ] 

public:
    int N = 1e6 + 10;
    vector<int> seg;
    vector<int> lazy;
    vector<int> v;
    
    int mergeOP(int &a, int &b)
    {
        return a + b;
        // return min(a,b) ;
        // return max(a,b)  ;
        // return gcd(a, b);
        // return a ^ b ;
        // return a | b ;
        // return a & b ;
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

        int left = query(n * 2 + 1, s, mid, l, r);
        int right = query(n * 2 + 2, mid + 1, e, l, r);

        int ans = mergeOP(left, right);

        if (s != e)
        {
            seg[n] = mergeOP(seg[2 * n + 1], seg[2 * n + 2]);
        }

        return ans;
    }
};


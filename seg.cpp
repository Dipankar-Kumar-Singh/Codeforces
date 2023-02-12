class segmentTree
{
    //!  IMPORTANT :
    //TODO : CHANGE THE RETURN VALUE IN QUERY [ for {0,INF} seg out of range ] 

    public:
    int N = 0;
    vector<int> seg;
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
            seg[n] = mergeOP(seg[n * 2 + 1], seg[n * 2 + 2]);
        }

        return ans;
    }
};
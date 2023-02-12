#include <bits/stdc++.h>
using namespace std;
#define int long long
#define TestCases   int _test {1} ; cin >> _test ; while(_test--) 
#define FAST  ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define all(x)  (x).begin() , (x).end()
#define nl "\n" 

int INF = -1e15 ;


class segmentTree_lazy
{
public:
    int N = 1e6 + 10;
    vector<int> seg;
    vector<int> lazy;
    vector<int> v;

    void pass(int n)
    {
        seg[n] = max(seg[n * 2 + 1] , seg[n * 2 + 2]);
    }

    void clean()
    {
        seg.clear();
        lazy.clear();
        v.clear();
    }

    segmentTree_lazy(vector<int> &vec)
    {
        v = vec;
        N = vec.size();
        seg.resize(4 * N, 0);
        lazy.resize(4 * N, 0);
        build(0, 0, N - 1);
    }

    segmentTree_lazy(vector<int> &vec, int size)
    {
        N = size;
        v.resize(N, 0);
        for (int i = 0; i < N; i++)
            v[i] = vec[i];
        seg.resize(4 * N + 10, 0);
        lazy.resize(4 * N + 10, 0);
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
            pass(n);
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
            lazy[n] += value;
            solvelazy(n, s, e);
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
        solvelazy(n, s, e);
        if (s > r or e < l)
        {
            return -1e15;
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

    void print()
    {
        cout << "seg = [ ";
        for (int i = 0; i < N; i++)
            cout << query(i, i) << " ";
        cout << " ]\n";
    }

    void printCerr()
    {
        cerr << "seg = [ ";
        for (int i = 0; i < N; i++)
            cerr << query(i, i) << " ";
        cerr << " ]\n";
    }
};

vector<int> nextGreater_indexs(vector<int>& arr, int n) {
    stack<int> s;	
        vector<int> result(n, n);
    for (int i = 0; i < n; i++) {
        while (!s.empty() && arr[s.top()] < arr[i]) {
            result[s.top()] = i;	
            s.pop();
        }
        s.push(i);
    }
        return result;
}
vector<int> prevGreater_indexs(vector<int>& arr, int n) {
    stack<int> s;	
        vector<int> result(n, -1);
    for (int i = n - 1; i >= 0; i--) {
        while (!s.empty() && arr[s.top()] < arr[i]) {
            result[s.top()] = i;	
            s.pop();
        }
        s.push(i);
    }
        return result;
}


void solve()
{
    int n ; cin >> n;
    vector<int> v(n) ;
    for(auto &x : v) cin >> x ;
    
    vector<int> arr = v ;

    vector<long long> prefix(n, 0), suffix(n, 0);
        prefix[0] = arr[0];
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + arr[i];
        }
        suffix[n - 1] = arr[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            suffix[i] = suffix[i + 1] + arr[i];
        }

    segmentTree_lazy tree2(suffix) ;

    // for(int i = 0 ; i < n ; i++)  swap(prefix[i],prefix[i+1]) ;
    // prefix.resize(n) ;

    segmentTree_lazy tree(prefix) ;

    vector<int> ng  = nextGreater_indexs(v,v.size()) ;
    vector<int> pg =  prevGreater_indexs(v,v.size()) ;

     bool flag = true;

    for(int i = 0 ; i < n ; i++)
    {
		int rightMax = tree.query(i+1,ng[i]-1) - prefix[i] ;
        int leftMax = tree2.query(pg[i]+1,i-1) - suffix[i] ;
		
        if (max(rightMax, leftMax) > 0) {
                flag = false;
                break;
        }

    }

     if (flag)  cout << "YES\n";
        else  cout << "NO\n";

}

signed main()
{   FAST  

    TestCases  
    solve() ;  

}


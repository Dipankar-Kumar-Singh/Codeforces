#include<bits/stdc++.h>
using namespace std ;

class segmentTreeMAAXX
{
    private:
    int N = 1e6 + 10;
    std::vector<int> seg , lazy , v ;
 
    int mergeOP(int &a, int &b) {
        return std::max(a,b) ;
    }

    public:
    segmentTreeMAAXX(int n) 
    {
        N = n;
        v = std::vector<int>(n);
        seg.resize(4 * N, 0);
        lazy.resize(4 * N, 0);
    }
 
    segmentTreeMAAXX(std::vector<int> &vec)
    {
        v = vec;
        N = vec.size();
        seg.resize(4 * N, 0);
        lazy.resize(4 * N, 0);
        build(0, 0, N - 1);
    }
 
    void rangeApply(int l, int r, int value){
        update(0, 0, N - 1, l, r, value);
    }
 
    int rangeQuery(int l, int r){
        return query(0, 0, N - 1, l, r);
    }
    
    private:
    void solvelazy(int n, int s, int e){
        
        if(lazy[n] == 0 ) return ;

        seg[n] += lazy[n] ;
        if (s != e) {
            lazy[n * 2 + 1] += lazy[n];
            lazy[n * 2 + 2] += lazy[n];
        }

        lazy[n] = 0;
    }
 
    void build(int n, int s, int e)
    {
        if (s == e){
            seg[n] = v[s];
            return;
        }
        int mid = (s + e) / 2;
        build(n * 2 + 1, s, mid);
        build(n * 2 + 2, mid + 1, e);
        if (s != e) {
            seg[n] = mergeOP(seg[2 * n + 1], seg[2 * n + 2]);
        }
    }
 
    void update(int n, int s, int e, int l, int r, int value)
    {
        solvelazy(n, s, e);
 
        if (s > r or e < l){
            return;
        }
 
        if (s >= l and e <= r){
            lazy[n] += value;
            solvelazy(n, s, e);
            return;
        }
 
        int mid = (s + e) / 2;
        update(n * 2 + 1, s, mid, l, r, value);
        update(n * 2 + 2, mid + 1, e, l, r, value);
 
        if (s != e){
            seg[n] = mergeOP(seg[2 * n + 1], seg[2 * n + 2]);
        }
    }
 
    int query(int n, int s, int e, int l, int r)
    {
        solvelazy(n, s, e);
 
        if (s > r or e < l){
            return 0;
        }
        if (s >= l and e <= r){
            return seg[n];
        }
 
        int mid = (s + e) / 2;
        int left = query(n * 2 + 1, s, mid, l, r);
        int right = query(n * 2 + 2, mid + 1, e, l, r);
        return mergeOP(left, right);
    }
};



template<class Info, class Tag>
struct LazySegmentTree {
    int n;
    std::vector<Info> info;
    std::vector<Tag> tag;
    LazySegmentTree() : n(0) {}
    LazySegmentTree(int n_, Info v_ = Info()) {
        init(n_, v_);
    }
    template<class T>
    LazySegmentTree(std::vector<T> init_) {
        init(init_);
    }
    void init(int n_, Info v_ = Info()) {
        init(std::vector(n_, v_));
    }
    template<class T>
    void init(std::vector<T> init_) {
        n = init_.size();
        info.assign(4 << std::__lg(n), Info());
        tag.assign(4 << std::__lg(n), Tag());
        std::function<void(int, int, int)> build = [&](int p, int l, int r) {
            if (r - l == 1) {
                info[p] = init_[l];
                return;
            }
            int m = (l + r) / 2;
            build(2 * p, l, m);
            build(2 * p + 1, m, r);
            pull(p);
        };
        build(1, 0, n);
    }
    void pull(int p) {
        info[p] = info[2 * p] + info[2 * p + 1];
    }
    void apply(int p, const Tag &v) {
        info[p].apply(v);
        tag[p].apply(v);
    }
    void push(int p) {
        apply(2 * p, tag[p]);
        apply(2 * p + 1, tag[p]);
        tag[p] = Tag();
    }
    void modify(int p, int l, int r, int x, const Info &v) {
        if (r - l == 1) {
            info[p] = v;
            return;
        }
        int m = (l + r) / 2;
        push(p);
        if (x < m) {
            modify(2 * p, l, m, x, v);
        } else {
            modify(2 * p + 1, m, r, x, v);
        }
        pull(p);
    }
    void modify(int p, const Info &v) {
        modify(1, 0, n, p, v);
    }
    Info rangeQuery(int p, int l, int r, int x, int y) {
        if (l >= y || r <= x) {
            return Info();
        }
        if (l >= x && r <= y) {
            cerr << "range " 
                << l 
                << " " 
                << r 
                << "ans : "  
                << (info[p].max) << endl ;
            return info[p];
        }
        int m = (l + r) / 2;
        push(p);
        return rangeQuery(2 * p, l, m, x, y) + rangeQuery(2 * p + 1, m, r, x, y);
    }
    Info rangeQuery(int l, int r) {
        return rangeQuery(1, 0, n, l, r);
    }
    void rangeApply(int p, int l, int r, int x, int y, const Tag &v) {
        if (l >= y || r <= x) {
            return;
        }
        if (l >= x && r <= y) {
            apply(p, v);
            return;
        }
        int m = (l + r) / 2;
        push(p);
        rangeApply(2 * p, l, m, x, y, v);
        rangeApply(2 * p + 1, m, r, x, y, v);
        pull(p);
    }
    void rangeApply(int l, int r, const Tag &v) {
        return rangeApply(1, 0, n, l, r, v);
    }
    template<class F>
    int findFirst(int p, int l, int r, int x, int y, F pred) {
        if (l >= y || r <= x || !pred(info[p])) {
            return -1;
        }
        if (r - l == 1) {
            return l;
        }
        int m = (l + r) / 2;
        push(p);
        int res = findFirst(2 * p, l, m, x, y, pred);
        if (res == -1) {
            res = findFirst(2 * p + 1, m, r, x, y, pred);
        }
        return res;
    }
    template<class F>
    int findFirst(int l, int r, F pred) {
        return findFirst(1, 0, n, l, r, pred);
    }
    template<class F>
    int findLast(int p, int l, int r, int x, int y, F pred) {
        if (l >= y || r <= x || !pred(info[p])) {
            return -1;
        }
        if (r - l == 1) {
            return l;
        }
        int m = (l + r) / 2;
        push(p);
        int res = findLast(2 * p + 1, m, r, x, y, pred);
        if (res == -1) {
            res = findLast(2 * p, l, m, x, y, pred);
        }
        return res;
    }
    template<class F>
    int findLast(int l, int r, F pred) {
        return findLast(1, 0, n, l, r, pred);
    }
};

struct Tag {
    int add = 0;
    void apply(Tag t) & {
        add += t.add;
    }
};

struct Info {
    int max = 0;
    void apply(Tag t) & {
        max += t.add;
    }
};

Info operator+(const Info &a, const Info &b) {
    return {std::max(a.max, b.max)};
}


mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count()); 
int gen(int l, int r) {
    return l + rng() % (r - l + 1);
}


signed main(){
    int n; cin >> n ;
    segmentTreeMAAXX tree(n + 1) ;
    LazySegmentTree<Info, Tag> seg(n + 2);

    seg.rangeApply(0,5, {100}) ;
    for(int i = 0 ; i < 10 ; i++) 
        cout << seg.rangeQuery(i,i).max << endl ;
    // cout << seg.rangeQuery(0,9).max << endl ;

    // auto prints = [&](){
        
    //     for(int i = 0 ; i < n ; i++){
    //         cout << tree.rangeQuery(i,i) << " " ;
    //     } cout << '\n' ;

    //     for(int i = 0 ; i < n ; i++){
    //         cout << seg.rangeQuery(i,i).max << " " ;
    //     } cout << '\n' ;

    // };

    // function apply = [&](int l , int r , int val ) -> void {
    //     tree.rangeApply(l,r,val) ;
    //     seg.rangeApply(l,r,{val}) ;
    // };


    // seg.rangeApply(0,9, {-10} ) ;
    // seg.rangeApply(0,9, {10} ) ;
    // seg.rangeApply(0,9, {10} ) ;
    // prints() ;


    // function testing_segmentTree = [&](){
    //     int n = gen(0,10000) ;
    //     tree = segmentTreeMAAXX(n) ;
    //     seg = LazySegmentTree<Info, Tag>(n) ;

    //     function isSame = [&](){
    //         for(int i = 0; i < n ;i++){
    //             if(tree.rangeQuery(i,i) != seg.rangeQuery(i,i).max) {
    //                 cout << "a : " << tree.rangeQuery(i,i) ;
    //                 cout << "\tb : " <<  seg.rangeQuery(i,i).max ;
    //                 // cout << "\n🔥🔥🔥\n" ;
    //                 cout << '\n' ;
    //             }

    //         };
    //     };

    //     for(int i = 0 ; i < gen(0,10) ; i++){
    //         int l = gen(0,n - 1) ;
    //         int r = gen(0,n - 1) ;

    //         int delta = gen(0,20) ;
    //         if(l > r ) swap(l , r) ;

    //         int val = gen(0,20)  ;
    //         apply(l,r,val) ;
    //     }

    //     isSame() ;
    // };

    // testing_segmentTree() ;



    // tree.rangeApply(0,0,-1) ;
    // prints() ;

    // tree.rangeApply(0,5,2) ;
    // prints() ;
    



}

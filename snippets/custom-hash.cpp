// Anti-hack hash for unordered_map / unordered_set.
// Plain unordered_map<int,int> gets hacked to TLE on Codeforces via collisions.
// Usage:  unordered_map<int, int, chash> mp;
//         unordered_set<int, chash> st;
struct chash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15ULL;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9ULL;
        x = (x ^ (x >> 27)) * 0x94d049bb133111ebULL;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED =
            chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED);
    }
};

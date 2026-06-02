// __int128 I/O. NOTE: with `#define int long long`, write `__int128` literally
// (do not rely on the `int` macro here). Use for overflow-safe products / sums.
istream& operator>>(istream& in, __int128& x) {
    string s; in >> s;
    x = 0;
    bool neg = (!s.empty() && s[0] == '-');
    for (size_t i = neg; i < s.size(); i++) x = x * 10 + (s[i] - '0');
    if (neg) x = -x;
    return in;
}
ostream& operator<<(ostream& out, __int128 x) {
    if (x < 0) { out << '-'; x = -x; }
    if (x > 9) out << x / 10;
    return out << (char)('0' + (int)(x % 10));
}

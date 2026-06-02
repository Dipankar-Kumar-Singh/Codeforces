// Recursive lambda without a named function (C++17+).
// Usage:
//   auto dfs = y_combinator([&](auto self, int u, int p) -> void {
//       for (int v : adj[u]) if (v != p) self(v, u);
//   });
//   dfs(root, -1);
template <class F>
struct y_combinator_result {
    F f;
    template <class... Args>
    decltype(auto) operator()(Args&&... args) {
        return f(*this, forward<Args>(args)...);
    }
};
template <class F>
y_combinator_result<decay_t<F>> y_combinator(F&& f) {
    return {forward<F>(f)};
}

// PBDS ordered_set: order statistics in O(log n).
//   os.find_by_order(k) -> iterator to k-th smallest (0-indexed)
//   os.order_of_key(v)  -> number of elements strictly less than v
// For an ordered MULTIset, use a pair<value, uniqueId> or map to less_equal<>.
//
// WARNING: __gnu_pbds is GCC-ONLY. Will NOT compile under Apple clang locally.
// Works on AtCoder / Codeforces judges. Compile locally with real g++ to test.
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template <class T>
using oset = tree<T, null_type, less<T>, rb_tree_tag,
                  tree_order_statistics_node_update>;

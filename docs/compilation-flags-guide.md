# C++ Compilation Flags Guide

A reference for compiling C++ with maximum diagnostics, aimed at competitive
programming. The goal here is **catching as many bugs as possible**, trading
away compile-time and runtime speed during local testing.

Key fact: `-Wall` does **not** mean "all warnings" despite the name. Real
coverage needs several more flags.

---

## TL;DR — the competitive-programming sweet spot

```bash
g++ -std=c++23 -O2 -Wall -Wextra -Wshadow -Wconversion \
    -fsanitize=address,undefined -D_GLIBCXX_DEBUG -DCPH
```

Catches the bugs that actually lose points — shadowing, sign/narrowing
conversions, out-of-bounds access, integer overflow — while staying readable
instead of drowning you in pedantic noise.

> Drop `-fsanitize=...` and `-D_GLIBCXX_DEBUG` for the **actual submission**.
> Judges don't run them, and they slow code ~2-3x. Use plain `-O2` to submit.

---

## Maximum diagnostics (GCC)

```bash
g++ -std=c++23 -Og -g \
    -Wall -Wextra -Wpedantic \
    -Wshadow -Wconversion -Wsign-conversion \
    -Wfloat-equal -Wcast-qual -Wold-style-cast \
    -Wuseless-cast -Wdouble-promotion -Wformat=2 \
    -Wnull-dereference -Wduplicated-cond -Wduplicated-branches \
    -Wlogical-op -fsanitize=address,undefined \
    -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -DCPH \
    -fno-omit-frame-pointer
```

### What each warning flag catches

| Flag | Catches |
|---|---|
| `-Wall` | Common mistakes: unused vars, missing returns, etc. (the baseline) |
| `-Wextra` | The second tier `-Wall` skips: unused params, sign-compare |
| `-Wpedantic` | Reliance on non-standard GCC extensions |
| `-Wshadow` | A variable hiding an outer one (nested `for(int i...)` bug) |
| `-Wconversion` | Implicit narrowing that silently loses data (`int = long long`) |
| `-Wsign-conversion` | Signed/unsigned mixing (`size()` vs `int i` loop bug) |
| `-Wfloat-equal` | Comparing floats with `==` |
| `-Wcast-qual` | Casts that drop `const`/`volatile` |
| `-Wold-style-cast` | C-style `(int)x` instead of `static_cast` |
| `-Wuseless-cast` | Casts that do nothing |
| `-Wdouble-promotion` | Accidental `float` -> `double` promotion |
| `-Wformat=2` | `printf`/`scanf` format-string mismatches |
| `-Wnull-dereference` | Provable null dereferences |
| `-Wduplicated-cond` | Copy-paste mistakes in `if / else if` chains |
| `-Wduplicated-branches` | Identical branches of an `if/else` |
| `-Wlogical-op` | Suspicious `&&` / `||` (e.g. `x > 0 && x > 0`) |

---

## The real bug-catchers: runtime sanitizers + debug containers

Compile-time warnings only go so far. Since runtime speed doesn't matter while
testing:

- **`-fsanitize=address`** (ASan) — out-of-bounds access, use-after-free,
  stack overflow. Finds the bugs behind silent WA/RE on judges.
- **`-fsanitize=undefined`** (UBSan) — signed integer overflow, oversized
  shifts, invalid casts, null derefs at runtime.
- **`-D_GLIBCXX_DEBUG`** — makes `std::vector::operator[]`, iterators, etc.
  bounds-check and abort with a clear message. Catches most CP runtime errors
  on its own.
- **`-D_GLIBCXX_DEBUG_PEDANTIC`** — even stricter libstdc++ checks.

Pair sanitizers with `-Og` (or `-O0`) and `-g` for readable diagnostics and
stack traces. `-fno-omit-frame-pointer` keeps traces accurate.

---

## Truly paranoid (high noise — more for library code)

```bash
-Weffc++ -Wctor-dtor-privacy -Wstrict-null-sentinel \
-Wnon-virtual-dtor -Woverloaded-virtual -Wcast-align \
-Wzero-as-null-pointer-constant -Wmissing-declarations
```

`-Weffc++` especially is very noisy. Useful for production C++, overkill for
contests.

---

## Clang alternative

Clang has a meta-flag GCC lacks:

```bash
clang++ -std=c++23 -Weverything -Wno-c++98-compat -Wno-padded
```

`-Weverything` literally enables every warning Clang has. Overwhelming by
design — nobody ships clean against it, but it's excellent for *seeing*
everything, then `-Wno-...`'ing the noise you don't want.

---

## The `-DCPH` flag

`-DCPH` defines the `CPH` preprocessor macro (Competitive Programming Helper).
Lets one source file compile two ways:

```cpp
#ifdef CPH
    freopen("input.txt", "r", stdin);   // local-only test scaffolding
#endif
```

- **Locally** with `-DCPH` -> debug/test scaffolding active.
- **On the judge** (no `-DCPH`) -> that code vanishes, reads stdin normally.

---

## Quick recipes

**Local testing (catch everything):**

```bash
g++ -std=c++23 -Og -g -Wall -Wextra -Wshadow -Wconversion -Wsign-conversion \
    -fsanitize=address,undefined -D_GLIBCXX_DEBUG -DCPH sol.cpp -o sol
```

**Submission build (fast, what the judge effectively runs):**

```bash
g++ -std=c++23 -O2 -Wall sol.cpp -o sol
```


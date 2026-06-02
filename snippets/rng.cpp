// Seeded RNG. Use for randomized algorithms and to defeat anti-hash attacks.
// shuffle(all(v), rng);  |  rng() % n  |  uniform_int_distribution<int>(l, r)(rng)
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

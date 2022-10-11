const uint64_t FIXED = 1 |
  chrono::steady_clock::now()
    .time_since_epoch()
    .count();
struct MyHash {
  static uint64_t splitmix64(uint64_t x) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }
  uint64_t operator()(uint64_t x) const {
    return splitmix64(x + FIXED);
  }
  uint64_t operator()(const pii &p) const {
    return splitmix64(p.F * FIXED + p.S);
  }
};
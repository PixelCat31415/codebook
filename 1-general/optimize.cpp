int mulll(int a, int b, int M) {
  int r = a * b - M * int(1.L / M * a * b);
  return r + M * ((r < 0) - (r >= (int)M));
}
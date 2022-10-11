int min_rot(int n, string s) {
  s = s + s;
  int i = 0, ans = 0;
  while (i < n) {
    ans = i;
    int j = i + 1, k = i;
    while (j < sz(s) && s[j] >= s[k]) {
      if (s[j] == s[k]) k++;
      else k = i;
      j++;
    }
    while (i <= k) i += j - k;
  }
  return ans;
}
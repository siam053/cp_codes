
ll BITree[N];

void BIT_init() {
  for (int i = 1; i < n+1; ++i) BITree[i] = 0;
}
void updateBIT(int i, int v) {
    ++i;
    while(i<=n) {
        BITree[i] += v;
        i += i&(-i);
    }
}
ll getSum(int i) {
    ++i;
    ll ret = 0;
    while(i>0) {
        ret += BITree[i];
        i -= i&(-i);
    }
    return ret;
}

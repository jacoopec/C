static int sum(unsigned n, int const a[n]){
    int s = 0;
    for(int i = 0; i != n; ++i){
        s += a[i];
    }
    return s;
}
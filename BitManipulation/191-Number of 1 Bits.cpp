int hammingWeight1(uint32_t n) {
    int num(0);
    for(int i=0; i<32; i++){
        num += (n>>i)&1;
    }
    return num;
}
int hammingWeight(uint32_t n) {
    int num(0);
    while (n != 0) {
        num++;
        n &= (n - 1);
    }
    return num;
}

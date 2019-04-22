bool isHappy2(int n) {
    unordered_set<int> storges;
    int sum(0);
    while(1)
    {
        sum = 0;
        while(n)
        {
            int b = n%10;
            sum += b*b;
            n /= 10;
        }
        if(sum == 1)
            break;
        if(!storges.count(sum))
            storges.insert(sum);
        else
            break;
        n = sum;
    }
    return (sum == 1);
}
int digitSquareSum(int n) {
    int sum = 0, tmp;
    while (n) {
        tmp = n % 10;
        sum += tmp * tmp;
        n /= 10;
    }
    return sum;
}

bool isHappy(int n) {
    int slow, fast;
    slow = fast = n;
    do {
        slow = digitSquareSum(slow);
        fast = digitSquareSum(fast);
        fast = digitSquareSum(fast);
    } while(slow != fast);
    if (slow == 1) return 1;
    else return 0;
}

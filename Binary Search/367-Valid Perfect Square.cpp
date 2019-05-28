bool isPerfectSquare1(int num) {
    int begin(1), end(num);
    int temp(1);
    int mid(num);

    while(temp<mid){
        temp = temp<<1;
        mid = num/temp;
    }
    end = temp;
    while(begin<=end){
        mid = (begin+end)/2;
        int mid2 = num/mid;
        int mid3 = num%mid;
        if(mid == mid2 && !mid3)
            return true;
        else if(mid < mid2)
            begin = mid+1;
        else
            end = mid-1;
    }
    return false;
}
bool isPerfectSquare2(int num) {
    int i = 1;
    while (num > 0) {
        num -= i;
        i += 2;
    }
    return num == 0;
}
bool isPerfectSquare(int num) {
    long x = num;
    while (x * x > num) {
        x = (x + num / x) >> 1;
    }
    cout<<x<<endl;
    return x * x == num;
}

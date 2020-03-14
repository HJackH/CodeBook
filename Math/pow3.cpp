long long pow3(long long a,long long b)
{
    long long ans = 1, base = a;
    while (b != 0) {
        if(b & 1) {
            ans *= base;
        }
        base *= base;
        b >>=1;
    }
    return ans;
}
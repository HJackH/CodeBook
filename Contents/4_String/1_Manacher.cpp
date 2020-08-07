int p[2 * MAXN];
int Manacher(const string &str) {
    string tmp = "@#";
    for (char c : str) {
        tmp += c;
        tmp += '#';
    }
    tmp += '$';
    int id = 0, mx = 0, ans = 0;
    for (int i = 1; i < tmp.length() - 1; i++) {
        p[i] = (mx > i ? min(p[2 * id - i], mx - i) : 1);
        for (; tmp[i - p[i]] == tmp[i + p[i]]; p[i]++);
        if (mx < i + p[i]) {
            mx = i + p[i];
            id = i;
        }
        ans = max(ans, p[i] - 1);
    }
    return ans;
}
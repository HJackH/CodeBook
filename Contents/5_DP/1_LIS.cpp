int LIS(vector<int> &arr) {
    vector<int> ans;
    for (int i = 0; i < arr.size(); i++) {
        if (ans.empty() || ans.back() < a[i]) {
            ans.push_back(arr[i]);
        } else {
            *lower_bound(ans.begin(), ans.end(), a[i], 
                [](int x, int y){return x < y;}) = a[i];
        }
    }
    return ans.size();
}
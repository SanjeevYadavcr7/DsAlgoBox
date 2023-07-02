#include<iostream>
using namespace std;

int distribute(int curr, vector<int>& cookies, vector<int> child, int zeroCount) {
    if(cookies.size() - curr < zeroCount) return INT_MAX;

    if(curr == cookies.size()) {
        return *max_element(child.begin(), child.end());
    }

    int res = INT_MAX;
    for(int j=0; j<child.size(); j++) {
        zeroCount -= child[j] == 0 ? 1 : 0;
        child[j] += cookies[curr];
        int temp = distribute(curr+1, cookies, child, zeroCount);
        res = min(res, temp);
        child[j] -= cookies[curr];
        zeroCount += child[j] == 0 ? 1 : 0;
    }
    return res;
}

int distributeCookies(vector<int>& cookies, int k) {
    vector<int> child(k);
    return distribute(0, cookies, child, k);
}

int main() {
    int n, k;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];
    cin >> k;
    
    int res = distributeCookies(arr, k);
    cout << res;

    return 0;
}
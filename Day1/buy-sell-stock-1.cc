#include<iostream>
using namespace std;

int maxProfit(vector<int>& prices) {
    int n = prices.size() - 1;
    int max_price = prices[n];
    int max_profit = 0;
    for(int i=n; i>=0; i--) {
        max_price = max(prices[i], max_price);
        max_profit = max(max_price-prices[i], max_profit);
    }
    return max_profit;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];

    int max_profit = maxProfit(arr);
    cout << max_profit;

    return 0;
}
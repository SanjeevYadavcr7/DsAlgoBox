#include<iostream>
using namespace std;

int maxProfit(vector<int>& prices) {
    int n = prices.size() - 1;
    int max_profit = 0;
    int max_price = prices[n];
    for(int i=n; i>=0; i--) {
        max_price = max(max_price, prices[i]);
        max_profit = max(max_profit, max_price - prices[i]);
    }

    return max_profit;
}

int main() {    
    int n;
    cin >> n;
    vector<int> prices(n);
    for(int i=0; i<n; i++) cin >> prices[i];

    int profit = maxProfit(prices);
    cout << profit << endl;

    return 0;
}
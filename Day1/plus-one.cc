#include<iostream>
using namespace std;

vector<int> plusOne(vector<int>& digits) {
    int n = digits.size() - 1;
    if(digits[n] != 9) {
        digits[n] += 1;
        return digits;
    }

    vector<int> ans;
    int c = 0;
    for(int i=n; i>=0; i--) {
        if(digits[i] == 9) {
            c = 1;
            digits[i] = 0;
        }
        else {
            digits[i] += 1;
            c = 0;
            break;
        } 
    }
    if(c == 1) ans.push_back(1);
    for(int &i : digits) ans.push_back(i);
    return ans;   
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];

    vector<int> res = plusOne(arr);
    for(int &i: res) cout << i << " ";

    return 0;
}
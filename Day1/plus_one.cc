#include<iostream>
using namespace std;

vector<int> plusOne(vector<int>& digits) {
    int n = digits.size();
    int carry = 1;
    vector<int> res;

    if(digits[n-1] != 9) {
        digits[n-1] += 1;
        return digits;
    }
    else {
        int i = n-1;
        while(i >= 0) {
            if(digits[i] == 9 && carry) {
                res.push_back(0);
                carry = 1;
            }
            else {
                res.push_back(digits[i]+carry);
                carry = 0;
            }
            i--;
        }
    }

    if(carry) res.push_back(1);
    n = res.size();
    for(int i=0; i<n/2; i++) {
        int tmp = res[i];
        res[i] = res[n-i-1];
        res[n-i-1] = tmp;
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];

    cout << "[Num] = ";
    for(int &i : arr) cout << i << " ";
    cout << endl;
    arr = plusOne(arr);
    cout << "[Num+1] = ";
    for(int &i : arr) cout << i << " ";
    cout << endl;

    return 0;
}
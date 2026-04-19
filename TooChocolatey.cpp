#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
string solve(int n, vector<int> arr) {
    sort(arr.rbegin(), arr.rend());
    int alex = 0, bob = 0;
    set<int> A, B;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) { 
            if (A.count(arr[i]) == 0) {
                alex += arr[i];
                A.insert(arr[i]); }
        } 
        else { 
            if (B.count(arr[i]) == 0) {
                bob += arr[i];
                B.insert(arr[i]);}
        }
    }
    return (alex > bob) ? "Alex" : "Bob";
}
int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i]; }
        cout << solve(n, arr) << "\n";}
    return 0;
}
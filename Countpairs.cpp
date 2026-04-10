#include <iostream>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int count = 0;
        if (n % 2 == 0) {
            count++;
            while (n % 2 == 0) {
                n = n / 2; }
        }
        for (int i = 3; i * i <= n; i += 2) {
            if (n % i == 0) {
                count++;
                while (n % i == 0) {
                    n = n / i;}
            }
        }
        if (n > 1) {
            count++; }
        int result = 1;
        for (int i = 0; i < count; i++) {
            result = result * 2;
        }
        cout << result << '\n';  }
    return 0;
}
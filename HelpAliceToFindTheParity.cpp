#include <iostream>
using namespace std;

long long f(long long n) {
    if (n % 4 == 0) return n;
    if (n % 4 == 1) return 1;
    if (n % 4 == 2) return n + 1;
    return 0;
}

int main() {
    long long L, R;
    cin >> L >> R;

    long long x = f(R) ^ f(L - 1);

    cout << (x % 2 == 0 ? "even" : "odd");
}
#include <bits/stdc++.h>
using namespace std;
class Bank {
public:
//userId -> balance
    map<int, int> accounts;
//create X Y
    bool create(int userId, int amount) {
//if user exists, add amount
        if (accounts.count(userId)) {
            accounts[userId] += amount;
            return false; }
//new account
        accounts[userId] = amount;
        return true; }
//debit X Y
    bool debit(int userId, int amount) {
//user not present OR insufficient balance
        if (!accounts.count(userId) || accounts[userId] < amount)
            return false;
        accounts[userId] -= amount;
        return true;}
//credit X Y
    bool credit(int userId, int amount) {
//user not present
        if (!accounts.count(userId))
            return false;
        accounts[userId] += amount;
        return true; }
//balance X
    int balance(int userId) {
        if (!accounts.count(userId))
            return -1;
        return accounts[userId]; }
};
int main() {
    Bank bank;
    int Q;
    cin >> Q;
    while (Q--) {
        string query;
        cin >> query;
        if (query == "CREATE") {
            int x, y;
            cin >> x >> y;
            cout << (bank.create(x, y) ? "true" : "false") << endl;}
        else if (query == "DEBIT") {
            int x, y;
            cin >> x >> y;
            cout << (bank.debit(x, y) ? "true" : "false") << endl;}
        else if (query == "CREDIT") {
            int x, y;
            cin >> x >> y;
            cout << (bank.credit(x, y) ? "true" : "false") << endl;}
        else if (query == "BALANCE") {
            int x;
            cin >> x;
            cout << bank.balance(x) << endl;}
    }
    return 0;
}
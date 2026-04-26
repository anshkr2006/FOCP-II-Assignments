#include <bits/stdc++.h>
using namespace std;
class MovieTicket {
public:
    map<int, set<int>> bookings;
    bool book(int userId, int movieId) {  // book X Y
//already booked
        if (bookings[movieId].count(userId))
            return false;
 //check if full
        if (bookings[movieId].size() >= 100)
            return false;
        bookings[movieId].insert(userId);
        return true; }
// cancel x y
    bool cancel(int userId, int movieId) {
// not booked
        if (!bookings[movieId].count(userId))
            return false;
        bookings[movieId].erase(userId);
        return true; }
//is_booked X Y
    bool isBooked(int userId, int movieId) {
        return bookings[movieId].count(userId); }

//avail_tickets Y
    int availableTickets(int movieId) {
        return 100 - bookings[movieId].size(); }
};
int main() {
    MovieTicket mt;
    int Q;
    cin >> Q;
    while (Q--) {
        string query;
        cin >> query;
        if (query == "BOOK") {
            int x, y;
            cin >> x >> y;
            cout << (mt.book(x, y) ? "true" : "false") << endl;}
        else if (query == "CANCEL") {
            int x, y;
            cin >> x >> y;
            cout << (mt.cancel(x, y) ? "true" : "false") << endl; }
        else if (query == "IS_BOOKED") {
            int x, y;
            cin >> x >> y;
            cout << (mt.isBooked(x, y) ? "true" : "false") << endl;}
        else if (query == "AVAILABLE_TICKETS") {
            int y;
            cin >> y;
            cout << mt.availableTickets(y) << endl;}
    }
    return 0;
}
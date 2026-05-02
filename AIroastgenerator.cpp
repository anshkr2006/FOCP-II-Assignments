#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

// Function to replace {name} with actual user name
string replaceName(string roast, string name) {
    size_t pos = roast.find("{name}");
    
    if (pos != string::npos) {
        roast.replace(pos, 6, name);
    }
    
    return roast;
}

int main() {

    // Seed random number generator using current time
    srand(time(0));

    string name;

    cout << "Enter your name: ";
    getline(cin, name);

    if (name.empty()) {
        name = "Mystery Person";
    }

    vector<string> roasts = {
        "{name}, you're not useless... you could be used as a bad example.",
        "{name}, if laziness were a sport, you'd come second... because you'd be too lazy to come first.",
        "{name}, your brain has more buffering than a slow YouTube video.",
        "{name}, you're like a cloud... when you disappear, it's a beautiful day.",
        "{name}, I'd explain it to you, but I left my crayons at home.",
        "{name}, you bring everyone so much joy... when you leave the room.",
        "{name}, you're proof that even Google doesn't have all the answers.",
        "{name}, you have something on your chin... no, the third one down.",
        "{name}, you're like a software update - nobody likes you when you show up.",
        "{name}, your secrets are always safe with me... I never even listen!"
    };

    int randomIndex = rand() % roasts.size();
    string selectedRoast = roasts[randomIndex];

    string finalRoast = replaceName(selectedRoast, name);

    cout << "\nHere's your roast:\n";
    cout << finalRoast << endl;

    return 0;
}
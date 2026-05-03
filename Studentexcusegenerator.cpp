#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

// Replace {name}
string replaceName(string excuse, string name) {
    size_t pos = excuse.find("{name}");
    if (pos != string::npos) {
        excuse.replace(pos, 6, name);
    }
    return excuse;
}

// Generate random excuse
string generateExcuse(string name) {
    vector<string> excuses = {
        "{name} forgot the homework because a monkey stole the notebook.",
        "{name} was busy saving the world from aliens last night.",
        "{name}'s dog ate not only the homework but also the pen.",
        "{name} accidentally submitted the homework to another dimension.",
        "{name} was practicing magic and the homework disappeared.",
        "{name}'s internet turned into a potato and stopped working.",
        "{name} had to help grandma fight a ninja invasion.",
        "{name} thought today was Sunday… turns out it wasn’t.",
        "{name} got stuck in a time loop and couldn’t finish it.",
        "{name}'s brain needed a software update overnight."
    };

    int randomIndex = rand() % excuses.size();
    return replaceName(excuses[randomIndex], name);
}

int main() {
    srand(time(0));

    string name;
    int dummy;

    cout << "=== Student Excuse Generator ===" << endl;

    cout << "Enter any number: ";
    cin >> dummy;

    cin.ignore(); // 🔥 Clears leftover newline from input buffer

    cout << "Enter your name: ";
    getline(cin, name);

    string finalExcuse = generateExcuse(name);

    cout << "\nYour Excuse:\n";
    cout << finalExcuse << endl;

    return 0;
}
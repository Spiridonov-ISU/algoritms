#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <cmath>

using namespace std;

int ascii_hash(string line) {
    unsigned int hash = 0;
    for (int i = 0; i < line.length(); i++) {
        hash += (unsigned int)line[i];
    }
    return hash;
}

int polynom_hash(string line) {
    unsigned int hash = 0;
    for (int i = 0; i < line.length(); i++) {
        hash += (unsigned int)pow(line.at(i), (i + 1));
    }
    return hash;
}

int main() {
    unsigned int total_hashes = 0;
    set<int> ascii_unique_hashes;
    set<int> polynom_unique_hashes;

    ifstream file("endict.txt");
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            total_hashes++;
            ascii_unique_hashes.insert(ascii_hash(line));
            polynom_unique_hashes.insert(polynom_hash(line));
        }
    }
    file.close();

    cout << "ascii_collisions = " << total_hashes - ascii_unique_hashes.size() << endl;
    cout << "polynom_collisions = " << total_hashes - polynom_unique_hashes.size() << endl;
    return 0;
}
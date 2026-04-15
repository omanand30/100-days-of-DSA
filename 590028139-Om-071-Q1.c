#include <iostream>
#include <vector>
using namespace std;

class HashTable {
    int m;
    vector<int> table;

public:
    HashTable(int size) {
        m = size;
        table.resize(m, -1);
    }

    int hashFunc(int key) {
        return key % m;
    }

    void insert(int key) {
        int h = hashFunc(key);

        for (int i = 0; i < m; i++) {
            int index = (h + i * i) % m;

            if (table[index] == -1) {
                table[index] = key;
                return;
            }
        }

        cout << "Hash Table Full\n";
    }

    bool search(int key) {
        int h = hashFunc(key);

        for (int i = 0; i < m; i++) {
            int index = (h + i * i) % m;

            if (table[index] == -1) {
                return false; // not found
            }

            if (table[index] == key) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    int m, q;
    cin >> m >> q;

    HashTable ht(m);

    while (q--) {
        string op;
        int key;
        cin >> op >> key;

        if (op == "INSERT") {
            ht.insert(key);
        } else if (op == "SEARCH") {
            if (ht.search(key))
                cout << "FOUND\n";
            else
                cout << "NOT FOUND\n";
        }
    }

    return 0;
}
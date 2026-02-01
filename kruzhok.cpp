#include <iostream>
#include <string>
using namespace std;

const int max_size = 1000;
struct Person {
    int number;
    string name;
    string address;
    string date;
};

Person inputPerson(int number) {
    Person p;
    p.number = number;
    cout << "Enter full name: ";
    getline(cin, p.name);
    cout << "Enter address: ";
    getline(cin, p.address);
    cout << "Enter registration date: ";
    getline(cin, p.date);
    return p;
}

void show(Person a[], int n) {
    if (n == 0) {cout << "No records.\n"; return;}
    for (int i = 0; i < n; i++) {
        cout << a[i].number << " | " << a[i].name << " | " << a[i].address << " | " << a[i].date << endl;
    }
}

void add(Person a[], int &n) {
    cout << "\nAdding a new record:\n";
    a[n] = inputPerson(n + 1);
    n++;
}

void removeDuplicates(Person a[], int &n){
    for (int i = 0; i < n; i++){
        for (int j = i + 1; j < n; ) {
            if ((a[i].name == a[j].name) && (a[i].address == a[j].address)){
                for (int k = j; k < n - 1; k++)
                    a[k] = a[k + 1];
                n--;
            }
            else j++;
        }
    }
    cout << "Duplicates removed." << endl;
}

void linearSearch(Person a[], int n){
    cout << "Enter full name to search: ";
    string key;
    getline(cin, key);
    bool found = false;
    for (int i = 0; i < n; i++){
        if (a[i].name == key){
            cout << a[i].number << " | " << a[i].name << " | " << a[i].address << " | " << a[i].date << endl;
            found = true;
        }
    }
    if (!found)
        cout << "Record not found.\n";
}

int main() {
    Person a[max_size];
    int n = 0;
    while (true){
        cout << "1. Add record" << endl;
        cout << "2. Show all records" << endl;
        cout << "3. Remove duplicates (name + address)" << endl;
        cout << "4. Linear search by name" << endl;
        cout << "0. Exit" << endl; 
        cout << "Enter your choice: ";
        int c;
        cin >> c;
        cin.ignore();
        if (c == 0) break;
        switch (c){
            case 1: add(a, n); break;
            case 2: show(a, n); break;
            case 3: removeDuplicates(a, n); break;
            case 4: linearSearch(a, n); break;
        }
    }
    return 0;
}

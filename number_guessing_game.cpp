#include <iostream>
#include <random>
using namespace std;

void menu();
int randomNumber();
void game(int chance, bool &sv_var);

int main()
{
    menu();
    return 0;
}

void menu() {
    int choice;
    bool sv_var = true;
    cout << "Welcome to the Number Guessing Game!" << '\n' << "I'm thinking of a number between 1 and 100." << '\n';
    while(sv_var) {
        cout << "Please select the difficulty level: " << '\n';
        cout << "1. Easy (10 chances)" << '\n' << "2. Medium (5 chances)" << '\n' << "3. Hard (3 chances)" << '\n' << "4. Exit" << '\n'; 
        cout << "Enter your choice: ";
        cin >> choice;
        switch(choice) {
            case 1:
                cout << "Great! You have selected the Easy difficulty level." << '\n';
                game(10, sv_var);
                break;
            case 2: 
                cout << "Great! You have selected the Medium difficulty level." << '\n';
                game(5, sv_var);
                break;
            case 3: 
                cout << "Great! You have selected the Hard difficulty level." << '\n';
                game(3, sv_var);
                break;
            case 4: 
                cout << "Exiting the program." << '\n';
                sv_var = false;
                break;
            default:
                cout << "There is no such choice!" << '\n'; 
                break;
        }
    }
}

int randomNumber() {
    random_device rd;
    mt19937 gen(rd());  
    uniform_int_distribution<> dist(1,100); 
    return dist(gen);
}

void game(int chance, bool &sv_var) {
    char yesno;
    int num_user;
    int cnt = 1;
    int num_program = randomNumber();
    while(chance) {
        cin >> num_user;
        if (num_user < num_program) {
            chance--;
            ++cnt;
            cout << "Your number is less than it is! Chances remaining: " << chance << '\n';
        }
        else if (num_user > num_program) {
            chance--;
            ++cnt;
            cout << "Your number is greater than it is! Chances remaining: " << chance << '\n';
        }
        else {
            if(cnt == 1) {
                cout << "Correct! You've guessed the number in " << cnt << " attempt." << '\n';
            }
            else if(cnt > 1) {
                cout << "Correct! You've guessed the number in " << cnt << " attempts." << '\n';
            }
            return;
        }
    }
    cout << "You have failed to guess the number. Better luck next time!" << '\n';
    cout << "Would you like to return to menu? (Y/N)" << '\n';
    cin >> yesno;
    if((yesno == 'Y') || (yesno == 'y')) {
        sv_var = true;
        return;
    }
    else if ((yesno == 'N') || (yesno == 'n')) {
        sv_var = false;
        return;
    }
}
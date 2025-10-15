#include <iostream>
#include <string>
using namespace std;


double total;
char choice;
int numch;
string CupS;
string dairy;
string sweetener;

void final(){
    cout << "Your " << CupS << " coffee with " << dairy << " and " << sweetener << " will be: " << total << endl;
}; 

void line(){
    cout << "------------------------------------" << endl;
};

int main(){
line();
    cout << "What size would you like your coffee?" << endl;
    cout << " 'A': Small \n 'B': Medium \n 'C': Large" << endl;
    cin >> choice; 
line();

switch (choice) {
    case 'A':
    case 'a': 
        CupS = "small";
        total += 2.15;
             break; 
    case 'B':
    case 'b':
        CupS = "medium";
        total += 2.66;
        break;
    case 'C':
    case 'c':
        CupS = "large";
        total += 3.62;
        break;
    default:
        cout << "Please make a Valid Choice of 'A' , 'B' , or 'C'." << endl;
        break;
    }

    do {
        cout << "What customization would you like to add?" << endl;
        cout << "0: Finish Order \n1: Diary \n2: Sweetner" << endl;
        cin >> numch;
        switch (numch){
             case 0: 
                cout << " Finishing order...\n";
                break;
            case 1:
                cout << "Which type of dairy would you like to add?\n";
                cin >> dairy;
                break;
            case 2:
                cout << "Which type of sweetener would you like to add?\n";
                cin >> sweetener;
                break;
            default:
                cout << "Invalid option \nSelect a valid option.\n";    
                break;
        }


    } while ( numch != 0);

    line();
    final();
    line();

    return 0;
}

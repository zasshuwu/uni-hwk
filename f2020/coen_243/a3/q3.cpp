#include <iostream>
#include <array>
#include <iomanip>
#include <vector>

using namespace std;

// Opted for functon return value instead of referencing address
// Because that is a major pain

// -------------------------------- global var initialization --------------------------------

array<int, 10> main_arr;
int cur_pos = 0; // store current position, init to 0
int choice;
int size = main_arr.size();
vector<int> hist = {};
int steps;

// -------------------------------- function definitions --------------------------------

// Helper function --------------------------------

array<int, 10> setAlltoZeros(array<int, 10> main_arr, int size) {
    array<int, 10> loc_arr = main_arr;
    for (size_t i = 0; i < size; ++i) {
        loc_arr[i] = 0;
    }
    return loc_arr;
}

//  Display and visual representations --------------------------------

void showArray(array<int, 10> main_arr, int size) {
    cout << "Array: ";
    for (size_t i = 0; i < size; i++) {
        cout << setw(2) << main_arr[i] << setw(2);
    }
    cout << endl;
}

void displayGrid(array<int, 10> main_arr, int size) {
    cout << "|";
    for (size_t i = 0; i < size; ++i) {
        if (main_arr[i] == 0) {
            cout << setw(2) << " " << setw(2) << "|";
        } else {
            cout << setw(2) << "^" << setw(2) << "|";
        }
    }
    cout << endl;
    cout << "|";
    for (size_t i = 0; i < size; ++i) {
            cout << setw(2) << i << setw(2) << "|";
    }
    cout << endl;
}

// History: cancel and replay --------------------------------

array<int, 10> replayOps(int old_pos, int size) {
    array<int, 10> loc_arr;
    loc_arr = setAlltoZeros(loc_arr, size);
    cout << "Old pos: " << old_pos << endl;
    
    cout << endl;
    loc_arr[old_pos] = 1;
    for (int i : loc_arr) {
        cout << i << " ";
    }
    return loc_arr;
}

array<int, 10> cancelOps(vector<int> hist, int size, int steps, int *cur_pos) {
    array<int, 10> loc_arr;
    int old_pos = *cur_pos; // save cur_pos for replay

    loc_arr = setAlltoZeros(loc_arr, size);

    cout << "hist index: " << hist[hist.size() - steps];
    *cur_pos = hist[hist.size() - steps];
    
    loc_arr[hist[hist.size() - steps]] = 1;
    
    // replay or not
    char replay_choice;
    cout << "\nReplay canncelled ops? (y)es/(n)o: ";
    cin >> replay_choice;
    if (replay_choice == 'y') {
        loc_arr = replayOps(old_pos, size);
        return loc_arr;
    } else {
        return loc_arr;
    }
}


// Movement

array<int, 10> moveRight(array<int, 10> main_arr, int size, int *cur_pos) {
    int steps;
    int new_pos;
    array<int, 10> loc_arr = main_arr;

    cout << "Move right for (steps): ";
    cin >> steps;
    new_pos = *cur_pos + steps;
    cout << endl;

    if (new_pos > 10) {
        *cur_pos = 10;
        loc_arr[size - 1] = 1;
        displayGrid(loc_arr, size);
        return loc_arr;
    } else {
        *cur_pos = new_pos;
        loc_arr[new_pos] = 1;
        displayGrid(loc_arr, size);
        return loc_arr;
    }
}

array<int, 10> moveLeft(array<int, 10> main_arr, int size, int *cur_pos) {
    int steps;
    int new_pos;
    array<int, 10> loc_arr = main_arr;

    cout << "Move right for (steps): ";
    cin >> steps;
    new_pos = *cur_pos - steps;
    cout << endl;

    if (new_pos < 0) {
        *cur_pos = 0;
        loc_arr[0] = 1;
        displayGrid(loc_arr, size);
        return loc_arr;
    } else {
        *cur_pos = new_pos;
        loc_arr[new_pos] = 1;
        displayGrid(loc_arr, size);
        return loc_arr;
    }

}

array<int, 10> rebootPos(array<int, 10> main_arr, int size) {
    array<int, 10> loc_arr = main_arr; // init a local var to store the main_var
    for (size_t i = 0; i < size; i++) {
        loc_arr[i] = 0;
    }
    loc_arr[0] = 1;
    cout << "Position reset to 0..." << endl;
    displayGrid(loc_arr, size);
    return loc_arr; // then return the processed local var
}

// -------------------------------- menu --------------------------------

void menu(int choice) {
    switch(choice) {
        case 1:
            cout << "\nOut-of-bounds movements will move the bot to last grid" << endl;
            main_arr = setAlltoZeros(main_arr, size);
            main_arr = moveRight(main_arr, size, &cur_pos);
            break;
        case 2:
            cout << "\nOut-of-bounds movements will move the bot to first grid" << endl; 
            main_arr = setAlltoZeros(main_arr, size);
            main_arr = moveLeft(main_arr, size, &cur_pos);
            break;
        case 3:
            displayGrid(main_arr, size);
            break;
        case 4:
            main_arr = rebootPos(main_arr, size);
            break;
        case 5:
            showArray(main_arr, size);
            break;
        case 6:
            cout << "Cancel last n ops. Enter n: ";
            cin >> steps;
            main_arr = cancelOps(hist, size, steps, &cur_pos);
            break;
        case 7:
            cout << "Program will now exit..." << endl << endl;
            exit(0);
            break;

    }   
}

// main driver function

int main() {

    // Welcome message:
    cout << "Welcome to that program to control your object's position in a 2D space" << endl;
    cout << "Hoang Anh (C) 2020. COEN 243 - Concordia U. Montreal, Canada." << endl;
    cout << string(50, '-') << endl;
    
    // init object at index 0
    main_arr[0] = 1;
    
    // display init grid and array
    displayGrid(main_arr, size);
    showArray(main_arr, size);
    cout << string(50, '-') << endl;
    
    // Action menu loop
    do {
        // Record obj's cur_pos for history actions
        if (choice <= 2 || choice == 6) {
            hist.push_back(cur_pos);
        }

        // Show position log of obj
        cout << "\nLog: ";
        for (int i : hist) {
            cout << i << " ";
        }

        // Print menu
        cout << "\nController menu:" << endl
            << "1. Right" << endl
            << "2. Left" << endl
            << "3. Display grid" << endl
            << "4. Reboot" << endl
            << "5. Show array" << endl
            << "6. Cancel and Replay operations" << endl
            << "7. Exit" << endl;
        cout << "Enter option: ";
        cin >> choice;
        cout << endl;
        menu(choice);
    } while (choice != 7);

    return 0;
}
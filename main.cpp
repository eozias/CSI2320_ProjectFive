#include<iostream>
#include "CityClock.h"

using namespace std;

int main() {
//    int h, m, s, input, format;
//    string location;
//    bool clockFormat;

    cout << "Create a CityClock object using the default constructor" << endl;
    CityClock clock1;
    clock1.show();
    cout << "The time in 12 hour format is: " << endl;
    clock1.toggleFormat();
    clock1.show();
    cout << "Using the tick function..." << endl;
    clock1.tick();
    clock1.show();

    cout << "Create a CityClock object using the three-argument constructor" << endl;
    CityClock clock2(10, 07, 57, "Troy, Michigan");
    cout << "The time in 24 hour format is: " << endl;
    clock2.show();
    cout << "The time in 12 hour format is: " << endl;
    clock2.toggleFormat();
    clock2.show();
    cout << "Using the tick function..." << endl;
    clock2.tick();
    clock2.show();

    cout << "Create a copy of clock2 using the copy constructor" << endl;
    CityClock clock3(clock2);
    clock3.show();

    cout << "Create a new CityClock object using the move constructor" << endl;
    CityClock clock4(move(clock3));
    clock4.show();

    cout << "Assign clock2 to clock1 using the copy assignment operator" << endl;
    clock1 = clock2;
    clock1.show();

    cout << "Assign clock4 to clock2 using the move assignment operator" << endl;
    clock2 = move(clock4);
    clock2.show();

    cout << "Convert clock1 to a string using the type conversion function" << endl;
    string clock1Str = clock1;
    cout << clock1Str << endl;

    cout << "Add one hour to clock1 using the overloaded addition operator" << endl;
    CityClock clock5 = clock1 + 3600;
    clock5.show();

    cout << "Print clock5 using the overloaded ostream insertion operator" << endl;
    cout << clock5 << endl;

//    do {
//        cout << "Create your own clock: " << endl;
//        cout << "Enter 1 if you would like the format to be 24-hour, or enter 0 for 12-hour: ";
//        cin >> format;
//        while (format != 0 && format != 1) {
//            cout << "Invalid input. Please enter 1 or 0: ";
//            cin >> format;
//        }
//        cout << "Enter the hour: ";
//        cin >> h;
//        cout << "Enter the minutes: ";
//        cin >> m;
//        cout << "Enter the seconds: ";
//        cin >> s;
//        cout << "Enter the location of the clock: ";
//        cin >> location;
//        if (format == 1) {
//            clockFormat = true;
//        } else {
//            clockFormat = false;
//        }
//        CityClock five(h, m, s, clockFormat, location.c_str());
//        five.show();
//        cout << "Enter 1 if you would like to make another clock, or enter 0 to exit: ";
//        cin >> input;
//        while (input != 0 && input != 1) {
//            cout << "Invalid input. Please enter 1 or 0: ";
//            cin >> input;
//        }
//        cout << endl;
//    } while (input == 1);

    return 0;
}
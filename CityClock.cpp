#include "CityClock.h"
#include <iostream>
#include <iomanip>
#include <sstream>

using namespace std;

CityClock::CityClock() {
    hour = 0;
    minute = 0;
    second = 0;
    is24HourFormat = true;
    isPM = false;
    cityName = new char[strlen("Rochester, Michigan") + 1];
    strcpy(cityName, "Rochester, Michigan");
}

CityClock::CityClock(int h, int m, int s, const char *name) {
    is24HourFormat = true;
    isPM = false;
    cityName = new char[strlen(name) + 1];
    strcpy(cityName, name);
    if (h >= 0 && h <= 23 && m >= 0 && m <= 59 && s >= 0 && s <= 59) {
        hour = h;
        minute = m;
        second = s;
    } else {
        cout << "Invalid input. Setting time to 00:00:00" << endl;
        hour = 0;
        minute = 0;
        second = 0;
    }
}

CityClock::CityClock(int h, int m, int s, bool format, const char *name) {
    is24HourFormat = format;
    int input;
    cityName = new char[strlen(name) + 1];
    strcpy(cityName, name);
    if (is24HourFormat == true && h >= 0 && h <= 23 && m >= 0 && m <= 59 && s >= 0 && s <= 59) {
        hour = h;
        minute = m;
        second = s;
    } else if (is24HourFormat == false && h >= 1 && h <= 12 && m >= 0 && m <= 59 && s >= 0 && s <= 59) {
        cout << "Enter 1 if you would like the time to be PM, or enter 0 for AM: ";
        cin >> input;
        if (input == 1) {
            isPM = true;
        } else {
            isPM = false;
        }
        hour = h;
        minute = m;
        second = s;
    } else {
        cout << "Invalid input. Setting time to 00:00:00" << endl;
        hour = 0;
        minute = 0;
        second = 0;
    }
}

void CityClock::toggleFormat() {
    if (is24HourFormat == true) {
        // Switch to 12-hour format
        is24HourFormat = false;
        if (hour > 12) {
            hour -= 12;
            isPM = true;
        } else if (hour == 12) {
            isPM = true;
        } else if (hour == 0) {
            hour = 12;
            isPM = false;
        } else {
            isPM = false;
        }
    } else {
        // Switch to 24-hour format
        is24HourFormat = true;
        if (hour == 12 && isPM == false) {
            hour = 0;
        } else if (hour == 12 && isPM == true) {
            hour = 12;
        } else if (isPM == true) {
            hour += 12;
        }
    }
}

void CityClock::tick() {
    second++;
    if (second == 60) {
        second = 0;
        minute++;
        if (minute == 60) {
            minute = 0;
            hour++;
            if (hour == 24) {
                hour = 0;
            }
        }
    }
}

void CityClock::show() {
    cout << cityName << " - ";
    if (is24HourFormat == true) {
        cout << setw(2) << setfill('0') << hour << ":"
             << setw(2) << setfill('0') << minute << ":"
             << setw(2) << setfill('0') << second << endl;
    } else {
        cout << setw(2) << setfill('0') << hour << ":"
             << setw(2) << setfill('0') << minute << ":"
             << setw(2) << setfill('0') << second
             << (isPM ? " PM" : " AM") << endl;
    }
}

CityClock::~CityClock() {
    delete[] cityName;
}

CityClock::CityClock(const CityClock &original) {
    hour = original.hour;
    minute = original.minute;
    second = original.second;
    is24HourFormat = original.is24HourFormat;
    isPM = original.isPM;
    cityName = new char[strlen(original.cityName) + 1];
    strcpy(cityName, original.cityName);
}

CityClock::CityClock(CityClock &&original) {
    hour = original.hour;
    minute = original.minute;
    second = original.second;
    is24HourFormat = original.is24HourFormat;
    isPM = original.isPM;
    cityName = original.cityName;
    // Nullify the original object's pointer
    original.cityName = nullptr;
}

CityClock &CityClock::operator=(const CityClock &original) {
    if (this != &original) {
        delete[] cityName;
        // Copy from original
        hour = original.hour;
        minute = original.minute;
        second = original.second;
        is24HourFormat = original.is24HourFormat;
        isPM = original.isPM;
        cityName = new char[strlen(original.cityName) + 1];
        strcpy(cityName, original.cityName);
    }
    return *this;
}

CityClock &CityClock::operator=(CityClock &&original) {
    if (this != &original) {
        delete[] cityName;
        // Move from original
        hour = original.hour;
        minute = original.minute;
        second = original.second;
        is24HourFormat = original.is24HourFormat;
        isPM = original.isPM;
        cityName = original.cityName;
        // Nullify the original object's pointer
        original.cityName = nullptr;
    }
    return *this;
}

CityClock::operator string() const {
    stringstream time;
    if (is24HourFormat) {
        time << setw(2) << setfill('0') << hour << ":" << setw(2) << setfill('0') << minute << ":" << setw(2)
             << setfill('0') << second;
    } else {
        time << setw(2) << setfill('0') << hour << ":" << setw(2) << setfill('0') << minute << ":" << setw(2)
             << setfill('0') << second;
        if (isPM) {
            time << " PM";
        } else {
            time << " AM";
        }
    }
    return string(cityName) + " - " + time.str();
}

CityClock CityClock::operator+(int sec) const {
    CityClock clock(*this);
    clock.second += sec;

    while (clock.second >= 60) {
        clock.second -= 60;
        clock.minute++;
    }

    while (clock.minute >= 60) {
        clock.minute -= 60;
        clock.hour++;
    }

    while (clock.hour >= 24) {
        clock.hour -= 24;
    }

    return clock;
}

ostream &operator<<(ostream &os, const CityClock &clock) {
    os << clock.cityName << " - ";
    if (clock.is24HourFormat) {
        os << setw(2) << setfill('0') << clock.hour << ":" << setw(2) << setfill('0') << clock.minute << ":" << setw(2)
           << setfill('0') << clock.second;
    } else {
        os << setw(2) << setfill('0') << clock.hour << ":" << setw(2) << setfill('0') << clock.minute << ":" << setw(2)
           << setfill('0') << clock.second;
        if (clock.isPM) {
            os << " PM";
        } else {
            os << " AM";
        }
    }
    return os;
}
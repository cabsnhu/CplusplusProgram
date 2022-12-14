/*Cindy Burnett
CS-210
Project One*/

#include<iostream>
#include<ctime>
#include<cstdlib>
#include<string>

using namespace std;

string twoDigitString(unsigned int n) { //format all numbers into two digits
    string newNumber;
    if ((n > 9) && (n < 60)) {
        newNumber = to_string(n);
    }
    else if (n < 10) {
        newNumber = to_string(n);
        newNumber = "0" + newNumber; //0 as leading number for single digit
    }
    return newNumber;
}

string nCharString(size_t n, char c) { //gets a string of chosen characters based on chosen width
    string charString;
    for (int i = 0; i < n; i++) {
        charString = charString + c;
    }
    return charString;
}

string formatTime24(unsigned int h, unsigned int m, unsigned int s) {
    // return time as hh:mm:ss for 24 hour clock format
    string time;
    time = twoDigitString(h) + ":" + twoDigitString(m) + ":" + twoDigitString(s);
    return time;
}

string formatTime12(unsigned int h, unsigned int m, unsigned int s) {
    // return hh:mm:ss A M or hh:mm:ss P M for 12 hour clock format
    string time;
    string amORpm;
    // conditions for am or pm
    if ((h > 12) && (s > 0)) {
        h = h - 12;
        amORpm = " P M";
    }
    else if ((h == 0) && (s > 0)) {
        h = 12;
        amORpm = " A M";
    }
    else if (h == 12) {
        amORpm = " P M";
    }
    else {
        amORpm = " A M";
    }
    time = twoDigitString(h) + ":" + twoDigitString(m) + ":" + twoDigitString(s) + amORpm; //calls 2 digit number format
    return time;
}

void printMenu() { //option menu to display
    cout << nCharString(23, ' ') << nCharString(26, '*') << endl;
    cout << nCharString(23, ' ') << "* 1 - Add One Hour" << nCharString(7, ' ') << "*" << endl;
    cout << nCharString(23, ' ') << "* 2 - Add One Minute" << nCharString(5, ' ') << "*" << endl;
    cout << nCharString(23, ' ') << "* 3 - Add One Second" << nCharString(5, ' ') << "*" << endl;
    cout << nCharString(23, ' ') << "* 4 - Exit Program" << nCharString(7, ' ') << "*" << endl;
    cout << nCharString(23, ' ') << nCharString(26, '*') << endl;
}

void displayClocks(unsigned int h, unsigned int m, unsigned int s) {
    // to display both clocks simultaneously
    cout << nCharString(5, ' ') << nCharString(27, '*') << nCharString(8, ' ') << nCharString(27, '*') << endl;
    cout << nCharString(5, ' ') << "*" << nCharString(6, ' ') << "12-HOUR CLOCK" << nCharString(6, ' ') << "*" << nCharString(3, ' ');
    cout << nCharString(5, ' ') << "*" << nCharString(6, ' ') << "24-HOUR CLOCK" << nCharString(6, ' ') << "*" << endl;
    cout << endl;
    cout << nCharString(5, ' ') << "*" << nCharString(6, ' ') << formatTime12(h, m, s) << nCharString(7, ' ') << "*" << nCharString(3, ' ');
    cout << nCharString(5, ' ') << "*" << nCharString(8, ' ') << formatTime24(h, m, s) << nCharString(9, ' ') << "*" << endl;
    cout << nCharString(5, ' ') << nCharString(27, '*') << nCharString(8, ' ') << nCharString(27, '*') << endl;
}

int main() {
    int s; //seconds
    int m; //minutes
    int h; //hours

    time_t total_seconds = time(0); //stores total seconds
     // makes current time tm tyoe
    struct tm ct;
    localtime_s(&ct, &total_seconds); 

    s = ct.tm_sec; //seconds
    m = ct.tm_min; //minutes
    h = ct.tm_hour; //hours

    displayClocks(h, m, s); //displays both clocks

    printMenu(); // displays menu options

    int userChoice; //declared variable for menu choice

    userChoice = 0;
    cin >> userChoice; //input for user choice

    while (userChoice > 0) {
        // actions to be taken based on user choice
       if (userChoice == 1) { //add one hour to both clocks
            if ((h >= 0) && (h <= 22)) {
                h = h + 1;
            }
            else if (h == 23) { //restart hours to 1
                h = 1;
            }
        }
        else if (userChoice == 2) { //add one minute to both clocks
            if ((m >= 0) && (m <= 58)) {
                m = m + 1;
            }
            else if (m == 59) { //restart minutes to 0 add 1 hour
                m = 0;
                h = h + 1;
            }
        }
        else if (userChoice == 3) { //add one second to both clocks
            if ((s >= 0) && (s <= 58)) { 
                s = s + 1;
            }
            else if (s == 59) { //restart seconds to 0 add 1 minute
                s = 0;
                m = m + 1;
            }
        }
        else if (userChoice == 4) { //exit program
            break;
        }
        else { //to handle invalid input
            cout << "invalid input. Please try again." << endl; 
        }
        system("CLS"); //clears screen
        displayClocks(h, m, s); // displays both clocks with changes
        printMenu(); // displays menu again
        cin >> userChoice; //takes users next input choice

    }
    return 0;
}

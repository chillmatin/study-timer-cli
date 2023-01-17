#include <iostream>
#include <string>
#include <sstream>
using namespace std;

/*
Wishing you fruitful sessions!

Menu:

1. Set pomodoro time (current time: 25 mins)
2. Set break time    (current time: 5 mins)
3. Advanced

4. start timer

Input:

*/

int pomodoro_time_minutes = 25;
int break_time_minutes = 5;

void printMenu()
{
        cout << "Menu:" << endl;
        cout << "1. Set pomodoro time (current: " << pomodoro_time_minutes << " minutes)" << endl;
        cout << "2. Set break time (current: " << break_time_minutes << " minutes)" << endl;
        cout << "3. Advanced" << endl;
        cout << "4. Start timer" << endl;
        cout << endl;
        cout << "Input: ";
}

void set_pomodoro_time_menu()
{
        bool validInput = false;
        int input = 0;
        while (!validInput)
        {
                cout << "Enter new pomodoro time in minutes: ";
                cin >> input;
                if (input >= 1 && input <= 180)
                        validInput = true;
                else
                        cout << "Invalid pomodoro time. Pomodoro session can be minimum 1 and maximum 180 minutes.\n";
        }
        pomodoro_time_minutes = input;
}

void set_break_time_menu()
{
        bool validInput = false;
        int input = 0;
        while (!validInput)
        {
                cout << "Enter new break time in minutes: ";
                cin >> input;
                if (input >= 1 && input <= 180)
                        validInput = true;
                else
                        cout << "Invalid pomodoro time. Pomodoro session can be minimum 1 and maximum 180 minutes.\n";
        }
        break_time_minutes = input;

}

void start_timer(){
        int pomodoros_done = 0;
        int total_pomodoro_minutes = 0;
        cout << "\033c";




}

void menuPrompt()
{
        cout << "\033c";
        printMenu();

        int choice;
        cin >> choice;

        switch (choice)
        {
        case 1:
                set_pomodoro_time_menu();
                break;
        case 2:
                set_break_time_menu();
                break;
        case 3:
                // show more options
                break;
        case 4:
                // TODO: timer should be more like alarm but only indicates time left until alarm
                // start timer

                break;
        default:
                cout << "Invalid choice. Try again.\n";
        }
}

bool isNumber(const string& s)
{
    string::const_iterator it = s.begin();
    while (it != s.end() && isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}


int main(int argc, char* argv[])
{
        bool valid_parameters = argc > 1 && isNumber(argv[1]) && isNumber(argv[2]) && stoi(argv[1]) <= 180 && \
                                stoi(argv[1]) > 0 && stoi(argv[2]) <= 180 && stoi(argv[2]) > 0;;
        if(valid_parameters){
                pomodoro_time_minutes = stoi(argv[1]);
                break_time_minutes = stoi(argv[2]);
        }
        
        cout << "Have fruitful sessions!\n";

        while (1)
        {
                menuPrompt();
                // TODO: find a way to clear and restart ui that supports all operating systems (linux, windows, macos)

        }

        return 0;
}
#include <iostream>
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

void setPomodoroTimeMenu()
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

void setBreakTimeMenu()
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

void menuPrompt()
{
        printMenu();

        int choice;
        cin >> choice;

        switch (choice)
        {
        case 1:
                setPomodoroTimeMenu();
                break;
        case 2:
                setBreakTimeMenu();
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

int main()
{
        cout << "Have fruitful sessions!\n";

        while (1)
        {
                menuPrompt();
                // TODO: find a way to clear and restart ui that supports all operating systems (linux, windows, macos)
                cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
        }

        return 0;
}
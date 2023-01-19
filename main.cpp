#include <iostream>
#include <string>
#include <sstream>
#include <chrono>
#include <thread>
#include <cstdlib>
#include <vector>
#include <dirent.h>

using namespace std;

/*
TODO:

- [ ] customizable ding sound
*/

int pomodoro_time_minutes = 25;
int break_time_minutes = 5;
string sfx_notif_title = "ding.wav";

void printMenu()
{
        cout << "Menu:" << endl;
        cout << "1. Set pomodoro time (current: " << pomodoro_time_minutes << " minutes)" << endl;
        cout << "2. Set break time (current: " << break_time_minutes << " minutes)" << endl;
        cout << "3. Set notification sound" << endl;
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

int toggle(int input)
{
        return input == 0 ? 1 : 0;
}

void printCharNTimes(char c, int n)
{
        for (int i = 0; i < n; i++)
        {
                cout << c;
        }
}

void print_timer_menu(int pomodoros_done, int total_focus_time, double percentile, int timer_mode, int time_left)
{
        cout << "Pomodoros done:\t\t" << pomodoros_done << endl;
        cout << "Total focus time:\t" << total_focus_time << " minutes" << endl
             << endl;

        if (timer_mode == 0)
                cout << "\033[1;32mFocusing...\033[0m" << endl;
        else
                cout << "\033[1;31mBreak!\033[0m" << endl;

        int bar_count = percentile * 26;
        cout << "[";
        printCharNTimes('#', 26 - bar_count);
        printCharNTimes(' ', bar_count);
        cout << "]\t" << time_left << " minutes left" << endl;
}

void start_timer()
{
        int pomodoros_done = 0;
        int total_pomodoro_minutes = 0;
        cout << "\033c";

        cout << "Pomodoros done:\t\t" << pomodoros_done << endl;
        cout << "Total focus time:\t" << total_pomodoro_minutes << " minutes" << endl
             << endl;
        cout << "\033[1;32mFocusing...\033[0m" << endl;
        cout << "[                          ]" << endl;

        int timer_mode = 1; // 0 => focus time
                            // 1 => not focus time

        int timers[] = {pomodoro_time_minutes, break_time_minutes};
        int timer;
        int counter = 0;
        int time_left = 0;
        double percentile;
        int bar_count;

        while (1)
        {
                timer_mode = toggle(timer_mode);
                timer = timers[timer_mode];

                while (counter < timer)
                {
                        // this_thread::sleep_for(chrono::minutes(1));
                        this_thread::sleep_for(chrono::seconds(1));
                        cout << "\033c";
                        counter++;
                        time_left = timer - counter;
                        if (timer_mode == 0)
                                total_pomodoro_minutes++;

                        percentile = (double)time_left / timer;

                        print_timer_menu(pomodoros_done, total_pomodoro_minutes, percentile, timer_mode, time_left);
                }
                counter = 0;
                string command = "aplay -q sfx/";
                command += sfx_notif_title;
                system(command.c_str());
                if (timer_mode == 0)
                        pomodoros_done++;
        }
}

vector<string> gather_files(string dir, string suffix)
{
        vector<string> wav_files;

        DIR *dp;
        struct dirent *dirp;
        if ((dp = opendir(dir.c_str())) == NULL)
        {
                cout << "Error opening " << dir << endl;
                return wav_files;
        }

        while ((dirp = readdir(dp)) != NULL)
        {
                string file_name = string(dirp->d_name);
                string file_ext = file_name.substr(file_name.find_last_of(".") + 1);
                if (file_ext.compare(suffix) == 0 )
                        wav_files.push_back(file_name);
        }

        closedir(dp);
        
        return wav_files;
}

void set_notification_sound()
{
        int choice;
        while (1)
        {
                cout << "\033c";
                cout << "Current song: " << sfx_notif_title << endl<< endl;
                cout << "Input one of the numbers below: " << endl;

                vector<string> sfx_vector = gather_files("sfx", "wav");
                for (int i = 1; i <= sfx_vector.size(); i++)
                {
                        cout << i << ". " << sfx_vector.at(i-1) << endl;
                }
                cout << "0 to leave to main menu\n";
                cout << "Input: ";
                int choice;
                cin >> choice;
                if (choice == 0)
                {
                        break;
                }
                else if (choice > 0 && choice <= sfx_vector.size())
                {
                        cout << sfx_vector.at(choice - 1) << " selected!\n";
                        sfx_notif_title = sfx_vector.at(choice - 1);
                        break;
                }
                else
                {
                        cout << "Wrong input! Try again.\n";
                }
        }
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
                set_notification_sound();
                break;
        case 4:
                start_timer();

                break;
        default:
                cout << "Invalid choice. Try again.\n";
        }
}

bool isNumber(const string &s)
{
        string::const_iterator it = s.begin();
        while (it != s.end() && isdigit(*it))
                ++it;
        return !s.empty() && it == s.end();
}

int main(int argc, char *argv[])
{
        bool valid_parameters = argc > 1 && isNumber(argv[1]) && isNumber(argv[2]) && stoi(argv[1]) <= 180 &&
                                stoi(argv[1]) > 0 && stoi(argv[2]) <= 180 && stoi(argv[2]) > 0;
        
        if (valid_parameters)
        {
                pomodoro_time_minutes = stoi(argv[1]);
                break_time_minutes = stoi(argv[2]);
        }

        cout << "Have fruitful sessions!\n";

        while (1)
        {
                menuPrompt();
        }

        return 0;
}
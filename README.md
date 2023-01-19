# Pomodoro Timer

This is a simple pomodoro timer that allows you to set the duration of your focus and break times. It also provides a timer menu that shows the progress of your focus time, the number of pomodoros completed, and the total focus time in minutes.

# Features

- Set the duration of focus and break times
- Timer menu that shows the progress of focus time, number of pomodoros completed, and total focus time in minutes
- Advanced menu to customize the timer

# Screenshots
## Main menu
![image](https://user-images.githubusercontent.com/73022312/213349345-afac9179-0dea-4676-81bb-1df36258a991.png)

### Timer menu while work time
![image](https://user-images.githubusercontent.com/73022312/213349267-cd474318-e9c6-42b5-8618-798d8c50ba36.png)

### Timer menu while break
![image](https://user-images.githubusercontent.com/73022312/213349198-2d7916be-047b-40b1-a192-baa288b44059.png)

### Advanced menu
[in progress]

# TODO

- [ ] Customizable ding sound
- [ ] Persistent configuration

# Usage

- Clone or download the repository
- Compile and run the program on your command line
- Select the options from the menu to set the focus and break times, start the timer and customize the timer

# Requirements

- C++11
- `iostream`, `string`, `sstream`, `chrono`, `thread` and `cstdlib` libraries
- `aplay` 

# Note

- The timer is limited to a minimum of 1 minute and a maximum of 180 minutes.
- The program uses escape codes to change text color on the console, which is not supported on Windows Command Prompt. It is recommended to use Git Bash or similar terminal for windows for best results.

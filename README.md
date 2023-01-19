# Pomodoro Timer

This is a simple pomodoro timer that allows you to set the duration of your focus and break times. It also provides a timer menu that shows the progress of your focus time, the number of pomodoros completed, and the total focus time in minutes.

# Features

- Set the duration of focus and break times
- Timer menu that shows the progress of focus time, number of pomodoros completed, and total focus time in minutes
- Advanced menu to customize the timer

# Screenshots
### Main menu
![image](https://user-images.githubusercontent.com/73022312/213548749-ca97cc11-ed89-43a5-84f5-7f85264530d2.png)

### Timer menu while work time
![image](https://user-images.githubusercontent.com/73022312/213349267-cd474318-e9c6-42b5-8618-798d8c50ba36.png)

### Timer menu while break
![image](https://user-images.githubusercontent.com/73022312/213349198-2d7916be-047b-40b1-a192-baa288b44059.png)

### Setting pomodoro time
![image](https://user-images.githubusercontent.com/73022312/213548897-8ce485f8-ec1b-4b4c-95e5-828d87746d7b.png)

### Setting break time
![image](https://user-images.githubusercontent.com/73022312/213549065-1dffb585-7250-4b7a-a798-19d6ccdbfe22.png)

### Choosing custom ding sound 
![image](https://user-images.githubusercontent.com/73022312/213549395-5919c99b-787e-4500-8744-434b5aa42da4.png)


# TODO

- [X] Customizable ding sound
- [ ] Add more ding sounds
- [ ] Parallelize ding sound

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

# CplusplusProgram

# Summarize the project and what problem it was solving.
The assignment was to display two clocks simultaneously.  One clock was in a twelve hour format, and the other clock was in a twenty four hour format.  The displayed clocks are followed by a displayed menu with four options that allows the user to add one hour; add one minute; add one second; or exit the program.  The user selection updates both clocks simultaneously.

# What did you do particularly well?
The program worked correctly, and the displays were easy to read and use.  My functions did most of the work in the program.  Also I cleared the screen after the clocks updated and displayed the menu again which kept the diplay consistently easy to read.

# Where could you enhance your code? How would these improvements make your code more efficient, secure, and so on?
One enhancement that I could add would to have the clocks use running time.  I had static time which pulled initially from the system clock, but the program would be more complete with current running time.

# Which pieces of the code did you find most challenging to write, and how did you overcome this? What tools or resources are you # # adding to your support network?
The most challenging part to write was the time code.  There were a lot of factors to take into consideration to keep the clocks displaying correct time. For example, when you add a minute at 59 minutes, minutes becomes zero and hours have one added.  It made me add a lot of conditions to the math so that the time would be correct.  Also, getting the am/pm correct on the twelve hour clock was difficult.  I read a lot of articles about time to solve these problems.

# What skills from this project will be particularly transferable to other projects or course work?
This was the first large project that I completed in C++, so the use of a menu and taking action from the user choice is a skill that I have used many times since I wrote this. Also, the use of functions outside of main is very important in every program that I write.

How did you make this program maintainable, readable, and adaptable?
I used comments throughout the program so that anyone else looking at it will understand exactly what I did, and why I did it.

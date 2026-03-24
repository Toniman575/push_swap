_This project has been created as part of the 42 curriculum by asadik._

# Description
Sorts a list of integers using limited operations on two stacks. It uses Radix sort for large lists and a simple comparative sort algorithm for small lists.

# Instructions
Compile with `make`. To compile with debug flags, use `make debug`. All other standard make rules apply.

Run the program with `./push_swap 'list of numbers'`. You can pass the numbers as a single string or as separate arguments. The program will close gracefully and print "Error" followed by a newline if any invalid number is passed as an argument. This includes numbers that would overflow an integer. If no argument is passed or the passed numbers are already sorted, nothing will be printed. Otherwise, the operations needed to sort the numbers are printed, each one followed by a newline.

# Resources
[Push_Swap Tutorial](https://medium.com/nerd-for-tech/push-swap-tutorial-fa746e6aba1e).<br>
[Push swap visualizer](https://push-swap42-visualizer.vercel.app/).<br>
[Left Shift and Right Shift Operators in C/C++](https://www.geeksforgeeks.org/cpp/left-shift-right-shift-operators-c-cpp/).
*This project has been created as part of the 42 curriculum by fharutyu.*

Description:

This projects aims to generally mimic the behavior of printf() function without implementic some specific functionalities such as buffer management.

Instruction:

Use the "make" command to get the archive file. Use "make clean" to remove the object files. Use "make fclean" to delete all files created by "make" command.

Resources:

For this project following resources were used for learning the subject: Youtube tutorials, own experience, Google, AI (for questions).

Additional Notes:

When using the ft_printf() function with format specifier "%p" and argument 0, this implementation prints "(nil)", while the original printf() doesn't compile at all. I assume this is due to compiler specifications.

There are no special algorithms or data structures involved in this project. I used helper functions which handle format specifiers. I chose not to use malloc, as it is not necessary and raises the chances of segfaults. 

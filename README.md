Jun Yen Leung
7657071621
junyenle@usc.edu
hw4

general:
executable will be created in hw4 folder
makefile can generate amazon executable and debug executable
debug executable is identical to amazon except is compiled with fsanitize flag

to compile:
make amazon

to compile debug version (with fsanitize):
make debug

both: 
make all

to run:
./amazon database.txt OR ./debug database.txt
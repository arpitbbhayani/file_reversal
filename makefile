# 	makefile : Operating System Assignment 1 : Reversing the contents of a text file
#
#	Author	: Arpit Bhayani
#	E-mail 	: arpit.bhayani@students.iiit.ac.in
#	Roll no.: 201305515
#

all: 	 a.out

a.out:   main.o reverseFile.o
	 gcc -Wall main.o reverseFile.o

main.o:	 main.c reverseFileHeader.h
	 gcc -Wall -c main.c reverseFileHeader.h

reverseFile.o: reverseFile.c reverseFileHeader.h
	 gcc -Wall -c reverseFile.c reverseFileHeader.h

clean:
	 rm -rf main.o reverseFile.o reverseFileHeader.h.gch a.out


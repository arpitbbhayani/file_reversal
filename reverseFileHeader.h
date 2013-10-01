/*      reverseFileHeader.h  : Operating System Assignment 1 : Reversing the contents of a text file
*
*       Author  : Arpit Bhayani
*       E-mail  : arpit.bhayani@students.iiit.ac.in
*       Roll no.: 201305515
*/


#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

/*
*	This function prints out the Usage for the file reversal code.
*	It validates the number of command line arguments and provides corressponding usage statements.
*	@argument : int argc : number of command line argument passed.
*	@returns : void
*/
void printUsage(int);

/*
*	This function reverses the buffer "buffer" and stores the reversed buffer into reversedBuffer which is passed as argument.
*	@argument : char * reversedBuffer : the buffer in which the rever content will be stored.
*	@argument : char * buffer : the buffer of which contents are to be reversed.
*	@argumenr : int count : count is the length of the buffer.
*	@returns : pointer to reversedBuffer
*/
void reverseFile(char *);

/*
*	For debugging only.
*	This function prints out the buffer passed from index 0 to length 
*	@argument : char *  buffer : buffer to b printed onto console
*	@argument : int length : length of the buffer.
*	@returns : void
*	
*/
void printBuffer(char * , int);

/*
*	This function takes argument as char * which is the input file name
*	and returns a pointer to character string which is the output file name in a format specified as below
*	If inputFilename = "textfile.txt"
*	then outputFilename = "reverse_textfile.txt"
*	@argument : char * inputFilename : the path of the file.
*	@returns : pointer to the string "reverse_<inputFilename>"
*/
char * getOutputFilename(char * , char *);

/*
*	This function reverses the buffer "buffer" and stores the reversed buffer into reversedBuffer which is passed as argument.
*	@argument : char * reversedBuffer : the buffer in which the rever content will be stored.
*	@argument : char * buffer : the buffer of which contents are to be reversed.
*	@argumenr : int count : count is the length of the buffer.
*	@returns : pointer to reversedBuffer
*/
char * reverseBuffer(char * , int);

/*
*       This function takes argument as char *
*       and returns the length of the string.
*       If string = "textfile.txt"
*       then return value = 12
*       @argument : char * string.
*       @returns : length of the string
*/

int getLength( char * );

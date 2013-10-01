/* 	main.c	: Operating System Assignment 1 : Reversing the contents of a text file
*
*       Author  : Arpit Bhayani
*       E-mail  : arpit.bhayani@students.iiit.ac.in
*       Roll no.: 201305515
*/

#include "reverseFileHeader.h"

int main( int argc , char * argv[] ) {
	if(argc != 2)
		printUsage(argc);
	else
		reverseFile(argv[1]);
	return 0;

}

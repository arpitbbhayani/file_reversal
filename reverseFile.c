/*	reverseFile.c	: Operating System Assignment 1 : Reversing the contents of a text file
*
*       Author  : Arpit Bhayani
*       E-mail  : arpit.bhayani@students.iiit.ac.in
*       Roll no.: 201305515
*/

#include "reverseFileHeader.h"
#define BUFFER_SIZE 4096

/*
*	This function has the core logic of the file reversal.
*	the method is a void method and it creates the file with reversed contents named reverse_<filename>
*	@argument : char * inputFilename - the path of the file that needs to be reversed.
*	@returns : void
*/

void reverseFile(char * inputFilename) {
	
	char * outputFilename = NULL , * readBuffer = NULL;
	char * prefix = "reverse_";

	int inputFileDesc = 0 , outputFileDesc = 0;
	long int readCount , writeCount = 0 , position = 0 , oldPosition = 0 ;
	
	outputFilename = getOutputFilename(inputFilename , prefix);

	inputFileDesc	= open(inputFilename , O_RDONLY);
	outputFileDesc	= open(outputFilename , O_WRONLY | O_CREAT | O_TRUNC , S_IRUSR | S_IWUSR);

	if(inputFileDesc == -1) {
		printf("Error opening input file : %s\n" , inputFilename);
		return;
	}

	if(outputFileDesc == -1) {
		printf("Error opening output file : %s\n" , outputFilename);
		return;
	}

	/*
	*	Assert : Both files are successfully opened.
	*/

	readBuffer = (char *) malloc ( BUFFER_SIZE );

	position = lseek(inputFileDesc , (long int) (BUFFER_SIZE * -1) , SEEK_END);
	if( position == -1 ) {
		position = lseek(inputFileDesc , 0L , SEEK_SET);
	}
	readCount = read(inputFileDesc , readBuffer , BUFFER_SIZE);

	do {
		writeCount = write( outputFileDesc , reverseBuffer(readBuffer , readCount) , readCount );
		
		oldPosition = position;
		position = lseek(inputFileDesc , (long int) (writeCount * -2) , SEEK_CUR);

		if( position == -1 ) {
			position  = lseek(inputFileDesc , 0L , SEEK_SET);
			readCount = read(inputFileDesc , readBuffer , oldPosition);
			writeCount = write( outputFileDesc , reverseBuffer(readBuffer , readCount) , readCount );
			break;
		}
		else {
			readCount = read(inputFileDesc , readBuffer , BUFFER_SIZE);
		}


	}while( readCount > 0 );

	/*
	*	Freeing all the memory allocated.
	*	1. inputFilename that was malloced so as to get reverse_<filename>
	*.	2. buffer that was allocated for reading from the input file.
	*/
	free(readBuffer);
	free(outputFilename);

	/*
	*	Closing input and output files using close system call
	*/
	close(inputFileDesc);
	close(outputFileDesc);

}


/*
*	This function takes argument as char *
*	and returns the length of the string.
*	If string = "textfile.txt"
*	then return value = 12
*	@argument : char * string.
*	@returns : length of the string
*/

int getLength( char * string ) {

	int length = 0;
	while( * string ) 	{ length++; 	string++; }
	return length;
}


/*
*	This function takes argument as char * which is the input file name
*	and returns a pointer to character string which is the output file name in a format specified as below
*	If inputFilename = "textfile.txt"
*	then outputFilename = "reverse_textfile.txt"
*	@argument : char * inputFilename : the path of the file.
*	@returns : pointer to the string "reverse_<inputFilename>"
*/

char * getOutputFilename(char * inputFilename , char * prefix) {

	char * outputFilename = (char *) malloc( getLength(inputFilename) + 9 );
	char *outputFile = outputFilename;

	int indexLastSlash = -1;
	int i = 0;

	/*
	*	To handle if the absolute path is passed as the command line argument.
	*	If argument =  /home/arpit/OS/input.txt
	*	then output =  /hone/arpit/OS/reverse_input.txt
	*/

	if( inputFilename[i] == '/' ) {
	
		while( inputFilename[i] ) {
			if( inputFilename[i] == '/' ) {
				indexLastSlash = i;
			}
			outputFilename[i] = inputFilename[i];
			i++;
		}
	}


	i = indexLastSlash + 1;
	inputFilename = &inputFilename[i];
	outputFilename = &outputFilename[i];

	while( * prefix ) 		*outputFilename++ = *prefix++;
	while( * inputFilename )	*outputFilename++ = *inputFilename++;
					*outputFilename = '\0';
	return outputFile;
}

/*
*	This function prints out the Usage for the file reversal code.
*	It validates the number of command line arguments and provides corressponding usage statements.
*	@argument : int argc : number of command line argument passed.
*	@returns : void
*/

void printUsage(int argc) {
	if( argc > 2 ) {
		printf("Too many arguments provided\n");
	}
	printf("Usage : reverse <inputFilename>\n");
}

/*
*	For debugging only.
*	This function prints out the buffer passed from index 0 to length 
*	@argument : char *  buffer : buffer to b printed onto console
*	@argument : int length : length of the buffer.
*	@returns : void
*	
*/
void printBuffer(char * buffer , int length) {
	int i = 0;
	printf("\ncount = %d and Buffer :" , length);
	for(i = 0 ; i < length ; i++) {
		printf("%c" , buffer[i]);
	}
	printf("\n");
}

/*
*	This function reverses the buffer "buffer" and stores the reversed buffer into reversedBuffer which is passed as argument.
*	@argument : char * reversedBuffer : the buffer in which the rever content will be stored.
*	@argument : char * buffer : the buffer of which contents are to be reversed.
*	@argumenr : int count : count is the length of the buffer.
*	@returns : pointer to reversedBuffer
*/
char * reverseBuffer(char * buffer , int count) {
    	int i = 0 , j = count - 1;
	char tempChar;
    	for (i = 0 ; i < (count / 2) ; i++ , j--) {
		tempChar = buffer[i];
		buffer[i] = buffer[j];
		buffer[j] = tempChar;
    	}

	return buffer;

}

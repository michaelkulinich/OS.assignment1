/*
Michael Kulinich
kulinich@chapman.edu

Ayden Best
bbest@chapman.edu

CPSC 380-01
Assignment 1
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
extern int errno;

int main(int argc, char *argv[])
{
  //require user to execute file correctly by using only 3 arguments: filecpy <input file> <output file>
  if (argc != 3) {
    printf("Error: %s <input file> <output file> \n", argv[0]);
    return 0;

  }
  printf("Given Input file: %s\nOutput file: %s\n", argv[1], argv[2]);


  //           Openning input file           //

  //attempt to open the input file
  // if it does not exist, its value will be -1 and we will exit the program
  int inFile = open(argv[1], O_RDONLY);

  // print error and exit if it fails
  if (inFile < 0){
    printf("Error: file:  %s not found\n", argv[1]);
    printf("Error Number %d\n", errno);
    return 0;
  }
  else
    printf("File %s succesfully found\n", argv[1]);


  //          Creating output file           //

  // attempt to open the output file
  // if it fails, its value will become -1, and again we quit
  int outFile = open(argv[2], O_CREAT|O_EXCL|O_WRONLY, 00700);
      // O_CREAT to create a new file
      // O_EXCL to prevent overwriting an existing file
      // O_WRONLY to write to the file

  // print error if file exists or it fails to open
  if (outFile < 0){
    printf("Error: file:  %s already exists\n", argv[2]);
    printf("Error Number %d\n", errno);
    return 0;
  }
  printf("File %s succesfully created\n", argv[2]);


  //         Reading from input file and writing to output      //

  char c[512];     // array of chars, used to read file contents by 512 chars at a time. Requires 512 bytes of space!
  int bytesRead;   // track bytes read
  int bytesWrote;  // track bytes written

  //infinite loop until no more bytes have been read
  //meaning it reached the end of input file
  while(1){
    bytesRead = read(inFile, c, 512);
    if (bytesRead == 0)
      break;
    //only write the number of bytes read into the buffer to prevent extra bytes being written
    bytesWrote = write(outFile, c, bytesRead);
  }

  //          Closing both files          //

  if (close(inFile) < 0){
    printf("Error Number %d\n", errno);
    return 0;
  }

  if (close(outFile) < 0){
    printf("Error Number %d\n", errno);
    return 0;
  }
  //delete[] c;
  printf("Successfully completed\n");


  return 0;

}

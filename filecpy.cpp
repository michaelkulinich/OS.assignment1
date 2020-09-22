/*
Michael Kulinich
Ayden Best
kulinich@chapman.edu

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
  //checks if the proper number of arguments is provided by the user
  //if it is not three then program ends and displays error message
  if (argc != 3) {
    printf("Error: %s <input file> <output file> \n", argv[0]);
    return 0;

  }
  printf("Given Input file: %s\nOutput file: %s\n", argv[1], argv[2]);



  //           Openining input file           //

  //Since the user gave the proper number of arguments
  //we try to open the input file, fd < 0 if input file does not exist or unsuccessuful 
  int fd = open(argv[1], O_RDONLY);

  //if the input file does not exist, then print error message and end program
  if (fd < 0){
    printf("Error: file:  %s not found\n", argv[1]);
    printf("Error Number %d\n", errno);
    return 0;
  }
  else
    printf("File %s succesfully found\n", argv[1]);

  //          Creating output file           //
  
  //We try to open the output file, if it doesn't exits, open() will return < 0
  // gives user read, write, and execute permission
  int out = open(argv[2], O_CREAT|O_EXCL|O_WRONLY, 00700);

  //if the output file does exist, then print error message and end program
  if (out < 0){
    printf("Error: file:  %s already exists\n", argv[2]);
    printf("Error Number %d\n", errno);
    return 0;
  }
  printf("File %s succesfully created\n", argv[2]);

  
  //         Reading from input file and writing to output      //

  char *c = new char[512];
  int bytesRead;
  int bytesWrote;
  //while loop to read from input file and write to output untill
  //it reaches the end of input file
  while(true){
    bytesRead = read(fd, c, 512);
    if (bytesRead == 0)
      break;
    //only write a certain count (bytesRead) of the buffer
    //so extra bytes arent written into the output file
    bytesWrote = write(out, c, bytesRead);
  }
  
  //          Closing both files          //
  
  if (close(fd) < 0){
    printf("Error Number %d\n", errno);
    return 0;
  }
 
  if (close(out) < 0){
    printf("Error Number %d\n", errno);
    return 0;
  }
  delete[] c;
  printf("Successfully completed\n");


  return 0;

}

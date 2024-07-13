#include <stdio.h>

static unsigned long long int noOfMoves; //global variable used to count the number of moves of the disks

void towersOfHanoi(unsigned int disks, unsigned int initialPeg, unsigned int finalPeg, unsigned int temporaryPeg); //Function prototype

int main(void) //start main
{
	unsigned int noOfDisks = 0, initPeg = 1, finPeg = 3, tempPeg = 2; //Initialization
	puts("\t\t\t\t\t\t~Towers of Hanoi~\n\n"); //Title of the program
	puts("The following program is programmed to solve the famous Towers of Hanoi problem using recursion.\nThe user has to input his/her number of disks to start the program.\nNOTE: After the user have inputted the number of disks, the program will print the ordered sequence to solve the problem.\n\n"); //Instruction / Intro
	
	//Asking the user for the no. of disks
	printf("%s", "Enter your number of disks: ");
	scanf("%u", &noOfDisks);
	
	printf("\nThe sequence of moves for %u disks are: ", noOfDisks);
	puts("\n--------------------------------------\n");
	towersOfHanoi(noOfDisks, initPeg, finPeg, tempPeg); //Function call
	printf("\nTotal number of moves: %llu", noOfMoves); //printing the number of moves the disks have taken.

} //end main

void towersOfHanoi(unsigned int disks, unsigned int initialPeg, unsigned int finalPeg, unsigned int temporaryPeg) //Fucntion definition
{
	if(1 == disks) //base case
	{
		++noOfMoves;
		printf("Move disk %u from peg %u to peg %u\n", disks, initialPeg, finalPeg); 
	}
	else
	{
		towersOfHanoi(disks - 1, initialPeg, temporaryPeg, finalPeg); //Recursive call #1
		++noOfMoves;
		printf("Move disk %u from peg %u to peg %u\n", disks, initialPeg, finalPeg);
		towersOfHanoi(disks - 1, temporaryPeg, finalPeg, initialPeg); //Recursive call #2
	}
}

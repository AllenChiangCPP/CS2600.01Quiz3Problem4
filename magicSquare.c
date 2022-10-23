#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
//magic square checker, takes a 2d array
int magicSquareCheck(int givenSquare[3][3])
{
    //calculate sum of all entries in given square for checking if entries are 1-9 with no repeats
    int squareSum = givenSquare[0][0] + givenSquare[0][1] + givenSquare[0][2] + 
    givenSquare[1][0] + givenSquare[1][1] + givenSquare[1][2] + givenSquare[2][0] + givenSquare[2][1] + givenSquare[2][2];
    //check if sum of all entries is 45 to check for no repeats
    //check sum of rows and columns to be 15 for all rows and colunmns
    //return 1 if is magic square, return 0 if not
    if(givenSquare[0][0] + givenSquare[0][1] + givenSquare[0][2] == 15 && givenSquare[1][0] + givenSquare[1][1] + givenSquare[1][2] == 15 &&
    givenSquare[2][0] + givenSquare[2][1] + givenSquare[2][2] == 15 && givenSquare[0][0] + givenSquare[1][0] + givenSquare[2][0] == 15
    && givenSquare[0][1] + givenSquare[1][1] + givenSquare[2][1] == 15 && givenSquare[0][2] + givenSquare[1][2] + givenSquare[2][2] == 15 
    && squareSum == 45)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
//add squarePrinter to print out 2d array as a square for later use
void squarePrinter(int givenSquare[3][3])
{
    printf("+---+---+---+\n");
    printf("| %d | %d | %d |\n", givenSquare[0][0], givenSquare[0][1], givenSquare[0][2]);
    printf("+-----------+\n");
    printf("| %d | %d | %d |\n", givenSquare[1][0], givenSquare[1][1], givenSquare[1][2]);
    printf("+-----------+\n");
    printf("| %d | %d | %d |\n", givenSquare[2][0], givenSquare[2][1], givenSquare[2][2]);
    printf("+-----------+\n");
}
//add randomizeSquare function
//add function that generates a random 2-d array with random numbers 1-9
int** randomizeSquare(int square[3][3])
{   
    int randomRow = 0;
    int randomColumn = 0;
    int temp;
    //shuffle a given 2d array randomly 
    int value = 1;
    for(int i = 0; i < 3; i ++) //for loops that go through every entry in the array
    {
        for(int j = 0; j < 3; j++)
        {
            randomRow = rand() % 3; //generate random number from 0 - 2 for swapping
            randomColumn = rand() % 3; //generate random number from 0 - 2 for swapping
            temp = square[i][j]; //temporary get current entry in square
            square[i][j] = square[randomRow][randomColumn]; //swap current entry with randomly generated square location
            square[randomRow][randomColumn] = temp; //set randomly generated location to temp to swap current and randomly generated square location
        }
    }
}

int main()
{
    srand(time(NULL) * getpid()); //for random generation in randomizeSquare
    //create 2d array that has a Lo Shu Magic Square
    int loShu[3][3] = {{4,9,2},{3,5,7},{8,1,6}};
    printf("Magic square success test: \n");
    squarePrinter(loShu); //print successful square
    if(magicSquareCheck(loShu) == 1) //prints if a square is successful or not
    {
        printf("successful square \n");
    }
    else
    {
        printf("unsuccessful square \n");
    }
    printf("\n");
    //create 2d array that fails the Lo Shu Magic Square 
    int loShuFail[3][3] = {{2,4,9},{3,5,7},{6,8,1}};
    printf("Magic square failure test: \n");
    squarePrinter(loShuFail); //print unsuccessful square
    if(magicSquareCheck(loShuFail) == 1) //prints if a square is successful or not
    {
        printf("successful square \n");
    }
    else
    {
        printf("unsuccessful square \n");
    }
    printf("\n");
    printf("Square with random numbers test.\n");
    //add counter, starts at 0, goes up for each failed magic square
    int magicSquareAttempts = 0;
    int defaultSquare[3][3] = {{1,2,3},{4,5,6},{7,8,9}}; //create a square with values 1 - 9
    randomizeSquare(defaultSquare); //randomize newly created square
    //add while loop, randomizeSquare function until generate a Lo Shu square
    while(magicSquareCheck(defaultSquare) == 0)
    {
        randomizeSquare(defaultSquare);
        magicSquareAttempts++;
    }
    //print square using squarePrinter
    printf("Number of squares generated before success: %d\n", magicSquareAttempts);
    printf("Successful square generated: \n");
    squarePrinter(defaultSquare);
    return 0;
}
    


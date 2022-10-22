#include <stdio.h>
//magic square checker, takes a 2d array

//return 1 if is magic square, return 0 if not
int magicSquareCheck(int givenSquare[3][3])
{
    int squareSum = givenSquare[0][0] + givenSquare[0][1] + givenSquare[0][2] +
    givenSquare[1][0] + givenSquare[1][1] + givenSquare[1][2] + givenSquare[2][0] + givenSquare[2][1] + givenSquare[2][2];
    //check if sum of all entries is 45 to check for no repeats
    //check sum of rows and columns to be 15 for all rows and colunmns
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
//add generateSquare function
    //add function that generates a random 2-d array with random numbers 1-9
    //shuffle a 2d array randomly that contains 1-9
int main()
{
    //create 2d array that has a Lo Shu Magic Square
    int loShu[3][3] = {{4,9,2},{3,5,7},{8,1,6}};
    printf("loShu success test: %d\n",magicSquareCheck(loShu));
    //create 2d array that fails the Lo Shu Magic Square 
    int loShuFail[3][3] = {{2,4,9},{3,5,7},{6,8,1}};
    printf("loShu failure test: %d\n",magicSquareCheck(loShuFail));
    return 0;

    //add while loop, generateSquare function until generate a Lo Shu square
    //add counter, starts at 0, goes up for each failed magic square
    //print square using squarePrinter
}
    


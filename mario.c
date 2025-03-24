#include <cs50.h>
#include <stdio.h>

void print_row(int total_rows,int current_row);

int main(void)
{
    //ask for height
    int height ;
    do
    {
        height = get_int("Height : ");
    }
    while(height<1 || height > 8);

    //build a pyramid of that height

    for(int i = 0 ; i < height ; i++)   // i is the no. of hashes in each row
    {
        print_row(height ,i+1);
    }


}

void print_row(int total_rows,int current_row) // total_rows is total rows and current_row is the current row number
{
    for(int n = 0 ; n < total_rows - current_row ; n++ ) //n is the dots in each row(= total rows - row number)
    {
        printf(" ");
    }
    for(int i = 0 ; i < current_row ; i++) //i is the number of hashes in each row (first pyramid)
    {
        printf("#");
    }
    printf("  ");
    for(int r = 0; r< current_row ; r++) //r is the number of hashes in each row (second pyramid)
    {
        printf("#");
    }
    printf("\n");

}

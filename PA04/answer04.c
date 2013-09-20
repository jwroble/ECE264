/*
 * Please fill the functions in this file.
 * You can add additional functions. 
 *
 * Hint: 
 * You can write additonal functions.
 * You can test your functions with your own input file.
 * See details in README or typing command ./pa04 in terminal after make.
 * See output format examples in any of the files in directory expected.
 * 
 * You may create additional arrays if needed.  The maximum size
 * needed is specified by MAXLENGTH in pa04.h.
 */

#include "pa04.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


/*
 * =================================================================
 * This function prints all partitions of a positive integer value
 * For example, if the value is 3:
 *
 * partitionAll 3
 * = 1 + 1 + 1
 * = 1 + 2
 * = 2 + 1
 * = 3
 */

void print_arr(int * arr, int len)
{
	int i;
	if(len > 0)
	{
		printf("= %d", arr[0]);
	}
	for(i = 1; i < len; i++)
	{
		printf(" + %d", arr[i]);
	}
	printf("\n");
}

void partition_worker(int * arr, int pos, int n)
{
	if(n == 0)
	{
		print_arr(arr, pos);
		return;
	}
	int i;
	for(i = 1; i<= n; i++)
	{
		arr[pos] = i;
		partition_worker(arr, pos+1, n-i);
	}
}

void partitionAll(int value)
{
    printf("partitionAll %d\n", value);
    int * buffer = malloc( value * sizeof(int));
    partition_worker(buffer, 0, value);
    free(buffer);
  
}
/*
 * =================================================================
 * This function prints the partitions that use increasing values.
 *
 * For example, if value is 5
 * 2 + 3 and
 * 1 + 4 are valid partitions
 *
 * 5 is a valid partition
 * 
 * 1 + 1 + 3 and
 * 2 + 1 + 2 and
 * 3 + 2 are invalid partitions.
 * 
 * The program should generate only valid partitions.  Do not
 * generates invalid partitions and checks validity before printing.
 *
 */



void printIncreasing(int * arr, int len)
{       
        int ind = 1; 
        int check = 1;
        while(ind < len)
        {
            if(arr[ind -1] >= arr[ind])
            {
                check = 0;
            }
            ind++;
        }

        if( check == 1)
        {
            int i;
            if(len > 0)
            {
                printf("= %d", arr[0]);
            }
            for(i = 1; i < len; i++)
            {
                printf(" + %d", arr[i]);
            }
            printf("\n");
        }
}

void partition_increasing(int * arr, int pos, int n)
{

        if(n == 0)
        {
            printIncreasing(arr, pos);
            return;
        }
        int i;
        for(i = 1; i<= n; i++)
        {
                arr[pos] = i;
                partition_increasing(arr, pos+1, n-i);
        }
}

void partitionIncreasing(int value)
{
    printf("partitionIncreasing %d\n", value);
    int * buffer = malloc( value * sizeof(int));
    partition_increasing(buffer, 0, value);
    free(buffer);
}

/*
 * =================================================================
 * This function prints the partitions that use Decreasing values.
 *
 * For example, if value is 5
 * 3 + 2 and
 * 4 + 1 are valid partitions
 *
 * 5 is a valid partition
 * 
 * 1 + 1 + 3 and
 * 2 + 1 + 2 and
 * 2 + 3 are invalid partitions.
 * 
 * The program should generate only valid partitions.  Do not
 * generates invalid partitions and checks validity before printing.
 *
 */

void printDecreasing(int * arr, int len)
{
        int ind = 1;
        int check = 1;
        while(ind < len)
        {
            if(arr[ind -1] <= arr[ind])
            {
                check = 0;
            }
            ind++;
        }

        if( check == 1)
        {
            int i;
            if(len > 0)
            {
                printf("= %d", arr[0]);
            }
            for(i = 1; i < len; i++)
            {
                printf(" + %d", arr[i]);
            }
            printf("\n");
        }
}

void partition_decreasing(int * arr, int pos, int n)
{

        if(n == 0)
        {
            printDecreasing(arr, pos);
            return;
        }
        int i;
        for(i = 1; i<= n; i++)
        {
                arr[pos] = i;
                partition_decreasing(arr, pos+1, n-i);
        }
}

void partitionDecreasing(int value)
{
    printf("partitionDecreasing %d\n", value);
    int * buffer = malloc( value * sizeof(int));
    partition_decreasing(buffer, 0, value);
    free(buffer);

}

/*
 * =================================================================
 * This function prints odd number only partitions of a positive integer value
 * For example, if value is 5
 * 1 + 1 + 1 + 1 + 1 and
 * 1 + 3 + 1 are valid partitions
 *
 * 5 is a valid partition
 * 
 * 1 + 1 + 1 + 2 and
 * 2 + 1 + 2 and
 * 2 + 3 are invalid partitions.
 * 
 * The program should generate only valid partitions.  Do not
 * generates invalid partitions and checks validity before printing.
 */


void partition_odd(int * arr, int pos, int n)
{
        if(n == 0)
        {
                print_arr(arr, pos);
                return;
        }
        int i;
        for(i = 1; i<= n; i++)
        {
                if(i % 2 != 1)
                {
                    continue;
                }
                arr[pos] = i;
                partition_odd(arr, pos+1, n-i);
        }
}

void partitionOdd(int value)
{
    printf("partitionOdd %d\n", value);
    int * buffer = malloc( value * sizeof(int));
    partition_odd(buffer, 0, value);
    free(buffer);
}

/*
 * =================================================================
 * This function prints even number only partitions of a positive integer value
 * For example, if value is 8
 * 2 + 2 + 2 + 2and
 * 2 + 4 + 2 are valid partitions
 *
 * 8 is a valid partition
 *
 * 2 + 1 + 1 + 2 + 2and
 * 2 + 1 + 2 + 3and
 * 5 + 3 are invalid partitions.
 *
 * if the value is 5, there will be no result generated
 * 
 * The program should generate only valid partitions.  Do not
 * generates invalid partitions and checks validity before printing.
 */

void partition_even(int * arr, int pos, int n)
{
        if(n == 0)
        {
                print_arr(arr, pos);
                return;
        }
        int i;
        for(i = 1; i<= n; i++)
        {
                if(i % 2 != 0)
                {
                    continue;
                }
                arr[pos] = i;
                partition_even(arr, pos+1, n-i);
        }
}

void partitionEven(int value)
{
    printf("partitionEven %d\n", value);
    int * buffer = malloc( value * sizeof(int));
    partition_even(buffer, 0, value);
    free(buffer);
}

/*
 * =================================================================
 * This function prints alternate ood and even number partitions of a positive integer value. Each partition starts from and odd number, even number, ood number again, even number again...etc.
 *
 * For example, if value is 6
 * 1 + 2 + 1 + 2 and
 * 3 + 2 + 1 are valid partitions
 *
 * 6 is not a valid partition
 *
 * 2 + 1 + 1 + 2 and
 * 2 + 1 + 3and
 * 5 + 1 are invalid partitions.
 * 
 * The program should generate only valid partitions.  Do not
 * generates invalid partitions and checks validity before printing.
 */

void partition_oddEven(int * arr, int pos, int n)
{        
        int check;
        if(pos % 2 == 1)
        {
            check = 1;
        }
        if(pos % 2 == 0)
        {
            check = 0;
        }
        if(n == 0)
        {
                print_arr(arr, pos);
                return;
        }
        int i;
        for(i = 1; i<= n; i++)
        {
                if((i % 2 != 1 && check != 1) || (i % 2 != 0 && check != 0))
                {
                    continue;
                }
                
                arr[pos] = i;
                partition_oddEven(arr, pos+1, n-i);
        }
}

void partitionOddAndEven(int value)
{
    printf("partitionOddAndEven %d\n", value);
    int * buffer = malloc( value * sizeof(int));
    partition_oddEven(buffer, 0, value);
    free(buffer);
}

/*
 * =================================================================
 * This function prints prime number only partitions of a positive integer value
 * For example, if value is 6
 * 2 + 2 + 2 and
 * 3 + 3 are valid partitions
 *
 * 6 is not a valid partition
 * 
 * 2 + 4 and
 * 1 + 5 are invalid partitions.
 * 
 * The program should generate only valid partitions.  Do not
 * generates invalid partitions and checks validity before printing.
 */


void partition_prime(int * arr, int pos, int n)
{
        if(n == 0)
        {
                print_arr(arr, pos);
                return;
        }
        int i;
        for(i = 1; i<= n; i++)
        {
            if(i == 1 || (i > 2 && i % 2 == 0) || (i > 3 && i % 3 == 0) || (i > 5 && i % 5 == 0)|| (i > 7 && i % 7 == 0))
            {
                continue;
            }
                arr[pos] = i;
                partition_prime(arr, pos+1, n-i);
        }
}

void partitionPrime(int value)
{
    printf("partitionPrime %d\n", value);
    int * buffer = malloc( value * sizeof(int));
    partition_prime(buffer, 0, value);
    free(buffer);
}

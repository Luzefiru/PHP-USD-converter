/**
 * @file main.c
 * @author Christian de Jesus
 * @brief Gets an amount in USD from the user & outputs the converted denominations in PHP.
 * @version 0.1
 * @date 2022-09-09
 * 
 * @copyright Copyright (c) 2022
 */

#include <stdio.h>

#define CONVERSION_RATE_USD_TO_PHP 49.2

int main(void)
{
    float usd, php, thousand, five_hundred, one_hundred, twenty, five, one, sum;

    /* asks for price in USD */
    printf("Enter amount (USD): ");
    scanf("%f", &usd);

    /* displays the raw values after converting to PHP */
    printf("Amount (USD): $%.2f\n", usd);
    printf("Amount (Peso): Php %.2f\n\n", php);

    /* floor divides by each denominator to get the number of each */

    // to be done

    /* displays the count & price of each denomination to get to the truncated raw value of PHP */
    printf("Denomination\n");
    printf("1000 peso bill = \n");
    printf("500 peso bill = \n");
    printf("100 peso bill = \n");
    printf("20 peso bill = \n");
    printf("5 peso coin = \n");
    printf("1 peso coin = \n");

    /* prints the total sum of the converted denominations */
    printf("\nTOTAL: Php %.2f", sum);




    return 0;
}
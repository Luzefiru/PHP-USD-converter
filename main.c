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

/**
 * 
 * @brief This function calculates the sum of the amount of denominations, given their inputted price.
 * 
 * INPUT
 * -----
 * denomination_num (int) : the amount of a specific denomination
 * denomination_price (int) : the price of a specific denomination
 * 
 * OUTPUT
 * ------
 * int : the product of the number of denominations & its price
 * 
 */
int calculateProduct(int denomination_num, int denomination_price)
{
    return denomination_num * denomination_price;
}

/**
 * 
 * @brief This calculates the the next current amount for the calculations by subtracting the last current amount by the product of the denominations before it.
 * 
 * INPUT
 * -----
 * previous_php (int) : the previous current amount of php
 * denomination_num (int) : the amount of a specific denomination
 * denomination_price (int) : the price of a specific denomination
 * 
 * OUTPUT
 * ------
 * new_current_php (int) : the previous_php minus the product of the number of denominations & its price
 * 
 */
int calculateCurrentPHP(int previous_php, int denomination_num, int denomination_price)
{
    int new_current_php = previous_php - (denomination_num * denomination_price);
    return new_current_php;
}


int main(void)
{
    float usd, php;
    int sum, thousand, five_hundred, one_hundred, twenty, five, one;

    /* asks for price in USD */
    printf("Enter amount (USD): ");
    scanf("%f", &usd);

    /* converts USD to PHP */
    php = usd * CONVERSION_RATE_USD_TO_PHP;

    /* displays the raw values after converting to PHP */
    printf("\nAmount (USD): $%.2f\n", usd);
    printf("Amount (Peso): Php %.2f\n\n", php);

    /* truncates the decimal points to convert to denominations */
    php = (int) php;

    /* floor divides by each denominator to get the number of each */
    int current_php = php; // the price at the moment

    thousand = current_php / 1000;
    current_php = calculateCurrentPHP(current_php, thousand, 1000);
    five_hundred = current_php / 500;
    current_php = calculateCurrentPHP(current_php, five_hundred, 500);
    one_hundred = current_php / 100;
    current_php = calculateCurrentPHP(current_php, one_hundred, 100);
    twenty = current_php / 20;
    current_php = calculateCurrentPHP(current_php, twenty, 20);
    five = current_php / 5;
    current_php = calculateCurrentPHP(current_php, five, 5);
    one = current_php / 1;
    current_php = calculateCurrentPHP(current_php, one, 1);
    
    /* calculates the sum of all denominations */
    sum = calculateProduct(thousand, 1000) + calculateProduct(five_hundred, 500) + calculateProduct(one_hundred, 100)
        + calculateProduct(twenty, 20) + calculateProduct(five, 5) + calculateProduct(one, 1);

    /* displays the count & price of each denomination to get to the truncated raw value of PHP */
    printf("DENOMINATIONS:\n");
    printf("1000 peso bill = %d = Php %d.00\n",
    thousand, calculateProduct(thousand, 1000));
    printf("500 peso bill = %d = Php %d.00\n",
    five_hundred, calculateProduct(five_hundred, 500));
    printf("100 peso bill = %d = Php %d.00\n",
    one_hundred, calculateProduct(one_hundred, 100));
    printf("20 peso bill = %d = Php %d.00\n",
    twenty, calculateProduct(twenty, 20));
    printf("5 peso coin = %d = Php %d.00\n",
    five, calculateProduct(five, 5));
    printf("1 peso coin = %d = Php %d.00\n",
    one,  calculateProduct(one, 1));

    /* prints the total sum of the converted denominations */
    printf("\nTOTAL: Php %d.00\n", sum);

    system("pause");
    return 0;
}
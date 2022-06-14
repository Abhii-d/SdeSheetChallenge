/*Problem Statement
Dora, the explorer, visits India and decides to try the famous Indian food. However, the restaurant accepts only Indian currency i.e. [1, 2, 5, 10, 20, 50, 100, 500, 1000] valued coins.
So, Dora goes to a bank that has an infinite supply of each of the denominations to make a change for a given ‘Amount’ of money. As a cashier at the bank, your task is to provide Dora the minimum number of coins that add up to the given ‘Amount’.*/


int findMinimumCoins(int amount) 
{
    // Write your code here
    int minimun_coins=0;
    while(amount){
        if(amount>=1000){
            minimun_coins += amount/1000;
            amount=amount%1000;
        }
        if(amount >=500){
            minimun_coins += amount/500;
            amount=amount%500;
        }
        if(amount >=100){
            minimun_coins += amount/100;
            amount=amount%100;
        }
        if(amount >=50){
            minimun_coins += amount/50;
            amount=amount%50;
        }
        if(amount >=20){
            minimun_coins += amount/20;
            amount=amount%20;
        }
        if(amount >=10){
            minimun_coins += amount/10;
            amount=amount%10;
        }
        if(amount >=5){
            minimun_coins += amount/5;
            amount=amount%5;
        }
        if(amount >=2){
            minimun_coins += amount/2;
            amount=amount%2;
        }
        if(amount >=1){
            minimun_coins += amount/1;
            amount=amount%1;
        }
        
    }
    return minimun_coins;
}

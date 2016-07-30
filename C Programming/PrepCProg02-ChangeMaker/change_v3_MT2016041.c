#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define INFINITY 99999

int min(int x, int y);
int dp_calculate_change(int amount, int no_of_denom, int* denomination, int* min_array);

int min(int x, int y) {
    if(x <= y)
        return x;
    else
        return y;
}
int dp_calculate_change(int amount, int no_of_denom, int* denomination, int* min_array) {
    int table[amount+1][no_of_denom];
    
    int x = 0, y = 0;
    int min_val = INFINITY;
    
    for(int i = 0; i < no_of_denom; i++)
        table[0][i] = 0;  // when sum = 0
    
    for(int i = 1; i < (amount+1); i++)
        for(int j = 0; j < no_of_denom; j++)
            table[i][j] = INFINITY;
    min_array[0] = 0;
    
    for(int i = 1; i < (amount+1); i++) {
        min_val = INFINITY;
        for(int j = 0; j < no_of_denom; j++) {
            // if coin is not included
            if((j-1) >= 0)
                x = table[i][j-1];
            else
                x = INFINITY;
           
            // if coin is included
            if(denomination[j] <= i)
                y = table[i-denomination[j]][j] + 1;
            else
                y = INFINITY;
            table[i][j] = min(x,y);
            if(table[i][j] < min_val) {
                min_val = table[i][j];
                min_array[i] = j;
            }
        }
    }
    /*for(int i = 0; i < (amount+1); i++) {
        for(int j = 0; j < no_of_denom; j++) {
            printf("%d\t", table[i][j]);
        }
        printf("\n");
    }*/
    return (table[amount][no_of_denom-1]);
}

int main() {
    
    int no_of_note_coin = 0;
    int m = 0, n = 0;
    int i = 0, j = 0;
    int denom_used, coins_of_denom, amt, first = 0;
    // Reading M and N:
    scanf("%d %d", &m, &n);
    int amount[n];
    int denomination[m];
    int asc_denomination[m];
    
    // Reading denominations:
    for(i = 0; i < m; i++)
        scanf("%d", &denomination[i]);
    
    // Rearranging the denominations in ascending order:
    i = 0; j = (m-1);
    while(i < m) {
        asc_denomination[i] = denomination[j];
        i++;
        j--;
    }
    
    // Reading the amounts:
    for(i = 0; i < n; i++)
        scanf("%d", &amount[i]);

    // Printing the initial denominations
    for(i = 0; i < m; i++) {
        if(i == (m-1))
            printf("%d",denomination[i]);
        else
            printf("%d ",denomination[i]);    
    }
    printf("\n");
    
    // Read the amount for which change has to be dispensed   
    for(i = 0; i < n; i++) {
        int min_array[amount[i]+1];
        // Dynamic Programming Algorithm: 
        // Create a fill a table of size (amount[i]+1) X m and get the last value of the table as the result
        no_of_note_coin = dp_calculate_change(amount[i], m, asc_denomination, min_array);  
        //printf("Min no of coins: %d\n", no_of_note_coin);   
        amt = amount[i];
        first = 1;
        while(amt != 0) {
            coins_of_denom = 0;
            denom_used = asc_denomination[min_array[amt]];
            //printf("denom: %d\n", denom_used);
            while((amt >= denom_used) && (denom_used == asc_denomination[min_array[amt]])) {
                coins_of_denom++;
                amt = amt - denom_used;
            }
            if(first == 1) {
                first = 0;
                printf("%d:%d", denom_used, coins_of_denom);
            }
            else
                printf(",%d:%d", denom_used, coins_of_denom);
        }
        
        printf("\n");
    }
    return 0;
}
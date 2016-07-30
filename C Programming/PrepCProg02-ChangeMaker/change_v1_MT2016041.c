#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main() {
    char denom_str[30];
    int denomination[10] = {0};
    char temp[4];
    int iterator = 0;
    int temp_iter, denom_iter = 0;
    int no_of_denominations = 0;
    int amount = 0, no_of_note_coin = 0;
    
    // Reading denominations:
    scanf("%s", denom_str);
    
    // Split the comma separated list into individual values
    while(denom_str[iterator] != '\0') {
        
        temp_iter = 0;
        while(denom_str[iterator] != ',' && denom_str[iterator] != '\0') {
            temp[temp_iter++] = denom_str[iterator++];
        }
        temp[temp_iter] = '\0';
        denomination[denom_iter++] = atoi(temp);
        iterator++;
        no_of_denominations++;
    }
    
    // Read the amount for which change has to be dispensed   
    for(scanf("%d", &amount); amount != -1; scanf("%d", &amount)) {
        // Greedy Algorithm: 
        /* Find the largest denomination of note/coin which is not greater than the 
        remaining amount for which change is to be dispensed*/
        for(iterator = 0; iterator < no_of_denominations; iterator++) {
            no_of_note_coin = 0;
            while(denomination[iterator] <= amount) {
                no_of_note_coin++;
                amount -= denomination[iterator];
            }
            if(no_of_note_coin != 0)
                printf("%d:%d,", denomination[iterator], no_of_note_coin);
        }
        printf("\b \n");
    }
    
    return 0;
}
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char* itoa(int number){
    int i, rem, len = 0, n;
    char* str;
    n = number;
    if(number == 0)
        return "0";
    while (n != 0) {
        len++;
        n /= 10;
    }
    
    str = (char*) malloc(sizeof(char) * len);
    
    for (i = 0; i < len; i++) {
        rem = number % 10;
        number = number / 10;
        str[len - (i + 1)] = rem + '0';
    }
    str[len] = '\0';
    return str;
}
int main() {
    char denom_str[30];
    int denomination[10] = {0};
    int available[10] = {0};
    char temp[4], change_result[50], available_result[50], temp_str[10];
    int iterator = 0;
    int temp_iter, denom_iter = 0;
    int no_of_denominations = 0;
    int amount = 0, no_of_note_coin = 0;
    
    // Reading denominations:
    scanf("%s", denom_str);
    
    // Split the comma separated list into individual values
    while(denom_str[iterator] != '\0') {
        temp_iter = 0;
        while(denom_str[iterator] != ':' && denom_str[iterator] != '\0') {
            temp[temp_iter++] = denom_str[iterator++];
        }
        temp[temp_iter] = '\0';
        denomination[denom_iter] = atoi(temp);
        no_of_denominations++;
        iterator++;
        temp_iter = 0;
        while(denom_str[iterator] != ',' && denom_str[iterator] != '\0') {
            temp[temp_iter++] = denom_str[iterator++];
        }
        temp[temp_iter] = '\0';
        available[denom_iter] = atoi(temp);
        iterator++;
        denom_iter++;
    }
    //Read the amount:
    for(int i = 0; i < n; i++) {
        scanf("%d", &amount[i]);
    }
    // Read the amount for which change has to be dispensed   
    for(int i = 0; i < n; i++) {
        strcpy(change_result, "");
        strcpy(available_result, "");
        
        // Greedy Algorithm: 
        /*Find the largest denomination of note/coin which is not greater than the 
        remaining amount for which change is to be dispensed*/
        for(iterator = 0; iterator < no_of_denominations; iterator++) {
            no_of_note_coin = 0;
            while(denomination[iterator] <= amount) {
                if(available[iterator] != 0) {
                    no_of_note_coin++;
                    amount -= denomination[iterator];
                    available[iterator] -= 1;
                }
                else
                    break;
            }
            strcpy(temp_str, "");
            
            if(no_of_note_coin != 0) {
                strcpy(temp_str, itoa(denomination[iterator]));
                strcat(temp_str, ":");
                strcat(change_result, temp_str);
                strcat(change_result, itoa(no_of_note_coin));
                strcat(change_result, ",");
            }
            
        }
        for(iterator = 0; iterator < no_of_denominations; iterator++) {
            // Available coins after change dispensing:
                strcat(available_result, itoa(denomination[iterator]));
                strcat(available_result, ":");
                strcat(available_result, itoa(available[iterator]));
                strcat(available_result, ",");   
        }
        printf("%s\b \n%s\b \n", available_result, change_result);
    }
    
    return 0;
}
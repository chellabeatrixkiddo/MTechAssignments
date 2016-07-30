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
    char denom_str[100];
    char temp[10], change_result[50], available_result[50], temp_str[10];
    int iterator = 0;
    int temp_iter, denom_iter = 0;
    int no_of_denominations = 0;
    int amount = 0, no_of_note_coin = 0;
    int m, n;
   
    // Reading M and N:
    printf("M and N:\n");
    scanf("%d %d", &m, &n);
    
    int inpamt[n];
    int available[m];
    int denomination[m];
    
    printf("Input Denominations:\n");
    // Reading denominations:
    scanf ("%[^\n]%*c", denom_str);
    
    //for(int i = 0; i < m; i++) {
    // Split the space separated list into individual values
        while(denom_str[iterator] != '\0') {
            temp_iter = 0;
            while(denom_str[iterator] != ':' && denom_str[iterator] != '\0') {
                temp[temp_iter++] = denom_str[iterator++];
            }
            temp[temp_iter] = '\0';
            denomination[denom_iter] = atoi(temp);
            iterator++;
            temp_iter = 0;
            while(denom_str[iterator] != ' ' && denom_str[iterator] != '\0') {
                temp[temp_iter++] = denom_str[iterator++];
            }
            temp[temp_iter] = '\0';
            available[denom_iter] = atoi(temp);
            iterator++;
            denom_iter++;
        }
        
    //}
    for(int i = 0; i < m; i++)
        printf("Denom: %d : Avail: %d ", denomination[i], available[i]);
    printf("\n");
    printf(
    for(int i = 0; i < n; i++) {
        scanf("%d", &inpamt[i]);
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
        printf("%s\n%s\n", available_result, change_result);
    }
    
    return 0;
}
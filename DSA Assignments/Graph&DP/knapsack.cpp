/**
*	0/1 Knapsack - Dynamic Programming Algorithm to find Maximum Profit obtainable in a 0/1 Knapsack Problem
*
*	Code written by: Chellapriyadharshini.M. (MT2016041)
**/
#include<iostream>
 
using namespace std;

int max(int a, int b) { return (a > b)? a : b; }
 
int knapSack(int W, int wt[], int val[], int n) {
   int i, w;
   int K[n+1][W+1];
 
   for (i = 0; i <= n; i++) {
       for (w = 0; w <= W; w++) {
           if (i==0 || w==0)
               K[i][w] = 0;
           else if (wt[i-1] <= w)
                 K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]],  K[i-1][w]);
           else
                 K[i][w] = K[i-1][w];
       }
   }
 
   return K[n][W];
}
 
int main() {
	int n;
    int  W;
    
    cout << "Enter the Capacity of the Knapsack: ";
    cin >> W;
    cout << "Enter the No. of Items available: ";
    cin >> n;
    
    int val[n];
    int wt[n];
    
    cout << "Enter the weight of each item and its value: \n";
    for(int i = 0; i < n; i++) {
    	cout << "Item: " << i << " : ";
    	cin >> wt[i] >> val[i];
    }
    
    cout << "Maximum Total Value in the Knapsack: " << knapSack(W, wt, val, n) << "\n";
    return 0;
}
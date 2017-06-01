/**
*	Subset Sum - Dynamic Programming Algorithm to find if a Subset with a given Sum exists in the given set
*
*	Code written by: Chellapriyadharshini.M. (MT2016041)
**/

#include <iostream>
using namespace std;

bool isSubsetSum(int set[], int n, int sum) {
   if (sum == 0)
     return true;
   if (n == 0 && sum != 0)
     return false;
 
   if (set[n-1] > sum)
     return isSubsetSum(set, n-1, sum);

   return isSubsetSum(set, n-1, sum) || 
                        isSubsetSum(set, n-1, sum-set[n-1]);
}
 
int main() {
	int n, sum;
	cout << "Enter the number of elements in the Set: ";
  	cin >> n;
  	int set[n];
  	cout << "Enter the elements of the Set: \n";
	for(int i = 0; i < n; i++) {
		cout << "Element: " << i << " : ";
		cin >> set[i];
	}
	cout << "Enter the Subset Sum: ";
  	cin >> sum;
  
  	if (isSubsetSum(set, n, sum) == true)
  		cout << "A subset with given sum exists\n";
	else
    	cout << "No subset with given sum exists\n";
	return 0;
}
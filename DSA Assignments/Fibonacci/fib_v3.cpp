/**
*	Find the Fibonacci(n)%m - when 'n' is represented in Decimal and converted to Binary
*
*	n is read from file: input_3.txt
*
*	Code written by: Chellapriyadharshini.M. (MT2016041)
**/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>

void decimal_to_binary(long long int[], long long int, std::vector<bool>&);
long long int fibonacci_mod_m(std::vector<bool>&, long long int);
void A_power_n(long long int[2][2], std::vector<bool>&, long long int, long long int[2][2]);
bool is_zero_bool(std::vector<bool>);
bool is_zero_decimal(long long int[], long long int);
void Matrix_Multiply_2x2(long long int[2][2], long long int[2][2], long long int);
void Divide_by_2(long long int[], long long int);

// Function to convert decimal to binary
void decimal_to_binary(long long int n_decimal[], long long int size, std::vector<bool>& n_array) {
	int r;
	while(!is_zero_decimal(n_decimal, size)) {
		r = n_decimal[size-1] % 2;
		n_array.push_back(r);
		Divide_by_2(n_decimal, size);
	}
	std::reverse(n_array.begin(), n_array.end());
	/*std::cout << "Inside D to B: ";
	for(int i = 0; i < n_array.size(); i++)
		std::cout << n_array[i];
	std::cout << std::endl;*/
}

// Function to calculate Fibonacci(n)%m
long long int fibonacci_mod_m(std::vector<bool>& n_array, long long int m) {
	long long int A[2][2] = {{1, 1}, {1, 0}};
	long long int result[2][2] = {{1, 0}, {0, 1}};
	// calculate A^n
	A_power_n(A, n_array, m, result);
	return result[1][0];
}

// Function to calculate A^n
void A_power_n(long long int A[2][2], std::vector<bool>& n_array, long long int m, long long int result[2][2]) {
	while(!is_zero_bool(n_array)) {
		if(n_array[n_array.size()-1] != 0)
			Matrix_Multiply_2x2(result, A, m);
		Matrix_Multiply_2x2(A, A, m);
		n_array.pop_back();
	}
}

// Function to check if N is 0
bool is_zero_bool(std::vector<bool> n_array) {
	long long int i;
	for(i = 0; i < n_array.size(); i++) {
		if(n_array[i] != 0)
			return false;
	}
	return true;
}

// Function to check if N is 0
bool is_zero_decimal(long long int n_decimal[], long long int size) {
	long long int i;
	for(i = 0; i < size; i++) {
		if(n_decimal[i] != 0)
			return false;
	}
	return true;
}

// Function to do Matrix Multiplication of two 2x2 matrices M1 = M1 X M2
void Matrix_Multiply_2x2(long long int M1[2][2], long long int M2[2][2], long long int m) {
	long long int i, j;
	long long int result[2][2] = {0};

	result[0][0] = ((M1[0][0] * M2[0][0]) + (M1[0][1] * M2[1][0])) % m;
	result[0][1] = ((M1[0][0] * M2[0][1]) + (M1[0][1] * M2[1][1])) % m;
	result[1][0] = ((M1[1][0] * M2[0][0]) + (M1[1][1] * M2[1][0])) % m;
	result[1][1] = ((M1[1][0] * M2[0][1]) + (M1[1][1] * M2[1][1])) % m;
	
	// Copy the result back to M1
	for(i = 0; i < 2; i++)
		for(j = 0; j < 2; j++)
			M1[i][j] = result[i][j];
}

// Function to do Division by 2
void Divide_by_2(long long int n_decimal[], long long int size) {
	long long int i, r = 0;
	for(i = 0; i < size; i++) {
		n_decimal[i] = (r*10) + n_decimal[i];
		r = n_decimal[i]%2;
		n_decimal[i] = n_decimal[i]/2;
	}
}

int main() {
	
	long long int i, digit, result, size;
	long long int n_decimal[100000];
	std::vector<bool> n_array;
	long long int m;
	char digit_char;
	std::string file_name = "input_3.txt";
	
	//size = 3322000;
	size = sizeof(n_decimal)/sizeof(long long int);
	
	std::srand(static_cast<unsigned int>(time(0)));
	
	// Generate Input 'n' and store it in a file
	std::ofstream fout(file_name);
	
	for(i = 0; i < size; i++) {
		digit = (std::rand()%(9 - 0 + 1)) + 0;
		fout << digit;
	}

	fout.close();
	
	// Generate Input 'm'
	m = (std::rand()%(1000000 - 2 + 1)) + 2;
	
	// Read the input n from file and store it in an array
	std::ifstream fin(file_name);
	
	i = 0;
	while(fin) {
		fin >> digit_char;
		if(fin.eof())
			break;
		n_decimal[i++] = digit_char - '0';
	}
	fin.close();
	
	std::cout << "size of n: "<< size << " m: " << m << std::endl;
	
	// Convert the decimal number to binary
	decimal_to_binary(n_decimal, size, n_array);
	
	// Call function to calculate F(n)%m -- (Fibonacci of n)%m
	result = fibonacci_mod_m(n_array, m);
	
	// Print the result
	std::cout << "Fibonacci: " << result << std::endl;
	
	return 0;
}
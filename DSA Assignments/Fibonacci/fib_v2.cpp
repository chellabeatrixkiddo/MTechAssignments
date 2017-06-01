/**
*	Find the Fibonacci(n)%m - when 'n' is represented in Binary
*
*	n is read from file: input_2.txt
*
*	Code written by: Chellapriyadharshini.M. (MT2016041)
**/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>

long long int fibonacci_mod_m(std::vector<bool>, long long int);
void A_power_n(long long int[2][2], std::vector<bool>, long long int, long long int[2][2]);
bool is_zero(std::vector<bool>);
void Matrix_Multiply_2x2(long long int[2][2], long long int[2][2], long long int);

// Function to calculate Fibonacci(n)%m
long long int fibonacci_mod_m(std::vector<bool> n_array, long long int m) {
	long long int A[2][2] = {{1, 1}, {1, 0}};
	long long int result[2][2] = {{1, 0}, {0, 1}};
	// calculate A^n
	A_power_n(A, n_array, m, result);
	return result[1][0];
}

// Function to calculate A^n
void A_power_n(long long int A[2][2], std::vector<bool> n_array, long long int m, long long int result[2][2]) {
	while(!is_zero(n_array)) {
		if(n_array[n_array.size()-1] != 0)
			Matrix_Multiply_2x2(result, A, m);
		Matrix_Multiply_2x2(A, A, m);
		n_array.pop_back();
	}
}

// Function to check if N is 0
bool is_zero(std::vector<bool> n_array) {
	long long int i;
	for(i = 0; i < n_array.size(); i++) {
		if(n_array[i] != 0)
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

int main() {
	
	long long int i, digit, result, size;
	std::vector<bool> n_array;
	long long int m;
	char digit_char;
	std::string file_name = "input_2.txt";
	
	size = 3322000;
	
	std::srand(static_cast<unsigned int>(time(0)));
	
	// Generate Input 'n' and store it in a file
	std::ofstream fout(file_name);
	
	for(i = 0; i < size; i++) {
		digit = (std::rand()%(1 - 0 + 1)) + 0;
		fout << digit;
	}

	fout.close();
	
	// Generate Input 'm'
	m = (std::rand()%(1000000 - 2 + 1)) + 2;
	
	// Read the input n from file and store it in an array
	std::ifstream fin(file_name);
	
	while(fin) {
		fin >> digit_char;
		if(fin.eof())
			break;
		n_array.push_back(digit_char - '0');
	}
	fin.close();
	
	std::cout << "size of n: "<< size << " m: " << m << std::endl;
	
	// Call function to calculate F(n)%m -- (Fibonacci of n)%m
	result = fibonacci_mod_m(n_array, m);
	
	// Print the result
	std::cout << "Fibonacci: " << result << std::endl;
	
	return 0;
}
/**
*	Find the Fibonacci(n)%m - when 'n' is represented in Decimal - Divide by 10
*
*	n is read from file: input_1.txt
*
*	Code written by: Chellapriyadharshini.M. (MT2016041)
**/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <vector>

long long int fibonacci_mod_m(std::vector<long long int>, long long int);
void A_power_n(long long int[2][2], std::vector<long long int>, long long int, long long int[2][2]);
bool is_zero(std::vector<long long int>);
void Matrix_pth_power(long long int[2][2], long long int, long long int);
void Matrix_Multiply_2x2(long long int[2][2], long long int[2][2], long long int);
void Divide_by_10(std::vector<long long int>);

// Function to calculate Fibonacci(n)%m
long long int fibonacci_mod_m(std::vector<long long int> n_array, long long int m) {
	long long int A[2][2] = {{1, 1}, {1, 0}};
	long long int y[2][2] = {{1, 0}, {0, 1}};
	// calculate A^n
	A_power_n(A, n_array, m, y);
	return y[1][0];
}

// Function to calculate A^n
void A_power_n(long long int A[2][2], std::vector<long long int> n_array, long long int m, long long int y[2][2]) {
	while(!is_zero(n_array)) {
		Matrix_pth_power(A, n_array[n_array.size()-1], m);
		Matrix_Multiply_2x2(y, A, m);
		Matrix_pth_power(A, 10, m);
		n_array.pop_back();
	}
}

// Function to check if N is 0
bool is_zero(std::vector<long long int> n_array) {
	long long int i;
	for(i = 0; i < n_array.size(); i++) {
		if(n_array[i] != 0)
			return false;
	}
	return true;
}

// Function to calculate the pth power of a Matrix. 0 <= p <= 10 . Time Complexity = O(Log p)
void Matrix_pth_power(long long int M[2][2], long long int p, long long int m) {
	if(p == 0) {
		M[0][0] = 1;
		M[0][1] = 0;
		M[1][0] = 0;
		M[1][1] = 1;
		return;
	}
	long long int z[2][2] = {{1, 0}, {0, 1}};
	int i , j;
	while(p > 0) {
		if((p % 2) != 0)
			Matrix_Multiply_2x2(z, M, m);
		Matrix_Multiply_2x2(M, M, m);
		p = p / 2;
	}
	// Copy the result into M
	for(i = 0; i < 2; i++)
		for(j = 0; j < 2; j++)
			M[i][j] = z[i][j];
	return;
}

// Function to do Matrix Multiplication of two 2x2 matrices M1 = M1 X M2. Time Complexity = O(1)
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
	std::vector<long long int> n_array;
	long long int m;
	char digit_char;
	std::string file_name = "input_4.txt";
	
	size = 100000;
	
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
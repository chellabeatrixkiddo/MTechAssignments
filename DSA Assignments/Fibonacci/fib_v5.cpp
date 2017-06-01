/**
*	Find the Fibonacci(n)%m - Periodic Sequence
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

long long int fibonacci_mod_m(long long int[], long long int, long long int);
long long int Modulo(long long int[], long long int, long long int);

// Function to calculate Fibonacci(n)%m
long long int fibonacci_mod_m(long long int n_array[], long long int m, long long int size) {
	long long int six_m, i, a, b, p, r;
	std::vector<long long int> fib_array;
	
	// Find 6*m
	six_m = 6 * m;
	// Calculate F(i) for i = 0 to 6m and store it in a fib_array. If seq starts to repeat at 'p' save p and break
	for(i = 1; (i+1) <= six_m; i = i + 2) {
		if(i == 1) {
			a = 1;
			b = 1;
			fib_array.push_back(a);
			fib_array.push_back(b);
			fib_array.push_back((a+b)%m);
		}
		else {
			a = (fib_array[i-1] + fib_array[i-2]) % m;
			fib_array.push_back(a);
			b = (fib_array[i] + fib_array[i-1]) % m;
			fib_array.push_back(b);
			// If the sequence starts to repeat, save 'p' and break;
			if(fib_array[i] == 0 && fib_array[i+1] == 1) {
				p = i;
				break;
			}
		}
	}
	//std::cout << "P value: " << p << std::endl;
	
	// Find (n_array mod p) as r
	r = Modulo(n_array, size, p);
	
	// Index r into the  fib_array to get F(n)
	return fib_array[r];
}

long long int Modulo(long long int n_array[], long long int size, long long int p) {
	long long int i, r = 0;
	for(i = 0; i < size; i++) {
		n_array[i] = (r*10) + n_array[i];
		r = n_array[i]%p;
		n_array[i] = n_array[i]/p;
	}
	return r;
}

int main() {
	
	long long int i, digit, result, size;
	long long int n_array[1000000];
	long long int m;
	char digit_char;
	std::string file_name = "input_5.txt";
	
	size = sizeof(n_array)/sizeof(long long int);
	
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
	//m = 3;
	
	// Read the input n from file and store it in an array
	std::ifstream fin(file_name);
	i = 0;
	while(fin) {
		fin >> digit_char;
		if(fin.eof())
			break;
		n_array[i++] = digit_char - '0';
	}
	fin.close();
	
	std::cout << "size of n: "<< size << " m: " << m << std::endl;
	
	// Call function to calculate F(n)%m -- (Fibonacci of n)%m
	result = fibonacci_mod_m(n_array, m, size);
	
	// Print the result
	std::cout << "Fibonacci: " << result << std::endl;
	
	return 0;
}
/**
*	Find the K smallest elements in an Array - Using Max Heap
*	
*	Input read from file: input_arr_k.txt
*	Output written to file: output_arr_k.txt
*
*	Code written by: Chellapriyadharshini.M. (MT2016041)
**/

#define K 10000
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <algorithm>
#include <ctime>

int A[K+1]; // heap
int heap_size; 

void max_heapify(int[], int);
void build_max_heap(int[], int);
void delete_max(int[]);
void insert_into_heap(int[], int);

void max_heapify(int A[], int index) {
	int left = (2 * index), right = ((2 * index) + 1);
	int largest;
	if(left <= heap_size && A[left] > A[index])
		largest = left;
	else
		largest = index;
	if(right <= heap_size && A[right] > A[largest])
		largest = right;
	if(largest != index) {
		std::swap(A[index], A[largest]);
		max_heapify(A, largest);
	}
}
void build_max_heap(int A[], int length) {
	int i;
	heap_size = length;
	for(i = (length/2); i >= 1; i--) {
		max_heapify(A, i);
	}
}

void delete_max(int A[]) {
	int max;
	max = A[1];
	A[1] = A[heap_size];
	heap_size = heap_size - 1;
	max_heapify(A, 1);
}

void insert_into_heap(int A[], int element) {
	int index = heap_size + 1;
	A[index] = element;
	heap_size = heap_size + 1;
	while(index > 1 && (A[index/2] < A[index])) {
		std::swap(A[index/2], A[index]);
		index = index/2;
	}
}

int main() {
	
	long int n = 100000000;
	int max, kplus1, i, number, noOfElements;
	std::string file_name = "input_arr_k.txt";
	std::string out_file = "output_arr_k.txt";
	
	std::srand(static_cast<unsigned int>(time(0)));
	
	// Generate Input array of length 'n' and store it in a file
	std::ofstream fout(file_name);
	
	for(i = 1; i <= n; i++) {
		number = (std::rand()%(100 - 1 + 1)) + 1;
		fout << number;
		fout << std::endl;
	}

	fout.close();

	// Read the first k numbers of the n numbers from file and store it in an array of size k
	std::ifstream fin(file_name);
	
	for(i = 1; i <= K; i++) {
		fin >> A[i];
	}
	
	// create a max heap out of the array
	build_max_heap(A, K);
	
	noOfElements = i;
	
	while(noOfElements <= n) {
		// take the max element from the heap
		max = A[1];

		// take the (k+1)th element from the file
		fin >> kplus1;
		
		// compare max with the (k+1)th element
		if(max > kplus1) {
			
			// delete the max element from heap
			delete_max(A);
		
			// insert kplus1 into the heap
			insert_into_heap(A, kplus1);
		}
		noOfElements++;
	}
	
	fin.close();
	
	// Store the output in a file
	std::ofstream fout1(out_file);
	for(i = 1; i <= K; i++)
		fout1 << A[i] << " ";
	
	fout1.close();
	
	std::cout << "The first " << K << " smallest elements are stored in the file: " << out_file << std::endl;
	
	return 0;
}
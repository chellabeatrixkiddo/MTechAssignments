/**
*	Randomized Find Rank Program
*
*	On cmd line, provide: Rank whose element is required
*	Array is read from file: input_arr_rand.txt
*
*	Code written by: Chellapriyadharshini.M. (MT2016041)
**/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <algorithm>
#include <ctime>

int partition(int[], int, int, int);
int choose_random_pivot(int[], int, int);
int find_rank_randomized(int[], int, int, int, int);

int partition(int A[], int p, int r, int pivot_index) {
	int i = p - 1, j, temp, pivot;
	std::swap(A[r], A[pivot_index]);
	pivot = A[r];
	
	for(j = p; j <= r - 1; j++) {
		if(A[j] <= pivot) {
			i = i + 1;
			std::swap(A[i], A[j]);
		}
	}
	std::swap(A[i+1], A[r]);
	return (i + 1);
}

int choose_random_pivot(int A[], int p, int r) {
	int random_pivot_index;
	random_pivot_index = (std::rand()%(r - p + 1)) + p;
	return random_pivot_index;
}

int find_rank_randomized(int A[], int length, int rank, int p, int r) {
	if(length == 1)
		return A[p];
	
	int pivot_index, rank_pivot;
	
	// choose a pivot from A at random and return its index
	pivot_index = choose_random_pivot(A, p, r);
	
	// Partition A around the pivot
	rank_pivot = partition(A, p, r, pivot_index);
	rank_pivot = rank_pivot - p + 1;

	if(rank_pivot == rank)
		return A[(p+rank_pivot-1)];
	else if(rank_pivot > rank) {
		int part_length = rank_pivot - 1;
		return find_rank_randomized(A, part_length, rank, p, (p+part_length-1));
	}
	else if(rank_pivot < rank) {
		int part_length = length - rank_pivot;
		return find_rank_randomized(A, part_length, rank-rank_pivot, (rank_pivot+p-1)+1, (rank_pivot+p+part_length)-1);
	}
}

int main(int argc, char**argv) {
	
	int element, rank, number, i;
	int arr_length = 1000000;
	int A[arr_length+1];
	std::string file_name = "input_arr_rand.txt";
	
	std::srand(static_cast<unsigned int>(time(0)));
	
	// Generate Input array of length 'n' and store it in a file
	std::ofstream fout(file_name);
	
	for(i = 1; i <= arr_length; i++) {
		number = (std::rand()%(1000000 - 1 + 1)) + 1;
		fout << number;
		fout << std::endl;
	}

	fout.close();

	// Read the input n from file and store it in an array
	std::ifstream fin(file_name);
	
	for(i = 1; i <= arr_length; i++) {
		fin >> A[i];
	}
	fin.close();
	
	rank = atoi(argv[1]);
	element = find_rank_randomized(A, arr_length, (arr_length-rank+1), 1, arr_length);
	
	std::cout << "Element whose Rank is " << rank << ": " << element << std::endl;
	return 0;
}
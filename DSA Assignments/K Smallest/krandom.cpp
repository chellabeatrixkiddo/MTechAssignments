/**
*	Find the K smallest elements in an Array - Using Randomized Find Rank
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

int orig_rank;

void merge(int[], int, int, int);
void merge_sort(int[], int, int);
int partition(int[], int, int, int);
int find_rank_deterministic(int[], int, int, int, int);

void merge(int arr[],int min,int mid,int max) {
	int tmp[(2*K)];
	int i,j,k,m; 
	j=min;
	m=mid+1;
	for(i=min; j<=mid && m<=max ; i++) {
		if(arr[j]<=arr[m])
        	tmp[i]=arr[j++];
    	else
        	tmp[i]=arr[m++];
  	}
	if(j>mid) {
    	for(k=m; k<=max; k++)
        	tmp[i++]=arr[k];
  	}
	else {
    	for(k=j; k<=mid; k++)
        	tmp[i++]=arr[k];
  	}
	for(k=min; k<=max; k++)
    	arr[k]=tmp[k];
}

void merge_sort(int arr[],int min,int max) {
	int mid;
	if(min<max) {
		mid=(min+max)/2;
   		merge_sort(arr,min,mid);
   		merge_sort(arr,mid+1,max);
   		merge(arr,min,mid,max);
 	}
}

int partition(int A[], int p, int r, int pivot_index) {
	int i = p - 1, j, temp, pivot;
	std::swap(A[r], A[pivot_index]);
	pivot = A[r];
	
	//partition around the pivot
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
	
	orig_rank = rank_pivot;
	rank_pivot = rank_pivot - p + 1;

	if(rank_pivot == rank)
		return orig_rank;
	else if(rank_pivot > rank)
		return orig_rank;
	else if(rank_pivot < rank) {
		int part_length = length - rank_pivot;
		return find_rank_randomized(A, part_length, rank-rank_pivot, (rank_pivot+p-1)+1, (rank_pivot+p+part_length)-1);
	}
}

int main() {

	long int n = 1000000;
	int A[2*K+1];
	int max, kplus1, i, number, noOfElements, rpivot_index, j;
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

	// Read the first 2k numbers of the n numbers from file and store it in an array of size 2k
	std::ifstream fin(file_name);
	
	for(i = 1; i <= (2*K); i++)
		fin >> A[i];
	
	noOfElements = i;
	
	while(1) {
		
		// Find a random pivot of 2k numbers
		rpivot_index = find_rank_randomized(A, (2*K), K, 1, (2*K));
	
		// Numbers to the right of the rpivot_index can be discarded. Overwrite the ((2*K)-rpivot_index) numbers on the right with the next (n-rpivot_index) numbers.
		j = rpivot_index+1;
		if(noOfElements > n)
			break;
		while(j <= (2*K) && noOfElements <= n) {
			fin >> A[j++];
			noOfElements++;
		}	
	}
	
	fin.close();
	
	// sort the elements to the left of the final rpivot_index
	merge_sort(A, 1, rpivot_index);
	
	// Store the output in a file
	std::ofstream fout1(out_file);
	for(i = 1; i <= K; i++)
		fout1 << A[i] << " ";
	
	fout1.close();
	
	std::cout << "The first " << K << " smallest elements are stored in the file: " << out_file << std::endl;
	
	return 0;
}
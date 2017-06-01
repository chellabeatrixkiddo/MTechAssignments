/**
*	Deterministic Find Rank Program
*
*	On cmd line, provide: Rank whose element is required
*	Array is read from file: input_arr_det.txt
*
*	Code written by: Chellapriyadharshini.M. (MT2016041)
**/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <algorithm>
#include <ctime>

int arr_length = 1000000;
int orig_length;

void merge(int[], int, int, int);
void merge_sort(int[], int, int);
int partition(int[], int, int, int);
int find_rank_deterministic(int[], int, int, int, int);

void merge(int arr[],int min,int mid,int max) {
	int tmp[5];
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

int partition(int A[], int p, int r, int pivot) {
	int i = p - 1, j, temp, pivot_index;
	
	// scan through the array to find the pivots position
	for(int k = p; k <= r; k++) {
		if(A[k] == pivot) {
			pivot_index = k;
			break;
		}
	}
	
	//exchange pivot with the last element
	std::swap(A[r], A[pivot_index]);
	
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

int find_rank_deterministic(int A[], int length, int rank, int p, int r) {
	int pivot, rank_pivot, i, j, C_index;
	int B[5], C[(length/5)+2];
	
	if(length == 1)
		return A[p];
	
	// Divide A into groups of 5, sort each group using Merge Sort and copy n/5 medians into array C
	C_index = 1;
	for(i = 1; i <= (length/5); i++) {
		for(j = 1; j <= 5; j++)
			B[j] = A[(p-1)+((i-1)*5)+j];
		
		// Sort B array using Merge Sort
		merge_sort(B, 1, 5);
		
		// Store the median of B into the array C
		C[C_index++] = B[3]; 
	}
	if(length%5 != 0) {
		for(j = 1; j <= (length%5); j++)
			B[j] = A[(p-1)+((length/5)*5)+j];
		merge_sort(B, 1, (j-1));
		if((j-1) > 1)
			C[C_index++] = B[(j-1)/2];
		else
			C[C_index++] = B[(j-1)];
		
	}
	
	// choose a det pivot (median)
	pivot = find_rank_deterministic(C, C_index-1, (C_index-1)/2, 1, C_index-1);

	if(length != 1 && length != orig_length)
		return pivot;
	
	// Partition A around the pivot
	rank_pivot = partition(A, p, r, pivot);
	rank_pivot = rank_pivot - p + 1;
	
	if(rank_pivot == rank)
		return A[(p+rank_pivot-1)];
	else if(rank_pivot > rank) {
		int part_length = rank_pivot - 1;
		orig_length = part_length;
		return find_rank_deterministic(A, part_length, rank, p, (p+part_length-1));
	}
	else if(rank_pivot < rank) {
		int part_length = length - rank_pivot;
		orig_length = part_length;
		return find_rank_deterministic(A, part_length, rank-rank_pivot, (rank_pivot+p-1)+1, (rank_pivot+p+part_length)-1);
	}
}

int main(int argc, char**argv) {
	
	int element, rank, number, i;
	
	int A[arr_length+1];
	std::string file_name = "input_arr_det.txt";
	
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
	orig_length = arr_length;
	element = find_rank_deterministic(A, arr_length, (arr_length-rank+1), 1, arr_length);
	
	std::cout << "Element whose Rank is " << rank << ": " << element << std::endl;
	return 0;
}
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
void print_vec(vector<double> vec, const int n);
void print_vec(vector<int> vec, const int n);

int main(void){
	const int N = 6;
	double A[N*N] = { 2, 1, 0, 0, 0, 0,
										1, 2, 1, 0, 0, 0,
										0, 1, 2, 1, 0, 0,
										0, 0, 1, 2, 1, 0,
										0, 0, 0, 1, 2, 1,
										0, 0, 0, 0, 1, 2 };
	int nnz = 0;
	for(int i = 0; i < N*N; ++i){
		if(A[i] != 0.0){
			nnz++;
		}
	}

	vector<double> val(nnz);
	vector<int>		 col_ind(nnz);
	int cnt_nnz = 0;
	for(int i = 0; i < N; ++i){
		//int nnz_per_row = 0;
		for(int j = 0; j < N; ++j){
			if(A[i*N+j] != 0.0){
				col_ind[cnt_nnz] = j;
				val[cnt_nnz]     = A[i*N+j];
				cnt_nnz++;
			}
		}
	}
	vector<double> row_ptr(N+1);
	row_ptr[0] = 0;
	for(int i = 0; i < N; ++i){
		int nnz_per_row = 0;
		for(int j = 0; j < N; ++j){
			if(A[i*N+j] != 0.0){
				nnz_per_row++;
			}
		}
		row_ptr[i+1] = row_ptr[i] + nnz_per_row;
	}
	print_vec(val, nnz);
	print_vec(col_ind, nnz);
	print_vec(row_ptr, N+1);
	return 0;
}

void print_vec(vector<double> vec, const int n)
{
	for(int i = 0; i < n; ++i){
		printf("%+f\n", vec[i]);
	}
	printf("\n");
}


void print_vec(vector<int> vec, const int n)
{
	for(int i = 0; i < n; ++i){
		printf("%d\n", vec[i]);
	}
	printf("\n");
}


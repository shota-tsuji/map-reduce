#include <cstdlib>
#include <iostream>
#include <cstdio>
using namespace std;
void print_vec(double *vec, const int n);
void print_mat(double *mat, const int n_row, const int n_col);

int main(void){
	const int N = 5;
	double a[N*N] = { 0, 1, 2, 0, 0,
										3, 2, 0, 0, 0,
										0, 0, 1, 1, 5,
										0, 0, 4, 0, 0,
										3, 0, 0, 0, 0 };
	double vec[N] = { 1, 3, 0, 2, 0 };
	double ans_vec[N] = {0};

	// count max-NNZ
	int cnt = -999;
	for(int i = 0; i < N; ++i){
		int cnt_per_row = 0;
		for(int j = 0; j < N; ++j){
			if(a[i*N+j] != 0.0){
				cnt_per_row++;
			}
		}
		if(cnt_per_row > cnt){ cnt = cnt_per_row; }
	}
	cout << "nnz_max = " << cnt << endl;
	
	// allocate 列優先
	double *val = (double*)malloc(cnt*N*sizeof(double));
	for(int i = 0; i < N; ++i){
		int nnz_per_row = 0;
		for(int j = 0; j < N; ++j){
			if(a[i*N+j] != 0.0){
				val[nnz_per_row*N+i] = a[i*N+j];
				nnz_per_row++;
			}
		}
	}
	print_mat(val, cnt, N);
	for(int i = 0; i < N; ++i){
		for(int j = 0; j < N; ++j){
			ans_vec[i] += a[i*N+j] * vec[j];
		}
	}
	print_vec(ans_vec, N);
	
	// set rowmax[]
	int *rowmax = (int*)malloc(N*sizeof(int));
	for(int i = 0; i < N; ++i){
		int nnz_per_row = 0;
		for(int j = 0; j < N; ++j){
			if(a[i*N+j] != 0.0){
				nnz_per_row++;
			}
		}
		rowmax[i] = nnz_per_row;
	}
	print_vec(rowmax, N);
	return 0;
}

void print_vec(double *vec, const int n)
{
	for(int i = 0; i < n; ++i){
		printf("%+f\n", vec[i]);
	}
	printf("\n");
}

void print_mat(double *mat, const int n_row, const int n_col)
{
	for(int i = 0; i < n_row; ++i){
		for(int j = 0; j < n_col; ++j){
			printf("%+f ", mat[i*n_col+j]);
		}
		printf("\n");
	}
}

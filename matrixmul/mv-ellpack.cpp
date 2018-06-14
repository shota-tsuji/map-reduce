#include <cstdlib>
#include <iostream>
#include <cstdio>
using namespace std;
void print_vec(double *vec, const int n);

int main(void){
	const int N = 5;
	double a[N*N] = { 0, 1, 2, 0, 0,
										3, 2, 0, 0, 0,
										0, 0, 1, 1, 5,
										0, 0, 4, 0, 0,
										3, 0, 0, 0, 0 };
	double vec[N] = { 1, 3, 0, 2, 0 };
	double ans_vec[N] = {0};
	for(int i = 0; i < N; ++i){
		for(int j = 0; j < N; ++j){
			ans_vec[i] += a[i*N+j] * vec[j];
		}
	}
	print_vec(ans_vec, N);
	return 0;
}

void print_vec(double *vec, const int n)
{
	for(int i = 0; i < n; ++i){
		printf("%+f\n", vec[i]);
	}
	printf("\n");
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARR_LENGTH 10
#define BIG_N 75

// standard fibbonacci sequence generator
int fib(int n){
	if (n <= 0){
		return 0;
	} 
	if (n == 1) return 1;
	return fib(n-2) + fib(n-1);
}

// use an array to store computed values into array
int fibMem(int n, int* memoArr){
	if (n <= 0) return 0;
	if (n == 1) return 1;
	if (memoArr[n] == 0){
		memoArr[n] = fibMem(n-2, memoArr) + fibMem(n-1, memoArr);
	} 
	return memoArr[n];
}

// populate the memo array with zeros
int* initMemo(int* memoiArr){
	
	for (int i = 0; i <= ARR_LENGTH; i++){
		memoiArr[i] = 0;
	}
	
	for (int i = 0; i <= BIG_N; i++){
		memoiArr[i] = 0;
	}
	printf("Finished initializing\n");
	return memoiArr;
}

int main(){
	clock_t start, end, startMem, endMem;
	// create array on the heap & init all zeros
	int* memoizationArr = (int*) (malloc(sizeof(int)*BIG_N));
	if (memoizationArr == 0){
		printf("No more memory in heap to allocate\n");
	}
	initMemo(memoizationArr);

	// print and check correct answer for fib function
	printf("\n Fibonnaci seqeunce\n");		
	for (int i = 0; i < ARR_LENGTH; i++){
		printf("%dth num: %d\n", i, fib(i));
	}
	// print and check answer for fib w/memoization 
	initMemo(memoizationArr);
	printf("\n Fib Memoization: \n");
	for (int i = 0; i < ARR_LENGTH; i++){
		printf("%dth num: %d\n", i, fibMem(i, memoizationArr));
	} 
	 
	// OVERFLOW
	//printf("fibMem(30, memoizationArr): %d\n", fibMem(30, memoizationArr));  
	printf("\nTime in seconds of fib calculations:\n");
	// time memoization fib sequence calculation
	//initMemo(memoizationArr);
	startMem = clock();
	int bigNseqMem = fibMem(BIG_N, memoizationArr);
	endMem = clock();
	double bigNtimeMem = ((double)(endMem - startMem))/CLOCKS_PER_SEC;
	

	// time normal fib sequence calculation
	start = clock();
	int bigNseq = fib(BIG_N);
	end = clock();
	double bigNtime = ((double)(end - start))/CLOCKS_PER_SEC;
	
	// print values and time took for each
	printf("Big N value: %d, Big N time: %f\n", bigNseq, bigNtime);
	printf("Big N value mem: %d, Big N time mem: %f\n", bigNseqMem, bigNtimeMem);
	free(memoizationArr);
	return 0;
}


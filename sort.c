#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <math.h>

/*
typedef void (*apply)(int);
void for_each(int array[], int len, apply func) {
}
*/

void int_array_output(int array[], int len) {
	for(int i = 0; i<len; i++) { printf("%d ", array[i]); }
	putchar('\n');
}

void int_array_output_partial(int array[], int len, int inc) {
	for(int i = 0; i<len; i += inc) { printf("%d ", array[i]); }
	putchar('\n');
}

void random_int_array(int array[], int len, int max) {
	srand(time(0));
	for(int i = 0; i<len; i++) { array[i] = rand() % max;}	
}

void swap(int array[], int _1, int _2) {
	int tmp = array[_1];
	array[_1] = array[_2];
	array[_2] = tmp;
}

void insert_sort(int array[], int len) {
	for(int i = 0; i < len; i++) {
		for(int j = i; j > 0; j--) {
			if(array[j] < array[j-1]) swap(array, j, j-1);
		}
	}
}

void insert_sort_partial(int array[], int len, int inc, int start) {
	for(int i = start; i < len; i += inc) {
		for(int j = i; j >= inc; j -= inc) {
			if(array[j] < array[j - inc] ) swap(array, j, j-inc);
		}
	}
}

void shell_sort(int array[], int len) {
	for(int inc = len / 2; inc >= 1; inc /= 2) {
		for(int i = 0; i < inc; i++) {
			insert_sort_partial(array, len, inc, i); 
		}
	}
}

bool assert_int_array_increasing(int array[], int len) {
	for(int i = 0; i < len; i++) {
		if(array[i] <= array[i + 1]) continue;
	}
	return true;
}

// left as possible as it could
int index_mean(int a, int b) { return (int)floor((a+b)/2.0); }

int binary_search(int array[], int len, int val) {
	if(val < array[0] || val > array[len - 1]) return -1;
	
	int left = 0, right = len - 1, idx = index_mean(left, right);
	/* todo: be with bsearch */
	while(true) {
		if(val == array[left]) return left;		
		if(val > array[idx]) { left = idx; } else { right = idx; }
		idx = index_mean(left, right);
		
		if(left == right - 1) return -1;		
	} 
	return -1;
}

bool in_array(int array[], int backup[], int len) {
	for(int i = 0; i < len; i++) {
		if(binary_search(array, len, backup[i]) < 0) return false;
	}
	return true;
}
		

int main(void) {
	int len = 50, array[len], backup[len];	
	random_int_array(array, len, 100);
	for(int i = 0; i < len; i++) { backup[i] = array[i]; }
	int_array_output(array, len);
		
	// insert_sort(array, len);
	
	shell_sort(array, len);
	int_array_output(array, len);
	
	int idx = binary_search(array, len, 10);
	printf("%d \n", idx);
	/*
	if(in_array(array, backup, len) == false) {
		printf("Fail in test \n");
	}
	*/
	if(assert_int_array_increasing(array, len) == false) {
		printf("Fail in test \n");
	}
	int a = 2, b = 3;
	printf("(%d + %d) / 2 = %d \n", a, b, (int)floor((a + b) / 2.0));
	return 0;
}
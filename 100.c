/* Alberto Amigo Alonso */

#include <stdio.h>

unsigned long cicle_len(int);

int main() {
	unsigned int in1, in2; /* The two input values */
	int i; /* Iterator */
	int min, max;
	unsigned long cicle_len_tmp; /* The cicle lenght of one iteration */
	unsigned long result; /* Number with the maximum cicle lenght */
	unsigned long next_step; /* The next number in the sequence */
	
	while (scanf("%d %d", &in1, &in2) != EOF) {
		result = 0;
		if (in1 < in2) {
			min = in1;
			max = in2;
		} else {
			min = in2;
			max = in1;
		}
		for (i = min; i <= max; i++) {
			cicle_len_tmp = cicle_len(i);
			if (cicle_len_tmp > result) 
				result = cicle_len_tmp;		
		}	

		printf("%d %d %lu\n", in1, in2, result);
	}
	return 0;
}

unsigned long cicle_len(int num) {
	unsigned long cicle_len = 1;

	while (num != 1) {
		if (num % 2 == 0)
			num /= 2;
		else
			num = 3*num+1; 
		cicle_len++;
	}

	return cicle_len;
}

/* Alberto Amigo Alonso */

#include <stdio.h>

float average(float *, int);

int main() {
	int std_num; /* Input: Number of  students */
	int i; /* Iterator */
	float expense[1000]; /* The amount of expenses of each student */
	float avg; /* The average of the expenses */
	float offset; /* Difference among the average and each expense*/
	float pos_offset, neg_offset;

	while (scanf("%d\n", &std_num) && std_num != 0) {
		for (i = 0; i < std_num; i++)
			scanf("%f\n", &expense[i]);
			
		pos_offset = 0;
		neg_offset = 0;
		avg = average(expense, std_num);
		for (i = 0; i < std_num; i++) {
			offset = avg - expense[i];
			if (offset > 0)
				pos_offset += offset;
			else
				neg_offset += (-offset);	
		}
		printf("$%.2f %.2f\n", pos_offset, neg_offset);
	}
}

float average(float *exp, int std_num) {
	int i;
	float sum;

	for (i = 0; i < std_num; i++) 
		sum += exp[i];

	return (float) ((int) (sum/std_num * 100))/100;
}

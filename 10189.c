/* Alberto Amigo Alonso */

#include <stdio.h>

#define MINE '*'
#define REP_MINE -10

int main() {
	int n, m; /* Inputs: NxM field */
	int field_num = 0; /* Number of field printed */
	int i, j; /* Iterators */
	char field[100][100]; /* Input field with mines and dots */
	int sol_field[102][102] = {0}; /* Field with the solution */

	while (scanf("%d %d\n", &n, &m) != EOF && (n != 0 && m != 0)) {
		if (field_num > 0)
			printf("\n");
		field_num++;

		for (i = 0; i < n; i++)
			scanf("%s\n", field[i]);
		
		/* Look for mines and set the mines arround */
		for (i = 0; i < n; i++) {
			for (j = 0; j < m; j++) {
				if (field[i][j] == MINE) {
					sol_field[i+1][j+1] = REP_MINE;
					/* Add 1 arround the mine */
					sol_field[i][j]++;
					sol_field[i][j+1]++;
					sol_field[i][j+2]++;
					sol_field[i+1][j]++;
					sol_field[i+1][j+2]++;
					sol_field[i+2][j]++;
					sol_field[i+2][j+1]++;
					sol_field[i+2][j+2]++;
				}
			}
		}

		/* Print the solved field */
		printf("Field #%d:\n", field_num);
		for (i = 1; i < n+1; i++) {
			for (j = 1; j < m+1; j++) {
				if (sol_field[i][j] < 0) 
					printf("*");
				else
					printf("%d", sol_field[i][j]);
			}
			printf("\n");
		}

		/* Reinitialize the solution field */
		for (i = 0; i < n+2; i++)
			for (j = 0; j < m+2; j++)
				sol_field[i][j] = 0;
	}
	return 0;
}

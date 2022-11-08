
#include <stdio.h>
#include <inttypes.h>

int64_t buffer[2][103];

int main()
{
	int N = 100;
	int k = 1000000;


	buffer[0][0] = 1;
	int64_t* prev = buffer[0];
	int64_t* curr = buffer[1];
	int64_t* temp;

	int r;
	int count = 0;
	for (int n = 1; n <= N; n++) {
		curr[0] = 1;
		for (r = 1; r < n; r++) {
			curr[r] = prev[r] + prev[r - 1];
			if (curr[r] > k) {
				count++;
				curr[r] = k;
			}
		}
		curr[r] = 1;


		temp = curr;
		curr = prev;
		prev = temp;
	}

	printf("%d\n", count);

    return 0;
}

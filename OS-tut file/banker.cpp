
#include <iostream>
using namespace std;
int n, m, i, j, k;

void process(){

n = 5;
	m = 3;
	int allocation[5][3] = { { 0, 1, 0 },
						{ 2, 0, 0 },
						{ 3, 0, 2 },
						{ 2, 1, 1 },
						{ 0, 0, 2 } };

	int maximum[5][3] = { { 7, 5, 3 },
					{ 3, 2, 2 },
					{ 9, 0, 2 },
					{ 2, 2, 2 },
					{ 4, 3, 3 } };

	int available[3] = { 3, 3, 2 };

	int fun[n], answer[n], index = 0;
	for (k = 0; k < n; k++) {
		fun[k] = 0;
	}
	int need[n][m];
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++)
			need[i][j] = maximum[i][j] - allocation[i][j];
	}
	int y = 0;
	for (k = 0; k < 5; k++) {
		for (i = 0; i < n; i++) {
			if (fun[i] == 0) {

				int flag = 0;
				for (j = 0; j < m; j++) {
					if (need[i][j] > available[j]){
						flag = 1;
						break;
					}
				}

				if (flag == 0) {
					answer[index++] = i;
					for (y = 0; y < m; y++)
						available[y] += allocation[i][y];
					fun[i] = 1;
				}
			}
		}
	}

	cout << "the safe sequence is as following " << endl;
	for (i = 0; i < n - 1; i++)
		cout << " P" << answer[i] << " ->";
	cout << " P" << answer[n - 1] <<endl;

}
int main()
{

    process();



	return (0);
}



#include <cstdio>
using namespace std;

int arr[2][100000];
int main()
{
	int n, m, l, x, nth, len, co, cnt;
	scanf("%d %d %d", &n, &m, &l);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[0][i]);
		if (arr[0][i] > l) arr[1][i] = 1;
	}
	co = 0; cnt = 0;
	for (int i = 0; i < n; i++) {
		if (arr[1][i] == 1) {
			if (co == 0) {
				cnt++;
				co = 1;
			}
		}
		else co = 0;
	}
	while (m--) {
		scanf("%d", &x);
		if (x == 0) {
			printf("%d\n", cnt);
		}
		else {
			scanf("%d %d", &nth, &len);
			if (arr[1][nth - 1] == 0) {
				arr[0][nth - 1] += len;
				if (arr[0][nth - 1] > l) {
					arr[1][nth - 1] = 1;
					if (nth - 1 == 0) {
						if (arr[1][nth] != 1) cnt++;
					}
					else if (nth - 1 == n - 1) {
						if (arr[1][nth - 2] != 1) cnt++;

					}
					else {
						if (arr[1][nth] != 1 && arr[1][nth - 2] != 1) cnt++;
						if (arr[1][nth] == 1 && arr[1][nth - 2] == 1) cnt--;
					}
				}
			}
		}
	}

	return 0;
}
#include <cstdio>
using namespace std;

int main() {
	int x, a, b;
	bool tt = false;
	scanf("%d", &x);
	for (int i = 1; i <= x; i++) {  //b
		for (int j = i; j <= x; j += i) { // a
			if (j / i<x && j*i>x) {
				tt = true;
				a = j; b = i;
				break;
			}
		}
		if (tt) break;
	}
	if (tt) printf("%d %d", a, b);
	else printf("-1");
	return 0;
}
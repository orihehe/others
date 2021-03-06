/*
수열에서 r~l범위의 수들을 k만큼 더할 수 있다. k는 절댓값이 50000 이하인 정수
k는 원하는 수로 설정할 수 있다. r~l범위를 바꾼 수열에서의 c값의 개수가 최대일때의 c 개수를 출력하는 문제다.
따라서 r~l범위에서 가장 많이 나온 수가 c값이 되도록 k를 설정하면 된다.
c의 개수는 범위 1~(l-1)의 c개수 + l~r의 i개수 + (r+1)~n의 c개수 이다.
여기까지 생각해냈지만 시간초과가 나는 구현밖에 생각이 나지 않아 다른 사람 풀이를 봤다.

l~r 범위의 c의 개수(lrC), i의 개수(lrT)를 구하고 
전체 c의 개수 - lrC + lrT 를 해주면 l~r범위에 i가 c가되는 k값을 더한 후 c의 개수가 된다.
만약 lrT가 lrC 이하라면 l=r을 해준다. l~r범위에서 c의 개수가 손해를 보기 때문이다.
*/
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int Ccnt[500001]; // 1~n까지 c개수 저장
vector<int> vec[500001];
int main() {
	int n, c, maxcnt = 0, x;
	scanf("%d %d", &n, &c);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &x);
		Ccnt[i] = Ccnt[i - 1];
		if (x == c) Ccnt[i]++;
		vec[x].push_back(i); // vec[x]에 인덱스 저장
	}
	if (Ccnt[n] == n) { // 다 c면
		printf("%d", n);
		return 0;
	}
	int len, l, r, tmp, lrC, lrT, fidx;
	maxcnt = Ccnt[n - 1] + 1; // c개수 + r~l범위의 길이가 1일경우(수 하나 바꿨을때)
	for (int i = 1; i <= 500000; i++) { 
		if (vec[i].size() == 0 || i == c) continue;
		fidx = 0;
		len = vec[i].size();
		for (int j = 1; j < len; j++) {
			l = vec[i][fidx];
			r = vec[i][j];
			lrC = Ccnt[r] - Ccnt[l - 1]; // l~r구간에서 c개수
			lrT = j - fidx + 1; // l~r구간에서 i개수
			maxcnt = max(maxcnt, Ccnt[n]-lrC+lrT);

			if (lrC >= lrT) { // 잃는게 더 많으면
				fidx = j;
			}
		}
	}

	printf("%d", maxcnt);

	return 0;
}
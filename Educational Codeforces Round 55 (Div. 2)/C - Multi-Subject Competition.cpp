#include <cstdio>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;

int main() {
	int n, m, sp, lv, maxlv=0, j;
	vector<vector<int>> vec;
	vector<pair<int, int>> sub; // 명수, 주제
	scanf("%d %d", &n, &m);
	vec.resize(m + 1);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &sp, &lv);
		vec[sp].push_back(lv);
	}
	for (int i = 1; i <= m; i++) {
		sub.push_back({ vec[i].size(),i });
	}
	sort(sub.begin(), sub.end(), greater<pair<int,int>>());
	for (int i = 1; i <= m; i++) {
		// 주제별로 내림차순
		sort(vec[i].begin(), vec[i].end(), greater<int>()); 
		for (int j = 1; j < vec[i].size(); j++) {
			vec[i][j] += vec[i][j - 1];
		}
	}
	for (int i = 0; i < n; i++) { // i+1명씩 과목 참가
		int tmp=0;
		for (j = 0; j < m; j++) { 
			if (sub[j].first <= i) break;
			if (vec[sub[j].second][i]>0) {
				tmp += vec[sub[j].second][i];
			}
		}
		if (j == 0) break; // i+1명보다 큰 참가자수가 없으면 종료
		maxlv = max(maxlv, tmp);
		if (tmp == 0) break;
	}
	printf("%d", maxlv);

	return 0;
}
#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	long long t, n, m, x1, y1, x2, y2, x3, y3, x4, y4, fx, fy, sx, sy;
	long long all, white, black, m_w, m_b, m_r;

	scanf("%lld", &t);
	while (t--) {
		scanf("%lld %lld", &n, &m);
		all = n * m;
		white = all / 2;
		black = all / 2;
		if (all % 2 == 1) {
			white++;
		}
		scanf("%lld %lld %lld %lld", &x1, &y1, &x2, &y2);
		scanf("%lld %lld %lld %lld", &x3, &y3, &x4, &y4);
		fx = max(x1, x3);
		fy = max(y1, y3);
		sx = min(x2, x4);
		sy = min(y2, y4);

		m_w = (x2 - x1 + 1)*(y2 - y1 + 1); // 면적
		m_b = (x4 - x3 + 1)*(y4 - y3 + 1);

		long long tmp = m_w / 2;
		if (m_w % 2 == 1) {
			if ((x1 + y1) % 2 == 1) { // 검은색
				tmp++;
			}
		}
		white += tmp;
		black -= tmp;

		if (fx <= sx && fy <= sy) {  //겹치는 부분 있으면
			m_r = (sx - fx + 1)*(sy - fy + 1);
			tmp = m_r / 2;
			if (m_r % 2 == 1) {
				if ((fx + fy) % 2 == 1) {//흰
					tmp++;
				}
			}
			black += tmp;
			white -= tmp;
		}

		tmp = m_b / 2;
		if (m_b % 2 == 1) {
			if ((x3 + y3) % 2 == 0) { // 검은색
				tmp++;
			}
		}
		white -= tmp;
		black += tmp;

		printf("%lld %lld\n", white, black);
	}

	return 0;
}
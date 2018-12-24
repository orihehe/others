/*
��ȸ �ð��� �� Ǯ���µ�, ���� �𸣰ھ Ǯ�̸� ����ô٤̤�
(x/k)*(x%k)=n ���� n�� k�� �־����� x�� ���ϴ� ����.
x%k�� i�� �δµ�, n�� 1�̻��̹Ƿ� 0�� �� �� ���� k�� ���� �������� k�̻��� ���� �� �� ���� ������
i�� ������ 1<=i<k �̴�.
i�� ���� �� ���� ���� x=n/i*k�� �ٲ� �� �ִ�. 
������ ���� (x/k)*i=n ���� n�� x/k ���꿡�� �������� ������ ���� ����� ���̴�.
���� x=n/i*k���� x���� ���� ���� ���������� ���� ���̴�. 
������ x���� x=n/i*k+i�� ���� �� �ִ�.
*/
#include <cstdio>
#include <algorithm>
#define ll long long
using namespace std;

int main()
{
	ll n, k;
	ll x = 987987987987987;
	scanf("%lld %lld", &n, &k);
	for (int i = 1; i < k; i++) {
		if (n%i == 0) {
			x = min(x, n / i * k + i);
		}
	}
	printf("%lld", x);

	return 0;
}
#include<iostream>
#include<vector>
using namespace std;

int main() {
	vector<int> s = { 1, 2, 0, 3, 2, 1, 2, 0, 1 };
	vector<int> c(20);
	int n = s.size();
	int cnt = 0;

	printf("ѧ������Ϊ��");
	for (int i = 0;i < n;i++) {
		printf(" %d", s[i]);
	}
	printf("\n");


	// �������ҽ��м���
	c[0] = 1;
	for (int i = 1;i < n;i++) {
		if (s[i] > s[i - 1]) {
			c[i] = c[i - 1] + 1;
		}
		else {
			c[i] = 1;
		}
	}

	// �������ҽ��м���
	for (int i = n - 2;i >= 0;i--) {
		if (s[i] > s[i + 1]) {
			c[i] = c[i + 1] + 1;
		}
	}

	// �����ܵ��ǹ�����
	for (int i = 0;i < n;i++) {
		cnt += c[i];
	}

	printf("�������ٵ��ǹ�����Ϊ��%d ��\n", cnt);
	printf("�������Ϊ��");
	for (int i = 0;i < n;i++) {
		printf(" %d", c[i]);
	}


	return 0;
}
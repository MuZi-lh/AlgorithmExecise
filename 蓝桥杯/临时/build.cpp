#include<iostream>
#include<string>
using namespace std;

bool matchable(string a, string b) {
	// �ж�b���Ƿ���a�в����ڵ��ַ�
	bool contain[26] = { false };
	for (int i = 0;i < a.length();i++) {
		contain[a[i] - 'a'] = true;
	}
	for (int i = 0;i < b.length();i++) {
		if (!contain[b[i] - 'a']) return false;
	}
	return true;
}

int main() {
	int n;
	cin >> n;
	string a, b;
	for (int p = 0;p < n;p++) {
		cin >> a >> b;
		// j ��ʾ����ƥ��b�еĵ�j���ַ� or �Ѿ�ƥ��ɹ�������
		int j = 0, cnt = 0, lenb = b.length();
		// flag ������¼���α���s�Ƿ���
		if (!matchable(a, b)) {
			printf("-1\n");
			continue;
		}
		while (j < lenb) {
			cnt++;
			for (int i = 0;i < a.length();i++) {
				if (j < lenb && a[i] == b[j]) j++;
			}
		}
		printf("%d\n", cnt);
	}
}
/*
4
a
a
aaccbb
act
aaxbdec
abc
xlearning
gninraelx

*/
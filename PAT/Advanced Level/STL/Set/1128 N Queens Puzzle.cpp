// ʹ��set��¼�ʺ����ڵ��У���б�ߣ���б�ߣ��������и�����ʺ�����һ�£���Ϊlegal
#include<iostream>
#include<unordered_set>
using namespace std;
int N, K, p;
unordered_set<int> c, l, r;

int main() {
	cin >> K;
	for (int t = 0;t < K;t++) {
		cin >> N;
		c.clear();
		l.clear();
		r.clear();
		for (int i = 1;i <= N;i++) {
			cin >> p;
			c.insert(p);
			l.insert(i + p);
			r.insert(i - p);
		}
		if (c.size() == N && l.size() == N && r.size() == N)
			printf("YES\n");
		else
			printf("NO\n");
	}
}
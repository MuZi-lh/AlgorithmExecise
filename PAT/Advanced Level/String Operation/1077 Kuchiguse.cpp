//
// Created by ľ����Ƿ on 2021/4/15.
//
#include<string>
#include<iostream>
using namespace std;
bool legal = true;
int N, minLen = 300;
string s[100], ku, cur;

int main() {
	// �˴���Ҫһ��\n�������һ��getline�������ȡN��ֵ����Ļس��������¶�ȡ����
	// Ҳ����cin>>N;֮�����һ��cin.get();����ȡ��ĩ�س�����
	scanf("%d\n", &N);
	for (int i = 0;i < N;i++) {
		getline(cin, s[i]);
		if (s[i].length() < minLen) minLen = s[i].length();
	}
	for (int k = 1;k <= minLen;k++) {
		cur = s[0].substr(s[0].length() - k, k);
		for (int i = 1;i < N;i++) {
			if (cur != s[i].substr(s[i].length() - k, k)) {
				legal = false;
				break;
			}
		}
		if (legal) ku = cur;
		else break;
	}
	if (ku.size()) cout << ku;
	else cout << "nai";
}
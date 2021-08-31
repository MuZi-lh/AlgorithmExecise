#include<iostream>
#include<cmath>
#include<queue>
using namespace std;

struct node {
	int val;
	node* left, * right;
};

int N, temp, flag = 1;
node* root = NULL;
queue<node*> q;
int getHeight(node* root) {
	return root == NULL ? 0 : max(getHeight(root->left), getHeight(root->right)) + 1;
}
int getBalanceFactor(node* root) {
	return root == NULL ? 0 : getHeight(root->left) - getHeight(root->right);
}
node* rotateLeft(node* root) {
	node* p = root->right;
	root->right = p->left;
	p->left = root;
	return p;
}
node* rotateRight(node* root) {
	node* p = root->left;
	root->left = p->right;
	p->right = root;
	return p;
}
node* rotateLeftRight(node* root) {
	root->left = rotateLeft(root->left);
	return rotateRight(root);
}
node* rotateRightLeft(node* root) {
	root->right = rotateRight(root->right);
	return rotateLeft(root);
}
node* rebalance(node* root) {
	int f = getBalanceFactor(root), l = getBalanceFactor(root->left), r = getBalanceFactor(root->right);
	if (abs(f) <= 1) return root;
	if (f > 1)
		return l > 0 ? rotateRight(root) : rotateLeftRight(root);
	else return r < 0 ? rotateLeft(root) : rotateRightLeft(root);
}
node* insert(node* root, int v) {
	if (root == NULL) {
		root = new node();
		root->val = v;
		root->left = root->right = NULL;
	}
	else if (v < root->val)
		root->left = insert(root->left, v);
	else root->right = insert(root->right, v);
	return rebalance(root);
}
// ע��������ȫ����������������������
void traverse(node* root) {
	node* cur;

	cout << root->val;
	q.push(root->left);
	q.push(root->right);
	cur = q.front();
	// ���ղ�������ķ��������ֱ��������һ��NULLֹͣ
	while (cur) {
		cout << ' ' << cur->val;
		q.push(cur->left);
		q.push(cur->right);
		q.pop();
		cur = q.front();
	}
	// ���������ȫΪNULL������ȫ��������������
	while (!q.empty()) {
		if (q.front()) {
			cout << ' ' << q.front()->val;
			// ���û�������������һ�������ȥ��
			// ����һ��while�˳�ʱ�����нڵ�δ�����뵽�����е����
			q.push(q.front()->left);
			q.push(q.front()->right);
			flag = 0;
		}
		q.pop();
	}
	if (flag) cout << "\nYES";
	else cout << "\nNO";
}


int main() {
	cin >> N;
	for (int i = 0;i < N;i++) {
		cin >> temp;
		root = insert(root, temp);
	}
	traverse(root);
	return 0;
}


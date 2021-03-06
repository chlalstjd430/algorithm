#include <iostream>

using namespace std;

typedef struct node *tree;
typedef struct node{
	char data;
	tree left, right;
};

void preorder(tree tr) {
	if (tr) {
		cout << tr->data;
		preorder(tr->left);
		preorder(tr->right);
	}
}
void inorder(tree tr) {
	if (tr) {	
		inorder(tr->left);
		cout << tr->data;
		inorder(tr->right);
	}
}

void postorder(tree tr) {
	if (tr) {
		postorder(tr->left);
		postorder(tr->right);
		cout << tr->data;
	}
}

int main() {
	node nodes[27];
	int nodeCnt;
	char a, b, c;

	cin >> nodeCnt;
	for (int i = 0; i < nodeCnt; i++) {
		cin >> a >> b >> c;
		nodes[a - 'A' + 1].data = a;
		(b == '.') ? nodes[a - 'A' + 1].left = NULL : nodes[a - 'A' + 1].left = &nodes[b - 'A' + 1];
		(c == '.') ? nodes[a - 'A' + 1].right = NULL : nodes[a - 'A' + 1].right = &nodes[c - 'A' + 1];
	}
	preorder(&nodes[1]);
	cout << endl;
	inorder(&nodes[1]);
	cout << endl;
	postorder(&nodes[1]);
;
}
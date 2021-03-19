#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct treeNode { // Ʈ���� ��� ���� ����
	int size; // ������ �ʵ�
	struct treeNode* left; // ���� ���� Ʈ���� ���� ��ũ ��Ʈ
	struct treeNode* right; // ������ ���� Ʈ���� ���� ��ũ �ʵ�
}treeNode;

int folderSize = 0;

// size�� ��Ʈ ����� ������ �ʵ�� �Ͽ� ���ʰ� ������ ���� Ʈ���� �����ϴ� ����
treeNode* makeRootNode(int size, treeNode* leftNode, treeNode* rightNode) {
	treeNode* root = (treeNode*)malloc(sizeof(treeNode));
	root->size = size;
	root->left = leftNode;
	root->right = rightNode;
	return root;
}

// �� ���� ũ�⸦ ����ϱ� ���� ���� ��ȸ ����
int postorder_foldersize(treeNode* root) {
	if (root) {
		postorder_foldersize(root->left);
		postorder_foldersize(root->right);
		folderSize += root->size;
	}
	return folderSize;
}

void main() {
	treeNode* F11 = makeRootNode(120, NULL, NULL);
	treeNode* F10 = makeRootNode(55, NULL, NULL);
	treeNode* F9 = makeRootNode(100, NULL, NULL);
	treeNode* F8 = makeRootNode(200, NULL, NULL);
	treeNode* F7 = makeRootNode(68, F10, F11);
	treeNode* F6 = makeRootNode(40, NULL, NULL);
	treeNode* F5 = makeRootNode(15, NULL, NULL);
	treeNode* F4 = makeRootNode(2, F8, F9);
	treeNode* F3 = makeRootNode(10, F6, F7);
	treeNode* F2 = makeRootNode(0, F4, F5);
	treeNode* F1 = makeRootNode(0, F2, F3);

	printf("\n\n C:\\�� �뷮 : %d M \n", postorder_foldersize(F2));
	
	folderSize = 0;
	printf("\n D:\\�� �뷮 : %d M \n", postorder_foldersize(F3));

	folderSize = 0;
	printf("\n �� ��ǻ���� ��ü �뷮 : %d M \n", postorder_foldersize(F1));

	getchar();
}
#include <stdio.h>
typedef int element;
int size;

// ���� �����ϴ� ����
void bubbleSort(element a[], int size) {
	int i, j, t;
	element temp;
	printf("\n������ ���� : ");
	for (t = 0; t < size; t++) printf("%d ", a[t]);
	printf("\n <<<<< ���� ���� ���� >>>>>");
	for (i = size - 1; i > 0; i--) {
		printf("\n %d�ܰ�>>", size - i);
		for (j = 0; j < i; j++) {
			if (a[j] > a[j + 1]) {
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
			printf("\n\t");
			for (t = 0; t < size; t++) printf("%3d ", a[t]);
		}
	}
}

void main() {
	element list[8] = { 69,10,30,2,16,8,31,22 };
	size = 8;
	bubbleSort(list, size);
	getchar();
}
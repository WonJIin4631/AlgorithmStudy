#include<iostream>
using namespace std;

void bubble_sort(int list[], int n) {
	int temp;
	for (int i = n - 1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (list[j] > list[j + 1]) {
				temp = list[j];
				list[j] = list[j + 1];
				list[j + 1]=temp;
			}
		}
	}
}
void selection_sort(int list[], int n) {
	int temp;
	for (int i = 0; i < n; i++) {
		int min = i;
		for (int j = i + 1; j < n; j++) {
			if (list[j] < list[min]) {
				min = j;
			}
		}
		if (min == i)
			continue;
		temp = list[i];
		list[i] = list[min];
		list[min] = temp;
	}
}
void insertion_sort(int list[], int n) {
	for (int i = 1; i < n; i++) {
		int key = list[i];
		int pos = i;
		while (pos >0&&key<list[pos-1]){
			list[pos] = list[pos - 1];
			pos--;
		}
		list[pos] = key;
	}
}

void interveral_sort(int list[],int begin,int end,int gap) {
	for (int i = begin + gap; i <= end; i = i + gap) {
		int key = list[i];
		int pos = i;
		while (pos >= gap&&key < list[pos - gap]) {
			list[pos] = list[pos - gap];
			pos -= gap;
		}
		list[pos] = key;
	}
}
void shell_sort(int list[], int n) {
	for (int gap = n / 2; gap > 0; gap = gap / 2) {
		if ((gap % 2) == 0) {
			gap++;
		}
		for (int i = 0; i < gap; i++) {
			interveral_sort(list, i, n-1, gap);
		}
	}
}
int main() {
	int list[] = { 5,1,3,4,2 };
	int listSize = 5;
	shell_sort(list, listSize);
	for (int i = 0; i < listSize; i++) {
		cout << list[i] << '\n';
	}
	return 0;
}
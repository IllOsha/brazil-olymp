#include <numeric>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <cmath>
#define _USE_MATH_DEFINES
#include <math.h>
#include <stdio.h>
#include <iomanip>
#define stop do{ } while(0)
#include <windows.h>
using namespace std;
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <cmath>
#include <algorithm>

struct uzel {
	int data;
	uzel* next;
};
// Функция для инвертирования связанного списка
void inverlist(uzel*& head) {
	uzel* prev = nullptr;
	uzel* current = head;
	uzel* next = nullptr;

	while (current != nullptr) {
		next = current -> next;// сохраняем следующий элемент
		current->next = prev;// меняем указатель
		prev = current;// передвигаем prev на текущий
		current = next;// передвигаем current на следующий
	}
	head = prev; // новый главный элемент
}
// Функция для печати списка
void printlist(uzel* head) {
	uzel* temp = head;
	while (temp != nullptr) {
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	// Пример списка: 1 -> 2 -> 3
	uzel* head = new uzel{ 1, nullptr };
	head->next = new uzel{ 2, nullptr };
	head->next->next = new uzel{ 3, nullptr };
	cout << " первоначальнный список = ";
	printlist(head);
	inverlist(head);
	cout << " новый список = ";
	printlist(head);



	return 0;
}
// 2 Сортировка связанного списка
uzel* merge(uzel* left, uzel* right) {
	if (!left) return right;
	if (!right) return left;
	if (left->data < right->data) {
		left -> next = merge(left -> next, right);
		return left;
	}
	else {
		right->next = merge(left, right->next);
		return right;
	}
}
uzel* mergesort(uzel* head) {
	if (!head || !head->next) {  // если список пуст или состоит из одного элемента
		return head;
	}
	// ищем середину списка с помощью двух указателей
	uzel* mid = head;
	uzel* fast = head;
	while (fast && fast->next) {
		mid = mid->next;
		fast = fast->next->next;
	}
	// разделяем список на две части
	uzel* left = head;
	uzel* right = mid -> next;
	mid->next = nullptr;
	left = mergesort(left);
	right = mergesort(right);

	return merge(left, right);
}
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	uzel* head = new uzel{ 3, nullptr };
	head->next = new uzel{ 1, nullptr };
	head->next->next = new uzel{ 2, nullptr };

	cout << " первоначальнный список";
	printlist(head);
	cout << "отсортированный список";
	printlist(head);



	return 0;
}
//3 Поиск элемента в связанном списке
bool search(uzel* head, int value) {
	uzel* current = head;
	while (current != nullptr) {
		if (current->data == value) {
			return true;
		}
		current = current->next;
	}
	return false;
}
int main() {
	uzel* head = new uzel{ 3 , nullptr };
	head->next = new uzel{ 1, nullptr };
	head->next->next = new uzel{ 2, nullptr };

	int value = 2;
	if (search(head, value)) {
		cout << " элемент " << value << "нашли))";
	}
	else {
		cout << "элемент" << value << "не нашли";
	}
	return 0;
}

//. Слияние двух отсортированных списков
uzel* mergsortlist(uzel* h1, uzel* h2) {
	uzel* vremenno = new uzel{ 0, nullptr };
	uzel* current = vremenno;

	while (h1 || h2) {
		if (h1->data < h2->data) {
			current->next = h1;
			h1 = h1->next;
		}
		else {
			current->next = h2;
			h2 = h2->next;
		}
		if (h1) current->next = h1;
		if (h2) current->next = h2;

		return vremenno->next;
	}
}
int main() {
	uzel* h1 = new uzel{ 1, nullptr };
	h1->next = new uzel{ 3, nullptr };
	uzel* h2 = new uzel{ 2, nullptr };

	uzel* merged = mergsortlist(h1, h2);

	printlist(merged);
	return 0;
}



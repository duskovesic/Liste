#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//Definition of one knot of the list
typedef struct list_knot {
	int element;
	struct list_knot* next;
} Knot;

//Making new knot
Knot* make_knot(int x) {
	Knot* new_knot = (Knot*)malloc(sizeof(Knot));
	if (new_knot == NULL)
		return NULL;
	new_knot->element = x;
	new_knot->next = NULL;
	return new_knot;
}

//Add element at the start of the list
void add_at_start2(Knot** list, int x) {
	Knot* new_head = make_knot(x);
	new_head->next = *list;
	*list = new_head;
}

//Add element at the start of the list (secound way to do)
Knot* add_at_start(Knot* list, int x) {
	Knot* new_head = make_knot(x);
	new_head->next = list;
	return new_head;
}

//Add element at the end of the list
void add_at_end(Knot** list, int x) {
	if (*list == NULL)
		*list = make_knot(x);
	else
		add_at_end(&(*list)->next, x);
}

//Print all elements from the list
void print_list(Knot* list) {
	printf("This is elements from the list:\n");
	while (list->next != NULL) {
		printf("%d  ", list->element);
		list = list->next;
	}
	printf("%d\n", list->element);
}

//Clear all elements from the list
void clear_list(Knot *list) {
	if (list != NULL) {
		clear_list(list->next);
		free(list);
	}
}

//Count how much elements are in the list
int count_elements(Knot* list) {
	int num = 0;
	while (list != NULL) {
		num++;
		list = list->next;
	}
	return num++;
}

//Add element in the midle of the list
void add_midle(Knot** list, int x) {
	int n = count_elements(*list);
	Knot* tmp = *list;
	int count = 1;
	while (count < n/2) {
		tmp = tmp->next;
		count++;
	}
	Knot* new_knot = make_knot(x);
	new_knot->next = tmp->next;
	tmp->next = new_knot;	
}

//Return threeth element from the back
int threeth_from_back(Knot* list) {
	while (((list->next)->next)->next != NULL) {
		list = list->next;
	}
	return list->element;
}

//Return n-th element from the back of the list
int nth_from_back(Knot * list, int n) {
	int i;
	Knot* last = list;
	for (i = 0; i < n; i++)
		last = last->next;
	while (last != NULL) {
		last = last->next;
		list = list->next;
	}
	return list->element;
}

//Minimal element from the list
int min_element(Knot* list) {
	int min = list->element;
	while (list != NULL) {
		if (list->element < min)
			min = list->element;
		list = list->next;
	}
	return min;
}
//Threeth element from the back of the list in one passing
int threeth_back_one_passing(Knot* list) {
	int i = 0;
	int* arr = (int*)malloc(3 * sizeof(int));
	while (list != NULL) {
		arr[i % 3] = list->element;
		i++;
		list = list->next;
	}
	return arr[i % 3];
}

//N-th element from the back of the list in one passing
int nth_back_one_passing(Knot* list, int n) {
	int i = 0;
	int* arr = (int*)malloc(n * sizeof(int));
	while (list != NULL) {
		arr[i % 3] = list->element;
		i++;
		list = list->next;
	}
	return arr[i % 3];
}

int main() {
	
	Knot* list = NULL;
	int i, n, xi;
	srand(time(NULL));
	printf("How much numbers do you want to add?\n");
	scanf_s("%d", &n);
	for (i = 0; i < n; i++) {
		xi = rand() % 100 + 1;
		add_at_end(&list, xi);
		}
	printf("Elements from the list:\n");
	print_list(list);

	printf("In the list is %d elements\n", count_elements(list));

/*	printf("Which number do you want tu add at the start of the list?\n");
	int x1;
	scanf_s("%d", &x1);
	add_at_start2(&list, x1);
	print_list(list);*/

/*	printf("Which number do you want do add in the midle of array?\n");
	int x2;
	scanf_s("%d", &x2);
	add_midle(&list, x2);
	print_list(list);*/

/*	printf("Threeth element from the back of the list is %d\n", threeth_from_back(list));
	printf("Which number from the back of the list do you want?\n");
	int x3;
	scanf_s("%d", &x3);
	printf("%d-th element from the back of the list is %d\n", x3, nth_from_back(list, x3));*/

/*	printf("Minimal element from the list is %d\n", min_element(list));*/

/*	printf("Threeth element from the back of the list in one passing is %d\n", threeth_back_one_passing(list));*/

	printf("Which number from the back of the list do you want?\n");
	int x3;
	scanf_s("%d", &x3);
	printf("%d-th element from the back of the list is %d\n", x3, nth_from_back(list, x3));



	
	
	clear_list(list);


	}

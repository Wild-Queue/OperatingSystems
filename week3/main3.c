#include <stdio.h>
#include <string.h>
struct Node
{
	int x;
	struct Node* p;
};

struct LinkedList
{
	struct Node* Head;
};

void print_list(struct LinkedList A){
	struct Node* writer;
	if (A.Head == NULL){
		printf("Liked list is empty\n");
	}
	else {
		writer = A.Head;
		for (int i = 0; writer->p != NULL; i++){
			int x = writer->x;
			printf("%d ", x);
		writer = writer->p;
		}
		
		int x = writer->x;
		printf("%d ", x);
		printf("\n");
	}
}

void insert_node(struct LinkedList* A, struct Node* P){
	struct Node* writer;
	
	if (A->Head == NULL){
		A->Head = P;
	}
	else {
		writer = A->Head;
		for (int i = 1; writer->p != NULL; i++){
			writer = writer->p;
		}
		writer->p = P;
	}
}

void delete_node(struct LinkedList* A, struct Node* P){
	struct Node* writer;
	writer = A->Head;
	if (A->Head == P){
		A->Head = P->p;
		return;
	}
	for (int i = 0; writer->p != NULL; i++){
		if (writer->p == P){
			writer->p = P->p;
			return;
		}
		writer = writer->p;
	}
}

int main (void)
{
	printf("Creating Linked list\n");
	struct LinkedList A;
	A.Head = NULL;
	
	printf("Creating the firts Node(with value 1)\n");
	struct Node B;
	B.x = 1;
	B.p = NULL;
	
	printf("Creating the second Node(with value 2)\n");
	struct  Node C;
	C.x = 2;
	C.p = NULL;
	
	printf("Inserting the first node into the list\n");
	insert_node(&A, &B);
	
	printf("Linked list values:\n");
	print_list(A);
	
	printf("Inserting the second node into the list\n");
	insert_node(&A, &C);
	
	printf("Linked list values:\n");
	print_list(A);
	
	printf("Creating the third Node(with value 3)\n");
	struct  Node D;
	D.x = 3;
	D.p = NULL;
	
	printf("Inserting the third node into the list\n");
	insert_node(&A, &D);
	
	printf("Linked list values:\n");
	print_list(A);
	
	printf("Deleting the second node from the list\n");
	delete_node(&A, &C);
	
	printf("Linked list values:\n");
	print_list(A);
	
	printf("Deleting the first node from the list\n");
	delete_node(&A, &B);
	
	printf("Linked list values:\n");
	print_list(A);
	
	printf("Deleting the last node from the list\n");
	delete_node(&A, &D);
	
	printf("Linked list values:\n");
	print_list(A);
	
  return 0;
}

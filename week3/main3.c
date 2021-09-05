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
	struct LinkedList A;
	A.Head = NULL;
	
	struct Node B;
	B.x = 1;
	B.p = NULL;
	
	struct  Node C;
	C.x = 2;
	C.p = NULL;
	
	insert_node(&A, &B);
	print_list(A);
	insert_node(&A, &C);
	print_list(A);
	
	struct  Node D;
	D.x = 3;
	D.p = NULL;
	
	insert_node(&A, &D);
	print_list(A);
	
	delete_node(&A, &B);
	print_list(A);
	
  return 0;
}

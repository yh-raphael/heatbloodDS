#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
	int data;
	struct _node* next;
} Node;

int main(void)
{
	Node* head = NULL;
	Node* tail = NULL;
	Node* cur = NULL;	// for reference

	Node* newNode = NULL;
	int readData;

	// 데이터를 입력 받는 과정.
	while (1)
	{
		printf("자연수 입력: ");
		scanf("%d", &readData);
		if (readData < 1)
			break;

		// 노드의 추가과정.
		newNode = (Node*)malloc(sizeof(Node));
		newNode->data = readData;
		newNode->next = NULL;

		if (head == NULL)
			head = newNode;	// If it is a head node.
		else
			tail->next = newNode;	// Unless a head node. connect with newNOde

		tail = newNode;	//tail update.
	}
	printf("\n");

	// 입력 받은 데이터의 출력과정.
	printf("입력 받은 데이터의 전체출력! \n");
	if (head == NULL)
	{
		printf("저장된 자연수가 존재하지 않습니다. \n");
	}	// error control.
	else
	{
		cur = head;
		printf("%d ", cur->data);	// printing first data .

		while (cur->next != NULL)
		{
			cur = cur->next;
			printf("%d ", cur->data);	// 두 번째 이후 데이터 출력.
		}
	}
	printf("\n\n");

	// 메모리의 해제과정
	if (head == NULL)
	{
		return 0;	// 해제할 노드가 존재하지 않는다.
	}
	else
	{
		Node* delNode = head;
		Node* delNextNode = head->next;

		printf("%d을(를) 삭제합니다. \n", head->data);
		free(delNode);		// 첫 번째 노드 삭제.

		while (delNextNode != NULL)
		{
			delNode = delNextNode;
			delNextNode = delNextNode->next;

			printf("%d을(를) 삭제합니다. \n", delNode->data);
			free(delNode);
		}
	}

	return 0;
}
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

	// �����͸� �Է� �޴� ����.
	while (1)
	{
		printf("�ڿ��� �Է�: ");
		scanf("%d", &readData);
		if (readData < 1)
			break;

		// ����� �߰�����.
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

	// �Է� ���� �������� ��°���.
	printf("�Է� ���� �������� ��ü���! \n");
	if (head == NULL)
	{
		printf("����� �ڿ����� �������� �ʽ��ϴ�. \n");
	}	// error control.
	else
	{
		cur = head;
		printf("%d ", cur->data);	// printing first data .

		while (cur->next != NULL)
		{
			cur = cur->next;
			printf("%d ", cur->data);	// �� ��° ���� ������ ���.
		}
	}
	printf("\n\n");

	// �޸��� ��������
	if (head == NULL)
	{
		return 0;	// ������ ��尡 �������� �ʴ´�.
	}
	else
	{
		Node* delNode = head;
		Node* delNextNode = head->next;

		printf("%d��(��) �����մϴ�. \n", head->data);
		free(delNode);		// ù ��° ��� ����.

		while (delNextNode != NULL)
		{
			delNode = delNextNode;
			delNextNode = delNextNode->next;

			printf("%d��(��) �����մϴ�. \n", delNode->data);
			free(delNode);
		}
	}

	return 0;
}
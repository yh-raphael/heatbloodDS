#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Point.h"

int main(void)
{
	List list;			// list ���� ����.
	Point compPos;		// compPos ���� ����
	Point * ppos;		// point ������ Ÿ�� ����

	ListInit(&list);

	/*** 4���� ������ ���� ***/
	ppos = (Point*)malloc(sizeof(Point));	// Point Ÿ�� ���� �Ҵ�.
	SetPointPos(ppos, 2, 1);				// point ����
	LInsert(&list, ppos);					// point ����ֱ�.

	ppos = (Point*)malloc(sizeof(Point));	// Point ž�� ���� �Ҵ�.
	SetPointPos(ppos, 2, 2);
	LInsert(&list, ppos);

	ppos = (Point*)malloc(sizeof(Point));
	SetPointPos(ppos, 3, 1);
	LInsert(&list, ppos);

	ppos = (Point*)malloc(sizeof(Point));
	SetPointPos(ppos, 3, 2);
	LInsert(&list, ppos);

	/*** ����� �������� ��� ***/
	printf("���� �������� ��: %d \n", LCount(&list));	// 4���� ��� �ǰ���.

	if(LFirst(&list, &ppos))
	{
		ShowPointPos(ppos);								// (2,1)
		
		while(LNext(&list, &ppos))
			ShowPointPos(ppos);							// (2,2) (3,1) (3,2)
	}
	printf("\n");

	/*** xpos�� 2�� ��� ������ ���� ***/
	compPos.xpos=2;
	compPos.ypos=0;

	if(LFirst(&list, &ppos))
	{
		if(PointComp(ppos, &compPos)==1)
		{
			ppos=LRemove(&list);
			free(ppos);						// User space ���� ����.
		}
		
		while(LNext(&list, &ppos)) 
		{
			if(PointComp(ppos, &compPos)==1)
			{
				ppos=LRemove(&list);
				free(ppos);
			}
		}
	}

	/*** ���� �� ���� ������ ��ü ��� ***/
	printf("���� �������� ��: %d \n", LCount(&list));	// 2 ����.

	if(LFirst(&list, &ppos))
	{
		ShowPointPos(ppos);				// (3,1)
		
		while(LNext(&list, &ppos))
			ShowPointPos(ppos);			// (3,2)
	}
	printf("\n");

	return 0;
}
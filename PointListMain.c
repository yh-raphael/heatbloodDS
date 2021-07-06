#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Point.h"

int main(void)
{
	List list;			// list 변수 선언.
	Point compPos;		// compPos 변수 선언
	Point * ppos;		// point 포인터 타입 선언

	ListInit(&list);

	/*** 4개의 데이터 저장 ***/
	ppos = (Point*)malloc(sizeof(Point));	// Point 타입 동적 할당.
	SetPointPos(ppos, 2, 1);				// point 설정
	LInsert(&list, ppos);					// point 집어넣기.

	ppos = (Point*)malloc(sizeof(Point));	// Point 탑입 동적 할당.
	SetPointPos(ppos, 2, 2);
	LInsert(&list, ppos);

	ppos = (Point*)malloc(sizeof(Point));
	SetPointPos(ppos, 3, 1);
	LInsert(&list, ppos);

	ppos = (Point*)malloc(sizeof(Point));
	SetPointPos(ppos, 3, 2);
	LInsert(&list, ppos);

	/*** 저장된 데이터의 출력 ***/
	printf("현재 데이터의 수: %d \n", LCount(&list));	// 4개가 출력 되겟지.

	if(LFirst(&list, &ppos))
	{
		ShowPointPos(ppos);								// (2,1)
		
		while(LNext(&list, &ppos))
			ShowPointPos(ppos);							// (2,2) (3,1) (3,2)
	}
	printf("\n");

	/*** xpos가 2인 모든 데이터 삭제 ***/
	compPos.xpos=2;
	compPos.ypos=0;

	if(LFirst(&list, &ppos))
	{
		if(PointComp(ppos, &compPos)==1)
		{
			ppos=LRemove(&list);
			free(ppos);						// User space 공간 해제.
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

	/*** 삭제 후 남은 데이터 전체 출력 ***/
	printf("현재 데이터의 수: %d \n", LCount(&list));	// 2 겟지.

	if(LFirst(&list, &ppos))
	{
		ShowPointPos(ppos);				// (3,1)
		
		while(LNext(&list, &ppos))
			ShowPointPos(ppos);			// (3,2)
	}
	printf("\n");

	return 0;
}
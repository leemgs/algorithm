#include <stdio.h>
#include <stdlib.h>    // malloc, free 함수가 선언된 헤더 파일

struct NODE {    // 연결 리스트의 노드 구조체
	struct NODE *next;    // 다음 노드의 주소를 저장할 포인터
	int data;             // 데이터를 저장할 멤버
};

void addFirst(struct NODE *target, int data)    // Head라는 기준 노드 뒤에 노드를 추가하는 함수
{
	struct NODE *newNode = (struct NODE*) malloc(sizeof(struct NODE));    // 새 노드 생성
	newNode->next = target->next;    // 새 노드의 다음 노드에 기준 노드의 다음 노드를 지정
	newNode->data = data;            // 데이터 저장

	target->next = newNode;    // 기준 노드의 다음 노드에 새 노드를 지정
}

void addLast(struct NODE *target, int data) //  제일 오른쪽 노트 뒤에 노드를 추가하는 함수 
{
	struct NODE *newNode = (struct NODE*) malloc(sizeof(struct NODE));
	newNode->next = NULL; // 새로운 노드가  가리키는 노드가 더이상 없을것이므로 NULL을 명시함. 
	newNode->data = data; // 새로운 노드에 새로운 데이터를 저장

	struct NODE *temp = target; 
	while (temp->next != NULL) // 마지막 노드를 찾는 루프
	{
		temp = temp->next; 
	}
	temp->next = newNode; // 새로 생성한 노드를 제일 마지막 노드에 연결

}

int main()
{
	struct NODE *head = (struct NODE*) malloc(sizeof(struct NODE));    // 머리 노드 생성
	// 머리 노드는 데이터를 저장하지 않음
	head->next = NULL;

	for (int i = 1; i < 100; i++){
		//addFirst(head, i*10);    // 머리 노드 뒤에 새 노드 추가
		addLast(head,i*10);  // 가장 오른쪽에 노드를 새 노드 추가 
		//removeNode(50); 
	}

	struct NODE *curr = head->next;    // 연결 리스트 순회용 포인터에 첫 번째 노드의 주소 저장
	while (curr != NULL)               // 포인터가 NULL이 아닐 때 계속 반복
	{
		printf("%d\n", curr->data);    // 현재 노드의 데이터 출력
		curr = curr->next;             // 포인터에 다음 노드의 주소 저장
	}

	curr = head->next;      // 연결 리스트 순회용 포인터에 첫 번째 노드의 주소 저장
	while (curr != NULL)    // 포인터가 NULL이 아닐 때 계속 반복
	{
		struct NODE *next = curr->next;    // 현재 노드의 다음 노드 주소를 임시로 저장
		free(curr);                        // 현재 노드 메모리 해제
		curr = next;                       // 포인터에 다음 노드의 주소 저장
	}

	free(head);    // 머리 노드 메모리 해제

	return 0;
}

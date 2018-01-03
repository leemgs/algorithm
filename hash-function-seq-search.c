// http://micropilot.tistory.com/m/3121

#include <stdio.h>
#include <stdlib.h> // malloc(), free()
#include <string.h> // strcmp(), strcpy()

// 구조체 선언
struct User {
	int num;
	char name[16];
	char phone[16];
};

// 구조체 인스턴스 생성
struct User* createUser(int num, char* name, char* phone) {
	// 아래의 pUser 지역변수는 이 함수가 종료되면 해제되더라도 
	// malloc()을 이용하여 할당된 메모리는 명시적으로 free() 
	// 함수를 사용해야만 해제된다
	struct User* pUser = malloc(sizeof(struct User));
	pUser->num = num;
	strcpy(pUser->name, name);
	strcpy(pUser->phone, phone);
	return pUser;
}

// 구조체 배열 선언(전역변수, Global Variable)
struct User* users[20];

// 구조체 배열 안에서 이름으로 검색
struct User* findUser(char* name, int size) {
	for (int i = 0; i < size; i++) {
		if (strcmp(users[i]->name, name)==0) {
			printf("name:%s\n", users[i]->name);
			return users[i];
		}
	}
	printf("검색실패! \n");
	return NULL;
}

// 구조체 인스턴스 내용 출력
void printUser(struct User* user) {
	printf("번호:%d, 이름:%s, 전화:%s \n", 
		user->num, user->name, user->phone);
}

int main()
{
	printf("Hashtable 1, 구조체 배열및 검색 \n");

	//구조체 배열을 생성한다
	int i = 0;
	struct User* pu = createUser(10, "홍길동", "010-9786-1976");
	users[i++] = pu;
	users[i++] = createUser(11, "문재인", "010-9513-7891");
	users[i++] = createUser(12, "안철수", "010-2798-7895");
	users[i++] = createUser(13, "홍준표", "010-7852-9193");
	users[i++] = createUser(14, "유승민", "010-9761-9713");

	struct User* u = findUser("안철수", i);

	printUser(u);

	return 0;
}

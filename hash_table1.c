#define _CRT_SECURE_NO_WARNINGS
#define HASH_KEY	10
#include <stdio.h>
#include <string.h>
// user라는 구조체 변수를 만든다. 
struct user{
	char name[10];
	int score;
};
struct user data[10];

void find(char name[10], int key_value) // 해당 정보를 찾아서 출력한다. 
{
	printf("[RESULT] %s: %d\n", data[key_value].name, data[key_value].score);
}
int hash_table(int score) // 해시테이블 함수를 만든다. 
{
	return score % HASH_KEY; 
}

void insert(char name[10], int score) // 데이타를 입력한다. 
{
	int index; 
	index = hash_table(score);
	strcpy(data[index].name, name);
	data[index].score = score;
}
int main(void)
{
	// 데이타 (성명, 점수)를 입력한다.
	insert("김철수",30);
	insert("김수연", 28);
	insert("김현준", 96);
	insert("김희지", 95);
	insert("김은혜", 37);
	insert("김은정", 74);
	// 김은혜의 index 값 7으로 해당 정보를 곧바로 출력한다. 
	find("김은혜", 7);
	return 0; 

}

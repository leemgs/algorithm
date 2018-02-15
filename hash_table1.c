#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
// user라는 구조체 변수를 만든다. 
struct user{
	char name[10];
	int score;
};
struct user data[10];
#define HASH_KEY	10

// find 함수를 만든다. 
void find(char name[10], int key_value)
{
	printf("[RESULT] %s: %d\n", data[key_value].name, data[key_value].score);
}
int hash_table(int score)
{
	return score % HASH_KEY; 
}

int main(void)
{
	char name[10];
	int score, index; 

	// 데이타 (성명, 점수)를 입력한다.
	strcpy(name, "김철수");
	score = 30;
	index = hash_table(score); 
	strcpy(data[index].name, name);
	data[index].score = score;

	strcpy(name, "김수연");
	score = 28;
	index = hash_table(score);
	strcpy(data[index].name, name);
	data[index].score = score;

	strcpy(name, "김현준");
	score = 96;
	index = hash_table(score);
	strcpy(data[index].name, name);
	data[index].score = score;

	strcpy(name, "김희지");
	score = 95;
	index = hash_table(score);
	strcpy(data[index].name, name);
	data[index].score = score;

	strcpy(name, "김은혜");
	score = 37;
	index = hash_table(score);
	strcpy(data[index].name, name);
	data[index].score = score;

	strcpy(name, "김은정");
	score = 74;
	index = hash_table(score);
	strcpy(data[index].name, name);
	data[index].score = score;

	// 김은혜의 index 값 10으로 해당 정보를 곧바로 출력한다. 
	find("김은혜", 7);

	return 0; 

}

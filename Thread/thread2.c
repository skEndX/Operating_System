#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define MAX 20

DWORD WINAPI ThreadFunc(LPVOID n)
{
	//최적화를 하지 않기 위해 volatile 사용
	for (volatile int i = 0; i < 1000000000; i++);	
	return 0;
}

int main() {
	clock_t start, finish;
	double time;
	DWORD thread;
	HANDLE thrd[MAX];

	int i;
	start = clock();//현재 시간 반환

	for (i = 0; i < MAX; i++) {
		thrd[i] = CreateThread(NULL, 0, ThreadFunc, (LPVOID)i, 0, &thread);
	}

	//thread가 다 끝날 때까지 기다림
	//WaitForMultipleObjects(MAX, thrd, TRUE, INFINITE);	

	for (i = 0; i < MAX; i++) {
		CloseHandle(thrd[i]);	//열려진 핸들을 닫음
	}
	//종료 시간
	finish = clock();

	//CLOCKS_PER_SEC로 나누줌 -> 초 단위로 바꾸기 위해서
	//thread가 생성되는데 소요한 시간
	time = (double)(finish - start) / CLOCKS_PER_SEC;	
	printf("소요시간 : %f 초\n", time);
	return 0;
}

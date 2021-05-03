#include <stdio.h>
#include <Windows.h>  

DWORD WINAPI Thread1(PVOID pArg);
DWORD WINAPI Thread2(PVOID pArg);
DWORD WINAPI Thread3(PVOID pArg);

//우선 순위를 정해 계속적으로 똑같은 thread 동적하는 프로그램
//scanf를 사용했을 때 수업시간에 했던 thread예제처럼 랜덤적으로 동작하는지 확인
//scanf를 I/O 명령어로 키보드 input을 받을 때까지 블락을 걸어놓음
//동작 구체적으로 어떻게 되는지 설명 보충
//그 때문에 thread가 랜덤적으로 작동하지 않고 한 번 정해진 순서대로 동작함.

DWORD WINAPI Thread1(PVOID pArg) {
	int i = 1;
	int v;
	while (1)
	{
		//for (volatile int s = 0; s < 1000000000; s++);
		scanf("%d", &v);
		printf("%d thread 1\n", v);
		//for (volatile int s = 0; s < 1000000000; s++);
	}
	return 0;
}

DWORD WINAPI Thread2(PVOID pArg) {
	int i = 1;
	int v;
	while (1)
	{
		//for (volatile int s = 0; s < 1000000000; s++);
		scanf("%d", &v);
		printf("%d thread 2\n", v);
		//for (volatile int s = 0; s < 1000000000; s++);
	}
	return 0;
}
DWORD WINAPI Thread3(PVOID pArg) {
	int i = 1;
	int v;
	while (1)
	{
		//for (volatile int s = 0; s < 1000000000; s++);
		scanf("%d", &v);
		printf("%d thread 3\n", v);
		//for (volatile int s = 0; s < 1000000000; s++);

	}
	return 0;
}

int main() {
	HANDLE hThread1, hThread2, hThread3;
	DWORD dwThreadID1 = 0, dwThreadID2 = 1, dwThreadID3 = 2;
	int i = 1;	int v;


	//Thread를 만듦
	hThread1 = CreateThread(NULL, 0, Thread1, (PVOID)0, 0, &dwThreadID1);
	CloseHandle(hThread1);

	hThread2 = CreateThread(NULL, 0, Thread2, (PVOID)0, 0, &dwThreadID2);
	CloseHandle(hThread2);

	hThread3 = CreateThread(NULL, 0, Thread3, (PVOID)0, 0, &dwThreadID3);
	CloseHandle(hThread3);

	while (1) {
		//for (volatile int s = 0; s < 1000000000; s++);
		scanf("%d", &v);
		printf("%d main\n", v);
		//for (volatile int s = 0; s < 1000000000; s++);

	}
	return;
}
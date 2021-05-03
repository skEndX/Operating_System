#include<stdio.h>
#include<windows.h>

// Double word
int num1[10] = { 0, };
int num2[10] = { 0, };

DWORD WINAPI Thread0(PVOID pArg)
{
	int i = 0;
	while (i < 10)
	{
		printf("%d + %d = %d\n", num1[i], num2[i], num1[i] + num2[i]);
		i++;
		//기다린다는 의미도 있지만 scheduling을 요청하는 것
		Sleep(1000);	//1000일 때 1초
	}
	return 0;
}
DWORD WINAPI Thread1(PVOID pArg)
{
	int i = 0;
	while (i < 10)
	{
		printf("%d - %d = %d\n", num1[i], num2[i], num1[i] - num2[i]);
		i++;
		Sleep(1000);
	}
	return 0;
}
DWORD WINAPI Thread2(PVOID pArg)
{
	int i = 0;
	while (i < 10)
	{
		printf("%d * %d = %d\n", num1[i], num2[i], num1[i] * num2[i]);
		i++;
		Sleep(1000);
	}
	return 0;
}



int main()
{
	HANDLE hThread[3]; 
	DWORD dwThreadID[3] = { 0,1,2 };

	for (int i = 0; i < 10; i++)
	{
		num1[i] = 5 * i;
		num2[i] = 3 * i;
	}

	int i = 0;

	//Thread를 생성하고 동작하도록 함
	hThread[0] = CreateThread(NULL, 0, Thread0, (PVOID)0, 0, &dwThreadID[0]);
	hThread[1] = CreateThread(NULL, 0, Thread1, (PVOID)0, 0, &dwThreadID[1]);
	hThread[2] = CreateThread(NULL, 0, Thread2, (PVOID)0, 0, &dwThreadID[2]);

	for (int k = 0; k < 3; k++)
	{
		CloseHandle(hThread[k]);	//생성 후, handle를 닫음
	}

	while (i < 10)
	{
		printf("main\n");
		Sleep(1000);
		i++;
	}

	//WaitForMultipleObjects가 없다면 한 번 정한 우선순위는 그래도 동작, sleep때문
	WaitForMultipleObjects(4, hThread, 1, INFINITE);	
	//Main에서 thread를 생성하기 때문에 main이 끝나버리면 thread 사라짐
	return;
}

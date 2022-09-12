//app.c
#include "std.h"
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
void app_init()
{
	FILE* fp = fopen("list.txt", "a");
	fclose(fp);
	readlist();
	logo();
}

void app_run()
{
	while (1)
	{
		system("cls");
		
		char ch = menuprint();
		switch (ch)
		{
		case '1': con_printall(); break;
		case '2': con_insert(); break;
		case '3': con_select();	break;
		case '4': con_update();	break;
		case '5': con_update1(); break;
		case '6': con_update2(); break;
		case '7': con_delete();	break;
		case '8': return;
		}

		system("pause");
	}
}

void app_exit()
{
	ending();
}

void logo()
{
	system("cls");		
	printf("\n\n\n\n\n\n\n\n\n");
	printf("\t\t\t\t\t��������������������������������������������\n");
	printf("\t\t\t\t\t��  �������� ���α׷� ��\n");
	printf("\t\t\t\t\t��                    ��\n");
	printf("\t\t\t\t\t��    ���������� ��   ��\n");
	printf("\t\t\t\t\t��������������������������������������������\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	system("pause");
}

void ending()
{
	system("cls");
	printf("��������������������������������������������������������������������������������������������������������������������������������������������������������\n");
	printf("\t\t\t ���α׷��� �����մϴ�.\n");
	printf("��������������������������������������������������������������������������������������������������������������������������������������������������������\n");
	system("pause");
}

char menuprint()
{
	printf("\n\n\n\n\n\n");
	printf("\t\t\t\t\t����������������������������������������������������������������\n");
	printf("\t\t\t\t\t��                              ��\n");
	printf("\t\t\t\t\t��        �� �� �� �� ��        ��\n");
	printf("\t\t\t\t\t��                              ��\n");
	printf("\t\t\t\t\t����������������������������������������������������������������\n");
	printf("\t\t\t\t\t����������������������������������������������������������������\n");
	printf("\t\t\t\t\t��                              ��\n");
	printf("\t\t\t\t\t��       [1] �� ��  �� ��       ��\n");
	printf("\t\t\t\t\t��       [2] �� ��  �� ��       ��\n");
	printf("\t\t\t\t\t��       [3] �� ��  �� ��       ��\n");
	printf("\t\t\t\t\t��       [4] �� ��  �� ��       ��\n");
	printf("\t\t\t\t\t��       [5] �� ��  �� ��       ��\n");
	printf("\t\t\t\t\t��       [6] �� ��  �� ��       ��\n");
	printf("\t\t\t\t\t��       [7] �� ��  �� ��       ��\n");
	printf("\t\t\t\t\t��       [8] ���α׷�����       ��\n");
	printf("\t\t\t\t\t��                              ��\n");
	printf("\t\t\t\t\t����������������������������������������������������������������\n\n\n\n");

	char ch = _getch(); 
	savelist();
	return ch;
	
}

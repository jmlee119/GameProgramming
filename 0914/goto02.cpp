#include <stdio.h>
#include <windows.h>
void gotoxy(int x, int y);
int main(void)
{
	int dan,i,j;
//	printf("Dan input : ");
//	scanf("%d",&dan);
////	for(i=1; i<=9; i++)
////	{
////		gotoxy(35, 5+i);
////		printf("%d*%d=%2d",dan,i,dan*i);
////	}
	for (i=1; i<=9; i++) {
		for(j=1; j<=9; j++){
			gotoxy(10*j,i);
			printf("%d X %d=%2d\n",i,j,i*j);
		}
		printf("\n");
	}
	printf("\n");
	return 0;
}
void gotoxy(int x, int y)
{
	COORD Pos = {x - 1, y - 1};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
	
//3�� ���

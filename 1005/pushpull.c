#include <stdio.h>
#include <conio.h>
#include <windows.h>
void gotoxy(int x, int y)
{
  COORD coord;
  coord.X = x;
  coord.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}


void pushpull(void);


// _getch() value of ESC key
#define MAGIC_KEY 224
#define ESC 27
#define A 65
#define a 97
#define L 76
#define l 108
#define ENTER 13

void menu_draw(void);
void game_fun(void);
void start_game(void);

char key;
char t_name1[20];
char t_name2[20];
int x = 40;
int y = 11;
int win = 0;
int win_lose = 0;
int input = 0;

enum MENU
{
	GAMESTART = 0,
	RULE,
	EXIT
};

enum KEYBOARD
{
	UP = 72,
	LEFT = 75,
	RIGHT = 77,
	DOWN = 80
};

// ���� ���� �Լ�
void menu_draw() {
	system("cls");
	gotoxy(37, 5);
	printf("�ڡڡڡڡڡڡڡڡڡ� �ٴٸ��� �ڡڡڡڡڡڡڡڡ�");
	printf("��");
	gotoxy(37, 7);
	printf("��         AŰ�� LŰ�� �������� ��Ÿ!!          ��");
	gotoxy(37, 9);
	printf("�� ���� ���� ���� �ڱ������� ���� �����Դϴ�! ��");
	gotoxy(37, 11);
	printf("��                 ���� �º�!                   ��");
	gotoxy(37, 13);
	printf("��   �ƹ�Ű�� ������ �޴�ȭ������ ���ư�����    ��");
	gotoxy(37, 15);
	printf("�ڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡڡ�");

	char kk = _getch();
}

// ���� ����ȭ�� �Լ�
void main_show() {
	system("cls");
	gotoxy(36, 10);
	printf("�ڡڡڡڡڡڡڡڡڡ� �ٴٸ��� �ڡڡڡڡڡڡڡڡڡ�");

	gotoxy(28, 10);
	printf("��");
	gotoxy(27, 11);
	printf("��|/");
	gotoxy(28, 12);
	printf(" |");
	gotoxy(28, 13);
	printf("/��");

	gotoxy(90, 10);
	printf(" ��");
	gotoxy(89, 11);
	printf("��|/");
	gotoxy(90, 12);
	printf(" |");
	gotoxy(90, 13);
	printf("/��");

	gotoxy(56, 13);
	printf("���� ����");

	gotoxy(56, 15);
	printf("���� ���");
	
	gotoxy(56, 17);
	printf("���� ����");

}

// �޴� ���� Ŀ�� �Լ�
enum MENU game(){
	int y = 0; 
	while (1){
		main_show();

		if (y <= 0)        
		{
			y = 0;
		}
		else if (y >= 6)
		{
			y = 2;
		}

		gotoxy(53, 13 + y); 
		printf(">");
		input = _getch();   

		if (input == MAGIC_KEY) 
		{
			switch (_getch())
			{
			case UP:            
				gotoxy(53, 13 + y);
				printf("  ");
				y = y - 2;
				break;
			case DOWN:           
				gotoxy(53, 13 + y);
				printf("  ");
				y = y + 2;
				break;
			}
		}
		else if (input == 13)
		{
			switch (y)            
			{
			case 0:   
				return GAMESTART;
			case 2:    
				return RULE;
			case 4:  
				return EXIT;
			}
		}
	}
}



void start_game() {
	system("cls");
	gotoxy(47, 10);
	printf("���� �� �� �̸��� �����ּ���!\n");
	gotoxy(47, 12);
	printf("ù��° �� �̸��Է� �� ����!> ");
	scanf("%s", &t_name1, 20);
	gotoxy(47, 14);
	printf("�ι�° �� �̸��Է� �� ����!> ");
	scanf("%s", &t_name2, 20);

	// �̸� �Է� �� ȭ�� �����
	system("cls");
	//line �׷���
	line(x, y);
	//�����Լ� ����
	game_fun();
}

void game_fun() {
	while (1) {
		char click = _getch();

		switch (click) {
		case 97: case 65: // A
			x -= 2;
			line(x, y);
			Sleep(100);
			if (x == 28) {
				gotoxy(57, 15);
				printf("%s �¸�!", t_name1);
				gotoxy(48, 17);
				printf("2�� �� ����ȭ������ ���ư��ϴ�.");
				Sleep(2000);
				pushpull();
			}
			break;

		case L: case l: // L
			x += 2;
			line(x, y);
			Sleep(100);
			if (x == 52) {
				gotoxy(57, 15);
				printf("%s �¸�!", t_name2);
				gotoxy(48, 17);
				printf("2�� �� ����ȭ������ ���ư��ϴ�.");
				Sleep(2000);
				pushpull();
			}
			break;
		case ESC:
			pushpull();
		}
	}
}

// �ٴٸ��� �׷��ִ� �Լ�
void line(int x, int y)
{
	system("cls");
	
	int i, line[21] = { 0 };
	line[10] = 1;
	line[4] = 2;
	line[16] = 2;
	gotoxy(31, 13);
	for (i = 0; i < 78; i++)
		printf(" ");

	gotoxy(28, 8);
	printf("%s", t_name1);
	gotoxy(86, 8);
	printf("%s", t_name2);

	gotoxy(30, 10);
	printf("��");
	gotoxy(29, 11);
	printf("��|/");
	gotoxy(30, 12);
	printf(" |");
	gotoxy(30, 13);
	printf("/��");

	gotoxy(87, 10);
	printf(" ��");
	gotoxy(86, 11);
	printf("��|/");
	gotoxy(87, 12);
	printf(" |");
	gotoxy(87, 13);
	printf("/��");

	gotoxy(42, 2);
	printf("�������� �ʴ´ٸ� �ѿ�Ű�� �ٲ㺸����!");

	// x,y�Լ��� line�׷��� x =40, y = 11
	gotoxy(x, y);
	for (i = 0; i < 21; i++)
		if (line[i] == 0)
			printf("��");
		else if (line[i] == 1)
			printf("��");
		else
			printf("��");

	gotoxy(58, 8);
	printf("������");
	gotoxy(60, 10);
	printf("��");
	gotoxy(60, 12);
	printf("��");

	gotoxy(45, 19);
	printf("�޴��� ���ư����� ESC�� �����ּ���\n");

	char end = _getch();
	if (end == ESC) {
		pushpull();
	}

}
// ���� ���� ���� �Լ�
void pushpull() {
	system("cls");
	while (1) {
		switch (game()) {
			case GAMESTART:
				x = 40;
				start_game();
				break;
	
			case RULE:
				menu_draw();
				break;
	
			case EXIT:
				exit(0);
				
		}
	}
}

int main() {
	pushpull();
	
	return 0;
}

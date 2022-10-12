#include <stdio.h>
#include <conio.h>
#include <windows.h>

#define MAGIC_KEY 224
#define A 65
#define a 97
#define L 76
#define l 108

#define ESC 27
#define ENTER 13 
#define AA 523  //�� 
#define B 587  //��
#define C 659  //�� 
#define D 698  //�� 
#define E 784  //�� 
#define F 880  //�� 
#define G 998  //�� 
#define H 1047  //�� 


void gotoxy(int x, int y);
void display_line();
double intro_game();
void game_control();
int menuDraw();
void pushpull();
void info();
int input=0,x=20, y=11; 


char t_name1[20];
char t_name2[20];
int score_win[2]={0}, score_loose[2]={0};

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

int main(void)
{
	system("title �ٴٸ��� ����");
	pushpull();


	return 0;
}

int menuDraw() {
	system("cls");
	printf("\n\n");
	printf("            ####        #     ##       ##    ##### \n");
	printf("          #            # #    # #     # #    #     \n");
	printf("          #   ##      #####   #  #   #  #    ##### \n");
	printf("          #     #    #    #   #   # #   #    #     \n");
	printf("           #####     #    #   #    #    #    ##### \n\n\n");
	gotoxy(56, 12);
	printf("---------------- \n");
	gotoxy(56, 13);
	printf("��  ���� ����   ��\n");
	gotoxy(56, 14);
	printf("---------------- \n");
	gotoxy(56, 15);
	printf("��  ���� ���   ��\n");
	gotoxy(56,16);
	printf("---------------- \n");	
	gotoxy(56, 17);
	printf("��  ���� ����   ��\n");
	gotoxy(56,18);
	printf("---------------- \n");
}

enum MENU game(){
	int y = 0; 
	menuDraw();
	while (1){
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
				Beep(AA,500);
				gotoxy(53, 13 + y);
				printf("  ");
				y = y - 2;
				break;
			case DOWN:     
				Beep(AA,500);      
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

void info() {
	system("cls");
	printf("\n \n"); 
	printf("                    ������ �ٴٸ��� �����Դϴ�. \n");
	printf("                 a Ű�� l �� ��Ÿ�Ͽ� ���� ���� �˴ϴ�. \n");

	printf("                       �����ڴ� �� ���Դϴ�. \n\n");
	printf("           �����̽� ȭ���� ������ ����ȭ������ �̵��մϴ�. \n");
	
	char kk = _getch();
}


void gotoxy(int x, int y) // �ܼ�â���� Ŀ���� ������� �̵�  
{
   COORD Pos = {x - 1, y - 1};
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void display_line(int x, int y)
{
	int i;
	system("cls");
	gotoxy(25,5);
	printf("*******************************�ٴٸ���**********************************");
	for (i=0; i<10; i++) {
		gotoxy(25,6+i);
		printf("*");
		gotoxy(97,6+i);
		printf("*");
	}
	printf("\n");
	gotoxy(25,15);
	printf("*************************************************************************");
	gotoxy(35,16);
	printf("�̵��� ���� �ʴ´ٸ� �ѿ�Ű�� �ٲ㺸����!");
	int line[21]={0};
	line[10]=1;
	line[4]=2;
	line[16]=2;
	gotoxy(31, 13);
	for(i=0;i<78;i++)
		printf(" ");

	gotoxy(30,6);
	printf("%s",t_name1);

	gotoxy(86,6);
	printf("%s",t_name2);
	for (i=0; i<2; i++) {
		gotoxy(i*56+30,7);
		printf("%d�� %d��",score_win[i] ,score_loose[i]);
	}
	gotoxy(30, 10);
	printf(" ��");
	gotoxy(29, 11);
	printf("--|--");
	gotoxy(30, 12);
	printf(" |");
	gotoxy(30, 13);
	printf("/��");
	gotoxy(87, 10);
	printf("��");
	gotoxy(86, 11);
	printf("--|--");
	gotoxy(87, 12);
	printf(" |");
	gotoxy(87, 13);
	printf("/��");
	

	// �ٴٸ��� ���� ����ϴ� �Լ�  

	gotoxy(x, y);
	
	for(i=0;i<21;i++)
		if (line[i]==0)
			printf("��");
		else if (line[i]==1)
			printf("��");
		else
			printf("��");
				gotoxy(56, 6);
	gotoxy(59,9);
	printf("������");
	gotoxy(60, 10);
	printf("��");
	gotoxy(60, 12);
	printf("��");

}
double intro_game()
//���ӿ� ���� ����, �����ڿ� ���ѽð��� �Է¹޴� �Լ� intro_game 
{
	int i;
	system ("cls");
	printf("ù���� �������� �̸��� �Է��ϰ� Enter>");
	scanf("%s", &t_name1);
	printf("\n");
	
	printf("�ι�° �������� �̸��� �Է��ϰ� Enter>"); 
	scanf("%s", &t_name2);
	
	
	display_line(x,y);
	game_control();
}

void game_control()
{
	
	while ((score_win[0]<2) && (score_win[1]<2)) {
		char click = _getch();
		switch (click) {
		case 97: case 65: // A
			x -= 2;
			display_line(x, y);
			Sleep(10);
			if (x == 28) {

				gotoxy(57, 20);
				printf("%s �¸�!", t_name1);
				Sleep(1500);
				score_win[0] +=1;
				score_loose[1] +=1;
				gotoxy(48, 17);
				x=40, y=11;
				display_line(x,y);
			}
			break;

		case L: case l: // L
			x += 2;
			display_line(x, y);
			Sleep(10);
			if (x == 52) {

				gotoxy(57, 20);
				printf("%s �¸�!", t_name2);
				Sleep(1500);
				score_win[1] +=1;
				score_loose[0] +=1;
				gotoxy(48, 17);
				x=40, y=11;
				display_line(x,y);
			}
			break;
		case ESC:
			pushpull();
		}
	}
	if (score_win[0] ==2) {

		system("cls");
		gotoxy(50,10);
		printf("%s ���� �¸��Ͽ����ϴ� \n" ,t_name1);
		gotoxy(45,11);
		printf("5�� �� ���� ȭ������ �̵��մϴ�.");
		Beep(AA,350);
		Beep(C,350);
		Beep(E,350);
		
		Sleep(5000);
	}
	else if(score_win[1]==2) {

		system("cls");
		gotoxy(50,10);
		printf("%s ���� �¸��Ͽ����ϴ�\n" ,t_name2);
		gotoxy(45,11);
		printf("5�� �� ���� ȭ������ �̵��մϴ�.");
		Beep(AA,300);
		Beep(C,300);
		Beep(E,300);
		
		Sleep(5000);
	}
	gotoxy(30, 1);

}


// ���� ���� ���� �Լ�
void pushpull() {
	system("cls");
	while (1) {
		switch (game()) {
			case GAMESTART:
				x = 40;
				intro_game();
				break;
	
			case RULE:
				info();
				break;
	
			case EXIT:
				exit(0);
				
		}
	}
}

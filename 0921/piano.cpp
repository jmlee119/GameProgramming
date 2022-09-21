	#include<stdio.h>
	#include<math.h>
	#include<conio.h>
	#include<windows.h>
	
	int calc_frequency(int octave, int inx);
	void practice_piano(void);
	void school_piano(void);
	
	int main(void)
	{
	   printf("�б����� ������")
	   school_piano(); 
	   return 0;
	}
	
	void school_piano(void) {
		int sheet[] = { 5, 5, 6, 6, 5, 5, 3, 5, 5, 3, 3, 2, 5, 5, 6, 6, 5, 5, 3, 5, 3, 2, 3, 1 };
		int i;
		int freq[24];
		for (i=0; i<24; i++) {
			freq[i] = calc_frequency(4,sheet[i]);
		}
		for (i=0; i<=23; i++) {
			Beep(freq[i],500);
		} 
	}
	
	int calc_frequency(int octave, int inx) // ��Ÿ�꿡 ���� ���躰 ���ļ��� ��ȯ�ϴ� �� �� 
	{
	   double do_scale = 32.7032;
	   double ratio = pow(2.,1/12.), temp;
	   int i;
	   temp = do_scale*pow(2, octave-1);
	   for(i=0;i<inx;i++)
	   {
	      temp = (int)(temp+0.5);
	      temp *= ratio;
	   }
	   return (int)temp;
	}
	
	void practice_piano(void) // ����Ű�� ���� ������ ���ļ��� ����Ŀ�� ��� �� �� 
	{
	   int index[] = {0,2,4,5,7,9,11,12};
	   int freq[8], code, i;
	   for(int i=0;i<8;i++)
	      freq[i] = calc_frequency(4,index[i]);
	   do
	   {
	      code = getch();
	      if('1'<=code && code<='8')
	      {
	         code -= 49;
	         Beep(freq[code],300);
	      }
	   }while(code!=27);
	}
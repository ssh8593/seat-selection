#include <stdio.h>
#include <string.h>

char seat[4][9];
void printSeat();
int main()
{
	int tot = 0;
	int movie = 0;
	char yes = 0, time = 0;
	int x = 0, y = 0, z = 0, c = 0;
	memset(seat, 'x', sizeof(seat));
	
//1.  ��ȭ�� 36�¼��� �¼�����

	while (1)
	{
		printSeat();
		printf("\n�¼��� ���� �Ͻðڽ��ϱ� ? (y / n) : \n");
		scanf(" %c", &yes);
		
		if (yes == 'y')
		{
			printf("�¼� �Է� ( ��, �� ) : ");
			scanf("%d %d", &x, &y);
			rewind(stdin);
			seat[x][y] = 'O';

//2.  ����,�ɾ� ���� �ð� ����

			printf("�ð��� �������ּ���.\n");
			printf("---------------------\n");
			printf("z = 08:00 - 10:00  \nx = 11:00 - 12:00 \nc = 24:00 - 02:00\n");
			printf("---------------------\n");
			
			scanf(" %c", &time);
			movie = 10000;

/*3. ([����,�ɾ� ������ 20% ����� 10% (�ߺ� ���� �Ұ�)
	 ([20%] 10000�� -> 8000��, 20000�� -> 16000��) 
	 ([10%] 10000�� -> 9000��, 20000�� -> 18000��)        
	 �ο��� + ������ % = �ѱݾ� ����.*/

			if (time == 'z' || time == 'c')
			{
				tot = movie *0.8;           
				printf("����,�ɾ� ������ �ѱݾ���:%d��\n", tot);
			}
			else if (time == 'x')
			{
				printf("\n����� ������ �����Ͻðڽ��ϱ�?? (y / n) : ");
				scanf(" %c", &yes);
				//rewind(stdin);
				while (getchar() == '\n')break;		//\n �� �������ֱ⶧����(�Է�) ���
				if (yes == 'y')
				{
					tot = movie *0.9;
					printf("�ѱݾ���:%d��\n", tot);
					//rewind(stdin);
					//while (getchar() == '\n')break;
				}
				else if (yes == 'n')
				{
					printf("�ѱݾ���:%d��\n", movie);
					rewind(stdin);
				}
				else
				{
					printf("\n y �Ǵ� n�� �����ּ���.");
					rewind(stdin);
				}
			}
			else
			{
				printf("\n z �Ǵ� c �Ǵ� x�� �����ּ���.");
				rewind(stdin);
			}
		}
		else if (yes == 'n')
			break;

		else
		{
			printf("\n y �Ǵ� n�� �����ּ���.");
			rewind(stdin);
		}
	}
}
//5. ���� ���� �¼� ������ �¼� ���� �ݺ�.(���� �Ϸ� �¼��� 0�� ǥ��)])

void printSeat()
{
	int i = 0, j = 0;
	printf("\t0\t1\t2\t3\t4\t5\t6\t7\t8\n");
	for (i = 0; i < 4; i++)
	{
		printf("%d\t", i);
		for (j = 0; j < 9; j++)
		{
			printf("%c\t", seat[i][j]);
		}
		printf("\n");
	}
	printf("0~8 �¼� ���� / x = ���¼� / O = ���ſϷἮ\n");
}
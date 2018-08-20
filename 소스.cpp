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
	
//1.  영화관 36좌석중 좌석선택

	while (1)
	{
		printSeat();
		printf("\n좌석을 예매 하시겠습니까 ? (y / n) : \n");
		scanf(" %c", &yes);
		
		if (yes == 'y')
		{
			printf("좌석 입력 ( 행, 열 ) : ");
			scanf("%d %d", &x, &y);
			rewind(stdin);
			seat[x][y] = 'O';

//2.  조조,심야 할인 시간 선택

			printf("시간을 선택해주세요.\n");
			printf("---------------------\n");
			printf("z = 08:00 - 10:00  \nx = 11:00 - 12:00 \nc = 24:00 - 02:00\n");
			printf("---------------------\n");
			
			scanf(" %c", &time);
			movie = 10000;

/*3. ([조조,심야 할인율 20% 멤버십 10% (중복 할인 불가)
	 ([20%] 10000원 -> 8000원, 20000원 -> 16000원) 
	 ([10%] 10000원 -> 9000원, 20000원 -> 18000원)        
	 인원수 + 할인율 % = 총금액 산출.*/

			if (time == 'z' || time == 'c')
			{
				tot = movie *0.8;           
				printf("조조,심야 할인후 총금액은:%d원\n", tot);
			}
			else if (time == 'x')
			{
				printf("\n멤버십 할인을 선택하시겠습니까?? (y / n) : ");
				scanf(" %c", &yes);
				//rewind(stdin);
				while (getchar() == '\n')break;		//\n 가 읽힐수있기때문에(입력) 사용
				if (yes == 'y')
				{
					tot = movie *0.9;
					printf("총금액은:%d원\n", tot);
					//rewind(stdin);
					//while (getchar() == '\n')break;
				}
				else if (yes == 'n')
				{
					printf("총금액은:%d원\n", movie);
					rewind(stdin);
				}
				else
				{
					printf("\n y 또는 n를 눌러주세요.");
					rewind(stdin);
				}
			}
			else
			{
				printf("\n z 또는 c 또는 x를 눌러주세요.");
				rewind(stdin);
			}
		}
		else if (yes == 'n')
			break;

		else
		{
			printf("\n y 또는 n을 눌러주세요.");
			rewind(stdin);
		}
	}
}
//5. 이전 예매 좌석 제외후 좌석 선택 반복.(예매 완료 좌석은 0로 표시)])

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
	printf("0~8 좌석 라인 / x = 빈좌석 / O = 예매완료석\n");
}
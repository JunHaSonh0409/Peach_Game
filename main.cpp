#include <stdio.h>
#include <stdlib.h>
#include <string>
#include"apple.h"
#include <time.h>
#include <iostream>
int score = 0;
int lifecount = 0;
bool clicks = false;
extern Mat bok[5];
Point cp;
extern Point up[5][5];
extern Point down[5][5];
extern Point bokup[5],bokdown[5];

void onMouse(int event, int x, int y, int flags, void* userdata)
{

	if (event == EVENT_LBUTTONDOWN)//사과 다른과일
	{
		cp = Point(x, y);
		clicks = true;
	}
	/*else if (event == EVENT_LBUTTONUP)
	{
		clicks = false;
	}*/
}
int main()
{
	Fruit F;
	clock_t start, end;
	namedWindow("game");
	setMouseCallback("game",onMouse,0);
	string a;
	srand((unsigned int)time(NULL));
	while (1)
	{
		F.setconsol();
		//time_t start = time(NULL);
		start = clock();

		
		while (1) //3초
		{

			if (clicks)
			{
				for (int i = 0; i < 5; i++)
				{
					for (int j = 0; j < 5; j++)
					{
						if (up[i][j].x <= cp.x && down[i][j].x >= cp.x && up[i][j].y <= cp.y && down[i][j].y >= cp.y)
						{
							rectangle(F.getconsol(), Rect((j * 150), (50 + (i * 150)), 150, 150), Scalar(255, 255, 255), -1);//복숭아 좌표 , 스코어 출력
							
							if (bokup[1].x <= cp.x && bokdown[1].x >= cp.x && bokup[1].y <= cp.y && bokdown[1].y >= cp.y||
								bokup[2].x <= cp.x && bokdown[2].x >= cp.x && bokup[2].y <= cp.y && bokdown[2].y >= cp.y||
								bokup[3].x <= cp.x && bokdown[3].x >= cp.x && bokup[3].y <= cp.y && bokdown[3].y >= cp.y||
								bokup[4].x <= cp.x && bokdown[4].x >= cp.x && bokup[4].y <= cp.y && bokdown[4].y >= cp.y||
								bokup[0].x <= cp.x && bokdown[0].x >= cp.x && bokup[0].y <= cp.y && bokdown[0].y >= cp.y)
							{
								score += 10;
								
								a = "score : " + to_string(score);
							}
							else
							{
								lifecount++;
								score -= 5;
								a = "score : " + to_string(score);
								if (lifecount == 5)
								{
									return 0;
								}
								
							}
						}
					}
				}
				clicks = false;
			}
			rectangle(F.getconsol(), Rect(Point(330, 0), Point(550, 50)), Scalar(255, 255, 255), -1);
			putText(F.getconsol(), a, Point(F.getconsol().cols / 2 - 30, 20), FONT_HERSHEY_PLAIN, 2, Scalar::all(0), 1);
			F.sortlife(lifecount);
			F.printconsol();
			waitKey(1);
			end = clock();
			if (end - start > (2 * CLOCKS_PER_SEC))
				break;
		}
		
		F.printconsol();
		waitKey(1);
	}
}

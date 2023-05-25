#include"apple.h"
Mat bok[5];
Point up[5][5];
Point down[5][5];
Mat test[5][5];
Point bokup[5], bokdown[5];
extern int lifecount;

void Fruit::resizeFruit()//과일 및 라이프 사이즈 조정
{
	resize(apple, apple, Size(150, 150));
	resize(apple2, apple2, Size(150, 150));
	resize(boksung, boksung, Size(150, 150));
	resize(jadu, jadu, Size(150, 150));
	resize(strow, strow, Size(150, 150));
	resize(lifes, lifes, Size(30, 30));
}
void Fruit::lineconsol()//라인
{
	int x = 750 / 5;
	int y = (750 / 5);
	line(startconsol, Point(0, 50), Point(750, 50), Scalar(0, 0, 0), 1);
	line(startconsol, Point(x, 50), Point(x, 800), Scalar(0, 0, 0), 1);//세로 라인
	line(startconsol, Point(x * 2, 50), Point(x * 2, 800), Scalar(0, 0, 0), 1);
	line(startconsol, Point(x * 3, 50), Point(x * 3, 800), Scalar(0, 0, 0), 1);
	line(startconsol, Point(x * 4, 50), Point(x * 4, 800), Scalar(0, 0, 0), 1);
	line(startconsol, Point(x * 5, 50), Point(x * 5, 800), Scalar(0, 0, 0), 1);

	line(startconsol, Point(0, 50 + (y * 1)), Point(750, 50 + (y * 1)), Scalar(0, 0, 0), 1);//가로라인
	line(startconsol, Point(0, 50 + (y * 2)), Point(750, 50 + (y * 2)), Scalar(0, 0, 0), 1);
	line(startconsol, Point(0, 50 + (y * 3)), Point(750, 50 + (y * 3)), Scalar(0, 0, 0), 1);
	line(startconsol, Point(0, 50 + (y * 4)), Point(750, 50 + (y * 4)), Scalar(0, 0, 0), 1);
	line(startconsol, Point(0, 50 + (y * 5)), Point(750, 50 + (y * 5)), Scalar(0, 0, 0), 1);
}
Mat Fruit::getconsol()
{
	return startconsol;
}
void Fruit::printconsol()
{
	imshow("game", startconsol);
}
void Fruit::setlife()//라이프위치
{
	int x = 570;
	int y = 0;
	Fruit();
	Mat life;
	Mat glife;
	Mat mask;
	life = imread("C:\\JUNHA\\openCV\\fruit\\life.jpg", IMREAD_COLOR);
	resize(life, life, Size(30, 30));
	cvtColor(life, glife, COLOR_BGR2GRAY);
	threshold(glife, glife, 240, 255, THRESH_BINARY);
	mask = glife.clone();
	Mat inv;
	bitwise_not(mask, inv);
	for (int i = 5; i > 0; i--)
	{
		Mat backcut = startconsol(Rect(Point(x, y), Point(x + 30, y + 30)));
		Mat img1, img2;
		bitwise_and(life, life, img1, inv);
		bitwise_and(backcut, backcut, img2, mask);
		Mat tmp;
		add(img1, img2, tmp);
		tmp.copyTo(startconsol(Rect(Point(x, y), Point(x + 30, y + 30))));
		x += 30;
		
	}
}

void Fruit::setFruits()//과일세팅
{
	resizeFruit();
	Mat Fruits(Size(150, 150), CV_8UC3, Scalar(255, 255, 255));
	int F[5][5];
	int count[25];
	int index = 0;
	int bokn = 0;
	int bokindex = 0;
	for (int i = 0; i < 25; i++)
	{
		count[i] = rand() % 25 + 1;
		for (int j = 0; j < i; j++)
		{
			if (count[i] == count[j])
			{
				i--;
				break;
			}
		}
	}
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			F[i][j] = count[index++];
		}
	}
	for (int i = 0; i < 5; i++)//과일 사진 입히기
	{
		for (int j = 0; j < 5; j++)
		{
			if (F[i][j] >= 1 && F[i][j] < 5)
				apple.copyTo(Fruits);
			else if (F[i][j] >= 5 && F[i][j] < 10)
				apple2.copyTo(Fruits);
			else if (F[i][j] >= 10 && F[i][j] < 15)
			{
				boksung.copyTo(Fruits);
				bokup[bokindex] = Point((j * 150), 50 + (i * 150));
				bokdown[bokindex] = Point(((j + 1) * 150), 50 + ((i + 1) * 150));
				bokindex++;
			}
			else if (F[i][j] >= 15 && F[i][j] < 20)
				jadu.copyTo(Fruits);
			else if (F[i][j] >= 20 && F[i][j] < 25)
				strow.copyTo(Fruits);

		     Mat startconsole_roi(startconsol ,Rect(Point((j * 150), 50 + (i * 150)), Point(((j + 1) * 150), 50 + ((i + 1) * 150))));
			up[i][j] = Point((j * 150), 50 + (i * 150));
			down[i][j] = Point(((j + 1) * 150), 50 + ((i + 1) * 150));
			test[i][j] = startconsole_roi;
			Fruits.copyTo(startconsole_roi);
			startconsole_roi.copyTo(startconsol(Rect(Point((j * 150), 50 + (i * 150)), Point(((j + 1) * 150), 50 + ((i + 1) * 150)))));
		}
	}
}
void Fruit::sortlife(int a)
{
	Fruit();
	int x = 570;
	int y = 0;
	Mat white(Size(30, 30),CV_8UC3, Scalar(255, 255, 255));
	for (int i = 0; i < a; i++)
	{
		Mat backcut= startconsol(Rect(Point(x, y), Point(x + 30, y + 30)));
		white.copyTo(backcut);
		backcut.copyTo(startconsol(Rect(Point(x, y), Point(x + 30, y + 30))));
		x += 30;
	}
}
void Fruit::setconsol()
{
	lineconsol();
	setlife();
	setFruits();
}

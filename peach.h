#include <opencv2/opencv.hpp>
#include <iostream>
#include<vector>
#include<stdlib.h>
#include<time.h>
using namespace cv;
using namespace std;
class Fruit {
public:
	Mat apple=imread("C:\\JUNHA\\openCV\\fruit\\apple.jpg",IMREAD_COLOR);
	Mat apple2 = imread("C:\\JUNHA\\openCV\\fruit\\apple2.jpg", IMREAD_COLOR);
	Mat boksung = imread("C:\\JUNHA\\openCV\\fruit\\boksung.jpg", IMREAD_COLOR);
	Mat jadu = imread("C:\\JUNHA\\openCV\\fruit\\jadu.jpg", IMREAD_COLOR);
	Mat strow = imread("C:\\JUNHA\\openCV\\fruit\\strow.jpg", IMREAD_COLOR);
	Mat startconsol;
	Mat lifes = imread("C:\\JUNHA\\openCV\\fruit\\life.jpg", IMREAD_COLOR);
public:
	Fruit()
	{
		startconsol = Mat(Size(750, 800), CV_8UC3, Scalar(255, 255, 255));
	}
	//과일들 roi함수
	void resizeFruit();//과일 및 라이프 사이즈 조정
	
	void lineconsol();//라인

	void printconsol();
	
	void setlife();//라이프설정
	Mat getconsol();
	
	void setFruits();//과일세팅
	
	void setconsol();//콘솔셋팅
	void sortlife(int a);//라이프제거
};
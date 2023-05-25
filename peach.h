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
	//���ϵ� roi�Լ�
	void resizeFruit();//���� �� ������ ������ ����
	
	void lineconsol();//����

	void printconsol();
	
	void setlife();//����������
	Mat getconsol();
	
	void setFruits();//���ϼ���
	
	void setconsol();//�ּܼ���
	void sortlife(int a);//����������
};
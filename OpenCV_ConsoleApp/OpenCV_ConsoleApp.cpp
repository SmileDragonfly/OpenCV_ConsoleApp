// OpenCV_ConsoleApp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include<opencv2/opencv.hpp>
#include<iostream>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
using namespace cv;
int main()
{
	VideoCapture video;
	video.open("EX_HATE_ME.mp4");
	unsigned int count = 0;
	while (count < 1000)
	{
		Mat frame;
		video >> frame;
		if ((count % 20) == 0)
		{
			string sfileName = "img_00";
			char pBuffer[3];
			int a = count / 20;
			_itoa_s(a, pBuffer, 10);
			sfileName += pBuffer;
			sfileName += ".jpg";
			printf("\n%s", sfileName);
			imwrite(sfileName,frame);
		}
		//if (waitKey(0) == 'c')
		//{
		//	break;
		//}
		count++;
	}
	waitKey(0);
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

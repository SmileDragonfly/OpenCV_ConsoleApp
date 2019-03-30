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
	video.open("BAD_BOY.mp4");
	unsigned int count = 0;
	void *pData = (void*)1;
	while (pData != NULL)
	{
		Mat *pframe = new Mat;
		Mat* pframeGray = new Mat;;
		video >> *pframe;
		pData = pframe->data;
		string sfileName = "img_00";
		char pBuffer[5];
		_itoa_s(count, pBuffer, 10);
		sfileName += pBuffer;
		sfileName += ".jpg";
		cvtColor(*pframe, *pframeGray, COLOR_BayerGB2GRAY);
		imwrite(sfileName, *pframeGray);
		free(pframeGray);
		free(pframe);
		pframe = NULL;
		pframeGray = NULL;
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

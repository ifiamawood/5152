// 5152.cpp : 定义控制台应用程序的入口点。
//

#include"stdafx.h"  
#include <iostream>
#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;


int main()
{
	Mat srcMat = imread("D:\\0.jpg", 0);
	Mat dstMat;
	float gamma=2;
 	//本函数只处理单通道图像 
 	if (srcMat.channels() != 1)return -1;


 	//建立查询表 
 	unsigned char lut[256];
 	for (int i = 0; i < 256; i++)
	{
		//saturate_cast，防止像素值溢出，如果值<0,则返回0，如果大于255，则返回255 
 		lut[i] = saturate_cast<uchar>(pow((float)(i / 255.0), gamma) * 255.0f);
		float inten = (float)i;
	}

 	srcMat.copyTo(dstMat);
 	MatIterator_<uchar> it, end;
	for (it = dstMat.begin<uchar>(), end = dstMat.end<uchar>(); it != end; it++) {
 * it = lut[(*it)];

		}

	imshow("src", srcMat);
	imshow("dst", dstMat);
	waitKey(0);
	destroyAllWindows();
	return 0;
 }



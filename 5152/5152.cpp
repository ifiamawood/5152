// 5152.cpp : �������̨Ӧ�ó������ڵ㡣
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
 	//������ֻ����ͨ��ͼ�� 
 	if (srcMat.channels() != 1)return -1;


 	//������ѯ�� 
 	unsigned char lut[256];
 	for (int i = 0; i < 256; i++)
	{
		//saturate_cast����ֹ����ֵ��������ֵ<0,�򷵻�0���������255���򷵻�255 
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



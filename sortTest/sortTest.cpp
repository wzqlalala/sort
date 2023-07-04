// sortTest.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <ctime>
#include "SortMethod.h"

using namespace std;
int main()
{
	vector<int> temp;
	for (int i = 0; i < 1000000; i++)
	{
		temp.push_back(rand());
	}
	vector<int> testVector0 = temp;
	vector<int> testVector1 = temp;
	vector<int> testVector2 = temp;
	vector<int> testVector3 = temp;
	vector<int> testVector4 = temp;
	vector<int> testVector5 = temp;
	vector<int> testVector6 = temp;
	vector<int> testVector7 = temp;

	clock_t start, end;//定义clock_t变量

	//c++自带排序
	{
		start = clock();//开始时间
		sort(testVector0.begin(), testVector0.end());
		end = clock();
		cout << "sort " << double(end - start) / CLOCKS_PER_SEC << endl;
	}

	/*
	//冒泡排序
	{
		start = clock();//开始时间
		BubbleSort<int> sort;
		sort.Sort(testVector1);
		end = clock();
		cout << "BubbleSort " << double(end - start) / CLOCKS_PER_SEC << endl;
	}



	//选择排序
	{
		start = clock();//开始时间
		SelectionSort<int> sort;
		sort.Sort(testVector2);
		end = clock();
		cout << "SelectionSort " << double(end - start) / CLOCKS_PER_SEC << endl;
	}



	//插入排序
	{
		start = clock();//开始时间
		InsertionSort<int> sort;
		sort.Sort(testVector3);
		end = clock();
		cout << "InsertionSort " << double(end - start) / CLOCKS_PER_SEC << endl;
	}
	*/
	//快速排序
	{
		start = clock();//开始时间
		QuickSort<int> sort;
		sort.Sort(testVector4);
		end = clock();
		cout << "QuickSort " << double(end - start) / CLOCKS_PER_SEC << endl;
	}

	//希尔排序
	{
		start = clock();//开始时间
		HillSort<int> sort;
		sort.Sort(testVector5);
		end = clock();
		cout << "HillSort " << double(end - start) / CLOCKS_PER_SEC << endl;
	}

	//归并排序
	{
		start = clock();//开始时间
		MergeSort<int> sort;
		sort.Sort(testVector6);
		end = clock();
		cout << "MergeSort " << double(end - start) / CLOCKS_PER_SEC << endl;
	}

	//堆排序
	{
		start = clock();//开始时间
		HeapSort<int> sort;
		sort.Sort(testVector7);
		end = clock();
		cout << "HeapSort " << double(end - start) / CLOCKS_PER_SEC << endl;
	}

	if (!checkIsSort<int>(testVector1)) { cout << __LINE__ << endl; };
	if (!checkIsSort<int>(testVector2)) { cout << __LINE__ << endl; };
	if (!checkIsSort<int>(testVector3)) { cout << __LINE__ << endl; };
	if (!checkIsSort<int>(testVector4)) { cout << __LINE__ << endl; };
	if (!checkIsSort<int>(testVector5)) { cout << __LINE__ << endl; };
	if (!checkIsSort<int>(testVector6)) { cout << __LINE__ << endl; };
	if (!checkIsSort<int>(testVector7)) { cout << __LINE__ << endl; };
	system("pause");
}

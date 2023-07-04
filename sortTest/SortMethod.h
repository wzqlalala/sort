#pragma once

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

//冒泡排序
template <typename T>
class BubbleSort
{
public:
	void Sort(vector<T> &v)
	{
		int n = v.size();
		for (int i = 0; i < n; ++i)
		{
			bool isSort{ true };//判断整个数组是否有序
			for (int j = 0; j < n - i - 1; ++j)
			{
				if (v[j] > v[j + 1])
				{
					swap(v[j], v[j + 1]);
					isSort = false;
				}
			}
			if (isSort)
			{
				break;//说明整个数组已经有序
			}
		}
	};
};


//选择排序
template <typename T>
class SelectionSort
{
public:
	void Sort(vector<T> &v)
	{
		int n = v.size();
		for (int i = 0; i < n; i++)
		{
			int minnum = v[i];//存储当次循环的最小值和下标索引
			int minIndex = i;
			for (int j = i; j < n; j++)
			{
				if (minnum > v[j])//更新最小值和下标
				{
					minIndex = j;
					minnum = v[j];
				}
			}
			swap(v[minIndex], v[i]);//将当次循环的最小值与位置为i的值交换，即把较小的值置前
		}
	};
};

//插入排序
template <typename T>
class InsertionSort
{
public:
	void Sort(vector<T> &v)
	{
		int n = v.size();

		for (int i = 0; i < n - 1; ++i)
		{
			int j = i;
			int num = v[j + 1];
			while (j >= 0 && v[j] > num)//当待插入的项小于前一项时
			{
				v[j + 1] = v[j];
				j--;
			}
			v[j + 1] = num;
		}
	};
};


//快速排序
template <typename T>
class QuickSort
{

public:

	void Sort(vector<T> &v)
	{
		quickSort(0, v.size() - 1, v);
	}

	void quickSort(int left, int right, vector<int> &v)
	{
		if (left >= right)
		{
			return;
		}
		int i = left;//左指针
		int j = right;//右指针

		T base = v[left];

		while (i < j)//只能在左指针小于右指针的情况下
		{
			while (v[j] >= base && i < j)//右指针从右向左移动，小于基准数时停下来
			{
				j--;
			}
			while (v[i] <= base && i < j)//左指针从左向右移动，大于基准数时停下来
			{
				i++;
			}
			if (i < j)//交换左右指针位置的数，将小于基准数的移到左边，大于基准数的移动到右边
			{
				swap(v[i], v[j]);
				//T tmp = v[i];
				//v[i] = v[j];
				//v[j] = tmp;
			}
		}

		v[left] = v[i];//基准数与左指针的数交换
		v[i] = base;

		quickSort(left, i - 1, v);//对左区间进行快排
		quickSort(j + 1, right, v);//对右区间进行快排
	}
};

//希尔排序
template <typename T>
class HillSort
{

public:

	void Sort(vector<T> &v)
	{
		int n = v.size();
		int gap = n / 2;
		for (int g = gap; g > 0; g /= 2)//控制步长，步长除2
		{
			for (int s = 0; s < g; ++s)//步长一定时，循环每组，控制起点+1
			{
				int size = n - g;
				for (int i = s; i < size; i += g)//单组的交换，起点和步长由上述控制
				{
					int j = i;
					int num = v[j + g];
					while (j >= s && v[j] > num)
					{
						v[j + g] = v[j];
						j -= g;
					}

					v[j + g] = num;
				}
			}
		}
	}
};

//归并排序
template <typename T>
class MergeSort
{
public:
	void Sort(vector<T> &v)
	{
		vector<T> res(v.size());
		merge(v, res, 0, v.size() - 1);
		v = res;//复制费时间
	}

	void merge(vector<T> &v, vector<T> &res, int start, int end)
	{
		if (start >= end)
		{
			return;
		}
		int len = end - start, mid = (len >> 1) + start;
		int start1 = start, end1 = mid;
		int start2 = mid + 1, end2 = end;
		merge(v, res, start1, end1);
		merge(v, res, start2, end2);
		int k = start;
		while (start1 <= end1 && start2 <= end2)
		{
			if (v[start1] < v[start2])
			{
				res[k++] = v[start1];
				++start1;
			}
			else
			{
				res[k++] = v[start2];
				++start2;
			}
		}
		while (start1 <= end1)
			res[k++] = v[start1++];
		while (start2 <= end2)
			res[k++] = v[start2++];
		for (k = start; k <= end; k++)
		{
			v[k] = res[k];
		}
	}
};

//堆排序
template <typename T>
class HeapSort
{
public:
	void Sort(vector<T> &v)
	{
		int num = v.size();
		//初始化堆
		for (int i = num/2 - 1; i >= 0; --i)//对每一个非叶节点进行调整
		{
			adjustHeap(v, num, i);
		}

		for (int i = num-1; i >=1; --i)//堆长度递减
		{
			swap(v[i], v[0]);//将大值交换到堆末尾
			adjustHeap(v, i, 0);//调整堆
		}
		
	}

private:

	//调整最大堆
	void adjustHeap(vector<T> &v,int length,int i)
	{
		int num = length;

		int left = 2 * i + 1;//根节点为i，左子节点为2*i+1，右子节点为2*i+2
		int right = 2 * i + 2;
		int maxIndex = i;//假设为该根节点最大
		if (left < num && v[left] > v[maxIndex])
		{
			maxIndex = left;
		}
		if (right < num && v[right] > v[maxIndex])
		{
			maxIndex = right;
		}
		if (maxIndex != i)
		{
			swap(v[maxIndex], v[i]);//交换该根节点和拥有大的子节点的值
			adjustHeap(v, num, maxIndex);//递归调整该子节点下的节点是否满足最大堆的条件
		}
		
	}
};

//检查是否排好序
template <typename T>
bool checkIsSort(vector<T> v)
{
	int n = v.size();
	for (int i = 0; i < n - 1; i++)
	{
		if (v[i] > v[i + 1])
		{
			return false;
		}
	}
	return true;
}

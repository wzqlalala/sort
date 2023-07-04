#pragma once

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

//ð������
template <typename T>
class BubbleSort
{
public:
	void Sort(vector<T> &v)
	{
		int n = v.size();
		for (int i = 0; i < n; ++i)
		{
			bool isSort{ true };//�ж����������Ƿ�����
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
				break;//˵�����������Ѿ�����
			}
		}
	};
};


//ѡ������
template <typename T>
class SelectionSort
{
public:
	void Sort(vector<T> &v)
	{
		int n = v.size();
		for (int i = 0; i < n; i++)
		{
			int minnum = v[i];//�洢����ѭ������Сֵ���±�����
			int minIndex = i;
			for (int j = i; j < n; j++)
			{
				if (minnum > v[j])//������Сֵ���±�
				{
					minIndex = j;
					minnum = v[j];
				}
			}
			swap(v[minIndex], v[i]);//������ѭ������Сֵ��λ��Ϊi��ֵ���������ѽ�С��ֵ��ǰ
		}
	};
};

//��������
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
			while (j >= 0 && v[j] > num)//�����������С��ǰһ��ʱ
			{
				v[j + 1] = v[j];
				j--;
			}
			v[j + 1] = num;
		}
	};
};


//��������
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
		int i = left;//��ָ��
		int j = right;//��ָ��

		T base = v[left];

		while (i < j)//ֻ������ָ��С����ָ��������
		{
			while (v[j] >= base && i < j)//��ָ����������ƶ���С�ڻ�׼��ʱͣ����
			{
				j--;
			}
			while (v[i] <= base && i < j)//��ָ����������ƶ������ڻ�׼��ʱͣ����
			{
				i++;
			}
			if (i < j)//��������ָ��λ�õ�������С�ڻ�׼�����Ƶ���ߣ����ڻ�׼�����ƶ����ұ�
			{
				swap(v[i], v[j]);
				//T tmp = v[i];
				//v[i] = v[j];
				//v[j] = tmp;
			}
		}

		v[left] = v[i];//��׼������ָ���������
		v[i] = base;

		quickSort(left, i - 1, v);//����������п���
		quickSort(j + 1, right, v);//����������п���
	}
};

//ϣ������
template <typename T>
class HillSort
{

public:

	void Sort(vector<T> &v)
	{
		int n = v.size();
		int gap = n / 2;
		for (int g = gap; g > 0; g /= 2)//���Ʋ�����������2
		{
			for (int s = 0; s < g; ++s)//����һ��ʱ��ѭ��ÿ�飬�������+1
			{
				int size = n - g;
				for (int i = s; i < size; i += g)//����Ľ��������Ͳ�������������
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

//�鲢����
template <typename T>
class MergeSort
{
public:
	void Sort(vector<T> &v)
	{
		vector<T> res(v.size());
		merge(v, res, 0, v.size() - 1);
		v = res;//���Ʒ�ʱ��
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

//������
template <typename T>
class HeapSort
{
public:
	void Sort(vector<T> &v)
	{
		int num = v.size();
		//��ʼ����
		for (int i = num/2 - 1; i >= 0; --i)//��ÿһ����Ҷ�ڵ���е���
		{
			adjustHeap(v, num, i);
		}

		for (int i = num-1; i >=1; --i)//�ѳ��ȵݼ�
		{
			swap(v[i], v[0]);//����ֵ��������ĩβ
			adjustHeap(v, i, 0);//������
		}
		
	}

private:

	//��������
	void adjustHeap(vector<T> &v,int length,int i)
	{
		int num = length;

		int left = 2 * i + 1;//���ڵ�Ϊi�����ӽڵ�Ϊ2*i+1�����ӽڵ�Ϊ2*i+2
		int right = 2 * i + 2;
		int maxIndex = i;//����Ϊ�ø��ڵ����
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
			swap(v[maxIndex], v[i]);//�����ø��ڵ��ӵ�д���ӽڵ��ֵ
			adjustHeap(v, num, maxIndex);//�ݹ�������ӽڵ��µĽڵ��Ƿ��������ѵ�����
		}
		
	}
};

//����Ƿ��ź���
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

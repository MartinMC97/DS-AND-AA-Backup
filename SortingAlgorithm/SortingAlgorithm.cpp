#include <iostream>
#inlcude <vector>
#include "SortingAlgorithm.h"
using namespace std;


void Swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

void InsertionSort(vector<int> &vec)		
{
	for (int i = 1; i < vec.size(); i++)
	{
		if (vec[i - 1] > vec[i])
		{
			int j = i;
			while (j != 0 && vec[j - 1] > vec[j])
			{
				Swap(vec[j], vec[j - 1]);
				j--;
			}
		}
	}
}

void BubbleSort(vector<int> &vec)
{
	for (int i = 1; i <= vec.size(); i++)
	{
		for (int j = vec.size() - 1; j > 0; j--)
		{
			if (vec[j] < vec[j - 1])
				Swap(vec[j], vec[j - 1]);
		}
	}
}

int inline LinearSearch(vector<int> vec, int start, int end)
{
	int temp = start;
	for (int i = start; i <= end; i++)
	{
		if (vec[i] < vec[temp])
			temp = i;
	}
	return temp;
}

void SelectionSort(vector<int> &vec)
{
	 
	for (int i = 0; i < vec.size(); i++)
	{
		int small = LinearSearch(vec, i, vec.size() - 1);
		Swap(vec[i], vec[small]);
	}
}

void BiInsertionSort(vector<int> &vec)
{
	for (int i = 1; i < vec.size(); i++)
	{
		if (vec[i - 1] > vec[i])
		{
			int low = 0, high = i - 1;
			while (low < high)		//折半查找
			{
				int mid = (low + high) / 2;
				if (vec[mid] > vec[i])
					high = mid;
				else
					low = mid;
			}
			for (int j = i; j > high; j--)	//交换位置
				Swap(vec[j], vec[j - 1]);
		}//if
	}//for
}

vector<int> GenerateDeltaArray(int length)
{
	int t = log2(length - 1);
	vector<int> delta;
	for (int k = 1; k <= t; k++)
		delta.push_back(pow(2, t - k) + 1);
	delta.push_back(1);
	return delta;
}

void ShellInsert(vector<int> &vec, int delta)
{
	for (int i = delta; i < vec.size(); i++)
	{
		if (vec[i] < vec[i - delta])
		{
			int j = i;
			while (j >= delta && vec[j - delta] > vec[j])
			{
				Swap(vec[j], vec[j - delta]);
				j -= delta;
			}
		}
	}//for
}

void ShellSort(vector<int> &vec)
{
	 
	vector<int> delta = GenerateDeltaArray(vec.size());
	for (int i = 0; i < delta.size(); i++)
		ShellInsert(vec, delta[i]);
}

int Partition(vector<int> &vec, int low, int high)
{
	int pivot = vec[low];

	while (low < high)
	{
		
		while (high > low && vec[high] >= pivot)
			high--;

		vec[low] = vec[high];
		
		while (high > low && vec[low] <= pivot) 
			low++;

		vec[high] = vec[low];

	}

	vec[low] = pivot;
	return low;
}

void QSort(vector<int> &vec, int low, int high)
{
	if (low < high)
	{
		int pivot = Partition(vec, low, high);
		QSort(vec, low, pivot - 1);
		QSort(vec, pivot + 1, high);
	}
}

void QuickSort(vector<int> &vec)
{
	 
	QSort(vec, 0, vec.size() - 1);
}

void MSort(vector<int> &vec, vector<int> &temp, int start, int end) 
{
	
	if (start >= end)
		return;

	int len = end - start, mid = (len >> 1) + start;
	int index1 = start, end1 = mid;
	int index2 = mid + 1, end2 = end;

	MSort(vec, temp, index1, end1);
	MSort(vec, temp, index2, end2);

	int k = start;

	while (index1 <= end1 && index2 <= end2)		//归并开始
	{
		
		if (vec[index1] < vec[index2])
			temp[k++] = vec[index1++];
		else
			temp[k++] = vec[index2++];
	}

	while (index1 <= end1)
		temp[k++] = vec[index1++];

	while (index2 <= end2)
		temp[k++] = vec[index2++];


	for (k = start; k <= end; k++)		//把排序好的部分放入原数组中
		vec[k] = temp[k];
}

void MergeSort(vector<int> &vec)
{
	 
	vector<int>  temp = vector<int>(vec.size());
	MSort(vec, temp, 0, vec.size() - 1);
}

void MaxHeap(vector<int> &vec, int start, int end)
{
	int ans = start;
	int dec = 2 * start + 1;
	while (dec <= end)		//在数组下标未越界时
	{
		if (dec + 1 <= end && vec[dec] < vec[dec + 1])	//若左子小于右子
			dec += 1;		//则选定右子

		if (vec[ans] > vec[dec])	//如果根节点较大则无动作
			return;
		else			
		{
			Swap(vec[dec], vec[ans]);		//否则根节点与子节点互换
			ans = dec;						//选定子节点
			dec = 2 * dec + 1;				//选定子节点的左子，继续循环
		}
	}
}

void HeapSort(vector<int> &vec)
{
	int i;
	for (i = vec.size() / 2 - 1; i >= 0; i--)		//最后一个有孩子的节点是vec.size()/2 - 1,从后往前调整。
		MaxHeap(vec, i, vec.size() - 1);
	
	for (i = vec.size() - 1; i > 0; i--)	//第一个元素与已排好的元素前一位来交换，再进行调整，直至第一个元素
	{		
		Swap(vec[0], vec[i]);
		MaxHeap(vec, 0, i - 1);
	}
}
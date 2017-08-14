/************************************************************************/
/*                  Learn  Sort Algorithm      by Mhk 2017-8-14         */
/************************************************************************/

#include <iostream>

/*-----------------------------Select sort------------------------------*/
void select_sort(int *a, int n)
{
	int i, j, k, temp;
	for (i = 0; i < n - 1; i++)
	{
		k = i;
		for (j = i + 1; j < n; j++)
		{
			if (a[k] > a[j])
			{
				k = j;
			}
		}

		if (i != k)
		{
			temp = a[i];
			a[i] = a[k];
			a[k] = temp;
		}
	}
}

/*-----------------------------bubble sort------------------------------*/
void bubble_sort(int *a, int n)
{
	int i, j, temp;
	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n - 1 - i; j++)
		{
			if (a[j] > a[j + 1])
			{
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}

}

/*-----------------------------Insert sort------------------------------*/
void insert_sort(int *a, int n)
{
	int i, j, temp;

	for (i = 1; i < n; i++)
	{
		temp = a[i];
		for (j = i - 1; j >= 0 && a[j] > temp; j--)
		{
			a[j + 1] = a[j];//前值后移
		}
		a[j + 1] = temp;
	}
}

/*---------------shell sort(折半/希尔 排序)------------------------------*/
void shell_sort(int *a, int n)
{
	int i, j, flag, temp;
	int gap = n;
	while (gap > 1)
	{
		gap /= 2;//增量缩小，每次减半（折半）
		do
		{
			flag = 0;
			for (i = 0; i < n - gap; i++)//n-gap控制上限，不让越界
			{
				j = i + gap;//相邻间隔的前后值进行比较
				if (a[i] > a[j])
				{
					temp = a[i];
					a[i] = a[j];
					a[j] = temp;
					flag = 1;
				}
			}


		} while (flag != 0);
	}

}

/*-----------------------------Quick sort------------------------------*/
/*查找位置；low为第一个元素下标，high为最后一个元素下标*/
int find_pos(int *a, int low, int high)
{
	int value = a[low];
	while (low < high)
	{
		while (low < high && a[high] >= value)
		{ //大于移动，小于则赋值，降序则相反
			high--;

		}
		a[low] = a[high];
		while (low < high && a[low] <= value)
		{//小于移动，大于则赋值，降序则相反
			low++;
		}
		a[high] = a[low];
	}//终止while循环之后low和high一定是相等的
	//high可以改为low
	a[low] = value;
	return low;
}
/*****快排******/
void quick_sort(int *a, int low, int high)
{
	if (low < high)
	{
		int pos = find_pos(a, low, high);
		quick_sort(a, low, pos - 1);
		quick_sort(a, pos + 1, high);
	}


}

void Print(const int a[], int n)
{
	std::cout << "{";
	if (n > 0)
	{
		std::cout << a[0];
		for (int i = 1; i < n; i++)
		{
			std::cout << " ," << a[i];
		}
	}
	std::cout << "}";

}


int main()
{

	int list[] = { 1, 3, -34, 2, 56, 4, 78, 7, 100, 2, 98 };
	int len = (sizeof list) / (sizeof list[0]);
	std::cout << "Sort Before: ";
	Print(list, len);
	std::cout << std::endl;
/***********************************************************************/
	//select_sort(list, len);//选择排序
	//bubble_sort(list, len);//冒泡排序
	//insert_sort(list, len);//插入排序
	//shell_sort(list, len);//希尔排序
	quick_sort(list, 0, len - 1);//快速排序
/***********************************************************************/
	std::cout << "Sort After: ";
	Print(list, len);
	std::cout << std::endl;
	std::system("pause");
	return 0;
}
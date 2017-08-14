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
			a[j + 1] = a[j];//ǰֵ����
		}
		a[j + 1] = temp;
	}
}

/*---------------shell sort(�۰�/ϣ�� ����)------------------------------*/
void shell_sort(int *a, int n)
{
	int i, j, flag, temp;
	int gap = n;
	while (gap > 1)
	{
		gap /= 2;//������С��ÿ�μ��루�۰룩
		do
		{
			flag = 0;
			for (i = 0; i < n - gap; i++)//n-gap�������ޣ�����Խ��
			{
				j = i + gap;//���ڼ����ǰ��ֵ���бȽ�
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
/*����λ�ã�lowΪ��һ��Ԫ���±꣬highΪ���һ��Ԫ���±�*/
int find_pos(int *a, int low, int high)
{
	int value = a[low];
	while (low < high)
	{
		while (low < high && a[high] >= value)
		{ //�����ƶ���С����ֵ���������෴
			high--;

		}
		a[low] = a[high];
		while (low < high && a[low] <= value)
		{//С���ƶ���������ֵ���������෴
			low++;
		}
		a[high] = a[low];
	}//��ֹwhileѭ��֮��low��highһ������ȵ�
	//high���Ը�Ϊlow
	a[low] = value;
	return low;
}
/*****����******/
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
	//select_sort(list, len);//ѡ������
	//bubble_sort(list, len);//ð������
	//insert_sort(list, len);//��������
	//shell_sort(list, len);//ϣ������
	quick_sort(list, 0, len - 1);//��������
/***********************************************************************/
	std::cout << "Sort After: ";
	Print(list, len);
	std::cout << std::endl;
	std::system("pause");
	return 0;
}
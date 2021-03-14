#define _CRT_SECURE_NO_WARNINGS 1
//找出单身狗
//一个数组中只有两个数组是出现一次，其他所有数组都出现两次，编写一个函数找出这两个只出现一次的数字
#include<stdio.h>
//异或法
void Find1(int *a,int n, int* num)
{
	int ret = 0;//记录异或结果
	int i = 0;
	for (i = 0; i < n; i++)
	{
		ret ^= a[i];
	}
	//得到的结果必定不为0
	//如 
	//5  0101 
	//6  0110
	//^  1011   (相同为0，不同为1）
	//即根据ret异或的结果可知，ret每个二进制为1的位置，所对应的两位数字在此位置不同，
	//可据此把两位不同数组分成两拨，每一波全部异或，异或结果即为单身狗
	int m = 0;
	while (m < 32)
	{
		if (ret & (1 << m))
			break;
		else
			m++;
	}
	int x1 = 0;
	int x2 = 0;
	for (i = 0; i < n; i++)
	{
		if (a[i] & (1 << m))
		{
			(*num) ^= a[i];
		}
		else
		{
			(*(num+1)) ^= a[i];
		}
	}

}
void Find2(int* a, int n, int* num)
{
	int tmp = 0;
	int i = 0;
	//由小到大排序
	for (i = 0; i < n; i++)
	{
		int j = 0;
		for (j = 0; j < n - i-1; j++)
		{
			if (a[j] > a[j + 1])
			{
				tmp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tmp;
			}
		}
	}
	//排序结果为1 1 2 2 3 4 5 5 6 6
	int sign = 0;
	i = 0;
	int k = 0;
	while (i<n)
	{
		//两两相比较，若相减为0，说明大小相同。比较完后，比较下两个，i+=2;
		//若相减不为0，则必定是下标为i（a[i]与a[i+1]比较，靠近起始下标0的那个）的数字是“单身狗”，找到之后就跳过这个“单身狗”，即i++
		if (!(a[i] - a[i + 1]))
		{
			i += 2;
		}
		else
		{
			*(num + k) = a[i];
			k++;
			i++;
			if (k == 2)
				break;
		}

	}
}
int main(void)
{
	int i = 0;
	int arr[] = { 1,2,3,5,6,1,2,4,5,6 };
	int num[2] = { 0 };//想要找出两个数，不能简单的retutn,把数组num的地址传过去，即可修改num数组内容，达到目的
	int sz = sizeof(arr) / sizeof(arr[0]);
//	Find1(arr,sz,num);
	Find2(arr, sz, num);

	for (i = 0; i < 2; i++)
	{
		printf("%d ", num[i]);
	}
	return 0;
}

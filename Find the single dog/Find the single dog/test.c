#define _CRT_SECURE_NO_WARNINGS 1
//�ҳ�����
//һ��������ֻ�����������ǳ���һ�Σ������������鶼�������Σ���дһ�������ҳ�������ֻ����һ�ε�����
#include<stdio.h>
//���
void Find1(int *a,int n, int* num)
{
	int ret = 0;//��¼�����
	int i = 0;
	for (i = 0; i < n; i++)
	{
		ret ^= a[i];
	}
	//�õ��Ľ���ض���Ϊ0
	//�� 
	//5  0101 
	//6  0110
	//^  1011   (��ͬΪ0����ͬΪ1��
	//������ret���Ľ����֪��retÿ��������Ϊ1��λ�ã�����Ӧ����λ�����ڴ�λ�ò�ͬ��
	//�ɾݴ˰���λ��ͬ����ֳ�������ÿһ��ȫ������������Ϊ����
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
	//��С��������
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
	//������Ϊ1 1 2 2 3 4 5 5 6 6
	int sign = 0;
	i = 0;
	int k = 0;
	while (i<n)
	{
		//������Ƚϣ������Ϊ0��˵����С��ͬ���Ƚ���󣬱Ƚ���������i+=2;
		//�������Ϊ0����ض����±�Ϊi��a[i]��a[i+1]�Ƚϣ�������ʼ�±�0���Ǹ����������ǡ����������ҵ�֮����������������������i++
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
	int num[2] = { 0 };//��Ҫ�ҳ������������ܼ򵥵�retutn,������num�ĵ�ַ����ȥ�������޸�num�������ݣ��ﵽĿ��
	int sz = sizeof(arr) / sizeof(arr[0]);
//	Find1(arr,sz,num);
	Find2(arr, sz, num);

	for (i = 0; i < 2; i++)
	{
		printf("%d ", num[i]);
	}
	return 0;
}

#include <stdio.h>
#include <string.h>

/*ð����������*/
void BubbleSort(unsigned int arr[], unsigned int arrsize)
{
	unsigned int i = 0, j = 0;
	
	for (j=0;j<arrsize-1;j++)
	{
		int flag = 0;
		for (i = 0; i < arrsize - j-1; i++)
		{
			/*����������ֵ*/
			if (arr[i] > arr[i + 1])
			{
				flag = 1;
				arr[i] = arr[i] ^ arr[i + 1];
				arr[i + 1] = arr[i] ^ arr[i + 1];
				arr[i] = arr[i] ^ arr[i + 1];
			}
		}
		if (flag == 0)break;
	}
}
/*ð���������ģ��*/
void Test01(void)
{	
	unsigned int i = 0;
	unsigned int arr[] = { 1,2,35,56,78,4,15,65,94,18,26,48,96 };
	unsigned int arrsize = sizeof(arr) / sizeof(arr[0]);
	BubbleSort(arr, arrsize);

	for (i = 0; i < arrsize; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}
/*�������ܣ���һ�������洢���ڴ��ж�����1�ĸ���*/
unsigned int Return_IntOneNum(int num)
{
	int i = 0;
	unsigned int cnt = 0;
	for (i = 0; i < 8*sizeof(int); i++)
	{
		if (num & 1)
			cnt++;
		num >>= 1;
	}
	return cnt;
}

unsigned int  Return_IntOneNumTest(int num)
{
	unsigned int cnt = 0;
	for (; num;)
	{
		cnt++;
		num = num & (num - 1);
	}
	return cnt;
}
/*����ĳ�������ڴ���1�ĸ���*/
void Test02(void)
{
	printf("%d����%u��1\n", 0xffffffff, Return_IntOneNum(0xffffffff));
	printf("%d����%u��1\n", 0xffffffff, Return_IntOneNumTest(0xffffffff));
}

/*��ʽ����ת������������*/
void Type_Change(void)
{
	char a = 0xb6;
	short b = 0xb600;
	int c = 0xb6000000;
	if (a == 0xb6)
		printf("a\n");
	if (b == 0xb600)
		printf("b\n");
	if (c == 0xb6000000)
		printf("c\n");
}
/*�������ݵĴ洢*/
void Test03(void)
{
	char a = -1;
	signed char b = -1;
	unsigned char c = -1;
	printf("a=%d,b=%d,c=%d ", a, b, c);
	char d = 128;
	//char d = -128;
	printf("%u\n", d);
	int i = -20;
	unsigned int j = 10;
	printf("%d\n", i + j);
}

/*���д���ִ�еĽ����ʲô��*/
void Test04(void)
{
	char a[1000];
	int i;
	for (i = 0; i < 1000; i++)
	{
		a[i] = -1 - i;
	}
	printf("%d", (int)strlen(a));
}
/*���ݵĴ洢*/
void Test05(void)
{
	int n = 9;		//�����͵���ʽ����
	float* pFloat = (float*)&n;	//��float���͵�ָ��ȥָ�����n���ڵ��ǿ�ռ�
	printf("n��ֵΪ��%d\n", n);			//�����͵ķ�ʽȥȡ     //�����9
	/*
	* �Ը������ķ�ʽȥȡ  �����0.000000
	*�������洢��(-1)^S*M*2^E   S:����λ(1bit) M(������Чλ) E(ָ��λ) 
	*9 -> 0 00000000 00000000 00000000 0001001
	*	�����͵ķ�ʽȥȡ��9
	*	�Ը������ķ�ʽȥȡ��EΪȫ0����׼�涨��(-1)^S*0.00000000 00000000 0001001*2^(1-127) ��Ϊ0��
	*/
	printf("*pFloat��ֵΪ��%f\n", *pFloat);
	/*
	* 9.0 -> 1001.0 ->(-1)^0*1.001*2^3
	* ��9.0���ڴ��еĴ洢��0 10000010 00100000 00000000 0000000
	*  �������ͷ�ʽȥȡ��1091567616
	*  ���Ը������ķ�ʽȥȡ��9.000000
	*/
	*pFloat = 9.0;
	printf("num��ֵΪ��%d\n", n);
	printf("*pFloat��ֵΪ��%f\n", *pFloat);
}

/*�����ָ��*/
void Test06(void)
{
	char str1[] = "hello bit.";
	char str2[] = "hello bit.";
	char* str3 = "hello bit.";
	char* str4 = "hello bit.";
	if (str1 == str2)
		printf("str1 and str2 are same\n");
	else
		printf("str1 and str2 are not same\n");
	if (str3 == str4)
		printf("str3 and str4 are same\n");
	else
		printf("str3 and str4 are not same\n");
}

/*ָ�봫�Σ����鴫��*/
//void Test07(int* arr[5]) �൱�ڽ��յ��Ƕ���ָ��
void Test07(int(* arr)[5]) //����һά����ĵ�ַ��������ָ��
{

}

int main(void)
{
	/*ð���������ģ��*/
	Test01();

	/*����ĳ�������ڴ���1�ĸ���*/
	Test02();

	/*��ʽ����ת������������*/
	Type_Change();

	/*�������ݵĴ洢*/
	Test03();

	/*���д���ִ�еĽ����ʲô��*/
	Test04();

	/*���ݵĴ洢*/
	Test05();

	/*�����ָ��*/
	Test06();

	int arr1[3][5];

	/*ָ�봫�Σ����鴫��*/
	Test07(arr1);

	return 0;
}

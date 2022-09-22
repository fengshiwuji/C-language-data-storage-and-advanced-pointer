#include <stdio.h>
#include <string.h>

/*冒泡排序：升序*/
void BubbleSort(unsigned int arr[], unsigned int arrsize)
{
	unsigned int i = 0, j = 0;
	
	for (j=0;j<arrsize-1;j++)
	{
		int flag = 0;
		for (i = 0; i < arrsize - j-1; i++)
		{
			/*交换变量的值*/
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
/*冒泡排序测试模块*/
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
/*函数功能：求一个整数存储在内存中二进制1的个数*/
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
/*返回某个数在内存中1的个数*/
void Test02(void)
{
	printf("%d中有%u个1\n", 0xffffffff, Return_IntOneNum(0xffffffff));
	printf("%d中有%u个1\n", 0xffffffff, Return_IntOneNumTest(0xffffffff));
}

/*隐式类型转换：整形提升*/
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
/*整型数据的存储*/
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

/*下列代码执行的结果是什么？*/
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
/*数据的存储*/
void Test05(void)
{
	int n = 9;		//以整型的形式存入
	float* pFloat = (float*)&n;	//用float类型的指针去指向变量n所在的那块空间
	printf("n的值为：%d\n", n);			//以整型的方式去取     //结果：9
	/*
	* 以浮点数的方式去取  结果：0.000000
	*浮点数存储：(-1)^S*M*2^E   S:符号位(1bit) M(数据有效位) E(指数位) 
	*9 -> 0 00000000 00000000 00000000 0001001
	*	以整型的方式去取：9
	*	以浮点数的方式去取：E为全0，标准规定，(-1)^S*0.00000000 00000000 0001001*2^(1-127) 即为0；
	*/
	printf("*pFloat的值为：%f\n", *pFloat);
	/*
	* 9.0 -> 1001.0 ->(-1)^0*1.001*2^3
	* 则9.0在内存中的存储：0 10000010 00100000 00000000 0000000
	*  若以整型方式去取：1091567616
	*  若以浮点数的方式去取：9.000000
	*/
	*pFloat = 9.0;
	printf("num的值为：%d\n", n);
	printf("*pFloat的值为：%f\n", *pFloat);
}

/*数组和指针*/
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

/*指针传参，数组传参*/
//void Test07(int* arr[5]) 相当于接收的是二级指针
void Test07(int(* arr)[5]) //接收一维数组的地址，即数组指针
{

}

int main(void)
{
	/*冒泡排序测试模块*/
	Test01();

	/*返回某个数在内存中1的个数*/
	Test02();

	/*隐式类型转换：整形提升*/
	Type_Change();

	/*整型数据的存储*/
	Test03();

	/*下列代码执行的结果是什么？*/
	Test04();

	/*数据的存储*/
	Test05();

	/*数组和指针*/
	Test06();

	int arr1[3][5];

	/*指针传参，数组传参*/
	Test07(arr1);

	return 0;
}

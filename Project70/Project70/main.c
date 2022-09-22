#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define size_t unsigned int
/*比较函数*/
int cmp(const void* elem1, const void* elem2)
{
	return (*(int*)elem1) - (*(int*)elem2);
}
/*交换函数*/
void swap(void* elem1, void* elem2,size_t cnt)
{
	size_t i = 0;
	char temp = 0;
	for (i=0;i<cnt;i++)
	{
		temp = *((char*)elem1 + i);
		*((char*)elem1 + i) = *((char*)elem2 + i);
		*((char*)elem2 + i) = temp;
	}
}

/*采用冒泡排序法实现qsort排序*/
void my_qsort(void* base, size_t num, size_t width, int(* compare)(const void* elem1, const void* elem2))
{
	size_t i = 0;
	size_t j = 0;
	for (i = 0; i < num - 1; i++)
	{
		for (j = 0; j < num - i - 1; j++)
		{
			if (compare((char*)base + j * width, (char*)base + (j + 1) * width) > 0)
			{
				swap((char*)base + j * width, (char*)base + (j + 1) * width,width);
			}
		}
	}
}
/*以下代码会输出什么？*/
void Test01(void)
{
	int a[] = { 1,2,3,4 };
	printf("%d\n", (int)sizeof(a));
	printf("%d\n",(int)sizeof(a + 0));
	printf("%d\n",(int)sizeof(*a));
	printf("%d\n",(int)sizeof(a + 1));
	printf("%d\n",(int)sizeof(a[1]));
	printf("%d\n",(int)sizeof(&a));
	printf("%d\n",(int)sizeof(*&a));
	printf("%d\n",(int)sizeof(&a + 1));
	printf("%d\n",(int)sizeof(&a[0]));
	printf("%d\n",(int)sizeof(&a[0] + 1));

	const char arr[] = { 'a','b','c','d','e','f' };
	printf("%d\n",(int)sizeof(arr));
	printf("%d\n",(int)sizeof(arr + 0));
	printf("%d\n",(int)sizeof(*arr));
	printf("%d\n",(int)sizeof(arr[1]));
	printf("%d\n",(int)sizeof(&arr));
	printf("%d\n",(int)sizeof(&arr + 1));
	printf("%d\n",(int)sizeof(&arr[0] + 1));
	//printf("%d\n",(int)strlen(arr));
	printf("%d\n",(int)strlen(arr + 0));
	//printf("%d\n",(int)strlen(*arr));
	//printf("%d\n",(int)strlen(arr[1]));
	//printf("%d\n",(int)strlen(&arr));
	//printf("%d\n",(int)strlen(&arr + 1));
	printf("%d\n",(int)strlen(&arr[0] + 1));
}
/*以下代码会输出什么？*/
void  Test02(void)
{
	char arr[] = "abcdef";
	printf("%d\n",(int)sizeof(arr));
	printf("%d\n",(int)sizeof(arr + 0));
	printf("%d\n",(int)sizeof(*arr));
	printf("%d\n",(int)sizeof(arr[1]));
	printf("%d\n",(int)sizeof(&arr));
	printf("%d\n",(int)sizeof(&arr + 1));
	printf("%d\n",(int)sizeof(&arr[0] + 1));
	printf("%d\n",(int)strlen(arr));
	printf("%d\n",(int)strlen(arr + 0));
	//printf("%d\n",(int)strlen(*arr));		//类型不匹配，且存在非法访问内存单元
	//printf("%d\n",(int)strlen(arr[1]));	//类型不匹配，且存在非法访问内存单元
	//printf("%d\n",(int)strlen(&arr));		//类型上的不匹配，但没有越界
	//printf("%d\n",(int)strlen(&arr + 1));  //会发生越界
	printf("%d\n",(int)strlen(&arr[0] + 1));

	char* p = "abcdef";
	printf("%d\n",(int)sizeof(p));
	printf("%d\n",(int)sizeof(p + 1));
	printf("%d\n",(int)sizeof(*p));
	printf("%d\n",(int)sizeof(p[0]));
	printf("%d\n",(int)sizeof(&p));
	printf("%d\n",(int)sizeof(&p + 1));
	printf("%d\n",(int)sizeof(&p[0] + 1));
	printf("%d\n",(int)strlen(p));
	printf("%d\n",(int)strlen(p + 1));
	//printf("%d\n",(int)strlen(*p));
	//printf("%d\n",(int)strlen(p[0]));
	//printf("%d\n",(int)strlen(&p));
	//printf("%d\n",(int)strlen(&p + 1));
	printf("%d\n",(int)strlen(&p[0] + 1));

}
/*以下代码会输出什么？*/
void Test03(void)
{
	//二维数组
	int a[3][4] = { 0 };
	printf("%d\n",(int)sizeof(a));
	printf("%d\n",(int)sizeof(a[0][0]));
	printf("%d\n",(int)sizeof(a[0]));
	printf("%d\n",(int)sizeof(a[0] + 1));
	printf("%d\n",(int)sizeof(*(a[0] + 1)));
	printf("%d\n",(int)sizeof(a + 1));
	printf("%d\n",(int)sizeof(*(a + 1))); //相当于sizeof(a[1]) 即sizeof(数组名)表示这个数组的大小
	printf("%d\n",(int)sizeof(&a[0] + 1));
	printf("%d\n",(int)sizeof(*(&a[0] + 1))); //相当于sizeof(a[1]) 即sizeof(数组名)表示这个数组的大小
	printf("%d\n",(int)sizeof(*a)); //相当于sizeof(a[0]) 即sizeof(数组名)表示这个数组的大小
	printf("%d\n",(int)sizeof(a[3])); // 即sizeof(数组名)表示这个数组的大小
}
/*以下代码会输出什么？*/
void Test04(void)
{
	int a[4] = { 1, 2, 3, 4 };
	int* ptr1 = (int*)(&a + 1);
	int* ptr2 = (int*)((int)a + 1);
	printf("%x,%x", ptr1[-1], *ptr2);
}
/*指针是无符号数，且指针减指针等于中间元素的个数*/
void Test05(void)
{
	int a[5][5] = {	0,1,2,3,4,
					5,6,7,8,9,
					10,11,12,13,14,
					15,16,17,18,19,
					20,21,22,23,24};
	int(*p)[4];
	p = a;
	printf("%p,%d\n", &p[4][2] - &a[4][2],  & p[4][2] - &a[4][2]);
}
/*以下代码会输出什么？*/
void Test06(void)
{
	int aa[2][5] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int* ptr1 = (int*)(&aa + 1);
	int* ptr2 = (int*)(*(aa + 1));
	printf("%d,%d", *(ptr1 - 1), *(ptr2 - 1));
}
/*以下代码会输出什么？*/
void Test07(void)
{
	char* a[] = { "work","at","alibaba" };
	char** pa = a;
	pa++;
	printf("%s\n", *pa);
}
/*以下代码会输出什么？*/
void Test08(void)
{
	char* c[] = { "ENTER","NEW","POINT","FIRST" };
	char** cp[] = { c + 3,c + 2,c + 1,c };
	char*** cpp = cp;
	printf("%s\n", **++cpp);
	printf("%s\n", *-- * ++cpp + 3);
	printf("%s\n", *cpp[-2] + 3);
	printf("%s\n", cpp[-1][-1] + 1);
}

/*main函数*/
int main(void)
{
	int i = 0;
	int arr[10] = {5,9,8,7,6,4,3,2,1,10};

	my_qsort(arr, 10, sizeof(arr[0]), cmp);

	for (i = 0; i < 10; i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");

	/*以下代码会输出什么？*/
	//Test01();

	//Test02();
	
	//Test03();

	//Test04();

	//Test05();
	
	//Test06();

	//Test07();

	Test08();

	return 0;
}
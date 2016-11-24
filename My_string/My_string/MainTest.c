#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>
#include<Windows.h>
#include"My_string.h"



int main(void)
{
	char a[100] = "andy  ";
	char b[] = "chang123";
	char *c[10] = { 0 };
	int  count = 0;
	printf("&a= %p , &b=%p \n", a, b);
	printf("a_strlen= %d, b_strlen=%d \n", My_strlen(a), My_strlen(b));

	puts(a);
	puts(b);

	strcat(a, b);
	printf("\n----------------------------\n");
	My_strcat(a, b);
	puts(a);
	puts(b);
	printf("\n----------------------------\n");

	char *p = My_strstr(a, b);
	printf("%p\n", p);

	printf("\n----------------------------\n");

	puts(a);
	puts(b);
	printf("\n----------------------------\n");

	int ret = My_strstr_mul(a, b, c, &count);
	printf("%p , %p , %d \n", c[0], c[1], count);
	printf("%p\n", p);

	printf("\n----------------------------\n");



	puts(a);
	printf("\n----------------------------\n");
	strncat(a, b, 2);
	puts(a);
	printf("\n----------------------------\n");

	int ret3 = 0;
	if (ret3 = strcmp(a, b))
	{
		printf("%d\n", ret3);
		puts("wrong string");
	}
	else
	{
		puts("hahaha");
		printf("%d\n", ret3);
	}

	char d[20] = "chang12";
	puts(a);
	puts(b);
	puts(d);

	if (ret3 = strap(b, d))
	{
		printf("%d\n", ret3);
		puts("wrong string~~~~~~~~~");
	}
	else
	{
		puts("hahaha~~~~~~~~~");
		printf("%d\n", ret3);
	}


	printf("\n%p", strchr(a, 'c'));
	printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	printf("\n%p__________%p______%d", strstr(a, "ang"), My_strstr(a, "g123"), My_strcount(a, "g123"));
	printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");


	system("pause");
	return 0;


}
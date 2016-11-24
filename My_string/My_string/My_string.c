#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>
#include<Windows.h>
#include"My_string.h"



//思路： 1 ，循环判断位置字符是否为'\0'， 不是则加1 ，否，继续判断。返回值。
int My_strlen(const char *a)
{
	int num = 0; //统计标识
	while (*a) //*a不等于0，执行循环
	{
		num++;  // 标识++
		a++;    //字符串位移后以为
	}

	return num;
}

// 思路： 1 ， 开辟辅助指针变量。
//       2 ， 移动辅助指针位置指向。 一个指向主字符串后面第一个字符位置，另外一个指向副字符串首位子。
//       3 ， 循环把副字符串字符 赋值 给主字符串辅助指针。
//       4 ， 主字符串后面加上'\0' 。
void My_strcat(char *allstr, char *addstr)
{

	int allstrlen = My_strlen(allstr);  //获取目标字符串长度
	int addstrlen = My_strlen(addstr);  // 获取合并字符串长度

	char *pall = allstr;   // 定义辅助指针，保护原指针
	pall += allstrlen;     // 指针指向移动到字符串最后面，等待添加字符。

	char *padd = addstr;   // 定义辅助指针，保护原指针

	while (*padd)
	{
		*pall++ = *padd++;  //一个一个拷贝字符
	}
	*(padd + 1) = '\0'; //结尾添加结束符。

}
//重点：循环设计方法，其中一个辅助flag是关键，两个break辅助跳出循环。
//思路：1 ， 两个辅助指针变量接过实参地址。
//     2 ， 设计双循环，遍历两个字符串

char *My_strstr(char *allstr, char *str)  //查找字符串在指定字符串中第一次出现的位置
{
	char *p = NULL;
	char *ptemp_a = allstr;
	char *ptemp_b = str;

	//双循环，遍历字符串
	for (int i = 0; i < (int)(strlen(ptemp_a) - strlen(ptemp_b)); i++)
	{
		int flag = 1;                                               //标志位，这个是算法的重点，需要理解。2016.11.23自己设计双循环时，就没考虑到用flag
		for (int j = 0; j < (int)strlen(ptemp_b); j++)
		{
			if (ptemp_a[i + j] != *(ptemp_b + j))                //判断是否相同
			{
				flag = 0;
				break;                                          //有位置不一样，跳出内层循环
			}
		}
		if (flag == 1)                                          //如果没有不一样的，那flag = 1 ，就找到字符串位子了
		{
			p = ptemp_a + i;
			break;                                            // 只找一次，找到就跳出外层循环
		}
	}

	return p;
}


int My_strstr_mul(char *allstr, char *str, char **p_arr, int *p_count)  //查找字符串在指定字符串中出现的位置,及次数。
{
	char *p = NULL;
	char *ptemp_a = allstr;
	char *ptemp_b = str;

	//双循环，遍历字符串
	for (int i = 0; i <= (int)(strlen(ptemp_a) - strlen(ptemp_b)); i++)
	{
		int flag = 1;                                               //标志位，这个是算法的重点，需要理解。2016.11.23自己设计双循环时，就没考虑到用flag
		for (int j = 0; j < (int)strlen(ptemp_b); j++)
		{
			if (ptemp_a[i + j] != *(ptemp_b + j))                //判断是否相同
			{
				flag = 0;
				break;
			}
		}
		if (flag == 1)
		{
			p_arr[*p_count] = ptemp_a + i;
			*p_count += 1;
			i = i + strlen(ptemp_b) - 1;
		}
	}

	return 0;
}



int My_strcount(char *allstr, char *str)
{
	int allstr_strlen = My_strlen(allstr);
	int str_strlen = My_strlen(str);

	char *p = NULL;
	int num = 0;

	for (int i = 0; i < allstr_strlen - str_strlen; i++)
	{
		int flag = 1;
		for (int j = 0; j < str_strlen; j++)
		{
			if (*(allstr + i + j) != *(str + j))
			{
				flag = 0;
				break;
			}

		}
		if (flag == 1)
		{
			p = allstr + i;
			num++;
		}

	}


	return num;



}

//重点： C规范的,ASCI C的实现思路，及方式值得学习。
//字符串对比，相同返回 0 . p_fir 顺序先于p_sec ，返回负数 。 p_fir后于p_sec，返回正数。
int My_strcmp(const char *allstr, const char *str)
{
	char *p_fir = allstr;
	char *p_sec = str;


	if (*p_fir != *p_sec || strlen(p_fir) != strlen(p_sec))
	{
		if (*p_fir < *p_sec)
		{
			return -1;
		}
		else
		{
			return 1;
		}
	}


	for (int i = 1; i < (int)strlen(p_fir); i++)
	{
		if (p_fir[i] != p_sec[i])                //判断是否相同
		{
			if (p_fir[i] < p_sec[i])
			{
				return -1;
			}
			else
			{
				return 1;
			}                                     //有位置不一样，跳出内层循环
		}

	}

	return 0;
}



/*

//此版本的亮点在，可返回第一个不相同字母相差具体数字。
int strcmp(p1,p2)
{
    const char *p1;
    const char *p2;
 
    register const unsignedchar *s1=(const unsignedchar*)p1;
    register const unsignedchar *s2=(const unsignedchar*)p2;
    unsigned reg_char c1,c2;           //reg_char ？ 搜索也没有相关东西，是否为作者笔误？
    do{
        c1=(unsigned char)*s1++;
        c2=(unsigned char)*s2++;
        if(c1=='\0')
            return c1-c2;
    }while(c1==c2);
    return c1-c2;
} 

//C规范的,ASCI C的在下面.此实现，如果是"ABCDEFG"和”ABCDEF"比较，会效率低一点，因为它依然要循环到最后一个不一样的字符再结束。
int(strap)(const char *sl, const char *s2)
{
//compare unsigned char sl[],s2[]
	for (; *sl == *s2; ++sl, ++s2)
	{
		if (*sl == '\0')
			return(0);
	}
	return((*(unsigned char*)sl<*(unsigned char*)s2) ? -1 : +1);
}

	
//调用约定(Calling convention) .它决定以下内容：
//1)函数参数的压栈顺序，
//2)由调用者还是被调用者把参数弹出栈，
//3)以及产生函数修饰名的方法。 
// __cdecl C语言默认的函数调用方法.  所有参数从右到左依次入栈，这些参数由调用者清除.
int __cdecl strcmp(const char *src,const char *dst)  
{
    int ret=0;

    while(!(ret = *(unsigned char *)src - *(unsigned char *)dst) && *dst)
        ++src,++dst;

    if(ret<0)
        ret=-1;
    else if(ret>0)
        ret=1;

    return(ret);
}
	
int strcmp(const char *str1,const char *str2)
{
	//不可用while(*str1++==*str2++)来比较，当不相等时仍会执行一次++，return返回的比较值实际上是下一个字符。应将++放到循环体中进行。
	while (*str1 == *str2)
	{
		if (*str1 == '\0')
			return0;

		str1++;
		str2++;
	}

	return *str1 - *str2;
}

	
	
	
*/
#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>
#include<Windows.h>

// 统计字符串长度
int My_strlen(const char *a);  				

// 链接字符串
void My_strcat(char *allstr, char *addstr);  

//查找字符串在指定字符串中第一次出现的位置
char *My_strstr(char *allstr, char *str);  
//查找字符串在指定字符串中出现的位置,及次数。
int My_strstr_mul(char *allstr, char *str, char **p, int *p_count); 
//查找字符串在指定字符串中出现的次数
int My_strcount(char *allstr, char *str);   

//字符串对比，相同返回 0 . p_fir 顺序先于p_sec ，返回负数 。 p_fir后于p_sec，返回正数。
int My_strcmp(const char *allstr, const char *str);   
//对比指定位数的字符,返回0，相同。 否则返回差值。
int My_strncmp(const char *allstr, const char * str, int str_count);

//从源字符串地址拷贝字符到目标字符串地址中。
char *My_strcpy(char *allstr, char *str);
//从源字符串地址拷贝N个字符到目标字符串地址中。
char *My_strncpy(char *allstr, char *str, int str_count);

//查找字符串s中首次出现字符c的位置
char *My_strchr(char *s, char c);

//返回字符串s 开头连续不含字符串reject 内的字符数目
int strcspn(char *s1, char *s2);
//在字符串s1中寻找字符串s2中任何一个字符相匹配的第一个字符的位置，空字符NULL不包括在内。返回指向s1中第一个相匹配的字符的指针，如果没有匹配字符则返回空指针NULL。
char *strpbrk(char *s1, char *s2);


//将字符串s转换为小写形式,只转换s中出现的大写字母，不改变其它字符。返回指向s的指针。
char *strlwr(char *s);
//将字符串s转换为大写形式,只转换s中出现的小写字母，不改变其它字符。返回指向s的指针。
char *strupr(char *s);

//把字符串s的所有字符的顺序颠倒过来（不包括空字符NULL）。返回指向颠倒顺序后的字符串指针。
char *strrev(char *s);

//把字符串s中的所有字符都设置成字符c。
char *strset(char *s, char c);

//分解字符串为一组标记串。s为要分解的字符串，delim为分隔符字符串。
strsep();
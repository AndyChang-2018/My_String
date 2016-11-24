#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>
#include<Windows.h>

int My_strlen(const char *a);  				// 统计字符串长度

void My_strcat(char *allstr, char *addstr);  // 链接字符串

char *My_strstr(char *allstr, char *str);  //查找字符串在指定字符串中第一次出现的位置
int My_strstr_mul(char *allstr, char *str, char **p, int *p_count); //查找字符串在指定字符串中出现的位置,及次数。
int My_strcount(char *allstr, char *str);   //查找字符串在指定字符串中出现的次数

int My_strcmp(const char *allstr, const char *str);     //字符串对比，相同返回 0 . p_fir 顺序先于p_sec ，返回负数 。 p_fir后于p_sec，返回正数。


int(strap)(const char *sl, const char *s2);

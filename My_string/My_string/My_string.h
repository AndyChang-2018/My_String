#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>
#include<Windows.h>

int My_strlen(const char *a);  				// ͳ���ַ�������

void My_strcat(char *allstr, char *addstr);  // �����ַ���

char *My_strstr(char *allstr, char *str);  //�����ַ�����ָ���ַ����е�һ�γ��ֵ�λ��
int My_strstr_mul(char *allstr, char *str, char **p, int *p_count); //�����ַ�����ָ���ַ����г��ֵ�λ��,��������
int My_strcount(char *allstr, char *str);   //�����ַ�����ָ���ַ����г��ֵĴ���

int My_strcmp(const char *allstr, const char *str);     //�ַ����Աȣ���ͬ���� 0 . p_fir ˳������p_sec �����ظ��� �� p_fir����p_sec������������


int(strap)(const char *sl, const char *s2);

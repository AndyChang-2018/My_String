#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>
#include<Windows.h>

// ͳ���ַ�������
int My_strlen(const char *a);  				

// �����ַ���
void My_strcat(char *allstr, char *addstr);  

//�����ַ�����ָ���ַ����е�һ�γ��ֵ�λ��
char *My_strstr(char *allstr, char *str);  
//�����ַ�����ָ���ַ����г��ֵ�λ��,��������
int My_strstr_mul(char *allstr, char *str, char **p, int *p_count); 
//�����ַ�����ָ���ַ����г��ֵĴ���
int My_strcount(char *allstr, char *str);   

//�ַ����Աȣ���ͬ���� 0 . p_fir ˳������p_sec �����ظ��� �� p_fir����p_sec������������
int My_strcmp(const char *allstr, const char *str);   
//�Ա�ָ��λ�����ַ�,����0����ͬ�� ���򷵻ز�ֵ��
int My_strncmp(const char *allstr, const char * str, int str_count);

//��Դ�ַ�����ַ�����ַ���Ŀ���ַ�����ַ�С�
char *My_strcpy(char *allstr, char *str);
//��Դ�ַ�����ַ����N���ַ���Ŀ���ַ�����ַ�С�
char *My_strncpy(char *allstr, char *str, int str_count);

//�����ַ���s���״γ����ַ�c��λ��
char *My_strchr(char *s, char c);

//�����ַ���s ��ͷ���������ַ���reject �ڵ��ַ���Ŀ
int strcspn(char *s1, char *s2);
//���ַ���s1��Ѱ���ַ���s2���κ�һ���ַ���ƥ��ĵ�һ���ַ���λ�ã����ַ�NULL���������ڡ�����ָ��s1�е�һ����ƥ����ַ���ָ�룬���û��ƥ���ַ��򷵻ؿ�ָ��NULL��
char *strpbrk(char *s1, char *s2);


//���ַ���sת��ΪСд��ʽ,ֻת��s�г��ֵĴ�д��ĸ�����ı������ַ�������ָ��s��ָ�롣
char *strlwr(char *s);
//���ַ���sת��Ϊ��д��ʽ,ֻת��s�г��ֵ�Сд��ĸ�����ı������ַ�������ָ��s��ָ�롣
char *strupr(char *s);

//���ַ���s�������ַ���˳��ߵ����������������ַ�NULL��������ָ��ߵ�˳�����ַ���ָ�롣
char *strrev(char *s);

//���ַ���s�е������ַ������ó��ַ�c��
char *strset(char *s, char c);

//�ֽ��ַ���Ϊһ���Ǵ���sΪҪ�ֽ���ַ�����delimΪ�ָ����ַ�����
strsep();
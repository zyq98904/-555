//QQ���ѹ����ܶ��塢Ⱥ������ 
#ifndef BASE_Q
#define BASE_Q
#include<string>
#include"base.h"
#include"iostream"
using namespace std;

class Tencent{
	protected:
		string id;//------------------------>�˺� 
		string name;//---------------------->����
		Date birthday;//-------------------->����
		Date tyear;//------------------------>��������
		Address where;//-------------------->��ַ
	public:
		Tencent(){
		cout<<" Please input the QQ account:";
		cin>>id;
		cout<<" Please input your nicheng:";
		cin>>name;}
		Tencent(string i,string n,int a,int b,int c,int a1,int b1,int c1,string d,string e,string f):birthday(a,b,c),tyear(a1,b1,c1),where(d,e,f)
		{
			id=i;
			name=n;
		}//��Ϣ¼�� 
};
class Tencent_qq:public Tencent{
	public:
		Tencent_qq();//----------------------���캯��
		Tencent_qq(string i,string n,int a,int b,int c,int a1,int b1,int c1,string d,string e,string f): Tencent(i,n,a,b,c,a1,b1,c1,d,e,f)
		{
			beizhu=n;
			cout<<"gouzao\n";
		}//----------------------------------��ȡ���캯��
		              //-------����--------//
		void WeiboApply();//------------------΢������
		void SearchWeixin();//----------------����΢�ź��� 
		void Surface();//---------------------��½����
		void Save();//------------------------������Ϣ���ļ�
		void save_haoyou();//-----------------��������б�
		void save_qun();//--------------------����QȺ
		void load();//------------------------��ȡ�����б�
		void load_qun();//--------------------��ȡȺ�б�
		const void put();//-------------------���������Ϣ
		void QqunApply();//-------------------����QȺ
		void QqunJoin();//--------------------����Ⱥ
		void QqunDelete();//------------------�˳�Ⱥ
		void QqunPut();//---------------------�������Ⱥ��
		void Qqunmanage();//------------------����Ⱥ
		               //------���ѹ���-----//
		void  HaoyouSurface();//--------------
	protected:
		string key;//-------------------------����
		List1 fried;//------------------------QQ���ѵĴ�ȡ��������
		List2 QQqun;//------------------------QQȺ��ȡ����
		string beizhu;//----------------------QQ���ѵı�ע 
};

#endif


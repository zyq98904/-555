#ifndef BAS
#define BAS
#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Date{
	public:
		int year;
		int month;
		int day;
		static int n;
	public:
		Date();
		Date(int a,int b,int c){year=a;month=b;day=c;}; 
		int inyear();
		int inmonth();
		int inday();
}; //�û�������Ϣ
class Address{
	public:
		string country;
		string province;
		string countryside;
	public:
		Address(){country=inwhere1();province=inwhere2();countryside=inwhere3();};
		Address(string a,string b,string c){country=a;province=b;countryside=c;};
		string inwhere1();
		string inwhere2();
		string inwhere3();
}; //�û���ַ��Ϣ
class List1{
	public:
		void List1_add();//�������
		void List1_add_wei();//weixin�������
		void List1_delete();//����ɾ��
		void List1_delete_wei();//weixin����ɾ��
		const void List1_put();//���������Ϣ
		const void List1_put_wei();//weixin���������Ϣ
		void List1_chat();//�������캯��
	public:
	vector<string>list;	
}; //���ѹ���
class List2{
	public:
		vector<int>list;//����QQȺ; 
};
#endif

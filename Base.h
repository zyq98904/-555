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
}; //用户日期信息
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
}; //用户地址信息
class List1{
	public:
		void List1_add();//好友添加
		void List1_add_wei();//weixin好友添加
		void List1_delete();//好友删除
		void List1_delete_wei();//weixin好友删除
		const void List1_put();//输出好友信息
		const void List1_put_wei();//weixin输出好友信息
		void List1_chat();//好友聊天函数
	public:
	vector<string>list;	
}; //好友管理
class List2{
	public:
		vector<int>list;//保存QQ群; 
};
#endif

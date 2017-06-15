//QQ好友管理功能定义、群管理定义 
#ifndef BASE_Q
#define BASE_Q
#include<string>
#include"base.h"
#include"iostream"
using namespace std;

class Tencent{
	protected:
		string id;//------------------------>账号 
		string name;//---------------------->名称
		Date birthday;//-------------------->生日
		Date tyear;//------------------------>申请日期
		Address where;//-------------------->地址
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
		}//信息录入 
};
class Tencent_qq:public Tencent{
	public:
		Tencent_qq();//----------------------构造函数
		Tencent_qq(string i,string n,int a,int b,int c,int a1,int b1,int c1,string d,string e,string f): Tencent(i,n,a,b,c,a1,b1,c1,d,e,f)
		{
			beizhu=n;
			cout<<"gouzao\n";
		}//----------------------------------读取构造函数
		              //-------功能--------//
		void WeiboApply();//------------------微博申请
		void SearchWeixin();//----------------搜索微信好友 
		void Surface();//---------------------登陆界面
		void Save();//------------------------保存信息到文件
		void save_haoyou();//-----------------保存好友列表
		void save_qun();//--------------------保存Q群
		void load();//------------------------读取好友列表
		void load_qun();//--------------------读取群列表
		const void put();//-------------------输出个人信息
		void QqunApply();//-------------------创建Q群
		void QqunJoin();//--------------------加入群
		void QqunDelete();//------------------退出群
		void QqunPut();//---------------------输出所在群组
		void Qqunmanage();//------------------管理群
		               //------好友管理-----//
		void  HaoyouSurface();//--------------
	protected:
		string key;//-------------------------密码
		List1 fried;//------------------------QQ好友的存取好友向量
		List2 QQqun;//------------------------QQ群存取向量
		string beizhu;//----------------------QQ好友的备注 
};

#endif


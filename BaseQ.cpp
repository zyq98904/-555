//重载QQ头文件中的所有函数
#include"BaseQ.h"
#include"Base.h"
#include"fstream"
#include"string"
#include"windows.h"
#include"weibo.h"
#include"Qqun.h"
#include"iostream"
using namespace std;

Tencent_qq::Tencent_qq(){
	string judge;
	int waring1=0;
	double waring2=0.2;
	beizhu=name;
	ofstream aaa("D:\\zhanghao.txt",ios::out|ios::app);
	if(aaa.fail()){
	ofstream bbb("D:\\zhanghao.txt");
	bbb.close();} 
	aaa.close();
	ifstream c("D:\\zhanghao.txt");
	if(c.fail())
	{
		throw waring1;
	}
	while(c.eof()!=1)
	{
		c>>judge;
		if(id==judge)
		{
			throw waring2;
		}
	}
	c.close();
	cout<<"Please input your key:\n";
	cin>>key;
	ofstream mi("D://mima.txt",ios::out|ios::app);
	mi<<"#"<<id<<" "<<key<<"\n";
	mi.close();
	Save();
	}

void Tencent_qq::Save(){
	ofstream a("D:\\zhanghao.txt",ios::out|ios::app);
	a<<"\n";
	a<<id;
	a.close();
	ofstream b("D:\\zongsave.txt",ios::out|ios::app);
	b<<"#"<<id<<" "<<name<<" "<<birthday.year<<" "<<birthday.month<<" "<<birthday.day<<" "<<tyear.year<<" "<<tyear.month<<" "<<tyear.day<<" "<<where.country<<" "<<where.province<<" "<<where.countryside<<" "<<beizhu<<"\n";
	b.close();
} 

void Tencent_qq::save_haoyou(){
	ofstream out(id.c_str(),ios::out|ios::trunc);
	out<<id;
	for(int i=0;i<fried.list.size();i++)
	{
		out<<" "<<fried.list[i];
	}
	out.close(); 
}

void Tencent_qq::save_qun(){
	ofstream out(name.c_str(),ios::out|ios::trunc);
	out<<id;
	for(int i=0;i<QQqun.list.size();i++)
	{
		out<<" "<<QQqun.list[i];
	}
	out.close();
}

void Tencent_qq::HaoyouSurface(){
	system("cls");
	load();//-----------------------------读取用户信息
	cout<<"Welcome to the friend surface!\n";
	int a;
	while(1){
		cout<<"1.Add friend\n";
		cout<<"2.Delete friend\n";
		cout<<"3.Output friend information\n";
		cout<<"4.Quit\n";
		cout<<"Please enter the required service:\n";
		cin>>a;
		if(a==4)
		break;
		if(a<=0||a>4)
		cout<<"输入错误，请重新输入\n";
		switch(a)
		{
			case 1:fried.List1_add();
			save_haoyou();
			break;
			case 2:fried.List1_delete();
			save_haoyou();
			break;
			case 3:fried.List1_put();
			break;
		}
	} 
}

const void Tencent_qq::put(){
	cout<<"QQ Account:"<<id<<"\n";
	cout<<"QQ Name:"<<name<<"\n";
	cout<<"User Birthday:"<<birthday.year<<"."<<birthday.month<<"."<<birthday.day<<"\n";
	cout<<"User Applycation time:"<<tyear.year<<"."<<tyear.month<<"."<<tyear.day<<"\n";
	cout<<"User Address:"<<where.country<<" "<<where.province<<" "<<where.countryside<<"\n";
	system("pause"); 
}
void Tencent_qq::load(){
	ofstream b(id.c_str(),ios::out|ios::app);
	b.close();
	ifstream a(id.c_str());
	string id1;//-------------------------本机ID 
	string list1;//------------------------好友账号
	if(a.fail())
	{
	cout<<"好友文件打开失败!\n";
	exit(0);
	}
	a>>id1;
	fried.list.clear();
	while(a.eof()!=1)
	{
		a>>list1;
		fried.list.push_back(list1);
	 } 
	 a.close();
	 cout<<"Read friends list success!\n";
}

void Tencent_qq::load_qun(){
	ofstream b(name.c_str(),ios::out|ios::app);
	b.close();
	ifstream a(name.c_str());
	string id1;//------------------本机ID 
	int list1;//-------------------群账号
	if(a.fail())
	{
		cout<<"群文件打开失败!\n";
		exit(0);
	}
	a>>id1;
	QQqun.list.clear();
	while(a.eof()!=1){
		a>>list1;
		QQqun.list.push_back(list1);
	}
	a.close();
	cout<<"Processing group information\n";
}

void Tencent_qq::WeiboApply(){
	system("cls");
	cout<<"Whether open microblogging?(y/n)";
	char a;
	cin>>a;
	if(a=='Y'||a=='y')
	{
		cout<<"Is opening...\n";
		weibo b(Tencent_qq::id);
	}
	system("pause");
}

void Tencent_qq::QqunApply(){
	cout<<"In the opening QQ group...\n";
	Tencent_QQqun a(id);
	QQqun.list.push_back(a.getid());
	system("pause");
}

void Tencent_qq::QqunPut(){
	cout<<"You have joined "<<QQqun.list.size()<<" groups\n";
	cout<<"Group account number are:\n";
	for(int i=0;i<QQqun.list.size();i++)
	{
		cout<<QQqun.list[i]<<"\n"; 
	}
	system("pause");
}

void Tencent_qq::QqunJoin(){
	char jing;
	string num;
	string nicheng;
	string vipn;
	int find;
	ifstream in("D:\\qqun_vip.txt");
	if(in.fail())
	{
		cout<<"Q group account missing!\n";
		return;
	}
	cout<<"Now the system has\n";
	while(in.eof()!=1)
	{
		in>>jing;
		if(jing=='#')
		{
			in>>num;
			in>>vipn;
			in>>nicheng;
			cout<<"Group account:"<<num<<" Leader QQ account:"<<vipn<<" group's nickname is:"<<nicheng<<"\n";
			jing=0; 
		}
	}
	in.close();
	cout<<"Please enter the QQ group you want to join the account:";
	cin>>find;
	Tencent_QQqun qqq(find,id);
	qqq.common.push_back(id);
	QQqun.list.push_back(find);
	save_qun();
	system("pause");
}

void Tencent_qq::QqunDelete(){
	QqunPut();
	int find;
	string zhong;
	int idzhong;
	char sz[5];
	cout<<"Please enter the group you want to exit:\n";
	cin>>find;
	//------------判断群主-------------//
	sprintf(sz,"%d",find);
	ifstream judge(sz);
	if(judge.fail())
	{
		cout<<"系统中无此群!\n";
		system("pause");
		return ;
	}
	judge>>idzhong;
	judge>>zhong;
	if(zhong==id)
	{
		cout<<"Since you are a group owner can not do this!\n";
		system("pause");
		return ;
	}
	//----------开始执行退群操作--------//
	Tencent_QQqun hlt(find,id);
	for(vector<string>::iterator it=hlt.common.begin();it!=hlt.common.end();)
	{
		if(*it==id)
		{
			hlt.common.erase(it);
			cout<<"You have exited the group!\n";
			continue;
		}
		++it;
	}
	for(vector<int>::iterator it1=QQqun.list.begin();it1!=QQqun.list.end();)
	{
		if(*it1==find)
		{
			QQqun.list.erase(it1);
			continue;
		}
		++it1;
	}
	save_qun();
	system("pause");
}

void Tencent_qq::Qqunmanage(){
	QqunPut();
	int find;
	cout<<"Please enter the group you want to manage:\n";
	cin>>find;
	Tencent_QQqun hlt(find,id);
	hlt.guanli();
}

void Tencent_qq::Surface(){
	system("cls");
	cout<<"You are using QQ Service!\n";
	cout<<"Welcome,Honor:"<<name<<"\n";
	system("pause");
	while(1)
	{
		system("cls");
		cout<<"---------------------QQ surface----------------------\n";
		cout<<"                1.Friend Manage.\n" ;
		cout<<"                2.Manage Qqun.\n";
		cout<<"                3.Output the Qqun information.\n";
		cout<<"                4.Quit the Qqun.\n";
		cout<<"                5.Join the Qqun.\n";
		cout<<"                6.Create a Qqun.\n";
		cout<<"                7.Apply for weibo.\n";
		cout<<"                8.Quit!\n";
		cout<<"Please choose the service you want to do:\n";
		int i;
		cin>>i;
		if(i==8)
		break;
		if(i<=0||i>8)
		cout<<"Input error!please input again!\n";
		switch(i)
		{
			case 1:
				HaoyouSurface();
				break;
			case 2:
				load_qun();
				Qqunmanage();
				break;
			case 3:
				load_qun();
				QqunPut();
				break;
			case 4:
				load_qun();
				QqunDelete();
				break;
			case 5:
				load_qun();
				QqunJoin();
				break;
			case 6:
				load_qun();
				QqunApply();
				save_qun();
				break;
			case 7:
				WeiboApply();
				break;
		}
	}
}

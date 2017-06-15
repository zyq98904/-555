//此程序功能为定义QQ，weixin的信息调用以及保存。通过对文件的修改，读取来完成。 
#include"Base.h"
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
using namespace std;

int Date::n=0;
Date::Date(){
	if(n==0)
	cout<<"Please input the birthday:\n";
	if(n==1)
	cout<<"Please input the apply time of this account:\n";
	n++;
	if(n>1)
	n=0;
	year=inyear();
	month=inmonth();
	day=inday();
}
int Date::inday()
{
	int a;
	bool flag=true;
	cout<<"Please input the days:\n";
	cin>>a;
	while(flag)
	{
		if(a>31||a<0)
		{
			cout<<"ERROR！Please try again:\n";
			cin>>a;
		 } 
		 else
		 flag=false;
	 } 
	 return a;
} 

int Date::inyear()
{
	int a;
	cout<<"Please input the years: \n";
	cin>>a;
	return a;
}

int Date::inmonth(){
	int a;
	bool flag=true;
	cout<<"Please input the months:\n";
	cin>>a;
	while(flag)
	{
		if(a>12||a<0)
		{
			cout<<"ERROR！Please try again:\n";
			cin>>a;
		}
		else
		flag=false;
	}
	return a;
}
string Address::inwhere1() {
	string a;
	cout<<"Country:\n";
	cin>>a;
	return a;
}
string Address::inwhere2(){
	string a;
	cout<<"Province:\n";
	cin>>a;
	return a;
}
string Address::inwhere3(){
	string a;
	cout<<"City:\n";
	cin>>a;
	return a;
}
void List1::List1_add(){
	string id;
	string id1;
	bool flag=false;
	cout<<"Please enter the friends you want to add QQ account:\n";
	cin>>id;
	ifstream b("D:\\zhanghao.txt");
	if(b.fail()){cout<<"账号文件不存在";exit(0);}
	while(b.eof()!=1){
		b>>id1;
		if(id==id1){
			cout<<"Find the target qq!\n";
			flag=true;
			list.push_back(id);//添加账号到最后一个 
		}
	}//寻找账号 
	b.close();
	if(flag){cout<<"Add friends success!\n";} 
}

const void List1::List1_put(){
	cout<<"A total of QQ friends:"<<list.size()<<"\n";
	cout<<"Their QQ account is:\n";
	for(int i=0;i<list.size();i++)
	{
		cout<<list[i]<<"\n";
		
	}
	string id1;
	string name1;
	char ch;
	cout<<"Their names are:\n";
	ifstream a("D:\\zongsave.txt");
	if(a.fail()){cout<<"文件打开异常，可能缺失!";}
	a>>ch;
	while(a.eof()!=1){
		a>>id1;
		for(int i=0;i<list.size();i++)
		{
			if(id1==list[i])
			{
				a>>name1;
				cout<<name1<<"\n";
			}
		}
		while(a.eof()!=1){
			a>>ch;
			if(ch=='#')
			break;
		}
	}
	a.close();//遍历文件 
}

void List1::List1_delete(){
	cout<<"Currently have friends:"<<list.size()<<"人"<<"\n";
	cout<<"Their QQ account are:\n";
	for(int i=0;i<list.size();i++)
	{
		cout<<list[i]<<"\n";
	}
	string a;
	cout<<"Please enter the account you want to delete:\n";
	cin>>a;
	for(vector<string>::iterator it=list.begin();it!=list.end();)
	{
		if(*it==a)
		{
			list.erase(it);
			it++;
		}
		else
		{
		it++;}
	}
	cout<<"Existing friends:"<<list.size()<<"人"<<"\n"; 
}

void List1::List1_add_wei(){
	string id;
	string id1;
	bool flag=false;
	cout<<"Please enter the weixin account you want to add\n";
	cin>>id;
	ifstream b("D:\\zhanghaowei.txt");
	if(b.fail()){cout<<"账号文件不存在！";exit(0);}
	while(b.eof()!=1){
		b>>id1;
		if(id==id1)
		{
			cout<<"Find the target weixin account!\n";
			flag=true;
			list.push_back(id);
		}
	}
	b.close();
	if(flag){cout<<"Add friends success!\n";}
}

const void List1::List1_put_wei(){
	cout<<"Total weixin friends "<<list.size()<<" people\n";
	if(list.size()!=0)
	{
		cout<<"Their weixin account is:\n";
		for(int i=0;i<list.size();i++)
		{
			cout<<list[i]<<"\n";
		}
		string id1;
		string name1;
		char ch;
		cout<<"Their name is:\n";
		ifstream a("D:\\zongsavewei.txt");
		if(a.fail()){cout<<"文件缺失!";}
		a>>ch;
		while(a.eof()!=1)
		{
			a>>id1;
			for(int i=0;i<list.size();i++)
			{
				if(id1==list[i])
				{
					a>>name1;
					cout<<name1<<"\n";
				}
			}
			while(a.eof()!=1)
			{
				a>>ch;
				if(ch=='#')
				break;
			}
		}
		a.close();
	}
	else
	{cout<<"You do not have weixin friends!\n";}
}

void List1::List1_delete_wei(){
	cout<<"There are currently friends:"<<list.size()<<"人"<<"\n";
	cout<<"Their weixin account are:\n";
	for(int i=0;i<list.size();i++)
	{
		cout<<list[i];
	}
	string a;
	cout<<"Please enter the weixin account you want to delete:\n";
	cin>>a;
	for(vector<string>::iterator it=list.begin();it!=list.end();)
	{
		if(*it==a)
		{
			list.erase(it);
			continue;
		}
		++it;
	}
} 

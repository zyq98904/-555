#include"weibo.h"
#include"Base.h"
#include"BaseQ.h"
#include"iostream"
#include"string"
#include"fstream"
using namespace std;

weibo::weibo(string a)
{
	id=a;
	//-------------ȷ���ļ�����-----------------//
	ofstream b("D:\\weibo_id.txt",ios::out|ios::app);
	if(b.fail()){ofstream c("D:\\weibo_id.txt");
	c.close();
	} 
	//-------------��֤-----------------------//
	ifstream in("D:\\weibo_id.txt");
	char jing;
	string panduan;
	bool flag=true;
	while(in.eof()!=1)
	{
		in>>jing;
		in>>panduan;
		if(panduan==a)
		flag=false;
	}
	in.close();
	if(flag==true)
	{
	//--------------д��-------------//
	     b<<"#"<<a<<" ";
	     b.close();
	     cout<<"Opening weibo success!\n";
	}
	else 
	cout<<"You have opened weibo, no need to open again!\n"; 
}
weibo::~weibo(){
	ofstream b("D:\\weibo_id.txt",ios::out|ios::app);
	b.close();
}

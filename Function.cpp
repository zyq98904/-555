#include"windows.h"
#include"iostream"
#include"Base.h"
#include"BaseQ.h"
#include"fstream"
#include"Weixin.h"
#include"weibo.h" 
#include"Function_h.h" 
using namespace std;

void dengluQ(){
	system("cls");
	cout<<"Entering the surface...\n";
	string a;//---------QQ�˺�
	string a1;//--------�Ա��˺�
	string b;//---------��½QQ����
	string b1;//--------�Ա�����
	char jing;//--------#�ŶԱ�
	string id1;
	string name1;
	int year1;
	int month1;
	int ri1;
	int year2;
	int month2;
	int ri2;
	string country1;
	string province1;
	string countryside1;
	bool flag1=false;//----------��֤�˺�
	bool flag2=false;//----------��֤����
	bool flag3=false;//----------��½ʹ��
	
	cout<<"Please input the QQ account��\n";
	cin>>a;
	ifstream c("D:\\zhanghao.txt");
	if(c.fail())
	{
		cout<<"File missing��\n";
		exit(0);
	 } 
	while(c.eof()!=1)
	{
		c>>a1;
		if(a==a1)
		{
			flag1=true;
		}
	}
	c.close();
	if(flag1==false)
	{
		cout<<"This account hasn't been applyed!\n";
		cout<<"Backing to the main menue\n";
		system("pause");
		system("cls");
		return ;
	}
	cout<<"Please input the key��\n";
	cin>>b;
	ifstream d("D:\\mima.txt");
	if(d.fail())
	{
		cout<<"��Ҫ�ļ�ȱʧ\n";
		exit(0);
	}
	while(d.eof()!=1)
	{
		d>>jing;
		if(jing=='#')
		{
			d>>a1;
			if(a==a1)
			{
				d>>b1;
				if(b==b1)
				{
					flag2=true;
				}
			}
		}
	}
	d.close();
	if(flag2)
	{
		cout<<"Key success��\n";
	}
	else{ 
	cout<<"Key error��\n";
	cout<<"Backing to the main menue...\n";
	system("pause");
	system("cls");
	return ;
	} 
//------------��½��ʼ-------------//
    ifstream e("D:\\zongsave.txt");
	if(e.fail())
	{
		cout<<"File missing��\n";
		exit(0);
	}
	while(e.eof()!=1)
	{
		e>>jing;
		if(jing=='#')
		{
			e>>id1;
			if(a==id1)
			{
				e>>name1;
				e>>year1;
				e>>month1;
				e>>ri1;
				e>>year2;
				e>>month2;
				e>>ri2;
				e>>country1;
				e>>province1;
				e>>countryside1;
				flag3=true;
			}
		}
	 } 
	 e.close();
	 if(flag3==false)
	 {
	 	cout<<"File open error��";
	 	return ;
	 }
	 else
	 {
	 	cout<<"User information reading success��\n";
	 }
	 Tencent_qq user(a,name1,year1,month1,ri1,year2,month2,ri2,country1,province1,countryside1);
	 user.put(); 
	 user.Surface();
	 extern int ctrl;
	 ctrl=0;
} 

void zhuceQ(){
	system("cls");
	cout<<" Entering the applycation of QQ\n";
	try{Tencent_qq hlt;}
	catch(int)
	{
		cout<<"File missing��\n"; 
	}
	catch(double){
		cout<<"Sorry!This account has been applyed!\n";
	}
	cout<<"Applycation done!\n";
}

void zhuceW()
{
	system("cls");
	cout<<"Entering the applycation of weixin\n";
	try{Tencent_weixin hlt;}
	catch(int){
		cout<<"Missing file��\n";
	}
	catch(double)
	{
		cout<<"The account has been applied, sorry!\n";
	}
	cout<<"Registration is complete!\n";
}

void dengluW(){
	system("cls");
	cout<<"Entering the login screen\n";
	string a;//---------------------------------------------------------��¼weixin�˺�
	string a1;//--------------------------------------------------------�ȶ��˺�
	string b;//---------------------------------------------------------��¼weixin����
	string b1;//--------------------------------------------------------�ȶ�����
	char jing;//--------------------------------------------------------#�űȶ�
	string id1;string name1;int year1;int month1; int ri1;int year2;int month2;int ri2;string country1;string province1;string countryside1;
			  //--------------------------------------------------------���г�Ա��
	bool flag=false;//--------------------------------------------------��֤�˺�
	bool flag1=false;//-------------------------------------------------��֤����
	bool flag2=false;//-------------------------------------------------��½ʹ��

//--------------------------------��֤�˺�--------------------------//
	cout<<"Please enter the weixin account:\n";
	cin>>a;
	ifstream c("D:\\zhanghaowei.txt");
	if(c.fail()){cout<<"��Ҫ�ļ�ȱʧ";exit(0);}
	while(c.eof()!=1)
	{
		c>>a1;
		if(a==a1)
		{
			flag=true;
		}
	}
	c.close();
	if(flag==false)
	{
		cout<<"The entered account is not registered\n";
		cout<<"Is returning to the main menu\n";
		system("pause");
		system("cls");
		return;
	}
//--------------------------------��֤����----------------------------//
	cout<<"Please enter your password:\n";
	cin>>b;
	ifstream d("D:\\mimawei.txt");
	if(d.fail()){cout<<"��Ҫ�ļ�ȱʧ\n";exit(0);}
	while(d.eof()!=1)
	{
		d>>jing;
		if(jing=='#')
		{
			d>>a1;
			if(a==a1)
			{
				d>>b1;
				if(b==b1)
				{
					flag1=true;
				}
			}
		}
	}
	d.close();
	if(flag1)
	{
		cout<<"Password is correct!\n";
	}
	else
	{
		cout<<"wrong password!\n";
		cout<<"Is returning to the main menu\n";
		system("pause");
		system("cls");
		return;
	}
//----------------------------��ʼ��½----------------------------//
	ifstream e("D:\\zongsavewei.txt");
	if(e.fail()){cout<<"Important documents are missing\n";exit(0);}
	while(e.eof()!=1)
	{
		e>>jing;
		if(jing=='#')
		{
			e>>id1;
			if(a==id1)
			{
				e>>name1;e>>year1;e>>month1;e>>ri1;e>>year2;e>>month2;e>>ri2;e>>country1;
				e>>province1;e>>countryside1;
				flag2=true;
			}
		}
	}
	e.close();
	if(flag2==false)
	{
		cout<<"User information reading failed, sorry!";
		return;
	}else
	{
		cout<<"User information read successfully!\n";
	}
	Tencent_weixin user(a,name1,year1,month1,ri1,year2,month2,ri2,country1,province1,countryside1);
	user.put();
	user.jiemian();
	extern int ctrl;
	ctrl=0;
}

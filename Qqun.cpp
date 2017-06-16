#include"Qqun.h"
#include"Base.h"
#include"BaseQ.h"
#include"iostream"
#include"string"
#include"fstream"
#include"stdio.h"
#include"windows.h"
#include"vector"
#include"sstream"
using namespace std;

int Tencent_QQqun::ID=1100;
Tencent_QQqun::Tencent_QQqun(string a)
{
	vip=a;
	id=ID++;
	cout<<"Please enter the nickname of the group you want to create:\n";
	cin>>name;
	judge=1;
	common.push_back(vip);
//---------确认头文件的存在-----------//
    ofstream b("D:\\qqun_vip.txt",ios::out|ios::app);
	if(b.fail()){
		ofstream c("D:\\qqun_vip.txt");
		c.close();
	}
	b<<"#"<<id<<" "<<vip<<" "<<name<<" ";
	b.close();
	cout<<"Open success!\n";
	cout<<"The group ID is:"<<id<<"\n";
	cout<<"The name of the group is:"<<name<<"\n";
	cout<<"Members of the group:"<<common.size()<<"peapole\n";
}

Tencent_QQqun::Tencent_QQqun(int find,string a)
{
//---------确认头文件的存在-----------//
    ofstream b("D:\\qqun_vip.txt",ios::out|ios::app);
    if(b.fail()){
	ofstream c("D:\\qqun_vip.txt");
	c.close();
	}
    b.close();
    //-------------验证--------------//
	char jing;//------------------读#;
	int id1;
	string vip1;
	string name1;
	bool flag=false;
	ifstream in("D:\\qqun_vip.txt");
	while(in.eof()!=1)
	{
		in>>jing;
		in>>id1;
		in>>vip1;
		in>>name1;
		if(id1==find)
		flag=true;
	 } 
	 in.close();
	 //------------登陆，读取文件----------//
	 char sz[5];
	 if(flag)
	 {
	 	ifstream in2("D:\\qqun_vip.txt");
	 	while(in2.eof()!=1)
	 	{
	 		in2>>jing;
	 		in2>>id1;
	 		in2>>vip1;
	 		in2>>name1;
	 		if(id1==find)
	 		{
	 			id=id1;
	 			name=name1;
	 			vip=vip1;
	 			cout<<"loading...\n";
	 			id1=0;
			}
		}
		in2.close();
        sprintf(sz,"%d",id);
		ifstream in3(sz);
		if(in3.fail()){
			cout<<"打开文件失败，该文件或许不存在!\n";
			exit(-1);
		}
		in3>>id1;
		common.clear();
		while(in3.eof()!=1)
		{
			in3>>vip1;
			common.push_back(vip1);
			cout<<"Join the group success!";
		}
		in3.close();
		if(vip==a){
		judge=1;
		}
		else
		judge=0;
	 }
	 else
	 {cout<<"输入信息有误!\n";
	 exit(-1);
	 }
}

void Tencent_QQqun::tiren(){
	string id1;
	string name1;
	string zhong;
	bool flag=false;
	char jing;
	stringstream qwe;
	qwe<<id;
	string stringid;
	qwe>>stringid;
	cout<<"Existing members："<<common.size()<<" people\n";
	cout<<"Their QQ ID are:\n";
	for(int i=0;i<common.size();i++)
	{
		cout<<common[i]<<"\n"; 
	}
	cout<<"Enter the ID you want to kick:\n";
	cin>>id1;
	for(int i=0;i<common.size();i++)
	{
		if(common[i]==id1)
		flag=true;
	}
	if(id1==common[0])
	flag=false;
	if(flag)
	{
		for(vector<string>::iterator it=common.begin();it!=common.end();)
		{
			if(*it==id1)
			{
				common.erase(it);
				continue;
			}
			++it;
		}
		//-------------------已删除
		ifstream in("D:\\zongsave.txt");
		if(in.fail())
		{
			cout<<"Fail!";
		}
		while(in.eof()!=1)
		{
			in>>jing;
			if(jing=='#')
			{
				in>>zhong;
				if(zhong==id1)
				{
					in>>name1;
					jing=0;
				}
			}
		} 
		in.close();
		
		ifstream in1(name1.c_str());
		int zid;
		vector<string>zqid;
		in1>>zid;
		while(in1.eof()!=1)
		{
			in1>>zhong;
			zqid.push_back(zhong);
		}
		in1.close();//-------------将文件信息读取到内存
		for(vector<string>::iterator it1=zqid.begin();it1!=zqid.end();)
		{
			if(*it1==stringid)
			{
				zqid.erase(it1);
				continue;
			}
			++it1;
		 } //-----------------------内存信息修改DONE！
		 ofstream out1(name1.c_str(),ios::out|ios::trunc);
		 out1<<zid;
		 for(int i=0;i<zqid.size();i++)
		{
		 	out1<<" "<<zqid[i];
		}
		out1.close();//---------------------内存信息存入文件 
    }
    else {cout<<"Incorrect input!\n";
	system("pause"); 
	}
	system("pause");
}

void Tencent_QQqun::chat(){
	cout<<"A temporary discussion group is being created···\n";
	cout<<"Existing members"<<common.size()<<"puople\n";
	cout<<"Their IDs are:\n";
	for(int i=0;i<common.size();i++)
	{
		cout<<common[i]<<"\n"; 
	}
	vector<string>talk;
	string ming;
	string zhong;
	char c;
	int ctr=1;
	bool flag=false;
	cout<<"Please enter a discussion group name:";
	cin>>ming;
	while(ctr)
	{
		cout<<"Enter the member ID to join the discussion group:\n";
		cin>>zhong;
		for(int i=0;i<common.size();i++)
		{
			if(common[i]==zhong)
			flag=true;
		}
		for(int i=0;i<talk.size();i++)
		{
			if(talk[i]==zhong)
			{
				flag=false;
				cout<<"The member is already in the discussion group!";
				system("pause");
			}
		}
		if(flag)
		{
			talk.push_back(zhong);
			cout<<"This person has been pulled into the discussion group\n";
			cout<<"Do you want to add?(y/n)\n";
			cin>>c;
			if(c=='y'||c=='Y')
			{flag=false;}
			else
			{ctr=0;}
		}
		else
		{
			cout<<"Incorrect input, whether to continue typing?(y/n)";
			cin>>c;
			if(c=='y'||c=='Y')
			flag=false;
			else
			ctr=0;
		}
	}
	if(flag)
	{
		cout<<"Discussion group created!\n";
		cout<<"Discussion Group Name:"<<ming<<"\n";
		cout<<"Discussion Group Members:\n";
		for(int i=0;i<talk.size();i++)
		{
			cout<<talk[i]<<"\n";
		} 
		system("pause");
	}
} 

void Tencent_QQqun::guanli(){
	int i;
	int j;
	cout<<"Welcome to the group management interface!\n";
	if(judge==1)
	{
		cout<<"Welcome,leader!\n";
		cout<<"Please enter your choice:\n";
		cout<<"1.Kicking\n";
		cout<<"2.Output the discussion group member information\n";
		cout<<"3.Create a temporary discussion group\n";
		cout<<"4.Drop out\n";
		cin>>i;
		if(i<=0||i>4)
		{
			cout<<"输入有误！请重新输入:\n";
			cin>>i;
		}
		switch(i)
		{
			case 1:
				tiren();
				break;
			case 2:
				cout<<"Existing members: "<<common.size()<<" people\n";
				cout<<"Their QQ are:\n";
				for(j=0;j<common.size();j++)
				{
					cout<<common[j]<<"\n";
				}
				system("pause");
				break;
			case 3:
				chat();
				break;
			case 4:
				return;
		}
	}
	else 
	{
		cout<<"Welcome,member!\n";
		cout<<"Please enter your choice:\n";
		cout<<"1. Output group member information\n";
		cout<<"2. Create a temporary discussion group\n";
		cout<<"3. Quit\n";
		cin>>i;
		if(i<=0||i>3)
		{
			cout<<"输入有误!请重新输入:\n";
			cin>>i;
		 } 
		 switch(i)
		 {
		 	case 1:
		 		cout<<"Existing members"<<common.size()<<"people\n";
				cout<<"Their QQ number are:\n";
				for(j=0;j<common.size();j++)
				{
					cout<<common[j]<<"\n";
				}
				system("pause");
				break;
			case 2:
				chat();
				break;
			case 3:
				return ;
		 }
	}
}

Tencent_QQqun::~Tencent_QQqun(){
	char sz[5];
	if(id!=0)
	{
		cout<<"Information is saved···\n";
		sprintf(sz,"%d",id);
		ofstream a(sz,ios::out|ios::trunc);
		a<<id;
		for(int i=0;i<common.size();i++)
		{
			a<<" "<<common[i];
		}
		a.close();
	}
}


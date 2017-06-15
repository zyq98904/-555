#include"Weiqun.h"
#include"Base.h"
#include"BaseQ.h"
#include"Weixin.h"
#include"iostream"
#include"string"
#include"fstream"
#include"stdio.h"
#include"windows.h"
#include"vector"
#include"sstream"
using namespace std;

int Tencent_weiqun::ID=2100;

Tencent_weiqun::Tencent_weiqun(string a)
{
	vip=a;
	id=ID++;
	cout<<"Please enter the weixin group nickname you created:\n";
	cin>>name;
	judge=1;
	common.push_back(vip);
	//--------------��֤�ļ�����,д��----------//
	ofstream b("D:\\weiqun_vip.txt",ios::out|ios::app);
	if(b.fail())
	{
		ofstream c("D:\\weiqun_vip.txt");
		c.close();
	}
	b<<"#"<<id<<" "<<vip<<" "<<name<<" "<<"\n";
	b.close();
	cout<<"Open success!\n";
	cout<<"The group ID is:"<<id<<"\n";
	cout<<"The name of the group is:"<<name<<"\n";
	cout<<"Members of the group :"<<common.size()<<" people\n";
}

Tencent_weiqun::Tencent_weiqun(int find,string a)
{
//----------------��֤�ļ���ȫ--------------//
    ofstream b("D:\\weiqun_vip.txt",ios::out|ios::app);
    if(b.fail()){ofstream c("D:\\weiqun_vip.txt");
    c.close();}
    b.close();
//----------------��֤-----------------//
    char jing;
    int id1;
    string vip1;
    string name1;
    bool flag=false;
    ifstream in("D:\\weiqun_vip.txt");
while(in.eof()!=1)
{
	in>>jing;
	in>>id1;
	in>>vip1;
	in>>name1;
	if(id1==find)
	{
		flag=true;
	}
} 
	in.close();
//----------------��½����ȡ�ļ�---------------//
char sz[5];
if(flag)
{
	ifstream in2("D:\\weiqun_vip.txt");
	while(in2.eof()!=1)
	{
		in2>>jing;
		in2>>id1;
		in2>>vip1;
		in2>>name1;
		if(id1==find)
		{id=id1;
		name=name1;
		vip=vip1;
		cout<<"loading...\n";
		id1=0;
		}
	}
	in2.close();
//-------------��ȡ��Ա��Ϣ------------//
sprintf(sz,"%d",id);
ifstream in3(sz);
if(in3.fail()){
	cout<<"Group file failed to open, or group does not exist!\n";
	exit(-1);
}
in3>>id1;
common.clear();
while(in3.eof()!=1)
{
	in3>>vip1;
	common.push_back(vip1);
}
in3.close();
//-------------------����||��ȡ����Ա��Ϣ---------//
string qun;
qun=name+"admin";
ifstream in4(qun.c_str());
if(in4.fail()){
	cout<<"����Ա�ļ���ʧ��,�����Ⱥ������!\n";
	exit(-1);
} 
in4>>id1;
admin.clear();
while(in4.eof()!=1)
{
	in4>>vip1;
	admin.push_back(vip1);
}
in4.close();
//------------------�ж����-----------------//
if(vip==a)
{
	judge=1;
 } 
 else
 {judge=0;
 }
 for(int i=0;i<admin.size();i++)
 {
 	if(admin[i]==a)
 	judge=2;
 }
}
else{
 	cout<<"�����Ⱥ��Ϣ������!\n";
 	exit(-1);
 }
}

Tencent_weiqun::~Tencent_weiqun(){
	string qun;
	qun=name+"admin";
	char sz[5];
	if(id!=0)
	{
		cout<<"Saving...\n";
		sprintf(sz,"%d",id);
		ofstream a(sz,ios::out|ios::trunc);
		a<<id;
		for(int i=0;i<common.size();i++)
		{
			a<<" "<<common[i];
		}
		a.close();
		ofstream b(qun.c_str(),ios::out|ios::trunc);
		b<<id;
		for(int i=0;i<admin.size();i++)
		{
			b<<" "<<admin[i];
		}
		b.close();
	}
}

void Tencent_weiqun::gunali() {
	int i;
	int j;
	cout<<"��ӭ����Ⱥ�������:\n";
	if(judge==1)
	{
		cout<<"��ӭ��,Ⱥ��!\n";
		cout<<"����������ѡ��:\n";
		cout<<"1.�Ƽ�������Ա�����Ⱥ\n";
		cout<<"2.���Ⱥ��Ա��Ϣ\n";
		cout<<"3.����Ϊ����Ա\n";
		cout<<"4.����Ϊ��ͨ��Ա\n";
		cout<<"5.�˳�!\n";
		cin>>i;
		if(i<=0||i>5)
		{
			cout<<"������������������:\n";
			cin>>i;
		}
		switch(i)
		{
			case 1:
				laren();
				break;
			case 2:
				cout<<"���г�Ա"<<common.size()<<"��\n";
				cout<<"���ǵ�weixin�˺�ID�ֱ�Ϊ:\n";
				for(j=0;j<common.size();j++)
				{
					cout<<common[j]<<"\n";
				}
				cout<<"����Ա��"<<admin.size()<<"��";
				cout<<"���ǵ�weixin�˺�ID�ֱ�Ϊ:\n";
				for(j=0;j<admin.size();j++)
				{
					cout<<admin[j]<<"\n";
				}
				system("pause");
				break;
			case 3:
				up();
				break;
			case 4:
				down();
				break;
			case 5:
				return ;
		}
	}
	if(judge==2)
	{
		cout<<"��ӭ��������Ա!\n";
		cout<<"����������ѡ��:\n";
		cout<<"1.�Ƽ�������Ա���뱾Ⱥ\n";
		cout<<"2.���Ⱥ��Ա��Ϣ\n";
		cout<<"3.�˳�\n";
		cin>>i;
		if(i<=0||i>3)
		{
			cout<<"��������!����������:\n";
			cin>>i;
		}
		switch(i)
		{
			case 1:
				laren();
				break;
			case 2:
				cout<<"���г�Ա"<<common.size()<<"��\n";
				cout<<"���ǵ�weixin�˺�ID�ֱ���:\n";
				for(j=0;j<common.size();j++)
				{
					cout<<common[j]<<"\n";
				} 
				cout<<"����Ա��"<<admin.size()<<"��\n";
				cout<<"���ǵ�weixin�˺�ID�ֱ���:\n";
				for(j=0;j<admin.size();j++)
				{
					cout<<admin[j]<<"\n";
				}
				system("pause");
				break;
			case 3:
				return ;
		}
	}
	if(judge==3)
	{
		cout<<"��ӭ������Ա!";
		cout<<"����������ѡ��:\n";
		cout<<"1.���Ⱥ��Ա��Ϣ\n";
		cout<<"2.�˳�\n";
		cin>>i;
		if(i<=0||i>2)
		{
			cout<<"������������������:\n";
			cin>>i;
		}
		switch(i)
		{
			case 1:
				cout<<"���г�Ա"<<common.size()<<"��\n";
				cout<<"���ǵ�weixin�˺�ID�ֱ���:\n";
				for(j=0;j<common.size();j++)
				{
					cout<<common[j]<<"\n";
				} 
				system("pause");
				break;
			case 2:
				return ;
		}
	}
}

void Tencent_weiqun::laren(){
	string weiid;
	string zhong;
	bool flag1=false;//-------�ж��Ƿ���� 
	bool flag2=false;//-------�жϱ�Ⱥ����Ա 
	bool flag3=false;//-------�жϱ�Ⱥ��Ա
	cout<<"������������ӵ�weixin�˺�:\n";
	cin>>weiid;
//--------�ж��˺��Ƿ����----------//
    ifstream in1("D:\\zhanghaowei.txt");
    if(in1.fail())
    {
    	cout<<"΢���˺��ļ�������";
    	exit(-1); 
	}
	while(in1.eof()!=1)
	{
		in1>>zhong;
		if(weiid==zhong)
		{
		cout<<"Find the target weixin account!\n";
		flag1=true;
		}
	}
	if(flag1==false)
	{
		cout<<"Can not find the account!";
		system("pause");
		return ; 
	}
	in1.close();
 //-----------�ж��Ƿ�Ϊ��Ⱥ��Ա-------//
    if(vip==weiid)
	{
		cout<<"The account for the group owners!\n";
		system("pause");
		return ;
	}
	for(int i=0;i<admin.size();i++)
	{
		if(admin[i]==weiid)
		{
			flag2=true;
		}
	}
	if(flag2)
	{
		cout<<"The account for the group administrator, don't need to join!\n";
		system("pause");
		return ; 
	}
	for(int i=0;i<common.size();i++)
	{
		if(common[i]==weiid)
		{
			flag3=true;
		}
	}
	if(flag3)
	{
		cout<<"The account is a member of this group!\n";
		system("pause");
		return ; 
	} 
//--------------�жϽ���---------//
    common.push_back(weiid);
	cout<<"Recommended to join success!\n";
	system("pause");	
}

void Tencent_weiqun::up(){
	bool flag2=false;
	bool flag3=false;
	string weiid;
	cout<<"Please enter the weiixn account ID of the member you want to promote:\n";
	cin>>weiid;
//-------------�ж�----------//
    for(int i=0;i<common.size();i++)
    {
    	if(common[i]==weiid)
    	{
    		flag3=false;
		}
	}
	if(flag3)
	{
		cout<<"The account is not a member of this group!\n";
		system("pause");
		return ;
	}
	if(vip==weiid)
	{
		cout<<"The account for the group owners!\n";
		system("pause");
		return ;
	}
	for(int i=0;i<admin.size();i++)
	{
		if(admin[i]==weiid)
		{
			flag2=true;
		}
	}
	if(flag2)
	{
		cout<<"The account for the group administrator! Can not be promoted\n";
		system("pause");
		return ;
	}
//----------------��ʼ���------------//
	admin.push_back(weiid);
	cout<<"Upgrade finished!\n";
	system("pause"); 
}

void Tencent_weiqun::down(){
	bool flag2=true;
	bool flag3=true;
	string weiid;
	cout<<"����������Ҫ��ְ�ĳ�Ա��weixin�˺�ID:\n";
	cin>>weiid;
//-------------�ж�-------------//
    for(int i=0;i<common.size();i++)
	{
		if(common[i]==weiid)
		{
			flag3=true;
		}
	}
	if(flag3)
	{
		cout<<"���˺Ų��Ǳ�Ⱥ��Ա!\n";
		system("pause");
		return ;
	}
	if(vip==weiid)
	{
		cout<<"���˺�Ϊ��ȺȺ�����޷���ְ\n";
		system("pause");
		return ;
	}
	for(int i=0;i<admin.size();i++)
	{
		if(admin[i]==weiid)
		{
			flag2=true;
		}
	} 
	if(flag2)
	{
		cout<<"���˺Ų��Ǳ�Ⱥ����Ա!\n";
		system("pause");
		return ;
	}
//------------��ʼ��ְ--------------//
    for(vector<string>::iterator it=admin.begin();it!=admin.end();)
	{
		if(*it==weiid)
		{
			admin.erase(it);
			continue;
		}
		++it;
	 }
	 system("pause");
}

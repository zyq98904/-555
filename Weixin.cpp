#include"string"
#include"Base.h"
#include"iostream"
#include"Weixin.h"
#include"Weiqun.h"
#include"fstream"
#include"BaseQ.h"
using namespace std;

Tencent_weixin::Tencent_weixin(){
	cout<<"Please input the account of WEIXIN you want to creat:\n";
	cin>>id;
	cout<<"Please input the nicheng:\n";
	cin>>name;
	string judge;
	int waring1=0;
	double waring2=0.2;
	Beizhu=name;
//-------------��֤�ļ�����-------------//
    ofstream k("D:\\zhanghaowei.txt",ios::out|ios::app);
	if(k.fail()){
		ofstream jjj("D:\\zhanghaowei.txt");
		jjj.close();
	}
	k.close();
//-----------���ļ�---------------//
    ifstream c("D:\\zhanghaowei.txt");
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
	cout<<"Please enter your password:\n";
	cin>>key;
	ofstream mi("D:\\mimawei.txt",ios::out|ios::app);
	mi<<"#"<<id<<" "<<key<<"\n";
	mi.close();
	Save();
} 

void Tencent_weixin::Save(){
	ofstream a("D:\\zhanghaowei.txt",ios::out|ios::app);
	a<<"\n";
	a<<id;
	a.close();
	ofstream b("D:\\zongsavewei.txt",ios::out|ios::app);
	b<<"#"<<id<<" "<<name<<" "<<birthday.year<<" "<<birthday.month<<" "<<birthday.day<<" "<<tyear.year<<" "<<tyear.month<<"  "<<tyear.day<<" "<<where.country<<" "<<where.province<<" "<<where.countryside<<" "<<Beizhu<<"\n";
	b.close();
}

const void Tencent_weixin::put(){
	cout<<"User weixin account:"<<id<<"\n";
	cout<<"User weixin nickname:"<<name<<"\n";
	cout<<"User Birthday:"<<birthday.year<<"."<<birthday.month<<"."<<birthday.day<<"\n";
	cout<<"User application time:"<<tyear.year<<"."<<tyear.month<<"."<<tyear.day<<"\n";
	cout<<"User address:"<<where.country<<"."<<where.province<<"."<<where.countryside<<"\n";
	system("pause"); 
}

void Tencent_weixin::Haoyoujiemian(){
	system("cls");
	load();
	cout<<"Welcome to the friend interface!\n";
	int a;
	while(1)
	{
		cout<<"1.��Ӻ���\n";
		cout<<"2.ɾ������\n";
		cout<<"3.���������Ϣ\n";
		cout<<"4.��ѯ����������Ϣ\n";
		cout<<"5.�˳�\n";
		cout<<"Please enter the service you need:\n";
		cin>>a;
		if(a==5)
		break;
		if(a<=0||a>5)
		{
			cout<<"������������������\n";
		}
		switch(a)
		{
			case 1:
				fried.List1_add_wei();
				save_haoyou();
				break;
			case 2:
				fried.List1_delete_wei();
				save_haoyou();
				break;
			case 3:
				fried.List1_put_wei();
				break;
			case 4:
				linkfriend_put();
				break;
		 } 
	}
}

void Tencent_weixin::save_haoyou(){
	string ID;
	ID=id+"wei";
	ofstream out(ID.c_str(),ios::out|ios::trunc);
	out<<id;
	for(int i=0;i<fried.list.size();i++)
	{
		out<<" "<<fried.list[i];
	}
	out.close();
}

void Tencent_weixin::load(){
	string ID;
	ID=id+"wei";
	ofstream b(ID.c_str(),ios::out|ios::app);
	b.close();
	ifstream a(ID.c_str());
	string id1;
	string list1;
	if(a.fail())
	{
		cout<<"�����ļ���ʧ��!\n";
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
	cout<<"��ȡ�����б�ɹ�!\n"; 
}

void Tencent_weixin::guanlianQQ(){
	system("cls");
	string guan;
	guan=id+"weilink";
	string QQid;
	string judge;
	char ch;
	bool flag=false;
//--------------�ж��Ƿ����qq-----------//
    ofstream tt(guan.c_str(),ios::out|ios::app);
	tt.close();
	ifstream ttt(guan.c_str());
	ch=ttt.get();
	if(ch!=EOF)
	{
	cout<<"The account has been associated with QQ account, no need to re-link!\n";
	ttt.close();
	system("pause");
	return ; }
	ttt.close();
	//-----------------------��ʼ-----------//
	cout<<"Welcome to QQ and WeChat associated interface\n";
	cout<<"Please enter the QQ number you want to associate:";
	cin>>QQid;
	//----------�ж��˺��Ƿ����----------//
	ifstream c("D:\\zhanghao.txt");
	if(c.fail()) 
	{
		cout<<"��Ҫ�ļ�ȱʧ!\n";
		exit(-1);
	}
	while(c.eof()!=1)
	{
		c>>judge;
		if(QQid==judge)
		{
			flag=true;
		}
	}
	c.close();
	if(flag==false)
	{
		cout<<"The entered account is not registered\n";
		cout<<"Is returning to the previous menu\n";
		system("pause");
		system("cls");
		return ;
	}
	//-----------��ʼ����||д���ļ�------//
	cout<<"Start the association\n";
	ofstream a(guan.c_str(),ios::out|ios::trunc);
	a<<id<<" "<<QQid;
	a.close();
	cout<<"The association is complete\n";
	system("pause"); 
}

void Tencent_weixin::deletelink(){
	system("cls");
	string guan;
	guan=id+"weilink";
	string zhong;
	string QQid;
	char ch;
	//------------�ж�--------------//
	ofstream tt(guan.c_str(),ios::out|ios::app);
	tt.close();
	ifstream ttt(guan.c_str());
	ch=ttt.get();
	if(ch==EOF)
	{
		cout<<"The account is not associated QQ account, can not lift the binding\n";
		ttt.close();
		system("pause");
		return ; 
	 } 
	 ttt.close();
	 //-------------��ʼ�Ӵ�----------//
	 ifstream in(guan.c_str());
	 in>>zhong;
	 in>>QQid;
	 cout<<"You are associated with the QQ account for:"<<QQid<<"\n";
	 cout<<"Whether to contact the association?(y/n)n";
	 cin>>ch;
	 if(ch=='y'||ch=='Y')
	 {
	 	ofstream z(guan.c_str(),ios::out|ios::trunc);
	 	cout<<"The association has been released\n";
	 }
	 else {
	 	return ;
	 }
	 system("pause");
}

void Tencent_weixin::linkfriend_put(){
	string zhong;
	string QQid;
	string haoyou;
//--------------�ж�---------------//
    string guan;
	guan=id+"weiid";
	char ch;
	ofstream tt(guan.c_str(),ios::out|ios::app);
	tt.close();
	ifstream ttt(guan.c_str());
	ch=ttt.get();
	if(ch==EOF){
		cout<<"The account is not associated with QQ account!\n";
		ttt.close();
		system("pause");
		return ; 
	} 
	ttt.close();
//--------------��ȡ----------------//
    ifstream in(guan.c_str());
	in>>zhong;
	in>>QQid;
	in.close();
	cout<<"��������QQ�˺�Ϊ:"<<QQid<<"\n";
	cout<<"���˺ŵĺ�����:\n";
	ifstream in1(QQid.c_str());
	in1>>zhong;
	while(in1.eof()!=1)
	{
		in1>>haoyou;
		cout<<haoyou<<"\n";
	}
	in1.close();
	system("pause");	
}

void Tencent_weixin::linkQ_put(){
	string zhong;
	string QQid;
	string haoyou;
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
	bool flag2=false;
	char jing;
//--------------------�ж�-----------//
    string guan;
	guan=id+"weilink";
	char ch;
	ofstream tt(guan.c_str(),ios::out|ios::app);
	tt.close();
	ifstream ttt(guan.c_str());
	ch=ttt.get();
	if(ch==EOF)
	{
		cout<<"���˺�δ����QQ�˺�!\n";
		ttt.close();
	}
//--------------��ȡ--------------//
    ifstream in(guan.c_str());
    in>>zhong;
    in>>QQid;
    in.close();
    ifstream e("D:\\zongsave.txt");
    while(e.eof()!=1)
    {
    	e>>jing;
    	if(jing=='#')
    	{
    		e>>id1;
    		if(QQid==id1)
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
    			flag2=true;
			}
		}
	}
	e.close();
	if(flag2)
	{
		cout<<"������QQ�˺�:"<<QQid<<"\n";
		cout<<"�ǳ�:"<<name1<<"\n";
		cout<<"����:"<<year1<<"."<<month1<<"."<<ri1<<"\n";
		cout<<"����ʱ��"<<year2<<"."<<month2<<"."<<ri2<<"\n";
		cout<<"��ͥסַ"<<country1<<"."<<province1<<"."<<countryside1<<"\n";	 
	}
	else
	cout<<"�ļ�ȱʧ!\n";
	system("pause");
}

void Tencent_weixin::load_weiqun(){
	string qun;
	qun=name+"weiqun";
	ofstream b(qun.c_str(),ios::out|ios::app);
	b.close();
	ifstream a(qun.c_str());
	string id1;
	int list1;
	if(a.fail())
	{
		cout<<"Ⱥ�ļ���ʧ��!\n";
		exit(0);
    }
    a>>id1;
    weiqun.list.clear();
    while(a.eof()!=1)
    {
    	a>>list1;
    	weiqun.list.push_back(list1);
	}
	a.close();
	cout<<"Proccessing information\n";
}

void Tencent_weixin::save_weiqun(){
	string qun;
	qun=name+"weiqun";
	ofstream out(qun.c_str(),ios::out|ios::trunc);
	out<<id;
	for(int i=0;i<weiqun.list.size();i++)
	{
		out<<" "<<weiqun.list[i]; 
	}
	out.close();
}

void Tencent_weixin::weiqun_Apply(){
	cout<<"Is opening weixin group\n";
	Tencent_weiqun a(id);
	weiqun.list.push_back(a.getid());
	system("pause");
}

void Tencent_weixin::weiqun_put(){
	cout<<"You have joined "<<weiqun.list.size()<<" groups\n";
	cout<<"Group account are:\n";
	for(int i=0;i<weiqun.list.size();i++)
	{
		cout<<weiqun.list[i]<<"\n";
	}
	system("pause");
}

void Tencent_weixin::weiqun_delete(){
	weiqun_put();
	int find;
	string zhong;
	int idzhong;
	char sz[5];
	cout<<"Please enter the group you want to exit\n";
	cin>>find;
//-------------�ж��Ƿ�ΪȺ��----------//
    sprintf(sz,"%d",find);
	ifstream judge(sz);
	if(judge.fail())
	{
		cout<<"There is no such group in the system!\n";
		system("pause");
		return ;
	 } 
	 judge>>idzhong;
	 judge>>zhong;
	 if(zhong==id)
	 {
	 	cout<<"Since you are the group owner, you can not do this!\n";
	 	system("pause");
	 	return ;
	 }
	 //-----------��ʼ�˳�Ⱥ--------//
	 Tencent_weiqun hlt(find,id);
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
	  for(vector<string>::iterator it3=hlt.admin.begin();it3!=hlt.admin.end();)
	  {
	  	if(*it3==id)
	  	{
	  		hlt.common.erase(it3);
	  		cout<<"You were not an administrator!\n";
	  		continue;
		}
		++it3;
	   }
		for(vector<int>::iterator it1=weiqun.list.begin();it1!=weiqun.list.end();)
		{
			if(*it1==find)
			{
				weiqun.list.erase(it1);
				continue;
			}
			++it1;
		}
		save_weiqun();
		system("pause");
	
}

void Tencent_weixin::weiqun_manage(){
	weiqun_put();
	int find;
	cout<<"Please enter the group you want to manage:\n";
	cin>>find;
	Tencent_weiqun hlt(find,id);
	hlt.gunali(); 
}

const void Tencent_weixin::jiemian(){
	system("cls");
	cout<<"������ʹ��weixn����\n";
	cout<<"��ӭ�����𾴵�"<<name<<"\n";
	int i;
	while(1)
	{
		system("cls");
		cout<<"----------------weixin������-----------\n";
		cout<<"1.���ѹ���\n";
		cout<<"2.����΢��Ⱥ\n";
		cout<<"3.���Ⱥ��Ϣ\n";
		cout<<"4.�˳�Ⱥ\n";
		cout<<"5.����Ⱥ\n";
		cout<<"6.����QQ\n";
		cout<<"7.��ѯ�����˺���Ϣ\n";
		cout<<"8.�������\n";
		cout<<"9.�˳�����\n";
		cout<<"����������Ҫ�ķ���:\n";
		cin>>i;
		if(i==9)
		break;
		if(i<=0||i>9)
		{
			cout<<"��������,����������:\n";
			cin>>i;
		}
		switch(i)
		{
			case 1:
				Haoyoujiemian();
				break;
			case 2:
				load_weiqun();
				weiqun_manage();
				break;
			case 3:
				load_weiqun();
				weiqun_put();
				break;
			case 4:
				load_weiqun();
				weiqun_delete();
				break;
			case 5:
				load_weiqun();
				weiqun_Apply();
				save_weiqun();
				break;
			case 6:
				guanlianQQ();
				break;
			case 7:
				linkQ_put();
				break;
			case 8:
				deletelink();
				break;
		}
		 
	}
}



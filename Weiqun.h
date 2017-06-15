#ifndef WEIQUN
#define WEIQUN
#include"string"
#include"vector"
using namespace std;

class Tencent_weiqun{
	protected:
		string vip;
		string name;
		static int ID;
		int id;
		int judge;
	public:
		vector<string>admin;//----------------管理员 
		vector<string>common;//---------------成员 
		int& getid(){return id;}//------------返回id 
		Tencent_weiqun(string);//-------------创建群所用的vip 
		Tencent_weiqun(int,string);//---------登陆操作 
		void gunali();//----------------------管理函数 
		void laren();//-----------------------拉人进群 
		void up();//--------------------------提升 
		void down();//------------------------降职 
		~Tencent_weiqun();//------------------保存信息到文件 
};
#endif


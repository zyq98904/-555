#include"weibo.h"
#include"Base.h"
#include"BaseQ.h"
#include"iostream"
#include"fstream"
#include"string"
using namespace std;

class Tencent_QQqun{
	public:
		static int ID;
		string vip;
		string name;
		int id;
		int judge;
	public:
	vector<string>admin;//管理员 
	vector<string>common;//普通成员 
	int& getid(){return id;};
	Tencent_QQqun(string );
	Tencent_QQqun(int,string);
	~Tencent_QQqun();//保存信息 
	void tiren();
	void laren();
	void chat();
	void guanli(); 
};

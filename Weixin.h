#ifndef WEI
#define WEI
#include"string"
#include"Base.h"
#include"iostream"
#include"BaseQ.h"
using namespace std;

class Tencent_weixin{
	public:
		Tencent_weixin();
		Tencent_weixin(string i,string n,int a,int b,int c,int a1,int b1,int c1,string d,string e,string f):birthday(a,b,c),tyear(a1,b1,c1),where(d,e,f)
		{
			id=i;
			name=n;
		}
		void Save();//----------------保存信息到文件 
		const void put();//-----------输出个人信息 
		const void jiemian();//-------登陆界面 
		void Haoyoujiemian();//-------调用List1 
		void load();//------------------读取好友列表 
		void save_haoyou();//---------保存好友到文件 
		void save_weiqun();//---------保存群信息到文件 
		void guanlianQQ();//----------关联QQ 
		void deletelink();//----------解除关联
		void linkfriend_put();//----------查找关联账号好友
		void linkQ_put();//---------------查找关联账号信息
		void load_weiqun();//-------------创建读取微信信息文件
		void weiqun_Apply();//------------申请微信群
		void weiqun_put();//--------------输入加入群的信息
		void weiqun_delete();//-----------退出群
		void weiqun_manage();//-----------管理群
	protected:
		string id;//----------------------号码 
		string name;//--------------------名字 
		Date birthday;//------------------生日 
		Date tyear;//---------------------申请时间 
		Address where;//------------------地址 
		string key;//---------------------密码 
		List1 fried;//--------------------weixin好友向量 
		List2 weiqun;//-------------------weixin群存储群向量 
		string Beizhu;//------------------好友备注 
};
#endif


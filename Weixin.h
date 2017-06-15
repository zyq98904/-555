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
		void Save();//----------------������Ϣ���ļ� 
		const void put();//-----------���������Ϣ 
		const void jiemian();//-------��½���� 
		void Haoyoujiemian();//-------����List1 
		void load();//------------------��ȡ�����б� 
		void save_haoyou();//---------������ѵ��ļ� 
		void deletelink();//----------�������
		void linkfriend_put();//----------���ҹ����˺ź���
		void linkQ_put();//---------------���ҹ����˺���Ϣ
		void load_weiqun();//-------------������ȡ΢����Ϣ�ļ�
		void weiqun_Apply();//------------����΢��Ⱥ
		void weiqun_put();//--------------�������Ⱥ����Ϣ
		void weiqun_delete();//-----------�˳�Ⱥ
		void weiqun_manage();//-----------����Ⱥ
	protected:
		string id;//----------------------���� 
		string name;//--------------------���� 
		Date birthday;//------------------���� 
		Date tyear;//---------------------����ʱ�� 
		Address where;//------------------��ַ 
		string key;//---------------------���� 
		List1 fried;//--------------------weixin�������� 
		List2 weiqun;//-------------------weixinȺ�洢Ⱥ���� 
		string Beizhu;//------------------���ѱ�ע 
};
#endif


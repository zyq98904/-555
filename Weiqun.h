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
		vector<string>admin;//----------------����Ա 
		vector<string>common;//---------------��Ա 
		int& getid(){return id;}//------------����id 
		Tencent_weiqun(string);//-------------����Ⱥ���õ�vip 
		Tencent_weiqun(int,string);//---------��½���� 
		void gunali();//----------------------������ 
		void laren();//-----------------------���˽�Ⱥ 
		void up();//--------------------------���� 
		void down();//------------------------��ְ 
		~Tencent_weiqun();//------------------������Ϣ���ļ� 
};
#endif


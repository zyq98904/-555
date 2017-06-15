#ifndef WEI
#define WEI

#include<string>
using namespace std;

class weibo{
	protected:
		string id;
	public:
		weibo(string);//-----------------开通且自动保存 
		~weibo();//----------------------析构并自动保存 
};

#endif 

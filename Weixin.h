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
	protected:
};
#endif


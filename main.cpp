#include"Base.h"
#include"BaseQ.h"
#include"Function_h.h"
#include"iostream"
#include"Qqun.h"
#include"string"
#include"Weiqun.h"
#include"Weixin.h"
#include"weibo.h"
#include"windows.h"
using namespace std;

int ctrl=1;//全局循环变量

int main()
{
	jiemian_main();
	while(ctrl)
	{
		jiemian(); 
	}
 } 

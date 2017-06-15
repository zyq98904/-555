#include"iostream"
#include"windows.h"
#include"Base.h"
#include"BaseQ.h"
#include"Function_h.h"
using namespace std;

void jiemian_main(){
	int b;
	int a=MessageBox(NULL,"欢迎进入本系统\n 正在加载\n 即将进入本系统","Tencent",MB_OK);
	cout<<"*********************吉林大学软件学院*****************\n";
	Sleep(100);
	cout<<"**********************第二次程序设计******************\n";
	Sleep(100);
	cout<<"                        作者:张叶钦                   \n";
	cout<<"\n";
	cout<<" 请输入所需服务:\n";
	cout<<"1.注册QQ账号\n";
	cout<<"2.登陆QQ账号\n";
	cout<<"3.注册weixin账号\n";
	cout<<"4.登陆weixin账号\n";
	cout<<"5.退出该系统\n";
	cin>>b;
	if(b<=0||b>5){
		cout<<"输入有误，请重新输入:\n";
		cin>>b;
	}                  
	switch(b)
	{
		case 1:
			zhuceQ();
			break;
		case 2:
			dengluQ();
			break;
		case 3:
			zhuceW();
			break;
		case 4:
			dengluW();
			break;
		case 5:
			cout<<"谢谢，欢迎下次使用";
			Sleep(800);
			exit(0);
			break;
	}
}

void jiemian(){
	int b;
	cout<<" 请选择所需的服务：\n";
	cout<<"1.注册QQ账号\n";
	cout<<"2.登陆QQ账号\n";
	cout<<"3.注册weixin账号\n";
	cout<<"4.登陆wexin账号\n";
	cout<<"5.退出该系统\n";
	cin>>b;
	if(b<=0||b>5)
	{
		cout<<"输入错误，请重新输入：\n";
		cin>>b;
	 } 
	 switch(b)
	 {
	 	case 1:
	 		zhuceQ();
	 		break;
	 	case 2:
	 		dengluQ();
	 		break;
	 	case 3:
	 		zhuceW();
	 		break;
	 	case 4:
	 		dengluW();
	 		break;
	 	case 5:
	 		cout<<"谢谢，欢迎下次使用\n";
	 		Sleep(800);
	 		exit(0);
	 		break;
	 }
}


#include"iostream"
#include"windows.h"
#include"Base.h"
#include"BaseQ.h"
#include"Function_h.h"
using namespace std;

void jiemian_main(){
	int b;
	int a=MessageBox(NULL,"��ӭ���뱾ϵͳ\n ���ڼ���\n �������뱾ϵͳ","Tencent",MB_OK);
	cout<<"*********************���ִ�ѧ���ѧԺ*****************\n";
	Sleep(100);
	cout<<"**********************�ڶ��γ������******************\n";
	Sleep(100);
	cout<<"                        ����:��Ҷ��                   \n";
	cout<<"\n";
	cout<<" �������������:\n";
	cout<<"1.ע��QQ�˺�\n";
	cout<<"2.��½QQ�˺�\n";
	cout<<"3.ע��weixin�˺�\n";
	cout<<"4.��½weixin�˺�\n";
	cout<<"5.�˳���ϵͳ\n";
	cin>>b;
	if(b<=0||b>5){
		cout<<"������������������:\n";
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
			cout<<"лл����ӭ�´�ʹ��";
			Sleep(800);
			exit(0);
			break;
	}
}

void jiemian(){
	int b;
	cout<<" ��ѡ������ķ���\n";
	cout<<"1.ע��QQ�˺�\n";
	cout<<"2.��½QQ�˺�\n";
	cout<<"3.ע��weixin�˺�\n";
	cout<<"4.��½wexin�˺�\n";
	cout<<"5.�˳���ϵͳ\n";
	cin>>b;
	if(b<=0||b>5)
	{
		cout<<"����������������룺\n";
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
	 		cout<<"лл����ӭ�´�ʹ��\n";
	 		Sleep(800);
	 		exit(0);
	 		break;
	 }
}


#include <iostream>
#include <string>
using namespace std;

bool input(Info *info)	//�˴�����ʱ��ע��ֲ������ĵ�ַ���ܷ���
{
	string name;
	cout<<"�����������Ϣ��"<<endl;
	cout<<"������";
	cin>>info->name;
	cout<<"������";
	cin>>info->job;
	cout<<"��ߣ�";
	cin>>info->height;
	cout<<"�����أ�";
	wcin>>info->birthplace;	//���ַ�
	cout<<"�������ڣ�";
	cin>>info->birthday;
	cout<<"�������ڣ�";
	cin>>info->deathday;
	cout<<"���꣺"<<endl;
	cin>>info->age;
	cout<<"�Ļ�ˮƽ��";
	cin>>info->education;
	cout<<"�Ƿ��й�׿�����ף�";
	cin>>info->great;
	cout<<"�Ƿ��ڣ�";
	cin>>info->live;
	cout<<"�Ա�(��1Ů0)��";
	cin>>info->gender;
	return true;
}

void Display(Person* p)
{
	cout<<"������Ϣ��"<<endl;
	cout<<"������"<<p->info.name<<endl;
	cout<<"ְҵ��"<<p->info.job<<endl;
	cout<<"�Ա�"<<p->info.gender<<endl;
	cout<<"��ߣ�"<<p->info.height<<endl;
	wcout<<"�����أ�"<<p->info.birthplace<<endl;
	cout<<"�������ڣ�"<<p->info.birthday<<endl;
	cout<<"����ˮƽ��"<<p->info.education<<endl;
	cout<<"�Ƿ�������"<<p->info.live<<endl;
	cout<<"�������ڣ�"<<p->info.deathday<<endl;
	cout<<"���꣺"<<p->info.age<<endl;
	cout<<"�Ƿ��й�׿Խ���ף�"<<p->info.great<<endl;
}
bool login_confirm()
{
	string passwd = "123456";
	string mypasswd;
	cout<<"�������룺";
	cin>>mypasswd;
	if (passwd==mypasswd)
		return true;
	else
		return false;
}
bool Login()
{
	cout<<"********��ӭ�������׹���ϵͳ����Ա��¼����************"<<endl;
	int choice;
	while(true)
	{
		cout<<"1.���ǹ���Ա"<<endl;
		cout<<"2.�Ҳ��ǹ���Ա\n"<<endl;
		cout<<"�������ѡ��"<<endl;
		cin>>choice;
		switch(choice)
		{
		case 1:
			int count;
			if (login_confirm())
				return true;
			else
			{
				cout<<"*****��ʾ����������㻹�����λ��ᣡ"<<endl;
				for(count = 1;count<=3;count++)
				{
					if (login_confirm())
					{
						return true;
						break;
					}
					cout<<"*****��ʾ���������"<<endl;
				}
				cout<<"���Ѿ�ʧ�����Σ��Զ���ת����ͨ����"<<endl;
				return false;
			}
			break;
		case 2:
			return false;
			break;
		default:
			cout<<"û�����ѡ��Զ�Ϊ����ת��ͨ����"<<endl;
			return false;
		}
	}
}

/*bool Loging()
{
	char a[10];
	char b[10];
	char c[10]="abc123";
	char d[10]="123456";
	int flag;
	cout<<"�������û�����"<<endl;
	cin>>a;
	cout<<"���������룺"<<endl;
	cin>>b;
	if((!strcmp(a,c))&&(!strcmp(b,d)))
	{
		cout<<"��֤ͨ��!"<<endl;
		return true;
	}
	else
	{
		cout<<"��ȷ��������˺������Ƿ���ȷ��"<<endl;
		cout<<endl;
		cout<<"��Ҫ�ٴ������밴1�������밴2��"<<endl;
		cin>>flag;
		if(flag==1)
		{
			if(Loging())
			{
				return true;
			}
			else
				return false;
		}
		else 
			return false;
	}
}

bool Login()
{
	cout<<"������ǹ���Ա�������롰1���������˺ź����룡���������롰2������~"<<endl;
	int i;
	cin>>i;
	switch(i)
	{
		case 1 :
			return Loging();
			break;
		case 2 :
			return false;
			break;
		default :
			return false;
			break;
	}
}*/


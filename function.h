#include <iostream>
#include <string>
using namespace std;

void Detect(bool *temp)
{
	while(!(cin>>*temp))
	{
		cin.clear();
		while(cin.get()!='\n'){
			continue;
		}
		cout<<"��ʾ����������\n���������룺"<<endl;
	}
}

void Detect(int *temp)
{
	while(!(cin>>*temp))
	{
		cin.clear();
		while(cin.get()!='\n'){
			continue;
		}
		cout<<"��ʾ����������\n���������룺"<<endl;
	}
}

void Detect(double *temp)
{
	while(!(cin>>*temp))
	{
		cin.clear();
		while(cin.get()!='\n'){
			continue;
		}
		cout<<"��ʾ����������\n���������룺"<<endl;
	}
}


bool Detect(string temp)	//��������Ƿ���ȷ
{
	const regex pattern("\\d{2,4}[-\.]\\d{0,2}[-\.]\\d{0,2}");
	return regex_match(temp,pattern);
}


bool input(Info *info)	//�˴�����ʱ��ע��ֲ������ĵ�ַ���ܷ���
{
	string name;
	string date;
	cout<<"�����������Ϣ��"<<endl;
	cout<<"������";
	cin>>info->name;
	cout<<"������";
	cin>>info->job;
	cout<<"���(��λ������)��";
	Detect(&(info->height));
	cout<<"�����أ�";
	cin>>info->birthplace;	//���ַ�
	cout<<"�������ڣ�";
	while(true)
	{
		cin>>date;
		if(Detect(date))
			break;
		else
			cout<<"��ʾ������ȷ�����ڣ�"<<endl;
	}
	info->birthday = date;
	cout<<"�������ڣ�";
	while(true)
	{
		cin>>date;
		if(Detect(date))
			break;
		else
			cout<<"��ʾ������ȷ�����ڣ�"<<endl;
	}
	info->deathday = date;
	cout<<"���꣺";
	Detect(&(info->age));
	cout<<"�Ļ�ˮƽ��";
	cin>>info->education;
	cout<<"�Ƿ��й�׿�����ף�";
	Detect(&(info->great));
	cout<<"�Ƿ��ڣ�";
	Detect(&(info->live));
	cout<<"�Ա�(��1Ů0)��";
	Detect(&(info->gender));
	return true;
}

void Display(Person* p)
{
	cout<<"������Ϣ��"<<endl;
	cout<<"������"<<p->info.name<<endl;
	cout<<"ְҵ��"<<p->info.job<<endl;
	cout<<"�Ա�"<<p->info.gender<<endl;
	cout<<"��ߣ�"<<p->info.height<<endl;
	cout<<"�����أ�"<<p->info.birthplace<<endl;
	cout<<"�������ڣ�"<<p->info.birthday<<endl;
	cout<<"����ˮƽ��"<<p->info.education<<endl;
	cout<<"�Ƿ�������"<<p->info.live<<endl;
	cout<<"�������ڣ�"<<p->info.deathday<<endl;
	cout<<"���꣺"<<p->info.age<<endl;
	cout<<"�Ƿ��й�׿Խ���ף�"<<p->info.great<<endl;
	cout<<"\n"<<endl;
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
		Detect(&choice);
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

void admin_menu()
{
	cout<<"**************���׹���ϵͳ�������**************"<<endl;
	cout<<"*		1.�½�                         *"<<endl;
	cout<<"*		2.ɾ��                         *"<<endl;
	cout<<"*		4.����������                   *"<<endl;
	cout<<"*		5.��ʾ����                     *"<<endl;
	cout<<"*		6.��������                     *"<<endl;
	cout<<"*		7.��Ӽ����Ա                 *"<<endl;
	cout<<"*		8.ͳ������                     *"<<endl;
	cout<<"*		9.ģ����ѯ                     *"<<endl;
	cout<<"*		10.�浵                     *"<<endl;
	cout<<"*		1024.�л��û�                  *"<<endl;
	cout<<"*		0.�˳�                         *"<<endl;
	cout<<"************************************************\n"<<endl;
}



bool Store(Person* p,ofstream& outfile)
{
	if(p)
	{
		outfile<<"��ͨ�ڵ㣺"<<endl;
		outfile<<p->info.name<<endl;
		outfile<<p->info.gender<<endl;
		outfile<<p->info.height<<endl;
		outfile<<p->info.job<<endl;
		outfile<<p->info.birthplace<<endl;
		outfile<<p->info.birthday<<endl;
		outfile<<p->info.live<<endl;
		outfile<<p->info.deathday<<endl;
		outfile<<p->info.age<<endl;
		outfile<<p->info.education<<endl;
		outfile<<p->info.great<<endl;
		if(p->mate.name!="��")
		{
			outfile<<"��ż��"<<endl;
			outfile<<p->mate.name<<endl;
			outfile<<p->mate.gender<<endl;
			outfile<<p->mate.height<<endl;
			outfile<<p->mate.job<<endl;
			outfile<<p->mate.birthplace<<endl;
			outfile<<p->mate.birthday<<endl;
			outfile<<p->mate.live<<endl;
			outfile<<p->mate.deathday<<endl;
			outfile<<p->mate.age<<endl;
			outfile<<p->mate.education<<endl;
			outfile<<p->mate.great<<endl;
		}
		else
		{
			outfile<<"����ż"<<endl;
		}	
		Store(p->firstchild,outfile);
		Store(p->nexsilbing,outfile);
		return true;
	}
	else
	{
		outfile<<"�޽ڵ�"<<endl;
		return true;
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


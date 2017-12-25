#include "base.h"
#include "definition.h"
#include "function.h"
#include "genealogy.h"

int main()
{
	Genealogy gen;
	Person *root = NULL;
	Person *temp;	//��Ŷ����е�root
	Person* result;
	string name;	//����ʱ������
	Rel rel;//��ϵ
	int rel_num;
	login:if (Login())
	{
		int choice;
		while(true)
		{
			cout<<"**************���׹���ϵͳ�������**************"<<endl;
			cout<<"1.�½�"<<endl;
			cout<<"2.ɾ��"<<endl;
			cout<<"4.����������"<<endl;
			cout<<"5.��ʾ����"<<endl;
			cout<<"6.��������"<<endl;
			cout<<"7.��Ӽ����Ա"<<endl;
			cout<<"8.ͳ������"<<endl;
			cout<<"1024.�л��û�"<<endl;
			cout<<"0.�˳�\n"<<endl;

			cout<<"�������ѡ��"<<endl;
			cin>>choice;
			switch(choice)
			{
			case 1:
				if (gen.Create(&root))
				{
					gen.set_root(root);
					cout<<"�����ɹ���"<<endl;
				}
				else
					cout<<"����ʧ�ܣ�"<<endl;
				break;
			case 2:
				cout<<"��������Ҫɾ�����˵����֣�"<<endl;
				cin>>name;
				temp = gen.get_root();
				if(gen.Delete(temp,name))
					cout<<"ɾ���ɹ�"<<endl;
				else
					cout<<"ɾ��ʧ��"<<endl;
				break;
			case 4:
				temp = gen.get_root();
				cout<<"����һ�����֣�"<<endl;
				cin>>name;
				result = gen.Search(temp,name);
				if(result)
					Display(result);
				else
					cout<<"������û�������"<<endl;
				break;
			case 5:
				temp =gen.get_root();
				gen.Show(temp,0);
				break;
			case 6:
				temp =gen.get_root();
				cout<<"����һ�����֣�"<<endl;
				cin>>name;
				gen.Update(temp,name);
				break;
			case 7:
				temp =gen.get_root();
				cout<<"����һ�����֣�"<<endl;
				cin>>name;
				cout<<"������뽫Ҫ��ӵ��˵Ĺ�ϵ����parent/brother��"<<endl;
				cin>>rel_num;	
				switch(rel_num)
				{
				case 0:
					rel = brother;
					break;
				default:
					rel = parent;
					break;
				}

				if(gen.Add(temp,name,rel))
					cout<<"��ӳɹ�"<<endl;
				else
					cout<<"���ʧ��"<<endl;
				break;
			case 8:
				temp =gen.get_root();
				if(gen.Statistics(temp))
					cout<<"ͳ�����"<<endl;
				gen.GetAge();
				gen.GetHeight();
				gen.GetRatio();
				break;
			case 1024:
				goto login;
				break;
			case 0:
				exit(0);
				break;
			default:
				cout<<"��������"<<endl;
				break;
			}
		}
	}
	else
	{
		int choice;
		while(true)
		{
			cout<<"**************���׹���ϵͳ��ͨ����**************"<<endl;
			cout<<"1.�鿴����"<<endl;
			cout<<"2.����"<<endl;
			cout<<"3."<<endl;
			cout<<"4."<<endl;
			cout<<"1024.�л��û�"<<endl;
			cout<<"0.�˳�\n"<<endl;

			cout<<"�������ѡ��"<<endl;
			cin>>choice;
			switch(choice)
			{
			case 1:
				temp =gen.get_root();
				gen.Show(temp,0);
				break;
			case 2:
				temp = gen.get_root();
				cout<<"����һ�����֣�"<<endl;
				cin>>name;
				result = gen.Search(temp,name);
				if (result)
					Display(result);
				else
					cout<<"������û�������"<<endl;
				break;
			case 1024:
				goto login;
				break;
			case 0:
				exit(0);
				break;
			}
		}
	}
	system("pause");
	return 0;
}
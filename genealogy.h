class Genealogy{
private:
	Person *root;	//����������
	Num num;	//����ͳ��
	double ave_age;	//ƽ������
	double ave_height;	//ƽ�����
	double ratio;	//��Ů����
	//����ʷ�ݲ�ͳ��
	int sumage;	//�ܹ�����
	double sumheight;	//�ܹ����
public:
	Genealogy();	//���캯����ʼ��
	Person* get_root();
	void set_root(Person *root);
	bool Create(Person **p,Person **root);
	bool Login();	//����Ա��¼
	Person* Search(Person* p,const string name);
	Person* Search(Person* p,const string name,int tag);
	Person* FindPre(Person* p);
	bool Delete(Person* p,const string name); //������ɾ��
	bool Update(Person* p,const string name);	//��������
	bool Add(Person* p,string name,Rel rel);	//����³�Ա
	void Show(Person* p,int depth);
	bool MemSearch();		//����Ա��ѯ
	bool RelSearch();	//���ҳ�Ա֮��Ĺ�ϵ
	bool Statistics(Person* p);
	double GetAge();	//��ȡƽ������	
	double GetHeight();	//��ȡƽ�����
	double GetRatio();	//��ȡ��Ů����
};

Genealogy::Genealogy()
{
	this->root = NULL;
	this->num.sum = 0;
	this->num.mnum = 0;
	this->num.fnum = 0;
	this->num.lnum = 0;
	this->num.dnum = 0;
	this->num.gnum = 0;
	this->sumage = 0;
	this->sumheight = 0;
	this->ave_age = 0;
	this->ave_height = 0;
	this->ratio = 0;
}

Person* Genealogy::get_root()
{
	return root;
}

void Genealogy::set_root(Person* root)
{
	this->root = root;
}


bool Genealogy::Create(Person **p,Person **root)
{
	bool mate;
	int tag;
	*p = new Person;
	if (!(*p))
	{
		return false;
	}
	(*p)->parent = NULL;
	(*p)->firstchild = NULL;
	(*p)->nexsilbing = NULL;
	cout<<"���ˣ�"<<endl;
	input(&((*p)->info));
	cout<<"�Ƿ�����ż����1��ʾ�У�0��ʾû�У�"<<endl;
	Detect(&mate);
	if (mate)
	{
		cout<<"��ż��"<<endl;
		input(&((*p)->mate));
	}
	Show(*root,0);
	cout<<"1.���"<<(*p)->info.name<<"�ĺ���"<<endl;
	cout<<"2.���"<<(*p)->info.name<<"���ֵܽ���"<<endl;
	cout<<"3.�������"<<(*p)->info.name<<"�ĺ����ͬ��"<<endl;
	cout<<"�������ѡ��";
	Detect(&tag);
	switch(tag)
	{
	case 1:
		Create(&((*p)->firstchild),root);
		if ((*p)->firstchild)
			(*p)->firstchild->parent = *p;
		cout<<"******�Ƿ����"<<(*p)->info.name<<"���ֵܽ���"<<endl;
		Detect(&tag);
		if(tag)
		{
			Create(&((*p)->nexsilbing),root);
			if ((*p)->nexsilbing)
				(*p)->nexsilbing->parent = (*p)->parent;
		}
		else
			(*p)->nexsilbing = NULL;
		return true;
		break;
	case 2:
		Create(&((*p)->nexsilbing),root);
		if ((*p)->nexsilbing)
			(*p)->nexsilbing->parent = (*p)->parent;
		cout<<"******�Ƿ����"<<(*p)->info.name<<"�ĺ��ӣ���1��ʾ�ǣ�0��ʾ����ӣ�"<<endl;
		Detect(&tag);
		if(tag)
		{
			Create(&((*p)->firstchild),root);
			if ((*p)->firstchild)
				(*p)->firstchild->parent = *p;
		}
		else
			(*p)->firstchild = NULL;
		return true;
		break;
	case 3:
		(*p)->firstchild = NULL;
		(*p)->nexsilbing = NULL;
		return true;
		break;
	default:
		(*p)->firstchild = NULL;
		(*p)->nexsilbing = NULL;
		return true;
		break;
	}
}
/*bool Genealogy::Create(Person **p)
{
	int tag;
	bool mate;
	cout<<"����һ����������0��ʾ�ýڵ�Ϊ�գ�:"<<endl;
	cin>>tag;
	if (!tag)
	{
		*p =  NULL;
	}
	else
	{
		*p = new Person;
		if (!(*p))
		{
			return false;
		}
		(*p)->parent = NULL;
		cout<<"���ˣ�"<<endl;
		input(&((*p)->info));
		cout<<"�Ƿ�����ż����1��ʾ�У�0��ʾû�У�"<<endl;
		cin>>mate;
		if (mate)//����ż���к���
		{
			cout<<"��ż��"<<endl;
			input(&((*p)->mate));
			Create(&((*p)->firstchild));
			if ((*p)->firstchild)
				(*p)->firstchild->parent = *p;
		}
		else
		{
			(*p)->firstchild = NULL;
		}
		Create(&((*p)->nexsilbing));
		if ((*p)->nexsilbing)
			(*p)->nexsilbing->parent = (*p)->parent;
	}
	return true;
}*/
/*bool Genealogy::Create(Person **p)
{
	bool mate;
	if((*p)->parent)
	{
		int tag;
		cout<<"1.���"<<(*p)->parent->info.name<<"�ĺ���"<<endl;
		cout<<"2.���"<<(*p)->parent->info.name<<"���ֵܽ���"<<endl;
		cout<<"3.�������"<<(*p)->parent->info.name<<"�ĺ����ͬ��"<<endl;
		cout<<"�������ѡ��";
		Detect(&tag);
		switch(tag)
		{
		case 1:

			break;
		case 2:
			break;
		case 3:
			*p = NULL;
			return true;
			break;
		default:
			*p = NULL;
			return true;
			break;
		}
	}
	else
	{
		*p = new Person;
		if (!(*p))
		{
			return false;
		}
		(*p)->parent = NULL;
		cout<<"������Ϣ��"<<endl;
		input(&((*p)->info));
		cout<<"�Ƿ�����ż����1��ʾ�У�0��ʾû�У�"<<endl;
		Detect(&mate);	//�Ϸ��Լ��
		if (mate)//����ż���к���
		{
			cout<<"��ż��"<<endl;
			input(&((*p)->mate));
			Create(&((*p)->firstchild));
			if ((*p)->firstchild)
				(*p)->firstchild->parent = *p;
		}
		else
		{
			(*p)->firstchild = NULL;
		}
		Create(&((*p)->nexsilbing));
		if ((*p)->nexsilbing)
			(*p)->nexsilbing->parent = (*p)->parent;
	}
	if (!tag)
	{
		*p =  NULL;
	}
	else
	{
		*p = new Person;
		if (!(*p))
		{
			return false;
		}
		(*p)->parent = NULL;
		cout<<"������Ϣ��"<<endl;
		input(&((*p)->info));
		cout<<"�Ƿ�����ż����1��ʾ�У�0��ʾû�У�"<<endl;
		Detect(&mate);	//�Ϸ��Լ��
		if (mate)//����ż���к���
		{
			cout<<"��ż��"<<endl;
			input(&((*p)->mate));
			Create(&((*p)->firstchild));
			if ((*p)->firstchild)
				(*p)->firstchild->parent = *p;
		}
		else
		{
			(*p)->firstchild = NULL;
		}
		Create(&((*p)->nexsilbing));
		if ((*p)->nexsilbing)
			(*p)->nexsilbing->parent = (*p)->parent;
	}
	return true;
}*/
Person* Genealogy::FindPre(Person* p)//�ҵ���p�ڵ�������ǰһ���ڵ�
{
	if(p)
	{
		Person* temp;
		Person* pre;
		Person* current;
		if(p->parent)	
		{
			temp = p->parent;
			if (temp->firstchild!=p) //�ж�p�Ƿ��ǵ�һ������
			{
				current = temp->firstchild;
				while(current!=p)
				{
					pre = current;
					current = current->nexsilbing;
				}
				return pre;//����ǰһ���ֵ�
			}
			else	//�ǵ�һ�����ӣ�ֱ�ӷ��ظ��ڵ�
				return temp;
		}
		else		//ֻ�е�һ���˲�û�и��ڵ�
		{
			if(root==p)
				return NULL;
			else{
				current = root;
				while(current!=p)
				{
					pre = current;
					current = current->nexsilbing;
				}
				return pre;
			}
		}
	}
	return NULL;
}
Person* Genealogy::Search(Person* p,const string name)
{
	if(p)
	{
		//Person* pre;	//�������ƥ��ڵ��ǰһ���ڵ�
		Person* temp;
		//pre = p;
		if (p->info.name==name)
			return p;
		else
		{
			temp = Search(p->firstchild,name);
			if(temp)
				return temp;
			temp = Search(p->nexsilbing,name);
			if (temp)
				return temp;
			return NULL;
		}
	}
	return NULL;
}
Person* Genealogy::Search(Person* p,const string name,int tag)	//ģ����ѯ
{
	if(p)
	{
		return NULL;
	}
	return NULL;
}
/*Person* Search(Person* p,const string name)
{
	Person* temp;
	if (p->info.name==name)
		return p;
	else
	{
		if (p->firstchild)
			temp = Search(p->firstchild,name);
			if (temp)
				return temp;
		if (p->nexsilbing)
			temp = Search(p->nexsilbing,name);
			if (temp)
				return temp;
		if (!p->firstchild&&!p->nexsilbing)
			return NULL;
	}
}*/

bool Genealogy::Delete(Person *p,const string name)//�˴�bug:���ɾ���Ľڵ�Ϊ���ڵ㣬��ô������ΪNULL,˫ָ�롣
{
	if(p)
	{
		Person* target;
		Person* pre;
		target = Search(p,name);
		if (target)
		{
			if(target->firstchild||target->nexsilbing)
			{
				cout<<"�ýڵ㲻�ܱ�ɾ��"<<endl;
				return false;
			}
			else
			{
				pre = FindPre(target);
				if (pre)//Ŀ��ڵ�ǰһ���ڵ����
				{
					if (pre->firstchild==target)
						pre->firstchild=NULL;
					else
						pre->nexsilbing = NULL;
				}
				free(target);
				return true;
			}
		}
		return false;//������û�������
	}
	return false;
}

void Genealogy::Show(Person* p,int depth)
{
	if(p)
	{
		int i;
		for (i = 1;i<=depth;i++)
		{
			cout<<"\t";
		}
		cout<<p->info.name<<endl;
		Show(p->firstchild,depth+1);
		Show(p->nexsilbing,depth);
	}
}
/*bool Genealogy::Delete(Person getroot(),const string name)
{
	const char* M=name.c_str();
	const char* N=getroot().info.name.c_str();

	if((&getroot()!=NULL))
	{
		if((!strcmp(N,M))&&(getroot().firstchild==NULL)&&(getroot().nexsilbing==NULL))
		{
			free(&getroot());
			cout<<"�ѳɹ�ɾ��������Ϣ��"<<endl;
			return true;
		}
		else if((!strcmp(N,M))&&(getroot().firstchild!=NULL)||(getroot().nexsilbing!=NULL))
		{
			cout<<"���˲���ɾ����"<<endl;
			return true;
		}
		else if(getroot().firstchild!=NULL)
		{
			Delete(getroot().firstchild,name);
		}
		else if(getroot().nexsilbing!=NULL)
		{
			Delete(getroot().nexsilbing,name);
		}
	}
	else 
		{
			cout<<"δ�ҵ����ˣ�"<<endl;
			return false;
		}
}
*/



bool Genealogy::Update(Person* p,const string name)
{
	Person* temp;
	temp = Search(p,name);
	if (temp)
	{
		Display(temp);	//��ʾ��ʼ��Ϣ
		input(&(temp->info));	//���и���
		return true;
	}
	else
		cout<<"�������޸ó�Ա��"<<endl;
		return false;
}

bool Genealogy::Add(Person *p,string name,Rel rel)
{
	Person* temp;
	Person* point;//���ܸ�����
	bool mate;
	point = Search(p,name);
	if (point)
	{
		temp = new Person;
		input(&(temp->info));
		temp->firstchild = NULL;
		temp->nexsilbing = NULL;
		temp->parent = NULL;
		cout<<"�Ƿ�����ż����1��ʾ�У�0û�У�"<<endl;
		cin>>mate;
		if (mate)
		{
			input(&(temp->mate));
		}
		else
		{
			temp->mate.name = "��";		//û����ż�ͽ���ż������Ϊ��
		}
		if (rel==parent)
		{
			if (point->firstchild)
			{
				Person* child,*prechild;
				child = point->firstchild;
				while(child)
				{
					prechild = child;
					child = child->nexsilbing;
				}
				prechild->nexsilbing = temp;	//��temp��ӵ����׵��⼸�����ӵ����
				temp->parent = prechild->parent;
			}
			else
			{
				point->firstchild = temp;
				temp->parent = point;
			}
		}
		else
		{
			if(point->nexsilbing)
			{
				Person* child,*prechild;
				child = point->nexsilbing;
				while(child)
				{
					prechild = child;
					child = child->nexsilbing;
				}
				prechild->nexsilbing = temp;
				temp->parent = prechild->parent;
				return true;
			}
			else
			{
				point->nexsilbing = temp;
				temp->parent = point->parent;
			}
		}
	}
	else
		return false;
}


bool Genealogy::Statistics(Person* p)
{
	if(p)
	{
		if(p->info.gender==0)
			num.fnum++;
		if(p->info.gender==1)
			num.mnum++;
		if(p->info.live)
			num.lnum++;
		if(!p->info.live)
			num.dnum++;
		if(p->mate.great)
			num.gnum++;
		if(p->info.live==0)
			sumage+=p->info.age;
		if(p->info.live==0)
			sumheight+=p->info.height;
		num.sum++;
		Statistics(p->firstchild);
		Statistics(p->nexsilbing);
	}
	return false;
}


double Genealogy::GetAge()
{
	if(num.dnum)
	{
		ave_age = sumage/double(num.dnum);
		cout<<"ƽ������Ϊ��"<<ave_age<<endl;
		return ave_age;
	}
	cout<<"Ŀǰ�޷�ͳ��"<<endl;
	return 1000;
}
double Genealogy::GetHeight()
{
	if(num.dnum)
	{
		ave_height = sumheight/num.dnum;  
		cout<<"ƽ����ߣ�"<<ave_height<<endl;
		return ave_height;
	}
	cout<<"Ŀǰ�޷�ͳ��"<<endl;
	return 10000;
	
}
double Genealogy::GetRatio()
{
	if(num.fnum)
	{
		ratio = num.mnum/double(num.fnum);
		cout<<"�ü�����Ů����Ϊ��"<<num.mnum<<"��"<<num.fnum<<endl;
		return ratio;
	}
	else
	{
		ratio = 1;
		cout<<"�ü�����Ů����Ϊ��"<<num.mnum<<"��"<<num.fnum<<endl;
		return ratio;
	}
}
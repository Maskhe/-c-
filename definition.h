typedef struct num{
	int sum;	//������
	int fnum;	//Ů������
	int mnum;	//��������
	int dnum;	//��ȥ����
	int lnum;	//��������
	int gnum;	//���ش��׵�����
}Num;
typedef struct info{
	string name;
	string job;
	double height;
	wstring birthplace;
	string birthday;
	string deathday;
	string education;
	int age;
	bool great;
	bool live;
	bool gender;
}Info;

typedef struct person{
	Info info;		//������Ϣ
	Info mate;		//��ż��Ϣ
	struct person* parent;
	struct person* firstchild;
	struct person* nexsilbing;
}Person;

typedef enum rel{parent,brother}Rel;

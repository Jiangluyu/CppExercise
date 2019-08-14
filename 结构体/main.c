#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct student{
	char name[10];
	float grade1;
	int grade2;
};

void exc(struct student *stu1, struct student *stu2)
{
	int index;
	char tmpStr[11];
	int tmpInt;
	float tmpFloat;

	strcpy(tmpStr,stu1->name);
	strcpy(stu1->name,stu2->name);
	strcpy(stu2->name,tmpStr);

	tmpInt = stu1->grade2;
	stu1->grade2 = stu2->grade2;
	stu2->grade2 = tmpInt;

	tmpFloat = stu1->grade1;
	stu1->grade1 = stu2->grade1;
	stu2->grade1 = tmpFloat;
}

int main(void)
{


	struct student stu[10];

	for(int i = 0;i<10;i++)
		scanf("%d,%f,%s",&stu[i].grade2,&stu[i].grade1,stu[i].name);

	int index;

	for(int i=0;i<9;i++)
	{
		index = i;
		for(int j=i+1;j<10;j++)
		{
			if(strcmp(stu[index].name, stu[j].name)>0)
				index = j;
		}
		if(index != i)
		{
			exc(&stu[index], &stu[i]);
		}
	}

	for(int i = 0; i < 10; i++){
		printf("%s, %d, %f\n", stu[i].name, stu[i].grade2, stu[i].grade1);
	}

}

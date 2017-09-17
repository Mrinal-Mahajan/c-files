#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct student
	{
		char name[10];
		float marks[10];
	};
	
void setValues(struct student* s, char * name, float marks[], int nSubjects)
{
	strcpy((*s).name,name);
	int i;
	for(i=0;i<nSubjects;i++)
	{
	(*s).marks[i] = marks[i];
	//printf("%d %d",(*s).marks[i],marks[i]);
    }
}

float getAvg(struct student  s, int nSubjects)
{
	int i;
	float sum=0;	
	for(i=0;i<nSubjects;i++)
	sum= sum + s.marks[i];
	return sum/nSubjects;
}

char * getTopper(struct student s[], int nStudents, int subjectIndex)
{
	int i,index=0;
	float score=0;
	for(i=0;i<nStudents;i++)
	{
		if(score < s[i].marks[subjectIndex])
		{
			score = s[i].marks[subjectIndex];
			index =i;
		}
	}
	return s[index].name;
}
int main()
{
	int n,k,i,j;
	scanf("%d %d",&n,&k);
	
	struct student records[n];
	
	
	char name[10];
	float marks[k];
	
	for(i=0;i<n;i++)
	{
	   scanf("%s",name);
	   for(j=0;j<k;j++)
	   scanf("%f",&marks[j]);
	   
	   setValues(&(records[i]),name,marks,k);
	
	 } 
	 
	 for(i=0;i<n;i++)
	 printf("%f\n",getAvg(records[i],k));
	 
	 for(i=0;i<k;i++)
	 printf("%s\n",getTopper(records,n,i));
	 
}


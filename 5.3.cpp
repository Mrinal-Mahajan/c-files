#include<iostream>
#include<string.h>
class String
{
	char *s;
	public:

	 String operator+(String str)
	 {
	 	String result;
	 	int len1=0,len2=0,i,j;
//		while(s[len1] != '\0')
//		{
//			len1++;
//		};
        len1 = strlen(s);
        printf("%d\n",len1);
		
//		while(str.s[len2] != '\0')
//		{
//			len2++;
//		};
        len2 = strlen(str.s);
        printf("%d\n",len2);
		result.s = new char[len1+len2];
		for(i=0;i<len1;i++)
		result.s[i]= s[i];
		for(j=0;j<len2;j++)
		result.s[i+j]=str.s[j];
	 	
		 return result;
			  } ;	
	  void replace(char old,char naya)
	  {
	  	   int len=0,i;
//		while(s[len]!='\0')
//		{
//			len++;
//		};
        len = strlen(s);
		printf("%d\n",len);
		for(i=0;i<len;i++)
		if(s[i]==old)
		s[i]=naya;
	  	
		  };
//	 bool find(char c)
//	 {
//	 	int i=0;
//	 	
//	 	while(s[i]='\0')
//	 	{
//	 	  if(c==s[i])
//		   return true;
//		  else
//		    i++;
//		 };
//		 printf()
//		 return false;
//		 };	
	void getcharacterarray()
	{
		int len = strlen(s),i;
		//for(i=0;i<len;i++)
		printf("%s",s);
		printf("\n");
	}
	void initialize(char *str)
	{
		int len=0,i;
//		while(str[len]!='\0')
//		{
//			len++;
//		};
        len = strlen(str);
		s = new char[len];
		for(i=0;i<len;i++)
		s[i] = str[i];
	};
};

int main()
{
	char s1[10],s2[10],old,naya;
	scanf("%s %s %c %c",s1,s2,&old,&naya);
	String str1,str2,result;
	str1.initialize(s1);
	str2.initialize(s2);

	result = str1.operator+(str2);
	result.getcharacterarray();
	
	result.replace(old,naya);
	result.getcharacterarray();
}

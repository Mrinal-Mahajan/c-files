#include "stdio.h"
int a=0;
void blocks(int n)
    { /* If only 1 block, make the move and return */
    if(n==0)
    	{
   		 return;
    	}
      if(n==1)
    	{
   		 a++;    
      	return;
    	}
      /* Move top n-1 blocks from table A to B, using C as auxiliary */
      blocks(n-1);
      /* Move remaining blocks from table A to C */
   	 a++;
      /* Move n-1 blocks from table B to C using A as auxiliary */
      blocks(n-1);
    }
int main()
    { int n;
      scanf("%d",&n);
      blocks(n);
      printf("%d",a);
      return 0;
    }

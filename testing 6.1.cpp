#include <cstdio>
#define MAX 100
using namespace std;

/**
 * Check given tree is value balanced or not
 * @param tree  : int array : Array representation of a complete binary tree
 * @param count : int   	: Number of elements in tree
 * @return boolean : Given tree is value balanced or not
 */
bool isValueBalanced(int tree[], int count);

int main() {
	int count;
	int tree[MAX];
	scanf("%d",&count);
	for (int i = 0; i < count; ++i) {
    	    scanf("%d",&tree[i]);
	}
	if(isValueBalanced(tree, count)) {
    	   printf("Tree is value balanced");
	} else {
    	   printf("Tree is not value balanced");
	}
	return 0;
}
/**
 * Check given sub tree rooted at `root` is value balanced or not
 * @param tree  : int array : Array representation of a complete binary tree
 * @param   	: int root  : location of root;
 * @param sum   : referece to an int: hold sum of elements in sub tree
 * @param count : int   	: Number of elements in tree
 * @return boolean : Given sub-tree is value balanced or not
 */
bool isValueBalanced(int tree[], int root, int &sum, int count) {
	int rightsum = 0;
	int leftsum = 0;
	if (root < count) {
    	//left = (2*root+1)
    	//right = (2*root+2)
    	if (isValueBalanced(tree, (2*root+1), leftsum, count) &&
        	isValueBalanced(tree, (2*root+2), rightsum, count)) {
       	 
        	
        	if ( rightsum == leftsum ) {
            	sum = rightsum + leftsum + tree[root];
            	return true;
        	} else {
            	sum = 0;
            	return false;
        	}
    	} else {
        	sum = 0;
    	}
    	return false;
	}
	return true;
}    

/**
 * Check given tree is value balanced or not
 * @param tree  : int array : Array representation of a complete binary tree
 * @param count : int   	: Number of elements in tree
 * @return boolean : Given tree is value balanced or not
 */
bool isValueBalanced(int tree[], int count) {
	int sum = 0;
	return isValueBalanced(tree, 0, sum, count);
}

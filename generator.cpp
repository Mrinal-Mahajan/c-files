#include<bits/stdc++.h>
using namespace std;
int main(){
	srand(time(NULL));
	ofstream file;
	file.open("test5.txt");
	long int n;
	n= rand()%100000+1;
	file<<n<<endl;
	while(n--){
		long long p;
		p = ((long long)rand())%1000000000000 + 1;
		file<<p<<" ";
	}
	file.close();
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
class city
{
	int clinic,population,load;
	public:
		city(int m)
		{
			clinic = 1;
			load = population =m;
		}
		void increase_clinic()
		{
			clinic++;
			load=population/clinic;
		}
		void increase_load()
		{
			if(population%clinic != 0)
			load++;
		}
		int return_load()
		{
			return load;
		}
};
bool compare(city A, city B)
{
	if(A.return_load() > B.return_load())
	return true;
	
	return false;
};
int main()
{
	vector<city> a;
	int n,b;
	scanf("%d %d",&n,&b);
	int m,i;
	for(i=0;i<n;i++)
	{
		scanf("%d",&m);
		city *temp;
		temp = new city(m);
		a.push_back(*temp);
	}
	sort(a.begin(),a.end(),compare);
	for(i=0;i<b-n;i++)
	{
		city temp = a.front();
		a.erase(a.begin());
		temp.increase_clinic();
		temp.increase_load();
		
		a.push_back(temp);
		sort(a.begin(),a.end(),compare);
   }
	city temp = a.front();
	cout<< temp.return_load();
}

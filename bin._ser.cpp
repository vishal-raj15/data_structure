#include <iostream>
using namespace std;


int bin(int a[],int key,int a1, int z){

	int mid = (z+a1)/2;

	if(a[mid] == key){
		return mid;
	}

	if(key < a[mid]){
		return bin(a, key ,a1,mid-1);
	}
	else{
		return bin(a,key , mid+1 , z);
	}


}
	

int main()
{
	
	int a[]={1,3,4,6,7,8,12,32,35,37,39,42,46,48,49,51,53,58,59};
	// int b = sizeof(a);
	// int c = sizeof(a[0]);
	// int z = b/c;
	// cout<<z;
	int x;


	cin>>x;
	int res = bin(a ,x,1,19);
	cout<<"psoitin of "<<x<<" is "<<res+1<<"\n";
	return 0;
}
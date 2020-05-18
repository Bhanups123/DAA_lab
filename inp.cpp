//	Steps for code execution

//	g++ -c inp.cpp
//	nasm -f elf64 sumdiff.asm
//	g++ -o output sumdiff.o inp.o
//	./output

#include <iostream>
using namespace std;
extern "C" void addDiff(int[], int, int *);

int main()
{
	int arr[4], len = 4, res=0, i=0;
	
	cout << "Enter four numbers(a, b, c, d): "<<endl;
	for (i = 0; i < len; i++)	cin>>arr[i];
	
	addDiff(arr, len, &res);
	
	cout<<"\na : "<<arr[0]<<"\nb : "<<arr[1]<<"\nc : "<<arr[2]<<"\nd : "<<arr[3]<<endl;  
	cout << "\nResult of a + b + c - d is :"<<res<<endl;
	return 0;
}

#include <iostream>
#include <vector>
using namespace std;

void printarr(vector<int>& arr){
	for(int i=0;i<arr.size();i++){
		cout<<arr[i];
        if(i!=arr.size()-1)
            cout<<":";
	}
	cout<<endl;
}

void insertionsort(vector<int>& arr){
	int i,j,n=arr.size(),key;
	for(i=1;i<n;i++){
		key = arr[i];
		j=i-1;
		while(j>-1 && arr[j]>key){
			arr[j+1]=arr[j];
			j=j-1;
		}
		arr[j+1]=key;
	}
}

int main() {
	// your code goes here
	vector<int> arr{5,4,1};
	printarr(arr);
	insertionsort(arr);
	printarr(arr);
	return 0;
}
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<windows.h>
void quick(int* a,int min,int max){
	if(min<max){
		int low=min,high=max,i=min+1,count=0;
		int temp=0;
	int standard=a[min];
	while(i<=max){
		if(a[i]<=standard){
			low=i;
		}
		if(a[i]>standard&&count==0){
			high=i;count=1;
		}
		if(low>high&&low!=min){
			temp=a[low];a[low]=a[high];a[high]=temp;
			low=high;high=low+1;
		}
		i++;
	}
	temp=a[low];a[low]=a[min];a[min]=temp;	
	quick(a,min,low-1);quick(a,low+1,max);
	}
	
}
void merge(int* a,int min,int max){
	if(min<max){
		int mid=(min+max)/2;
		merge(a,min,mid);
		merge(a,mid+1,max);
		int i=min,j=mid+1,k=0;
		int b[max-min+1];
		while(i<=mid&&j<=max){
			if(a[i]<=a[j]){
				b[k]=a[i];
				i++;k++;
			}
			if(a[j]<=a[i]){
				b[k]=a[j];
				j++;k++;
			}
		}
		if(i<=mid){
			while(i<=mid){
				b[k]=a[i];
				i++;k++;
			}
		}
		else if(j<=max){
			while(j<=max){
				b[k]=a[j];
				j++;k++;
			}
		}
		k=0;
		for(i=min;i<=max;i++){
			a[i]=b[k];k++;
		}
	}

	}	
void bubble(int* a,int n){
	int i,j,t,c;
	for(j=0;j<n;j++){
		c=1;
		for(i=0;i<n-1-j;i++){
		if(a[i+1]<a[i]){
			t=a[i];a[i]=a[i+1];a[i+1]=t;c=0;
		}
		}
		if(c==1) break;
	}
}
void insert(int* a,int n){
	int i,t,j;
	for(i=1;i<n;i++){
		for(j=i;j>0;j--){
			if(a[j]<a[j-1]){
			t=a[j]; a[j]=a[j-1];a[j-1]=t;}
		}
	}
}
void select(int*a,int n){
	int i,j,t,s;
	for(i=0;i<n;i++){
		t=a[i];
		for(j=i;j<n;j++){
			if(a[j]<t){
			 t=a[j];s=j;}
		}
		a[s]=a[i];a[i]=t;s=-1;
	}
} 
int main() {
    int n=1000;
    						//选择排序数量级 
    srand(time(0));
    int a[n];
    for (int i = 0; i < n ; i++) {
        a[i]=rand();
    }
	LARGE_INTEGER cpuFreq;
	LARGE_INTEGER startTime;
	LARGE_INTEGER endTime;
	QueryPerformanceFrequency(&cpuFreq);
	QueryPerformanceCounter(&startTime);
	//merge(a,0,n-1);
	//bubble(a,n);
	quick(a,0,n-1);
	//insert(a,n);
	//select(a,n);
							//在此处选择排序算法 
	QueryPerformanceCounter(&endTime);
	double last = ((endTime.QuadPart - startTime.QuadPart) * 1000000.0)/ cpuFreq.QuadPart;
	for(int i=0;i<n;i++){
		printf("%d ",a[i]);
	}
							//查看排序结果 
	printf("\n用时为：%.1lf微秒",last);
    return 0;
}


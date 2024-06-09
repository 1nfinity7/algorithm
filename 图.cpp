#include<iostream>
#include<malloc.h>
using namespace std;
struct link{
	int data;
	int weight;
	link* pnext;
	int color;
};
						//建立链表储存每个节点的相连节点以及边的权重  


link* init_link(int n){
	link *phead=(link *)malloc(sizeof(link));
	phead->data=n;
	phead->weight=-1;
	phead->color=0;
	phead->pnext=NULL;
	return phead;
}
						//初始化链表 
						
									
link* add(link* p,int a,int w){
	link* p1=(link *)malloc(sizeof(link));
	p->pnext=p1;
	p1->data=a;
	p1->weight=w;
	p1->color=0;
	p1->pnext=NULL;
	return p1;
} 


void buildmap(link** a,int n){
	int i,j,p,w;
	for(i=0;i<n;i++){
		a[i]=init_link(i+1);	
	}
	for(i=0;i<n;i++){
		link* p0=a[i];
		cout<<"第"<<i+1<<"个节点信息输入："<<endl;
		for(j=0;j<n;j++){
			scanf("%d%d",&p,&w);
			if(p<0) {
				cout<<"over"<<endl;
				break;
			}
			p0=add(p0,p,w);
		} 
	}
}
						//构建图 
						
						
void visitpoint(link* p){
	int i=1;	
	while(p->pnext!=NULL&&i<=10){
		printf("%d ",p->data);
		p=p->pnext;
		i++;
	}
	printf("%d ",p->data);
	cout<<endl;
	
}


void BFS(link** a,int n,int start){
	link* s[10];int b=0;
	for(int i=0;i<n;i++){
		s[i]=0;
	}
	int i=0,j=0,count=0;
	s[i]=a[start-1];count++;j++;
							//导入起点
	printf("广度遍历顺序为:");
	while(i!=j){
		link* p=s[i];
		printf("%d ",p->data);
		if(j<=n-1){
			p=p->pnext;
			while(p!=NULL){
				if(a[p->data-1]->color==0){
					s[j]=a[p->data-1];
					a[p->data-1]->color=1;
					j++;
				}
				p=p->pnext;	
			}	
		}	
		s[i]->color=1;	
		i++;count++;
	}
}


void DFS(link** a,int n,int start){
	printf("%d ",a[start-1]->data);
	a[start-1]->color=1;
	link* p=a[start-1];
	while(p!=NULL){
		if(a[p->data-1]->color==0){
			DFS(a,n,p->data);
		}
		p=p->pnext;
	}
}


void dijkstra(link** a,int n,int start){
	
	
} 


int main(){
	int n=7;
						//选择节点个数 
	link* a[10];
	buildmap(a,n);
	cout<<"邻接链表为:"<<endl;
	for(int i=0;i<n;i++){
		visitpoint(a[i]);
	}
	BFS(a,n,1);
	//DFS(a,n,1);
							//选择算法 
	return 0;
	
}



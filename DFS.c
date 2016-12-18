/*
this is a c code contain DFS,BFS,topologicalsort,SCC
copyright:Rookie Hou
data:2016/12/7
*/
#include<stdio.h>
#include<stdlib.h>
#define max 100
#define INF 999
int grap[max][max];
int d[max];//discover time
int f[max];//finish time
int color[max];//DFS mark,0 white,1 gray,2 black
int time=0;

DFS_Visit(int u,int vetex_num){
	color[u]=1;//visit the vetex u,mark its color
	time++;
	d[u]=time;
	int i;
	//recursive DFS, visit adjacence unvisited vetex
	//and then visit adjacence unvisited vetex's adjacence unvisited vetex
	//until there are no white vetex
	for(i=0;i<vetex_num;i++){
		if(grap[u][i]!=0&&color[i]==0){ 
			DFS_Visit(i,vetex_num);  
		}
	}
	color[u]=2;//then turn the current vetex into black
	time++;
	f[u]=time;//turn black and finsish, never visit it again
	

}
DFS(int vetex_num){
	int i;
	for(i=0;i<vetex_num;i++){
		color[i]=0;       //init the color,all white
	}
	
	for(i=0;i<vetex_num;i++){
		if(color[i]==0){
			DFS_Visit(i,vetex_num);//DFS visit all the vetex
		} 
	}
}


int main(){
	int edge_num,vetex_num;
	FILE *fin  = fopen ("graph.in", "r");
    FILE *fout = fopen ("graph.out", "w");
    
	char buf[10];
	fgets(buf,10,fin);
	edge_num=atoi(buf);
	
	printf("edge_num:%d\n",edge_num);
	fgets(buf,10,fin);
	vetex_num=atoi(buf);

	
	printf("vetex_num:%d\n",vetex_num);
	int i;
	for(i=0;i<edge_num;i++){
		int start,end,weight;//start point,end point and the weight of edge
		fgets(buf,10,fin);
		sscanf(buf,"%d %d %d",&start,&end,&weight);
		
		printf("start:%d end:%d weight:%d\n",start,end,weight);
		grap[start][end]=grap[end][start]=weight;//init the graph matrix no direct
		
	}

	DFS(vetex_num);        //DFS search

	for(i=0;i<vetex_num;i++){
		printf("d[%d]:%d; f[%d]:%d\n",i,d[i],i,f[i]);
	}
	return 0;
} 

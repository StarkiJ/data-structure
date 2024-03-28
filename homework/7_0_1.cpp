#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
//图的两种存储结构
#define INF 32767 //定义∞
#define MAXV 100  //最大顶点个数
typedef char InfoType;

//以下定义邻接矩阵类型
typedef struct
{
	int no;		   //顶点编号
	InfoType info; //顶点其他信息
} VertexType;	   //顶点类型
typedef struct
{
	int edges[MAXV][MAXV]; //邻接矩阵数组
	int n, e;			   //顶点数，边数
	VertexType vexs[MAXV]; //存放顶点信息
} MatGraph;				   //完整的图邻接矩阵类型

void CreateMat(MatGraph &g, int A[MAXV][MAXV], int n, int e) //创建图的邻接矩阵
{
	int i, j;
	g.n = n;
	g.e = e;
	for (i = 0; i < g.n; i++)
		for (j = 0; j < g.n; j++)
			g.edges[i][j] = A[i][j];
}
void DispMat(MatGraph g) //输出邻接矩阵g
{
	int i, j;
	for (i = 0; i < g.n; i++)
	{
		for (j = 0; j < g.n; j++)
			if (g.edges[i][j] != INF)
				printf("%4d", g.edges[i][j]);
			else
				printf("%4s", "∞");
		printf("\n");
	}
}

void ygq1(int n, int path[][MAXV], int q)
{
	printf("村庄的初始化Path矩阵P%d\n", q);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%4d", path[i][j]);
		}
		printf("\n");
	}
	printf("\n\n");
}

void ygq2(int n, int A[][MAXV], int q)
{
	printf("村庄的距离矩阵A%d\n", q);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (A[i][j] != INF)
				printf("%4d", A[i][j]);
			else
				printf("%4s", "∞");
		}
		printf("\n");
	}
	printf("\n\n");
}
void ygq3(int n, int A[][MAXV])
{
	int gg = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			gg += A[i][j];
			gg += A[j][i];
		}
		printf("医院建在的村庄：%d				各村庄往返总的交通代价为：%d\n", i, gg);
		gg = 0;
	}
}

void Floyd(MatGraph g) // Floyd算法
{
	int q = 0;
	int A[MAXV][MAXV], path[MAXV][MAXV];
	int i, j, k;
	for (i = 0; i < g.n; i++)
		for (j = 0; j < g.n; j++)
		{
			A[i][j] = g.edges[i][j];
			if (i != j && g.edges[i][j] < INF)
				path[i][j] = i; //顶点i到j有边时
			else
				path[i][j] = -1; //顶点i到j没有边时
		}

	ygq1(g.n, path, q - 1);

	for (k = 0; k < g.n; k++) //依次考察所有顶点
	{
		for (i = 0; i < g.n; i++)
			for (j = 0; j < g.n; j++)
				if (A[i][j] > A[i][k] + A[k][j])
				{
					A[i][j] = A[i][k] + A[k][j]; //修改最短路径长度
					path[i][j] = path[k][j];	 //修改最短路径
				}
		ygq2(g.n, A, q);
		q++;
		ygq1(g.n, path, q - 1);
	}

	/*	Dispath(g,A,path);*/
	ygq3(g.n, A); //输出最短路径
}

int main()
{
	MatGraph g;
	int A[MAXV][MAXV] = {
		{0, 13, INF, 4, INF},
		{13, 0, 15, INF, 5},
		{INF, INF, 0, 12, INF},
		{4, INF, 12, 0, INF},
		{INF, INF, 6, 3, 0}};

	int n = 5, e = 10;
	CreateMat(g, A, n, e); //建立图8.1的邻接矩阵
	printf("村庄的的邻接矩阵A-1:\n");
	DispMat(g);
	/*	printf("村庄的初始化Path矩阵P-1:\n");*/
	printf("\n");
	Floyd(g);
	system("pause");
	return 1;
}

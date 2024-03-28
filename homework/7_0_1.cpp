#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
//ͼ�����ִ洢�ṹ
#define INF 32767 //�����
#define MAXV 100  //��󶥵����
typedef char InfoType;

//���¶����ڽӾ�������
typedef struct
{
	int no;		   //������
	InfoType info; //����������Ϣ
} VertexType;	   //��������
typedef struct
{
	int edges[MAXV][MAXV]; //�ڽӾ�������
	int n, e;			   //������������
	VertexType vexs[MAXV]; //��Ŷ�����Ϣ
} MatGraph;				   //������ͼ�ڽӾ�������

void CreateMat(MatGraph &g, int A[MAXV][MAXV], int n, int e) //����ͼ���ڽӾ���
{
	int i, j;
	g.n = n;
	g.e = e;
	for (i = 0; i < g.n; i++)
		for (j = 0; j < g.n; j++)
			g.edges[i][j] = A[i][j];
}
void DispMat(MatGraph g) //����ڽӾ���g
{
	int i, j;
	for (i = 0; i < g.n; i++)
	{
		for (j = 0; j < g.n; j++)
			if (g.edges[i][j] != INF)
				printf("%4d", g.edges[i][j]);
			else
				printf("%4s", "��");
		printf("\n");
	}
}

void ygq1(int n, int path[][MAXV], int q)
{
	printf("��ׯ�ĳ�ʼ��Path����P%d\n", q);
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
	printf("��ׯ�ľ������A%d\n", q);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (A[i][j] != INF)
				printf("%4d", A[i][j]);
			else
				printf("%4s", "��");
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
		printf("ҽԺ���ڵĴ�ׯ��%d				����ׯ�����ܵĽ�ͨ����Ϊ��%d\n", i, gg);
		gg = 0;
	}
}

void Floyd(MatGraph g) // Floyd�㷨
{
	int q = 0;
	int A[MAXV][MAXV], path[MAXV][MAXV];
	int i, j, k;
	for (i = 0; i < g.n; i++)
		for (j = 0; j < g.n; j++)
		{
			A[i][j] = g.edges[i][j];
			if (i != j && g.edges[i][j] < INF)
				path[i][j] = i; //����i��j�б�ʱ
			else
				path[i][j] = -1; //����i��jû�б�ʱ
		}

	ygq1(g.n, path, q - 1);

	for (k = 0; k < g.n; k++) //���ο������ж���
	{
		for (i = 0; i < g.n; i++)
			for (j = 0; j < g.n; j++)
				if (A[i][j] > A[i][k] + A[k][j])
				{
					A[i][j] = A[i][k] + A[k][j]; //�޸����·������
					path[i][j] = path[k][j];	 //�޸����·��
				}
		ygq2(g.n, A, q);
		q++;
		ygq1(g.n, path, q - 1);
	}

	/*	Dispath(g,A,path);*/
	ygq3(g.n, A); //������·��
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
	CreateMat(g, A, n, e); //����ͼ8.1���ڽӾ���
	printf("��ׯ�ĵ��ڽӾ���A-1:\n");
	DispMat(g);
	/*	printf("��ׯ�ĳ�ʼ��Path����P-1:\n");*/
	printf("\n");
	Floyd(g);
	system("pause");
	return 1;
}

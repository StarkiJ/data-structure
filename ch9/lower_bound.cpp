#include <iostream>
#include <vector>
using namespace std;

int* lower_bound1(vector<int> &R,int n,int k)
{
	int low=0,high=n;
   	while (low<high)
   	{
	   	int mid=(low+high)/2;
	   	if (R[mid]>=k)						//p(x)=x>=k,ν��Ϊtrue 
			high=mid;						//���������в��� 
		else								//ν��Ϊfalse
			low=mid+1;						//���������в��� 
	}
	return &R[low];							//����R[low]Ԫ�ص�ַ 
}
int* lower_bound2(vector<int> &R,int n,int k)	//STL�汾 
{
    int low=0,mid;
    int half,len;
    len=n;
    while (len>0)
	{
		half=len/2;
        mid=low+half;
        if (R[mid]>=k)			//p(x)=x>=k��ν��Ϊtrue 
			len=half;			//������(��R[low]��ʼ��len��Ԫ�أ���R[mid])�в���,low���� 
		else					//ν��Ϊfalse
		{     
            low=mid+1;          //�޸�low 
            len=len-half-1;     //��������(��R[low]��ʼ��len��Ԫ��)�в���
        }
    }
	return &R[low];				//����R[low]Ԫ�ص�ַ 
}

int* lower_bound3(vector<int> &R,int n,int k)
{
	int low=0,high=n-1;
	while (low<=high)						//��ǰ����������һ��Ԫ��ʱ
	{	int mid=(low+high)/2;				//�����������м�λ��
		if (R[mid]>=k)						//p(x)=x>=k,ν��Ϊtrue
			high=mid-1;						//��R[low..mid-1]�в���,low���� 
		else								//ν��Ϊfalse
			low=mid+1;						//��R[mid+1..high]�в���
	}
	return &R[low];							//����R[low]����R[high+1]Ԫ�ص�ַ 
}
int main()
{
	vector<int> a={1,3,3,3,5,8};
	int n=a.size();
	int k=5;
	cout << "���ҵ�һ�����ڵ���" << k << "��λ��" << endl; 
	cout << "  �ⷨ1: " << lower_bound1(a,n,k)-&a[0] << endl;
	cout << "  �ⷨ2: " << lower_bound2(a,n,k)-&a[0] << endl;
	cout << "  �ⷨ3: " << lower_bound3(a,n,k)-&a[0] << endl;
    return 0;
}


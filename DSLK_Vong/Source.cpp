#include <iostream>
using namespace std;

struct node
{
	int data;
	node* link;
};
typedef node* NODEPTR;
struct List
{
	NODEPTR first;
	NODEPTR last;
};

void khoiTao(List& list)
{
	list.first = list.last = NULL;
}

NODEPTR taoNode(int x)
{
	NODEPTR p = new node;
	p->link = NULL;
	p->data = x;
	return p;
}

void themDau(List& list, int x)
{
	NODEPTR p = taoNode(x);
	if (list.first == NULL)
	{
		list.first = list.last = p;
	}
	else {
		p->link = list.first;
		list.first = p;
		list.last->link = list.first;
	}
}

void themCuoi(List& list, int x)
{
	NODEPTR p = taoNode(x);
	if (list.first == NULL)
	{
		list.first = list.last = p;
	}
	else
	{
		list.last->link = p;
		list.last = p;
		p->link = list.first;
	}
}

void xoaDau(List& list)
{
	if (list.first != NULL)
	{
		if (list.first != list.last)
		{
			NODEPTR p = list.first;
			list.first = list.first->link;
			list.last->link = list.first;
			delete p;
		}
		else
		{
			list.first = NULL;
		}
	}
}

void xoaCuoi(List& list)
{
	NODEPTR p, before;
	if (list.first != NULL)
	{
		if (list.first != list.last)
		{
			p = list.first;
			before = list.first;
			while (p->link != list.first)
			{
				before = p;
				p = p->link;
			}
			if (p->link == list.first)
			{
				before->link = list.first;
				delete p;
			}
		}
		else
		{
			list.first = NULL;
		}
	}
}


NODEPTR  timNodeX(List& list, int x)
{
	NODEPTR p = list.first;
	while (p != NULL)
	{
		if (p->data == x)
		{
			return p;
		}
		p = p->link;
	}
	return p;
}


void nhap(List& list)
{
	int x;
	do {
		cout << "\n Nhap Gia Tri: (-99 De Thoat )"; cin >> x;
		if (x == -99) break;
		themCuoi(list, x);
	} while (1);
}

void xuat(List list)
{
	if (list.first != NULL)
	{
		cout << "\n Cac Phan Tu Cua Ds Vong ";
		NODEPTR p = list.first;
		do
		{
			cout << " " << p->data;
			p = p->link;
		} while (p != list.first);
	}
}

int main()
{
	List list;
	khoiTao(list);
	nhap(list);
	xuat(list);
	int x;
	cout << "\n Nhap Gia Tri: "; cin >> x;
	NODEPTR kq = new node;
	kq = timNodeX(list, x);
	if (kq == NULL)
	{
		cout << "\n Khong Tim Thay X";
	}
	else {
		cout << "\n Tim Thay X Bang " << kq->data << " Trong Danh Sach ";
	}
	return 0;
}
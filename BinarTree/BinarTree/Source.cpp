#include<iostream>
using namespace std;

#define tab "\t"

class Tree
{
	class Element
	{
		int Data;
		Element* pLeft, * pRight;
	public:
		Element(int Data, Element* pLeft = nullptr, Element* pRight = nullptr) :Data(Data), pLeft(pLeft), pRight(pRight)
		{
			cout << "EConstructor:\t" << this << endl;
		}
		~Element()
		{
			cout << "EDestructor:\t" << this << endl;
		}
		bool is_leaf()
		{
			return pLeft == pRight;
		}
		friend class Tree;
	}*Root;
public:
	Element* getRoot()
	{
		return this->Root;
	}
	Tree() :Root(nullptr)
	{
		cout << "TConstructor:\t" << this << endl;
	}
	Tree(const Tree& other)
	{
		copy(other.Root);
		cout << "CopyConstructor:" << this << endl;
	}
	Tree(const initializer_list<int>& il) :Tree()
	{
		for (int const* it = il.begin(); it != il.end(); it++)
			insert(*it, this->Root);
	}
	~Tree()
	{
		clear(this->Root);
		cout << "TDestructor:\t" << this << endl;
	}
	void insert(int Data)
	{
		insert(Data, this->Root);
	}
	void erase(int Data)
	{
		erase(Data, this->Root);
	}
	int minValue()
	{
		if (this->Root)
			return minValue(this->Root);
		else
			return 0;
	}
	int maxValue()
	{
		return this->Root ? maxValue(this->Root) : 0;
	}
	int size()
	{
		return this->Root ? count(this->Root) : 0;
	}
	int sum()
	{
		return sum(this->Root);
	}
	double avg()
	{
		return (double)sum(this->Root) / count(this->Root);
	}
	void clear()
	{
		clear(this->Root);
		this->Root = nullptr;
	}
	void print()
	{
		print(this->Root);
		cout << endl;
	}
private:
	void insert(int Data, Element* Root)//Root - �������� ������� ��������� (�����)
	{
		if (this->Root == nullptr)this->Root = new Element(Data);
		if (Root == nullptr)return;	//���� ����� � �����-���� �����, � ��� ��������� ������ - ����� �� ������� �� ���.
		if (Data < Root->Data)
		{
			if (Root->pLeft == nullptr)
				Root->pLeft = new Element(Data);
			else
				insert(Data, Root->pLeft);
		}
		else //if (Data > Root->Data)
		{
			if (Root->pRight)insert(Data, Root->pRight);
			else Root->pRight = new Element(Data);
		}
	}
	void erase(int Data, Element*& Root)
	{
		if (Root == nullptr)return;
		erase(Data, Root->pLeft);
		erase(Data, Root->pRight);
		if (Data == Root->Data)
		{
			if (Root->is_leaf())
			{
				delete Root;
				Root = nullptr;
			}
			else
			{
				if (Root->pLeft)
				{
					Root->Data = maxValue(Root->pLeft);
					erase(maxValue(Root->pLeft), Root->pLeft);
				}
				else
				{
					Root->Data = minValue(Root->pRight);
					erase(minValue(Root->pRight), Root->pRight);
				}
			}
		}

	}
	int minValue(Element* Root)
	{
		if (Root->pLeft == nullptr)return Root->Data;
		else return minValue(Root->pLeft);
	}
	int maxValue(Element* Root)
	{
		return Root->pRight ? maxValue(Root->pRight) : Root->Data;
	}
	int count(Element* Root)
	{
		if (Root == nullptr)return 0;
		return Root->is_leaf() ? 1 : count(Root->pLeft) + count(Root->pRight) + 1;
	}
	int sum(Element* Root)
	{
		return Root ? sum(Root->pLeft) + sum(Root->pRight) + Root->Data : 0;
	}
	void copy(Element* Root)
	{
		if (Root == nullptr)return;
		insert(Root->Data, this->Root);
		copy(Root->pLeft);
		copy(Root->pRight);
	}
	void clear(Element* Root)
	{
		if (Root == nullptr)return;
		clear(Root->pLeft);
		clear(Root->pRight);
		delete Root;
	}
	void print(Element* Root)
	{
		if (Root == nullptr)return;
		print(Root->pLeft);
		cout << Root->Data << tab;
		print(Root->pRight);
	}
};


void main()
{
	setlocale(LC_ALL, "Russian");
	int n;
	Tree t = { 50, 25, 16, 32, 8, 85, 64, 62, 80, 91, 98 };
	t.print();
	cout << "����������� �������� � ������: " << t.minValue() << endl;
	cout << "����������� �������� � ������: " << t.maxValue() << endl;
	cout << "��������� ��������� ������: " << t.size() << endl;
	cout << "����� ��������� ������: " << t.sum() << endl;
	cout << "������� �������������� ��������� ������: " << t.avg() << endl;
	int value;	cout << "������� ��������� ��������: "; cin >> value;
	t.erase(value);
	t.print();
	cout << "����������� �������� � ������: " << t.minValue() << endl;
	cout << "����������� �������� � ������: " << t.maxValue() << endl;
	cout << "��������� ��������� ������: " << t.size() << endl;
	cout << "����� ��������� ������: " << t.sum() << endl;
	cout << "������� �������������� ��������� ������: " << t.avg() << endl;


}
#include<iostream>

using namespace std;

class Element
{
	int Data;
	Element* pNext;
	Element* pPrev;

public:
	
	friend class List;
};

class List
{
	Element* Head;
	Element* Tail;
public:
	List()
	{
		Head = Tail = nullptr;	
		cout << "LConstructor:\t" << this << endl;
	}
	~List()
	{
		cout << "LDestructor:\t" << this << endl;
	}

	/////////////////Methods://///////////
	void push_front(int Data)//Добавление в начало списка
	{
		Element* Temp = new Element;
		Temp->Data = Data;
		if (!Head)
		{
			Temp->pNext = Tail;
			Tail = Temp;
		}
		else
		{
			Temp->pNext = Head;
			Head->pPrev = nullptr;
		}
	}
	void push_back(int Data)//Добавление с конца
	{
		Element* Temp = new Element;
		Temp->Data = Data;
		if (!Head)
		{
			Temp->pNext = Tail;
			Head = Temp;
			Temp->pPrev = nullptr;
		}
		else
		{
			Temp->pNext = Tail->pNext;
			Temp->pPrev = Tail;
			Tail->pNext = Temp;
		}
		Tail = Temp;
	}

	void print()
	{
		Element* Temp = Head;
		while (Temp != nullptr)
		{
			cout << Temp << "\t" << Temp->Data << "\t" << Temp->pNext << endl;
			Temp = Temp->pNext;	//Переход на следующий элемент
		}

	}

};

void main()
{
	setlocale(LC_ALL, "ru");
	int n;
	cout << "Введите размер двусвязного списка -\t";cin >> n;
	cout << endl;
	List list;
	for (int i = 0; i < n; i++)
	{
		list.push_back(rand() % 100);
	}
	list.print();
	

}
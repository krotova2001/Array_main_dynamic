//�����-��������� ����������� ������

#pragma once
#include "Arr_el.h"
#include <iostream>
using namespace std;
template<typename T>

class Array
{
	int lenth; // ����� ������
	Arr_el<T>* start; // ������ ������
public:
	Array(): lenth{0}, start{nullptr}{} // ����������� �� ��������� - ������ ������
	int GetSize() { return lenth; } // ������ �����
	bool IsEmpty() { return !start; } // �������� �� �������
	
	Array& Add(const T& D) // ���������� ��������
	{
		Arr_el<T>* d = new Arr_el<T>; // 
		d->data = D;
		
		if (start) //���� ��� ������ �� ������
		{
			d->p = start; // ����������� ������� � ����������� ��������
			start->n = d; // ���������� ������� ����������� � ������
			start = d; // ��������� ����� ������� �������
		}
		else // ���� ������
		{
			start = d; // ������ ��������� ����� ������� �������
		}
		lenth++;
		return *this;
	}
	
	Array& Add() // ������������� ������ ���������� ������� ��������
	{
		Arr_el<T>* d = new Arr_el<T>;
		if (start) //���� ��� ������ �� ������
		{
			d->p = start; // ����������� ������� � ����������� ��������
			start->n = d; // ���������� ������� ����������� � ������
			start = d; // ��������� ����� ������� �������
		}
		else // ���� ������
		{
			start = d; // ������ ��������� ����� ������� �������
		}
		lenth++;
		return *this;
	}
	
	Array& Pop() // �������� �������� ��������
	{
		start = start->p; // ����������� ��������� �� �������������
		delete start->n; // ������ ������ ��� ���������;
		lenth--;
		return *this;
	}


	Array& SetSize(int size, int grow=1) // �������� ����� ������� � ����������
	{
		if (lenth>size) // ���� ������� ����� ������ ������ �������
		{
			for (int i = 0; i < lenth-size; i++)
			{
				Pop();
			}
		}
		if (size == lenth)	return *this; // ��� ����� �� �������� ������
		if (lenth < size) //���� ������� ����� ������ ������ �������
		{
			for (int i = lenth; i <= size+grow; i++) // ���� �  ��������� ����� ������� ������, �� ��� ���� �������� ��� ���...
			{
				Add();
			}
		}
	}
	
	T GetAt(int index) // ������ � �������� �� �������
	{
		if (index <= lenth) 
		{
			Arr_el<T>* temp = start;
			for (int i = 0; i < index; i++)
			{
				temp = temp->p;
			}
			return temp->data;
		}
	}

	void RemoveAt(int index) // �������� �������� �� �������
	{
		if (start)
		{
			Arr_el<T>* temp = start;
			for (int i = 0; i < index; i++)
			{
				temp = temp->p;
			}
			if (index<lenth) // ���� ������� � ��������
			{
				temp->p->n = temp->n;
				temp->n->p = temp->p;
			}
			if (index==lenth) // ���� ��� ��������� �������
			{
				temp->p->n = nullptr;
			}
			if (index==0) // ���� ��� ������ �������
			{
				Pop();
			}
			delete temp;
		}
	}

	/*
	void FreeExtra()
	{
		if (start) // ���� �� ������ �� ����
		{
			Arr_el<T>* tmp = start;
			while (!(tmp->data)) // ���� � ���������� ��� ������, �� �������
			{
				delete start;

			}
		}
	}
	*/
	void RemooveAll() // ������� ���� ������
	{
		if (start) // ���� �� �����
		{
			while (start->p) // ���� �� ��������� ���� ������
			{
				start = start->p; // �� ������ ������� � ������������ ������ �� ���������
				delete start->n;
				lenth--;
			} 
			delete start; // ������� ����� ���������
			start = nullptr;
		}
	}

	void Show() // ������� ������
	{
		if (start) // ���� �� �����
		{
			Arr_el<T>* tmp = start; // ��������� �������
			cout << "-------\n";
			do
			{
				cout << tmp->data << "\n";
				tmp = tmp->p; // ������� ��������� ������� �� ����������
			} 
			while (tmp!=nullptr);
		}
		else // ���� �����
		{
			cout << "Empty";
		}
	}
	
	~Array()
	{
		RemooveAll();
	}
};


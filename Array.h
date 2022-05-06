//класс-контейнер двусв€зного списка

#pragma once
#include "Arr_el.h"
#include <iostream>
using namespace std;
template<typename T>

class Array
{
	int lenth; // длина списка
	Arr_el<T>* start; // начало списка
public:
	Array(): lenth{0}, start{nullptr}{} // конструктор по умолчанию - пустой список
	int GetSize() { return lenth; } // узнать длину
	bool IsEmpty() { return !start; } // проверка на пустоту
	
	Array& Add(const T& D) // добавление элемента
	{
		Arr_el<T>* d = new Arr_el<T>; // 
		d->data = D;
		
		if (start) //если наш список не пустой
		{
			d->p = start; // приписываем элемент к предыдущему элементу
			start->n = d; // предыдущий элемент приписываем к новому
			start = d; // объ€вл€ем новый элемент началом
		}
		else // если пустой
		{
			start = d; // просто объ€вл€ем новый элемент началом
		}
		lenth++;
		return *this;
	}
	
	Array& Add() // перегруженна€ верси€ добавлени€ пустого элемента
	{
		Arr_el<T>* d = new Arr_el<T>;
		if (start) //если наш список не пустой
		{
			d->p = start; // приписываем элемент к предыдущему элементу
			start->n = d; // предыдущий элемент приписываем к новому
			start = d; // объ€вл€ем новый элемент началом
		}
		else // если пустой
		{
			start = d; // просто объ€вл€ем новый элемент началом
		}
		lenth++;
		return *this;
	}
	
	Array& Pop() // удаление крайнего элемента
	{
		start = start->p; // передвигаем последний на предпоследний
		delete start->n; // удалем теперь тот последний;
		lenth--;
		return *this;
	}


	Array& SetSize(int size, int grow=1) // устновка новго размера и приращение
	{
		if (lenth>size) // если текуща€ длина больше нового размера
		{
			for (int i = 0; i < lenth-size; i++)
			{
				Pop();
			}
		}
		if (size == lenth)	return *this; // тут можно не измен€ть ничего
		if (lenth < size) //если текуща€ длина меньше нового размера
		{
			for (int i = lenth; i <= size+grow; i++) // если €  правильно пон€л условие задачт, то это надо записать вот так...
			{
				Add();
			}
		}
	}
	
	T GetAt(int index) // доступ к элементу по индексу
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

	void RemoveAt(int index) // удаление элемента по индексу
	{
		if (start)
		{
			Arr_el<T>* temp = start;
			for (int i = 0; i < index; i++)
			{
				temp = temp->p;
			}
			if (index<lenth) // если элемент в середине
			{
				temp->p->n = temp->n;
				temp->n->p = temp->p;
			}
			if (index==lenth) // если это последний элемент
			{
				temp->p->n = nullptr;
			}
			if (index==0) // если это первый элемент
			{
				Pop();
			}
			delete temp;
		}
	}

	/*
	void FreeExtra()
	{
		if (start) // если на массив не пуст
		{
			Arr_el<T>* tmp = start;
			while (!(tmp->data)) // если в предыдущем нет данных, то удал€ем
			{
				delete start;

			}
		}
	}
	*/
	void RemooveAll() // удалить весь массив
	{
		if (start) // если не пусто
		{
			while (start->p) // пока не сотанетс€ один элмент
			{
				start = start->p; // то удалем элемент и препоследний ставим на последний
				delete start->n;
				lenth--;
			} 
			delete start; // удал€ем самый последний
			start = nullptr;
		}
	}

	void Show() // показть массив
	{
		if (start) // если не пусто
		{
			Arr_el<T>* tmp = start; // временный элемент
			cout << "-------\n";
			do
			{
				cout << tmp->data << "\n";
				tmp = tmp->p; // двигаем временный элемент на предыдущий
			} 
			while (tmp!=nullptr);
		}
		else // если пусто
		{
			cout << "Empty";
		}
	}
	
	~Array()
	{
		RemooveAll();
	}
};


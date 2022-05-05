//элемент двусвязного списка
#pragma once
template<typename T> // шаблон для типа данных
struct Arr_el
{
	T data=NULL; // данные. По умолчанию NULL чтобы отобразить пустой элемент, не заполненный
	Arr_el* p = nullptr; // предыдущий элемент
	Arr_el* n = nullptr; // следующий элемент
};


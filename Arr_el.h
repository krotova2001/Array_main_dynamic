//������� ����������� ������
#pragma once
template<typename T> // ������ ��� ���� ������
struct Arr_el
{
	T data=NULL; // ������. �� ��������� NULL ����� ���������� ������ �������, �� �����������
	Arr_el* p = nullptr; // ���������� �������
	Arr_el* n = nullptr; // ��������� �������
};


#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <windows.h>

using namespace std;

struct Patient
{
	int policy_num;
	string surname;
	string name;
	string patronymic;
	string birthday;
	int phone;
	string date_vac;
};

struct Table
{
	int n;
	vector <Patient> table;
};

void inputPatient(Patient& per)
{
	cout << "������� ����� ������ ��������: ";
	cin >> per.policy_num;
	cout << "������� ������� ��������: ";
	cin >> per.surname;
	cout << "������� ��� ��������: ";
	cin >> per.name;
	cout << "������� �������� ��������: ";
	cin >> per.patronymic;
	cout << "������� ���� �������� ��������: ";
	cin >> per.birthday;
	cout << "������� ����� �������� ��������: ";
	cin >> per.phone;
	cout << "������� ���� �������� ��������, ���� �������� �� ���� �������, �� ������� '-': ";
	cin >> per.date_vac;
}

void createTable(Table& tab, Patient& per)
{
	cout << "������� ���������� ���������: ";
	cin >> tab.n;
	for (int i = 0; i < tab.n; i++)
	{
		inputPatient(per);
		tab.table.push_back(per);
		if (i > 0)
		{
			for (int j = 0; j < i; j++)
			{
				if (tab.table[i].policy_num < tab.table[j].policy_num) swap(tab.table[i], tab.table[j]);
			}
		}
	}
}

void outputTable(Table tab)
{
	cout << "   ����� ������" << "        �������" << "            ���" << "       ��������" << "       ���� ��������" << "      ����� ��������" << "       ���� ��������" << endl;
	for (int i = 0; i < tab.n; i++)
	{
		cout << setw(15) << right << tab.table[i].policy_num;
		cout << setw(15) << right << tab.table[i].surname;
		cout << setw(15) << right << tab.table[i].name;
		cout << setw(15) << right << tab.table[i].patronymic;
		cout << setw(20) << right << tab.table[i].birthday;
		cout << setw(20) << right << tab.table[i].phone;
		cout << setw(20) << right << tab.table[i].date_vac << endl;
	}
}

void addPatient(Table& tab, Patient& per)
{
	cout << "�� ������ �������� ������ ��������? ���� �� - ������� 1, ����� ������� 0: ";
	int ans;
	cin >> ans;
	while (ans != 1 && ans != 0)
	{
		cout << "�� ������ �������� ������ ��������? ���� �� - ������� 1, ����� ������� 0: ";
		cin >> ans;
	}
	if (ans == 0) return;
	while (ans != 0)
	{
		tab.n += 1;
		inputPatient(per);
		tab.table.push_back(per);
		for (int i = 0; i < tab.n; i++)
		{
			for (int j = 0; j < tab.n - 1; j++)
			{
				if (tab.table[tab.n - 1].policy_num < tab.table[j].policy_num) swap(tab.table[tab.n - 1], tab.table[j]);
			}
		}
		cout << "�� ������ �������� ������ ��������? ���� �� - ������� 1, ����� ������� 0: ";
		cin >> ans;
	}
}

void delPatient(Table& tab)
{
	cout << "�� ������ ������� ������ ��������? ���� �� - ������� 1, ����� ������� 0: ";
	int ans;
	cin >> ans;
	while (ans != 1 && ans != 0)
	{
		cout << "�� ������ ������� ������ ��������? ���� �� - ������� 1, ����� ������� 0: ";
		cin >> ans;
	}
	if (ans == 0) return;
	while (ans != 0)
	{
		cout << "������� ����� ������ ���� ��������, �������� �� ������ ������� �� �������: ";
		int num;
		cin >> num;
		for (int i = 0; i < tab.n; i++)
		{
			if (tab.table[i].policy_num == num)
			{
				int k = i;
				for (int j = i + 1; j < tab.n; j++)
				{
					swap(tab.table[k], tab.table[j]);
					k += 1;
				}
			}
		}
		tab.n -= 1;
		tab.table.pop_back();
		cout << "�� ������ ������� ������ ��������? ���� �� - ������� 1, ����� ������� 0: ";
		cin >> ans;
	}
}

void noVac(Table tab)
{
	int k = 0;
	for (int i = 0; i < tab.n; i++)
	{
		if (tab.table[i].date_vac == "-")
		{
			k += 1;
		}
	}
	if (k == 0)
	{
		cout << "��������� ��� �������� ���";
		return;
	}
	cout << "������ ���������, �� ������� ��������:" << endl;
	cout << "   ����� ������" << "        �������" << "            ���" << "       ��������" << "       ���� ��������" << "      ����� ��������" << endl;
	for (int i = 0; i < tab.n; i++)
	{
		if (tab.table[i].date_vac == "-")
		{
			cout << setw(15) << right << tab.table[i].policy_num;
			cout << setw(15) << right << tab.table[i].surname;
			cout << setw(15) << right << tab.table[i].name;
			cout << setw(15) << right << tab.table[i].patronymic;
			cout << setw(20) << right << tab.table[i].birthday;
			cout << setw(20) << right << tab.table[i].phone << endl;
		}
	}
}

int main()
{
	setlocale(LC_ALL, "Rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Patient per;
	Table tab;
	createTable(tab, per);
	outputTable(tab);
	addPatient(tab, per);
	outputTable(tab);
	delPatient(tab);
	outputTable(tab);
	noVac(tab);
	return 0;
}
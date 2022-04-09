#include <iostream>
#include <string>
#include <iomanip>
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
	static const int N = 100;
	Patient table[N];
};

void inputPatient(Patient& per)
{
	cout << "Введите номер полиса пациента: ";
	cin >> per.policy_num;
	cout << "Введите фамилию пациента: ";
	cin >> per.surname;
	cout << "Введите имя пациента: ";
	cin >> per.name;
	cout << "Введите отчество пациента: ";
	cin >> per.patronymic;
	cout << "Введите дату рождения пациента: ";
	cin >> per.birthday;
	cout << "Введите номер телефона пациента: ";
	cin >> per.phone;
	cout << "Введите дату прививки пациента, если прививка не была сделана, то введите '-': ";
	cin >> per.date_vac;
}

void createTable(Table& tab, Patient& per)
{
	cout << "Введите количество пациентов: ";
	cin >> tab.n;
	for (int i = 0; i < tab.n; i++)
	{
		inputPatient(per);
		tab.table[i] = per;
		if (i>0)
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
	cout << "   Номер полиса" << "        Фамилия" << "            Имя" << "       Отчество" << "       Дата рождения" << "      Номер телефона" << "       Дата прививки" << endl;
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
	cout << "Вы хотите добавить данные пациента? Если да - введите 1, иначе введите 0: ";
	int ans;
	cin >> ans;
	while (ans != 1 && ans != 0)
	{
		cout << "Вы хотите добавить данные пациента? Если да - введите 1, иначе введите 0: ";
		cin >> ans;
	}
	if (ans == 0) return;
	while (ans != 0)
	{
		tab.n += 1;
		inputPatient(per);
		tab.table[tab.n - 1] = per;
		for (int i = 0; i < tab.n; i++)
		{
			for (int j = 0; j < tab.n - 1; j++)
			{
				if (tab.table[tab.n - 1].policy_num < tab.table[j].policy_num) swap(tab.table[tab.n - 1], tab.table[j]);
			}
		}
		cout << "Вы хотите добавить данные пациента? Если да - введите 1, иначе введите 0: ";
		cin >> ans;
	}
}

void delPatient(Table& tab)
{
	cout << "Вы хотите удалить данные пациента? Если да - введите 1, иначе введите 0: ";
	int ans;
	cin >> ans;
	while (ans != 1 && ans != 0)
	{
		cout << "Вы хотите удалить данные пациента? Если да - введите 1, иначе введите 0: ";
		cin >> ans;
	}
	if (ans == 0) return;
	while (ans != 0)
	{
		cout << "Введите номер полиса того пациента, которого вы хотите удалить из таблицы: ";
		int num;
		cin >> num;
		for (int i = 0; i < tab.n; i++)
		{
			if (tab.table[i].policy_num == num)
			{
				int k = i;
				for (int j = i+1; j < tab.n; j++)
				{
					swap(tab.table[k], tab.table[j]);
					k += 1;
				}
			}
		}
		tab.n -= 1;
		cout << "Вы хотите удалить данные пациента? Если да - введите 1, иначе введите 0: ";
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
		cout << "Пациентов без прививки нет";
		return;
	}
	cout << "Список пациентов, не имеющих прививки:" << endl;
	cout << "   Номер полиса" << "        Фамилия" << "            Имя" << "       Отчество" << "       Дата рождения" << "      Номер телефона" << endl;
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
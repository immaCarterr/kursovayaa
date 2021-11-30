#pragma once
#include "Libraries.h"
#include "User.h"
#include "Subclasses.h"
#include "Flat.h"
#include "Buyer.h"
#include "OneRoom.h"
#include "TwoRoom.h"
#include "ThreeRoom.h"
#include "MultyRoom.h"

using namespace std;

bool operator==(Fio obj1, Fio obj2) {
	if (obj1.name == obj2.name && obj1.surname == obj2.surname && obj1.patronymic == obj2.patronymic) return true;
	else return false;
}

bool operator==(Adress obj1, Adress obj2) {
	return (obj1.city == obj2.city && obj1.street == obj2.street && obj1.houseNum == obj2.houseNum && obj1.flatNum == obj2.flatNum);
}

fstream& operator>>(fstream& fs, Fio& obj) {
	fs >> obj.name >> obj.surname >> obj.patronymic;
	return fs;
}

fstream& operator<<(fstream& fs, Fio& obj) {
	fs << obj.GetName() << " " << obj.GetSurname() << " " << obj.GetPatronymic();
	return fs;
}

fstream& operator>>(fstream& fs, User& obj) {
	fs >> obj.login >> obj.password;
	return fs;
}

fstream& operator<<(fstream& fs, User& obj) {
	fs << endl << obj.login << " " << obj.password;
	return fs;
}

fstream& operator>>(fstream& fs, Adress& obj) {
	fs >> obj.city >> obj.street >> obj.houseNum >> obj.flatNum;
	return fs;
}

fstream& operator<<(fstream& fs, Adress& obj) {
	fs << obj.GetCity() << " " << obj.GetStreet() << " " << obj.GetHouseNum() << " " << obj.GetFlatNum();
	return fs;
}

fstream& operator>>(fstream& fs, Flat& obj) {
	fs >> obj.buildYear >> obj.floor >> obj.price;
	fs >> obj.adress >> obj.balconyNum >> obj.area >> obj.ceilingHigh;
	return fs;
}

fstream& operator<<(fstream& fs, Flat& obj) {
	fs << endl << obj.buildYear << " " << obj.floor << " " << obj.price << " ";
	fs << obj.adress << " " << obj.balconyNum << " " << obj.area << " " << obj.ceilingHigh;
	return fs;
}

fstream& operator>>(fstream& fs, Buyer& obj) {
	fs >> obj.fio >> obj.age;
	fs >> obj.adress;
	return fs;
}

fstream& operator<<(fstream& fs, Buyer& obj) {
	fs << endl;
	fs << obj.fio << " " << obj.age;
	return fs;
}

int Password(string& info) {
	int flag = 0;
	info = "";
	int ch = 0; 
	while (true)
	{
		ch = _getch();
		if (ch == 13)
		{
			break;
		}
		if (ch == 27)
		{
			flag = 1;
			break;
		}
		if (ch == 8 && !info.empty())
		{
			cout << (char)8 << ' ' << char(8);
			if (!info.empty()) info.erase(info.length() - 1);
		}

		if (ch != 8) {
			cout << "*";
			info += (char)ch;
		}
	}
	cout << endl;
	return flag;
}

int INTS(int& num) {
	string info;
	int flag = 0;
	info = "";
	int ch = 0; 
	while (true) 
	{
		while (true) {
			ch = _getch();
			if ((ch >= 48 && ch <= 57) || ch == 8 || ch == 13) break;
		}
		if (ch == 13)
		{
			break;
		}
		if (ch == 27)
		{
			flag = 1;
			break;
		}
		if (ch == 8 && !info.empty())
		{
			cout << (char)8 << ' ' << char(8);
			if (!info.empty()) info.erase(info.length() - 1);
		}

		if (ch != 8) {
			cout << (char)ch;
			info += (char)ch;
		}
	}
	stringstream A; A << info; A >> num;
	cout << endl;
	return flag;
}

int INTS(float& num) {
	string info;
	int flag = 0;
	info = "";
	int ch = 0; 
	while (true)
	{
		while (true) {
			ch = _getch();
			if ((ch >= 48 && ch <= 57) || ch == 8 || ch == 13 || ch == 46) break;
		}
		if (ch == 13) 
		{
			break; 
		}
		if (ch == 27) 
		{
			flag = 1;
			break;
		}
		if (ch == 8 && !info.empty())
		{
			cout << (char)8 << ' ' << char(8);
			if (!info.empty()) info.erase(info.length() - 1);
		}

		if (ch != 8) {
			cout << (char)ch;
			info += (char)ch;
		}
	}
	stringstream A; A << info; A >> num;
	cout << endl;
	return flag;
}

void Encryption(string& str) {
	for (int i = 0; i < str.length(); i++)
	{
		str[i] = str[i] + 10;
	}
}

void Decryption(string& str) {
	for (int i = 0; i < str.length(); i++)
	{
		str[i] = str[i] - 10;
	}
}

int Menu() {
	int choice;
	cout << "\n\n\n\n\n";
	cout << "\t\t\t\t\t|=====================================|\n"
		"\t\t\t\t\t|                                     |\n"
		"\t\t\t\t\t|  1. Регистрация                     |\n"
		"\t\t\t\t\t|                                     |\n"
		"\t\t\t\t\t|=====================================|\n"
		"\t\t\t\t\t|                                     |\n"
		"\t\t\t\t\t|  2. Вход в систему                  |\n"
		"\t\t\t\t\t|                                     |\n"
		"\t\t\t\t\t|=====================================|\n"
		"\t\t\t\t\t|                                     |\n"
		"\t\t\t\t\t|  3. Выход                           |\n"
		"\t\t\t\t\t|                                     |\n"
		"\t\t\t\t\t|=====================================|\n\n";
	cout << "\t\t\t\t\t         Ваш выбор: "; INTS(choice);
	return choice;
}

int EnterMenu() {
	int choice;
	cout << "\n\n\n\n\n\t\t\t\t\t|====================================|\n"
		"\t\t\t\t\t|                                    |\n"
		"\t\t\t\t\t|  1. Вход в режиме администратора   |\n"
		"\t\t\t\t\t|                                    |\n"
		"\t\t\t\t\t|====================================|\n"
		"\t\t\t\t\t|                                    |\n"
		"\t\t\t\t\t|  2. Вход в режиме пользователя     |\n"
		"\t\t\t\t\t|                                    |\n"
		"\t\t\t\t\t|====================================|\n"
		"\t\t\t\t\t|                                    |\n"
		"\t\t\t\t\t|  3. Назад                          |\n"
		"\t\t\t\t\t|                                    |\n"
		"\t\t\t\t\t|====================================|\n\n";
	cout << "\t\t\t\t\t        Ваш выбор: "; INTS(choice);
	return choice;
}

int AdminMenu() {
	int choice;
	cout << "\t\t\t\t\t|=======================================|\n"
		"\t\t\t\t\t|                                       |\n"
		"\t\t\t\t\t|  1. Добавить информацию               |\n"
		"\t\t\t\t\t|                                       |\n"
		"\t\t\t\t\t|=======================================|\n"
		"\t\t\t\t\t|                                       |\n"
		"\t\t\t\t\t|  2. Отредактировать информацию        |\n"
		"\t\t\t\t\t|                                       |\n"
		"\t\t\t\t\t|=======================================|\n"
		"\t\t\t\t\t|                                       |\n"
		"\t\t\t\t\t|  3. Удалить информацию                |\n"
		"\t\t\t\t\t|                                       |\n"
		"\t\t\t\t\t|=======================================|\n"
		"\t\t\t\t\t|                                       |\n"
		"\t\t\t\t\t|  4. Просмотреть информацию            |\n"
		"\t\t\t\t\t|                                       |\n"
		"\t\t\t\t\t|=======================================|\n"
		"\t\t\t\t\t|                                       |\n"
		"\t\t\t\t\t|  5. Поиск информации                  |\n"
		"\t\t\t\t\t|                                       |\n"
		"\t\t\t\t\t|=======================================|\n"
		"\t\t\t\t\t|                                       |\n"
		"\t\t\t\t\t|  6. Управление пользователями         |\n"
		"\t\t\t\t\t|                                       |\n"
		"\t\t\t\t\t|=======================================|\n"
		"\t\t\t\t\t|                                       |\n"
		"\t\t\t\t\t|  7. Назад                             |\n"
		"\t\t\t\t\t|                                       |\n"
		"\t\t\t\t\t|=======================================|\n"
		"\t\t\t\t\t               Ваш выбор: "; INTS(choice);
	return choice;

}

int UserMenu() {
	int choice;
	cout << "\n\n\n\n\n\t\t\t\t\t|============================================|\n"
		"\t\t\t\t\t|                                            |\n"
		"\t\t\t\t\t|  1. Просмотреть информацию                 |\n"
		"\t\t\t\t\t|                                            |\n"
		"\t\t\t\t\t|============================================|\n"
		"\t\t\t\t\t|                                            |\n"
		"\t\t\t\t\t|  2. Поиск информации                       |\n"
		"\t\t\t\t\t|                                            |\n"
		"\t\t\t\t\t|============================================|\n"
		"\t\t\t\t\t|                                            |\n"
		"\t\t\t\t\t|  3. Выбор квартиры из списка предложенных  |\n"
		"\t\t\t\t\t|                                            |\n"
		"\t\t\t\t\t|============================================|\n"
		"\t\t\t\t\t|                                            |\n"
		"\t\t\t\t\t|  4. Назад                                  |\n"
		"\t\t\t\t\t|                                            |\n"
		"\t\t\t\t\t|============================================|\n"
		"\t\t\t\t\t               Ваш выбор: "; INTS(choice);
	return choice;
}

int AddMenu() {
	int choice;
	cout << "\n\n\n";
	cout << "\t\t\t\t|========================================================|\n"
		"\t\t\t\t|                                                        |\n"
		"\t\t\t\t|   1. Добавление информации об однокомнатной квартире   |\n"
		"\t\t\t\t|                                                        |\n"
		"\t\t\t\t|========================================================|\n"
		"\t\t\t\t|                                                        |\n"
		"\t\t\t\t|   2. Добавление информации о двухкомнатной квартире    |\n"
		"\t\t\t\t|                                                        |\n"
		"\t\t\t\t|========================================================|\n"
		"\t\t\t\t|                                                        |\n"
		"\t\t\t\t|   3. Добавление информации о трёхкомнатной квартире    |\n"
		"\t\t\t\t|                                                        |\n"
		"\t\t\t\t|========================================================|\n"
		"\t\t\t\t|                                                        |\n"
		"\t\t\t\t|   4. Добавление информации о многокомнатной квартире   |\n"
		"\t\t\t\t|                                                        |\n"
		"\t\t\t\t|========================================================|\n"
		"\t\t\t\t|                                                        |\n"
		"\t\t\t\t|   5. Назад                                             |\n"
		"\t\t\t\t|                                                        |\n"
		"\t\t\t\t|========================================================|\n\n"
		"\t\t\t\t                      Ваш выбор: "; INTS(choice);
	return choice;
}

int RedMenu() {
	int choice;
	cout << "\n\n\n";
	cout << "\t\t\t\t|============================================================|\n"
		"\t\t\t\t|   1. Редактирование информации об однокомнатной квартире   |\n"
		"\t\t\t\t|============================================================|\n"
		"\t\t\t\t|   2. Редактирование информации о двухкомнатной квартире    |\n"
		"\t\t\t\t|============================================================|\n"
		"\t\t\t\t|   3. Редактирование информации о трёхкомнатной квартире    |\n"
		"\t\t\t\t|============================================================|\n"
		"\t\t\t\t|   4. Редактирование информации о многокомнатной квартире   |\n"
		"\t\t\t\t|============================================================|\n"
		"\t\t\t\t|   5. Редактирование информации об однокомнатной квартире   |\n"
		"\t\t\t\t|                     из списка купленных                    |\n"
		"\t\t\t\t|============================================================|\n"
		"\t\t\t\t|   6. Редактирование информации о двухкомнатной квартире    |\n"
		"\t\t\t\t|                     из списка купленных                    |\n"
		"\t\t\t\t|============================================================|\n"
		"\t\t\t\t|   7. Редактирование информации о трёхкомнатной квартире    |\n"
		"\t\t\t\t|                     из списка купленных                    |\n"
		"\t\t\t\t|============================================================|\n"
		"\t\t\t\t|   8. Редактирование информации о многокомнатной квартире   |\n"
		"\t\t\t\t|                     из списка купленных                    |\n"
		"\t\t\t\t|============================================================|\n"
		"\t\t\t\t|                      9. Назад                              |\n"
		"\t\t\t\t|============================================================|\n\n"
		"\t\t\t\t                     Ваш выбор: "; INTS(choice);
	return choice;
}

int DelMenu() {
	int choice;
	cout << "\n\n";
	cout << "\t\t\t\t|======================================================|\n"
		"\t\t\t\t|   1. Удаление информации об однокомнатной квартире   |\n"
		"\t\t\t\t|======================================================|\n"
		"\t\t\t\t|   2. Удаление информации о двухкомнатной квартире    |\n"
		"\t\t\t\t|======================================================|\n"
		"\t\t\t\t|   3. Удаление информации о трёхкомнатной квартире    |\n"
		"\t\t\t\t|======================================================|\n"
		"\t\t\t\t|   4. Удаление информации о многокомнатной квартире   |\n"
		"\t\t\t\t|======================================================|\n"
		"\t\t\t\t|   5. Удаление информации об однокомнатной квартире   |\n"
		"\t\t\t\t|                     из списка купленных              |\n"
		"\t\t\t\t|======================================================|\n"
		"\t\t\t\t|   6. Удаление информации о двухкомнатной квартире    |\n"
		"\t\t\t\t|                     из списка купленных              |\n"
		"\t\t\t\t|======================================================|\n"
		"\t\t\t\t|   7. Удаление информации о трёхкомнатной квартире    |\n"
		"\t\t\t\t|                     из списка купленных              |\n"
		"\t\t\t\t|======================================================|\n"
		"\t\t\t\t|   8. Удаление информации о многокомнатной квартире   |\n"
		"\t\t\t\t|                     из списка купленных              |\n"
		"\t\t\t\t|======================================================|\n"
		"\t\t\t\t|   9. Удаление информации о покупателях квартир       |\n"
		"\t\t\t\t|======================================================|\n"
		"\t\t\t\t|                      10. Назад                       |\n"
		"\t\t\t\t|======================================================|\n\n"
		"\t\t\t\t                     Ваш выбор: "; INTS(choice);
	return choice;
}

int ShowMenu() {
	int choice;
	cout << "\n\n";
	cout << "\t\t\t\t|=======================================================|\n"
		"\t\t\t\t|                                                       |\n"
		"\t\t\t\t|  1. Просмотр информации об однокомнатных квартирах    |\n"
		"\t\t\t\t|                                                       |\n"
		"\t\t\t\t|=======================================================|\n"
		"\t\t\t\t|                                                       |\n"
		"\t\t\t\t|  2. Просмотр информации о двухкомнатных квартирах     |\n"
		"\t\t\t\t|                                                       |\n"
		"\t\t\t\t|=======================================================|\n"
		"\t\t\t\t|                                                       |\n"
		"\t\t\t\t|  3. Просмотр информации о трёхкомнатных квартирах     |\n"
		"\t\t\t\t|                                                       |\n"
		"\t\t\t\t|=======================================================|\n"
		"\t\t\t\t|                                                       |\n"
		"\t\t\t\t|  4. Просмотр информации о многокомнатных квартирах    |\n"
		"\t\t\t\t|                                                       |\n"
		"\t\t\t\t|=======================================================|\n"
		"\t\t\t\t|                                                       |\n"
		"\t\t\t\t|  5. Просмотр информации о купленных квартирах         |\n"
		"\t\t\t\t|           в отсортированном по цене виде              |\n"
		"\t\t\t\t|                                                       |\n"
		"\t\t\t\t|=======================================================|\n"
		"\t\t\t\t|                                                       |\n"
		"\t\t\t\t|  6. Просмотр информации о покупателях квартир         |\n"
		"\t\t\t\t|                                                       |\n"
		"\t\t\t\t|=======================================================|\n"
		"\t\t\t\t|                                                       |\n"
		"\t\t\t\t|  7. Назад                                             |\n"
		"\t\t\t\t|                                                       |\n"
		"\t\t\t\t|=======================================================|\n"
		"\t\t\t\t                     Ваш выбор: "; INTS(choice);
	return choice;
}

int FindMenu() {
	int choice;
	cout << "\n";
	cout << "\t\t\t\t|====================================================|\n"
		"\t\t\t\t|                                                    |\n"
		"\t\t\t\t|  1. Поиск информации об однокомнатных квартирах    |\n"
		"\t\t\t\t|                                                    |\n"
		"\t\t\t\t|====================================================|\n"
		"\t\t\t\t|                                                    |\n"
		"\t\t\t\t|  2. Поиск информации о двухкомнатных квартирах     |\n"
		"\t\t\t\t|                                                    |\n"
		"\t\t\t\t|====================================================|\n"
		"\t\t\t\t|                                                    |\n"
		"\t\t\t\t|  3. Поиск информации о трёхкомнатных квартирах     |\n"
		"\t\t\t\t|                                                    |\n"
		"\t\t\t\t|====================================================|\n"
		"\t\t\t\t|                                                    |\n"
		"\t\t\t\t|  4. Поиск информации о многокомнатных квартирах    |\n"
		"\t\t\t\t|                                                    |\n"
		"\t\t\t\t|====================================================|\n"
		"\t\t\t\t|                                                    |\n"
		"\t\t\t\t|  5. Поиск информации о купленных квартирах         |\n"
		"\t\t\t\t|                                                    |\n"
		"\t\t\t\t|====================================================|\n"
		"\t\t\t\t|                                                    |\n"
		"\t\t\t\t|  6. Поиск информации с фильтрацией по цене         |\n"
		"\t\t\t\t|                                                    |\n"
		"\t\t\t\t|====================================================|\n"
		"\t\t\t\t|                                                    |\n"
		"\t\t\t\t|  7. Назад                                          |\n"
		"\t\t\t\t|                                                    |\n"
		"\t\t\t\t|====================================================|\n"
		"\t\t\t\t                     Ваш выбор: "; INTS(choice);
	return choice;
}

int CheckExistLog(string log, string pass) {
	int flag = 1;
	fstream fs;
	fs.open("Users.txt");
	if (fs.is_open()) {
		deque <User> U;
		while (!fs.eof())
		{
			User user;
			fs >> user;
			U.push_back(user);
		}
		fs.close();
		for (int i = 0; i < U.size(); i++)
		{
			Decryption(U[i].password);
			(U[i].login == log) ? flag = 0 : flag;
			(U[i].login == log && U[i].password == pass) ? flag = 2 : flag;
		}
	}
	else {
		flag = -1;
	}
	return flag;
}

void reg() {
	User user;
	bool flag = true;
	while (flag) {
		system("cls");
		cout << "Введите логин: "; cin >> user.login;
		int ch = CheckExistLog(user.login, "");
		if (ch == 1 || ch == -1) {
			cout << "\nВведите пароль: "; Password(user.password);
			cout << "\nПовторите пароль: "; Password(user.confpass);
			if (user.password == user.confpass) {
				Encryption(user.password);
				cout << "\nРегистрация прошла успешно" << endl;
				system("pause");
				fstream fs;
				fs.open("Users.txt", fstream::in | fstream::app);
				fs << user;
				fs.close();
				flag = false;
			}
			else {
				cout << "Пароль или логин не совпадают!" << endl;
				system("pause");
			}
		}
		else {
			cout << "Пользователь с таким логином уже зарегистрирован!" << endl;
			system("pause");
		}
	}
}

int authorization() {
	int res;
	User user;
	bool flag = true;
	while (flag) {
		system("cls");
		int ch = CheckExistLog("", "");
		if (ch == -1) {
			cout << "Необходима регистрация!" << endl;
			res = -1;
			system("pause");
			break;
		}
		cout << "Введите логин: "; cin >> user.login;
		cout << "\nВведите пароль: "; Password(user.password);
		ch = CheckExistLog(user.login, user.password);
		if (ch == 2) {
			res = 1;
			cout << "Вход выполнен успешно!" << endl;
			system("pause");
			flag = false;
		}
		else {
			cout << "\nНеверный логин или пароль!\n";
			system("pause");
			continue;
		}
	}
	return res;
}

int Check(string path) {
	int res = 0;
	fstream fs;
	fs.open(path);
	if (fs.is_open()) res = 1;
	return res;
}

void AddData(Flat* obj, string path, int flag) {
	if (flag == 0) obj->SetInformation();
	fstream fs;
	fs.open(path, fstream::in | fstream::out | fstream::app);
	if (fs.is_open()) {
		fs << *obj;
		obj->PrintUnique(fs);
		fs.close();
	}
	else {
		cout << "Не удалось записать информацию" << endl;
	}
}

template <class Type>
void RedactData(Type type, string path) {
	cout << endl;
	if (Check(path) == 0) {
		cout << "Информация о квартирах не найдена!" << endl;
		system("pause");
		return;
	}
	Adress adress;
	cout << "Введите адрес квартиры, информацию о которой необходимо изменить: " << endl;
	adress.SetInformation();
	fstream fs;
	fs.open(path, fstream::in | fstream::out);
	if (fs.is_open()) {
		int flag = 0;
		deque <Type> D;
		while (!fs.eof()) {
			Type object;
			fs >> object;
			object.SetUnique(fs);
			D.push_back(object);
		}
		fs.close();
		for (int i = 0; i < D.size(); i++)
		{
			if (D[i].GetAdress() == adress) {
				flag = 1;
				cout << "Введите новую информацию:" << endl << endl;
				D[i].SetInformation();
			}
		}
		if (flag == 0) {
			cout << endl << "Квартира с таким адресом не найдена, проверьте введённые данные" << endl;
			system("pause");
			return;
		}
		char Fname[20];
		for (int i = 0; i < path.size(); i++)
		{
			Fname[i] = path[i];
		}
		Fname[path.size()] = '\0';
		remove(Fname);
		fs.open(path, fstream::out | fstream::in | fstream::app);
		if (fs.is_open()) {
			for (int i = 0; i < D.size(); i++)
			{
				fs << D[i];
				D[i].PrintUnique(fs);
			}
			fs.close();
		}
	}
	else {
		cout << "Не удалось отредактировать информацию" << endl;
	}
}

template <class Type>
void DeleteData(Type type, string path) {
	if (Check(path) == 0) {
		cout << "Информация о квартирах не найдена!" << endl;
		system("pause");
		return;
	}
	Adress adress;
	cout << "Введите адрес квартиры, информацию о которой необходимо удалить: " << endl;
	adress.SetInformation();
	fstream fs;
	fs.open(path, fstream::in | fstream::out);
	if (fs.is_open()) {
		int flag = 0;
		deque <Type> D;
		while (!fs.eof()) {
			Type object;
			fs >> object;
			object.SetUnique(fs);
			D.push_back(object);
		}
		fs.close();
		for (int i = 0; i < D.size(); i++)
		{
			if (D[i].GetAdress() == adress) flag = 1;
		}
		if (flag == 0) {
			cout << endl << "Квартира с таким адресом не найдена, проверьте введённые данные" << endl;
			system("pause");
			return;
		}
		char Fname[20];
		for (int i = 0; i < path.size(); i++)
		{
			Fname[i] = path[i];
		}
		Fname[path.size()] = '\0';
		remove(Fname);
		if (D.size() == 1) return;
		fs.open(path, fstream::out | fstream::in | fstream::app);
		if (fs.is_open()) {
			for (int i = 0; i < D.size(); i++)
			{
				if (!(D[i].GetAdress() == adress)) fs << D[i];
			}
			fs.close();
		}
	}
	else {
		cout << "Не удалось удалить информацию" << endl;
	}
}

template <class Type>
void DeleteData(Type type, Adress adress, string path) {
	fstream fs;
	fs.open(path, fstream::in | fstream::out);
	if (fs.is_open()) {
		int flag = 0;
		deque <Type> D;
		while (!fs.eof()) {
			Type object;
			fs >> object;
			object.SetUnique(fs);
			D.push_back(object);
		}
		fs.close();
		char Fname[20];
		for (int i = 0; i < path.size(); i++)
		{
			Fname[i] = path[i];
		}
		Fname[path.size()] = '\0';
		remove(Fname);
		if (D.size() == 1) return;
		fs.open(path, fstream::out | fstream::in | fstream::app);
		if (fs.is_open()) {
			for (int i = 0; i < D.size(); i++)
			{
				if (!(D[i].GetAdress() == adress)) fs << D[i];
			}
			fs.close();
		}
	}
	else {
		cout << "Не удалось удалить информацию" << endl;
	}
}

void DeleteBuyer(Buyer buyer, string path) {
	if (Check(path) == 0) {
		cout << "Информация о покупателях не найдена!" << endl;
		system("pause");
		return;
	}
	Fio fio;
	cout << "Введите ФИО покупателя, информацию о котором необходимо удалить: " << endl;
	fio.Set();
	fstream fs;
	fs.open(path, fstream::in | fstream::out);
	if (fs.is_open()) {
		int flag = 0;
		deque <Buyer> D;
		while (!fs.eof()) {
			Buyer object;
			fs >> object;
			D.push_back(object);
		}
		fs.close();
		for (int i = 0; i < D.size(); i++)
		{
			if (D[i].GetFio() == fio) flag = 1;
		}
		if (flag == 0) {
			cout << endl << "Покупатель с такими данными не найден, проверьте введённые данные" << endl;
			system("pause");
			return;
		}
		char Fname[20];
		for (int i = 0; i < path.size(); i++)
		{
			Fname[i] = path[i];
		}
		Fname[path.size()] = '\0';
		remove(Fname);
		if (D.size() == 1) return;
		fs.open(path, fstream::out | fstream::in | fstream::app);
		if (fs.is_open()) {
			for (int i = 0; i < D.size(); i++)
			{
				if (!(D[i].GetFio() == fio)) fs << D[i];
			}
			fs.close();
		}
	}
	else {
		cout << "Не удалось удалить информацию" << endl;
	}
}

void PrintHead() {
	cout << "|" << setw(117) << setfill('=') << "|" << endl;
	cout << "|" << setw(16) << setfill(' ') << "|" << setw(7) << setfill(' ') << "|" << setw(12) << setfill(' ') << "|" << setw(30) << setfill(' ') << "|" << setw(10) << setfill(' ') << "|" << setw(10) << setfill(' ') << "|" << setw(16) << setfill(' ') << "|" << setw(16) << setfill(' ') << "|" << endl;

	cout << resetiosflags(ios::adjustfield);
	cout.setf(ios::left);
	cout << "|" << setw(15) << setfill(' ') << " Год постройки" << "|" << setw(6) << setfill(' ') << " Этаж" << "|" << setw(11) << setfill(' ') << " Цена(в $)" << "|" << setw(29) << setfill(' ') << " Адрес" << "|" << setw(9) << setfill(' ') << " Балконы" << "|" << setw(9) << setfill(' ') << " Площадь" << "|" << setw(15) << setfill(' ') << " Выс. потолков" << "|" << setw(15) << setfill(' ') << " Кол-во комнат" << "|" << endl;

	cout.setf(ios::right);
	cout << "|" << setw(16) << setfill(' ') << "|" << setw(7) << setfill(' ') << "|" << setw(12) << setfill(' ') << "|" << setw(30) << setfill(' ') << "|" << setw(10) << setfill(' ') << "|" << setw(10) << setfill(' ') << "|" << setw(16) << setfill(' ') << "|" << setw(16) << setfill(' ') << "|" << endl;
	cout << "|" << setw(117) << setfill('=') << "|" << endl;
}

void PrintObject(Flat* obj) {
	cout << "|" << setw(16) << setfill(' ') << "|" << setw(7) << setfill(' ') << "|" << setw(12) << setfill(' ') << "|" << setw(30) << setfill(' ') << "|" << setw(10) << setfill(' ') << "|" << setw(10) << setfill(' ') << "|" << setw(16) << setfill(' ') << "|" << setw(16) << setfill(' ') << "|" << endl;
	
	cout << resetiosflags(ios::adjustfield);
	cout.setf(ios::left);
	string adr = obj->GetAdress().GetCity() + " " + obj->GetAdress().GetStreet() + " " + obj->GetAdress().GetHouseNum() + " " + obj->GetAdress().GetFlatNum();

	cout << "| " << setw(14) << setfill(' ') << obj->GetBuildYear() << "| " << setw(5) << setfill(' ') << obj->GetFloor() << "| " << setw(10) << setfill(' ') << obj->GetPrice() << "| " << setw(28) << setfill(' ') << adr << "| " << setw(8) << setfill(' ') << obj->GetBalconyNum() << "| " << setw(8) << setfill(' ') << obj->GetArea() << "| " << setw(14) << setfill(' ') << obj->GetCeilingHigh() << "| " << setw(14) << setfill(' ') << obj->GetUnique() << "|" << endl;

	cout << resetiosflags(ios::adjustfield);
	cout.setf(ios::right);
	cout << "|" << setw(16) << setfill(' ') << "|" << setw(7) << setfill(' ') << "|" << setw(12) << setfill(' ') << "|" << setw(30) << setfill(' ') << "|" << setw(10) << setfill(' ') << "|" << setw(10) << setfill(' ') << "|" << setw(16) << setfill(' ') << "|" << setw(16) << setfill(' ') << "|" << endl;
	cout << "|" << setw(117) << setfill('=') << "|" << endl;
}

template <class Type>
void ShowData(Type type, string path, int flag) {
	if (Check(path) == 0) {
		cout << "Информация отсутствует!" << endl;
		if (flag == 0) system("pause");
		return;
	}
	fstream fs;
	fs.open(path, fstream::in | fstream::out);
	if (fs.is_open()) {
		deque <Type> D;
		while (!fs.eof()) {
			Type object;
			fs >> object;
			object.SetUnique(fs);
			D.push_back(object);
		}
		fs.close();

		if (flag == 1) {
			for (int i = 1; i < D.size(); i++)
			{
				int d = exp2(i) - 1;
				if (d <= D.size()) {

					for (int k = 0; k < D.size() - d; k++)
					{
						int j = k;
						while (j >= 0 && D[j].GetPrice() > D[j + d].GetPrice())
						{
							Type object = D[j];
							D[j] = D[j + d];
							D[j + d] = object;
							j--;
						}
					}
				}
			}
		}

		PrintHead();

		for (int i = 0; i < D.size(); i++)
		{
			PrintObject(&D[i]);
		}
		if (flag == 0) system("pause");
	}
	else {
		cout << "Не удалось просмотреть информацию" << endl;
	}
}

template <class Type>
void FindData(Type type, string path) {
	if (Check(path) == 0) {
		cout << "Информация о квартирах отсутствует!" << endl;
		system("pause");
		return;
	}
	Adress adress;
	cout << "Введите адрес квартиры, информацию о которой необходимо найти: " << endl;
	adress.SetInformation();
	fstream fs;
	fs.open(path, fstream::in | fstream::out);
	if (fs.is_open()) {
		int flag = 0;
		deque <Type> D;
		while (!fs.eof()) {
			Type object;
			fs >> object;
			object.SetUnique(fs);
			D.push_back(object);
		}
		fs.close();
		for (int i = 0; i < D.size(); i++)
		{
			if (D[i].GetAdress() == adress) flag = 1;
		}
		if (flag == 0) {
			cout << endl << "Квартира с таким адресом не найдена, проверьте введённые данные" << endl;
			system("pause");
			return;
		}
		cout << endl;
		for (int i = 0; i < D.size(); i++)
		{
			if (D[i].GetAdress() == adress) {
				PrintHead();
				PrintObject(&D[i]);
			}
		}
		system("pause");
	}
	else {
		cout << "Не удалось найти информацию" << endl;
	}
}

void FindBought() {
	
	if (Check("BoughtOneRoom.txt") == 0 && Check("BoughtTwoRoom.txt") == 0 && Check("BoughtThreeRoom.txt") == 0 && Check("BoughtMultyRoom.txt") == 0) {
		cout << "Информация о купленных квартирах отсутствует!" << endl;
		system("pause");
		return;
	}
	Adress adress;
	cout << "Введите адрес квартиры, информацию о которой необходимо найти: " << endl;
	adress.SetInformation();

	int flag = 0;
	while (true) {
		fstream fs;

		fs.open("BoughtOneRoom.txt");
		if (fs.is_open()) {
			deque <OneRoom> A;
			while (!fs.eof()) {
				OneRoom object;
				fs >> object;
				object.SetUnique(fs);
				A.push_back(object);
			}
			fs.close();
			for (int i = 0; i < A.size(); i++)
			{
				if (A[i].GetAdress() == adress) {
					flag = 1;
					PrintHead();
					PrintObject(&A[i]);
					system("pause");
					break;
				}
			}
			if (flag == 1) break;
		}

		fs.open("BoughtTwoRoom.txt");
		if (fs.is_open()) {
			deque <TwoRoom> B;
			while (!fs.eof()) {
				TwoRoom object;
				fs >> object;
				object.SetUnique(fs);
				B.push_back(object);
			}
			fs.close();
			for (int i = 0; i < B.size(); i++)
			{
				if (B[i].GetAdress() == adress) {
					flag = 1;
					PrintHead();
					PrintObject(&B[i]);
					system("pause");
					break;
				}
			}
			if (flag == 1) break;
		}

		fs.open("BoughtThreeRoom.txt");
		if (fs.is_open()) {
			deque <ThreeRoom> C;
			while (!fs.eof()) {
				ThreeRoom object;
				fs >> object;
				object.SetUnique(fs);
				C.push_back(object);
			}
			fs.close();
			for (int i = 0; i < C.size(); i++)
			{
				if (C[i].GetAdress() == adress) {
					flag = 1;
					PrintHead();
					PrintObject(&C[i]);
					system("pause");
					break;
				}
			}
			if (flag == 1) break;
		}

		fs.open("BoughtMultyRoom.txt");
		if (fs.is_open()) {
			deque <MultyRoom> D;
			while (!fs.eof()) {
				MultyRoom object;
				fs >> object;
				object.SetUnique(fs);
				D.push_back(object);
			}
			fs.close();
			for (int i = 0; i < D.size(); i++)
			{
				if (D[i].GetAdress() == adress) {
					flag = 1;
					PrintHead();
					PrintObject(&D[i]);
					system("pause");
					break;
				}
			}
			if (flag == 1) break;
		}
		break;
	}

	if (flag == 0) {
		cout << endl << "Квартира с таким адресом не найдена, проверьте введённые данные" << endl;
		system("pause");
		return;
	}
	cout << endl;
}

template <class Type>
void FilterPrice(Type type, string path) {
	int flag = 0;
	if (Check(path) == 0) {
		cout << "Информация отсутствует!" << endl;
		return;
	}
	fstream fs;
	fs.open(path, fstream::in | fstream::out);
	if (fs.is_open()) {
		deque <Type> D;
		while (!fs.eof()) {
			Type object;
			fs >> object;
			object.SetUnique(fs);
			D.push_back(object);
		}
		fs.close();
		int minP, maxP;
		while (true) {
			cout << "Введите нижний диапазон цен: "; cin >> minP;
			cout << "Введите верхний диапазон цен: "; cin >> maxP;
			if (maxP <= minP) {
				cout << "Максимальный цена не может быть меньше, либо равна минимальной" << endl;
				system("pause");
			}
			else break;
		}
		for (int i = 0; i < D.size(); i++)
		{
			if (D[i].GetPrice() >= minP && D[i].GetPrice() <= maxP) flag = 1;
		}
		if (flag == 1) {
			PrintHead();

			for (int i = 0; i < D.size(); i++)
			{
				if (D[i].GetPrice() >= minP && D[i].GetPrice() <= maxP) {
					PrintObject(&D[i]);
				}
			}
		}
		else {
			cout << "\nНи одной квартиры с ценой в таком диапазоне не найдено\n";
		}
	}
}

void DelUsers() {
	fstream fs;
	fs.open("Users.txt", fstream::in | fstream::out);
	if (fs.is_open()) {
		deque <User> D;
		while (!fs.eof()) {
			User user;
			fs >> user;
			D.push_back(user);
		}
		fs.close();

		cout << "|" << setw(42) << setfill('=') << "|" << endl;
		cout << "|" << setw(5) << setfill(' ') << "|" << setw(18) << setfill(' ') << "|" << setw(19) << setfill(' ') << "|" << endl;

		cout << resetiosflags(ios::adjustfield);
		cout.setf(ios::left);
		cout << "|" << setw(4) << setfill(' ') << " №" << "|" << setw(17) << setfill(' ') << " Логин" << "|" << setw(18) << setfill(' ') << " Пароль" << "|" << endl;

		cout.setf(ios::right);
		cout << "|" << setw(5) << setfill(' ') << "|" << setw(18) << setfill(' ') << "|" << setw(19) << setfill(' ') << "|" << endl;
		cout << "|" << setw(42) << setfill('=') << "|" << endl;

		for (int i = 0; i < D.size(); i++)
		{
			cout << "|" << setw(5) << setfill(' ') << "|" << setw(18) << setfill(' ') << "|" << setw(19) << setfill(' ') << "|" << endl;

			cout << resetiosflags(ios::adjustfield);
			cout.setf(ios::left);
			Decryption(D[i].password);

			cout << "| " << setw(3) << setfill(' ') << i+1 << "| " << setw(16) << setfill(' ') << D[i].login << "| " << setw(17) << setfill(' ') << D[i].password << "|" << endl;

			cout.setf(ios::right);
			cout << "|" << setw(5) << setfill(' ') << "|" << setw(18) << setfill(' ') << "|" << setw(19) << setfill(' ') << "|" << endl;
			cout << "|" << setw(42) << setfill('=') << "|" << endl;
		}
		system("pause");

		string log;
		while (true) {
			cout << "\nВведите логин пользователя, которого вы хотите удалить: "; cin >> log;
			if (D.size() == 1) {
				cout << "Невозможно удалить информацию, когда существует только один пользователь" << endl;
				system("pause");
				return;
			}
			if (CheckExistLog(log, "") != 0) {
				cout << "Пользователя с таким логином не существует, повторите ввод";
			}
			else break;
		}

		remove("Users.txt");
		fs.open("Users.txt", fstream::out | fstream::in | fstream::app);
		if (fs.is_open()) {
			for (int i = 0; i < D.size(); i++)
			{
				if (D[i].login != log) {
					Encryption(D[i].password);
					fs << D[i];
				}
			}
			fs.close();
		}
	}
	else {
		cout << "Не удалось просмотреть информацию" << endl;
	}
}

void AddBuyer(Buyer* obj) {
	fstream fs;
	fs.open("Buyers.txt", fstream::in | fstream::out | fstream::app);
	if (fs.is_open()) {
		fs << endl;
		fs << obj->fio << " " << obj->age << " ";
		fs << obj->adress;
		fs.close();
	}
	else {
		cout << "Не удалось записать информацию о покупателях!";
		system("pause");
	}
}

void BuyFlat() {

	if (Check("OneRoom.txt") == 0 && Check("TwoRoom.txt") == 0 && Check("ThreeRoom.txt") == 0 && Check("MultyRoom.txt") == 0) {
		cout << "Информация о квартирах отсутствует!" << endl;
		system("pause");
		return;
	}
	Buyer buyer;
	Adress adress;
	cout << "Введите информацию о покупателе:\n"; buyer.SetInformation();
	cout << "\nВведите адрес квартиры, которую вы хотите приобрести: " << endl;
	adress.SetInformation();
	buyer.adress = adress;

	int flag = 0;
	while (true) {
		fstream fs;

		fs.open("OneRoom.txt");
		if (fs.is_open()) {
			deque <OneRoom> A;
			while (!fs.eof()) {
				OneRoom object;
				fs >> object;
				object.SetUnique(fs);
				A.push_back(object);
			}
			fs.close();
			for (int i = 0; i < A.size(); i++)
			{
				if (A[i].GetAdress() == adress) {
					flag = 1;
					DeleteData(A[i], adress, "OneRoom.txt");
					AddData(&A[i], "BoughtOneRoom.txt", 1);
					AddBuyer(&buyer);
					break;
				}
			}
			if (flag == 1) break;
		}

		fs.open("TwoRoom.txt");
		if (fs.is_open()) {
			deque <TwoRoom> B;
			while (!fs.eof()) {
				TwoRoom object;
				fs >> object;
				object.SetUnique(fs);
				B.push_back(object);
			}
			fs.close();
			for (int i = 0; i < B.size(); i++)
			{
				if (B[i].GetAdress() == adress) {
					flag = 1;
					DeleteData(B[i], adress, "TwoRoom.txt");
					AddData(&B[i], "BoughtTwoRoom.txt", 1);
					AddBuyer(&buyer);
					break;
				}
			}
			if (flag == 1) break;
		}

		fs.open("ThreeRoom.txt");
		if (fs.is_open()) {
			deque <ThreeRoom> C;
			while (!fs.eof()) {
				ThreeRoom object;
				fs >> object;
				object.SetUnique(fs);
				C.push_back(object);
			}
			fs.close();
			for (int i = 0; i < C.size(); i++)
			{
				if (C[i].GetAdress() == adress) {
					flag = 1;
					DeleteData(C[i], adress, "ThreeRoom.txt");
					AddData(&C[i], "BoughtThreeRoom.txt", 1);
					AddBuyer(&buyer);
					break;
				}
			}
			if (flag == 1) break;
		}

		fs.open("MultyRoom.txt");
		if (fs.is_open()) {
			deque <MultyRoom> D;
			while (!fs.eof()) {
				MultyRoom object;
				fs >> object;
				object.SetUnique(fs);
				D.push_back(object);
			}
			fs.close();
			for (int i = 0; i < D.size(); i++)
			{
				if (D[i].GetAdress() == adress) {
					flag = 1;
					DeleteData(D[i], adress, "MultyRoom.txt");
					AddData(&D[i], "BoughtMultyRoom.txt", 1);
					AddBuyer(&buyer);
					break;
				}
			}
			if (flag == 1) break;
		}
		break;
	}

	if (flag == 0) {
		cout << endl << "Квартира с таким адресом не найдена, проверьте введённые данные" << endl;
		system("pause");
		return;
	}
	cout << endl;
}

void ShowBuyers() {
	if (Check("Buyers.txt") == 0) {
		cout << "Информация отсутствует!" << endl;
		system("pause");
		return;
	}
	fstream fs;
	fs.open("Buyers.txt", fstream::in | fstream::out);
	if (fs.is_open()) {
		deque <Buyer> D;
		while (!fs.eof()) {
			Buyer object;
			fs >> object;
			D.push_back(object);
		}
		fs.close();

		cout << "|" << setw(75) << setfill('=') << "|" << endl;
		cout << "|" << setw(31) << setfill(' ') << "|" << setw(11) << setfill(' ') << "|" << setw(33) << setfill(' ') << "|" << endl;

		cout << resetiosflags(ios::adjustfield);
		cout.setf(ios::left);
		cout << "|" << setw(30) << setfill(' ') << " ФИО" << "|" << setw(10) << setfill(' ') << " Возраст" << "|" << setw(32) << setfill(' ') << " Адрес" << "|" << endl;

		cout.setf(ios::right);
		cout << "|" << setw(31) << setfill(' ') << "|" << setw(11) << setfill(' ') << "|" << setw(33) << setfill(' ') << "|" << endl;
		cout << "|" << setw(75) << setfill('=') << "|" << endl;


		for (int i = 0; i < D.size(); i++)
		{
			cout << "|" << setw(31) << setfill(' ') << "|" << setw(11) << setfill(' ') << "|" << setw(33) << setfill(' ') << "|" << endl;

			cout << resetiosflags(ios::adjustfield);
			cout.setf(ios::left);
			string adr = D[i].GetAdress().GetCity() + " " + D[i].GetAdress().GetStreet() + " " + D[i].GetAdress().GetHouseNum() + " " + D[i].GetAdress().GetFlatNum();
			string fio = D[i].GetFio().GetName() + " " + D[i].GetFio().GetSurname() + " " + D[i].GetFio().GetPatronymic();

			cout << "| " << setw(29) << setfill(' ') << fio << "| " << setw(9) << setfill(' ') << D[i].GetAge() << "| " << setw(31) << setfill(' ') << adr << "|" << endl;

			cout << resetiosflags(ios::adjustfield);
			cout.setf(ios::right);
			cout << "|" << setw(31) << setfill(' ') << "|" << setw(11) << setfill(' ') << "|" << setw(33) << setfill(' ') << "|" << endl;
			cout << "|" << setw(75) << setfill('=') << "|" << endl;
		}
		system("pause");
	}
	else {
		cout << "Не удалось просмотреть информацию" << endl;
	}
}
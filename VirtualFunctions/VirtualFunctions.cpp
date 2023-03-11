/*Создайте иерархию классов по работе с файлами.
Базовый класс должен открывать файл и отображать его содержимое
в консоль.
Первый класс потомка должен открывать файл и отображать его
содержимое в виде ASCII-кодов символов, расположенных в файле.

Второй производный класс должен открывать файл и отображать его
содержимое в шестнадцатеричном виде.
Для отображения содержимого файла в базовом классе необходимо
определить виртуальную функцию.
• void Display(const char * path);
• path — путь к файлу.
Потомки должны создать свою реализацию виртуальной функции.*/


#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Базовый класс должен открывать файл и отображать его содержимое
//в консоль.
class OpenFileToConsole
{
protected:
	string path;
public:
	void setPath(string p)
	{
		path = p;
	}
	virtual void Display(const char* path)
	{
		ifstream file;
		file.open(path, ios::out);
		if (!file.is_open())
			cout << "File was not opened!";
		else
		{
			string buffer;
			while (getline(file, buffer));
			//выводим считанное
			cout << buffer << "\n";
		}
		file.close();
	}
};

//Первый класс потомка должен открывать файл и отображать его
//содержимое в виде ASCII - кодов символов, расположенных в файле.
class OpenFileToASKII : public OpenFileToConsole
{
	void Display(const char* path) override
	{
		ifstream file;
		string buffer;
		file.open(path, ios::out);
		if (!file.is_open())
			cout << "File was not opened!";
			else
			{
				while (getline(file, buffer));
				//выводим считанное
				cout << buffer << "\n";
			}
		file.close();

		for (int i = 0; i < buffer.length(); i++)
		{
			char x = buffer.at(i);
			cout << int(x) << " ";
		}
	}

};



class OpenFileToРexadecimal : public OpenFileToConsole
{
	void Display(const char* path) override
	{
		ifstream file;
		string buffer;
		file.open(path, ios::out);
		if (!file.is_open())
			cout << "File was not opened!";
		else
		{
			while (getline(file, buffer));
			//выводим считанное
			cout << buffer << "\n";
		}
		file.close();

		for (int i = 0; i < buffer.length(); i++)
		{
			char x = buffer.at(i);

			//преобразуем в Hexadecimal код
			char bufHex = GetHex(x);

			//выводим считанное
			cout << bufHex << ' ';
			i++;
		}

	}

	// Отображение шестнадцатеричной цифры
	char digit(int num)
	{
		switch (num) {
		case 0: return '0';
		case 1: return '1';
		case 2: return '2';
		case 3: return '3';
		case 4: return '4';
		case 5: return '5';
		case 6: return '6';
		case 7: return '7';
		case 8: return '8';
		case 9: return '9';
		case 10: return 'A';
		case 11: return 'B';
		case 12: return 'C';
		case 13: return 'D';
		case 14: return 'E';
		case 15: return 'F';
		}
	}
	// Получение целой части числа
	int dectox_int(int a, int p, char *s)
	{
		int num = (int)a;
		int rest = num % p;
		num /= p;
		if (num == 0)
		{
			s[0] = digit(rest);
			return 1;
		}
		int k = dectox_int(num, p, s);
		s [k++] = digit(rest);
		return k;
	}

	char GetHex(int a)
	{
		char s[100] = {0};
		int k = dectox_int((int)a, 16, s);

		return *s;
	}
};

	void OpenFile(OpenFileToConsole* f)
	{
		f->Display("text.txt");
	}


	int main()
	{
		while(true){

		OpenFileToConsole* f = nullptr;
		int choice;
		cout << "\n1. Open file to console\n2. Open file to ASKII\n"
			<< "3. Open file to Hexadecimal\n0. Exit\n";
		cout << "Make your choice: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			f = new OpenFileToConsole;
			f->setPath("text.txt");
			break;
		case 2:
			f = new OpenFileToASKII;
			f->setPath("text.txt");
			break;
		case 3:
			f = new OpenFileToРexadecimal;
			f->setPath("text.txt");
			break;
		case 0:

			return 0;
		}

		OpenFile(f);
	}
	return 0;
}



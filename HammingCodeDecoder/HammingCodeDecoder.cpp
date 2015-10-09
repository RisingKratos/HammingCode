#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

char input[1024];
int len;

int find_mistake()
{
	int i, mistake = 0;
	for (i = 0; i < len; i++)
		if (input[i] == '1')
			mistake ^= i + 1;
	return mistake;
}

int main()
{
	int i, mistake = 0;
	char info[1024];
	int infoPos = 0;
	int b = 1;

	len = 0;
	printf("Enter code: ");
	cin>>input;
	while (input[len] != NULL) // нахожу длину
	{
		++len;
	}
	for (i = 0; i < len; i++)			//проверка на правильность
		if (input[i] != '0' && input[i] != '1')
		{
			cout<< "Invalid code." << endl;
			return -1;
		}
	mistake = find_mistake();//находим ошибку
	if (mistake)
	{
		input[mistake - 1] ^= '0' ^ '1';//
		mistake = find_mistake();

		if (mistake)
		{
			cout<<"Invalid code."<<endl;
			return -1;
		}
	}

	cout << "Fixed code: ";
	for (int i = 0; i < len;++i)
	{
		cout<<input[i];
	}
	cout << endl;
	for (i = 0; i < len; i++)
		if (i + 1 == b)
			b <<= 1;
		else
			info[infoPos++] = input[i];
	info[infoPos] = '\0';
	cout<<"Informational string"<< info <<endl;
	return 0;
}
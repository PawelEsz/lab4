#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

string NumberToString(int);

int main(int argc, char *argv[])
{
	int number = atoi(argv[1]);
	cout << NumberToString(number);
}

string NumberToString(int n)
{
	string text;
	string ones[] = { "jeden", "dwa", "trzy", "cztery", "piêæ", "szeœæ", "siedem", "osiem", "dziewiêæ" };
	string teens[] = { "jedenaœcie", "dwanaœcie", "trzynaœcie", "czternaœcie",
		"piêtnaœcie", "szesnaœcie", "siedemnaœcie", "osiemnaœcie", "dziewiêtnaœcie" };
	string teen[] = { "dwadzieœcia", "dwadzieœcia", "trzydzieœci", "czterdzieœci", "piêædziesi¹t",
		"szeœædziesi¹t", "siedemdziesi¹t", "osiemdziesi¹t", "dziewiêædziesti¹t" };
	string hundreads[] = { "sto", "dzwieœcie", "trzysta", "czterysta", "piêœcet",
		"szeœæset", "siedemset", "osiemset", "dziewiêæset" };
	string thousands[] = { "tysi¹c", "tysi¹ce", "tysiêcy" };
	int numbers[6];

	for (int i = 5; i >= 0; i--)
	{
		numbers[i] = n % 10;
		n /= 10;
	}

	for (int i = 1; i < 10; i++)
	{
		if (numbers[0] == i) { text += (hundreads[i - 1] + " "); }
	}

	if (numbers[1] == 1)
	{
		for (int i = 1; i < 10; i++)
		{
			if (numbers[2] == i) { text += (teens[i - 1] + " "); }
			if (numbers[2] == 0) { text += (teen[i - 1] + " "); }
		}
		text += (thousands[2] + " ");
	}
	else
	{
		for (int i = 2; i < 10; i++) if (numbers[1] == i) { text += (teen[i - 1] + " "); }
		for (int i = 1; i < 10; i++) if (numbers[2] == i) { text += (ones[i - 1] + " "); }

		if (numbers[0] == 0 && numbers[1] == 0 && numbers[2] == 1) { text += (thousands[0] + " "); }
		else if (numbers[0] != 0 || numbers[1] != 0 || numbers[2] != 0)
		{
			if (numbers[2] > 1 && numbers[2] < 5) { text += (thousands[1] + " "); }
			else text += (thousands[2] + " ");
		}
	}

	for (int i = 1; i < 10; i++)
	{
		if (numbers[3] == i) { text += (hundreads[i - 1] + " "); }
	}

	if (numbers[4] == 1)
	{
		for (int i = 1; i < 10; i++)
		{
			if (numbers[5] == i) { text += (teens[i - 1] + " "); }
			if (numbers[5] == 0) { text += (teen[i - 1] + " "); }
		}
	}
	else
	{
		for (int i = 2; i < 10; i++) if (numbers[4] == i) { text += (teen[i - 1] + " "); }
		for (int i = 1; i < 10; i++) if (numbers[5] == i) { text += (ones[i - 1] + "."); }

	}

	return text;
}


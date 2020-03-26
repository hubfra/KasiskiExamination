
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;


vector<int> dividers(19, 0);
void FindAllDivisors(int num);


int main()
{
	string text;
	ifstream input("input.txt");
	ofstream output("output.txt");
	int min_pattern_length = 5;

	cout << "Enter minimum pattern length: ";
	cin >> min_pattern_length;

	char c;
	while (input >> c)
	{
		if (c >= 'a' && c <= 'z')
			text.push_back(c - 32);
		else if ((c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z'))
			text.push_back(c);
	}
	input.close();
	
	int max_pattern_length = text.size() / 2;
	int flag;

	for (int pattern_length = min_pattern_length; pattern_length < max_pattern_length; pattern_length++)
	{
		flag = 0;

		int max_a = text.size() - pattern_length - pattern_length;
		for (int a = 0; a <= max_a; ++a)
		{
			int max_b = text.size() - a - pattern_length;
			for (int b = pattern_length; b <= max_b; b++) 
			{
				int c;
				for (c = 0; c < pattern_length; c++)
				{
					if (text[b + c + a] != text[c + a])
						break;
				}
					
				if (c == pattern_length)
				{
					flag++;
					FindAllDivisors(b);
				}
			}
		}

		if (flag == 0)
			break;
	}

	for (int a = 0; a < dividers.size(); ++a)
		output << "N = " << a + 2 << " - " << dividers[a] << '\n';

	output.close();

	return 0;
}

void FindAllDivisors(int num)
{
	for (int a = 2; a <= 20; ++a)
		if (num % a == 0)
			dividers[a - 2]++;
}
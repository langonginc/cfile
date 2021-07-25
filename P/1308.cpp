#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

char change (char &x)
{
	if (x >= 'A' && x <= 'Z')
	{
		return x = x - 'A' + 'a';
	}
	return x;
}

int main ()
{
	string word, str;
	getline (cin, word);
	getline (cin, str);
	int wordlen = word.length(), strlen = str.length();
	for (int i = 0; i <= wordlen; i ++)
	{
		change (word[i]);
	}
	for (int i = 0; i <= strlen; i ++)
	{
		change (str[i]);
	}
	int count = 0, pos = -1;
	for (int i = 0; i <= strlen - wordlen; i ++)
	{
		int curpos = i, wordpos = 0;
		while (wordpos < wordlen &&str[curpos] == word[wordpos])
		{
			curpos ++, wordpos ++;
		}
		if (wordpos == wordlen)
		{
			if (((i == 0) || (str[i - 1] == ' ')) && ((i == strlen - wordlen) || (str[curpos] == ' ')))
			{
				count ++;
				if (pos == -1)
				{
					pos = i;
				}
			}
		}
	}
	if (count == 0)
	{
		printf ("-1");
	}
	else
	{
		printf ("%d %d", count, pos);
	}
	return 0;
}

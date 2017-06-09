// ShortestDuplicateWord.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <unordered_map>

using namespace std;

void shortestDuplicateWord(const char * p)
{
	typedef pair <string, int> StrIntPair;
	typedef unordered_map<string, int> WordCountMap;
	typedef WordCountMap::iterator WordCountMapIter;

	if (NULL == p || !*p)
		return;

	WordCountMap wordCount;
	WordCountMapIter iter;
	string word;
	int wordLen = strlen(p);
	while(true)
	{
		if (*p == ' ' || !*p)
		{
			int count = 1;
			WordCountMapIter iter = wordCount.find(word);
			if (wordCount.end() == iter)
				wordCount.insert(StrIntPair(word, count));
			else
				count = ++iter->second; //increase count
			
			//Find shortest duplicate
			if (count > 1 && word.length() < wordLen)
				wordLen = word.length();
			
			word.clear(); //erase it 
			if (!*p)
				break;
		}
		else
			word += *p;

		++p;
	}

	//Find the most repeated duplicate
	int max = 0;
	string result;
	for (iter = wordCount.begin(); iter != wordCount.end(); ++iter)
	{
		if (iter->first.length() == wordLen && iter->second > max)
		{
			max = iter->second;
			result = iter->first;
		}
	}

	printf("Result = %s\n", result.c_str());
}

int main()
{
	const char str[] = "A ABCD ABC ABC ABCD AB AB ABCD AB BC BC BC BC";
	shortestDuplicateWord(str);
    return 0;
}

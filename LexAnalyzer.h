#ifndef LEXANALYZER
#define LEXANALYZER

#include <iostream>
#include <regex>

using namespace std;

struct element
{
	string elem;
	unsigned type;
};

class LexAnalyzer
{
	private:
		string text;
		int i; //длина текста в символах
		int count_words;

	public:
		LexAnalyzer(string s) : text(s), i(0), count_words(0) {}
		LexAnalyzer() : text(""), i(0), count_words(0) {}

	class AnError
	{
		public:
			string ans_error;
			AnError(string s) { ans_error = s; }
	};

	string Translit(element symbols[100]);
	string LexAnaliz(element symbols[100], element answer[100]);
	int get_i() { return i; }
	int get_count_words() { return count_words; }
};

#endif
#include "LexAnalyzer.h"

string LexAnalyzer::Translit(element answer[100])
{
	string message = "";
	for (i = 0; i <= text.size(); i++)
	{
		answer[i].type = 0;
		if ((text[i] == '0') || (text[i] == '1'))
		{
			answer[i].elem = text[i];
			answer[i].type = 1;
			message = message + "(Number " + answer[i].elem + ")";
		}
		if ((text[i] >= 'a') && (text[i] <= 'd'))
		{
			answer[i].elem = text[i];
			answer[i].type = 2;
			message = message + "(Letter " + answer[i].elem + ")";
		}
		if (text[i] == '(')
		{
			answer[i].elem = text[i];
			answer[i].type = 3;
			message = message + "(Reserved " + answer[i].elem + ")";
		}
		if (text[i] == ')')
		{
			answer[i].elem = text[i];
			answer[i].type = 4;
			message = message + "(Reserved " + answer[i].elem + ")";
		}
		if (text[i] == '[')
		{
			answer[i].elem = text[i];
			answer[i].type = 5;
			message = message + "(Reserved " + answer[i].elem + ")";
		}
		if (text[i] == ']')
		{
			answer[i].elem = text[i];
			answer[i].type = 6;
			message = message + "(Reserved " + answer[i].elem + ")";
		}
		if (text[i] == '#')
		{
			answer[i].elem = text[i];
			answer[i].type = 7;
			message = message + "(Reserved " + answer[i].elem + ")";
		}
		if (text[i] == '\n')
		{
			answer[i].elem = text[i];
			answer[i].type = 8;
			message = message + "(EndRow )";
		}
		if (text[i] == '\t')
		{
			answer[i].elem = text[i];
			answer[i].type = 9;
			message = message + "(Tab )";
		}
		if (text[i] == ' ')
		{
			answer[i].elem = text[i];
			answer[i].type = 10;
			message = message + "(Space )";
		}
		if (text[i] == '\0')
		{
			answer[i].elem = text[i];
			answer[i].type = 11;
			message = message + "(EndText )";
		}
		if (answer[i].type == 0)
		{
			answer[i].elem = text[i];
			message = message + "(Character does not belong to the alphabet " + answer[i].elem + ")";
			return message;
		}
	}
	return message + "(Text is correct)";
}

string LexAnalyzer::LexAnaliz(element symbols[100], element words[100])
{
	int k = 0;
	for (int j = 0; j <= text.size(); j++)
	{
		// если это "#"
		if (symbols[j].type == 7)
		{
			j++;
			while (true)
				if (symbols[j].type == 7)
				{
					j++;
					break;
				}
				else
					j++;
		}

		// если это " " или "\n" или "\0" или "\t"
		if ((symbols[j].type <= 11) && (symbols[j].type >= 8))
		{
			continue;
		}

		// если это 0 или 1 или a-d или ( или ) или [ или ]
		if ((symbols[j].type <= 6) && (symbols[j].type >= 1))
		{
			if (j == 0) // если это первый символ 
				words[k].elem = words[k].elem + text[j]; // запись слова
			else
				// если не совпадает с предыдущим по типу или это скобка(любая)
				if ((symbols[j].type != symbols[j - 1].type) || ((symbols[j].type <= 8) && (symbols[j].type >= 3)))
				{
					if (words[k].elem != "")
					{
						k++;
					}
					words[k].elem = words[k].elem + text[j]; // запись слова
				}
				else
					words[k].elem = words[k].elem + text[j]; // запись слова
		}
	}

	string otvet_error = "";
	for (count_words = 0; count_words <= k; count_words++)
	{
		regex   regexp1("(010)*101(110)*"),
				regexp2("(^[acd](a|b|c|d)*)|(^b[bcd]*)"),
				regexp3("\\("),
				regexp4("\\)"),
				regexp5("\\["),
				regexp6("\\]");
		words[count_words].type = 0;
		if (regex_match(words[count_words].elem, regexp1))
		{
			words[count_words].type = 1;
			otvet_error = otvet_error + "(" + words[count_words].elem + ", number)";
		}
		if (regex_match(words[count_words].elem, regexp2))
		{
			words[count_words].type = 2;
			otvet_error = otvet_error + "(" + words[count_words].elem + ", id)";
		}
		if (regex_match(words[count_words].elem, regexp3))
		{
			words[count_words].type = 3;
			otvet_error = otvet_error + "(" + words[count_words].elem + ", reserved)";
		}
		if (regex_match(words[count_words].elem, regexp4))
		{
			words[count_words].type = 4;
			otvet_error = otvet_error + "(" + words[count_words].elem + ", reserved)";
		}
		if (regex_match(words[count_words].elem, regexp5))
		{
			words[count_words].type = 5;
			otvet_error = otvet_error + "(" + words[count_words].elem + ", reserved)";
		}
		if (regex_match(words[count_words].elem, regexp6))
		{
			words[count_words].type = 6;
			otvet_error = otvet_error + "(" + words[count_words].elem + ", reserved)";
		}
		if (words[count_words].type == 0)
		{
			otvet_error = otvet_error + "(" + words[count_words].elem + ", wrong word)";
			count_words++;
			throw AnError(otvet_error);
		}
	}
	return otvet_error + "(Text is correct)";
}
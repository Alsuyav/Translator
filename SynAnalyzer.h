#ifndef SYNANALYZER
#define SYNANALYZER
#include "Node.h"
#include "LexAnalyzer.h"

class SynAnalyzer
{
	private:
		element words[100];
		int count_words;
		int num_word;
		Node* root;
	public:
		SynAnalyzer(element w[100], int count)
		{
			count_words = count;
			num_word = 0;
			for (int j = 0; j < count_words; j++) { words[j] = w[j];}
			root = new Node("S", NULL);
		}
		
		class AnError
		{
			public:
				int number_of_word;
				AnError(int n) { number_of_word = n; }
		};
		
		Node* get_root() { return root; }

		int SyntAnaliz(); // возвращает 1 (если нет ошибки)
		void S();
		void A();
		void B();
		int iter_check();

		int for_go_tree(Node* r, string& m);

		string go_tree();

};

#endif
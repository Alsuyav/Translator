#ifndef MYFORM
#define MYFORM

#include "LexAnalyzer.h"
#include "SynAnalyzer.h"
#include "HashTables.h"
#include "Node.h"
#include <cmath>
#include <string>					// для работы с обычными строками C++
#include <msclr/marshal_cppstd.h>	// для перевода из System::String^ в std::string

string convert_to_dec(string bs)
{
	int b = stoi(bs);
	int sum = 0;
	for (int i = 0; i < bs.length(); i++)
	{
		sum = sum + b%10*pow(2, i);
		b = b / 10;
	}
	return to_string(sum);
}

int check_context = 0;
string num_repeat = "";


namespace CopyLab2 
{
	
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
		public:
			MyForm(void)
			{
				InitializeComponent();
			}

		protected:
			/// <summary>
			/// Освободить все используемые ресурсы.
			/// </summary>
			~MyForm()
			{
				if (components) delete components;
			}

		#pragma region Components
			private: System::Windows::Forms::Label^ label1;
			private: System::Windows::Forms::Label^ label2;
			private: System::Windows::Forms::Label^ label3;
			private: System::Windows::Forms::Label^ label4;
			private: System::Windows::Forms::Label^ label5;
			private: System::Windows::Forms::RichTextBox^ richTextBox1;
			private: System::Windows::Forms::RichTextBox^ richTextBox2;
			private: System::Windows::Forms::RichTextBox^ richTextBox3;
			private: System::Windows::Forms::RichTextBox^ richTextBox4;
			private: System::Windows::Forms::RichTextBox^ richTextBox5;
			private: System::Windows::Forms::Button^ button1;
			private: System::Windows::Forms::Button^ button2;
			private: System::Windows::Forms::Button^ button3;
			private: System::Windows::Forms::Button^ button4;
			private: System::Windows::Forms::Button^ button5;
			private: System::Windows::Forms::RichTextBox^ richTextBox6;
			private: System::Windows::Forms::Label^ label6;

			private: System::Windows::Forms::Button^ button6;
			private: System::Windows::Forms::RichTextBox^ richTextBox7;
			private: System::Windows::Forms::RichTextBox^ richTextBox8;
			private: System::Windows::Forms::Button^ button7;
			private: System::Windows::Forms::Button^ button8;
	private: System::Windows::Forms::TreeView^ treeView1;
#pragma endregion

		private:
			/// <summary>
			/// Обязательная переменная конструктора.
			/// </summary>
			System::ComponentModel::Container ^components;

		#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->richTextBox2 = (gcnew System::Windows::Forms::RichTextBox());
			this->richTextBox3 = (gcnew System::Windows::Forms::RichTextBox());
			this->richTextBox4 = (gcnew System::Windows::Forms::RichTextBox());
			this->richTextBox5 = (gcnew System::Windows::Forms::RichTextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->richTextBox6 = (gcnew System::Windows::Forms::RichTextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->richTextBox7 = (gcnew System::Windows::Forms::RichTextBox());
			this->richTextBox8 = (gcnew System::Windows::Forms::RichTextBox());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->treeView1 = (gcnew System::Windows::Forms::TreeView());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(11, 7);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(117, 17);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Исходный текст:";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(398, 7);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(133, 17);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Результат работы:";
			this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(76, 262);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(53, 17);
			this->label3->TabIndex = 8;
			this->label3->Text = L"Числа:";
			this->label3->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(315, 262);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(128, 17);
			this->label4->TabIndex = 11;
			this->label4->Text = L"Идентификаторы:";
			this->label4->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(565, 245);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(140, 51);
			this->label5->TabIndex = 12;
			this->label5->Text = L"Слова из\r\nзарезервированных\r\nсимволов:";
			this->label5->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// richTextBox1
			// 
			this->richTextBox1->Location = System::Drawing::Point(14, 34);
			this->richTextBox1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(341, 145);
			this->richTextBox1->TabIndex = 2;
			this->richTextBox1->Text = L"";
			// 
			// richTextBox2
			// 
			this->richTextBox2->BackColor = System::Drawing::SystemColors::Window;
			this->richTextBox2->Location = System::Drawing::Point(402, 34);
			this->richTextBox2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->richTextBox2->Name = L"richTextBox2";
			this->richTextBox2->ReadOnly = true;
			this->richTextBox2->Size = System::Drawing::Size(341, 145);
			this->richTextBox2->TabIndex = 4;
			this->richTextBox2->Text = L"";
			// 
			// richTextBox3
			// 
			this->richTextBox3->BackColor = System::Drawing::SystemColors::Window;
			this->richTextBox3->Location = System::Drawing::Point(14, 304);
			this->richTextBox3->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->richTextBox3->Name = L"richTextBox3";
			this->richTextBox3->ReadOnly = true;
			this->richTextBox3->Size = System::Drawing::Size(208, 145);
			this->richTextBox3->TabIndex = 7;
			this->richTextBox3->Text = L"";
			// 
			// richTextBox4
			// 
			this->richTextBox4->BackColor = System::Drawing::SystemColors::Window;
			this->richTextBox4->Location = System::Drawing::Point(275, 304);
			this->richTextBox4->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->richTextBox4->Name = L"richTextBox4";
			this->richTextBox4->ReadOnly = true;
			this->richTextBox4->Size = System::Drawing::Size(208, 145);
			this->richTextBox4->TabIndex = 9;
			this->richTextBox4->Text = L"";
			// 
			// richTextBox5
			// 
			this->richTextBox5->BackColor = System::Drawing::SystemColors::Window;
			this->richTextBox5->Location = System::Drawing::Point(533, 304);
			this->richTextBox5->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->richTextBox5->Name = L"richTextBox5";
			this->richTextBox5->ReadOnly = true;
			this->richTextBox5->Size = System::Drawing::Size(208, 145);
			this->richTextBox5->TabIndex = 10;
			this->richTextBox5->Text = L"";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(14, 199);
			this->button1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(175, 34);
			this->button1->TabIndex = 3;
			this->button1->Text = L"Транслитератор";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(195, 199);
			this->button2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(175, 34);
			this->button2->TabIndex = 5;
			this->button2->Text = L"Лексич. анализатор";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(376, 199);
			this->button3->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(175, 34);
			this->button3->TabIndex = 6;
			this->button3->Text = L"Синтакс. анализатор";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(291, 458);
			this->button4->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(175, 54);
			this->button4->TabIndex = 13;
			this->button4->Text = L"Разделение слов по таблицам";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(829, 85);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(148, 44);
			this->button5->TabIndex = 14;
			this->button5->Text = L"Поиск слова";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::button5_Click);
			// 
			// richTextBox6
			// 
			this->richTextBox6->BackColor = System::Drawing::SystemColors::Window;
			this->richTextBox6->Location = System::Drawing::Point(799, 34);
			this->richTextBox6->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->richTextBox6->Name = L"richTextBox6";
			this->richTextBox6->Size = System::Drawing::Size(208, 46);
			this->richTextBox6->TabIndex = 15;
			this->richTextBox6->Text = L"";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(796, 142);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(167, 17);
			this->label6->TabIndex = 16;
			this->label6->Text = L"Синтаксическое дерево";
			this->label6->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(829, 458);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(148, 44);
			this->button6->TabIndex = 18;
			this->button6->Text = L"Вывод дерева";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &MyForm::button6_Click);
			// 
			// richTextBox7
			// 
			this->richTextBox7->BackColor = System::Drawing::SystemColors::Window;
			this->richTextBox7->Location = System::Drawing::Point(784, 350);
			this->richTextBox7->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->richTextBox7->Name = L"richTextBox7";
			this->richTextBox7->ReadOnly = true;
			this->richTextBox7->Size = System::Drawing::Size(223, 82);
			this->richTextBox7->TabIndex = 19;
			this->richTextBox7->Text = L"";
			// 
			// richTextBox8
			// 
			this->richTextBox8->BackColor = System::Drawing::SystemColors::Window;
			this->richTextBox8->Location = System::Drawing::Point(1037, 34);
			this->richTextBox8->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->richTextBox8->Name = L"richTextBox8";
			this->richTextBox8->Size = System::Drawing::Size(208, 46);
			this->richTextBox8->TabIndex = 21;
			this->richTextBox8->Text = L"";
			// 
			// button7
			// 
			this->button7->Location = System::Drawing::Point(1055, 85);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(178, 44);
			this->button7->TabIndex = 20;
			this->button7->Text = L"Проверка контекста";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &MyForm::button7_Click);
			// 
			// button8
			// 
			this->button8->Location = System::Drawing::Point(557, 183);
			this->button8->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(175, 50);
			this->button8->TabIndex = 22;
			this->button8->Text = L"Перевод в чисел в десятич. СС";
			this->button8->UseVisualStyleBackColor = true;
			this->button8->Click += gcnew System::EventHandler(this, &MyForm::button8_Click);
			// 
			// treeView1
			// 
			this->treeView1->Location = System::Drawing::Point(784, 176);
			this->treeView1->Name = L"treeView1";
			this->treeView1->Size = System::Drawing::Size(223, 148);
			this->treeView1->TabIndex = 17;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->ClientSize = System::Drawing::Size(1255, 514);
			this->Controls->Add(this->button8);
			this->Controls->Add(this->richTextBox8);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->richTextBox7);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->treeView1);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->richTextBox6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->richTextBox5);
			this->Controls->Add(this->richTextBox4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->richTextBox3);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->richTextBox2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->richTextBox1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Name = L"MyForm";
			this->Text = L"Транслятор";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
		#pragma endregion

		// что происходит при щелчке на кнопку "Транслитератор"
		private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e)
		{
			string input = msclr::interop::marshal_as <std::string>(richTextBox1->Text);
			LexAnalyzer obj(input);
			element symb[100];
			string otvet = obj.Translit(symb);
			richTextBox2->Text = msclr::interop::marshal_as <System::String^>(otvet);
		}
		

		// что происходит при щелчке на кнопку "Лексич. анализатор"
		private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e)
		{
			string input = msclr::interop::marshal_as <std::string>(richTextBox1->Text);
			LexAnalyzer obj(input);
			element symb[100];
			element slova[100];
			obj.Translit(symb);
			string otvet;
			try
			{
				otvet = obj.LexAnaliz(symb, slova);
				richTextBox2->Text = msclr::interop::marshal_as <System::String^>(otvet);
			}

			catch (LexAnalyzer::AnError b)
			{
				richTextBox2->Text = msclr::interop::marshal_as <System::String^>(b.ans_error);
			}
		}
		

		// что происходит при щелчке на кнопку "Синтакс. анализатор"
		private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e)
		{
			string input = msclr::interop::marshal_as <std::string>(richTextBox1->Text);
			LexAnalyzer obj1(input);
			element symb[100];
			element slova[100];
			obj1.Translit(symb);
			obj1.LexAnaliz(symb, slova);
			SynAnalyzer obj2(slova, obj1.get_count_words());
			string otvet;
			try
			{
				obj2.SyntAnaliz();
				otvet = "Text is correct";
			}
			catch (SynAnalyzer::AnError a)
			{
				otvet = "Mistake in " + to_string(a.number_of_word + 1) + " word";
			}
			richTextBox2->Text = msclr::interop::marshal_as <System::String^>(otvet);
		}
	

		// что происходит при щелчке на кнопку "Разделение слов по таблицам"
		private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) 
		{
			unordered_map <string, string> numTable;
			unordered_map <string, string> idTable;
			unordered_map <string, string> reservedTable;
			string input = msclr::interop::marshal_as <std::string>(richTextBox1->Text);
				LexAnalyzer obj1(input);
				element symb[100]; // токены символов
				element slova[100]; // токены слов
				obj1.Translit(symb);
				obj1.LexAnaliz(symb, slova);
				SynAnalyzer obj2(slova, obj1.get_count_words());
			if (obj2.SyntAnaliz())
			{
				string otvet3 = "";
				string otvet4 = "";
				string otvet5 = "";
				for (int i = 0; i < obj1.get_count_words(); i++)
				{
					if (slova[i].type == 1)
					{
						numTable.insert(make_pair(slova[i].elem, slova[i].elem));
						string temp = numTable[slova[i].elem];
						otvet3 = otvet3 + temp + "\n";
					}
					if (slova[i].type == 2)
					{
						idTable.insert(make_pair(slova[i].elem, slova[i].elem));
						string temp = idTable[slova[i].elem];
						otvet4 = otvet4 + temp + "\n";
					}
					if ((slova[i].type >= 3) && (slova[i].type <= 6))
					{
						reservedTable.insert(make_pair(slova[i].elem, slova[i].elem));
						string temp = reservedTable[slova[i].elem];
						otvet5 = otvet5 + temp + "\n";
					}
				}
				richTextBox3->Text = msclr::interop::marshal_as <System::String^>(otvet3);
				richTextBox4->Text = msclr::interop::marshal_as <System::String^>(otvet4);
				richTextBox5->Text = msclr::interop::marshal_as <System::String^>(otvet5);
			}
		}


		// Поиск по хэштаблице
		private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e)
		{
			unordered_map <string, string> numTable;
			unordered_map <string, string> idTable;
			unordered_map <string, string> reservedTable;
			string input = msclr::interop::marshal_as <std::string>(richTextBox1->Text);
			LexAnalyzer obj1(input);
			element symb[100]; // токены символов
			element slova[100]; // токены слов
			obj1.Translit(symb);
			obj1.LexAnaliz(symb, slova);
			SynAnalyzer obj2(slova, obj1.get_count_words());
			if (obj2.SyntAnaliz())
			{
				for (int i = 0; i < obj1.get_count_words(); i++)
				{
					if (slova[i].type == 1)
					{
						numTable.insert(make_pair(slova[i].elem, slova[i].elem));
					}
					if (slova[i].type == 2)
					{
						idTable.insert(make_pair(slova[i].elem, slova[i].elem));
					}
					if ((slova[i].type >= 3) && (slova[i].type <= 6))
					{
						reservedTable.insert(make_pair(slova[i].elem, slova[i].elem));
					}
				}
				string input = msclr::interop::marshal_as <std::string>(richTextBox6->Text);
				if ((numTable.find(input) == numTable.end()) && (idTable.find(input) == idTable.end()) && (reservedTable.find(input) == reservedTable.end()))
					richTextBox6->Text = msclr::interop::marshal_as <System::String^>("Слово " + input + " не найдено");
				else
					richTextBox6->Text = msclr::interop::marshal_as <System::String^>("Слово " + input + " найдено");
			}
		}


		// проверка контекста
		private: System::Void button7_Click(System::Object^ sender, System::EventArgs^ e)
		{
			unordered_map <string, string> numTable;
			unordered_map <string, string> idTable;
			unordered_map <string, string> reservedTable;
			string input = msclr::interop::marshal_as <std::string>(richTextBox1->Text);
			LexAnalyzer obj1(input);
			element symb[100]; // токены символов
			element slova[100]; // токены слов
			obj1.Translit(symb);
			obj1.LexAnaliz(symb, slova);
			SynAnalyzer obj2(slova, obj1.get_count_words());
			if (obj2.SyntAnaliz())
			{
				for (int i = 0; i < obj1.get_count_words(); i++)
				{
					if (slova[i].type == 1)
					{
						if (numTable.find(slova[i].elem) != numTable.end())
						{
							check_context = 1;
							num_repeat = slova[i].elem;
						}
						numTable.insert(make_pair(slova[i].elem, slova[i].elem));
					}
					if (slova[i].type == 2)
					{
						idTable.insert(make_pair(slova[i].elem, slova[i].elem));
					}
					if ((slova[i].type >= 3) && (slova[i].type <= 6))
					{
						reservedTable.insert(make_pair(slova[i].elem, slova[i].elem));
					}
				}
				if (check_context)
				{
					richTextBox8->Text = msclr::interop::marshal_as <System::String^>("В тексте есть одинаковые числа: " + num_repeat);
				}
				else
					richTextBox8->Text = msclr::interop::marshal_as <System::String^>("В тексте нет одинаковых чисел!");
			}
		}

		
		// перевод чисел в десятичную СС
		private: System::Void button8_Click(System::Object^ sender, System::EventArgs^ e)
		{
			string input = msclr::interop::marshal_as <std::string>(richTextBox1->Text);
			LexAnalyzer obj(input);
			element symb[100];
			element slova[100];
			obj.Translit(symb);
			string otvet = "";
			try
			{
				obj.LexAnaliz(symb, slova);
			}

			catch (LexAnalyzer::AnError b)
			{
				richTextBox2->Text = msclr::interop::marshal_as <System::String^>(b.ans_error);
			}

			for (int i = 0; i < obj.get_count_words(); i++)
			{
				if (slova[i].type == 1)
					otvet = otvet + convert_to_dec(slova[i].elem);
				else
					otvet = otvet + slova[i].elem;
			}
			richTextBox2->Text = msclr::interop::marshal_as <System::String^>(otvet);
		}


		// построение синтаксического дерева
		private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e)
		{
			string input = msclr::interop::marshal_as <std::string>(richTextBox1->Text);
			LexAnalyzer obj1(input);
			element symb[100];
			element slova[100];
			obj1.Translit(symb);
			obj1.LexAnaliz(symb, slova);
			SynAnalyzer obj2(slova, obj1.get_count_words());
			string otvet;
			try
			{
				obj2.SyntAnaliz();
				otvet = "Text is correct";
			}
			catch (SynAnalyzer::AnError a)
			{
				otvet = "Mistake in " + to_string(a.number_of_word + 1) + " word";
			}
			richTextBox2->Text = msclr::interop::marshal_as <System::String^>(otvet);

			string mess = obj2.go_tree();



			richTextBox7->Text = msclr::interop::marshal_as <System::String^>(mess);








			//
			//string mess2;

			//Node* tempo = obj2.get_root(); // указатель на корень дерева
			//mess = mess + tempo->get_symbol() + "\n";
			//TreeNode^ node1 = gcnew TreeNode;
			//node1->Text = "S";
			//this->treeView1->Nodes->Add(node1);

			//Node* arr[8];
			//tempo->get_all_child(arr);

			//for (int i = 0; i < tempo->get_number_of_child(); i++)
			//{
			//	if (arr[i])
			//	{
			//		mess = mess + arr[i]->get_symbol() + " ";
			//		for (int j = 0; j < arr[i]->get_number_of_child(); j++)
			//		{
			//			if (arr[j])
			//			{
			//				mess2 = mess2 + arr[j]->get_symbol() + " ";
			//			}
			//		}


			//		TreeNode^ node2 = gcnew TreeNode;
			//		node2->Text = msclr::interop::marshal_as < System::String^>(arr[i]->get_symbol());
			//		cli::array <TreeNode^>^ temp = { node2 };
			//		/*TreeNode(node1, temp);*/
			//	}
			//	else
			//		break;
			//}

	



		}


};
}

#endif
#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "MyForm2.h"

int NC;

struct z {
	char companyName[20];
	char rocketName[20];
	int pricePerLaunch;
	int successfulFlights;
	int failureFlights;
} *companies;

struct sp {
	char companyName[20];
	int successfulFlights;
	struct sp* sled;
	struct sp* pred;
} *spisok;

void vstavka(struct z* company, char* companyName)
{
	struct sp* nov, * nt, * z = 0;

	for (nt = spisok; nt != 0 && strcmp(nt->companyName, companyName) < 0; z = nt, nt = nt->sled);

	if (nt && strcmp(nt->companyName, companyName) == 0) return;

	nov = (struct sp*)malloc(sizeof(struct sp));
	strcpy(nov->companyName, companyName);
	nov->sled = nt;
	nov->pred = z;
	nov->successfulFlights = 0;

	for (int i = 0; i < NC; i++)
		if (strcmp(company[i].companyName, companyName) == 0)
			nov->successfulFlights += company[i].successfulFlights;

	if (!z) spisok = nov;
	else z->sled = nov;
	if (nt) nt->pred = nov;
	return;
}

namespace KursovayaGUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Runtime::InteropServices;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{

	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ файлToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ открытьToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ завершитьToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ вопросыToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ выходToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ среднеејрифметическое”спешных«апусковToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ кака€—ама€ƒешева€–акетаƒл€«апускаToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ размах–€да÷еныToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ естьЋиќдинакова€÷ена«апуска”–азных омпанийToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ алфавитный—писок¬сех омпанийToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ диаграммаѕроцентное—оотношение¬сех«апусков аждой омпанииToolStripMenuItem;
	private: System::Windows::Forms::TabControl^ tabControl1;
	private: System::Windows::Forms::TabPage^ tabPage1;
	private: System::Windows::Forms::TabPage^ tabPage2;

	private: System::Windows::Forms::RichTextBox^ richTextBox1;
	private: System::Windows::Forms::TabPage^ tabPage3;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::ToolStripMenuItem^ число омпаний” оторых„ислоѕровальныхѕусковћеньше„емToolStripMenuItem;

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle3 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->файлToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->открытьToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->завершитьToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->вопросыToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->среднеејрифметическое”спешных«апусковToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->кака€—ама€ƒешева€–акетаƒл€«апускаToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->размах–€да÷еныToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->естьЋиќдинакова€÷ена«апуска”–азных омпанийToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->алфавитный—писок¬сех омпанийToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->диаграммаѕроцентное—оотношение¬сех«апусков аждой омпанииToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->выходToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->tabPage3 = (gcnew System::Windows::Forms::TabPage());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->число омпаний” оторых„ислоѕровальныхѕусковћеньше„емToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuStrip1->SuspendLayout();
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->tabPage2->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Font = (gcnew System::Drawing::Font(L"Courier New", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->файлToolStripMenuItem,
					this->вопросыToolStripMenuItem, this->выходToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1254, 25);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// файлToolStripMenuItem
			// 
			this->файлToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->открытьToolStripMenuItem,
					this->завершитьToolStripMenuItem
			});
			this->файлToolStripMenuItem->Name = L"файлToolStripMenuItem";
			this->файлToolStripMenuItem->Size = System::Drawing::Size(56, 21);
			this->файлToolStripMenuItem->Text = L"‘айл";
			// 
			// открытьToolStripMenuItem
			// 
			this->открытьToolStripMenuItem->Name = L"открытьToolStripMenuItem";
			this->открытьToolStripMenuItem->Size = System::Drawing::Size(157, 22);
			this->открытьToolStripMenuItem->Text = L"ќткрыть";
			this->открытьToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::открытьToolStripMenuItem_Click);
			// 
			// завершитьToolStripMenuItem
			// 
			this->завершитьToolStripMenuItem->Name = L"завершитьToolStripMenuItem";
			this->завершитьToolStripMenuItem->Size = System::Drawing::Size(157, 22);
			this->завершитьToolStripMenuItem->Text = L"«авершить";
			this->завершитьToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::завершитьToolStripMenuItem_Click);
			// 
			// вопросыToolStripMenuItem
			// 
			this->вопросыToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(7) {
				this->среднеејрифметическое”спешных«апусковToolStripMenuItem,
					this->кака€—ама€ƒешева€–акетаƒл€«апускаToolStripMenuItem, this->размах–€да÷еныToolStripMenuItem, this->естьЋиќдинакова€÷ена«апуска”–азных омпанийToolStripMenuItem,
					this->число омпаний” оторых„ислоѕровальныхѕусковћеньше„емToolStripMenuItem, this->алфавитный—писок¬сех омпанийToolStripMenuItem,
					this->диаграммаѕроцентное—оотношение¬сех«апусков аждой омпанииToolStripMenuItem
			});
			this->вопросыToolStripMenuItem->Enabled = false;
			this->вопросыToolStripMenuItem->Name = L"вопросыToolStripMenuItem";
			this->вопросыToolStripMenuItem->Size = System::Drawing::Size(83, 21);
			this->вопросыToolStripMenuItem->Text = L"¬опросы";
			// 
			// среднеејрифметическое”спешных«апусковToolStripMenuItem
			// 
			this->среднеејрифметическое”спешных«апусковToolStripMenuItem->Name = L"среднеејрифметическое”спешных«апусковToolStripMenuItem";
			this->среднеејрифметическое”спешных«апусковToolStripMenuItem->Size = System::Drawing::Size(661, 22);
			this->среднеејрифметическое”спешных«апусковToolStripMenuItem->Text = L"—реднее арифметическое успешных запусков\? ";
			this->среднеејрифметическое”спешных«апусковToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::среднеејрифметическое”спешных«апусковToolStripMenuItem_Click);
			// 
			// кака€—ама€ƒешева€–акетаƒл€«апускаToolStripMenuItem
			// 
			this->кака€—ама€ƒешева€–акетаƒл€«апускаToolStripMenuItem->Name = L"кака€—ама€ƒешева€–акетаƒл€«апускаToolStripMenuItem";
			this->кака€—ама€ƒешева€–акетаƒл€«апускаToolStripMenuItem->Size = System::Drawing::Size(661, 22);
			this->кака€—ама€ƒешева€–акетаƒл€«апускаToolStripMenuItem->Text = L" ака€ сама€ дешева€ ракета дл€ запуска\? ";
			this->кака€—ама€ƒешева€–акетаƒл€«апускаToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::кака€—ама€ƒешева€–акетаƒл€«апускаToolStripMenuItem_Click);
			// 
			// размах–€да÷еныToolStripMenuItem
			// 
			this->размах–€да÷еныToolStripMenuItem->Name = L"размах–€да÷еныToolStripMenuItem";
			this->размах–€да÷еныToolStripMenuItem->Size = System::Drawing::Size(661, 22);
			this->размах–€да÷еныToolStripMenuItem->Text = L"–азмах р€да цены";
			this->размах–€да÷еныToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::размах–€да÷еныToolStripMenuItem_Click);
			// 
			// естьЋиќдинакова€÷ена«апуска”–азных омпанийToolStripMenuItem
			// 
			this->естьЋиќдинакова€÷ена«апуска”–азных омпанийToolStripMenuItem->Name = L"естьЋиќдинакова€÷ена«апуска”–азных омпанийToolStripMenuItem";
			this->естьЋиќдинакова€÷ена«апуска”–азных омпанийToolStripMenuItem->Size = System::Drawing::Size(661, 22);
			this->естьЋиќдинакова€÷ена«апуска”–азных омпанийToolStripMenuItem->Text = L"≈сть ли одинакова€ цена запуска у разных компаний\?";
			this->естьЋиќдинакова€÷ена«апуска”–азных омпанийToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::естьЋиќдинакова€÷ена«апуска”–азных омпанийToolStripMenuItem_Click);
			// 
			// алфавитный—писок¬сех омпанийToolStripMenuItem
			// 
			this->алфавитный—писок¬сех омпанийToolStripMenuItem->Name = L"алфавитный—писок¬сех омпанийToolStripMenuItem";
			this->алфавитный—писок¬сех омпанийToolStripMenuItem->Size = System::Drawing::Size(661, 22);
			this->алфавитный—писок¬сех омпанийToolStripMenuItem->Text = L"јлфавитный список всех компаний";
			this->алфавитный—писок¬сех омпанийToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::алфавитный—писок¬сех омпанийToolStripMenuItem_Click);
			// 
			// диаграммаѕроцентное—оотношение¬сех«апусков аждой омпанииToolStripMenuItem
			// 
			this->диаграммаѕроцентное—оотношение¬сех«апусков аждой омпанииToolStripMenuItem->Name = L"диаграммаѕроцентное—оотношение¬сех«апусков аждой омпанииToolStripMenuItem";
			this->диаграммаѕроцентное—оотношение¬сех«апусков аждой омпанииToolStripMenuItem->Size = System::Drawing::Size(661, 22);
			this->диаграммаѕроцентное—оотношение¬сех«апусков аждой омпанииToolStripMenuItem->Text = L"ƒиаграмма. ѕроцентное соотношение всех запусков каждой компании";
			this->диаграммаѕроцентное—оотношение¬сех«апусков аждой омпанииToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::диаграммаѕроцентное—оотношение¬сех«апусков аждой омпанииToolStripMenuItem_Click);
			// 
			// выходToolStripMenuItem
			// 
			this->выходToolStripMenuItem->Name = L"выходToolStripMenuItem";
			this->выходToolStripMenuItem->Size = System::Drawing::Size(65, 21);
			this->выходToolStripMenuItem->Text = L"¬ыход";
			this->выходToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::выходToolStripMenuItem_Click);
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Controls->Add(this->tabPage3);
			this->tabControl1->Font = (gcnew System::Drawing::Font(L"Courier New", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->tabControl1->Location = System::Drawing::Point(0, 27);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(1256, 706);
			this->tabControl1->TabIndex = 1;
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->dataGridView1);
			this->tabPage1->Location = System::Drawing::Point(4, 26);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(1248, 676);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"»сходные данные";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->BackgroundColor = System::Drawing::SystemColors::Window;
			dataGridViewCellStyle1->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle1->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"Courier New", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			dataGridViewCellStyle1->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle1->Padding = System::Windows::Forms::Padding(2);
			dataGridViewCellStyle1->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle1->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle1->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGridView1->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle1;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			dataGridViewCellStyle2->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle2->BackColor = System::Drawing::SystemColors::Window;
			dataGridViewCellStyle2->Font = (gcnew System::Drawing::Font(L"Courier New", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			dataGridViewCellStyle2->ForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle2->Padding = System::Windows::Forms::Padding(2);
			dataGridViewCellStyle2->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle2->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle2->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGridView1->DefaultCellStyle = dataGridViewCellStyle2;
			this->dataGridView1->Location = System::Drawing::Point(0, 0);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			dataGridViewCellStyle3->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle3->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle3->Font = (gcnew System::Drawing::Font(L"Courier New", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			dataGridViewCellStyle3->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle3->Padding = System::Windows::Forms::Padding(2);
			dataGridViewCellStyle3->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle3->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle3->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGridView1->RowHeadersDefaultCellStyle = dataGridViewCellStyle3;
			this->dataGridView1->Size = System::Drawing::Size(1248, 684);
			this->dataGridView1->TabIndex = 0;
			// 
			// tabPage2
			// 
			this->tabPage2->Controls->Add(this->richTextBox1);
			this->tabPage2->Location = System::Drawing::Point(4, 26);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(1248, 676);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"јлфавитный список";
			this->tabPage2->UseVisualStyleBackColor = true;
			this->tabPage2->Click += gcnew System::EventHandler(this, &MyForm::tabPage2_Click);
			// 
			// richTextBox1
			// 
			this->richTextBox1->Font = (gcnew System::Drawing::Font(L"Courier New", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->richTextBox1->Location = System::Drawing::Point(0, 0);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(1252, 688);
			this->richTextBox1->TabIndex = 0;
			this->richTextBox1->Text = L"";
			// 
			// tabPage3
			// 
			this->tabPage3->Location = System::Drawing::Point(4, 26);
			this->tabPage3->Name = L"tabPage3";
			this->tabPage3->Size = System::Drawing::Size(1248, 676);
			this->tabPage3->TabIndex = 2;
			this->tabPage3->Text = L"ƒиаграмма";
			this->tabPage3->UseVisualStyleBackColor = true;
			this->tabPage3->Click += gcnew System::EventHandler(this, &MyForm::tabPage3_Click);
			this->tabPage3->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::tabPage3_Paint);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"SpaceCompanies";
			this->openFileDialog1->Filter = L"Data Files (*.dat) | *.dat";
			this->openFileDialog1->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &MyForm::openFileDialog1_FileOk);
			// 
			// число омпаний” оторых„ислоѕровальныхѕусковћеньше„емToolStripMenuItem
			// 
			this->число омпаний” оторых„ислоѕровальныхѕусковћеньше„емToolStripMenuItem->Name = L"число омпаний” оторых„ислоѕровальныхѕусковћеньше„емToolStripMenuItem";
			this->число омпаний” оторых„ислоѕровальныхѕусковћеньше„емToolStripMenuItem->Size = System::Drawing::Size(661, 22);
			this->число омпаний” оторых„ислоѕровальныхѕусковћеньше„емToolStripMenuItem->Text = L" оличество компаний, у которых число провальных пусков меньше чем";
			this->число омпаний” оторых„ислоѕровальныхѕусковћеньше„емToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::число омпаний” оторых„ислоѕровальныхѕусковћеньше„емToolStripMenuItem_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1254, 741);
			this->Controls->Add(this->tabControl1);
			this->Controls->Add(this->menuStrip1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MyForm";
			this->Text = L" урсова€ GUI";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->tabPage2->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void завершитьToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
private: System::Void tabPage2_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void выходToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Close();
}
private: System::Void открытьToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	FILE* in;
	String^ s;

	// Open the file
	if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		s = openFileDialog1->FileName;
		char* str_tmp = (char*)(void*)Marshal::StringToHGlobalAnsi(s);

		if ((in = fopen(str_tmp, "r")) == NULL)
		{
			MessageBox::Show("‘айл не открыт!", "ќшибка!", MessageBoxButtons::OK, MessageBoxIcon::Error);
			Marshal::FreeHGlobal(IntPtr((void*)str_tmp));
			return;
		}

		Marshal::FreeHGlobal(IntPtr((void*)str_tmp));
	}
	else return;

	вопросыToolStripMenuItem->Enabled = true;

	// Read the file
	DataTable^ Table1 = gcnew DataTable();
	this->dataGridView1->DataSource = Table1;
	this->dataGridView1->AllowUserToAddRows = false;
	this->dataGridView1->AllowUserToDeleteRows = false;
	this->dataGridView1->ReadOnly = true;

	Table1->Columns->Add(" омпани€");
	Table1->Columns->Add("–акета");
	Table1->Columns->Add("—тоимость в M$");
	Table1->Columns->Add("”дачные пуски");
	Table1->Columns->Add("Ќеудачные пуски");

	this->dataGridView1->Columns["—тоимость в M$"]->HeaderCell->Style->Alignment = DataGridViewContentAlignment::MiddleRight;
	this->dataGridView1->Columns["—тоимость в M$"]->DefaultCellStyle->Alignment = DataGridViewContentAlignment::MiddleRight;

	this->dataGridView1->Columns["”дачные пуски"]->HeaderCell->Style->Alignment = DataGridViewContentAlignment::MiddleRight;
	this->dataGridView1->Columns["”дачные пуски"]->DefaultCellStyle->Alignment = DataGridViewContentAlignment::MiddleRight;

	this->dataGridView1->Columns["Ќеудачные пуски"]->HeaderCell->Style->Alignment = DataGridViewContentAlignment::MiddleRight;
	this->dataGridView1->Columns["Ќеудачные пуски"]->DefaultCellStyle->Alignment = DataGridViewContentAlignment::MiddleRight;

	fscanf(in, "%d", &NC);
	companies = new z[NC];

	for (int i = 0; i < NC; i++)
	{
		fscanf(in, "%s%s%d%d%d",
			companies[i].companyName,
			companies[i].rocketName,
			&companies[i].pricePerLaunch,
			&companies[i].successfulFlights,
			&companies[i].failureFlights);

		Table1->Rows->Add();
		s = gcnew String(companies[i].companyName);
		Table1->Rows[i][0] = s;
		s = gcnew String(companies[i].rocketName);
		Table1->Rows[i][1] = s;
		Table1->Rows[i][2] = companies[i].pricePerLaunch;
		Table1->Rows[i][3] = companies[i].successfulFlights;
		Table1->Rows[i][4] = companies[i].failureFlights;
	}

	fclose(in);
}
private: System::Void среднеејрифметическое”спешных«апусковToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	int totalFlights = 0;
	char ss[30];
	String^ s;

	for (int i = 0; i < NC; i++)
		totalFlights += companies[i].successfulFlights;

	sprintf(ss, "%.3f", (float)totalFlights / NC);
	s = gcnew String(ss);

	MessageBox::Show(s, "—реднее арифметическое успешных запусков", MessageBoxButtons::OK, MessageBoxIcon::Information);
}
private: System::Void кака€—ама€ƒешева€–акетаƒл€«апускаToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	struct z cheapest = companies[0];
	int minPrice = cheapest.pricePerLaunch;
	String^ s;
	char ss[100];

	for (int i = 1; i < NC; i++)
	{
		if (companies[i].pricePerLaunch < minPrice)
		{
			cheapest = companies[i];
			minPrice = cheapest.pricePerLaunch;
		}
	}

	sprintf(ss, "»м€: %s\n омпани€: %s\n—тоимость запуска в миллионах $: %d", 
		cheapest.rocketName, 
		cheapest.companyName, 
		cheapest.pricePerLaunch);
	s = gcnew String(ss);

	MessageBox::Show(s, "—ама€ дешева€ ракета дл€ запуска", MessageBoxButtons::OK, MessageBoxIcon::Information);
}
private: System::Void естьЋиќдинакова€÷ена«апуска”–азных омпанийToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	bool isSamePrice = false;
	String^ s;
	char ss[100];

	for (int i = 0; i < NC; i++)
	{
		for (int j = i + 1; j < NC; j++)
		{
			if (companies[i].pricePerLaunch == companies[j].pricePerLaunch) {
				isSamePrice = true;
				sprintf(ss, "%s (%dM$) = %s (%dM$)", 
					companies[i].rocketName, 
					companies[i].pricePerLaunch, 
					companies[j].rocketName, 
					companies[j].pricePerLaunch);
				s = gcnew String(ss);

				MessageBox::Show(s, "—овпадени€ есть!", MessageBoxButtons::OK, MessageBoxIcon::Information);
				break;
			}
		}
		if (isSamePrice)
			break;
	}

	if (!isSamePrice)
		MessageBox::Show("—овпадений нет!", "ќшибка!", MessageBoxButtons::OK, MessageBoxIcon::Error);
}
private: System::Void размах–€да÷еныToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	int minPrice = companies[0].pricePerLaunch;
	int maxPrice = minPrice;
	String^ s;
	char ss[20];

	for (int i = 1; i < NC; i++)
	{
		if (companies[i].pricePerLaunch < minPrice)
			minPrice = companies[i].pricePerLaunch;

		if (companies[i].pricePerLaunch > maxPrice)
			maxPrice = companies[i].pricePerLaunch;
	}

	sprintf(ss, "%d", (maxPrice - minPrice));
	s = gcnew String(ss);

	MessageBox::Show(s, "–азмах р€да цены в миллионах $", MessageBoxButtons::OK, MessageBoxIcon::Information);
}
private: System::Void алфавитный—писок¬сех омпанийToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	int i = 0;
	struct sp* nt, * z;
	String^ s;
	char ss[100];

	tabControl1->SelectTab(1);

	if (!spisok)
		for (int i = 0; i < NC; i++)
			vstavka(companies, companies[i].companyName);

	richTextBox1->ReadOnly = 1;
	richTextBox1->Clear();
	richTextBox1->Text = "јлфавитный список ј->я";
	richTextBox1->Text = richTextBox1->Text + "\n----------------------------";

	for (nt = spisok; nt != 0; nt = nt->sled)
	{
		sprintf(ss, "%-20s %-10d", nt->companyName, nt->successfulFlights);
		s = gcnew String(ss, 0, 31);
		richTextBox1->Text = richTextBox1->Text + "\n" + s;
	}

	richTextBox1->Text = richTextBox1->Text + "\n\n\nјлфавитный список я->ј";
	richTextBox1->Text = richTextBox1->Text + "\n----------------------------";

	for (z = 0, nt = spisok; nt != 0; z = nt, nt = nt->sled);
	for (nt = z; nt != 0; nt = nt->pred)
	{
		sprintf(ss, "%-20s %-10d", nt->companyName, nt->successfulFlights);
		s = gcnew String(ss, 0, 31);
		richTextBox1->Text = richTextBox1->Text + "\n" + s;
	}
}
private: System::Void listBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void диаграммаѕроцентное—оотношение¬сех«апусков аждой омпанииToolStripMenuItem_Click(System::Object^ sender,
	System::EventArgs^ e) {
	tabControl1->SelectTab(2);
}
private: System::Void tabPage3_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void tabPage3_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	Pen^ myPen = gcnew Pen(System::Drawing::Color::Black, 3);
	SolidBrush^ myBrush = gcnew SolidBrush(Color::FromArgb(196, 0, 0, 0));
	System::Drawing::Font^ myFont = gcnew System::Drawing::Font("Courier New Regular", 10);

	int i, K = 0;
	int iRed, iGreen, iBlue;
	int aStart, aEnd;
	long flights = 0;
	float xPos, yPos;
	struct sp* nt;

	Graphics^ g = tabPage3->CreateGraphics();
	g->Clear(System::Drawing::Color::Silver);

	if (!spisok)
		for (i = 0; i < NC; i++)
			vstavka(companies, companies[i].companyName);

	for (nt = spisok; nt != 0; nt = nt->sled)
	{
		K++;
		flights += nt->successfulFlights;
	}

	g->DrawEllipse(myPen, 25, 25, 185, 185);
	aEnd = 0;

	for (nt = spisok, i = 0; nt != 0; nt = nt->sled, i++)
	{
		iRed = (((i + 1) & 4) > 0) * 255 / (i / 8 + 1);
		iGreen = (((i + 1) & 2) > 0) * 255 / (i / 8 + 1);
		iBlue = (((i + 1) & 1) > 0) * 255 / (i / 8 + 1);
		aStart = aEnd;
		aEnd += nt->successfulFlights * 360 / flights;
		if (i == K - 1)
			aEnd = 360;

		myBrush->Color::set(Color::FromArgb(196, iRed, iGreen, iBlue));
		g->FillPie(myBrush, 25, 25, 185, 185, aStart, aEnd - aStart);
		g->FillRectangle(myBrush, 300, 50 + (i - 1) * 20, 20, 20);

		myBrush->Color::set(Color::FromArgb(196, 0, 0, 0));
		xPos = 30 + (185 - 25) / 2 + (185 - 25) / 1.5 * Math::Cos(Math::PI * (aStart + aEnd) / 360);
		yPos = 30 + (185 - 25) / 2 + (185 - 25) / 1.5 * Math::Sin(Math::PI * (aStart + aEnd) / 360);

		g->DrawString(gcnew String(nt->companyName), myFont, myBrush, 320, 55 + (i - 1) * 20);
		g->DrawString(Convert::ToString(nt->successfulFlights * 100 / flights) + "%", myFont, myBrush, xPos, yPos);
	}
}
private: System::Void openFileDialog1_FileOk(System::Object^ sender, System::ComponentModel::CancelEventArgs^ e) {
}
private: System::Void число омпаний” оторых„ислоѕровальныхѕусковћеньше„емToolStripMenuItem_Click(System::Object^ sender,
	System::EventArgs^ e) {
	MyForm2^ form2 = gcnew MyForm2();
	form2->ShowDialog();
	
	int failureFlights = System::Convert::ToInt32(form2->a);
	int counter = 0;

	for (int i = 0; i < NC; i++) 
		if (companies[i].failureFlights < failureFlights)
			counter++;
	
	char answer[20];
	char title[100];
	sprintf(answer, "%d", counter);
	sprintf(title, " ол-во компаний, число провальных пусков меньше, чем %d", failureFlights);
	String^ sAnswer = gcnew String(answer);
	String^ sTitle = gcnew String(title);
	MessageBox::Show(sAnswer, sTitle, MessageBoxButtons::OK, MessageBoxIcon::Information);
}
};
}

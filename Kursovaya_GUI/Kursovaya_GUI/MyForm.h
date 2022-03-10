#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>

namespace KursovayaGUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

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

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{

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
	private: System::Windows::Forms::ToolStripMenuItem^ ����ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ �������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ���������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ �������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ �����ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ �������������������������������������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ���������������������������������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ���������������������������������������������XToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ������������������������������������������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ����������������������������ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ��������������������������������������������������������ToolStripMenuItem;
	private: System::Windows::Forms::TabControl^ tabControl1;
	private: System::Windows::Forms::TabPage^ tabPage1;
	private: System::Windows::Forms::TabPage^ tabPage2;
	private: System::Windows::Forms::ListBox^ listBox1;
	private: System::Windows::Forms::RichTextBox^ richTextBox1;
	private: System::Windows::Forms::TabPage^ tabPage3;
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
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->����ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->���������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�������������������������������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->���������������������������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->���������������������������������������������XToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->������������������������������������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->����������������������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->��������������������������������������������������������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�����ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->tabPage3 = (gcnew System::Windows::Forms::TabPage());
			this->menuStrip1->SuspendLayout();
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->tabPage2->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->����ToolStripMenuItem,
					this->�������ToolStripMenuItem, this->�����ToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1256, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// ����ToolStripMenuItem
			// 
			this->����ToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->�������ToolStripMenuItem,
					this->���������ToolStripMenuItem
			});
			this->����ToolStripMenuItem->Name = L"����ToolStripMenuItem";
			this->����ToolStripMenuItem->Size = System::Drawing::Size(48, 20);
			this->����ToolStripMenuItem->Text = L"����";
			// 
			// �������ToolStripMenuItem
			// 
			this->�������ToolStripMenuItem->Name = L"�������ToolStripMenuItem";
			this->�������ToolStripMenuItem->Size = System::Drawing::Size(135, 22);
			this->�������ToolStripMenuItem->Text = L"�������";
			this->�������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::�������ToolStripMenuItem_Click);
			// 
			// ���������ToolStripMenuItem
			// 
			this->���������ToolStripMenuItem->Name = L"���������ToolStripMenuItem";
			this->���������ToolStripMenuItem->Size = System::Drawing::Size(135, 22);
			this->���������ToolStripMenuItem->Text = L"���������";
			this->���������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::���������ToolStripMenuItem_Click);
			// 
			// �������ToolStripMenuItem
			// 
			this->�������ToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(6) {
				this->�������������������������������������ToolStripMenuItem,
					this->���������������������������������ToolStripMenuItem, this->���������������������������������������������XToolStripMenuItem,
					this->������������������������������������������ToolStripMenuItem, this->����������������������������ToolStripMenuItem, this->��������������������������������������������������������ToolStripMenuItem
			});
			this->�������ToolStripMenuItem->Enabled = false;
			this->�������ToolStripMenuItem->Name = L"�������ToolStripMenuItem";
			this->�������ToolStripMenuItem->Size = System::Drawing::Size(69, 20);
			this->�������ToolStripMenuItem->Text = L"�������";
			// 
			// �������������������������������������ToolStripMenuItem
			// 
			this->�������������������������������������ToolStripMenuItem->Name = L"�������������������������������������ToolStripMenuItem";
			this->�������������������������������������ToolStripMenuItem->Size = System::Drawing::Size(472, 22);
			this->�������������������������������������ToolStripMenuItem->Text = L"������� �������������� �������� ��������\? ";
			this->�������������������������������������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::�������������������������������������ToolStripMenuItem_Click);
			// 
			// ���������������������������������ToolStripMenuItem
			// 
			this->���������������������������������ToolStripMenuItem->Name = L"���������������������������������ToolStripMenuItem";
			this->���������������������������������ToolStripMenuItem->Size = System::Drawing::Size(472, 22);
			this->���������������������������������ToolStripMenuItem->Text = L"����� ����� ������� ������ ��� �������\? ";
			this->���������������������������������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::���������������������������������ToolStripMenuItem_Click);
			// 
			// ���������������������������������������������XToolStripMenuItem
			// 
			this->���������������������������������������������XToolStripMenuItem->Name = L"���������������������������������������������XToolStripMenuItem";
			this->���������������������������������������������XToolStripMenuItem->Size = System::Drawing::Size(472, 22);
			this->���������������������������������������������XToolStripMenuItem->Text = L"������ �����, � ������� ����� ������� �������� ������ X";
			this->���������������������������������������������XToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::���������������������������������������������XToolStripMenuItem_Click);
			// 
			// ������������������������������������������ToolStripMenuItem
			// 
			this->������������������������������������������ToolStripMenuItem->Name = L"������������������������������������������ToolStripMenuItem";
			this->������������������������������������������ToolStripMenuItem->Size = System::Drawing::Size(472, 22);
			this->������������������������������������������ToolStripMenuItem->Text = L"���� �� ���������� ���� ������� � ������ ��������\?";
			this->������������������������������������������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::������������������������������������������ToolStripMenuItem_Click);
			// 
			// ����������������������������ToolStripMenuItem
			// 
			this->����������������������������ToolStripMenuItem->Name = L"����������������������������ToolStripMenuItem";
			this->����������������������������ToolStripMenuItem->Size = System::Drawing::Size(472, 22);
			this->����������������������������ToolStripMenuItem->Text = L"���������� ������ ���� ��������";
			this->����������������������������ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::����������������������������ToolStripMenuItem_Click);
			// 
			// ��������������������������������������������������������ToolStripMenuItem
			// 
			this->��������������������������������������������������������ToolStripMenuItem->Name = L"��������������������������������������������������������ToolStripMenuItem";
			this->��������������������������������������������������������ToolStripMenuItem->Size = System::Drawing::Size(472, 22);
			this->��������������������������������������������������������ToolStripMenuItem->Text = L"���������. ���������� ����������� ���� �������� ������ ��������";
			// 
			// �����ToolStripMenuItem
			// 
			this->�����ToolStripMenuItem->Name = L"�����ToolStripMenuItem";
			this->�����ToolStripMenuItem->Size = System::Drawing::Size(54, 20);
			this->�����ToolStripMenuItem->Text = L"�����";
			this->�����ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::�����ToolStripMenuItem_Click);
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Controls->Add(this->tabPage3);
			this->tabControl1->Location = System::Drawing::Point(0, 27);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(1256, 706);
			this->tabControl1->TabIndex = 1;
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->listBox1);
			this->tabPage1->Location = System::Drawing::Point(4, 22);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(1248, 680);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"�������� ������";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// listBox1
			// 
			this->listBox1->Font = (gcnew System::Drawing::Font(L"Courier New", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->listBox1->FormattingEnabled = true;
			this->listBox1->ItemHeight = 17;
			this->listBox1->Location = System::Drawing::Point(0, 0);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(1248, 684);
			this->listBox1->TabIndex = 0;
			this->listBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::listBox1_SelectedIndexChanged);
			// 
			// tabPage2
			// 
			this->tabPage2->Controls->Add(this->richTextBox1);
			this->tabPage2->Location = System::Drawing::Point(4, 22);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(1248, 680);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"������";
			this->tabPage2->UseVisualStyleBackColor = true;
			this->tabPage2->Click += gcnew System::EventHandler(this, &MyForm::tabPage2_Click);
			// 
			// richTextBox1
			// 
			this->richTextBox1->Font = (gcnew System::Drawing::Font(L"Courier New", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->richTextBox1->Location = System::Drawing::Point(0, 0);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(1252, 688);
			this->richTextBox1->TabIndex = 0;
			this->richTextBox1->Text = L"";
			// 
			// tabPage3
			// 
			this->tabPage3->Location = System::Drawing::Point(4, 22);
			this->tabPage3->Name = L"tabPage3";
			this->tabPage3->Size = System::Drawing::Size(1248, 680);
			this->tabPage3->TabIndex = 2;
			this->tabPage3->Text = L"���������";
			this->tabPage3->UseVisualStyleBackColor = true;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1256, 735);
			this->Controls->Add(this->tabControl1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MyForm";
			this->Text = L"�������� GUI";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->tabPage2->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void ���������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
private: System::Void tabPage2_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void �����ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Close();
}
private: System::Void �������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	FILE* in;
	int i;
	char ctemp[80];
	char filePath[90] = "D:\\University\\�����\\������\\Kursovaya_GUI\\Kursovaya_GUI\\SpaceCompanies.dat";
	String^ s;

	if ((in = fopen(filePath, "r")) == NULL)
	{
		MessageBox::Show("���� �� ������!", "������!", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}

	�������ToolStripMenuItem->Enabled = true;
	listBox1->Items->Clear();

	fscanf(in, "%d", &NC);
	companies = new z[NC];

	sprintf(ctemp, "%-20s %-20s %-15s %-15s %-10s",
		"��������",
		"������",
		"��������� � M$",
		"������� �����",
		"��������� �����");
	s = gcnew String(ctemp);
	listBox1->Items->Add(s);

	char separator[95];
	memset(separator, '-', 91);
	separator[91] = 0;
	s = gcnew String(separator);
	listBox1->Items->Add(s);

	for (i = 0; i < NC; i++)
	{
		fscanf(in, "%s%s%d%d%d",
			companies[i].companyName,
			companies[i].rocketName,
			&companies[i].pricePerLaunch,
			&companies[i].successfulFlights,
			&companies[i].failureFlights);
		sprintf(ctemp, "%-20s %-20s %-15d %-15d %-10d", 
			companies[i].companyName,
			companies[i].rocketName,
			companies[i].pricePerLaunch,
			companies[i].successfulFlights,
			companies[i].failureFlights);

		s = gcnew String(ctemp);
		listBox1->Items->Add(s);
	}

	fclose(in);
}
private: System::Void �������������������������������������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	int totalFlights = 0;
	char ss[30];
	String^ s;

	for (int i = 0; i < NC; i++)
		totalFlights += companies[i].successfulFlights;

	sprintf(ss, "%.3f", (float)totalFlights / NC);
	s = gcnew String(ss);

	MessageBox::Show(s, "������� �������������� �������� ��������");
}
private: System::Void ���������������������������������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
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

	sprintf(ss, "���: %s\n��������: %s\n��������� ������� � ��������� $: %d", 
		cheapest.rocketName, 
		cheapest.companyName, 
		cheapest.pricePerLaunch);
	s = gcnew String(ss);

	MessageBox::Show(s, "����� ������� ������ ��� �������");
}
private: System::Void ������������������������������������������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
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

				MessageBox::Show(s, "���������� ����!");
				break;
			}
		}
		if (isSamePrice)
			break;
	}

	if (!isSamePrice)
		MessageBox::Show("���������� ���!");
}
private: System::Void ���������������������������������������������XToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	
}
private: System::Void ����������������������������ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
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
	richTextBox1->Text = "���������� ������ �->�";
	richTextBox1->Text = richTextBox1->Text + "\n----------------------------";

	for (nt = spisok; nt != 0; nt = nt->sled)
	{
		sprintf(ss, "%-20s %-10d", nt->companyName, nt->successfulFlights);
		s = gcnew String(ss, 0, 31);
		richTextBox1->Text = richTextBox1->Text + "\n" + s;
	}

	richTextBox1->Text = richTextBox1->Text + "\n\n���������� ������ �->�";
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
};
}

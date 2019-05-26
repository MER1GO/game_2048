#pragma once
#include "engine.h"
#include <fstream>
game process;

namespace CppCLRWinformsProjekt {
	
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Zusammenfassung für Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Konstruktorcode hier hinzufügen.
			//
		}

	protected:
		/// <summary>
		/// Verwendete Ressourcen bereinigen.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ menu_panel;
	protected:

	private: System::Windows::Forms::Label^ game_tag;
	private: System::Windows::Forms::Button^ start;

	private: System::Windows::Forms::Panel^ current_score_panel;
	private: System::Windows::Forms::Label^ Current_score_tag;
	private: System::Windows::Forms::Panel^ best_score_panel;
	private: System::Windows::Forms::Label^ best_score_tag;
	private: System::Windows::Forms::Label^ current_score;
	private: System::Windows::Forms::Label^ best_score;

	private: System::Windows::Forms::Panel^ game_field;
	private: System::Windows::Forms::Label^ game_over;
	private: bool playing = 0;
	private: bool started = 0;
	private: int best = best_score_read();
	protected:
	private:
		/// <summary>
		/// Erforderliche Designervariable.
		/// </summary>
		System::ComponentModel::Container ^components;
#pragma region Windows Form Designer generated code
		/// <summary>
		/// Erforderliche Methode für die Designerunterstützung.
		/// Der Inhalt der Methode darf nicht mit dem Code-Editor geändert werden.
		/// </summary>
		
		void InitializeComponent(void)
		{
			this->menu_panel = (gcnew System::Windows::Forms::Panel());
			this->best_score_panel = (gcnew System::Windows::Forms::Panel());
			this->best_score = (gcnew System::Windows::Forms::Label());
			this->best_score_tag = (gcnew System::Windows::Forms::Label());
			this->current_score_panel = (gcnew System::Windows::Forms::Panel());
			this->current_score = (gcnew System::Windows::Forms::Label());
			this->Current_score_tag = (gcnew System::Windows::Forms::Label());
			this->game_tag = (gcnew System::Windows::Forms::Label());
			this->start = (gcnew System::Windows::Forms::Button());
			this->game_field = (gcnew System::Windows::Forms::Panel());
			this->game_over = (gcnew System::Windows::Forms::Label());
			this->menu_panel->SuspendLayout();
			this->best_score_panel->SuspendLayout();
			this->current_score_panel->SuspendLayout();
			this->SuspendLayout();
			// 
			// menu_panel
			// 
			this->menu_panel->Controls->Add(this->best_score_panel);
			this->menu_panel->Controls->Add(this->current_score_panel);
			this->menu_panel->Controls->Add(this->game_tag);
			this->menu_panel->Location = System::Drawing::Point(-3, 0);
			this->menu_panel->Name = L"menu_panel";
			this->menu_panel->Size = System::Drawing::Size(269, 95);
			this->menu_panel->TabIndex = 0;
			// 
			// best_score_panel
			// 
			this->best_score_panel->BackColor = System::Drawing::Color::Transparent;
			this->best_score_panel->Controls->Add(this->best_score);
			this->best_score_panel->Controls->Add(this->best_score_tag);
			this->best_score_panel->Location = System::Drawing::Point(87, 58);
			this->best_score_panel->Name = L"best_score_panel";
			this->best_score_panel->Size = System::Drawing::Size(182, 30);
			this->best_score_panel->TabIndex = 2;
			// 
			// best_score
			// 
			this->best_score->AutoSize = true;
			this->best_score->Font = (gcnew System::Drawing::Font(L"Raleway Black", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->best_score->ForeColor = System::Drawing::Color::Purple;
			this->best_score->Location = System::Drawing::Point(93, 5);
			this->best_score->Name = L"best_score";
			this->best_score->Text = best_score_read().ToString();
			this->best_score->Size = System::Drawing::Size(0, 18);
			this->best_score->TabIndex = 1;
			// 
			// best_score_tag
			// 
			this->best_score_tag->AutoSize = true;
			this->best_score_tag->Font = (gcnew System::Drawing::Font(L"Raleway SemiBold", 8.999999F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->best_score_tag->Location = System::Drawing::Point(8, 8);
			this->best_score_tag->Name = L"best_score_tag";
			this->best_score_tag->Size = System::Drawing::Size(69, 14);
			this->best_score_tag->TabIndex = 0;
			this->best_score_tag->Text = L"Best score:";
			this->best_score_tag->TextAlign = System::Drawing::ContentAlignment::TopRight;
			// 
			// current_score_panel
			// 
			this->current_score_panel->BackColor = System::Drawing::Color::Transparent;
			this->current_score_panel->Controls->Add(this->current_score);
			this->current_score_panel->Controls->Add(this->Current_score_tag);
			this->current_score_panel->Location = System::Drawing::Point(87, 21);
			this->current_score_panel->Margin = System::Windows::Forms::Padding(0);
			this->current_score_panel->Name = L"current_score_panel";
			this->current_score_panel->Size = System::Drawing::Size(180, 34);
			this->current_score_panel->TabIndex = 1;
			// 
			// current_score
			// 
			this->current_score->AutoSize = true;
			this->current_score->BackColor = System::Drawing::Color::Transparent;
			this->current_score->Font = (gcnew System::Drawing::Font(L"Raleway Black", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->current_score->ForeColor = System::Drawing::Color::Purple;
			this->current_score->Location = System::Drawing::Point(93, 5);
			this->current_score->Name = L"current_score";
			this->current_score->Text = process.get_score().ToString();
			this->current_score->Size = System::Drawing::Size(0, 18);
			this->current_score->TabIndex = 1;
			// 
			// Current_score_tag
			// 
			this->Current_score_tag->AutoSize = true;
			this->Current_score_tag->BackColor = System::Drawing::Color::Transparent;
			this->Current_score_tag->Font = (gcnew System::Drawing::Font(L"Raleway SemiBold", 8.999999F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Current_score_tag->Location = System::Drawing::Point(8, 8);
			this->Current_score_tag->Name = L"Current_score_tag";
			this->Current_score_tag->Size = System::Drawing::Size(85, 14);
			this->Current_score_tag->TabIndex = 0;
			this->Current_score_tag->Text = L"Current score:";
			// 
			// game_tag
			// 
			this->game_tag->AutoSize = true;
			this->game_tag->BackColor = System::Drawing::Color::Transparent;
			this->game_tag->Font = (gcnew System::Drawing::Font(L"Raleway", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->game_tag->ForeColor = System::Drawing::Color::Purple;
			this->game_tag->Location = System::Drawing::Point(15, 43);
			this->game_tag->Name = L"game_tag";
			this->game_tag->Size = System::Drawing::Size(55, 22);
			this->game_tag->TabIndex = 0;
			this->game_tag->Text = L"2048";
			// 
			// start
			// 
			this->start->BackColor = System::Drawing::Color::Thistle;
			this->start->Cursor = System::Windows::Forms::Cursors::Hand;
			this->start->FlatAppearance->BorderColor = System::Drawing::Color::Purple;
			this->start->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->start->Font = (gcnew System::Drawing::Font(L"Raleway SemiBold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->start->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->start->Location = System::Drawing::Point(12, 106);
			this->start->Name = L"start";
			this->start->Size = System::Drawing::Size(89, 44);
			this->start->TabIndex = 1;
			this->start->Text = L"start";
			this->start->UseVisualStyleBackColor = false;
			this->start->Click += gcnew System::EventHandler(this, &Form1::Button1_Click);
			// 
			// game_field
			// 
			this->game_field->Location = System::Drawing::Point(24, 166);
			this->game_field->MaximumSize = System::Drawing::Size(215, 215);
			this->game_field->MinimumSize = System::Drawing::Size(215, 215);
			this->game_field->Name = L"game_field";
			this->game_field->Size = System::Drawing::Size(215, 215);
			this->game_field->TabIndex = 1;
			// 
			// game_over
			// 
			this->game_over->AutoSize = true;
			this->game_over->Font = (gcnew System::Drawing::Font(L"Raleway SemiBold", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->game_over->ForeColor = System::Drawing::Color::Purple;
			this->game_over->Location = System::Drawing::Point(123, 106);
			this->game_over->Name = L"game_over";
			this->game_over->Size = System::Drawing::Size(0, 22);
			this->game_over->TabIndex = 2;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(264, 411);
			this->Controls->Add(this->game_over);
			this->Controls->Add(this->game_field);
			this->Controls->Add(this->start);
			this->Controls->Add(this->menu_panel);
			this->KeyPreview = true;
			this->MaximumSize = System::Drawing::Size(280, 450);
			this->MinimumSize = System::Drawing::Size(280, 450);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &Form1::Form1_FormClosing);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::Form1_KeyDown);
			this->menu_panel->ResumeLayout(false);
			this->menu_panel->PerformLayout();
			this->best_score_panel->ResumeLayout(false);
			this->best_score_panel->PerformLayout();
			this->current_score_panel->ResumeLayout(false);
			this->current_score_panel->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}

		void best_score_write() {
			ofstream feof("highest.dat", ios::binary);
			feof << best;
			feof.close();
		}

		int best_score_read() {
			int rtn;
			ifstream fin("highest.dat", ios::binary);
			fin >> rtn;
			fin.close();
			return rtn;
		}

		void updatescore() {
			int curr = process.get_score();
			this->current_score->Text = curr.ToString();
			if (curr > best) {
				best = curr;
			}
			this->best_score->Text = best.ToString();
		}
		void Draw() {
			game_field->Refresh();
			System::Drawing::Font^ fnt = gcnew System::Drawing::Font(L"Raleway SemiBold", 12.0F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204));
			//Color ppl;
			Graphics^ g = game_field->CreateGraphics();
			StringFormat^ stringFormat = gcnew StringFormat();
			stringFormat->Alignment = StringAlignment::Center;
			stringFormat->LineAlignment = StringAlignment::Center;
			String^ str;
			SolidBrush^ penw;
			SolidBrush^ drawBrush = gcnew SolidBrush(Color::WhiteSmoke);		
			int x, y;
			int width = 50;
			int height = 50;
			Rectangle rect(x,y,width,height);
			for (size_t i(0); i < 4; i++) {
				for (size_t j(0); j < 4; j++) {
					if (process.matrix[i][j]) {
						str = process.matrix[i][j].ToString();
						x = j*55;
						y = i*55;
						rect.X = x;
						rect.Y = y;
						if (sqrts(process.matrix[i][j]) <= 10) {
							penw = gcnew SolidBrush(Color::FromArgb(256 / 10 * sqrts(process.matrix[i][j]), 102, 9, 161));
						}
						else if (sqrts(process.matrix[i][j]) == 11) {
							penw = gcnew SolidBrush(Color::FromArgb(100, 17, 128, 0));
						}
						else if (sqrts(process.matrix[i][j]) == 12) {
							penw = gcnew SolidBrush(Color::FromArgb(100, 237, 225, 0));
						}
						else {
							penw = gcnew SolidBrush(Color::FromArgb(100, 168, 0, 0));
						}
						
						g->FillRectangle(penw, rect);
						
						g->DrawString(str, fnt, drawBrush, rect, stringFormat);
					}
				}
			}
		}
		void check() {
			if (!process.can_move()) {
				Graphics^ g = game_field->CreateGraphics();
				SolidBrush^ br = gcnew SolidBrush(Color::FromArgb(20, 0, 0, 0));
				g->FillRectangle(br, 0, 0, game_field->Width, game_field->Height);
				this->game_over->Text = "Game over";
				playing = 0;
			}
		}
		void MoveRight() {
			process.move_right();
			updatescore();
			Draw();
			check();
		}
		void MoveLeft() {
			process.move_left();
			updatescore();
			Draw();
			check();
		}
		void MoveTop() {
			process.move_top();
			updatescore();
			Draw();
			check();
		}
		void MoveBottom() {
			process.move_bottom();
			updatescore();
			Draw();
			check();
		}
		
		

#pragma endregion
	
private: System::Void Button1_Click(System::Object^ sender, System::EventArgs^ e) {
	
	if (!playing) {
		best = best_score_read();
		playing = 1;
		this->game_over->Text = "";
		this->start->Text = "Restart";
	}
	process.restart();

	Draw();


	
}
private: System::Void Form1_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
	if (playing) {
		if (e->KeyCode == Keys::D || e->KeyCode == Keys::Right) {
			MoveRight();
		}
		else if (e->KeyCode == Keys::A || e->KeyCode == Keys::Left) {
			MoveLeft();
		}
		else if (e->KeyCode == Keys::W || e->KeyCode == Keys::Up) {
			MoveTop();
		}
		else if (e->KeyCode == Keys::S || e->KeyCode == Keys::Down) {
			MoveBottom();
		}
		else {

		}
	}
	
}
private: System::Void Form1_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
	if (best > best_score_read()) {
		best_score_write();
	}
}
};

}

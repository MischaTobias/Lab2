#pragma once
#include <random>
#include "Carrera.h"

namespace Lab2MischaTobias1170919 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;

	/// <summary>
	/// Resumen de MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Timer^ timer1;

	private: System::Windows::Forms::Button^ btnCrearCarrera;
	private: System::Windows::Forms::RichTextBox^ rTextBoxCarrera;
	protected:
	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->btnCrearCarrera = (gcnew System::Windows::Forms::Button());
			this->rTextBoxCarrera = (gcnew System::Windows::Forms::RichTextBox());
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Interval = 1000;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// btnCrearCarrera
			// 
			this->btnCrearCarrera->Location = System::Drawing::Point(12, 12);
			this->btnCrearCarrera->Name = L"btnCrearCarrera";
			this->btnCrearCarrera->Size = System::Drawing::Size(173, 36);
			this->btnCrearCarrera->TabIndex = 1;
			this->btnCrearCarrera->Text = L"Crear Carrera";
			this->btnCrearCarrera->UseVisualStyleBackColor = true;
			this->btnCrearCarrera->Click += gcnew System::EventHandler(this, &MyForm::btnCrearCarrera_Click);
			// 
			// rTextBoxCarrera
			// 
			this->rTextBoxCarrera->Location = System::Drawing::Point(221, 21);
			this->rTextBoxCarrera->Name = L"rTextBoxCarrera";
			this->rTextBoxCarrera->Size = System::Drawing::Size(447, 335);
			this->rTextBoxCarrera->TabIndex = 2;
			this->rTextBoxCarrera->Text = L"";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ControlDark;
			this->ClientSize = System::Drawing::Size(1055, 425);
			this->Controls->Add(this->rTextBoxCarrera);
			this->Controls->Add(this->btnCrearCarrera);
			this->Name = L"MyForm";
			this->Text = L"Liebre y Tortuga";
			this->ResumeLayout(false);

		}
#pragma endregion
	public: Carrera *c = new Carrera();
		  System::String^ car = "";
		  System::String^ car2 = "";
		  System::String^ carf = "";

	public: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		Random^ r = gcnew Random();
		int r1 = r->Next(0, 10);
		int r2 = r->Next(0, 10);
		if (c->posliebre < 70 && c->postortuga < 70) {
			c->impCarrera(r1, r2);
			carreraImp();
		}
		else {
			if (*c->pliebre == 1 && *c->ptortuga == 1) {
				rTextBoxCarrera->Text += "¡LA TORTUGA GANA! ¡BRAVO!";
			} else if (*c->ptortuga == 1) {
				rTextBoxCarrera->Text += "¡LA TORTUGA GANA! ¡BRAVO!";
			} else {
				rTextBoxCarrera->Text += "La liebre gana. Ni hablar";
			}

			timer1->Enabled = false;
		}
	}

	public: void carreraImp() {
		car = "";
		car2 = "";
		carf = "";
		for (int* i = &c->vliebre[0]; *i != -1; i++) {
			if (*i == 1) {
				car += "H";
			}
			else {
				car += "-";
			}
		}

		if (c->posliebre == 70) {
			car += "H";
		}
		else {
			car += "M";
		}

		for (int* i = &c->vtortuga[0]; *i != -1; i++) {
			if (*i == 1 && c->postortuga == c->posliebre) {
				car2 += "O";
			}
			else if (*i == 1) {
				car2 += "T";
			}
			else {
				car2 += "-";
			}
		}

		if (c->postortuga == 70) {
			car2 += "T";
		}
		else {
			car2 += "M";
		}


		for (int i = 0; i < 70; i++) {
			if (car[i] == 'H' && car2[i] == 'T') {
				carf += "¡OUCH!";
			}
			else if (car2[i] == 'T') {
				carf += "T";
			}
			else if (car[i] == 'H') {
				carf += "H";
			}
			else {
				carf += "-";
			}
		}
		rTextBoxCarrera->Text += carf + "\n";
	}

	public: System::Void btnCrearCarrera_Click(System::Object^ sender, System::EventArgs^ e) {
		//Generar carrera
		c = new Carrera();
		c->crearCarrera();
		timer1->Enabled = true;
		rTextBoxCarrera->Text = "¡BANG!\n" + "¡Y ARRANCAN!\n";
	}

	};
}

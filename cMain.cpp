#include "cMain.h"
#include "cApp.h"
#include "DATA.h"
#include <iostream>
#include <string>
#include <sstream>
#include "WX_STRING_TO_DOUBLE.h"

wxBEGIN_EVENT_TABLE(cMain, wxFrame)
EVT_BUTTON(1001, OnButtonClicked)
EVT_BUTTON(1001, OnButtonClicked_2) //segundo evento;
wxEND_EVENT_TABLE()


int LIMITE_TAMANHO_COMMONTEXT = 250; // TAMANHO MAXIMO TEXTOS
int LIMITE_ALTURA_COMMONTEXT = 30;
int SPACING = 10;  // ESPAÇAMENTO ENTRE TEXTO
int NUMERO_COLUNAS = 3;
int JANELA_LIMITE[2] = { LIMITE_TAMANHO_COMMONTEXT*NUMERO_COLUNAS + SPACING*NUMERO_COLUNAS, 500 };
int TXT_BOX_HEIGHT = 30;
int BSYZE = (50, 20);

void Convert_str_resize(wxString& text, double value, int houses);

cMain::cMain() :  wxFrame(nullptr, wxID_ANY, "Creative.com!", wxPoint(30,30), wxSize(JANELA_LIMITE[0], JANELA_LIMITE[1]))
{
	m_WelcomeText = new wxStaticText(this, wxID_ANY,"DADOS DA ESCADA: ", wxPoint(10, 10), wxSize(LIMITE_TAMANHO_COMMONTEXT, LIMITE_ALTURA_COMMONTEXT));
	m_button1 = new wxButton(this, 1001, "Load", wxPoint(115, 50), wxSize(50, 20));
	m_text1 = new wxTextCtrl(this, wxID_ANY, "", wxPoint(10, 50), wxSize(100,20));
	m_DescriptionText = new wxStaticText(this, wxID_ANY, "Informe o pé-esquerdo (altura) da escada em Centimetros ", wxPoint(10, 80), wxSize(350, 30));
}

cMain::~cMain()
{

}

void cMain::OnButtonClicked(wxCommandEvent& evt) // limit LT_WFR
{
	wxMessageBox("DONE!");
	
		double valor = 0; // intialization of a double to pass the value to Class DATA(16,17,18)

		wxString value = m_text1->GetValue();

	Convert_wxSTRING_TO_DOUBLE(value, valor);

		DATA16 DEFAULT(valor);

		m_text1 = new wxTextCtrl(this, wxID_ANY, "RELATÓRIO 01 (VALÓRES MÍNIMOS)", wxPoint(10, 150), wxSize(300, 30));
	m_DescriptionText2 = new wxStaticText(this, wxID_ANY, "Altura Informada da Escada: " + value + "cm ", wxPoint(10, 190), wxSize(300, 30));

		Convert_str_resize(value, DEFAULT.H_degree, 5);

	m_DescriptionText2 = new wxStaticText(this, wxID_ANY, "Altura do Degrau:  " + value + " cm", wxPoint(10, 230), wxSize(150, 30));

		Convert_str_resize(value, DEFAULT.B_degree, 5);

	m_DescriptionText2 = new wxStaticText(this, wxID_ANY, "Base do Degrau:  " + value + " cm", wxPoint(10, 270), wxSize(140, 30));

		Convert_str_resize(value, DEFAULT.COMPLEMENT_Blondel + DEFAULT.B_degree, 5);

	m_DescriptionText2 = new wxStaticText(this, wxID_ANY, " - " + value + "cm", wxPoint(150, 270), wxSize(150, 30));

	m_DescriptionText2 = new wxStaticText(this, wxID_ANY, "Constante de Blondel: Entre 63 - 64", wxPoint(10, 310), wxSize(220, 30)); // Melhorar 

	m_button2 = new wxButton(this, 1002, "Next >>", wxPoint(400, 400), wxSize(60, 30));

	evt.Skip();
}

void cMain::OnButtonClicked_2(wxCommandEvent& evt) 
{
	//delete[]m_DescriptionText2; CONFIGURAR MELHOR

	double valor = 0; // intialization of a double to pass the value to Class DATA(16,17,18)

	wxString value = m_text1->GetValue();

		Convert_wxSTRING_TO_DOUBLE(value, valor);

		
	DATA17 DEFAULT(valor);

	m_DescriptionText3 = new wxStaticText(this, wxID_ANY, "RELATÓRIO 02 (VALÓRES MÉDIOS)", wxPoint(350+10, 150), wxSize(350, 30));
	m_DescriptionText3 = new wxStaticText(this, wxID_ANY, "Altura Informada da Escada: " + value + "cm ", wxPoint(350+10, 190), wxSize(350, 30));

		Convert_str_resize(value, DEFAULT.H_degree, 5);

	m_DescriptionText3 = new wxStaticText(this, wxID_ANY, "Altura do Degrau:  " + value + " cm", wxPoint(350+10, 230), wxSize(350, 30));

		Convert_str_resize(value, DEFAULT.B_degree, 5);

	m_DescriptionText3 = new wxStaticText(this, wxID_ANY, "Base do Degrau:  " + value + " cm", wxPoint(350+10, 270), wxSize(350, 30));

		Convert_str_resize(value, DEFAULT.Blondel, 2);

	m_DescriptionText3 = new wxStaticText(this, wxID_ANY, "Constante de Blondel:  " + value, wxPoint(350+10, 310), wxSize(350, 30));

	//m_button3 = new wxButton(this, 1002, "Next >>", wxPoint(400, 400), wxSize(60, 30));

	evt.Skip();
}

void Convert_str_resize(wxString& text, double value, int houses)
{
	text = std::to_string(value);
	text.resize(houses);
}



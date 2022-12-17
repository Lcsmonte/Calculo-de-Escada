#pragma once
#include "wx/wx.h"


class cMain : public wxFrame
{
public:
	cMain();
	~cMain();

public:
	
	wxButton* m_button1 = nullptr;
	wxButton* m_button2 = nullptr;
	wxButton* m_button3 = nullptr;
	wxTextCtrl* m_text1 = nullptr;
	wxListBox* m_list1 = nullptr;
	wxString m_string1;
	wxString m_string2;
	wxString m_string3;
	wxString m_string4;
	wxString m_string5;

public:
	
	wxStaticText* m_WelcomeText = nullptr;
	wxStaticText* m_DescriptionText = nullptr;
	wxStaticText* m_DescriptionText2 = nullptr;
	wxStaticText* m_DescriptionText3 = nullptr;
	wxStaticText* m_DescriptionText4 = nullptr;
	wxStaticText* m_DescriptionText5 = nullptr;
	wxStaticText* m_DescriptionText6 = nullptr;

	void OnButtonClicked(wxCommandEvent& evt);
	void OnButtonClicked_2(wxCommandEvent& evt);

	wxDECLARE_EVENT_TABLE();

};


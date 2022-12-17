#pragma once
#include <sstream>
#include <iostream>
#include "wx/wx.h"


void Convert_wxSTRING_TO_DOUBLE(wxString& text, double& value)
{
	std::stringstream sS;
	sS << text; // conversão Stringstream
	sS >> value;
}
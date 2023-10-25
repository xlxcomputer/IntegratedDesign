// draw_arrow.cpp
#include "draw_arrow.h"
#include <cmath>

MyFrame::MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
	:wxFrame(NULL, wxID_ANY, title, pos, size)
{
	SetBackgroundColour(*wxWHITE);
}

//绘制箭头，接受起点终点坐标、粗细、颜色
void MyFrame::DrawArrow(int x1, int x2, int y1, int y2, int borderWidth, const wxColour& penColor)
{
	wxClientDC dc(this);
	dc.SetPen(wxPen(penColor, borderWidth, wxPENSTYLE_SOLID));

	dc.DrawLine(x1, y1, x2, y2);
	double x3 = x2 - (x2 - x1) / 5;
	double y3 = y2 - (y2 - y1) / 5;
	double x4, y4, x5, y5;
	double length = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2)) / 7;
	
	if (x1 == x2)
	{
		y4 = y5 = y3;
		x4 = x3 - length;
		x5 = x3 + length;
	}
	else if (y1 == y2)
	{
		x4 = x5 = x3;
		y4 = y3 + length;
		y5 = y3 - length;
	}
	else
	{
		double k0 = (x2 - x1) / (y2 - y1);
		double k = -1 / k0;

		double angle = std::atan(k);
		x4 = x3 + length * std::cos(angle);
		y4 = y3 + length * std::sin(angle);
		x5 = 2 * x3 - x4;
		y5 = 2 * y3 - y4;
	}
	dc.DrawLine(x2, y2, x4, y4);
	dc.DrawLine(x2, y2, x5, y5);
}

//绘制箭头，仅提供起点和终点坐标
void MyFrame::DrawArrow(int x1, int x2, int y1, int y2)
{
	DrawArrow(x1, y1, x2, y2, 3, *wxBLACK);
}

void MyFrame::DrawArrow(int x1, int x2, int y1, int y2, int borderWidth)
{
	DrawArrow(x1, y1, x2, y2, borderWidth, *wxBLACK);
}

void MyFrame::DrawArrow(int x1, int x2, int y1, int y2, const wxColour& penColor)
{
	DrawArrow(x1, y1, x2, y2, 3, penColor);
}

wxBEGIN_EVENT_TABLE(MyFrame, wxFrame)

wxEND_EVENT_TABLE()
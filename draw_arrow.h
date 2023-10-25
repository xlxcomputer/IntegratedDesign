//draw_arrow.h

#ifndef DRAW_ARROW_H
#define DRAW_ARROW_H

#include <wx/wx.h>

class MyFrame : public wxFrame
{
public:
	MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size);

	void DrawArrow(int x1, int x2, int y1, int y2);
	void DrawArrow(int x1, int x2, int y1, int y2, int borderWidth);
	void DrawArrow(int x1, int x2, int y1, int y2, const wxColor& penColor);
	void DrawArrow(int x1, int x2, int y1, int y2, int borderWidth, const wxColor& penColor);
	
private:
	void OnPaint(wxPaintEvent& event);
	wxDECLARE_EVENT_TABLE();
};

#endif
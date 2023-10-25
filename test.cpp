#include "draw_symbol.h"
#include <wx/wx.h>

class MyApp : public wxApp
{
public:
	virtual bool OnInit();
};

bool MyApp::OnInit()
{
	MyFrame* frame = new MyFrame("draw_symbol", wxPoint(50, 50), wxSize(800, 600));
	frame->Show(true);

	frame->Draw_usb(50, 100);
	frame->Draw_led(300, 300);
	return true;
}

IMPLEMENT_APP(MyApp)
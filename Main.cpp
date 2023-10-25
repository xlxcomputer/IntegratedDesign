#include <wx/wx.h>

class MyApp : public wxApp
{
public:
	virtual bool OnInit();
};

class MyFrame : public wxFrame
{
public:
	MyFrame(const wxString& title);
	void OnQuit(wxCommandEvent& event);
	void OnAbout(wxCommandEvent& event);

private:
	DECLARE_EVENT_TABLE()
};

BEGIN_EVENT_TABLE(MyFrame, wxFrame)
EVT_MENU(wxID_ABOUT, MyFrame::OnAbout)
EVT_MENU(wxID_EXIT, MyFrame::OnQuit)
END_EVENT_TABLE()


bool MyApp::OnInit()
{
	MyFrame* frame = new MyFrame(wxT("Minimal wx App"));
	frame->Show(true);

	return true;
}

void MyFrame::OnAbout(wxCommandEvent& event)
{
	wxString msg;
	msg.Printf(wxT("Hello and welcome to % s"),
		wxVERSION_STRING);
	wxMessageBox(msg, wxT("About Minimal"),
		wxOK | wxICON_INFORMATION, this);
}

void MyFrame::OnQuit(wxCommandEvent& event)
{
	Close();
}

MyFrame::MyFrame(const wxString& title) : wxFrame(NULL, wxID_ANY, title)
{
	wxMenu* fileMenu = new wxMenu;
	wxMenu* helpMenu = new wxMenu;
	helpMenu->Append(wxID_ABOUT, wxT("&About...\tF1"), wxT("Show about dialog"));
	fileMenu->Append(wxID_EXIT, wxT("&Exit\tAlt-X"), wxT("Quit this program"));

	wxMenuBar* menuBar = new wxMenuBar;
	menuBar->Append(fileMenu, wxT("&File"));
	menuBar->Append(helpMenu, wxT("&Help"));

	SetMenuBar(menuBar);

	CreateStatusBar(2); //显示在页面下方，鼠标悬停时出现
	SetStatusText(wxT("Welcome to wxWidget!"));
}

DECLARE_APP(MyApp)
IMPLEMENT_APP(MyApp)
#include <wx/wx.h>
#include <wx/dcclient.h>
#include <wx/graphics.h>
#include <wx/dcbuffer.h>

// �Զ�����������εĺ���
void DrawTriangle(wxDC& dc, int x1, int y1, int x2, int y2, int x3, int y3)
{
    dc.DrawLine(x1, y1, x2, y2);
    dc.DrawLine(x2, y2, x3, y3);
    dc.DrawLine(x3, y3, x1, y1);
}

class MyFrame : public wxFrame
{
public:
    MyFrame(const wxString& title)
        : wxFrame(NULL, wxID_ANY, title)
    {
        SetBackgroundStyle(wxBG_STYLE_CUSTOM);
        Bind(wxEVT_PAINT, &MyFrame::OnPaint, this);
    }

private:
    void OnPaint(wxPaintEvent& event)
    {
        wxPaintDC dc(this);
        wxBufferedPaintDC bpdc(this);
        wxGraphicsContext* gc = wxGraphicsContext::Create(bpdc);

        // ������ת�Ƕȣ���λ�����ȣ�
        double rotation_angle = wxDegToRad(45);

        // ���Ƶ�һ��������
        DrawTriangle(dc, 50, 50, 100, 100, 150, 50);

        // ���Ƶڶ���������
        DrawTriangle(dc, 200, 50, 250, 100, 300, 50);

        // Ӧ����ת�任
        gc->Rotate(rotation_angle);

        // ��������ͼ��
        DrawTriangle(dc, 50, 200, 100, 250, 150, 200);
        DrawTriangle(dc, 200, 200, 250, 250, 300, 200);

        delete gc;
    }
};

class MyApp : public wxApp
{
public:
    virtual bool OnInit()
    {
        MyFrame* frame = new MyFrame("Vector Graphics Demo");
        frame->Show(true);
        return true;
    }
};

wxIMPLEMENT_APP(MyApp);
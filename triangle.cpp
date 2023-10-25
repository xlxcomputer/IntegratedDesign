#include <wx/wx.h>
#include <wx/dcclient.h>

class MyFrame : public wxFrame
{
public:
    MyFrame() : wxFrame(nullptr, wxID_ANY, "���Ƽ�ͷ")
    {
        // ע������¼�������
        Bind(wxEVT_PAINT, &MyFrame::OnPaint, this);
    }

    void OnPaint(wxPaintEvent& event)
    {
        // ������ͼ������
        wxPaintDC dc(this);

        // ���������ɫ
        dc.SetBrush(wxBrush(wxColour(255, 0, 0))); // ��ɫ���

        // ��ͷ����ʼ�ͽ���������
        wxPoint start(100, 100);
        wxPoint end(300, 200);

        // �����ͷ�ĳ��ȺͽǶ�
        double length = sqrt(pow(end.x - start.x, 2) + pow(end.y - start.y, 2));
        double angle = atan2(end.y - start.y, end.x - start.x);

        // ��ͷ�ĳ��ȺͿ��
        double arrowLength = 20; // ��ͷ����
        double arrowWidth = 10;  // ��ͷ���

        // �����ͷβ����ͷ��������
        wxPoint tail, head;
        head.x = end.x - arrowLength * cos(angle);
        head.y = end.y - arrowLength * sin(angle);
        tail.x = head.x - arrowWidth * sin(angle);
        tail.y = head.y + arrowWidth * cos(angle);

        // ���Ƽ�ͷ
        dc.DrawLine(start, end);
        dc.DrawLine(head, wxPoint(head.x + arrowWidth * sin(angle + M_PI / 2.0), head.y - arrowWidth * cos(angle + M_PI / 2.0)));
        dc.DrawLine(head, wxPoint(head.x - arrowWidth * sin(angle + M_PI / 2.0), head.y + arrowWidth * cos(angle + M_PI / 2.0)));
        dc.DrawPolygon(3, new wxPoint[3]{ start, wxPoint(tail.x + arrowWidth * sin(angle), tail.y - arrowWidth * cos(angle)),
                                           wxPoint(tail.x - arrowWidth * sin(angle), tail.y + arrowWidth * cos(angle)) });

    }
};

class MyApp : public wxApp
{
public:
    bool OnInit() override
    {
        // ����������
        MyFrame* frame = new MyFrame();
        frame->Show();

        return true;
    }
};

wxIMPLEMENT_APP(MyApp);
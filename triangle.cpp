#include <wx/wx.h>
#include <wx/dcclient.h>

class MyFrame : public wxFrame
{
public:
    MyFrame() : wxFrame(nullptr, wxID_ANY, "绘制箭头")
    {
        // 注册绘制事件处理函数
        Bind(wxEVT_PAINT, &MyFrame::OnPaint, this);
    }

    void OnPaint(wxPaintEvent& event)
    {
        // 创建绘图上下文
        wxPaintDC dc(this);

        // 设置填充颜色
        dc.SetBrush(wxBrush(wxColour(255, 0, 0))); // 红色填充

        // 箭头的起始和结束点坐标
        wxPoint start(100, 100);
        wxPoint end(300, 200);

        // 计算箭头的长度和角度
        double length = sqrt(pow(end.x - start.x, 2) + pow(end.y - start.y, 2));
        double angle = atan2(end.y - start.y, end.x - start.x);

        // 箭头的长度和宽度
        double arrowLength = 20; // 箭头长度
        double arrowWidth = 10;  // 箭头宽度

        // 计算箭头尾部和头部的坐标
        wxPoint tail, head;
        head.x = end.x - arrowLength * cos(angle);
        head.y = end.y - arrowLength * sin(angle);
        tail.x = head.x - arrowWidth * sin(angle);
        tail.y = head.y + arrowWidth * cos(angle);

        // 绘制箭头
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
        // 创建主窗口
        MyFrame* frame = new MyFrame();
        frame->Show();

        return true;
    }
};

wxIMPLEMENT_APP(MyApp);
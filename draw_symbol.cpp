//draw_symbol.cpp
#include "draw_symbol.h"
#include <wx/wx.h>

MyFrame::MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
	:wxFrame(NULL, wxID_ANY, title, pos, size)
{
	SetBackgroundColour(*wxWHITE);
}

//����ֱ�ߣ����ܶ˵����꣬������ɫ�ʹ�ϸ
void MyFrame::Draw_line(int x1, int y1, int x2, int y2, int width, const wxColour& penColor)
{
    wxClientDC dc(this);
    dc.SetPen(wxPen(penColor, width, wxPENSTYLE_SOLID));
    dc.DrawLine(x1, y1, x2, y2);
}

//����ֱ�ߣ����ܶ˵����꣬������ɫ
void MyFrame::Draw_line(int x1, int y1, int x2, int y2, const wxColour& penColor)
{
    Draw_line(x1, y1, x2, y2, 2, penColor);
}

//����ֱ�ߣ����ܶ˵����꣬������ϸ
void MyFrame::Draw_line(int x1, int y1, int x2, int y2, int width)
{
    Draw_line(x1, y1, x2, y2, width, *wxBLACK);
}

//����ֱ�ߣ�ֻ���ܶ˵�����
void MyFrame::Draw_line(int x1, int y1, int x2, int y2)
{
    Draw_line(x1, y1, x2, y2, 2, *wxBLACK);
}

void MyFrame::Draw_rect(int x1, int y1, int x2, int y2, const wxColour& color) {
    // ����һ�������ľ��Σ��������ñ߿���ɫ���߿���Ĭ��Ϊ1
    Draw_rect(x1, y1, x2, y2, color, 1, false, wxNullColour);
}

void MyFrame::Draw_rect(int x1, int y1, int x2, int y2, int width) {
    // ����һ�������ľ��Σ��������ñ߿���,�߿���ɫĬ��ΪwxColor(132, 0, 0)
    Draw_rect(x1, y1, x2, y2, wxColor(132, 0, 0), width, false, wxNullColour);
}

void MyFrame::Draw_rect(int x1, int y1, int x2, int y2, bool fill, const wxColour& color_in) {
    // ����һ�����Σ������Ƿ���Ҫ�����ѡ��ָ����ɫ
    Draw_rect(x1, y1, x2, y2, wxColor(132, 0, 0), 1, fill, color_in);
}

void MyFrame::Draw_rect(int x1, int y1, int x2, int y2, const wxColour& color, int width, bool fill, const wxColour& color_in) {
    // ����һ�����Σ������Ƿ���Ҫ��䡢ָ����ɫ�ͱ߿�����ѡ��
    wxClientDC dc(this);

    dc.SetPen(wxPen(color, width, wxPENSTYLE_SOLID)); // ������ɫ�Ϳ��

    if (fill) {
        dc.SetBrush(wxBrush(color_in)); // ���������ɫ
    }
    dc.DrawRectangle(x1, y1, x2 - x1, y2 - y1);
}

void MyFrame::Draw_triangle(int x1, int y1, int x2, int y2, int x3, int y3, const wxColour& color) {
    // ����һ�������������Σ��������ñ߿���ɫ���߿���Ĭ��Ϊ1
    Draw_triangle(x1, y1, x2, y2, x3, y3, color, 1, false, wxNullColour);
}

void MyFrame::Draw_triangle(int x1, int y1, int x2, int y2, int x3, int y3, int width) {
    // ����һ�������������Σ��������ñ߿���,�߿���ɫĬ��ΪwxColor(132, 0, 0)
    Draw_triangle(x1, y1, x2, y2, x3, y3, wxColor(132, 0, 0), width, false, wxNullColour);
}

void MyFrame::Draw_triangle(int x1, int y1, int x2, int y2, int x3, int y3, bool fill, const wxColour& color_in) {
    // ����һ�������Σ������Ƿ���Ҫ�����ѡ��ָ����ɫ
    Draw_triangle(x1, y1, x2, y2, x3, y3, wxColor(132, 0, 0), 1, fill, color_in);
}

void MyFrame::Draw_triangle(int x1, int y1, int x2, int y2, int x3, int y3, const wxColour& color, int width, bool fill, const wxColour& color_in) {
    // ����һ�������Σ������Ƿ���Ҫ��䡢ָ����ɫ�ͱ߿�����ѡ��
    wxClientDC dc(this);

    dc.SetPen(wxPen(color, width, wxPENSTYLE_SOLID)); // ������ɫ�Ϳ��

    if (fill) {
        dc.SetBrush(wxBrush(color_in)); // ���������ɫ
    }
    const wxPoint points[] = {
        wxPoint(x1, y1),
        wxPoint(x2, y2),
        wxPoint(x3, y3),
    };
    dc.DrawPolygon(3, points);
}

void MyFrame::Draw_text(const char* txt, int x, int y) {
    // �����ı�����1��Ĭ���ı���ɫ��Ĭ���ı���ϸ��Ĭ���ı���С��Ĭ������
    wxClientDC dc(this);
    dc.SetFont(wxFont(20, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Malgun Gothic"))); // ���������С����ϸ������
    dc.DrawText(txt, x, y);
}

void MyFrame::Draw_text(const char* txt, int x, int y, const wxColour& color) {
    // �����ı�����2�������ı���ɫ��Ĭ���ı���ϸ��Ĭ���ı���С��Ĭ������
    wxClientDC dc(this);
    dc.SetTextForeground(color); // ����������ɫ
    dc.SetFont(wxFont(20, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Malgun Gothic"))); // ���������С����ϸ������
    dc.DrawText(txt, x, y);
}

void MyFrame::Draw_text(const char* txt, int x, int y, wxFontWeight weight) {
    // �����ı�����3��Ĭ���ı���ɫ�������ı���ϸ��Ĭ���ı���С��Ĭ������
    wxClientDC dc(this);
    dc.SetFont(wxFont(20, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, weight, false, wxT("Malgun Gothic"))); // ���������С����ϸ������
    dc.DrawText(txt, x, y);
}

void MyFrame::Draw_text(const char* txt, int x, int y, int size) {
    // �����ı�����4��Ĭ���ı���ɫ��Ĭ���ı���ϸ�������ı���С��Ĭ������
    wxClientDC dc(this);
    dc.SetFont(wxFont(size, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Malgun Gothic"))); // ���������С����ϸ������
    dc.DrawText(txt, x, y);
}

void MyFrame::Draw_text(const char* txt, int x, int y, const wxString& fontName) {
    // �����ı�����5��Ĭ���ı���ɫ��Ĭ���ı���ϸ��Ĭ���ı���С����������
    wxClientDC dc(this);
    dc.SetFont(wxFont(20, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, fontName)); // ���������С����ϸ������
    dc.DrawText(txt, x, y);
}

void MyFrame::Draw_text(const char* txt, int x, int y, const wxColour& color, wxFontWeight weight) {
    // �����ı�����6�������ı���ɫ�������ı���ϸ��Ĭ���ı���С��Ĭ������
    wxClientDC dc(this);
    dc.SetTextForeground(color); // ����������ɫ
    dc.SetFont(wxFont(20, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, weight, false, wxT("Malgun Gothic"))); // ���������С����ϸ������
    dc.DrawText(txt, x, y);
}

void MyFrame::Draw_text(const char* txt, int x, int y, const wxColour& color, int size) {
    // �����ı�����7�������ı���ɫ��Ĭ���ı���ϸ�������ı���С��Ĭ������
    wxClientDC dc(this);
    dc.SetTextForeground(color); // ����������ɫ
    dc.SetFont(wxFont(size, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Malgun Gothic"))); // ���������С����ϸ������
    dc.DrawText(txt, x, y);
}

void MyFrame::Draw_text(const char* txt, int x, int y, const wxColour& color, const wxString& fontName) {
    // �����ı�����8�������ı���ɫ��Ĭ���ı���ϸ��Ĭ���ı���С����������
    wxClientDC dc(this);
    dc.SetTextForeground(color); // ����������ɫ
    dc.SetFont(wxFont(20, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, fontName)); // ���������С����ϸ������
    dc.DrawText(txt, x, y);
}

void MyFrame::Draw_text(const char* txt, int x, int y, wxFontWeight weight, int size) {
    // �����ı�����9��Ĭ���ı���ɫ�������ı���ϸ�������ı���С��Ĭ������
    wxClientDC dc(this);
    dc.SetFont(wxFont(size, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, weight, false, wxT("Malgun Gothic"))); // ���������С����ϸ������
    dc.DrawText(txt, x, y);
}

void MyFrame::Draw_text(const char* txt, int x, int y, wxFontWeight weight, const wxString& fontName) {
    // �����ı�����10��Ĭ���ı���ɫ�������ı���ϸ��Ĭ���ı���С����������
    wxClientDC dc(this);
    dc.SetFont(wxFont(20, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, weight, false, fontName)); // ���������С����ϸ������
    dc.DrawText(txt, x, y);
}

void MyFrame::Draw_text(const char* txt, int x, int y, int size, const wxString& fontName) {
    // �����ı�����11��Ĭ���ı���ɫ��Ĭ���ı���ϸ�������ı���С����������
    wxClientDC dc(this);
    dc.SetFont(wxFont(size, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, fontName)); // ���������С����ϸ������
    dc.DrawText(txt, x, y);
}

void MyFrame::Draw_text(const char* txt, int x, int y, const wxColour& color, wxFontWeight weight, int size) {
    // �����ı�����12�������ı���ɫ�������ı���ϸ�������ı���С��Ĭ������
    wxClientDC dc(this);
    dc.SetTextForeground(color); // ����������ɫ
    dc.SetFont(wxFont(size, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, weight, false, wxT("Malgun Gothic"))); // ���������С����ϸ������
    dc.DrawText(txt, x, y);
}

void MyFrame::Draw_text(const char* txt, int x, int y, const wxColour& color, wxFontWeight weight, const wxString& fontName) {
    // �����ı�����13�������ı���ɫ�������ı���ϸ��Ĭ���ı���С����������
    wxClientDC dc(this);
    dc.SetTextForeground(color); // ����������ɫ
    dc.SetFont(wxFont(20, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, weight, false, fontName)); // ���������С����ϸ������
    dc.DrawText(txt, x, y);
}

void MyFrame::Draw_text(const char* txt, int x, int y, wxFontWeight weight, int size, const wxString& fontName) {
    // �����ı�����14��Ĭ���ı���ɫ�������ı���ϸ�������ı���С����������
    wxClientDC dc(this);
    dc.SetFont(wxFont(size, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, weight, false, fontName)); // ���������С����ϸ������
    dc.DrawText(txt, x, y);
}

void MyFrame::Draw_text(const char* txt, int x, int y, const wxColour& color, int size, const wxString& fontName) {
    // �����ı�����15�������ı���ɫ��Ĭ���ı���ϸ�������ı���С����������
    wxClientDC dc(this);
    dc.SetTextForeground(color); // ����������ɫ
    dc.SetFont(wxFont(size, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, fontName)); // ���������С����ϸ������
    dc.DrawText(txt, x, y);
}

void MyFrame::Draw_text(const char* txt, int x, int y, const wxColour& color, wxFontWeight weight, int size, const wxString& fontName) {
    // �����ı�����16�������ı���ɫ�������ı���ϸ�������ı���С����������
    wxClientDC dc(this);
    dc.SetTextForeground(color); // ����������ɫ
    dc.SetFont(wxFont(size, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, weight, false, fontName)); // ���������С����ϸ������
    dc.DrawText(txt, x, y);
}

void MyFrame::Draw_rotated_text(const char* txt, int x, int y, int angle) {
    // ������ת�ı�����1��Ĭ���ı���ɫ��Ĭ���ı���ϸ��Ĭ���ı���С��Ĭ������
    wxClientDC dc(this);
    dc.SetFont(wxFont(20, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Malgun Gothic"))); // ���������С����ϸ������
    dc.DrawRotatedText(txt, x, y, angle);
}

void MyFrame::Draw_rotated_text(const char* txt, int x, int y, int angle, const wxColour& color) {
    // ������ת�ı�����2�������ı���ɫ��Ĭ���ı���ϸ��Ĭ���ı���С��Ĭ������
    wxClientDC dc(this);
    dc.SetTextForeground(color); // ����������ɫ
    dc.SetFont(wxFont(20, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Malgun Gothic"))); // ���������С����ϸ������
    dc.DrawRotatedText(txt, x, y, angle);
}

void MyFrame::Draw_rotated_text(const char* txt, int x, int y, int angle, wxFontWeight weight) {
    // ������ת�ı�����3��Ĭ���ı���ɫ�������ı���ϸ��Ĭ���ı���С��Ĭ������
    wxClientDC dc(this);
    dc.SetFont(wxFont(20, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, weight, false, wxT("Malgun Gothic"))); // ���������С����ϸ������
    dc.DrawRotatedText(txt, x, y, angle);
}

void MyFrame::Draw_rotated_text(const char* txt, int x, int y, int angle, int size) {
    // ������ת�ı�����4��Ĭ���ı���ɫ��Ĭ���ı���ϸ�������ı���С��Ĭ������
    wxClientDC dc(this);
    dc.SetFont(wxFont(size, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Malgun Gothic"))); // ���������С����ϸ������
    dc.DrawRotatedText(txt, x, y, angle);
}

void MyFrame::Draw_rotated_text(const char* txt, int x, int y, int angle, const wxString& fontName) {
    // ������ת�ı�����5��Ĭ���ı���ɫ��Ĭ���ı���ϸ��Ĭ���ı���С����������
    wxClientDC dc(this);
    dc.SetFont(wxFont(20, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, fontName)); // ���������С����ϸ������
    dc.DrawRotatedText(txt, x, y, angle);
}

void MyFrame::Draw_rotated_text(const char* txt, int x, int y, int angle, const wxColour& color, wxFontWeight weight) {
    // ������ת�ı�����6�������ı���ɫ�������ı���ϸ��Ĭ���ı���С��Ĭ������
    wxClientDC dc(this);
    dc.SetTextForeground(color); // ����������ɫ
    dc.SetFont(wxFont(20, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, weight, false, wxT("Malgun Gothic"))); // ���������С����ϸ������
    dc.DrawRotatedText(txt, x, y, angle);
}

void MyFrame::Draw_rotated_text(const char* txt, int x, int y, int angle, const wxColour& color, int size) {
    // ������ת�ı�����7�������ı���ɫ��Ĭ���ı���ϸ�������ı���С��Ĭ������
    wxClientDC dc(this);
    dc.SetTextForeground(color); // ����������ɫ
    dc.SetFont(wxFont(size, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Malgun Gothic"))); // ���������С����ϸ������
    dc.DrawRotatedText(txt, x, y, angle);
}

void MyFrame::Draw_rotated_text(const char* txt, int x, int y, int angle, const wxColour& color, const wxString& fontName) {
    // ������ת�ı�����8�������ı���ɫ��Ĭ���ı���ϸ��Ĭ���ı���С����������
    wxClientDC dc(this);
    dc.SetTextForeground(color); // ����������ɫ
    dc.SetFont(wxFont(20, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, fontName)); // ���������С����ϸ������
    dc.DrawRotatedText(txt, x, y, angle);
}

void MyFrame::Draw_rotated_text(const char* txt, int x, int y, int angle, wxFontWeight weight, int size) {
    // ������ת�ı�����9��Ĭ���ı���ɫ�������ı���ϸ�������ı���С��Ĭ������
    wxClientDC dc(this);
    dc.SetFont(wxFont(size, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, weight, false, wxT("Malgun Gothic"))); // ���������С����ϸ������
    dc.DrawRotatedText(txt, x, y, angle);
}

void MyFrame::Draw_rotated_text(const char* txt, int x, int y, int angle, wxFontWeight weight, const wxString& fontName) {
    // ������ת�ı�����10��Ĭ���ı���ɫ�������ı���ϸ��Ĭ���ı���С����������
    wxClientDC dc(this);
    dc.SetFont(wxFont(20, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, weight, false, fontName)); // ���������С����ϸ������
    dc.DrawRotatedText(txt, x, y, angle);
}

void MyFrame::Draw_rotated_text(const char* txt, int x, int y, int angle, int size, const wxString& fontName) {
    // ������ת�ı�����11��Ĭ���ı���ɫ��Ĭ���ı���ϸ�������ı���С����������
    wxClientDC dc(this);
    dc.SetFont(wxFont(size, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, fontName)); // ���������С����ϸ������
    dc.DrawRotatedText(txt, x, y, angle);
}

void MyFrame::Draw_rotated_text(const char* txt, int x, int y, int angle, const wxColour& color, wxFontWeight weight, int size) {
    // ������ת�ı�����12�������ı���ɫ�������ı���ϸ�������ı���С��Ĭ������
    wxClientDC dc(this);
    dc.SetTextForeground(color); // ����������ɫ
    dc.SetFont(wxFont(size, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, weight, false, wxT("Malgun Gothic"))); // ���������С����ϸ������
    dc.DrawRotatedText(txt, x, y, angle);
}

void MyFrame::Draw_rotated_text(const char* txt, int x, int y, int angle, const wxColour& color, wxFontWeight weight, const wxString& fontName) {
    // ������ת�ı�����13�������ı���ɫ�������ı���ϸ��Ĭ���ı���С����������
    wxClientDC dc(this);
    dc.SetTextForeground(color); // ����������ɫ
    dc.SetFont(wxFont(20, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, weight, false, fontName)); // ���������С����ϸ������
    dc.DrawRotatedText(txt, x, y, angle);
}

void MyFrame::Draw_rotated_text(const char* txt, int x, int y, int angle, wxFontWeight weight, int size, const wxString& fontName) {
    // ������ת�ı�����14��Ĭ���ı���ɫ�������ı���ϸ�������ı���С����������
    wxClientDC dc(this);
    dc.SetFont(wxFont(size, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, weight, false, fontName)); // ���������С����ϸ������
    dc.DrawRotatedText(txt, x, y, angle);
}

void MyFrame::Draw_rotated_text(const char* txt, int x, int y, int angle, const wxColour& color, int size, const wxString& fontName) {
    // ������ת�ı�����15�������ı���ɫ��Ĭ���ı���ϸ�������ı���С����������
    wxClientDC dc(this);
    dc.SetTextForeground(color); // ����������ɫ
    dc.SetFont(wxFont(size, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, fontName)); // ���������С����ϸ������
    dc.DrawRotatedText(txt, x, y, angle);
}

void MyFrame::Draw_rotated_text(const char* txt, int x, int y, int angle, const wxColour& color, wxFontWeight weight, int size, const wxString& fontName) {
    // ������ת�ı�����16�������ı���ɫ�������ı���ϸ�������ı���С����������
    wxClientDC dc(this);
    dc.SetTextForeground(color); // ����������ɫ
    dc.SetFont(wxFont(size, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, weight, false, fontName)); // ���������С����ϸ������
    dc.DrawRotatedText(txt, x, y, angle);
}

//���Ƽ�ͷ����������յ����ꡢ��ϸ����ɫ
void MyFrame::Draw_arrow(int x1, int x2, int y1, int y2, int borderWidth, const wxColour& penColor)
{
    wxClientDC dc(this);
    dc.SetPen(wxPen(penColor, borderWidth, wxPENSTYLE_SOLID));

    dc.DrawLine(x1, y1, x2, y2);
    double x3 = x2 - (x2 - x1) / 5;
    double y3 = y2 - (y2 - y1) / 5;
    double x4, y4, x5, y5;
    //��ͷ�����������Ϊ��ͷ���ȵ�1/7
    double length = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2)) / 7;

    //��ͷΪˮƽ����ֱ���������ʱб��Ϊ0��INF����Ҫ�����ж�
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
    else //һ�����
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

//���Ƽ�ͷ�����ṩ�����յ�����
void MyFrame::Draw_arrow(int x1, int x2, int y1, int y2)
{
    Draw_arrow(x1, y1, x2, y2, 3, *wxBLACK);
}

//���Ƽ�ͷ�����ṩ��㡢�յ�������������
void MyFrame::Draw_arrow(int x1, int x2, int y1, int y2, int borderWidth)
{
    Draw_arrow(x1, y1, x2, y2, borderWidth, *wxBLACK);
}

//���Ƽ�ͷ�����ṩ��㡢�յ������������ɫ
void MyFrame::Draw_arrow(int x1, int x2, int y1, int y2, const wxColour& penColor)
{
    Draw_arrow(x1, y1, x2, y2, 3, penColor);
}

//����Բ�Σ��ṩԲ�����ꡢ�߿���ɫ
void MyFrame::Draw_circle(int x, int y, int radius, const wxColour& color) {
    Draw_circle(x, y, radius, color, 1, false, wxNullColour);
}

//����Բ�Σ��ṩԲ�����ꡢ�뾶���߿���
void MyFrame::Draw_circle(int x, int y, int radius, int width) {
    Draw_circle(x, y, radius, wxColor(132, 0, 0), width, false, wxNullColour);
}

//����Բ�Σ��ṩԲ�����ꡢ�뾶���Ƿ����������ɫ
void MyFrame::Draw_circle(int x, int y, int radius, bool fill, const wxColour& color_in) {
    Draw_circle(x, y, radius, wxColor(132, 0, 0), 1, fill, color_in);
}

//����Բ�Σ��ṩԲ�����ꡢ�뾶���߿���ɫ����ȡ��Ƿ����������ɫ
void MyFrame::Draw_circle(int x, int y, int radius, const wxColour& color, int width, bool fill, const wxColour& color_in) {
    wxClientDC dc(this);

    dc.SetPen(wxPen(color, width, wxPENSTYLE_SOLID));

    if (fill) {
        dc.SetBrush(wxBrush(color_in));
    }

    dc.DrawCircle(x, y, radius);
}

//����USBģ�飬�ṩ���Ͻ�����
void MyFrame::Draw_usb(int x, int y)
{

    //��������
    double x1 = x + USB_WIDTH;
    double y1 = y + USB_LENGTH / 8;
    double x3 = x1;
    double y3 = y + USB_LENGTH / 2;
    double x2 = x1;
    double y2 = y3 + USB_LENGTH / 8;
    double x4 = x + USB_WIDTH / 4;
    double y4 = y + USB_LENGTH;
    double x5 = x4 - USB_WIDTH / 4;
    double y5 = y4;
    double x_circle = x + 20;
    double y_circle = y + 80;

    //���ֲ���
    Draw_rect(x, y, x + USB_WIDTH, y + USB_LENGTH, RED, 2, true, YELLOW);
    Draw_text("J", x + USB_WIDTH / 2 - 5, y - 65, GREEN);
    Draw_text("USB_A", x + USB_WIDTH / 2 - 40, y - 38, GREEN);
    Draw_text("1", x1 + 5, y1 - 25, RED);
    Draw_text("2", x2 + 5, y2 - 25, RED);
    Draw_text("3", x3 + 5, y3 - 30, RED);
    Draw_text("VBUS", x1 -80, y1 - 15, GREEN);
    Draw_text("D+", x3 - 48, y3 - 20, GREEN);
    Draw_text("D-", x2 - 48, y2 - 15, GREEN);

    //��ת����
    Draw_rotated_text("4", x4 + 6, y4 + 20, 90, RED);
    Draw_rotated_text("5", x5 + 6, y5 + 20, 90, RED);
    Draw_rotated_text("GND", x4 + 19, y4 - 10, 90, GREEN);
    Draw_rotated_text("Shield", x5 + 19, y5 - 10, 90, GREEN);

    //�ڲ�ͼ��
    Draw_circle(x_circle, y_circle, 10, true, RED);
    Draw_circle(x_circle + 48, y_circle - 15, 8, true, RED);
    Draw_triangle(x_circle + 65, y_circle + 12, x_circle + 65, y_circle - 12, x_circle + 85.7, y_circle, true, RED);
    Draw_rect(x_circle + 42, y_circle + 7, x_circle + 57, y_circle + 21, true, RED);
    Draw_line(x_circle, y_circle, x_circle + 80, y_circle, 5, RED);
    Draw_line(x_circle + 16, y_circle, x_circle + 36, y_circle - 15, 5, RED);
    Draw_line(x_circle + 26, y_circle, x_circle + 36, y_circle + 15, 5, RED);
    Draw_line(x_circle + 36, y_circle + 15, x_circle + 44, y_circle + 15, 5, RED);
    Draw_line(x_circle + 36, y_circle - 15, x_circle + 44, y_circle - 15, 5, RED);

    //����ͷ
    Draw_line(x1, y1 + 10, x1 + 30, y1 + 10, 2, RED);
    Draw_line(x2, y2 + 10, x2 + 30, y2 + 10, 2, RED);
    Draw_line(x3, y3 + 5, x3 + 30, y3 + 5, 2, RED);
    Draw_line(x4 + 43, y4, x4 + 43, y4 + 30, 2, RED);
    Draw_line(x5 + 43, y5, x5 + 43, y5 + 30, 2, RED);
    Draw_circle(x1 + 30, y1 + 10, 3, RED, 2, false, wxNullColour);
    Draw_circle(x2 + 30, y2 + 10, 3, RED, 2, false, wxNullColour);
    Draw_circle(x3 + 30, y3 + 5, 3, RED, 2, false, wxNullColour);
    Draw_circle(x4 + 43, y4 + 30, 3, RED, 2, false, wxNullColour);
    Draw_circle(x5 + 43, y5 + 30, 3, RED, 2, false, wxNullColour);
    Draw_rect(x1, y1 + 11, x1 - 10, y1 + 6, RED, 2, true, YELLOW);
    Draw_rect(x2, y2 + 11, x2 - 10, y2 + 6, RED, 2, true, YELLOW);
    Draw_rect(x3, y3 + 6, x3 - 10, y3 + 1, RED, 2, true, YELLOW);
    Draw_rect(x4 + 43, y4, x4 + 48, y4 - 10, RED, 2, true, YELLOW);

    //USB�߿�
    Draw_rect(x + 10, y1 - 2, x + 55, y1 + 15, RED, 2, true, YELLOW);
    Draw_rect(x + 13, y1 + 5, x + 52, y1 + 12, RED, 2, true, RED);
}

//����LEDģ�飬�ṩ���ĵ�����
void MyFrame::Draw_led(int x, int y)
{
    Draw_triangle(x, y, x + 50, y - 27, x + 50, y + 27, RED, 2, false, wxNullColour);
    Draw_line(x, y + 29, x, y - 29, RED);
    Draw_line(x - 55, y, x + 100, y, RED);
    Draw_arrow(x - 10, y + 10, x - 40, y + 40, RED);
    Draw_arrow(x - 40, y + 10, x - 70, y + 40, RED);
    Draw_text("LED", x - 21, y + 26, GREEN);
}

wxBEGIN_EVENT_TABLE(MyFrame, wxFrame)

wxEND_EVENT_TABLE()
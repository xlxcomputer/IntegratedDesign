//draw_symbol.h
#ifndef DRAW_ARROW_H
#define DRAW_ARROW_H

#include <wx/wx.h>
#include <cmath>
//���峣����ɫ
#define RED wxColor(132, 0, 0)
#define GREEN wxColor(0, 100, 100)
#define YELLOW wxColor(255, 255, 194)
//USBģ��Ĭ�ϵĳ���
#define USB_LENGTH 216
#define USB_WIDTH 144

class MyFrame : public wxFrame
{
public:
    MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size);

    //����ֱ��
    void Draw_line(int x1, int y1, int x2, int y2, int width, const wxColour& penColor);
    void Draw_line(int x1, int y1, int x2, int y2, const wxColour& penColor);
    void Draw_line(int x1, int y1, int x2, int y2, int width);
    void Draw_line(int x1, int y1, int x2, int y2);

    //���ƾ���
    void Draw_rect(int x1, int y1, int x2, int y2, const wxColour& color);
    void Draw_rect(int x1, int y1, int x2, int y2, int width);
    void Draw_rect(int x1, int y1, int x2, int y2, bool fill, const wxColour& color_in);
    void Draw_rect(int x1, int y1, int x2, int y2, const wxColour& color, int width, bool fill, const wxColour& color_in);

    //����������
    void Draw_triangle(int x1, int y1, int x2, int y2, int x3, int y3, const wxColour& color);//����һ������䣬�������ñ߿���ɫ���߿���Ĭ��Ϊ1��������
    void Draw_triangle(int x1, int y1, int x2, int y2, int x3, int y3, int width);//����һ������䣬�������ñ߿���, �߿���ɫĬ��ΪwxColor(132, 0, 0)��������
    void Draw_triangle(int x1, int y1, int x2, int y2, int x3, int y3, bool fill, const wxColour& color_in);// ����һ�������Ƿ���Ҫ�����ѡ��ָ����ɫ��������
    void Draw_triangle(int x1, int y1, int x2, int y2, int x3, int y3, const wxColour& color, int width, bool fill, const wxColour& color_in); // ����һ�������Ƿ���Ҫ��䡢ָ����ɫ�ͱ߿�����ѡ���������

    //�����ı�����
    void Draw_text(const char* txt, int x, int y);
    void Draw_text(const char* txt, int x, int y, const wxColour& color);
    void Draw_text(const char* txt, int x, int y, wxFontWeight weight);
    void Draw_text(const char* txt, int x, int y, int size);
    void Draw_text(const char* txt, int x, int y, const wxString& fontName);
    void Draw_text(const char* txt, int x, int y, const wxColour& color, wxFontWeight weight);
    void Draw_text(const char* txt, int x, int y, const wxColour& color, int size);
    void Draw_text(const char* txt, int x, int y, const wxColour& color, const wxString& fontName);
    void Draw_text(const char* txt, int x, int y, wxFontWeight weight, int size);
    void Draw_text(const char* txt, int x, int y, wxFontWeight weight, const wxString& fontName);
    void Draw_text(const char* txt, int x, int y, int size, const wxString& fontName);
    void Draw_text(const char* txt, int x, int y, const wxColour& color, wxFontWeight weight, int size);
    void Draw_text(const char* txt, int x, int y, const wxColour& color, wxFontWeight weight, const wxString& fontName);
    void Draw_text(const char* txt, int x, int y, const wxColour& color, int size, const wxString& fontName);
    void Draw_text(const char* txt, int x, int y, wxFontWeight weight, int size, const wxString& fontName);
    void Draw_text(const char* txt, int x, int y, const wxColour& color, wxFontWeight weight, int size, const wxString& fontName);

    //�ı���ת����
    void Draw_rotated_text(const char* txt, int x, int y, int angle);
    void Draw_rotated_text(const char* txt, int x, int y, int angle, const wxColour& color);
    void Draw_rotated_text(const char* txt, int x, int y, int angle, wxFontWeight weight);
    void Draw_rotated_text(const char* txt, int x, int y, int angle, int size);
    void Draw_rotated_text(const char* txt, int x, int y, int angle, const wxString& fontName);
    void Draw_rotated_text(const char* txt, int x, int y, int angle, const wxColour& color, wxFontWeight weight);
    void Draw_rotated_text(const char* txt, int x, int y, int angle, const wxColour& color, int size);
    void Draw_rotated_text(const char* txt, int x, int y, int angle, const wxColour& color, const wxString& fontName);
    void Draw_rotated_text(const char* txt, int x, int y, int angle, wxFontWeight weight, int size);
    void Draw_rotated_text(const char* txt, int x, int y, int angle, wxFontWeight weight, const wxString& fontName);
    void Draw_rotated_text(const char* txt, int x, int y, int angle, int size, const wxString& fontName);
    void Draw_rotated_text(const char* txt, int x, int y, int angle, const wxColour& color, wxFontWeight weight, int size);
    void Draw_rotated_text(const char* txt, int x, int y, int angle, const wxColour& color, wxFontWeight weight, const wxString& fontName);
    void Draw_rotated_text(const char* txt, int x, int y, int angle, const wxColour& color, int size, const wxString& fontName);
    void Draw_rotated_text(const char* txt, int x, int y, int angle, wxFontWeight weight, int size, const wxString& fontName);
    void Draw_rotated_text(const char* txt, int x, int y, int angle, const wxColour& color, wxFontWeight weight, int size, const wxString& fontName);

    //���Ƽ�ͷ
    void Draw_arrow(int x1, int x2, int y1, int y2);
    void Draw_arrow(int x1, int x2, int y1, int y2, int borderWidth);
    void Draw_arrow(int x1, int x2, int y1, int y2, const wxColor& penColor);
    void Draw_arrow(int x1, int x2, int y1, int y2, int borderWidth, const wxColor& penColor);

    void Draw_circle(int x, int y, int radius, const wxColour& color);

    // ����Բ��
    void Draw_circle(int x, int y, int radius, int width);
    void Draw_circle(int x, int y, int radius, bool fill, const wxColour& color_in);
    void Draw_circle(int x, int y, int radius, const wxColour& color, int width, bool fill, const wxColour& color_in);

    //����USBģ��
    void Draw_usb(int x1, int y1);
    void Draw_usb(int x1, int y1, int angle);

    //����LEDģ��
    void Draw_led(int x1, int y1);
    void Draw_led(int x1, int y1, int angle);

private:
    void OnPaint(wxPaintEvent& event);
    wxDECLARE_EVENT_TABLE();
};

#endif
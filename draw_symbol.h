//draw_symbol.h
#ifndef DRAW_ARROW_H
#define DRAW_ARROW_H

#include <wx/wx.h>
#include <cmath>
//定义常用颜色
#define RED wxColor(132, 0, 0)
#define GREEN wxColor(0, 100, 100)
#define YELLOW wxColor(255, 255, 194)
//USB模块默认的长宽
#define USB_LENGTH 216
#define USB_WIDTH 144

class MyFrame : public wxFrame
{
public:
    MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size);

    //绘制直线
    void Draw_line(int x1, int y1, int x2, int y2, int width, const wxColour& penColor);
    void Draw_line(int x1, int y1, int x2, int y2, const wxColour& penColor);
    void Draw_line(int x1, int y1, int x2, int y2, int width);
    void Draw_line(int x1, int y1, int x2, int y2);

    //绘制矩形
    void Draw_rect(int x1, int y1, int x2, int y2, const wxColour& color);
    void Draw_rect(int x1, int y1, int x2, int y2, int width);
    void Draw_rect(int x1, int y1, int x2, int y2, bool fill, const wxColour& color_in);
    void Draw_rect(int x1, int y1, int x2, int y2, const wxColour& color, int width, bool fill, const wxColour& color_in);

    //绘制三角形
    void Draw_triangle(int x1, int y1, int x2, int y2, int x3, int y3, const wxColour& color);//绘制一个无填充，可以设置边框颜色，边框宽度默认为1的三角形
    void Draw_triangle(int x1, int y1, int x2, int y2, int x3, int y3, int width);//绘制一个无填充，可以设置边框宽度, 边框颜色默认为wxColor(132, 0, 0)的三角形
    void Draw_triangle(int x1, int y1, int x2, int y2, int x3, int y3, bool fill, const wxColour& color_in);// 绘制一个根据是否需要填充来选择，指定颜色的三角形
    void Draw_triangle(int x1, int y1, int x2, int y2, int x3, int y3, const wxColour& color, int width, bool fill, const wxColour& color_in); // 绘制一个根据是否需要填充、指定颜色和边框宽度来选择的三角形

    //绘制文本函数
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

    //文本旋转函数
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

    //绘制箭头
    void Draw_arrow(int x1, int x2, int y1, int y2);
    void Draw_arrow(int x1, int x2, int y1, int y2, int borderWidth);
    void Draw_arrow(int x1, int x2, int y1, int y2, const wxColor& penColor);
    void Draw_arrow(int x1, int x2, int y1, int y2, int borderWidth, const wxColor& penColor);

    void Draw_circle(int x, int y, int radius, const wxColour& color);

    // 绘制圆形
    void Draw_circle(int x, int y, int radius, int width);
    void Draw_circle(int x, int y, int radius, bool fill, const wxColour& color_in);
    void Draw_circle(int x, int y, int radius, const wxColour& color, int width, bool fill, const wxColour& color_in);

    //绘制USB模块
    void Draw_usb(int x1, int y1);
    void Draw_usb(int x1, int y1, int angle);

    //绘制LED模块
    void Draw_led(int x1, int y1);
    void Draw_led(int x1, int y1, int angle);

private:
    void OnPaint(wxPaintEvent& event);
    wxDECLARE_EVENT_TABLE();
};

#endif
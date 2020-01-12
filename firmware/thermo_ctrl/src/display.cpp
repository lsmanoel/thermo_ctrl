//By Lucas Seara Manoel - LPAE - IFSC
#include <Arduino.h>
#include "display.h"

Dysplay::Dysplay()
{ 
    u8g = U8GLIB_SSD1306_128X64(U8G_I2C_OPT_NO_ACK);

    if ( u8g.getMode() == U8G_MODE_R3G3B2 ) {
        u8g.setColorIndex(128);     // white
    }
    else if ( u8g.getMode() == U8G_MODE_GRAY2BIT ) {
        u8g.setColorIndex(3);         // max intensity
    }
    else if ( u8g.getMode() == U8G_MODE_BW ) {
        u8g.setColorIndex(1);         // pixel on
    }
    else if ( u8g.getMode() == U8G_MODE_HICOLOR ) {
        u8g.setHiColorByRGB(255,0,0);
    }

    init_draw_flag = 1; 
}

void Dysplay::init_draw() 
{
    u8g.firstPage();
    do
    {
        this->_init_draw();
    } while(u8g.nextPage());
    // delay(600); 
}

void Dysplay::_init_draw()
{
    u8g.setFont(u8g_font_9x15B);
    u8g.drawStr(0, 10, "load");
    u8g.drawStr(10, 30, " display...");
    u8g.drawStr(30, 60, "by Lucas");
    init_draw_flag=0; 
}

void Dysplay::draw(uint16_t temp, uint16_t ref) 
{
    u8g.firstPage();
    do
    {
        if(init_draw_flag) this->init_draw();
        else this->_draw(temp, ref);
    } while(u8g.nextPage());
}

void Dysplay::_draw(uint16_t temp, uint16_t ref) 
{
    u8g.setFont(u8g_font_9x15B);
    u8g.drawStr(0, 10, "Temp:");
    u8g.setPrintPos(50, 10);
    u8g.print(temp/10);u8g.print('.');u8g.print(temp%10);
    u8g.drawStr(0, 30, "Ref:");
    u8g.setPrintPos(50, 30);
    u8g.print(ref/10);u8g.print('.');u8g.print(ref%10);
    if(power_flag)
        u8g.drawDisc(62, 52, 6, U8G_DRAW_ALL);
}

void Dysplay::set_power_flag(uint8_t pwr_flag) 
{
    power_flag = pwr_flag;
}
 

//By Lucas Seara Manoel - LPAE - IFSC
#include <U8glib.h>

class Dysplay
{
protected:
	U8GLIB_SSD1306_128X64 u8g;
    uint8_t init_draw_flag;
    uint8_t power_flag;

public:
	Dysplay();
    void set_power_flag(uint8_t pwr_flag);
    void init_draw();
    void _init_draw();
    void draw(uint16_t temp, uint16_t ref);
    void _draw(uint16_t temp, uint16_t ref);
    void first_page();
    uint8_t next_page(); 
};
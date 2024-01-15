#include <lib.h>

namespace main
{
    namespace lcd
    {
        LiquidCrystal_I2C lcd(0x27,16,2);
        char date[20], time[20];

        void setup()
        {
            lcd.init();
            lcd.backlight();
        }

        void lcd_main(){
            lcd.clear();
            lcd.setCursor(0, 0);
            lcd.print(" MAN HINH CHINH "); 
            lcd.setCursor(0,1);
            lcd.print("THPT Dien Chau 4");
        }

        void lcd_time()
        {
            main::ds3231::time_update();
            lcd.clear();
            sprintf(date, "%02d/%02d/%02d", main::ds3231::thoigian.day, main::ds3231::thoigian.month, main::ds3231::thoigian.year);
            sprintf(time, "%02d:%02d:%02d", main::ds3231::thoigian.hour, main::ds3231::thoigian.min, main::ds3231::thoigian.sec);
            lcd.setCursor(0,0);
            lcd.print("DATE: ");
            lcd.setCursor(0,1);
            lcd.print("TIME: ");
            lcd.setCursor(6,0);
            lcd.print(date);
            lcd.setCursor(6,1);
            lcd.print(time);
            delay(200);
        }
        void lcd_temp()
        {
            main::dht::temp_update();
            lcd.clear();
            lcd.setCursor(1,0);
            lcd.print("HUMID: ");
            lcd.setCursor(8,0);
            lcd.print(main::dht::humid);
            lcd.print(" %");
            lcd.setCursor(1,1);
            lcd.print("TEMP: ");
            lcd.setCursor(7,1);
            lcd.print(main::dht::temp);
            lcd.print(" C");
            delay(200);
        }
        void lcd_chedo(){
            lcd.clear();
            lcd.setCursor(0,0);
            lcd.print("CHE DO: ");
            if(main::action::count2 == 0){
                lcd.setCursor(9,0);
                lcd.print("auto");
            }
            else
            {
                lcd.print("not auto");
            }
            delay(200);
        }
        
        void lcd_auto(){
            lcd.clear();
            lcd.print("> AUTO");
            lcd.setCursor(0,1);
            lcd.print("  NOT AUTO");
        }
        void lcd_notauto(){
            lcd.clear();
            lcd.print("  AUTO");
            lcd.setCursor(0,1);
            lcd.print("> NOT AUTO");
        }
        void lcd_humid(){
            lcd.clear();
            lcd.setCursor(0,0);
            lcd.print("  Humid Setting");
            lcd.setCursor(0,1);
            lcd.print("Current set: ");
            lcd.print(main::action::counthumid);

        }
        
        void lcd_sethumid(){
            lcd.clear();
            lcd.setCursor(0,0);
            lcd.print(" Humid: ");
            lcd.print(main::action::counthumid);
            lcd.print("%");
        }
        void lcd_settime(){
            lcd.clear();
            lcd.print("  TIME SETTING: ");
            lcd.setCursor(8,1);
            lcd.print(main::action::count_time);
       }
        void lcd_setdis(){
            lcd.clear();
            lcd.print("DISTANCE SETTING: ");
            lcd.setCursor(8,1);
            lcd.print(main::action::count_dis);
        }

        void done_set(){
            lcd.clear();
            lcd.setCursor(2,0);
            lcd.print("  DONE SET  ");
            lcd.setCursor(2,1);
            lcd.print("PROCESSING...");
            delay(1000);
        }

        void function1(){ //  3 che do cua tang 1 dua theo count1
            if (main::action:: count1 == 1){
                main::lcd::lcd_time();
            }
            else if (main::action::count1 == 2){
                main::lcd::lcd_temp();
            }
            else if (main::action::count1 == 3){
                main::lcd::lcd_chedo();
            }
        }

        void function2(){ // 2 che do cua tang 2 la auto va not auto count 2
            if (main::action::count2 == 0){
                main::lcd:: lcd_auto();
            }
            else if (main::action::count2 == 1){
                main::lcd:: lcd_notauto();
            }
        } 
        void lcd_stop(){
            lcd.clear();
            lcd.setCursor(3,0);
            lcd.print("STOP WATER");
            lcd.setCursor(0,1);
            lcd.print("Traffic interuption");
        }
        void lcd_timerest(int time_rest_min, int time_rest_sec){
            lcd.clear();
            lcd.print("Time rest: ");
            lcd.print(time_rest_min);
            lcd.print(":");
            if(time_rest_sec <= 9){
                lcd.print("0");
                lcd.print(time_rest_sec);
            }
            else{
                lcd.print(time_rest_sec);
            }
            lcd.setCursor(0,1);
            if(main::action::count2 == 1){
                lcd.print("Che do: notauto");
            }
            else{
                lcd.print("Che do:  auto");
            }
        }
        void lcd_reset(){
            lcd.clear();
            lcd.print("  Resetting...  ");
            delay(2000);
            lcd.clear();
            lcd.print("......DONE......");
            delay(1000);
        }

    } // namespace lcd
    
} // namespace main

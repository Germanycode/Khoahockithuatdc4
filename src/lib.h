#include <Arduino.h>
#include <SPI.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <inttypes.h>
#include <RTClib.h>
#include <DHT.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_I2CDevice.h>
#include <Ultrasonic.h>


namespace main
{
    struct time
    {
        uint16_t year;
        uint8_t month;
        uint8_t day;

        uint8_t hour;
        uint8_t min;
        uint8_t sec;
    };
    
    namespace action
    {
        extern int count_time;
        extern int count_dis;
        extern int counthumid;

        extern int count1;
        extern int count2;

        extern int gt_back;
        extern int back_bt;

        extern int count_tong;
        extern int count_start;
        
        void setup();
        void action();
    } // namespace action
    
    namespace lcd
    {
        extern LiquidCrystal_I2C lcd;
        void setup();

        void lcd_main();

        void lcd_time();
        void lcd_temp();
        void lcd_chedo();
        void lcd_humid();
        void lcd_sethumid();

        void function1();
        void function2();

        void lcd_settime();
        void lcd_setdis();
        void lcd_auto();
        void lcd_notauto();

        void done_set();
        
        void lcd_stop();

        void lcd_reset();
        void lcd_timerest(int time_rest_min, int time_rest_sec);
    } // namespace lcd
    
    namespace ds3231
    {
        extern DateTime now;
        extern time thoigian;
        void setup();
        void time_update();

    } // namespace ds3231
    
    namespace dht
    {
        extern int humid;
        extern int temp;

        void setup();
        void temp_update();
    } // namespace dht
    namespace radar
    {
        extern float kc1;
        extern int gt_radar;
        void radar_update();

    } // namespace radar
    // namespace function
    // {
    //     extern DateTime t6ime_off;
    //     extern DateTime ht;
    //     void setup();
    //     void auto_function();
    //     void notauto_function();

    // } // namespace function
    namespace function_test
    {
        extern DateTime time_off;
        extern DateTime ht;
        void setup();
        void auto_function();
        void notauto_function();
    } // namespace function_test
    
    
} // namespace main

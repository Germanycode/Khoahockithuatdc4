#include <lib.h>
namespace main
{
    namespace ds3231
    {
        RTC_DS3231 rtc;
        time thoigian;
        DateTime now ;

        void setup()
        {
            rtc.begin();
            rtc.adjust(DateTime(2024, 1, 10, 19, 0, 0)); 
        }

        void time_update()
        {
            now = rtc.now();

            thoigian.year = now.year();
            thoigian.month = now.month();
            thoigian.day = now.day();
            thoigian.hour = now.hour();
            thoigian.min = now.minute();
            thoigian.sec = now.second();
        }
    } // namespace ds3231
} // namespace main

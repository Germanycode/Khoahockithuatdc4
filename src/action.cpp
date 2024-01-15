#include <lib.h>

namespace main
{
    namespace action
    {

        #define led 13

        #define menu_bt 4
        int gt_menu;
        int back_bt = 3;
        int gt_back;
        #define inc_bt  7
        int gt_inc;
        #define  dec_bt  6
        int gt_dec ;   
        #define start_bt 5
        int gt_start;

        int mac = 1;

        int count1 = 0; 
        int count2 = 0;
        int count_tong = 0;  
        int count_back = 0;

        int count_time = 5; // macdinh cho count_time va count_dis
        int count_dis = 3;
        int counthumid = 65;

        int count_start = 0;

        void setup()
        {
            // pinMode(radar_pin, INPUT_PULLUP);
            pinMode(menu_bt, INPUT_PULLUP);
            pinMode(back_bt, INPUT_PULLUP);
            pinMode(inc_bt, INPUT_PULLUP);
            pinMode(dec_bt, INPUT_PULLUP);
            pinMode(start_bt, INPUT_PULLUP);

            pinMode(led,OUTPUT);
        }

        void action()

        {   //cap nhat lien tuc thoi gian
            main::ds3231::time_update();
            // capnhat radar
            main::radar::radar_update();
            //cap nhat temp
            main::dht::temp_update();
            // cap nhat lien tuc gt nut nhan

            gt_menu = digitalRead(menu_bt);
            gt_back = digitalRead(back_bt);
            gt_inc = digitalRead(inc_bt);
            gt_dec = digitalRead(dec_bt);
            gt_start = digitalRead(start_bt);

            // ...................MENU button......................//
            if (gt_menu != mac)
            {
                if(gt_menu == 0 )
                { 
                    count_tong ++;

                    if(count_tong == 1)
                    {
                        // count1 = 0;
                        main::lcd::lcd_time();
                    }
                    else if(count_tong == 2 && count1 == 0){
                        main::lcd::lcd_settime();
                    }
                        if(count_tong == 3){
                            main::lcd::done_set();
                            count_tong = 1;
                            // count1 = 0;
                            main::lcd::lcd_time();
                        }
                    else if (count_tong == 2 && count1 == 1){// vao menu 2 la set dis
                        main::lcd::lcd_setdis();
                    }
                        if(count_tong == 3 ){
                            main::lcd::done_set();
                            count_tong --;
                            count1 = 0;
                            main::lcd::lcd_temp();
                        }
                    else if(count_tong == 2 && count1 == 2){
                        main::lcd::lcd_sethumid();
                    }
                        if(count_tong == 3 && count1 == 2){
                           main::lcd::done_set(); 
                            count_tong --;
                            count1 = 0;
                            main::lcd::lcd_humid();
                            }
                    else if ( count_tong == 2 && count1 == 3){
                        // count2 = 0; 
                        main::lcd::function2();// chon che do
                    
                        if ( count_tong == 3 && count2 == 0){
                            count2 = 0;
                            main::lcd::done_set();
                            count_tong --;
                            main::lcd::lcd_chedo();
                        }
                        else if(count_tong == 3 && count2 == 1){
                            count2 = 1;
                            main::lcd::done_set();
                            count_tong --;
                            main::lcd::lcd_chedo();
                        }
                    }
                   
                    delay(100);
                }
                mac = gt_menu;
            }   
            // ...................INC button......................//

            else if (gt_inc != mac)
            {
                if(gt_inc == 0 )
                {
                    if(count_tong == 1){// len o menutong
                        if(count1 >= 3){
                            count1 = 0;
                        }
                        else{
                            count1++;
                        }
                        switch (count1)
                        {
                        case 0:
                            main::lcd::lcd_time();
                            break;
                        case 1:
                            main::lcd::lcd_temp();
                            break;
                        case 2:
                            main::lcd::lcd_humid();
                            break;
                        case 3:
                            main::lcd::lcd_chedo();
                            break;
                        }
                    }
                    else if(count_tong == 2 && count1 == 0){// tang count_time madinh la 5
                        if(count_time >= 15){
                            count_time = 0;
                        }
                        else{
                            count_time++;
                        }
                        main::lcd::lcd_settime();
                    }
                    else if(count_tong == 2 && count1 == 1){// tang count_dis macdinh la 3
                        if(count_dis >= 7){
                            count_dis = 3;
                        }
                        else{
                            count_dis ++;
                        }
                        main::lcd::lcd_setdis();
                    }
                    else if(count_tong == 2 && count1 == 2){ // vao chon humid
                        if(counthumid >= 80){
                            counthumid = 50;
                        }
                        else{
                            counthumid ++;
                        }
                        main::lcd::lcd_sethumid();                        
                    }
                    else if(count_tong == 2 && count1 == 3){ // vao chon che do
                        if( count2 >= 1){
                            count2 =0;
                        }
                        else{
                            count2++;
                        }
                        main::lcd::function2();                        
                    }
                    delay(100);
                }
                mac = gt_inc;
            }
            // ...................DEC button......................//
            else if (gt_dec != mac)
            {
                if(gt_dec == 0 )
                {
                    if(count_tong == 1){
                        if(count1 <= 0){
                            count1 = 3; 
                        }
                        else{
                            count1 --;
                        }
                        switch (count1)
                        {
                        case 0:
                            main::lcd::lcd_time();
                            break;
                        case 1:
                            main::lcd::lcd_temp();
                            break;
                        case 2:
                            main::lcd::lcd_humid();
                            break;
                        case 3:
                            main::lcd::lcd_chedo();
                            break;
                        }
                    }
                    else if( count_tong == 2 && count1 == 0){
                        if(count_time <= 0){
                            count_time = 15;
                        }
                        else{
                            count_time --;
                        }
                        main::lcd::lcd_settime();
                    }
                    else if( count_tong == 2 && count1 == 1){
                        if(count_dis <= 3){
                            count_dis = 7;
                        }
                        else{
                            count_dis --;
                        }
                        main::lcd::lcd_setdis();
                    }
                    else if(count_tong == 2 && count1 == 3){
                        if(count2 <= 0){
                            count2 = 1;
                        }
                        else{
                            count2--;
                        }
                        main::lcd::function2();
                    }
                    else if(count_tong == 2 && count1 == 2){
                        if(counthumid <= 50){
                            counthumid = 80;
                        }
                        else{
                            counthumid--;
                        }
                        main::lcd::lcd_sethumid();
                    }
                    delay(100);
                }
                mac = gt_dec;
            }

            // ...................DEC button......................//

            else if (gt_back != mac)
            {
                if(gt_back == 0 )
                {
                    count_back++;
                    if (count_back == 1){
                        if(count_tong == 1 ){// menutong ve manhinchinh
                            count_tong --;
                            count_back = 0;
                            main::lcd::lcd_main();
                        }
                    }
                    else if (count_tong == 2 && count1 == 0){ // quay tu menu1 laf settime ve menutong
                        count_tong = 1;
                        count_back = 0;
                        // count1 = 0;
                        main::lcd::lcd_time();
                    }
                    else if (count_tong == 2 && count1  == 1){// quay ve tu setdis laf menu 2 ve menutong
                        count_back = 0;
                        count_tong --;
                        count1 = 0;
                        main::lcd::lcd_temp();;
                    }
                    else if(count_tong == 2 && count1 == 2){
                        count_back = 0;
                        count_tong = 1;
                        count1 = 0;
                        main::lcd::lcd_humid();
                    }
                    else if(count_tong == 2 && count1 == 3){
                        count_back = 0;
                        count_tong = 1;
                        count1 = 0;
                        main::lcd::lcd_chedo();
                    }
                    else {count_back = 0;}

                    delay(100);
                }
                mac = gt_back;
            }
            int hour_now = main::ds3231::thoigian.hour;

            Serial.print("count_tong: ");
            Serial.print(count_tong);
            Serial.print("  ");
            Serial.print("count1: ");
            Serial.print(count1);
            Serial.print("  ");
            Serial.print("count2: ");
            Serial.print(count2);
            Serial.print("  ");
            Serial.print("count_time: ");
            Serial.print(count_time);
            Serial.print("  ");
            Serial.print("Hour");
            Serial.print(hour_now);
            Serial.print("  ");
            Serial.print("counthumid: ");
            Serial.print(counthumid);
            Serial.print("  ");
            Serial.print("real humid:  ");
            Serial.println(main::dht::humid);

            delay(200);

            // int hour_now = main::ds3231::thoigian.hour;

            switch (count2)
            {
                case 0:
                    if((hour_now <= 12 && hour_now >= 14) || (hour_now <= 23 && hour_now >= 6 )){ // tim thoi gian hop ly qua do dat
                        // main::function::auto_function();
                        main::function_test::auto_function();
                    }
                    break;
                case 1:
                    if(gt_start == 0){
                        count_start ++;
                        if(count_start == 1){
                            main::function_test::notauto_function();    
                            count_start = 0;
                            count2 = 0;
                        }
                        delay(50);
                    }
                    break;
            }
        }

    } // namespace action
    
} // namespace main

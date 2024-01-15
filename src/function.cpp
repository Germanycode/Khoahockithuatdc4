#include <lib.h>

namespace main
{
    namespace function
    {
        #define water_pump 9
        int water_power; // may bom
        
        #define bientro A0 // chi dung trong notauto function
        int gt_bientro;
        // int time_rest;

        void setup(){
            pinMode(water_pump, OUTPUT);
            pinMode(bientro, INPUT);
        }
        void auto_function(){
          
            DateTime ht = main::ds3231::now;  // cap nhat thoi gian

            if(main::dht::humid <= 55 )   // gia su do am can thiet la 50
            {
                DateTime time_off = ht + TimeSpan(0,0, main::action::count_time, 0);// thoi gian tat may sau cac lan bat

                float water_max = map(main::action::count_dis, 0,7,0,100);// gia su 7m la muc phun toi da cua dong co
                
                int time_rest_min = time_off.minute() - ht.minute() ;
                int time_rest_sec = 59 - ht.second();
                
                while (time_rest_min >= 0 && time_rest_sec >= 0){// can đưa biến thoi gian ve int
                    main::action::gt_back = digitalRead(main::action::back_bt);
                    main::radar::radar_update();
                    main::ds3231::time_update();

                    DateTime ht = main::ds3231::now;

                    time_rest_min = time_off.minute() - ht.minute();
                    time_rest_sec = 59 - ht.second();

                    water_power = map(time_rest_min,0,main::action::count_time,0, water_max);


                    analogWrite(water_pump, water_power);// bat may bom

                    main::lcd::lcd_timerest(time_rest_min, time_rest_sec);

                        // xem cac gian doan khi dang phun///
                    if(main::radar::gt_radar == 0){
                        digitalWrite(water_pump,LOW);
                        main::lcd::lcd_stop();
                        delay(5000);
                    } 
                    else{
                        analogWrite(water_pump,water_power);
                    }
                    if(main::action::gt_back == 0){
                        digitalWrite(water_pump, LOW);
                        main::action::count_start = 0;
                        main::action::count_tong = 0;
                        main::lcd::lcd_main();
                        break;
                    }       
                }
                if(time_rest_min < 0 ){
                    main::lcd::lcd_main();
                    digitalWrite(water_pump, LOW);
                    main::action::count_tong = 0;
                    main::action::count1 = 0;

                }

                DateTime off_waterpump = ht + TimeSpan(0,1,0,0);// thoi gian tat may bom sau cac lan phun

                while(ht <= off_waterpump){
                    digitalWrite(water_pump, LOW);
                    // main::action::count2 = 1; // sau 1 tiếng thì luôn ở chế độ notauto
                    main::ds3231::time_update();
                    int gt_exit = digitalRead(main::action::back_bt);
                    if(gt_exit == 0){
                        main::lcd::lcd_reset();
                        main::lcd::lcd_main();
                        main::action::count_tong = 0;
                        break;
                    }
                }
            }
        }
        void notauto_function(){
            DateTime ht = main::ds3231::now; // cap nhat thoi gian

            DateTime time_off = ht + TimeSpan(0,0, main::action::count_time, 0);; // thoi gian tat may sau cac lan bat

            float water_max = map(main::action::count_dis, 0,7,0,100);// gia su 7m la muc phun toi da cua dong co

            int time_rest_min = time_off.minute() - ht.minute() ;// khong tru 1 vi thoi gian that thoat
            int time_rest_sec = time_off.second() - ht.second();

            while (time_rest_min >= 0 && time_rest_sec >= 0){

                main::action::gt_back = digitalRead(main::action::back_bt);
                main::radar::radar_update();
                main::ds3231::time_update();

                DateTime ht = main::ds3231::now;
                
                gt_bientro = analogRead(bientro);

                main::ds3231::time_update();

                time_rest_min = time_off.minute() - ht.minute();
                time_rest_sec = 59 - ht.second();

                water_power = map(gt_bientro,0,1023,0, water_max);

                analogWrite(water_pump,water_power);

                main::lcd::lcd_timerest(time_rest_min,time_rest_sec);

            // cac gian doan khi dang phun //
                if(main::radar::gt_radar == 0){
                    digitalWrite(water_pump,LOW);
                    main::lcd::lcd_stop();
                    delay(5000);
                } 
                else{
                    analogWrite(water_pump,water_power);
                }
                if(main::action::gt_back == 0){
                    digitalWrite(water_pump, LOW);
                    main::action::count_start = 0;
                    main::action::count_tong = 0;
                    main::lcd::lcd_main();
                    break;       
                    }
            }
            if(time_rest_min < 0 ){
                main::lcd::lcd_main();
                digitalWrite(water_pump, LOW);
                main::action::count_tong = 0;
                main::action::count1 = 0;
            }
        }

    } // namespace function
    
} // namespace main

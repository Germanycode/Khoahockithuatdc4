#include <lib.h>

namespace main
{
    namespace radar
    {
        #define trig1 13
        #define echo1 8
        #define trig2 9
        #define echo2 10

        Ultrasonic ultra1(trig1, echo1);
        Ultrasonic ultra2(trig2, echo2);

        float kc1;
        float kc2;

        int gt_radar;

        void radar_update()
        {
            kc1 = ultra1.read();
            kc2 = ultra2.read();

            if(kc2<= 20 || kc1 <= 20){
                gt_radar = 0;
            }
            else{
                gt_radar = 1;
            }

        }

    } // namespace radar
    
} // namespace main

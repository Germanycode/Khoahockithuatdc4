#include <lib.h>

namespace main
{
    namespace dht
    {
        #define dht_pin 12
        #define dht_type DHT22

        DHT dht(dht_pin,dht_type);

        int humid;
        int temp;
        
        void setup(){
            dht.begin();
        }
        void temp_update()
        {
            
            humid = dht.readHumidity(); // Read temp

            temp = dht.readTemperature(); // Read humid

        }
        
    } // namespace dht
    
} // namespace main

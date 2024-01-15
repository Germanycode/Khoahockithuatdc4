#include <lib.h>

void setup() {
  Serial.begin(115200);
  main::lcd::setup();
  main::action::setup();
  main::ds3231::setup();
  main::dht::setup();
  // main::function::setup();
  main::function_test::setup();   
  main::lcd::lcd_main();
}

void loop() {
  main::action::action();
}
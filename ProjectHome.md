# File logger for Arduino #

This project focus in just one simple functionality: logging data to a file in SD cards from Arduino boards. We are trying to get it 1) fast and 2) small, so this library can be used in other projects based on arduino with little impact on memory resources and performance.

### References ###
Ths library was developed to be included in GPSLogger, an arduino shield that logs GPS data to SD cards and is small enough to be embedded into RC airplanes.

You can find info on the GPSLogger shield here:
|http://www.arduino.cc/cgi-bin/yabb2/YaBB.pl?num=1240704102|
|:---------------------------------------------------------|
|![http://elbaroncojo.stream18.com/wp-content/uploads/2009/04/gpslogger.png](http://elbaroncojo.stream18.com/wp-content/uploads/2009/04/gpslogger.png)|

### Features ###
By now, it takes about 175 mSecs to append 512 bytes to the file, so transfer rate is about 2925 bytes per second.

Anyway, take into account that the size of the minimum data chunk that you can write on SD is 512 bytes, so to write 1 single byte it will take 175 mSecs, even if 511 bytes are unchanged on SD.

Consider buffering to optimize SD access speed.

The library memory footprint, for version 0.6, is:
  * 3581 bytes in program memory (Flash)
  * 537 bytes in data memory (SRAM)

### Developer's guide ###
Using the library is as simple as this
```
void setup(void) {
...
  // This is to power on the shield
  pinMode(MEM_PW, OUTPUT);
  digitalWrite(MEM_PW, HIGH);
...
}

void loop(void) {
...
  // This will append the message "Data" to the end of the file "data.log"
  byte buffer[] = "Data";
  if( FileLogger::append("data.log", buffer, 4) != 0) {
     // Error appending data, notify or do whatever!
  }
...
}

```
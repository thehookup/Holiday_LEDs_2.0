/*****************  NEEDED TO MAKE NODEMCU WORK ***************************/
#define FASTLED_INTERRUPT_RETRY_COUNT 0
#define FASTLED_ESP8266_RAW_PIN_ORDER

/******************  LIBRARY SECTION *************************************/

#include <FastLED.h>        //https://github.com/FastLED/FastLED
#include <SimpleTimer.h>    //https://github.com/thehookup/Simple-Timer-Library
#include <PubSubClient.h>   //https://github.com/knolleary/pubsubclient
#include <ESP8266WiFi.h>    //if you get an error here you need to install the ESP8266 board manager 
#include <ESP8266mDNS.h>    //if you get an error here you need to install the ESP8266 board manager 
#include <ArduinoOTA.h>     //ArduinoOTA is now included with the ArduinoIDE

/*****************  START USER CONFIG SECTION *********************************/
/*****************  START USER CONFIG SECTION *********************************/
/*****************  START USER CONFIG SECTION *********************************/
/*****************  START USER CONFIG SECTION *********************************/

#define USER_SSID                 "YOUR_WIRELESS_SSID"
#define USER_PASSWORD             "YOUR_WIRELESS_PW"
#define USER_MQTT_SERVER          "YOUR_MQTT_SERVER_ADDRESS"
#define USER_MQTT_PORT            1883
#define USER_MQTT_USERNAME        "YOUR_MQTT_USERNAME"
#define USER_MQTT_PASSWORD        "YOUR_MQTT_PASSWORD"
#define USER_MQTT_CLIENT_NAME     "LightMCU"           // Used to define MQTT topics, MQTT Client ID, and ArduinoOTA


#define ZONEONE                         1                   //ZONEONE is pin D1, 1 = zone used 0 = zone unused
#define FIRSTZONE_SECTIONS              1                   //Number of roof sections setup below
#define FIRSTZONE_LEDS                  300                 //Number of LEDS in this zone (comment out if zone is unused)
#define FIRSTZONE_COLOR_ORDER           GRB                 //Color orders, can be RGB, RBG, GRB, GBR, BRG, BGR (comment out if zone is unused)


#define ZONETWO                         1                   //ZONETWO is pin D2, 1 = zone used 0 = zone unused
#define SECONDZONE_SECTIONS             1                   //Number of roof sections setup below
#define SECONDZONE_LEDS                 300                 //Number of LEDS in this zone (comment out if zone is unused)
#define SECONDZONE_COLOR_ORDER          GRB                 //Color orders, can be RGB, RBG, GRB, GBR, BRG, BGR (comment out if zone is unused)


#define ZONETHREE                       1                   //ZONETHREE is pin D3, 1 = zone used 0 = zone unused
#define THIRDZONE_SECTIONS              1                   //Number of roof sections setup below
#define THIRDZONE_LEDS                  300                 //Number of LEDS in this zone (comment out if zone is unused)
#define THIRDZONE_COLOR_ORDER           GRB                 //Color orders, can be RGB, RBG, GRB, GBR, BRG, BGR (comment out if zone is unused)


#define ZONEFOUR                        1                   //ZONEFOUR is pin D5, 1 = zone used 0 = zone unused
#define FOURTHZONE_SECTIONS             1                   //Number of roof sections setup below
#define FOURTHZONE_LEDS                 300                 //Number of LEDS in this zone (comment out if zone is unused)
#define FOURTHZONE_COLOR_ORDER          GRB                 //Color orders, can be RGB, RBG, GRB, GBR, BRG, BGR (comment out if zone is unused)

#define ZONEFIVE                        1                   //ZONEFIVE is pin D6, 1 = zone used 0 = zone unused
#define FIFTHZONE_SECTIONS              1                   //Number of roof sections setup below
#define FIFTHZONE_LEDS                  300                 //Number of LEDS in this zone (comment out if zone is unused)
#define FIFTHZONE_COLOR_ORDER           GRB                 //Color orders, can be RGB, RBG, GRB, GBR, BRG, BGR (comment out if zone is unused)

#define ZONESIX                         1                   //ZONESIX is pin D7, 1 = zone used 0 = zone unused
#define SIXTHZONE_SECTIONS              1                   //Number of roof sections setup below
#define SIXTHZONE_LEDS                  300                 //Number of LEDS in this zone (comment out if zone is unused)
#define SIXTHZONE_COLOR_ORDER           GRB                 //Color orders, can be RGB, RBG, GRB, GBR, BRG, BGR (comment out if zone is unused)

/*****************************    ZONEONE ROOF SETUP    *************************************/
/*****************************    ZONEONE ROOF SETUP    *************************************/

#if  FIRSTZONE_SECTIONS >= 1        
#define ZONEONE_SECTION1_START            0           //starting LED for this zone
#define ZONEONE_SECTION1_END              100         //ending LED for this zone
#define ZONEONE_SECTION1_START_FIRE       1           //would you like fire to begin from this point? 0 = no 1 = yes
#define ZONEONE_SECTION1_END_FIRE         1           //would you like fire to begin from this point? 0 = no 1 = yes
#endif

#if  FIRSTZONE_SECTIONS >= 2
#define ZONEONE_SECTION2_START            0           //starting LED for this zone
#define ZONEONE_SECTION2_END              100         //ending LED for this zone
#define ZONEONE_SECTION2_START_FIRE       1           //would you like fire to begin from this point? 0 = no 1 = yes
#define ZONEONE_SECTION2_END_FIRE         1           //would you like fire to begin from this point? 0 = no 1 = yes
#endif

#if  FIRSTZONE_SECTIONS >= 3
#define ZONEONE_SECTION3_START            0           //starting LED for this zone
#define ZONEONE_SECTION3_END              100         //ending LED for this zone
#define ZONEONE_SECTION3_START_FIRE       1           //would you like fire to begin from this point? 0 = no 1 = yes
#define ZONEONE_SECTION3_END_FIRE         1           //would you like fire to begin from this point? 0 = no 1 = yes
#endif

#if  FIRSTZONE_SECTIONS >= 4
#define ZONEONE_SECTION4_START            0           //starting LED for this zone
#define ZONEONE_SECTION4_END              100         //ending LED for this zone
#define ZONEONE_SECTION4_START_FIRE       1           //would you like fire to begin from this point? 0 = no 1 = yes
#define ZONEONE_SECTION4_END_FIRE         1           //would you like fire to begin from this point? 0 = no 1 = yes
#endif

#if  FIRSTZONE_SECTIONS >= 5
#define ZONEONE_SECTION5_START            0           //starting LED for this zone
#define ZONEONE_SECTION5_END              100         //ending LED for this zone
#define ZONEONE_SECTION5_START_FIRE       1           //would you like fire to begin from this point? 0 = no 1 = yes
#define ZONEONE_SECTION5_END_FIRE         1           //would you like fire to begin from this point? 0 = no 1 = yes
#endif

#if  FIRSTZONE_SECTIONS >= 6
#define ZONEONE_SECTION6_START            0           //starting LED for this zone
#define ZONEONE_SECTION6_END              100         //ending LED for this zone
#define ZONEONE_SECTION6_START_FIRE       1           //would you like fire to begin from this point? 0 = no 1 = yes
#define ZONEONE_SECTION6_END_FIRE         1           //would you like fire to begin from this point? 0 = no 1 = yes
#endif

#if  FIRSTZONE_SECTIONS >= 7
#define ZONEONE_SECTION7_START            0          //starting LED for this zone
#define ZONEONE_SECTION7_END              100        //ending LED for this zone
#define ZONEONE_SECTION7_START_FIRE       1          //would you like fire to begin from this point? 0 = no 1 = yes
#define ZONEONE_SECTION7_END_FIRE         1          //would you like fire to begin from this point? 0 = no 1 = yes
#endif

#if  FIRSTZONE_SECTIONS >= 8
#define ZONEONE_SECTION8_START            0          //starting LED for this zone
#define ZONEONE_SECTION8_END              100        //ending LED for this zone
#define ZONEONE_SECTION8_START_FIRE       1          //would you like fire to begin from this point? 0 = no 1 = yes
#define ZONEONE_SECTION8_END_FIRE         1          //would you like fire to begin from this point? 0 = no 1 = yes
#endif

#if  FIRSTZONE_SECTIONS >= 9
#define ZONEONE_SECTION9_START            0          //starting LED for this zone
#define ZONEONE_SECTION9_END              100        //ending LED for this zone
#define ZONEONE_SECTION9_START_FIRE       1          //would you like fire to begin from this point? 0 = no 1 = yes
#define ZONEONE_SECTION9_END_FIRE         1          //would you like fire to begin from this point? 0 = no 1 = yes
#endif

/*****************************    ZONETWO ROOF SETUP    *************************************/
/*****************************    ZONETWO ROOF SETUP    *************************************/

#if  SECONDZONE_SECTIONS >= 1        
#define ZONETWO_SECTION1_START            0           //starting LED for this zone
#define ZONETWO_SECTION1_END              44         //ending LED for this zone
#define ZONETWO_SECTION1_START_FIRE       1           //would you like fire to begin from this point? 0 = no 1 = yes
#define ZONETWO_SECTION1_END_FIRE         1           //would you like fire to begin from this point? 0 = no 1 = yes
#endif

#if  SECONDZONE_SECTIONS >= 2
#define ZONETWO_SECTION2_START            44           //starting LED for this zone
#define ZONETWO_SECTION2_END              87         //ending LED for this zone
#define ZONETWO_SECTION2_START_FIRE       1           //would you like fire to begin from this point? 0 = no 1 = yes
#define ZONETWO_SECTION2_END_FIRE         1           //would you like fire to begin from this point? 0 = no 1 = yes
#endif

#if  SECONDZONE_SECTIONS >= 3
#define ZONETWO_SECTION3_START            88           //starting LED for this zone
#define ZONETWO_SECTION3_END              94         //ending LED for this zone
#define ZONETWO_SECTION3_START_FIRE       1           //would you like fire to begin from this point? 0 = no 1 = yes
#define ZONETWO_SECTION3_END_FIRE         1           //would you like fire to begin from this point? 0 = no 1 = yes
#endif

#if  SECONDZONE_SECTIONS >= 4
#define ZONETWO_SECTION4_START            95           //starting LED for this zone
#define ZONETWO_SECTION4_END              182         //ending LED for this zone
#define ZONETWO_SECTION4_START_FIRE       1           //would you like fire to begin from this point? 0 = no 1 = yes
#define ZONETWO_SECTION4_END_FIRE         1           //would you like fire to begin from this point? 0 = no 1 = yes
#endif

#if  SECONDZONE_SECTIONS >= 5
#define ZONETWO_SECTION5_START            183           //starting LED for this zone
#define ZONETWO_SECTION5_END              189         //ending LED for this zone
#define ZONETWO_SECTION5_START_FIRE       1           //would you like fire to begin from this point? 0 = no 1 = yes
#define ZONETWO_SECTION5_END_FIRE         1           //would you like fire to begin from this point? 0 = no 1 = yes
#endif

#if  SECONDZONE_SECTIONS >= 6
#define ZONETWO_SECTION6_START            190           //starting LED for this zone
#define ZONETWO_SECTION6_END              286         //ending LED for this zone
#define ZONETWO_SECTION6_START_FIRE       1           //would you like fire to begin from this point? 0 = no 1 = yes
#define ZONETWO_SECTION6_END_FIRE         1           //would you like fire to begin from this point? 0 = no 1 = yes
#endif

#if  SECONDZONE_SECTIONS >= 7
#define ZONETWO_SECTION7_START            287          //starting LED for this zone
#define ZONETWO_SECTION7_END              382        //ending LED for this zone
#define ZONETWO_SECTION7_START_FIRE       1          //would you like fire to begin from this point? 0 = no 1 = yes
#define ZONETWO_SECTION7_END_FIRE         1          //would you like fire to begin from this point? 0 = no 1 = yes
#endif

#if  SECONDZONE_SECTIONS >= 8
#define ZONETWO_SECTION8_START            0          //starting LED for this zone
#define ZONETWO_SECTION8_END              100        //ending LED for this zone
#define ZONETWO_SECTION8_START_FIRE       1          //would you like fire to begin from this point? 0 = no 1 = yes
#define ZONETWO_SECTION8_END_FIRE         1          //would you like fire to begin from this point? 0 = no 1 = yes
#endif

#if  SECONDZONE_SECTIONS >= 9
#define ZONETWO_SECTION9_START            0          //starting LED for this zone
#define ZONETWO_SECTION9_END              100        //ending LED for this zone
#define ZONETWO_SECTION9_START_FIRE       1          //would you like fire to begin from this point? 0 = no 1 = yes
#define ZONETWO_SECTION9_END_FIRE         1          //would you like fire to begin from this point? 0 = no 1 = yes
#endif


/*****************************    ZONETHREE ROOF SETUP    *************************************/
/*****************************    ZONETHREE ROOF SETUP    *************************************/

#if  THIRDZONE_SECTIONS >= 1        
#define ZONETHREE_SECTION1_START            0           //starting LED for this zone
#define ZONETHREE_SECTION1_END              100         //ending LED for this zone
#define ZONETHREE_SECTION1_START_FIRE       1           //would you like fire to begin from this point? 0 = no 1 = yes
#define ZONETHREE_SECTION1_END_FIRE         1           //would you like fire to begin from this point? 0 = no 1 = yes
#endif

#if  THIRDZONE_SECTIONS >= 2
#define ZONETHREE_SECTION2_START            0           //starting LED for this zone
#define ZONETHREE_SECTION2_END              100         //ending LED for this zone
#define ZONETHREE_SECTION2_START_FIRE       1           //would you like fire to begin from this point? 0 = no 1 = yes
#define ZONETHREE_SECTION2_END_FIRE         1           //would you like fire to begin from this point? 0 = no 1 = yes
#endif

#if  THIRDZONE_SECTIONS >= 3
#define ZONETHREE_SECTION3_START            0           //starting LED for this zone
#define ZONETHREE_SECTION3_END              100         //ending LED for this zone
#define ZONETHREE_SECTION3_START_FIRE       1           //would you like fire to begin from this point? 0 = no 1 = yes
#define ZONETHREE_SECTION3_END_FIRE         1           //would you like fire to begin from this point? 0 = no 1 = yes
#endif

#if  THIRDZONE_SECTIONS >= 4
#define ZONETHREE_SECTION4_START            0           //starting LED for this zone
#define ZONETHREE_SECTION4_END              100         //ending LED for this zone
#define ZONETHREE_SECTION4_START_FIRE       1           //would you like fire to begin from this point? 0 = no 1 = yes
#define ZONETHREE_SECTION4_END_FIRE         1           //would you like fire to begin from this point? 0 = no 1 = yes
#endif

#if  THIRDZONE_SECTIONS >= 5
#define ZONETHREE_SECTION5_START            0           //starting LED for this zone
#define ZONETHREE_SECTION5_END              100         //ending LED for this zone
#define ZONETHREE_SECTION5_START_FIRE       1           //would you like fire to begin from this point? 0 = no 1 = yes
#define ZONETHREE_SECTION5_END_FIRE         1           //would you like fire to begin from this point? 0 = no 1 = yes
#endif

#if  THIRDZONE_SECTIONS >= 6
#define ZONETHREE_SECTION6_START            0           //starting LED for this zone
#define ZONETHREE_SECTION6_END              100         //ending LED for this zone
#define ZONETHREE_SECTION6_START_FIRE       1           //would you like fire to begin from this point? 0 = no 1 = yes
#define ZONETHREE_SECTION6_END_FIRE         1           //would you like fire to begin from this point? 0 = no 1 = yes
#endif

#if  THIRDZONE_SECTIONS >= 7
#define ZONETHREE_SECTION7_START            0          //starting LED for this zone
#define ZONETHREE_SECTION7_END              100        //ending LED for this zone
#define ZONETHREE_SECTION7_START_FIRE       1          //would you like fire to begin from this point? 0 = no 1 = yes
#define ZONETHREE_SECTION7_END_FIRE         1          //would you like fire to begin from this point? 0 = no 1 = yes
#endif

#if  THIRDZONE_SECTIONS >= 8
#define ZONETHREE_SECTION8_START            0          //starting LED for this zone
#define ZONETHREE_SECTION8_END              100        //ending LED for this zone
#define ZONETHREE_SECTION8_START_FIRE       1          //would you like fire to begin from this point? 0 = no 1 = yes
#define ZONETHREE_SECTION8_END_FIRE         1          //would you like fire to begin from this point? 0 = no 1 = yes
#endif

#if  THIRDZONE_SECTIONS >= 9
#define ZONETHREE_SECTION9_START            0          //starting LED for this zone
#define ZONETHREE_SECTION9_END              100        //ending LED for this zone
#define ZONETHREE_SECTION9_START_FIRE       1          //would you like fire to begin from this point? 0 = no 1 = yes
#define ZONETHREE_SECTION9_END_FIRE         1          //would you like fire to begin from this point? 0 = no 1 = yes
#endif

/*****************************    ZONEFOUR ROOF SETUP    *************************************/
/*****************************    ZONEFOUR ROOF SETUP    *************************************/

#if  FOURTHZONE_SECTIONS >= 1        
#define ZONEFOUR_SECTION1_START            0           //starting LED for this zone
#define ZONEFOUR_SECTION1_END              100         //ending LED for this zone
#define ZONEFOUR_SECTION1_START_FIRE       1           //would you like fire to begin from this point? 0 = no 1 = yes
#define ZONEFOUR_SECTION1_END_FIRE         1           //would you like fire to begin from this point? 0 = no 1 = yes
#endif

#if  FOURTHZONE_SECTIONS >= 2
#define ZONEFOUR_SECTION2_START            0           //starting LED for this zone
#define ZONEFOUR_SECTION2_END              100         //ending LED for this zone
#define ZONEFOUR_SECTION2_START_FIRE       1           //would you like fire to begin from this point? 0 = no 1 = yes
#define ZONEFOUR_SECTION2_END_FIRE         1           //would you like fire to begin from this point? 0 = no 1 = yes
#endif

#if  FOURTHZONE_SECTIONS >= 3
#define ZONEFOUR_SECTION3_START            0           //starting LED for this zone
#define ZONEFOUR_SECTION3_END              100         //ending LED for this zone
#define ZONEFOUR_SECTION3_START_FIRE       1           //would you like fire to begin from this point? 0 = no 1 = yes
#define ZONEFOUR_SECTION3_END_FIRE         1           //would you like fire to begin from this point? 0 = no 1 = yes
#endif

#if  FOURTHZONE_SECTIONS >= 4
#define ZONEFOUR_SECTION4_START            0           //starting LED for this zone
#define ZONEFOUR_SECTION4_END              100         //ending LED for this zone
#define ZONEFOUR_SECTION4_START_FIRE       1           //would you like fire to begin from this point? 0 = no 1 = yes
#define ZONEFOUR_SECTION4_END_FIRE         1           //would you like fire to begin from this point? 0 = no 1 = yes
#endif

#if  FOURTHZONE_SECTIONS >= 5
#define ZONEFOUR_SECTION5_START            0           //starting LED for this zone
#define ZONEFOUR_SECTION5_END              100         //ending LED for this zone
#define ZONEFOUR_SECTION5_START_FIRE       1           //would you like fire to begin from this point? 0 = no 1 = yes
#define ZONEFOUR_SECTION5_END_FIRE         1           //would you like fire to begin from this point? 0 = no 1 = yes
#endif

#if  FOURTHZONE_SECTIONS >= 6
#define ZONEFOUR_SECTION6_START            0           //starting LED for this zone
#define ZONEFOUR_SECTION6_END              100         //ending LED for this zone
#define ZONEFOUR_SECTION6_START_FIRE       1           //would you like fire to begin from this point? 0 = no 1 = yes
#define ZONEFOUR_SECTION6_END_FIRE         1           //would you like fire to begin from this point? 0 = no 1 = yes
#endif

#if  FOURTHZONE_SECTIONS >= 7
#define ZONEFOUR_SECTION7_START            0          //starting LED for this zone
#define ZONEFOUR_SECTION7_END              100        //ending LED for this zone
#define ZONEFOUR_SECTION7_START_FIRE       1          //would you like fire to begin from this point? 0 = no 1 = yes
#define ZONEFOUR_SECTION7_END_FIRE         1          //would you like fire to begin from this point? 0 = no 1 = yes
#endif

#if  FOURTHZONE_SECTIONS >= 8
#define ZONEFOUR_SECTION8_START            0          //starting LED for this zone
#define ZONEFOUR_SECTION8_END              100        //ending LED for this zone
#define ZONEFOUR_SECTION8_START_FIRE       1          //would you like fire to begin from this point? 0 = no 1 = yes
#define ZONEFOUR_SECTION8_END_FIRE         1          //would you like fire to begin from this point? 0 = no 1 = yes
#endif

#if  FOURTHZONE_SECTIONS >= 9
#define ZONEFOUR_SECTION9_START            0          //starting LED for this zone
#define ZONEFOUR_SECTION9_END              100        //ending LED for this zone
#define ZONEFOUR_SECTION9_START_FIRE       1          //would you like fire to begin from this point? 0 = no 1 = yes
#define ZONEFOUR_SECTION9_END_FIRE         1          //would you like fire to begin from this point? 0 = no 1 = yes
#endif


/*****************************    ZONEFIVE ROOF SETUP    *************************************/
/*****************************    ZONEFIVE ROOF SETUP    *************************************/

#if  FIFTHZONE_SECTIONS >= 1        
#define ZONEFIVE_SECTION1_START            0           //starting LED for this zone
#define ZONEFIVE_SECTION1_END              100         //ending LED for this zone
#define ZONEFIVE_SECTION1_START_FIRE       1           //would you like fire to begin from this point? 0 = no 1 = yes
#define ZONEFIVE_SECTION1_END_FIRE         1           //would you like fire to begin from this point? 0 = no 1 = yes
#endif

#if  FIFTHZONE_SECTIONS >= 2
#define ZONEFIVE_SECTION2_START            0           //starting LED for this zone
#define ZONEFIVE_SECTION2_END              100         //ending LED for this zone
#define ZONEFIVE_SECTION2_START_FIRE       1           //would you like fire to begin from this point? 0 = no 1 = yes
#define ZONEFIVE_SECTION2_END_FIRE         1           //would you like fire to begin from this point? 0 = no 1 = yes
#endif

#if  FIFTHZONE_SECTIONS >= 3
#define ZONEFIVE_SECTION3_START            0           //starting LED for this zone
#define ZONEFIVE_SECTION3_END              100         //ending LED for this zone
#define ZONEFIVE_SECTION3_START_FIRE       1           //would you like fire to begin from this point? 0 = no 1 = yes
#define ZONEFIVE_SECTION3_END_FIRE         1           //would you like fire to begin from this point? 0 = no 1 = yes
#endif

#if  FIFTHZONE_SECTIONS >= 4
#define ZONEFIVE_SECTION4_START            0           //starting LED for this zone
#define ZONEFIVE_SECTION4_END              100         //ending LED for this zone
#define ZONEFIVE_SECTION4_START_FIRE       1           //would you like fire to begin from this point? 0 = no 1 = yes
#define ZONEFIVE_SECTION4_END_FIRE         1           //would you like fire to begin from this point? 0 = no 1 = yes
#endif

#if  FIFTHZONE_SECTIONS >= 5
#define ZONEFIVE_SECTION5_START            0           //starting LED for this zone
#define ZONEFIVE_SECTION5_END              100         //ending LED for this zone
#define ZONEFIVE_SECTION5_START_FIRE       1           //would you like fire to begin from this point? 0 = no 1 = yes
#define ZONEFIVE_SECTION5_END_FIRE         1           //would you like fire to begin from this point? 0 = no 1 = yes
#endif

#if  FIFTHZONE_SECTIONS >= 6
#define ZONEFIVE_SECTION6_START            0           //starting LED for this zone
#define ZONEFIVE_SECTION6_END              100         //ending LED for this zone
#define ZONEFIVE_SECTION6_START_FIRE       1           //would you like fire to begin from this point? 0 = no 1 = yes
#define ZONEFIVE_SECTION6_END_FIRE         1           //would you like fire to begin from this point? 0 = no 1 = yes
#endif

#if  FIFTHZONE_SECTIONS >= 7
#define ZONEFIVE_SECTION7_START            0          //starting LED for this zone
#define ZONEFIVE_SECTION7_END              100        //ending LED for this zone
#define ZONEFIVE_SECTION7_START_FIRE       1          //would you like fire to begin from this point? 0 = no 1 = yes
#define ZONEFIVE_SECTION7_END_FIRE         1          //would you like fire to begin from this point? 0 = no 1 = yes
#endif

#if  FIFTHZONE_SECTIONS >= 8
#define ZONEFIVE_SECTION8_START            0          //starting LED for this zone
#define ZONEFIVE_SECTION8_END              100        //ending LED for this zone
#define ZONEFIVE_SECTION8_START_FIRE       1          //would you like fire to begin from this point? 0 = no 1 = yes
#define ZONEFIVE_SECTION8_END_FIRE         1          //would you like fire to begin from this point? 0 = no 1 = yes
#endif

#if  FIFTHZONE_SECTIONS >= 9
#define ZONEFIVE_SECTION9_START            0          //starting LED for this zone
#define ZONEFIVE_SECTION9_END              100        //ending LED for this zone
#define ZONEFIVE_SECTION9_START_FIRE       1          //would you like fire to begin from this point? 0 = no 1 = yes
#define ZONEFIVE_SECTION9_END_FIRE         1          //would you like fire to begin from this point? 0 = no 1 = yes
#endif


/*****************************    ZONESIX ROOF SETUP    *************************************/
/*****************************    ZONESIX ROOF SETUP    *************************************/

#if  SIXTHZONE_SECTIONS >= 1        
#define ZONESIX_SECTION1_START            0           //starting LED for this zone
#define ZONESIX_SECTION1_END              100         //ending LED for this zone
#define ZONESIX_SECTION1_START_FIRE       1           //would you like fire to begin from this point? 0 = no 1 = yes
#define ZONESIX_SECTION1_END_FIRE         1           //would you like fire to begin from this point? 0 = no 1 = yes
#endif

#if  SIXTHZONE_SECTIONS >= 2
#define ZONESIX_SECTION2_START            0           //starting LED for this zone
#define ZONESIX_SECTION2_END              100         //ending LED for this zone
#define ZONESIX_SECTION2_START_FIRE       1           //would you like fire to begin from this point? 0 = no 1 = yes
#define ZONESIX_SECTION2_END_FIRE         1           //would you like fire to begin from this point? 0 = no 1 = yes
#endif

#if  SIXTHZONE_SECTIONS >= 3
#define ZONESIX_SECTION3_START            0           //starting LED for this zone
#define ZONESIX_SECTION3_END              100         //ending LED for this zone
#define ZONESIX_SECTION3_START_FIRE       1           //would you like fire to begin from this point? 0 = no 1 = yes
#define ZONESIX_SECTION3_END_FIRE         1           //would you like fire to begin from this point? 0 = no 1 = yes
#endif

#if  SIXTHZONE_SECTIONS >= 4
#define ZONESIX_SECTION4_START            0           //starting LED for this zone
#define ZONESIX_SECTION4_END              100         //ending LED for this zone
#define ZONESIX_SECTION4_START_FIRE       1           //would you like fire to begin from this point? 0 = no 1 = yes
#define ZONESIX_SECTION4_END_FIRE         1           //would you like fire to begin from this point? 0 = no 1 = yes
#endif

#if  SIXTHZONE_SECTIONS >= 5
#define ZONESIX_SECTION5_START            0           //starting LED for this zone
#define ZONESIX_SECTION5_END              100         //ending LED for this zone
#define ZONESIX_SECTION5_START_FIRE       1           //would you like fire to begin from this point? 0 = no 1 = yes
#define ZONESIX_SECTION5_END_FIRE         1           //would you like fire to begin from this point? 0 = no 1 = yes
#endif

#if  SIXTHZONE_SECTIONS >= 6
#define ZONESIX_SECTION6_START            0           //starting LED for this zone
#define ZONESIX_SECTION6_END              100         //ending LED for this zone
#define ZONESIX_SECTION6_START_FIRE       1           //would you like fire to begin from this point? 0 = no 1 = yes
#define ZONESIX_SECTION6_END_FIRE         1           //would you like fire to begin from this point? 0 = no 1 = yes
#endif

#if  SIXTHZONE_SECTIONS >= 7
#define ZONESIX_SECTION7_START            0          //starting LED for this zone
#define ZONESIX_SECTION7_END              100        //ending LED for this zone
#define ZONESIX_SECTION7_START_FIRE       1          //would you like fire to begin from this point? 0 = no 1 = yes
#define ZONESIX_SECTION7_END_FIRE         1          //would you like fire to begin from this point? 0 = no 1 = yes
#endif

#if  SIXTHZONE_SECTIONS >= 8
#define ZONESIX_SECTION8_START            0          //starting LED for this zone
#define ZONESIX_SECTION8_END              100        //ending LED for this zone
#define ZONESIX_SECTION8_START_FIRE       1          //would you like fire to begin from this point? 0 = no 1 = yes
#define ZONESIX_SECTION8_END_FIRE         1          //would you like fire to begin from this point? 0 = no 1 = yes
#endif

#if  SIXTHZONE_SECTIONS >= 9
#define ZONESIX_SECTION9_START            0          //starting LED for this zone
#define ZONESIX_SECTION9_END              100        //ending LED for this zone
#define ZONESIX_SECTION9_START_FIRE       1          //would you like fire to begin from this point? 0 = no 1 = yes
#define ZONESIX_SECTION9_END_FIRE         1          //would you like fire to begin from this point? 0 = no 1 = yes
#endif


/*****************  END USER CONFIG SECTION *********************************/
/*****************  END USER CONFIG SECTION *********************************/
/*****************  END USER CONFIG SECTION *********************************/
/*****************  END USER CONFIG SECTION *********************************/
/*****************  END USER CONFIG SECTION *********************************/

/***********************  WIFI AND MQTT SETUP *****************************/
/***********************  DON'T CHANGE THIS INFO *****************************/

const char* ssid = USER_SSID ; 
const char* password = USER_PASSWORD ;
const char* mqtt_server = USER_MQTT_SERVER ;
const int mqtt_port = USER_MQTT_PORT ;
const char *mqtt_user = USER_MQTT_USERNAME ;
const char *mqtt_pass = USER_MQTT_PASSWORD ;
const char *mqtt_client_name = USER_MQTT_CLIENT_NAME ; 

/*****************  DECLARATIONS  ****************************************/
WiFiClient espClient;
PubSubClient client(espClient);
SimpleTimer timer;

#if ZONEONE == 1
CRGB firstZone[FIRSTZONE_LEDS];
const int Pin_firstZone = 5; //marked as D1 on the board
int center_firstZone = 0;
int step_firstZone = -1;
int previousLED_firstZone = 0;
#endif

#if ZONETWO == 1
CRGB secondZone[SECONDZONE_LEDS];
const int Pin_secondZone = 4; //marked as D2 on the board
int center_secondZone = 0;
int step_secondZone = -1;
int previousLED_secondZone = 0;
#endif

#if ZONETHREE == 1
CRGB thirdZone[THIRDZONE_LEDS];
const int Pin_thirdZone = 0; //marked as D3 on the board
int center_thirdZone = 0;
int step_thirdZone = -1;
int previousLED_thirdZone = 0;
#endif

#if ZONEFOUR == 1
CRGB fourthZone[FOURTHZONE_LEDS];
const int Pin_fourthZone = 14; //marked as D5 on the board
int center_fourthZone = 0;
int step_fourthZone = -1;
int previousLED_fourthZone = 0;
#endif

#if ZONEFIVE == 1
CRGB fifthZone[FIFTHZONE_LEDS];
const int Pin_fifthZone = 12; //marked as D6 on the board
int center_fifthZone = 0;
int step_fifthZone = -1;
int previousLED_fifthZone = 0;
#endif

#if ZONESIX == 1
CRGB sixthZone[SIXTHZONE_LEDS];
const int Pin_sixthZone = 13; //marked as D7 on the board
int center_sixthZone = 0;
int step_sixthZone = -1;
int previousLED_sixthZone = 0;
#endif



/*****************  GENERAL VARIABLES  *************************************/

CRGBPalette16 gPal;
int glitterFrequency = 100;
int lightningChance = 65280;
int firesize = 40;
int SPARKING = 85;
int COOLING =  120;
bool gReverseDirection = false;
uint8_t mark = 0;
uint8_t gHue = 0; 
uint8_t startPosition = 0;
uint8_t glitterChance = 250;
int chaseDelay = 1000;
int lastPosition = 1;
int lightning = 1;
int raceSpeed = 12;
int BeatsPerMinute = 62;
uint8_t numberOfRainbows = 7;
int twinkleChance = 250;
int eyeChance = 248;
bool boot = true;
String effect = "None";
bool showGlitter = false;
bool showLightning = false;
bool audioEffects = false;
bool showLights = false;
byte red1 = 255;
byte green1 = 0;
byte blue1 = 0;
byte red2 = 0;
byte green2 = 255;
byte blue2 = 0;
byte red3 = 0;
byte green3 = 0;
byte blue3 = 255;
byte redG = 255;
byte greenG = 255;
byte blueG = 255;
byte brightness = 255;
char charPayload[50];
int maxLEDs = 500;
int locatorLED = 0;
char MQTT_locatorLED[50];
int locatorDelay = 1000;


/*****************  SYSTEM FUNCTIONS  *************************************/
/*****************  SYSTEM FUNCTIONS  *************************************/
/*****************  SYSTEM FUNCTIONS  *************************************/
/*****************  SYSTEM FUNCTIONS  *************************************/
/*****************  SYSTEM FUNCTIONS  *************************************/

void setup_wifi() 
{
  // We start by connecting to a WiFi network
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void reconnect() 
{
  // Loop until we're reconnected
  int retries = 0;
  while (!client.connected()) {
    if(retries < 150)
    {
        Serial.print("Attempting MQTT connection...");
      // Attempt to connect
      if (client.connect(mqtt_client_name, mqtt_user, mqtt_pass)) 
      {
        Serial.println("connected");
        // Once connected, publish an announcement...
        if(boot == true)
        {
          client.publish(USER_MQTT_CLIENT_NAME"/checkIn","Rebooted");
          boot = false;
        }
        if(boot == false)
        {
          client.publish(USER_MQTT_CLIENT_NAME"/checkIn","Reconnected"); 
        }
        // ... and resubscribe
        client.subscribe(USER_MQTT_CLIENT_NAME"/configure");
        client.subscribe(USER_MQTT_CLIENT_NAME"/modifier");
        client.subscribe(USER_MQTT_CLIENT_NAME"/effect");
        client.subscribe(USER_MQTT_CLIENT_NAME"/state");
        client.subscribe(USER_MQTT_CLIENT_NAME"/color1");
        client.subscribe(USER_MQTT_CLIENT_NAME"/color2");
        client.subscribe(USER_MQTT_CLIENT_NAME"/color3");
        client.subscribe(USER_MQTT_CLIENT_NAME"/power");
        client.subscribe(USER_MQTT_CLIENT_NAME"/brightness");
        client.subscribe(USER_MQTT_CLIENT_NAME"/addEffects");
        client.subscribe(USER_MQTT_CLIENT_NAME"/lightningChance");
        client.subscribe(USER_MQTT_CLIENT_NAME"/glitterChance");
        client.subscribe(USER_MQTT_CLIENT_NAME"/glitterColor");
      } 
      else 
      {
        Serial.print("failed, rc=");
        Serial.print(client.state());
        Serial.println(" try again in 5 seconds");
        retries++;
        // Wait 5 seconds before retrying
        delay(5000);
      }
    }
    if(retries > 1500)
    {
    ESP.restart();
    }
  }
}

void calculateMax()
{
  #if ZONETWO == 1
  maxLEDs = max(FIRSTZONE_LEDS, SECONDZONE_LEDS);
  #endif

  #if ZONETHREE == 1
  maxLEDs = max(maxLEDs, THIRDZONE_LEDS);
  #endif

  #if ZONEFOUR == 1
  maxLEDs = max(maxLEDs, FOURTHZONE_LEDS);
  #endif

  #if ZONEFIVE == 1
  maxLEDs = max(maxLEDs, FIFTHZONE_LEDS);
  #endif

  #if ZONESIX == 1
  maxLEDs = max(maxLEDs, SIXTHZONE_LEDS);
  #endif 
}

/************************** MQTT CALLBACK ***********************/
/************************** MQTT CALLBACK ***********************/
/************************** MQTT CALLBACK ***********************/
/************************** MQTT CALLBACK ***********************/
/************************** MQTT CALLBACK ***********************/


void callback(char* topic, byte* payload, unsigned int length) 
{
  Serial.print("Message arrived [");
  String newTopic = topic;
  Serial.print(topic);
  Serial.print("] ");
  payload[length] = '\0';
  String newPayload = String((char *)payload);
  int intPayload = newPayload.toInt();
  Serial.println(newPayload);
  Serial.println();
  newPayload.toCharArray(charPayload, newPayload.length() + 1); 
  if (newTopic == USER_MQTT_CLIENT_NAME"/modifier")
  {
    client.publish(USER_MQTT_CLIENT_NAME"/modifierState", charPayload);
    if(effect == "Double_Crash" || effect == "Single_Race")
    {
      raceSpeed = (intPayload/20);
    }
    if(effect == "BPM")
    {
      BeatsPerMinute = (intPayload/4);
    }
    if(effect == "Color_Chase" || effect == "Blocked_Colors")
    {
      chaseDelay = (intPayload*5);
      if(chaseDelay < 100)
      {
        chaseDelay = 100;
      }
    }
    if(effect == "Color_Glitter")
    {
      glitterChance = (intPayload/2);
    }
    if(effect == "Rainbow")
    {
      numberOfRainbows = (intPayload/30);
    }
    if(effect == "Twinkle")
    {
      twinkleChance = map(intPayload, 0, 500, 0, 255);
    }
    if(effect == "Spooky_Eyes")
    {
      eyeChance = map(intPayload, 0, 500, 0, 255);
    }
    if(effect == "LED_Locator")
    {
      locatorDelay = map(intPayload, 0, 500, 500, 5000);
    }
  }
  if (newTopic == USER_MQTT_CLIENT_NAME"/addEffects")
  {
    if(newPayload == "Audio On")
    {
      audioEffects = true;
      client.publish(USER_MQTT_CLIENT_NAME"/audio/state", charPayload);
    }
    if(newPayload == "Audio Off")
    {
      audioEffects = false;
      client.publish(USER_MQTT_CLIENT_NAME"/audio/state", charPayload);
    }
    if(newPayload == "Glitter On")
    {
      showGlitter = true;
      client.publish(USER_MQTT_CLIENT_NAME"/glitter/state", charPayload);
    }
    if(newPayload == "Glitter Off")
    {
      showGlitter = false;
      client.publish(USER_MQTT_CLIENT_NAME"/glitter/state", charPayload);
    }
    if(newPayload == "Lightning On")
    {
      showLightning = true;
      client.publish(USER_MQTT_CLIENT_NAME"/lightning/state","Lightning On");
    }
    if(newPayload == "Lightning Off")
    {
      showLightning = false;
      client.publish(USER_MQTT_CLIENT_NAME"/lightning/state","Lightning Off");
    }
  }
  if (newTopic == USER_MQTT_CLIENT_NAME"/effect") 
  {
    effect = newPayload;
    client.publish(USER_MQTT_CLIENT_NAME"/effectState", charPayload);
    
    #if ZONEONE == 1
    fill_solid(firstZone, FIRSTZONE_LEDS, CRGB::Black); 
    #endif

    #if ZONETWO == 1
    fill_solid(secondZone, SECONDZONE_LEDS, CRGB::Black); 
    #endif

    #if ZONETHREE == 1
    fill_solid(thirdZone, THIRDZONE_LEDS, CRGB::Black);
    #endif

    #if ZONEFOUR == 1
    fill_solid(fourthZone, FOURTHZONE_LEDS, CRGB::Black);
    #endif

    #if ZONEFIVE == 1
    fill_solid(fifthZone, FIFTHZONE_LEDS, CRGB::Black); 
    #endif
    
    #if ZONESIX == 1
    fill_solid(sixthZone, SIXTHZONE_LEDS, CRGB::Black);
    #endif  

    if(effect == "LED_Locator")
    {
      locator_Move();
    }
  }
  
  if (newTopic == USER_MQTT_CLIENT_NAME "/color1")
  {
    client.publish(USER_MQTT_CLIENT_NAME "/color1State", charPayload); 
    // get the position of the first and second commas
    uint8_t firstIndex = newPayload.indexOf(',');
    uint8_t lastIndex = newPayload.lastIndexOf(',');
    
    uint8_t rgb_red = newPayload.substring(0, firstIndex).toInt();
    if (rgb_red < 0 || rgb_red > 255) {
      return;
    } else {
      red1 = rgb_red;
    }
    
    uint8_t rgb_green = newPayload.substring(firstIndex + 1, lastIndex).toInt();
    if (rgb_green < 0 || rgb_green > 255) {
      return;
    } else {
      green1 = rgb_green;
    }
    
    uint8_t rgb_blue = newPayload.substring(lastIndex + 1).toInt();
    if (rgb_blue < 0 || rgb_blue > 255) {
      return;
    } else {
      blue1 = rgb_blue;
    }
  }

  if (newTopic == USER_MQTT_CLIENT_NAME "/color2")
  {
    client.publish(USER_MQTT_CLIENT_NAME "/color2State", charPayload); 
    // get the position of the first and second commas
    uint8_t firstIndex = newPayload.indexOf(',');
    uint8_t lastIndex = newPayload.lastIndexOf(',');
    
    uint8_t rgb_red = newPayload.substring(0, firstIndex).toInt();
    if (rgb_red < 0 || rgb_red > 255) {
      return;
    } else {
      red2 = rgb_red;
    }
    
    uint8_t rgb_green = newPayload.substring(firstIndex + 1, lastIndex).toInt();
    if (rgb_green < 0 || rgb_green > 255) {
      return;
    } else {
      green2 = rgb_green;
    }
    
    uint8_t rgb_blue = newPayload.substring(lastIndex + 1).toInt();
    if (rgb_blue < 0 || rgb_blue > 255) {
      return;
    } else {
      blue2 = rgb_blue;
    }
  }

  if (newTopic == USER_MQTT_CLIENT_NAME "/color3")
  {
    client.publish(USER_MQTT_CLIENT_NAME "/color3State", charPayload); 
    // get the position of the first and second commas
    uint8_t firstIndex = newPayload.indexOf(',');
    uint8_t lastIndex = newPayload.lastIndexOf(',');
    
    uint8_t rgb_red = newPayload.substring(0, firstIndex).toInt();
    if (rgb_red < 0 || rgb_red > 255) {
      return;
    } else {
      red3 = rgb_red;
    }
    
    uint8_t rgb_green = newPayload.substring(firstIndex + 1, lastIndex).toInt();
    if (rgb_green < 0 || rgb_green > 255) {
      return;
    } else {
      green3 = rgb_green;
    }
    
    uint8_t rgb_blue = newPayload.substring(lastIndex + 1).toInt();
    if (rgb_blue < 0 || rgb_blue > 255) {
      return;
    } else {
      blue3 = rgb_blue;
    }
  }

  if (newTopic == USER_MQTT_CLIENT_NAME "/glitterColor")
  {
    client.publish(USER_MQTT_CLIENT_NAME "/glitterColorState", charPayload); 
    // get the position of the first and second commas
    uint8_t firstIndex = newPayload.indexOf(',');
    uint8_t lastIndex = newPayload.lastIndexOf(',');
    
    uint8_t rgb_red = newPayload.substring(0, firstIndex).toInt();
    if (rgb_red < 0 || rgb_red > 255) {
      return;
    } else {
      redG = rgb_red;
    }
    
    uint8_t rgb_green = newPayload.substring(firstIndex + 1, lastIndex).toInt();
    if (rgb_green < 0 || rgb_green > 255) {
      return;
    } else {
      greenG = rgb_green;
    }
    
    uint8_t rgb_blue = newPayload.substring(lastIndex + 1).toInt();
    if (rgb_blue < 0 || rgb_blue > 255) {
      return;
    } else {
      blueG = rgb_blue;
    }
  }
  
  if (newTopic == USER_MQTT_CLIENT_NAME"/glitterChance") 
  {
    client.publish(USER_MQTT_CLIENT_NAME "/glitterChanceState", charPayload); 
    glitterFrequency = intPayload;
  }
  
  if (newTopic == USER_MQTT_CLIENT_NAME"/lightningChance") 
  {
    client.publish(USER_MQTT_CLIENT_NAME "/lightningChanceState", charPayload); 
    lightningChance = (65535 - intPayload);
  }
  
  if (newTopic == USER_MQTT_CLIENT_NAME"/power")
  {
    client.publish(USER_MQTT_CLIENT_NAME "/powerState", charPayload); 
    if(newPayload == "ON")
    {
      showLights = true;
    }
    if(newPayload == "OFF")
    {
      showLights = false;
    }
  }
}



/*****************  GLOBAL LIGHT FUNCTIONS  *******************************/
/*****************  GLOBAL LIGHT FUNCTIONS  *******************************/
/*****************  GLOBAL LIGHT FUNCTIONS  *******************************/
/*****************  GLOBAL LIGHT FUNCTIONS  *******************************/
/*****************  GLOBAL LIGHT FUNCTIONS  *******************************/


void chase()
{
  if(startPosition == 5)
  {
    startPosition = 0;
  }
  else
  {
    startPosition++;
  }
  timer.setTimeout(chaseDelay, chase);
}

void checkIn()
{
  client.publish(USER_MQTT_CLIENT_NAME"/checkIn","OK");
  timer.setTimeout(120000, checkIn);
}

void choosePattern()
{
  if(showLights == true)
  {
   if(effect == "Color_Chase")
   {
    #if ZONEONE == 1 
    RGB_firstZone();
    #endif

    #if ZONETWO == 1
    RGB_secondZone(); 
    #endif

    #if ZONETHREE == 1
    RGB_thirdZone();
    #endif

    #if ZONEFOUR == 1
    RGB_fourthZone();
    #endif

    #if ZONEFIVE == 1
    RGB_fifthZone();
    #endif
    
    #if ZONESIX == 1
    RGB_sixthZone();
    #endif 
      
   }
   if(effect == "Color_Glitter")
   {

    #if ZONEONE == 1 
    ColorGlitter_firstZone(glitterChance);
    #endif

    #if ZONETWO == 1
    ColorGlitter_secondZone(glitterChance); 
    #endif

    #if ZONETHREE == 1
    ColorGlitter_thirdZone(glitterChance);
    #endif

    #if ZONEFOUR == 1
    ColorGlitter_fourthZone(glitterChance);
    #endif

    #if ZONEFIVE == 1
    ColorGlitter_fifthZone(glitterChance);
    #endif
    
    #if ZONESIX == 1
    ColorGlitter_sixthZone(glitterChance);
    #endif  
   }
   if(effect == "Single_Race")
   {

    #if ZONEONE == 1 
    SingleRace_firstZone();
    #endif

    #if ZONETWO == 1
    SingleRace_secondZone(); 
    #endif

    #if ZONETHREE == 1
    SingleRace_thirdZone();
    #endif

    #if ZONEFOUR == 1
    SingleRace_fourthZone();
    #endif

    #if ZONEFIVE == 1
    SingleRace_fifthZone();
    #endif
    
    #if ZONESIX == 1
    SingleRace_sixthZone();
    #endif 
   }
   if(effect == "Double_Crash")
   {
    #if ZONEONE == 1
    Crash_firstZone();
    #endif

    #if ZONETWO == 1
    Crash_secondZone(); 
    #endif

    #if ZONETHREE == 1
    Crash_thirdZone();
    #endif

    #if ZONEFOUR == 1
    Crash_fourthZone();
    #endif

    #if ZONEFIVE == 1
    Crash_fifthZone();
    #endif
    
    #if ZONESIX == 1
    Crash_sixthZone();
    #endif 
   }
   if(effect == "Rainbow")
   {
    #if ZONEONE == 1  
    Rainbow_firstZone();
    #endif

    #if ZONETWO == 1
    Rainbow_secondZone(); 
    #endif

    #if ZONETHREE == 1
    Rainbow_thirdZone();
    #endif

    #if ZONEFOUR == 1
    Rainbow_fourthZone();
    #endif

    #if ZONEFIVE == 1
    Rainbow_fifthZone();
    #endif
    
    #if ZONESIX == 1
    Rainbow_sixthZone();
    #endif 
   }
   if(effect == "Blocked_Colors")
   {
    #if ZONEONE == 1
    Blocked_firstZone();
    #endif

    #if ZONETWO == 1
    Blocked_secondZone(); 
    #endif

    #if ZONETHREE == 1
    Blocked_thirdZone();
    #endif

    #if ZONEFOUR == 1
    Blocked_fourthZone();
    #endif

    #if ZONEFIVE == 1
    Blocked_fifthZone();
    #endif
    
    #if ZONESIX == 1
    Blocked_sixthZone();
    #endif 

   }
   if(effect == "BPM")
   {

    #if ZONEONE == 1
    BPM_firstZone();
    #endif

    #if ZONETWO == 1
    BPM_secondZone(); 
    #endif

    #if ZONETHREE == 1
    BPM_thirdZone();
    #endif

    #if ZONEFOUR == 1
    BPM_fourthZone();
    #endif

    #if ZONEFIVE == 1
    BPM_fifthZone();
    #endif
    
    #if ZONESIX == 1
    BPM_sixthZone();
    #endif 
   }
   if(effect == "Twinkle")
   {
    #if ZONEONE == 1
    Twinkle_firstZone();
    #endif

    #if ZONETWO == 1
    Twinkle_secondZone(); 
    #endif

    #if ZONETHREE == 1
    Twinkle_thirdZone();
    #endif

    #if ZONEFOUR == 1
    Twinkle_fourthZone();
    #endif

    #if ZONEFIVE == 1
    Twinkle_fifthZone();
    #endif
    
    #if ZONESIX == 1
    Twinkle_sixthZone();
    #endif 

   }
   if(effect == "Fill_Solid")
   {
    #if ZONEONE == 1
    Solid_firstZone();
    #endif

    #if ZONETWO == 1
    Solid_secondZone(); 
    #endif

    #if ZONETHREE == 1
    Solid_thirdZone();
    #endif

    #if ZONEFOUR == 1
    Solid_fourthZone();
    #endif

    #if ZONEFIVE == 1
    Solid_fifthZone();
    #endif
    
    #if ZONESIX == 1
    Solid_sixthZone();
    #endif
    
   }
   if(effect == "Spooky_Eyes")
   {
    #if ZONEONE == 1
    Eyes_firstZone();
    #endif

    #if ZONETWO == 1
    Eyes_secondZone(); 
    #endif

    #if ZONETHREE == 1
    Eyes_thirdZone();
    #endif

    #if ZONEFOUR == 1
    Eyes_fourthZone();
    #endif

    #if ZONEFIVE == 1
    Eyes_fifthZone();
    #endif
    
    #if ZONESIX == 1
    Eyes_sixthZone();
    #endif

   }
   
   if(effect == "LED_Locator")
   {
    #if ZONEONE == 1
    Locator_firstZone();
    #endif

    #if ZONETWO == 1
    Locator_secondZone(); 
    #endif

    #if ZONETHREE == 1
    Locator_thirdZone();
    #endif

    #if ZONEFOUR == 1
    Locator_fourthZone();
    #endif

    #if ZONEFIVE == 1
    Locator_fifthZone();
    #endif
    
    #if ZONESIX == 1
    Locator_sixthZone();
    #endif

   }
   if(effect == "Ripple")
   {

    #if ZONEONE == 1 
    Ripple_firstZone();
    #endif

    #if ZONETWO == 1
    Ripple_secondZone(); 
    #endif

    #if ZONETHREE == 1
    Ripple_thirdZone();
    #endif

    #if ZONEFOUR == 1
    Ripple_fourthZone();
    #endif

    #if ZONEFIVE == 1
    Ripple_fifthZone();
    #endif
    
    #if ZONESIX == 1
    Ripple_sixthZone();
    #endif
   }
   if(effect == "Fire")
   {

    #if ZONEONE == 1 
      #if FIRSTZONE_SECTIONS >= 1
      fire_firstZone_SECTION1();
      #endif
      #if FIRSTZONE_SECTIONS >= 2
      fire_firstZone_SECTION2();
      #endif
      #if FIRSTZONE_SECTIONS >= 3
      fire_firstZone_SECTION3();
      #endif
      #if FIRSTZONE_SECTIONS >= 4
      fire_firstZone_SECTION4();
      #endif
      #if FIRSTZONE_SECTIONS >= 5
      fire_firstZone_SECTION5();
      #endif
      #if FIRSTZONE_SECTIONS >= 6
      fire_firstZone_SECTION6();
      #endif
      #if FIRSTZONE_SECTIONS >= 7
      fire_firstZone_SECTION7();
      #endif
      #if FIRSTZONE_SECTIONS >= 8
      fire_firstZone_SECTION8();
      #endif
      #if FIRSTZONE_SECTIONS >= 9
      fire_firstZone_SECTION9();
      #endif
    #endif

    #if ZONETWO == 1 
      #if SECONDZONE_SECTIONS >= 1
      fire_secondZone_SECTION1();
      #endif
      #if SECONDZONE_SECTIONS >= 2
      fire_secondZone_SECTION2();
      #endif
      #if SECONDZONE_SECTIONS >= 3
      fire_secondZone_SECTION3();
      #endif
      #if SECONDZONE_SECTIONS >= 4
      fire_secondZone_SECTION4();
      #endif
      #if SECONDZONE_SECTIONS >= 5
      fire_secondZone_SECTION5();
      #endif
      #if SECONDZONE_SECTIONS >= 6
      fire_secondZone_SECTION6();
      #endif
      #if SECONDZONE_SECTIONS >= 7
      fire_secondZone_SECTION7();
      #endif
      #if SECONDZONE_SECTIONS >= 8
      fire_secondZone_SECTION8();
      #endif
      #if SECONDZONE_SECTIONS >= 9
      fire_secondZone_SECTION9();
      #endif
    #endif

    #if ZONETHREE == 1 
      #if THIRDZONE_SECTIONS >= 1
      fire_thirdZone_SECTION1();
      #endif
      #if THIRDZONE_SECTIONS >= 2
      fire_thirdZone_SECTION2();
      #endif
      #if THIRDZONE_SECTIONS >= 3
      fire_thirdZone_SECTION3();
      #endif
      #if THIRDZONE_SECTIONS >= 4
      fire_thirdZone_SECTION4();
      #endif
      #if THIRDZONE_SECTIONS >= 5
      fire_thirdZone_SECTION5();
      #endif
      #if THIRDZONE_SECTIONS >= 6
      fire_thirdZone_SECTION6();
      #endif
      #if THIRDZONE_SECTIONS >= 7
      fire_thirdZone_SECTION7();
      #endif
      #if THIRDZONE_SECTIONS >= 8
      fire_thirdZone_SECTION8();
      #endif
      #if THIRDZONE_SECTIONS >= 9
      fire_thirdZone_SECTION9();
      #endif
    #endif

    #if ZONEFOUR == 1 
      #if FOURTHZONE_SECTIONS >= 1
      fire_fourthZone_SECTION1();
      #endif
      #if FOURTHZONE_SECTIONS >= 2
      fire_fourthZone_SECTION2();
      #endif
      #if FOURTHZONE_SECTIONS >= 3
      fire_fourthZone_SECTION3();
      #endif
      #if FOURTHZONE_SECTIONS >= 4
      fire_fourthZone_SECTION4();
      #endif
      #if FOURTHZONE_SECTIONS >= 5
      fire_fourthZone_SECTION5();
      #endif
      #if FOURTHZONE_SECTIONS >= 6
      fire_fourthZone_SECTION6();
      #endif
      #if FOURTHZONE_SECTIONS >= 7
      fire_fourthZone_SECTION7();
      #endif
      #if FOURTHZONE_SECTIONS >= 8
      fire_fourthZone_SECTION8();
      #endif
      #if FOURTHZONE_SECTIONS >= 9
      fire_fourthZone_SECTION9();
      #endif
    #endif

    #if ZONEFIVE == 1 
      #if FIFTHZONE_SECTIONS >= 1
      fire_fifthZone_SECTION1();
      #endif
      #if FIFTHZONE_SECTIONS >= 2
      fire_fifthZone_SECTION2();
      #endif
      #if FIFTHZONE_SECTIONS >= 3
      fire_fifthZone_SECTION3();
      #endif
      #if FIFTHZONE_SECTIONS >= 4
      fire_fifthZone_SECTION4();
      #endif
      #if FIFTHZONE_SECTIONS >= 5
      fire_fifthZone_SECTION5();
      #endif
      #if FIFTHZONE_SECTIONS >= 6
      fire_fifthZone_SECTION6();
      #endif
      #if FIFTHZONE_SECTIONS >= 7
      fire_fifthZone_SECTION7();
      #endif
      #if FIFTHZONE_SECTIONS >= 8
      fire_fifthZone_SECTION8();
      #endif
      #if FIFTHZONE_SECTIONS >= 9
      fire_fifthZone_SECTION9();
      #endif
    #endif

    #if ZONESIX == 1 
      #if SIXTHZONE_SECTIONS >= 1
      fire_sixthZone_SECTION1();
      #endif
      #if SIXTHZONE_SECTIONS >= 2
      fire_sixthZone_SECTION2();
      #endif
      #if SIXTHZONE_SECTIONS >= 3
      fire_sixthZone_SECTION3();
      #endif
      #if SIXTHZONE_SECTIONS >= 4
      fire_sixthZone_SECTION4();
      #endif
      #if SIXTHZONE_SECTIONS >= 5
      fire_sixthZone_SECTION5();
      #endif
      #if SIXTHZONE_SECTIONS >= 6
      fire_sixthZone_SECTION6();
      #endif
      #if SIXTHZONE_SECTIONS >= 7
      fire_sixthZone_SECTION7();
      #endif
      #if SIXTHZONE_SECTIONS >= 8
      fire_sixthZone_SECTION8();
      #endif
      #if SIXTHZONE_SECTIONS >= 9
      fire_sixthZone_SECTION9();
      #endif
    #endif
   }
  }
  if(showLights == false)
  {
    #if ZONEONE == 1 
    fill_solid(firstZone, FIRSTZONE_LEDS, CRGB::Black); 
    #endif

    #if ZONETWO == 1
    fill_solid(secondZone, SECONDZONE_LEDS, CRGB::Black); 
    #endif

    #if ZONETHREE == 1
    fill_solid(thirdZone, THIRDZONE_LEDS, CRGB::Black);
    #endif

    #if ZONEFOUR == 1
    fill_solid(fourthZone, FOURTHZONE_LEDS, CRGB::Black);
    #endif

    #if ZONEFIVE == 1
    fill_solid(fifthZone, FIFTHZONE_LEDS, CRGB::Black); 
    #endif
    
    #if ZONESIX == 1
    fill_solid(sixthZone, SIXTHZONE_LEDS, CRGB::Black);
    #endif
  }
  addGlitter();
  addLightning(); 
}

/*********************** PATTERN MODIFIERS ***************************/
/*********************** PATTERN MODIFIERS ***************************/
/*********************** PATTERN MODIFIERS ***************************/
/*********************** PATTERN MODIFIERS ***************************/
/*********************** PATTERN MODIFIERS ***************************/

void addLightning()
{
  if(showLightning == true)
  {
    #if ZONEONE == 1 
    fadeToBlackBy(firstZone, FIRSTZONE_LEDS, 1); 
    #endif

    #if ZONETWO == 1
    fadeToBlackBy(secondZone, SECONDZONE_LEDS, 1); 
    #endif

    #if ZONETHREE == 1
    fadeToBlackBy(thirdZone, THIRDZONE_LEDS, 1);
    #endif

    #if ZONEFOUR == 1
    fadeToBlackBy(fourthZone, FOURTHZONE_LEDS, 1);
    #endif

    #if ZONEFIVE == 1
    fadeToBlackBy(fifthZone, FIFTHZONE_LEDS, 1); 
    #endif
    
    #if ZONESIX == 1
    fadeToBlackBy(sixthZone, SIXTHZONE_LEDS, 1);
    #endif
    
    unsigned int chance = random16();
    if( chance > lightningChance) 
    {
      #if ZONEONE == 1 
      fill_solid(firstZone, FIRSTZONE_LEDS, CRGB::White); 
      #endif
  
      #if ZONETWO == 1
      fill_solid(secondZone, SECONDZONE_LEDS, CRGB::White); 
      #endif
  
      #if ZONETHREE == 1
      fill_solid(thirdZone, THIRDZONE_LEDS, CRGB::White);
      #endif
  
      #if ZONEFOUR == 1
      fill_solid(fourthZone, FOURTHZONE_LEDS, CRGB::White);
      #endif
  
      #if ZONEFIVE == 1
      fill_solid(fifthZone, FIFTHZONE_LEDS, CRGB::White); 
      #endif
      
      #if ZONESIX == 1
      fill_solid(sixthZone, SIXTHZONE_LEDS, CRGB::White);
      #endif

      lightning = 20;
      if(audioEffects == true)
      {
        int thunder = random8();
        if( thunder > 128)
        {
          client.publish("Audio","2");
        }
        if( thunder < 127)
        {
          client.publish("Audio","1");
        }
      }
    }
    if(lightning != 1)
    {
      if(lightning > 15)
      {
        #if ZONEONE == 1  
        fadeToBlackBy(firstZone, FIRSTZONE_LEDS, 150); 
        #endif
    
        #if ZONETWO == 1
        fadeToBlackBy(secondZone, SECONDZONE_LEDS, 150); 
        #endif
    
        #if ZONETHREE == 1
        fadeToBlackBy(thirdZone, THIRDZONE_LEDS, 150);
        #endif
    
        #if ZONEFOUR == 1
        fadeToBlackBy(fourthZone, FOURTHZONE_LEDS, 150);
        #endif
    
        #if ZONEFIVE == 1
        fadeToBlackBy(fifthZone, FIFTHZONE_LEDS, 150); 
        #endif
        
        #if ZONESIX == 1
        fadeToBlackBy(sixthZone, SIXTHZONE_LEDS, 150);
        #endif

        lightning--;
      }
      if(lightning == 15)
      {

        #if ZONEONE == 1 
        fill_solid(firstZone, FIRSTZONE_LEDS, CRGB::White); 
        #endif
    
        #if ZONETWO == 1
        fill_solid(secondZone, SECONDZONE_LEDS, CRGB::White); 
        #endif
    
        #if ZONETHREE == 1
        fill_solid(thirdZone, THIRDZONE_LEDS, CRGB::White);
        #endif
    
        #if ZONEFOUR == 1
        fill_solid(fourthZone, FOURTHZONE_LEDS, CRGB::White);
        #endif
    
        #if ZONEFIVE == 1
        fill_solid(fifthZone, FIFTHZONE_LEDS, CRGB::White); 
        #endif
        
        #if ZONESIX == 1
        fill_solid(sixthZone, SIXTHZONE_LEDS, CRGB::White);
        #endif
        lightning--; 
      }
      if(lightning > 5 && lightning < 15)
      {
        #if ZONEONE == 1
        fadeToBlackBy(firstZone, FIRSTZONE_LEDS, 150); 
        #endif
    
        #if ZONETWO == 1
        fadeToBlackBy(secondZone, SECONDZONE_LEDS, 150); 
        #endif
    
        #if ZONETHREE == 1
        fadeToBlackBy(thirdZone, THIRDZONE_LEDS, 150);
        #endif
    
        #if ZONEFOUR == 1
        fadeToBlackBy(fourthZone, FOURTHZONE_LEDS, 150);
        #endif
    
        #if ZONEFIVE == 1
        fadeToBlackBy(fifthZone, FIFTHZONE_LEDS, 150); 
        #endif
        
        #if ZONESIX == 1
        fadeToBlackBy(sixthZone, SIXTHZONE_LEDS, 150);
        #endif
        lightning--;
      }
      if(lightning == 5)
      {
        #if ZONEONE == 1 
        fill_solid(firstZone, FIRSTZONE_LEDS, CRGB::White); 
        #endif
    
        #if ZONETWO == 1
        fill_solid(secondZone, SECONDZONE_LEDS, CRGB::White); 
        #endif
    
        #if ZONETHREE == 1
        fill_solid(thirdZone, THIRDZONE_LEDS, CRGB::White);
        #endif
    
        #if ZONEFOUR == 1
        fill_solid(fourthZone, FOURTHZONE_LEDS, CRGB::White);
        #endif
    
        #if ZONEFIVE == 1
        fill_solid(fifthZone, FIFTHZONE_LEDS, CRGB::White); 
        #endif
        
        #if ZONESIX == 1
        fill_solid(sixthZone, SIXTHZONE_LEDS, CRGB::White);
        #endif
        lightning--; 
      }
      if(lightning > 0 && lightning < 5)
      {
        #if ZONEONE == 1
        fadeToBlackBy(firstZone, FIRSTZONE_LEDS, 150); 
        #endif
    
        #if ZONETWO == 1
        fadeToBlackBy(secondZone, SECONDZONE_LEDS, 150); 
        #endif
    
        #if ZONETHREE == 1
        fadeToBlackBy(thirdZone, THIRDZONE_LEDS, 150);
        #endif
    
        #if ZONEFOUR == 1
        fadeToBlackBy(fourthZone, FOURTHZONE_LEDS, 150);
        #endif
    
        #if ZONEFIVE == 1
        fadeToBlackBy(fifthZone, FIFTHZONE_LEDS, 150); 
        #endif
        
        #if ZONESIX == 1
        fadeToBlackBy(sixthZone, SIXTHZONE_LEDS, 150);
        #endif
        lightning--;
      }
    }
  }
}

void addGlitter() 
{
  if(showGlitter == true)
  {     
    if( random8() < glitterFrequency) 
    {
      #if ZONEONE == 1 
      {
        firstZone[ random16(FIRSTZONE_LEDS) ] = CRGB(redG, greenG, blueG);  
      }
      #endif
  
      #if ZONETWO == 1
      {
        secondZone[ random16(SECONDZONE_LEDS) ] = CRGB(redG, greenG, blueG);  
      }
      #endif
  
      #if ZONETHREE == 1
      {
        thirdZone[ random16(THIRDZONE_LEDS) ] = CRGB(redG, greenG, blueG);  
      }
      #endif
  
      #if ZONEFOUR == 1
      {
        fourthZone[ random16(FOURTHZONE_LEDS) ] = CRGB(redG, greenG, blueG);  
      }
      #endif
  
      #if ZONEFIVE == 1
      {
        fifthZone[ random16(FIFTHZONE_LEDS) ] = CRGB(redG, greenG, blueG);  
      }
      #endif
      
      #if ZONESIX == 1
      {
        sixthZone[ random16(SIXTHZONE_LEDS) ] = CRGB(redG, greenG, blueG);  
      }
      #endif  
    }
  }
}

void setupZones()
{
    #if ZONEONE == 1
    FastLED.addLeds<WS2812B, Pin_firstZone, FIRSTZONE_COLOR_ORDER>(firstZone, FIRSTZONE_LEDS);
    #endif

    #if ZONETWO == 1
    FastLED.addLeds<WS2812B, Pin_secondZone, SECONDZONE_COLOR_ORDER>(secondZone, SECONDZONE_LEDS);
    #endif

    #if ZONETHREE == 1
    FastLED.addLeds<WS2812B, Pin_thirdZone, THIRDZONE_COLOR_ORDER>(thirdZone, THIRDZONE_LEDS);
    #endif

    #if ZONEFOUR == 1
    FastLED.addLeds<WS2812B, Pin_fourthZone, FOURTHZONE_COLOR_ORDER>(fourthZone, FOURTHZONE_LEDS);
    #endif

    #if ZONEFIVE == 1
    FastLED.addLeds<WS2812B, Pin_fifthZone, FIFTHZONE_COLOR_ORDER>(fifthZone, FIFTHZONE_LEDS);
    #endif
    
    #if ZONESIX == 1
    FastLED.addLeds<WS2812B, Pin_sixthZone, SIXTHZONE_COLOR_ORDER>(sixthZone, SIXTHZONE_LEDS);
    #endif
}


void locator_Move()
{
  if(effect == "LED_Locator")
  {
    if(locatorLED <= maxLEDs)
    {
      String temp_str = String(locatorLED);
      temp_str.toCharArray(MQTT_locatorLED, temp_str.length() + 1);
      client.publish(USER_MQTT_CLIENT_NAME"/locator", MQTT_locatorLED);
      locatorLED++;    
    }
    else
    {
      locatorLED == 0;
    }
    timer.setTimeout(locatorDelay, locator_Move);
  }
}



/*****************  SETUP FUNCTION  ****************************************/
/*****************  SETUP FUNCTION  ****************************************/
/*****************  SETUP FUNCTION  ****************************************/
/*****************  SETUP FUNCTION  ****************************************/
/*****************  SETUP FUNCTION  ****************************************/


void setup() {
  Serial.begin(115200);
  calculateMax();
  setupZones();
  FastLED.setDither( 0 );
  WiFi.setSleepMode(WIFI_NONE_SLEEP);
  WiFi.mode(WIFI_STA);
  setup_wifi();
  client.setServer(mqtt_server, mqtt_port);
  client.setCallback(callback);
  ArduinoOTA.setHostname(USER_MQTT_CLIENT_NAME);
  ArduinoOTA.begin(); 

  gPal = HeatColors_p;
  
  timer.setTimeout(10000, chase);
  timer.setTimeout(120000, checkIn);

}


/*****************  MAIN LOOP  ****************************************/
/*****************  MAIN LOOP  ****************************************/
/*****************  MAIN LOOP  ****************************************/
/*****************  MAIN LOOP  ****************************************/
/*****************  MAIN LOOP  ****************************************/


void loop() 
{
  if (!client.connected()) 
  {
    reconnect();
  }
  client.loop();
  if(showLights == false)
  {
    ArduinoOTA.handle();  
  }
  timer.run();
  EVERY_N_MILLISECONDS( 20 ) { gHue++; }
  choosePattern();

  #if ZONEONE == 1
  FastLED[0].showLeds(brightness);
  #endif

  #if ZONETWO == 1
  FastLED[1].showLeds(brightness);
  #endif

  #if ZONETHREE == 1
  FastLED[2].showLeds(brightness);
  #endif

  #if ZONEFOUR == 1
  FastLED[3].showLeds(brightness);
  #endif

  #if ZONEFIVE == 1
  FastLED[4].showLeds(brightness);
  #endif
  
  #if ZONESIX == 1
  FastLED[5].showLeds(brightness);
  #endif
  
}



/*****************  firstZone Animations  ****************************************/
/*****************  firstZone Animations  ****************************************/
/*****************  firstZone Animations  ****************************************/
/*****************  firstZone Animations  ****************************************/
/*****************  firstZone Animations  ****************************************/

#if ZONEONE == 1


void Ripple_firstZone()
{
  for (int i = 0; i < FIRSTZONE_LEDS; i++)
  {
    firstZone[i] = CRGB((red2/75), (green2/75), (blue2/75));
  }   
  switch (step_firstZone) 
  {
    case -1:                                                          
      center_firstZone = random16(FIRSTZONE_LEDS);
      step_firstZone = 0;
      break;
    case 0:
      firstZone[center_firstZone] = CRGB(red1, green1, blue1);                          
      step_firstZone ++;
      break;
    case 12:                                                   
      step_firstZone = -1;
      break;
    default:                                                             // Middle of the ripples.
      firstZone[(center_firstZone + step_firstZone + FIRSTZONE_LEDS) % FIRSTZONE_LEDS] += CRGB((red1/(step_firstZone * 5)), (green1/(step_firstZone * 5)), (blue1/(step_firstZone * 5)));
      firstZone[(center_firstZone - step_firstZone + FIRSTZONE_LEDS) % FIRSTZONE_LEDS] += CRGB((red1/(step_firstZone * 5)), (green1/(step_firstZone * 5)), (blue1/(step_firstZone * 5)));
      step_firstZone ++;                                                         
      break;
  }
}

void RGB_firstZone()
{
  if(startPosition < 6)
  {
    fadeToBlackBy( firstZone, FIRSTZONE_LEDS, 80);
    for(int pixel = startPosition+1; pixel < FIRSTZONE_LEDS; pixel+=6)  
    {
      if(pixel <= FIRSTZONE_LEDS)
      {
        firstZone[pixel] = CRGB(red1,green1,blue1);
      }
    }
    for(int pixel = startPosition+3; pixel < FIRSTZONE_LEDS; pixel+=6)
    {
      if(pixel <= FIRSTZONE_LEDS)
      {
        firstZone[pixel] = CRGB(red2,green2,blue2);
      }
    }
    for(int pixel = startPosition+5; pixel < FIRSTZONE_LEDS; pixel+=6)
    {
      if(pixel <= FIRSTZONE_LEDS)
      {
        firstZone[pixel] = CRGB(red3,green3,blue3);
      } 
    }
  }
  if(startPosition == 1)
  {
    firstZone[0]=CRGB(red3,green3,blue3);
  }
  if(startPosition == 2)
  {
    firstZone[1]=CRGB(red3,green3,blue3);
  }
  if(startPosition == 3)
  {
    firstZone[2]=CRGB(red3,green3,blue3);
    firstZone[0]=CRGB(red2,green2,blue2);
  }
  if(startPosition == 4)
  {
    firstZone[3]=CRGB(red3,green3,blue3);
    firstZone[1]=CRGB(red2,green2,blue2);
  }
  if(startPosition == 5)
  {
    firstZone[4]=CRGB(red3,green3,blue3);
    firstZone[2]=CRGB(red2,green2,blue2);
    firstZone[0]=CRGB(red1,green1,blue1);
  }
}

void ColorGlitter_firstZone( fract8 chanceOfGlitter) 
{
  fadeToBlackBy( firstZone, FIRSTZONE_LEDS, 2);
  if(startPosition == 0)
  {
    if( random8() < chanceOfGlitter) 
    {
    firstZone[ random16(FIRSTZONE_LEDS) ] += CRGB::Red;
    }
  }
  if(startPosition == 1)
  {
    if( random8() < chanceOfGlitter) 
    {
    firstZone[ random16(FIRSTZONE_LEDS) ] += CRGB::Orange;
    }
  }
  if(startPosition == 2)
  {
    if( random8() < chanceOfGlitter) 
    {
    firstZone[ random16(FIRSTZONE_LEDS) ] += CRGB::Yellow;
    }  
  }
  if(startPosition == 3)
  {
    if( random8() < chanceOfGlitter) 
    {
    firstZone[ random16(FIRSTZONE_LEDS) ] += CRGB::Green;
    }
  }
  if(startPosition == 4)
  {
    if( random8() < chanceOfGlitter) 
    {
    firstZone[ random16(FIRSTZONE_LEDS) ] += CRGB::Blue;
    }
  }
  if(startPosition == 5)
  {
    if( random8() < chanceOfGlitter) 
    {
    firstZone[ random16(FIRSTZONE_LEDS) ] += CRGB::Violet;
    }
  } 
}

void SingleRace_firstZone()
{
  fadeToBlackBy( firstZone, FIRSTZONE_LEDS, 1);
  int pos = beatsin16( raceSpeed, 0, 474);
  if(pos > previousLED_firstZone)
  {
    firstZone[pos] = CRGB(red1,green1,blue1);
    previousLED_firstZone = pos;
  }
  if(pos < previousLED_firstZone)
  {
    firstZone[pos] = CRGB(red2,green2,blue2);
    previousLED_firstZone = pos;
  }                 
}

void Crash_firstZone()
{
  fadeToBlackBy( firstZone, FIRSTZONE_LEDS, 15);
  #ifdef ZONEONE_SECTION1_START
  int pos_SECTION1 = beatsin16( raceSpeed, 0, (ZONEONE_SECTION1_END - ZONEONE_SECTION1_START) );
  firstZone[ZONEONE_SECTION1_START + pos_SECTION1] = CRGB(red1,green1,blue1);
  firstZone[ZONEONE_SECTION1_END - pos_SECTION1] = CRGB(red2,green2,blue2);
  #endif

  #ifdef ZONEONE_SECTION2_START
  int pos_SECTION2 = beatsin16( raceSpeed, 0, (ZONEONE_SECTION2_END - ZONEONE_SECTION2_START) );
  firstZone[ZONEONE_SECTION2_START + pos_SECTION2] = CRGB(red2,green2,blue2);
  firstZone[ZONEONE_SECTION2_END - pos_SECTION2] = CRGB(red1,green1,blue1);
  #endif
  
  #ifdef ZONEONE_SECTION3_START
  int pos_SECTION3 = beatsin16( raceSpeed, 0, (ZONEONE_SECTION3_END - ZONEONE_SECTION3_START) );
  firstZone[ZONEONE_SECTION3_START + pos_SECTION3] = CRGB(red1,green1,blue1);
  firstZone[ZONEONE_SECTION3_END - pos_SECTION3] = CRGB(red2,green2,blue2);
  #endif
  
  #ifdef ZONEONE_SECTION4_START
  int pos_SECTION4 = beatsin16( raceSpeed, 0, (ZONEONE_SECTION4_END - ZONEONE_SECTION4_START) );
  firstZone[ZONEONE_SECTION4_START + pos_SECTION4] = CRGB(red2,green2,blue2);
  firstZone[ZONEONE_SECTION4_END - pos_SECTION4] = CRGB(red1,green1,blue1);
  #endif
  
  #ifdef ZONEONE_SECTION5_START
  int pos_SECTION5 = beatsin16( raceSpeed, 0, (ZONEONE_SECTION5_END - ZONEONE_SECTION5_START) );
  firstZone[ZONEONE_SECTION5_START + pos_SECTION5] = CRGB(red1,green1,blue1);
  firstZone[ZONEONE_SECTION5_END - pos_SECTION5] = CRGB(red2,green2,blue2);
  #endif
  
  #ifdef ZONEONE_SECTION6_START
  int pos_SECTION6 = beatsin16( raceSpeed, 0, (ZONEONE_SECTION6_END - ZONEONE_SECTION6_START) );
  firstZone[ZONEONE_SECTION6_START + pos_SECTION6] = CRGB(red2,green2,blue2);
  firstZone[ZONEONE_SECTION6_END - pos_SECTION6] = CRGB(red1,green1,blue1);
  #endif
  
  #ifdef ZONEONE_SECTION7_START
  int pos_SECTION7 = beatsin16( raceSpeed, 0, (ZONEONE_SECTION7_END - ZONEONE_SECTION7_START) );
  firstZone[ZONEONE_SECTION7_START + pos_SECTION7] = CRGB(red1,green1,blue1);
  firstZone[ZONEONE_SECTION7_END - pos_SECTION7] = CRGB(red2,green2,blue2);
  #endif
  
  #ifdef ZONEONE_SECTION8_START
  int pos_SECTION8 = beatsin16( raceSpeed, 0, (ZONEONE_SECTION8_END - ZONEONE_SECTION8_START) );
  firstZone[ZONEONE_SECTION8_START + pos_SECTION8] = CRGB(red2,green2,blue2);
  firstZone[ZONEONE_SECTION8_END - pos_SECTION8] = CRGB(red1,green1,blue1);
  #endif
  
  #ifdef ZONEONE_SECTION9_START
  int pos_SECTION9 = beatsin16( raceSpeed, 0, (ZONEONE_SECTION9_END - ZONEONE_SECTION9_START) );
  firstZone[ZONEONE_SECTION9_START + pos_SECTION9] = CRGB(red1,green1,blue1);
  firstZone[ZONEONE_SECTION9_END - pos_SECTION9] = CRGB(red2,green2,blue2);
  #endif
  
}

void Rainbow_firstZone()
{
  fill_rainbow( firstZone, FIRSTZONE_LEDS, gHue, numberOfRainbows);
}

void Blocked_firstZone()
{
  fadeToBlackBy( firstZone, FIRSTZONE_LEDS, 2);
  for( int mark = 0; mark < FIRSTZONE_LEDS; mark+=30)
  {
    for( int i = 0; i < 9; i++) 
    {
      if(startPosition == 0 || startPosition == 1)
      {
        if(i+mark <= FIRSTZONE_LEDS)
        {
          firstZone[i+mark] = CRGB(red1,green1,blue1);
        }
        if(i+10+mark <= FIRSTZONE_LEDS)
        {
          firstZone[i+10+mark] = CRGB(red2,green2,blue2);
        }
        if(i+20+mark <= FIRSTZONE_LEDS)
        {
          firstZone[i+20+mark] = CRGB(red3,green3,blue3);
        }
      }
      if(startPosition == 2 || startPosition == 3)
      {
        if(i+mark <= FIRSTZONE_LEDS)
        {
          firstZone[i+mark] = CRGB(red2,green2,blue2);
        }
        if(i+10+mark <= FIRSTZONE_LEDS)
        {
          firstZone[i+10+mark] = CRGB(red3,green3,blue3);
        }
        if(i+20+mark <= FIRSTZONE_LEDS)
        {
          firstZone[i+20+mark] = CRGB(red1,green1,blue1);
        }
      }
      if(startPosition == 4 || startPosition == 5)
      {
        if(i+mark <= FIRSTZONE_LEDS)
        {
          firstZone[i+mark] = CRGB(red3,green3,blue3);
        }
        if(i+10+mark <= FIRSTZONE_LEDS)
        {
          firstZone[i+10+mark] = CRGB(red1,green1,blue1);
        }
        if(i+20+mark <= FIRSTZONE_LEDS)
        {
          firstZone[i+20+mark] = CRGB(red2,green2,blue2);
        }
      }
    }
  }
}

void BPM_firstZone()
{
  if((red1*2) > (green1 + blue1))
  {
    CRGBPalette16 palette_firstZone = LavaColors_p; 
    uint8_t beat = beatsin16( BeatsPerMinute, 64, 255);
    for( int i = 0; i < FIRSTZONE_LEDS; i++) 
    {
      firstZone[i] = ColorFromPalette(palette_firstZone, gHue+(i*2), beat-gHue+(i*10));
    } 
  }
  if((green1*2) > (red1 + blue1))
  {
    CRGBPalette16 palette_firstZone = ForestColors_p; 
    uint8_t beat = beatsin16( BeatsPerMinute, 64, 255);
    for( int i = 0; i < FIRSTZONE_LEDS; i++) 
    {
      firstZone[i] = ColorFromPalette(palette_firstZone, gHue+(i*2), beat-gHue+(i*10));
    } 
  }
  if((blue1*2) > (green1 + red1))
  {
    CRGBPalette16 palette_firstZone = CloudColors_p; 
    uint8_t beat = beatsin16( BeatsPerMinute, 64, 255);
    for( int i = 0; i < FIRSTZONE_LEDS; i++) 
    {
      firstZone[i] = ColorFromPalette(palette_firstZone, gHue+(i*2), beat-gHue+(i*10));
    } 
  }
  if((blue1*2) == (green1 + red1))
  {
    CRGBPalette16 palette_firstZone = PartyColors_p; 
    uint8_t beat = beatsin16( BeatsPerMinute, 64, 255);
    for( int i = 0; i < FIRSTZONE_LEDS; i++) 
    {
      firstZone[i] = ColorFromPalette(palette_firstZone, gHue+(i*2), beat-gHue+(i*10));
    } 
  }
}

void Twinkle_firstZone()
{
  fadeToBlackBy( firstZone, FIRSTZONE_LEDS, 80);
  for( int i = 0; i < FIRSTZONE_LEDS-5; i+=5)
  {
    if(i <= FIRSTZONE_LEDS)
    {
      if (random8() > twinkleChance)
      {
        firstZone[i] = CRGB( red1, green1, blue1);
      }
      else
      {
        firstZone[i] = CRGB( 150, 100, 40);
      }  
    }
  }                     
}

void Eyes_firstZone()
{
  unsigned int chance = random8();
  if( chance > eyeChance) 
  {
    unsigned int eye = random16(FIRSTZONE_LEDS);  
    firstZone[eye] = CRGB(red1,green1,blue1);
    firstZone[eye-4] = CRGB(red1,green1,blue1);
  }
  if( chance > 39) 
  {
    fadeToBlackBy( firstZone, FIRSTZONE_LEDS, 10);
  }
}

void Solid_firstZone()
{
  fill_solid(firstZone, FIRSTZONE_LEDS, CRGB(red1, green1, blue1));
}

void Locator_firstZone()
{
  if(locatorLED <= FIRSTZONE_LEDS)
  {
    fill_solid(firstZone, FIRSTZONE_LEDS, CRGB::Black); 
    firstZone[locatorLED]=CRGB(red1, green1, blue1);
  }
}

#ifdef ZONEONE_SECTION1_START
void fire_firstZone_SECTION1()
{
  static byte heat[ZONEONE_SECTION1_END - ZONEONE_SECTION1_START];
  for( int i = 0; i < ZONEONE_SECTION1_END - ZONEONE_SECTION1_START; i++) 
  {
    heat[i] = qsub8( heat[i],  random8(0, ((COOLING * 10) / ZONEONE_SECTION1_END - ZONEONE_SECTION1_START) + 2));
  }

  for( int k= ZONEONE_SECTION1_END - ZONEONE_SECTION1_START - 1; k >= 2; k--) 
  {
    heat[k] = (heat[k - 1] + heat[k - 2] + heat[k - 2] ) / 3;
  }
  if( random8() < SPARKING ) 
  {
    int y = random8(7);
    heat[y] = qadd8( heat[y], random8(160,255) );
  }
  for( int j = 0; j < ZONEONE_SECTION1_END - ZONEONE_SECTION1_START; j++) 
  {
    byte colorindex = scale8( heat[j], 240);
    CRGB color = ColorFromPalette( gPal, colorindex);
    int pixelnumber;
    if( gReverseDirection ) {
      pixelnumber = (ZONEONE_SECTION1_END - ZONEONE_SECTION1_START -1) - j;
    } else {
      pixelnumber = j;
    }
    int thisFlame = ((pixelnumber * firesize)/100);
    if(thisFlame <=  ZONEONE_SECTION1_END - ZONEONE_SECTION1_START )
    
    #if ZONEONE_SECTION1_START_FIRE == 1
    {
      firstZone[ZONEONE_SECTION1_START + thisFlame] = color;
    }
    #endif
    
    #if ZONEONE_SECTION1_END_FIRE == 1
    {
      firstZone[ZONEONE_SECTION1_END - thisFlame] = color;
    }
    #endif
  }
}
#endif

#ifdef ZONEONE_SECTION2_START
void fire_firstZone_SECTION2()
{
  static byte heat[ZONEONE_SECTION2_END - ZONEONE_SECTION2_START];
  for( int i = 0; i < ZONEONE_SECTION2_END - ZONEONE_SECTION2_START; i++) 
  {
    heat[i] = qsub8( heat[i],  random8(0, ((COOLING * 10) / ZONEONE_SECTION2_END - ZONEONE_SECTION2_START) + 2));
  }

  for( int k= ZONEONE_SECTION2_END - ZONEONE_SECTION2_START - 1; k >= 2; k--) 
  {
    heat[k] = (heat[k - 1] + heat[k - 2] + heat[k - 2] ) / 3;
  }
  if( random8() < SPARKING ) 
  {
    int y = random8(7);
    heat[y] = qadd8( heat[y], random8(160,255) );
  }
  for( int j = 0; j < ZONEONE_SECTION2_END - ZONEONE_SECTION2_START; j++) 
  {
    byte colorindex = scale8( heat[j], 240);
    CRGB color = ColorFromPalette( gPal, colorindex);
    int pixelnumber;
    if( gReverseDirection ) {
      pixelnumber = (ZONEONE_SECTION2_END - ZONEONE_SECTION2_START -1) - j;
    } else {
      pixelnumber = j;
    }
    int thisFlame = ((pixelnumber * firesize)/100);
    if(thisFlame <=  ZONEONE_SECTION2_START && thisFlame <= ZONEONE_SECTION2_END)
    
    #if ZONEONE_SECTION2_START_FIRE == 1
    {
      firstZone[ZONEONE_SECTION2_START + thisFlame] = color;
    }
    #endif
    
    #if ZONEONE_SECTION2_END_FIRE == 1
    {
      firstZone[ZONEONE_SECTION2_END - thisFlame] = color;
    }
    #endif
  }
}
#endif

#ifdef ZONEONE_SECTION3_START
void fire_firstZone_SECTION3()
{
  static byte heat[ZONEONE_SECTION3_END - ZONEONE_SECTION3_START];
  for( int i = 0; i < ZONEONE_SECTION3_END - ZONEONE_SECTION3_START; i++) 
  {
    heat[i] = qsub8( heat[i],  random8(0, ((COOLING * 10) / ZONEONE_SECTION3_END - ZONEONE_SECTION3_START) + 2));
  }

  for( int k= ZONEONE_SECTION3_END - ZONEONE_SECTION3_START - 1; k >= 2; k--) 
  {
    heat[k] = (heat[k - 1] + heat[k - 2] + heat[k - 2] ) / 3;
  }
  if( random8() < SPARKING ) 
  {
    int y = random8(7);
    heat[y] = qadd8( heat[y], random8(160,255) );
  }
  for( int j = 0; j < ZONEONE_SECTION3_END - ZONEONE_SECTION3_START; j++) 
  {
    byte colorindex = scale8( heat[j], 240);
    CRGB color = ColorFromPalette( gPal, colorindex);
    int pixelnumber;
    if( gReverseDirection ) {
      pixelnumber = (ZONEONE_SECTION3_END - ZONEONE_SECTION3_START -1) - j;
    } else {
      pixelnumber = j;
    }
    int thisFlame = ((pixelnumber * firesize)/100);
    if(thisFlame <=  ZONEONE_SECTION3_START && thisFlame <= ZONEONE_SECTION3_END)
    
    #if ZONEONE_SECTION3_START_FIRE == 1
    {
      firstZone[ZONEONE_SECTION3_START + thisFlame] = color;
    }
    #endif
    
    #if ZONEONE_SECTION3_END_FIRE == 1
    {
      firstZone[ZONEONE_SECTION3_END - thisFlame] = color;
    }
    #endif
  }
}
#endif

#ifdef ZONEONE_SECTION4_START
void fire_firstZone_SECTION4()
{
  static byte heat[ZONEONE_SECTION4_END - ZONEONE_SECTION4_START];
  for( int i = 0; i < ZONEONE_SECTION4_END - ZONEONE_SECTION4_START; i++) 
  {
    heat[i] = qsub8( heat[i],  random8(0, ((COOLING * 10) / ZONEONE_SECTION4_END - ZONEONE_SECTION4_START) + 2));
  }

  for( int k= ZONEONE_SECTION4_END - ZONEONE_SECTION4_START - 1; k >= 2; k--) 
  {
    heat[k] = (heat[k - 1] + heat[k - 2] + heat[k - 2] ) / 3;
  }
  if( random8() < SPARKING ) 
  {
    int y = random8(7);
    heat[y] = qadd8( heat[y], random8(160,255) );
  }
  for( int j = 0; j < ZONEONE_SECTION4_END - ZONEONE_SECTION4_START; j++) 
  {
    byte colorindex = scale8( heat[j], 240);
    CRGB color = ColorFromPalette( gPal, colorindex);
    int pixelnumber;
    if( gReverseDirection ) {
      pixelnumber = (ZONEONE_SECTION4_END - ZONEONE_SECTION4_START -1) - j;
    } else {
      pixelnumber = j;
    }
    int thisFlame = ((pixelnumber * firesize)/100);
    if(thisFlame <=  ZONEONE_SECTION4_START && thisFlame <= ZONEONE_SECTION4_END)
    
    #if ZONEONE_SECTION4_START_FIRE == 1
    {
      firstZone[ZONEONE_SECTION4_START + thisFlame] = color;
    }
    #endif
    
    #if ZONEONE_SECTION4_END_FIRE == 1
    {
      firstZone[ZONEONE_SECTION4_END - thisFlame] = color;
    }
    #endif
  }
}
#endif

#ifdef ZONEONE_SECTION5_START
void fire_firstZone_SECTION5()
{
  static byte heat[ZONEONE_SECTION5_END - ZONEONE_SECTION5_START];
  for( int i = 0; i < ZONEONE_SECTION5_END - ZONEONE_SECTION5_START; i++) 
  {
    heat[i] = qsub8( heat[i],  random8(0, ((COOLING * 10) / ZONEONE_SECTION5_END - ZONEONE_SECTION5_START) + 2));
  }

  for( int k= ZONEONE_SECTION5_END - ZONEONE_SECTION5_START - 1; k >= 2; k--) 
  {
    heat[k] = (heat[k - 1] + heat[k - 2] + heat[k - 2] ) / 3;
  }
  if( random8() < SPARKING ) 
  {
    int y = random8(7);
    heat[y] = qadd8( heat[y], random8(160,255) );
  }
  for( int j = 0; j < ZONEONE_SECTION5_END - ZONEONE_SECTION5_START; j++) 
  {
    byte colorindex = scale8( heat[j], 240);
    CRGB color = ColorFromPalette( gPal, colorindex);
    int pixelnumber;
    if( gReverseDirection ) {
      pixelnumber = (ZONEONE_SECTION5_END - ZONEONE_SECTION5_START -1) - j;
    } else {
      pixelnumber = j;
    }
    int thisFlame = ((pixelnumber * firesize)/100);
    if(thisFlame <=  ZONEONE_SECTION5_START && thisFlame <= ZONEONE_SECTION5_END)
    
    #if ZONEONE_SECTION5_START_FIRE == 1
    {
      firstZone[ZONEONE_SECTION5_START + thisFlame] = color;
    }
    #endif
    
    #if ZONEONE_SECTION5_END_FIRE == 1
    {
      firstZone[ZONEONE_SECTION5_END - thisFlame] = color;
    }
    #endif
  }
}
#endif

#ifdef ZONEONE_SECTION6_START
void fire_firstZone_SECTION6()
{
  static byte heat[ZONEONE_SECTION6_END - ZONEONE_SECTION6_START];
  for( int i = 0; i < ZONEONE_SECTION6_END - ZONEONE_SECTION6_START; i++) 
  {
    heat[i] = qsub8( heat[i],  random8(0, ((COOLING * 10) / ZONEONE_SECTION6_END - ZONEONE_SECTION6_START) + 2));
  }

  for( int k= ZONEONE_SECTION6_END - ZONEONE_SECTION6_START - 1; k >= 2; k--) 
  {
    heat[k] = (heat[k - 1] + heat[k - 2] + heat[k - 2] ) / 3;
  }
  if( random8() < SPARKING ) 
  {
    int y = random8(7);
    heat[y] = qadd8( heat[y], random8(160,255) );
  }
  for( int j = 0; j < ZONEONE_SECTION6_END - ZONEONE_SECTION6_START; j++) 
  {
    byte colorindex = scale8( heat[j], 240);
    CRGB color = ColorFromPalette( gPal, colorindex);
    int pixelnumber;
    if( gReverseDirection ) {
      pixelnumber = (ZONEONE_SECTION6_END - ZONEONE_SECTION6_START -1) - j;
    } else {
      pixelnumber = j;
    }
    int thisFlame = ((pixelnumber * firesize)/100);
    if(thisFlame <=  ZONEONE_SECTION6_START && thisFlame <= ZONEONE_SECTION6_END)
    
    #if ZONEONE_SECTION6_START_FIRE == 1
    {
      firstZone[ZONEONE_SECTION6_START + thisFlame] = color;
    }
    #endif
    
    #if ZONEONE_SECTION6_END_FIRE == 1
    {
      firstZone[ZONEONE_SECTION6_END - thisFlame] = color;
    }
    #endif
  }
}
#endif

#ifdef ZONEONE_SECTION7_START
void fire_firstZone_SECTION7()
{
  static byte heat[ZONEONE_SECTION7_END - ZONEONE_SECTION7_START];
  for( int i = 0; i < ZONEONE_SECTION7_END - ZONEONE_SECTION7_START; i++) 
  {
    heat[i] = qsub8( heat[i],  random8(0, ((COOLING * 10) / ZONEONE_SECTION7_END - ZONEONE_SECTION7_START) + 2));
  }

  for( int k= ZONEONE_SECTION7_END - ZONEONE_SECTION7_START - 1; k >= 2; k--) 
  {
    heat[k] = (heat[k - 1] + heat[k - 2] + heat[k - 2] ) / 3;
  }
  if( random8() < SPARKING ) 
  {
    int y = random8(7);
    heat[y] = qadd8( heat[y], random8(160,255) );
  }
  for( int j = 0; j < ZONEONE_SECTION7_END - ZONEONE_SECTION7_START; j++) 
  {
    byte colorindex = scale8( heat[j], 240);
    CRGB color = ColorFromPalette( gPal, colorindex);
    int pixelnumber;
    if( gReverseDirection ) {
      pixelnumber = (ZONEONE_SECTION7_END - ZONEONE_SECTION7_START -1) - j;
    } else {
      pixelnumber = j;
    }
    int thisFlame = ((pixelnumber * firesize)/100);
    if(thisFlame <=  ZONEONE_SECTION7_START && thisFlame <= ZONEONE_SECTION7_END)
    
    #if ZONEONE_SECTION7_START_FIRE == 1
    {
      firstZone[ZONEONE_SECTION7_START + thisFlame] = color;
    }
    #endif
    
    #if ZONEONE_SECTION7_END_FIRE == 1
    {
      firstZone[ZONEONE_SECTION7_END - thisFlame] = color;
    }
    #endif
  }
}
#endif

#ifdef ZONEONE_SECTION8_START
void fire_firstZone_SECTION8()
{
  static byte heat[ZONEONE_SECTION8_END - ZONEONE_SECTION8_START];
  for( int i = 0; i < ZONEONE_SECTION8_END - ZONEONE_SECTION8_START; i++) 
  {
    heat[i] = qsub8( heat[i],  random8(0, ((COOLING * 10) / ZONEONE_SECTION8_END - ZONEONE_SECTION8_START) + 2));
  }

  for( int k= ZONEONE_SECTION8_END - ZONEONE_SECTION8_START - 1; k >= 2; k--) 
  {
    heat[k] = (heat[k - 1] + heat[k - 2] + heat[k - 2] ) / 3;
  }
  if( random8() < SPARKING ) 
  {
    int y = random8(7);
    heat[y] = qadd8( heat[y], random8(160,255) );
  }
  for( int j = 0; j < ZONEONE_SECTION8_END - ZONEONE_SECTION8_START; j++) 
  {
    byte colorindex = scale8( heat[j], 240);
    CRGB color = ColorFromPalette( gPal, colorindex);
    int pixelnumber;
    if( gReverseDirection ) {
      pixelnumber = (ZONEONE_SECTION8_END - ZONEONE_SECTION8_START -1) - j;
    } else {
      pixelnumber = j;
    }
    int thisFlame = ((pixelnumber * firesize)/100);
    if(thisFlame <=  ZONEONE_SECTION8_START && thisFlame <= ZONEONE_SECTION8_END)
    
    #if ZONEONE_SECTION8_START_FIRE == 1
    {
      firstZone[ZONEONE_SECTION8_START + thisFlame] = color;
    }
    #endif
    
    #if ZONEONE_SECTION8_END_FIRE == 1
    {
      firstZone[ZONEONE_SECTION8_END - thisFlame] = color;
    }
    #endif
  }
}
#endif

#ifdef ZONEONE_SECTION9_START
void fire_firstZone_SECTION9()
{
  static byte heat[ZONEONE_SECTION9_END - ZONEONE_SECTION9_START];
  for( int i = 0; i < ZONEONE_SECTION9_END - ZONEONE_SECTION9_START; i++) 
  {
    heat[i] = qsub8( heat[i],  random8(0, ((COOLING * 10) / ZONEONE_SECTION9_END - ZONEONE_SECTION9_START) + 2));
  }

  for( int k= ZONEONE_SECTION9_END - ZONEONE_SECTION9_START - 1; k >= 2; k--) 
  {
    heat[k] = (heat[k - 1] + heat[k - 2] + heat[k - 2] ) / 3;
  }
  if( random8() < SPARKING ) 
  {
    int y = random8(7);
    heat[y] = qadd8( heat[y], random8(160,255) );
  }
  for( int j = 0; j < ZONEONE_SECTION9_END - ZONEONE_SECTION9_START; j++) 
  {
    byte colorindex = scale8( heat[j], 240);
    CRGB color = ColorFromPalette( gPal, colorindex);
    int pixelnumber;
    if( gReverseDirection ) {
      pixelnumber = (ZONEONE_SECTION9_END - ZONEONE_SECTION9_START -1) - j;
    } else {
      pixelnumber = j;
    }
    int thisFlame = ((pixelnumber * firesize)/100);
    if(thisFlame <=  ZONEONE_SECTION9_START && thisFlame <= ZONEONE_SECTION9_END)
    
    #if ZONEONE_SECTION9_START_FIRE == 1
    {
      firstZone[ZONEONE_SECTION9_START + thisFlame] = color;
    }
    #endif
    
    #if ZONEONE_SECTION9_END_FIRE == 1
    {
      firstZone[ZONEONE_SECTION9_END - thisFlame] = color;
    }
    #endif
  }
}
#endif

#endif

/*****************  secondZone Animations  ****************************************/
/*****************  secondZone Animations  ****************************************/
/*****************  secondZone Animations  ****************************************/
/*****************  secondZone Animations  ****************************************/
/*****************  secondZone Animations  ****************************************/

#if ZONETWO == 1  

void Ripple_secondZone()
{
  for (int i = 0; i < SECONDZONE_LEDS; i++)
  {
    secondZone[i] = CRGB((red2/75), (green2/75), (blue2/75));
  }   
  switch (step_secondZone) 
  {
    case -1:                                                          
      center_secondZone = random16(SECONDZONE_LEDS);
      step_secondZone = 0;
      break;
    case 0:
      secondZone[center_secondZone] = CRGB(red1, green1, blue1);                          
      step_secondZone ++;
      break;
    case 12:                                                   
      step_secondZone = -1;
      break;
    default:                                                             // Middle of the ripples.
      secondZone[(center_secondZone + step_secondZone + SECONDZONE_LEDS) % SECONDZONE_LEDS] += CRGB((red1/(step_secondZone * 5)), (green1/(step_secondZone * 5)), (blue1/(step_secondZone * 5)));
      secondZone[(center_secondZone - step_secondZone + SECONDZONE_LEDS) % SECONDZONE_LEDS] += CRGB((red1/(step_secondZone * 5)), (green1/(step_secondZone * 5)), (blue1/(step_secondZone * 5)));
      step_secondZone ++;                                                         
      break;
  }
}

void RGB_secondZone()
{
  if(startPosition < 6)
  {
    fadeToBlackBy( secondZone, SECONDZONE_LEDS, 80);
    for(int pixel = startPosition+1; pixel < SECONDZONE_LEDS; pixel+=6)  
    {
      if(pixel <= SECONDZONE_LEDS)
      {
        secondZone[pixel] = CRGB(red1,green1,blue1);
      }
    }
    for(int pixel = startPosition+3; pixel < SECONDZONE_LEDS; pixel+=6)
    {
      if(pixel <= SECONDZONE_LEDS)
      {
        secondZone[pixel] = CRGB(red2,green2,blue2);
      }
    }
    for(int pixel = startPosition+5; pixel < SECONDZONE_LEDS; pixel+=6)
    {
      if(pixel <= SECONDZONE_LEDS)
      {
        secondZone[pixel] = CRGB(red3,green3,blue3);
      } 
    }
  }
  if(startPosition == 1)
  {
    secondZone[0]=CRGB(red3,green3,blue3);
  }
  if(startPosition == 2)
  {
    secondZone[1]=CRGB(red3,green3,blue3);
  }
  if(startPosition == 3)
  {
    secondZone[2]=CRGB(red3,green3,blue3);
    secondZone[0]=CRGB(red2,green2,blue2);
  }
  if(startPosition == 4)
  {
    secondZone[3]=CRGB(red3,green3,blue3);
    secondZone[1]=CRGB(red2,green2,blue2);
  }
  if(startPosition == 5)
  {
    secondZone[4]=CRGB(red3,green3,blue3);
    secondZone[2]=CRGB(red2,green2,blue2);
    secondZone[0]=CRGB(red1,green1,blue1);
  }
}

void ColorGlitter_secondZone( fract8 chanceOfGlitter) 
{
  fadeToBlackBy( secondZone, SECONDZONE_LEDS, 2);
  if(startPosition == 0)
  {
    if( random8() < chanceOfGlitter) 
    {
    secondZone[ random16(SECONDZONE_LEDS) ] += CRGB::Red;
    }
  }
  if(startPosition == 1)
  {
    if( random8() < chanceOfGlitter) 
    {
    secondZone[ random16(SECONDZONE_LEDS) ] += CRGB::Orange;
    }
  }
  if(startPosition == 2)
  {
    if( random8() < chanceOfGlitter) 
    {
    secondZone[ random16(SECONDZONE_LEDS) ] += CRGB::Yellow;
    }  
  }
  if(startPosition == 3)
  {
    if( random8() < chanceOfGlitter) 
    {
    secondZone[ random16(SECONDZONE_LEDS) ] += CRGB::Green;
    }
  }
  if(startPosition == 4)
  {
    if( random8() < chanceOfGlitter) 
    {
    secondZone[ random16(SECONDZONE_LEDS) ] += CRGB::Blue;
    }
  }
  if(startPosition == 5)
  {
    if( random8() < chanceOfGlitter) 
    {
    secondZone[ random16(SECONDZONE_LEDS) ] += CRGB::Violet;
    }
  } 
}

void SingleRace_secondZone()
{
  fadeToBlackBy( secondZone, SECONDZONE_LEDS, 1);
  int pos = beatsin16( raceSpeed, 0, 474);
  if(pos > previousLED_secondZone)
  {
    secondZone[pos] = CRGB(red1,green1,blue1);
    previousLED_secondZone = pos;
  }
  if(pos < previousLED_secondZone)
  {
    secondZone[pos] = CRGB(red2,green2,blue2);
    previousLED_secondZone = pos;
  }                 
}

void Crash_secondZone()
{
  fadeToBlackBy( secondZone, SECONDZONE_LEDS, 15);
  #ifdef ZONETWO_SECTION1_START
  int pos_SECTION1 = beatsin16( raceSpeed, 0, (ZONETWO_SECTION1_END - ZONETWO_SECTION1_START) );
  secondZone[ZONETWO_SECTION1_START + pos_SECTION1] = CRGB(red1,green1,blue1);
  secondZone[ZONETWO_SECTION1_END - pos_SECTION1] = CRGB(red2,green2,blue2);
  #endif

  #ifdef ZONETWO_SECTION2_START
  int pos_SECTION2 = beatsin16( raceSpeed, 0, (ZONETWO_SECTION2_END - ZONETWO_SECTION2_START) );
  secondZone[ZONETWO_SECTION2_START + pos_SECTION2] = CRGB(red2,green2,blue2);
  secondZone[ZONETWO_SECTION2_END - pos_SECTION2] = CRGB(red1,green1,blue1);
  #endif
  
  #ifdef ZONETWO_SECTION3_START
  int pos_SECTION3 = beatsin16( raceSpeed, 0, (ZONETWO_SECTION3_END - ZONETWO_SECTION3_START) );
  secondZone[ZONETWO_SECTION3_START + pos_SECTION3] = CRGB(red1,green1,blue1);
  secondZone[ZONETWO_SECTION3_END - pos_SECTION3] = CRGB(red2,green2,blue2);
  #endif
  
  #ifdef ZONETWO_SECTION4_START
  int pos_SECTION4 = beatsin16( raceSpeed, 0, (ZONETWO_SECTION4_END - ZONETWO_SECTION4_START) );
  secondZone[ZONETWO_SECTION4_START + pos_SECTION4] = CRGB(red2,green2,blue2);
  secondZone[ZONETWO_SECTION4_END - pos_SECTION4] = CRGB(red1,green1,blue1);
  #endif
  
  #ifdef ZONETWO_SECTION5_START
  int pos_SECTION5 = beatsin16( raceSpeed, 0, (ZONETWO_SECTION5_END - ZONETWO_SECTION5_START) );
  secondZone[ZONETWO_SECTION5_START + pos_SECTION5] = CRGB(red1,green1,blue1);
  secondZone[ZONETWO_SECTION5_END - pos_SECTION5] = CRGB(red2,green2,blue2);
  #endif
  
  #ifdef ZONETWO_SECTION6_START
  int pos_SECTION6 = beatsin16( raceSpeed, 0, (ZONETWO_SECTION6_END - ZONETWO_SECTION6_START) );
  secondZone[ZONETWO_SECTION6_START + pos_SECTION6] = CRGB(red2,green2,blue2);
  secondZone[ZONETWO_SECTION6_END - pos_SECTION6] = CRGB(red1,green1,blue1);
  #endif
  
  #ifdef ZONETWO_SECTION7_START
  int pos_SECTION7 = beatsin16( raceSpeed, 0, (ZONETWO_SECTION7_END - ZONETWO_SECTION7_START) );
  secondZone[ZONETWO_SECTION7_START + pos_SECTION7] = CRGB(red1,green1,blue1);
  secondZone[ZONETWO_SECTION7_END - pos_SECTION7] = CRGB(red2,green2,blue2);
  #endif
  
  #ifdef ZONETWO_SECTION8_START
  int pos_SECTION8 = beatsin16( raceSpeed, 0, (ZONETWO_SECTION8_END - ZONETWO_SECTION8_START) );
  secondZone[ZONETWO_SECTION8_START + pos_SECTION8] = CRGB(red2,green2,blue2);
  secondZone[ZONETWO_SECTION8_END - pos_SECTION8] = CRGB(red1,green1,blue1);
  #endif
  
  #ifdef ZONETWO_SECTION9_START
  int pos_SECTION9 = beatsin16( raceSpeed, 0, (ZONETWO_SECTION9_END - ZONETWO_SECTION9_START) );
  secondZone[ZONETWO_SECTION9_START + pos_SECTION9] = CRGB(red1,green1,blue1);
  secondZone[ZONETWO_SECTION9_END - pos_SECTION9] = CRGB(red2,green2,blue2);
  #endif
  
}

void Rainbow_secondZone()
{
  fill_rainbow( secondZone, SECONDZONE_LEDS, gHue, numberOfRainbows);
}

void Blocked_secondZone()
{
  fadeToBlackBy( secondZone, SECONDZONE_LEDS, 2);
  for( int mark = 0; mark < SECONDZONE_LEDS; mark+=30)
  {
    for( int i = 0; i < 9; i++) 
    {
      if(startPosition == 0 || startPosition == 1)
      {
        if(i+mark <= SECONDZONE_LEDS)
        {
          secondZone[i+mark] = CRGB(red1,green1,blue1);
        }
        if(i+10+mark <= SECONDZONE_LEDS)
        {
          secondZone[i+10+mark] = CRGB(red2,green2,blue2);
        }
        if(i+20+mark <= SECONDZONE_LEDS)
        {
          secondZone[i+20+mark] = CRGB(red3,green3,blue3);
        }
      }
      if(startPosition == 2 || startPosition == 3)
      {
        if(i+mark <= SECONDZONE_LEDS)
        {
          secondZone[i+mark] = CRGB(red2,green2,blue2);
        }
        if(i+10+mark <= SECONDZONE_LEDS)
        {
          secondZone[i+10+mark] = CRGB(red3,green3,blue3);
        }
        if(i+20+mark <= SECONDZONE_LEDS)
        {
          secondZone[i+20+mark] = CRGB(red1,green1,blue1);
        }
      }
      if(startPosition == 4 || startPosition == 5)
      {
        if(i+mark <= SECONDZONE_LEDS)
        {
          secondZone[i+mark] = CRGB(red3,green3,blue3);
        }
        if(i+10+mark <= SECONDZONE_LEDS)
        {
          secondZone[i+10+mark] = CRGB(red1,green1,blue1);
        }
        if(i+20+mark <= SECONDZONE_LEDS)
        {
          secondZone[i+20+mark] = CRGB(red2,green2,blue2);
        }
      }
    }
  }
}

void BPM_secondZone()
{
  if((red1*2) > (green1 + blue1))
  {
    CRGBPalette16 palette_secondZone = LavaColors_p; 
    uint8_t beat = beatsin16( BeatsPerMinute, 64, 255);
    for( int i = 0; i < SECONDZONE_LEDS; i++) 
    {
      secondZone[i] = ColorFromPalette(palette_secondZone, gHue+(i*2), beat-gHue+(i*10));
    } 
  }
  if((green1*2) > (red1 + blue1))
  {
    CRGBPalette16 palette_secondZone = ForestColors_p; 
    uint8_t beat = beatsin16( BeatsPerMinute, 64, 255);
    for( int i = 0; i < SECONDZONE_LEDS; i++) 
    {
      secondZone[i] = ColorFromPalette(palette_secondZone, gHue+(i*2), beat-gHue+(i*10));
    } 
  }
  if((blue1*2) > (green1 + red1))
  {
    CRGBPalette16 palette_secondZone = CloudColors_p; 
    uint8_t beat = beatsin16( BeatsPerMinute, 64, 255);
    for( int i = 0; i < SECONDZONE_LEDS; i++) 
    {
      secondZone[i] = ColorFromPalette(palette_secondZone, gHue+(i*2), beat-gHue+(i*10));
    } 
  }
  if((blue1*2) == (green1 + red1))
  {
    CRGBPalette16 palette_secondZone = PartyColors_p; 
    uint8_t beat = beatsin16( BeatsPerMinute, 64, 255);
    for( int i = 0; i < SECONDZONE_LEDS; i++) 
    {
      secondZone[i] = ColorFromPalette(palette_secondZone, gHue+(i*2), beat-gHue+(i*10));
    } 
  }
}

void Twinkle_secondZone()
{
  fadeToBlackBy( secondZone, SECONDZONE_LEDS, 80);
  for( int i = 0; i < SECONDZONE_LEDS-5; i+=5)
  {
    if(i <= SECONDZONE_LEDS)
    {
      if (random8() > twinkleChance)
      {
        secondZone[i] = CRGB( red1, green1, blue1);
      }
      else
      {
        secondZone[i] = CRGB( 150, 100, 40);
      }  
    }
  }                     
}

void Eyes_secondZone()
{
  unsigned int chance = random8();
  if( chance > eyeChance) 
  {
    unsigned int eye = random16(SECONDZONE_LEDS);  
    secondZone[eye] = CRGB(red1,green1,blue1);
    secondZone[eye-4] = CRGB(red1,green1,blue1);
  }
  if( chance > 39) 
  {
    fadeToBlackBy( secondZone, SECONDZONE_LEDS, 10);
  }
}

void Solid_secondZone()
{
  fill_solid(secondZone, SECONDZONE_LEDS, CRGB(red1, green1, blue1));
}

void Locator_secondZone()
{
  if(locatorLED <= SECONDZONE_LEDS)
  {
    fill_solid(secondZone, SECONDZONE_LEDS, CRGB::Black); 
    secondZone[locatorLED]=CRGB(red1, green1, blue1);
  }
}

#ifdef ZONETWO_SECTION1_START
void fire_secondZone_SECTION1()
{
  static byte heat[ZONETWO_SECTION1_END - ZONETWO_SECTION1_START];
  for( int i = 0; i < ZONETWO_SECTION1_END - ZONETWO_SECTION1_START; i++) 
  {
    heat[i] = qsub8( heat[i],  random8(0, ((COOLING * 10) / ZONETWO_SECTION1_END - ZONETWO_SECTION1_START) + 2));
  }

  for( int k= ZONETWO_SECTION1_END - ZONETWO_SECTION1_START - 1; k >= 2; k--) 
  {
    heat[k] = (heat[k - 1] + heat[k - 2] + heat[k - 2] ) / 3;
  }
  if( random8() < SPARKING ) 
  {
    int y = random8(7);
    heat[y] = qadd8( heat[y], random8(160,255) );
  }
  for( int j = 0; j < ZONETWO_SECTION1_END - ZONETWO_SECTION1_START; j++) 
  {
    byte colorindex = scale8( heat[j], 240);
    CRGB color = ColorFromPalette( gPal, colorindex);
    int pixelnumber;
    if( gReverseDirection ) {
      pixelnumber = (ZONETWO_SECTION1_END - ZONETWO_SECTION1_START -1) - j;
    } else {
      pixelnumber = j;
    }
    int thisFlame = ((pixelnumber * firesize)/100);
    if(thisFlame <=  ZONETWO_SECTION1_START && thisFlame <= ZONETWO_SECTION1_END)
    
    #if ZONETWO_SECTION1_START_FIRE == 1
    {
      secondZone[ZONETWO_SECTION1_START + thisFlame] = color;
    }
    #endif
    
    #if ZONETWO_SECTION1_END_FIRE == 1
    {
      secondZone[ZONETWO_SECTION1_END - thisFlame] = color;
    }
    #endif
  }
}
#endif

#ifdef ZONETWO_SECTION2_START
void fire_secondZone_SECTION2()
{
  static byte heat[ZONETWO_SECTION2_END - ZONETWO_SECTION2_START];
  for( int i = 0; i < ZONETWO_SECTION2_END - ZONETWO_SECTION2_START; i++) 
  {
    heat[i] = qsub8( heat[i],  random8(0, ((COOLING * 10) / ZONETWO_SECTION2_END - ZONETWO_SECTION2_START) + 2));
  }

  for( int k= ZONETWO_SECTION2_END - ZONETWO_SECTION2_START - 1; k >= 2; k--) 
  {
    heat[k] = (heat[k - 1] + heat[k - 2] + heat[k - 2] ) / 3;
  }
  if( random8() < SPARKING ) 
  {
    int y = random8(7);
    heat[y] = qadd8( heat[y], random8(160,255) );
  }
  for( int j = 0; j < ZONETWO_SECTION2_END - ZONETWO_SECTION2_START; j++) 
  {
    byte colorindex = scale8( heat[j], 240);
    CRGB color = ColorFromPalette( gPal, colorindex);
    int pixelnumber;
    if( gReverseDirection ) {
      pixelnumber = (ZONETWO_SECTION2_END - ZONETWO_SECTION2_START -1) - j;
    } else {
      pixelnumber = j;
    }
    int thisFlame = ((pixelnumber * firesize)/100);
    if(thisFlame <=  ZONETWO_SECTION2_START && thisFlame <= ZONETWO_SECTION2_END)
    
    #if ZONETWO_SECTION2_START_FIRE == 1
    {
      secondZone[ZONETWO_SECTION2_START + thisFlame] = color;
    }
    #endif
    
    #if ZONETWO_SECTION2_END_FIRE == 1
    {
      secondZone[ZONETWO_SECTION2_END - thisFlame] = color;
    }
    #endif
  }
}
#endif

#ifdef ZONETWO_SECTION3_START
void fire_secondZone_SECTION3()
{
  static byte heat[ZONETWO_SECTION3_END - ZONETWO_SECTION3_START];
  for( int i = 0; i < ZONETWO_SECTION3_END - ZONETWO_SECTION3_START; i++) 
  {
    heat[i] = qsub8( heat[i],  random8(0, ((COOLING * 10) / ZONETWO_SECTION3_END - ZONETWO_SECTION3_START) + 2));
  }

  for( int k= ZONETWO_SECTION3_END - ZONETWO_SECTION3_START - 1; k >= 2; k--) 
  {
    heat[k] = (heat[k - 1] + heat[k - 2] + heat[k - 2] ) / 3;
  }
  if( random8() < SPARKING ) 
  {
    int y = random8(7);
    heat[y] = qadd8( heat[y], random8(160,255) );
  }
  for( int j = 0; j < ZONETWO_SECTION3_END - ZONETWO_SECTION3_START; j++) 
  {
    byte colorindex = scale8( heat[j], 240);
    CRGB color = ColorFromPalette( gPal, colorindex);
    int pixelnumber;
    if( gReverseDirection ) {
      pixelnumber = (ZONETWO_SECTION3_END - ZONETWO_SECTION3_START -1) - j;
    } else {
      pixelnumber = j;
    }
    int thisFlame = ((pixelnumber * firesize)/100);
    if(thisFlame <=  ZONETWO_SECTION3_START && thisFlame <= ZONETWO_SECTION3_END)
    
    #if ZONETWO_SECTION3_START_FIRE == 1
    {
      secondZone[ZONETWO_SECTION3_START + thisFlame] = color;
    }
    #endif
    
    #if ZONETWO_SECTION3_END_FIRE == 1
    {
      secondZone[ZONETWO_SECTION3_END - thisFlame] = color;
    }
    #endif
  }
}
#endif

#ifdef ZONETWO_SECTION4_START
void fire_secondZone_SECTION4()
{
  static byte heat[ZONETWO_SECTION4_END - ZONETWO_SECTION4_START];
  for( int i = 0; i < ZONETWO_SECTION4_END - ZONETWO_SECTION4_START; i++) 
  {
    heat[i] = qsub8( heat[i],  random8(0, ((COOLING * 10) / ZONETWO_SECTION4_END - ZONETWO_SECTION4_START) + 2));
  }

  for( int k= ZONETWO_SECTION4_END - ZONETWO_SECTION4_START - 1; k >= 2; k--) 
  {
    heat[k] = (heat[k - 1] + heat[k - 2] + heat[k - 2] ) / 3;
  }
  if( random8() < SPARKING ) 
  {
    int y = random8(7);
    heat[y] = qadd8( heat[y], random8(160,255) );
  }
  for( int j = 0; j < ZONETWO_SECTION4_END - ZONETWO_SECTION4_START; j++) 
  {
    byte colorindex = scale8( heat[j], 240);
    CRGB color = ColorFromPalette( gPal, colorindex);
    int pixelnumber;
    if( gReverseDirection ) {
      pixelnumber = (ZONETWO_SECTION4_END - ZONETWO_SECTION4_START -1) - j;
    } else {
      pixelnumber = j;
    }
    int thisFlame = ((pixelnumber * firesize)/100);
    if(thisFlame <=  ZONETWO_SECTION4_START && thisFlame <= ZONETWO_SECTION4_END)
    
    #if ZONETWO_SECTION4_START_FIRE == 1
    {
      secondZone[ZONETWO_SECTION4_START + thisFlame] = color;
    }
    #endif
    
    #if ZONETWO_SECTION4_END_FIRE == 1
    {
      secondZone[ZONETWO_SECTION4_END - thisFlame] = color;
    }
    #endif
  }
}
#endif

#ifdef ZONETWO_SECTION5_START
void fire_secondZone_SECTION5()
{
  static byte heat[ZONETWO_SECTION5_END - ZONETWO_SECTION5_START];
  for( int i = 0; i < ZONETWO_SECTION5_END - ZONETWO_SECTION5_START; i++) 
  {
    heat[i] = qsub8( heat[i],  random8(0, ((COOLING * 10) / ZONETWO_SECTION5_END - ZONETWO_SECTION5_START) + 2));
  }

  for( int k= ZONETWO_SECTION5_END - ZONETWO_SECTION5_START - 1; k >= 2; k--) 
  {
    heat[k] = (heat[k - 1] + heat[k - 2] + heat[k - 2] ) / 3;
  }
  if( random8() < SPARKING ) 
  {
    int y = random8(7);
    heat[y] = qadd8( heat[y], random8(160,255) );
  }
  for( int j = 0; j < ZONETWO_SECTION5_END - ZONETWO_SECTION5_START; j++) 
  {
    byte colorindex = scale8( heat[j], 240);
    CRGB color = ColorFromPalette( gPal, colorindex);
    int pixelnumber;
    if( gReverseDirection ) {
      pixelnumber = (ZONETWO_SECTION5_END - ZONETWO_SECTION5_START -1) - j;
    } else {
      pixelnumber = j;
    }
    int thisFlame = ((pixelnumber * firesize)/100);
    if(thisFlame <=  ZONETWO_SECTION5_START && thisFlame <= ZONETWO_SECTION5_END)
    
    #if ZONETWO_SECTION5_START_FIRE == 1
    {
      secondZone[ZONETWO_SECTION5_START + thisFlame] = color;
    }
    #endif
    
    #if ZONETWO_SECTION5_END_FIRE == 1
    {
      secondZone[ZONETWO_SECTION5_END - thisFlame] = color;
    }
    #endif
  }
}
#endif

#ifdef ZONETWO_SECTION6_START
void fire_secondZone_SECTION6()
{
  static byte heat[ZONETWO_SECTION6_END - ZONETWO_SECTION6_START];
  for( int i = 0; i < ZONETWO_SECTION6_END - ZONETWO_SECTION6_START; i++) 
  {
    heat[i] = qsub8( heat[i],  random8(0, ((COOLING * 10) / ZONETWO_SECTION6_END - ZONETWO_SECTION6_START) + 2));
  }

  for( int k= ZONETWO_SECTION6_END - ZONETWO_SECTION6_START - 1; k >= 2; k--) 
  {
    heat[k] = (heat[k - 1] + heat[k - 2] + heat[k - 2] ) / 3;
  }
  if( random8() < SPARKING ) 
  {
    int y = random8(7);
    heat[y] = qadd8( heat[y], random8(160,255) );
  }
  for( int j = 0; j < ZONETWO_SECTION6_END - ZONETWO_SECTION6_START; j++) 
  {
    byte colorindex = scale8( heat[j], 240);
    CRGB color = ColorFromPalette( gPal, colorindex);
    int pixelnumber;
    if( gReverseDirection ) {
      pixelnumber = (ZONETWO_SECTION6_END - ZONETWO_SECTION6_START -1) - j;
    } else {
      pixelnumber = j;
    }
    int thisFlame = ((pixelnumber * firesize)/100);
    if(thisFlame <=  ZONETWO_SECTION6_START && thisFlame <= ZONETWO_SECTION6_END)
    
    #if ZONETWO_SECTION6_START_FIRE == 1
    {
      secondZone[ZONETWO_SECTION6_START + thisFlame] = color;
    }
    #endif
    
    #if ZONETWO_SECTION6_END_FIRE == 1
    {
      secondZone[ZONETWO_SECTION6_END - thisFlame] = color;
    }
    #endif
  }
}
#endif

#ifdef ZONETWO_SECTION7_START
void fire_secondZone_SECTION7()
{
  static byte heat[ZONETWO_SECTION7_END - ZONETWO_SECTION7_START];
  for( int i = 0; i < ZONETWO_SECTION7_END - ZONETWO_SECTION7_START; i++) 
  {
    heat[i] = qsub8( heat[i],  random8(0, ((COOLING * 10) / ZONETWO_SECTION7_END - ZONETWO_SECTION7_START) + 2));
  }

  for( int k= ZONETWO_SECTION7_END - ZONETWO_SECTION7_START - 1; k >= 2; k--) 
  {
    heat[k] = (heat[k - 1] + heat[k - 2] + heat[k - 2] ) / 3;
  }
  if( random8() < SPARKING ) 
  {
    int y = random8(7);
    heat[y] = qadd8( heat[y], random8(160,255) );
  }
  for( int j = 0; j < ZONETWO_SECTION7_END - ZONETWO_SECTION7_START; j++) 
  {
    byte colorindex = scale8( heat[j], 240);
    CRGB color = ColorFromPalette( gPal, colorindex);
    int pixelnumber;
    if( gReverseDirection ) {
      pixelnumber = (ZONETWO_SECTION7_END - ZONETWO_SECTION7_START -1) - j;
    } else {
      pixelnumber = j;
    }
    int thisFlame = ((pixelnumber * firesize)/100);
    if(thisFlame <=  ZONETWO_SECTION7_START && thisFlame <= ZONETWO_SECTION7_END)
    
    #if ZONETWO_SECTION7_START_FIRE == 1
    {
      secondZone[ZONETWO_SECTION7_START + thisFlame] = color;
    }
    #endif
    
    #if ZONETWO_SECTION7_END_FIRE == 1
    {
      secondZone[ZONETWO_SECTION7_END - thisFlame] = color;
    }
    #endif
  }
}
#endif

#ifdef ZONETWO_SECTION8_START
void fire_secondZone_SECTION8()
{
  static byte heat[ZONETWO_SECTION8_END - ZONETWO_SECTION8_START];
  for( int i = 0; i < ZONETWO_SECTION8_END - ZONETWO_SECTION8_START; i++) 
  {
    heat[i] = qsub8( heat[i],  random8(0, ((COOLING * 10) / ZONETWO_SECTION8_END - ZONETWO_SECTION8_START) + 2));
  }

  for( int k= ZONETWO_SECTION8_END - ZONETWO_SECTION8_START - 1; k >= 2; k--) 
  {
    heat[k] = (heat[k - 1] + heat[k - 2] + heat[k - 2] ) / 3;
  }
  if( random8() < SPARKING ) 
  {
    int y = random8(7);
    heat[y] = qadd8( heat[y], random8(160,255) );
  }
  for( int j = 0; j < ZONETWO_SECTION8_END - ZONETWO_SECTION8_START; j++) 
  {
    byte colorindex = scale8( heat[j], 240);
    CRGB color = ColorFromPalette( gPal, colorindex);
    int pixelnumber;
    if( gReverseDirection ) {
      pixelnumber = (ZONETWO_SECTION8_END - ZONETWO_SECTION8_START -1) - j;
    } else {
      pixelnumber = j;
    }
    int thisFlame = ((pixelnumber * firesize)/100);
    if(thisFlame <=  ZONETWO_SECTION8_START && thisFlame <= ZONETWO_SECTION8_END)
    
    #if ZONETWO_SECTION8_START_FIRE == 1
    {
      secondZone[ZONETWO_SECTION8_START + thisFlame] = color;
    }
    #endif
    
    #if ZONETWO_SECTION8_END_FIRE == 1
    {
      secondZone[ZONETWO_SECTION8_END - thisFlame] = color;
    }
    #endif
  }
}
#endif

#ifdef ZONETWO_SECTION9_START
void fire_secondZone_SECTION9()
{
  static byte heat[ZONETWO_SECTION9_END - ZONETWO_SECTION9_START];
  for( int i = 0; i < ZONETWO_SECTION9_END - ZONETWO_SECTION9_START; i++) 
  {
    heat[i] = qsub8( heat[i],  random8(0, ((COOLING * 10) / ZONETWO_SECTION9_END - ZONETWO_SECTION9_START) + 2));
  }

  for( int k= ZONETWO_SECTION9_END - ZONETWO_SECTION9_START - 1; k >= 2; k--) 
  {
    heat[k] = (heat[k - 1] + heat[k - 2] + heat[k - 2] ) / 3;
  }
  if( random8() < SPARKING ) 
  {
    int y = random8(7);
    heat[y] = qadd8( heat[y], random8(160,255) );
  }
  for( int j = 0; j < ZONETWO_SECTION9_END - ZONETWO_SECTION9_START; j++) 
  {
    byte colorindex = scale8( heat[j], 240);
    CRGB color = ColorFromPalette( gPal, colorindex);
    int pixelnumber;
    if( gReverseDirection ) {
      pixelnumber = (ZONETWO_SECTION9_END - ZONETWO_SECTION9_START -1) - j;
    } else {
      pixelnumber = j;
    }
    int thisFlame = ((pixelnumber * firesize)/100);
    if(thisFlame <=  ZONETWO_SECTION9_START && thisFlame <= ZONETWO_SECTION9_END)
    
    #if ZONETWO_SECTION9_START_FIRE == 1
    {
      secondZone[ZONETWO_SECTION9_START + thisFlame] = color;
    }
    #endif
    
    #if ZONETWO_SECTION9_END_FIRE == 1
    {
      secondZone[ZONETWO_SECTION9_END - thisFlame] = color;
    }
    #endif
  }
}
#endif

#endif

/*****************  thirdZone Animations  ****************************************/
/*****************  thirdZone Animations  ****************************************/
/*****************  thirdZone Animations  ****************************************/
/*****************  thirdZone Animations  ****************************************/
/*****************  thirdZone Animations  ****************************************/

#if ZONETHREE == 1

void Ripple_thirdZone()
{
  for (int i = 0; i < THIRDZONE_LEDS; i++)
  {
    thirdZone[i] = CRGB((red2/75), (green2/75), (blue2/75));
  }   
  switch (step_thirdZone) 
  {
    case -1:                                                          
      center_thirdZone = random16(THIRDZONE_LEDS);
      step_thirdZone = 0;
      break;
    case 0:
      thirdZone[center_thirdZone] = CRGB(red1, green1, blue1);                          
      step_thirdZone ++;
      break;
    case 12:                                                   
      step_thirdZone = -1;
      break;
    default:                                                             // Middle of the ripples.
      thirdZone[(center_thirdZone + step_thirdZone + THIRDZONE_LEDS) % THIRDZONE_LEDS] += CRGB((red1/(step_thirdZone * 5)), (green1/(step_thirdZone * 5)), (blue1/(step_thirdZone * 5)));
      thirdZone[(center_thirdZone - step_thirdZone + THIRDZONE_LEDS) % THIRDZONE_LEDS] += CRGB((red1/(step_thirdZone * 5)), (green1/(step_thirdZone * 5)), (blue1/(step_thirdZone * 5)));
      step_thirdZone ++;                                                         
      break;
  }
}

void RGB_thirdZone()
{
  if(startPosition < 6)
  {
    fadeToBlackBy( thirdZone, THIRDZONE_LEDS, 80);
    for(int pixel = startPosition+1; pixel < THIRDZONE_LEDS; pixel+=6)  
    {
      if(pixel <= THIRDZONE_LEDS)
      {
        thirdZone[pixel] = CRGB(red1,green1,blue1);
      }
    }
    for(int pixel = startPosition+3; pixel < THIRDZONE_LEDS; pixel+=6)
    {
      if(pixel <= THIRDZONE_LEDS)
      {
        thirdZone[pixel] = CRGB(red2,green2,blue2);
      }
    }
    for(int pixel = startPosition+5; pixel < THIRDZONE_LEDS; pixel+=6)
    {
      if(pixel <= THIRDZONE_LEDS)
      {
        thirdZone[pixel] = CRGB(red3,green3,blue3);
      } 
    }
  }
  if(startPosition == 1)
  {
    thirdZone[0]=CRGB(red3,green3,blue3);
  }
  if(startPosition == 2)
  {
    thirdZone[1]=CRGB(red3,green3,blue3);
  }
  if(startPosition == 3)
  {
    thirdZone[2]=CRGB(red3,green3,blue3);
    thirdZone[0]=CRGB(red2,green2,blue2);
  }
  if(startPosition == 4)
  {
    thirdZone[3]=CRGB(red3,green3,blue3);
    thirdZone[1]=CRGB(red2,green2,blue2);
  }
  if(startPosition == 5)
  {
    thirdZone[4]=CRGB(red3,green3,blue3);
    thirdZone[2]=CRGB(red2,green2,blue2);
    thirdZone[0]=CRGB(red1,green1,blue1);
  }
}

void ColorGlitter_thirdZone( fract8 chanceOfGlitter) 
{
  fadeToBlackBy( thirdZone, THIRDZONE_LEDS, 2);
  if(startPosition == 0)
  {
    if( random8() < chanceOfGlitter) 
    {
    thirdZone[ random16(THIRDZONE_LEDS) ] += CRGB::Red;
    }
  }
  if(startPosition == 1)
  {
    if( random8() < chanceOfGlitter) 
    {
    thirdZone[ random16(THIRDZONE_LEDS) ] += CRGB::Orange;
    }
  }
  if(startPosition == 2)
  {
    if( random8() < chanceOfGlitter) 
    {
    thirdZone[ random16(THIRDZONE_LEDS) ] += CRGB::Yellow;
    }  
  }
  if(startPosition == 3)
  {
    if( random8() < chanceOfGlitter) 
    {
    thirdZone[ random16(THIRDZONE_LEDS) ] += CRGB::Green;
    }
  }
  if(startPosition == 4)
  {
    if( random8() < chanceOfGlitter) 
    {
    thirdZone[ random16(THIRDZONE_LEDS) ] += CRGB::Blue;
    }
  }
  if(startPosition == 5)
  {
    if( random8() < chanceOfGlitter) 
    {
    thirdZone[ random16(THIRDZONE_LEDS) ] += CRGB::Violet;
    }
  } 
}

void SingleRace_thirdZone()
{
  fadeToBlackBy( thirdZone, THIRDZONE_LEDS, 1);
  int pos = beatsin16( raceSpeed, 0, 474);
  if(pos > previousLED_thirdZone)
  {
    thirdZone[pos] = CRGB(red1,green1,blue1);
    previousLED_thirdZone = pos;
  }
  if(pos < previousLED_thirdZone)
  {
    thirdZone[pos] = CRGB(red2,green2,blue2);
    previousLED_thirdZone = pos;
  }                 
}

  void Crash_thirdZone()
{
  fadeToBlackBy( thirdZone, THIRDZONE_LEDS, 15);
  #ifdef ZONETHREE_SECTION1_START
  int pos_SECTION1 = beatsin16( raceSpeed, 0, (ZONETHREE_SECTION1_END - ZONETHREE_SECTION1_START) );
  thirdZone[ZONETHREE_SECTION1_START + pos_SECTION1] = CRGB(red1,green1,blue1);
  thirdZone[ZONETHREE_SECTION1_END - pos_SECTION1] = CRGB(red2,green2,blue2);
  #endif

  #ifdef ZONETHREE_SECTION2_START
  int pos_SECTION2 = beatsin16( raceSpeed, 0, (ZONETHREE_SECTION2_END - ZONETHREE_SECTION2_START) );
  thirdZone[ZONETHREE_SECTION2_START + pos_SECTION2] = CRGB(red2,green2,blue2);
  thirdZone[ZONETHREE_SECTION2_END - pos_SECTION2] = CRGB(red1,green1,blue1);
  #endif
  
  #ifdef ZONETHREE_SECTION3_START
  int pos_SECTION3 = beatsin16( raceSpeed, 0, (ZONETHREE_SECTION3_END - ZONETHREE_SECTION3_START) );
  thirdZone[ZONETHREE_SECTION3_START + pos_SECTION3] = CRGB(red1,green1,blue1);
  thirdZone[ZONETHREE_SECTION3_END - pos_SECTION3] = CRGB(red2,green2,blue2);
  #endif
  
  #ifdef ZONETHREE_SECTION4_START
  int pos_SECTION4 = beatsin16( raceSpeed, 0, (ZONETHREE_SECTION4_END - ZONETHREE_SECTION4_START) );
  thirdZone[ZONETHREE_SECTION4_START + pos_SECTION4] = CRGB(red2,green2,blue2);
  thirdZone[ZONETHREE_SECTION4_END - pos_SECTION4] = CRGB(red1,green1,blue1);
  #endif
  
  #ifdef ZONETHREE_SECTION5_START
  int pos_SECTION5 = beatsin16( raceSpeed, 0, (ZONETHREE_SECTION5_END - ZONETHREE_SECTION5_START) );
  thirdZone[ZONETHREE_SECTION5_START + pos_SECTION5] = CRGB(red1,green1,blue1);
  thirdZone[ZONETHREE_SECTION5_END - pos_SECTION5] = CRGB(red2,green2,blue2);
  #endif
  
  #ifdef ZONETHREE_SECTION6_START
  int pos_SECTION6 = beatsin16( raceSpeed, 0, (ZONETHREE_SECTION6_END - ZONETHREE_SECTION6_START) );
  thirdZone[ZONETHREE_SECTION6_START + pos_SECTION6] = CRGB(red2,green2,blue2);
  thirdZone[ZONETHREE_SECTION6_END - pos_SECTION6] = CRGB(red1,green1,blue1);
  #endif
  
  #ifdef ZONETHREE_SECTION7_START
  int pos_SECTION7 = beatsin16( raceSpeed, 0, (ZONETHREE_SECTION7_END - ZONETHREE_SECTION7_START) );
  thirdZone[ZONETHREE_SECTION7_START + pos_SECTION7] = CRGB(red1,green1,blue1);
  thirdZone[ZONETHREE_SECTION7_END - pos_SECTION7] = CRGB(red2,green2,blue2);
  #endif
  
  #ifdef ZONETHREE_SECTION8_START
  int pos_SECTION8 = beatsin16( raceSpeed, 0, (ZONETHREE_SECTION8_END - ZONETHREE_SECTION8_START) );
  thirdZone[ZONETHREE_SECTION8_START + pos_SECTION8] = CRGB(red2,green2,blue2);
  thirdZone[ZONETHREE_SECTION8_END - pos_SECTION8] = CRGB(red1,green1,blue1);
  #endif
  
  #ifdef ZONETHREE_SECTION9_START
  int pos_SECTION9 = beatsin16( raceSpeed, 0, (ZONETHREE_SECTION9_END - ZONETHREE_SECTION9_START) );
  thirdZone[ZONETHREE_SECTION9_START + pos_SECTION9] = CRGB(red1,green1,blue1);
  thirdZone[ZONETHREE_SECTION9_END - pos_SECTION9] = CRGB(red2,green2,blue2);
  #endif
  
}

void Rainbow_thirdZone()
{
  fill_rainbow( thirdZone, THIRDZONE_LEDS, gHue, numberOfRainbows);
}

void Blocked_thirdZone()
{
  fadeToBlackBy( thirdZone, THIRDZONE_LEDS, 2);
  for( int mark = 0; mark < THIRDZONE_LEDS; mark+=30)
  {
    for( int i = 0; i < 9; i++) 
    {
      if(startPosition == 0 || startPosition == 1)
      {
        if(i+mark <= THIRDZONE_LEDS)
        {
          thirdZone[i+mark] = CRGB(red1,green1,blue1);
        }
        if(i+10+mark <= THIRDZONE_LEDS)
        {
          thirdZone[i+10+mark] = CRGB(red2,green2,blue2);
        }
        if(i+20+mark <= THIRDZONE_LEDS)
        {
          thirdZone[i+20+mark] = CRGB(red3,green3,blue3);
        }
      }
      if(startPosition == 2 || startPosition == 3)
      {
        if(i+mark <= THIRDZONE_LEDS)
        {
          thirdZone[i+mark] = CRGB(red2,green2,blue2);
        }
        if(i+10+mark <= THIRDZONE_LEDS)
        {
          thirdZone[i+10+mark] = CRGB(red3,green3,blue3);
        }
        if(i+20+mark <= THIRDZONE_LEDS)
        {
          thirdZone[i+20+mark] = CRGB(red1,green1,blue1);
        }
      }
      if(startPosition == 4 || startPosition == 5)
      {
        if(i+mark <= THIRDZONE_LEDS)
        {
          thirdZone[i+mark] = CRGB(red3,green3,blue3);
        }
        if(i+10+mark <= THIRDZONE_LEDS)
        {
          thirdZone[i+10+mark] = CRGB(red1,green1,blue1);
        }
        if(i+20+mark <= THIRDZONE_LEDS)
        {
          thirdZone[i+20+mark] = CRGB(red2,green2,blue2);
        }
      }
    }
  }
}

void BPM_thirdZone()
{
  if((red1*2) > (green1 + blue1))
  {
    CRGBPalette16 palette_thirdZone = LavaColors_p; 
    uint8_t beat = beatsin16( BeatsPerMinute, 64, 255);
    for( int i = 0; i < THIRDZONE_LEDS; i++) 
    {
      thirdZone[i] = ColorFromPalette(palette_thirdZone, gHue+(i*2), beat-gHue+(i*10));
    } 
  }
  if((green1*2) > (red1 + blue1))
  {
    CRGBPalette16 palette_thirdZone = ForestColors_p; 
    uint8_t beat = beatsin16( BeatsPerMinute, 64, 255);
    for( int i = 0; i < THIRDZONE_LEDS; i++) 
    {
      thirdZone[i] = ColorFromPalette(palette_thirdZone, gHue+(i*2), beat-gHue+(i*10));
    } 
  }
  if((blue1*2) > (green1 + red1))
  {
    CRGBPalette16 palette_thirdZone = CloudColors_p; 
    uint8_t beat = beatsin16( BeatsPerMinute, 64, 255);
    for( int i = 0; i < THIRDZONE_LEDS; i++) 
    {
      thirdZone[i] = ColorFromPalette(palette_thirdZone, gHue+(i*2), beat-gHue+(i*10));
    } 
  }
  if((blue1*2) == (green1 + red1))
  {
    CRGBPalette16 palette_thirdZone = PartyColors_p; 
    uint8_t beat = beatsin16( BeatsPerMinute, 64, 255);
    for( int i = 0; i < THIRDZONE_LEDS; i++) 
    {
      thirdZone[i] = ColorFromPalette(palette_thirdZone, gHue+(i*2), beat-gHue+(i*10));
    } 
  }
}

void Twinkle_thirdZone()
{
  fadeToBlackBy( thirdZone, THIRDZONE_LEDS, 80);
  for( int i = 0; i < THIRDZONE_LEDS-5; i+=5)
  {
    if(i <= THIRDZONE_LEDS)
    {
      if (random8() > twinkleChance)
      {
        thirdZone[i] = CRGB( red1, green1, blue1);
      }
      else
      {
        thirdZone[i] = CRGB( 150, 100, 40);
      }  
    }
  }                     
}

void Eyes_thirdZone()
{
  unsigned int chance = random8();
  if( chance > eyeChance) 
  {
    unsigned int eye = random16(THIRDZONE_LEDS);  
    thirdZone[eye] = CRGB(red1,green1,blue1);
    thirdZone[eye-4] = CRGB(red1,green1,blue1);
  }
  if( chance > 39) 
  {
    fadeToBlackBy( thirdZone, THIRDZONE_LEDS, 10);
  }
}

void Solid_thirdZone()
{
  fill_solid(thirdZone, THIRDZONE_LEDS, CRGB(red1, green1, blue1));
}

void Locator_thirdZone()
{
  if(locatorLED <= THIRDZONE_LEDS)
  {
    fill_solid(thirdZone, THIRDZONE_LEDS, CRGB::Black); 
    thirdZone[locatorLED]=CRGB(red1, green1, blue1);
  }
}

#ifdef ZONETHREE_SECTION1_START
void fire_thirdZone_SECTION1()
{
  static byte heat[ZONETHREE_SECTION1_END - ZONETHREE_SECTION1_START];
  for( int i = 0; i < ZONETHREE_SECTION1_END - ZONETHREE_SECTION1_START; i++) 
  {
    heat[i] = qsub8( heat[i],  random8(0, ((COOLING * 10) / ZONETHREE_SECTION1_END - ZONETHREE_SECTION1_START) + 2));
  }

  for( int k= ZONETHREE_SECTION1_END - ZONETHREE_SECTION1_START - 1; k >= 2; k--) 
  {
    heat[k] = (heat[k - 1] + heat[k - 2] + heat[k - 2] ) / 3;
  }
  if( random8() < SPARKING ) 
  {
    int y = random8(7);
    heat[y] = qadd8( heat[y], random8(160,255) );
  }
  for( int j = 0; j < ZONETHREE_SECTION1_END - ZONETHREE_SECTION1_START; j++) 
  {
    byte colorindex = scale8( heat[j], 240);
    CRGB color = ColorFromPalette( gPal, colorindex);
    int pixelnumber;
    if( gReverseDirection ) {
      pixelnumber = (ZONETHREE_SECTION1_END - ZONETHREE_SECTION1_START -1) - j;
    } else {
      pixelnumber = j;
    }
    int thisFlame = ((pixelnumber * firesize)/100);
    if(thisFlame <=  ZONETHREE_SECTION1_START && thisFlame <= ZONETHREE_SECTION1_END)
    
    #if ZONETHREE_SECTION1_START_FIRE == 1
    {
      thirdZone[ZONETHREE_SECTION1_START + thisFlame] = color;
    }
    #endif
    
    #if ZONETHREE_SECTION1_END_FIRE == 1
    {
      thirdZone[ZONETHREE_SECTION1_END - thisFlame] = color;
    }
    #endif
  }
}
#endif

#ifdef ZONETHREE_SECTION2_START
void fire_thirdZone_SECTION2()
{
  static byte heat[ZONETHREE_SECTION2_END - ZONETHREE_SECTION2_START];
  for( int i = 0; i < ZONETHREE_SECTION2_END - ZONETHREE_SECTION2_START; i++) 
  {
    heat[i] = qsub8( heat[i],  random8(0, ((COOLING * 10) / ZONETHREE_SECTION2_END - ZONETHREE_SECTION2_START) + 2));
  }

  for( int k= ZONETHREE_SECTION2_END - ZONETHREE_SECTION2_START - 1; k >= 2; k--) 
  {
    heat[k] = (heat[k - 1] + heat[k - 2] + heat[k - 2] ) / 3;
  }
  if( random8() < SPARKING ) 
  {
    int y = random8(7);
    heat[y] = qadd8( heat[y], random8(160,255) );
  }
  for( int j = 0; j < ZONETHREE_SECTION2_END - ZONETHREE_SECTION2_START; j++) 
  {
    byte colorindex = scale8( heat[j], 240);
    CRGB color = ColorFromPalette( gPal, colorindex);
    int pixelnumber;
    if( gReverseDirection ) {
      pixelnumber = (ZONETHREE_SECTION2_END - ZONETHREE_SECTION2_START -1) - j;
    } else {
      pixelnumber = j;
    }
    int thisFlame = ((pixelnumber * firesize)/100);
    if(thisFlame <=  ZONETHREE_SECTION2_START && thisFlame <= ZONETHREE_SECTION2_END)
    
    #if ZONETHREE_SECTION2_START_FIRE == 1
    {
      thirdZone[ZONETHREE_SECTION2_START + thisFlame] = color;
    }
    #endif
    
    #if ZONETHREE_SECTION2_END_FIRE == 1
    {
      thirdZone[ZONETHREE_SECTION2_END - thisFlame] = color;
    }
    #endif
  }
}
#endif

#ifdef ZONETHREE_SECTION3_START
void fire_thirdZone_SECTION3()
{
  static byte heat[ZONETHREE_SECTION3_END - ZONETHREE_SECTION3_START];
  for( int i = 0; i < ZONETHREE_SECTION3_END - ZONETHREE_SECTION3_START; i++) 
  {
    heat[i] = qsub8( heat[i],  random8(0, ((COOLING * 10) / ZONETHREE_SECTION3_END - ZONETHREE_SECTION3_START) + 2));
  }

  for( int k= ZONETHREE_SECTION3_END - ZONETHREE_SECTION3_START - 1; k >= 2; k--) 
  {
    heat[k] = (heat[k - 1] + heat[k - 2] + heat[k - 2] ) / 3;
  }
  if( random8() < SPARKING ) 
  {
    int y = random8(7);
    heat[y] = qadd8( heat[y], random8(160,255) );
  }
  for( int j = 0; j < ZONETHREE_SECTION3_END - ZONETHREE_SECTION3_START; j++) 
  {
    byte colorindex = scale8( heat[j], 240);
    CRGB color = ColorFromPalette( gPal, colorindex);
    int pixelnumber;
    if( gReverseDirection ) {
      pixelnumber = (ZONETHREE_SECTION3_END - ZONETHREE_SECTION3_START -1) - j;
    } else {
      pixelnumber = j;
    }
    int thisFlame = ((pixelnumber * firesize)/100);
    if(thisFlame <=  ZONETHREE_SECTION3_START && thisFlame <= ZONETHREE_SECTION3_END)
    
    #if ZONETHREE_SECTION3_START_FIRE == 1
    {
      thirdZone[ZONETHREE_SECTION3_START + thisFlame] = color;
    }
    #endif
    
    #if ZONETHREE_SECTION3_END_FIRE == 1
    {
      thirdZone[ZONETHREE_SECTION3_END - thisFlame] = color;
    }
    #endif
  }
}
#endif

#ifdef ZONETHREE_SECTION4_START
void fire_thirdZone_SECTION4()
{
  static byte heat[ZONETHREE_SECTION4_END - ZONETHREE_SECTION4_START];
  for( int i = 0; i < ZONETHREE_SECTION4_END - ZONETHREE_SECTION4_START; i++) 
  {
    heat[i] = qsub8( heat[i],  random8(0, ((COOLING * 10) / ZONETHREE_SECTION4_END - ZONETHREE_SECTION4_START) + 2));
  }

  for( int k= ZONETHREE_SECTION4_END - ZONETHREE_SECTION4_START - 1; k >= 2; k--) 
  {
    heat[k] = (heat[k - 1] + heat[k - 2] + heat[k - 2] ) / 3;
  }
  if( random8() < SPARKING ) 
  {
    int y = random8(7);
    heat[y] = qadd8( heat[y], random8(160,255) );
  }
  for( int j = 0; j < ZONETHREE_SECTION4_END - ZONETHREE_SECTION4_START; j++) 
  {
    byte colorindex = scale8( heat[j], 240);
    CRGB color = ColorFromPalette( gPal, colorindex);
    int pixelnumber;
    if( gReverseDirection ) {
      pixelnumber = (ZONETHREE_SECTION4_END - ZONETHREE_SECTION4_START -1) - j;
    } else {
      pixelnumber = j;
    }
    int thisFlame = ((pixelnumber * firesize)/100);
    if(thisFlame <=  ZONETHREE_SECTION4_START && thisFlame <= ZONETHREE_SECTION4_END)
    
    #if ZONETHREE_SECTION4_START_FIRE == 1
    {
      thirdZone[ZONETHREE_SECTION4_START + thisFlame] = color;
    }
    #endif
    
    #if ZONETHREE_SECTION4_END_FIRE == 1
    {
      thirdZone[ZONETHREE_SECTION4_END - thisFlame] = color;
    }
    #endif
  }
}
#endif

#ifdef ZONETHREE_SECTION5_START
void fire_thirdZone_SECTION5()
{
  static byte heat[ZONETHREE_SECTION5_END - ZONETHREE_SECTION5_START];
  for( int i = 0; i < ZONETHREE_SECTION5_END - ZONETHREE_SECTION5_START; i++) 
  {
    heat[i] = qsub8( heat[i],  random8(0, ((COOLING * 10) / ZONETHREE_SECTION5_END - ZONETHREE_SECTION5_START) + 2));
  }

  for( int k= ZONETHREE_SECTION5_END - ZONETHREE_SECTION5_START - 1; k >= 2; k--) 
  {
    heat[k] = (heat[k - 1] + heat[k - 2] + heat[k - 2] ) / 3;
  }
  if( random8() < SPARKING ) 
  {
    int y = random8(7);
    heat[y] = qadd8( heat[y], random8(160,255) );
  }
  for( int j = 0; j < ZONETHREE_SECTION5_END - ZONETHREE_SECTION5_START; j++) 
  {
    byte colorindex = scale8( heat[j], 240);
    CRGB color = ColorFromPalette( gPal, colorindex);
    int pixelnumber;
    if( gReverseDirection ) {
      pixelnumber = (ZONETHREE_SECTION5_END - ZONETHREE_SECTION5_START -1) - j;
    } else {
      pixelnumber = j;
    }
    int thisFlame = ((pixelnumber * firesize)/100);
    if(thisFlame <=  ZONETHREE_SECTION5_START && thisFlame <= ZONETHREE_SECTION5_END)
    
    #if ZONETHREE_SECTION5_START_FIRE == 1
    {
      thirdZone[ZONETHREE_SECTION5_START + thisFlame] = color;
    }
    #endif
    
    #if ZONETHREE_SECTION5_END_FIRE == 1
    {
      thirdZone[ZONETHREE_SECTION5_END - thisFlame] = color;
    }
    #endif
  }
}
#endif

#ifdef ZONETHREE_SECTION6_START
void fire_thirdZone_SECTION6()
{
  static byte heat[ZONETHREE_SECTION6_END - ZONETHREE_SECTION6_START];
  for( int i = 0; i < ZONETHREE_SECTION6_END - ZONETHREE_SECTION6_START; i++) 
  {
    heat[i] = qsub8( heat[i],  random8(0, ((COOLING * 10) / ZONETHREE_SECTION6_END - ZONETHREE_SECTION6_START) + 2));
  }

  for( int k= ZONETHREE_SECTION6_END - ZONETHREE_SECTION6_START - 1; k >= 2; k--) 
  {
    heat[k] = (heat[k - 1] + heat[k - 2] + heat[k - 2] ) / 3;
  }
  if( random8() < SPARKING ) 
  {
    int y = random8(7);
    heat[y] = qadd8( heat[y], random8(160,255) );
  }
  for( int j = 0; j < ZONETHREE_SECTION6_END - ZONETHREE_SECTION6_START; j++) 
  {
    byte colorindex = scale8( heat[j], 240);
    CRGB color = ColorFromPalette( gPal, colorindex);
    int pixelnumber;
    if( gReverseDirection ) {
      pixelnumber = (ZONETHREE_SECTION6_END - ZONETHREE_SECTION6_START -1) - j;
    } else {
      pixelnumber = j;
    }
    int thisFlame = ((pixelnumber * firesize)/100);
    if(thisFlame <=  ZONETHREE_SECTION6_START && thisFlame <= ZONETHREE_SECTION6_END)
    
    #if ZONETHREE_SECTION6_START_FIRE == 1
    {
      thirdZone[ZONETHREE_SECTION6_START + thisFlame] = color;
    }
    #endif
    
    #if ZONETHREE_SECTION6_END_FIRE == 1
    {
      thirdZone[ZONETHREE_SECTION6_END - thisFlame] = color;
    }
    #endif
  }
}
#endif

#ifdef ZONETHREE_SECTION7_START
void fire_thirdZone_SECTION7()
{
  static byte heat[ZONETHREE_SECTION7_END - ZONETHREE_SECTION7_START];
  for( int i = 0; i < ZONETHREE_SECTION7_END - ZONETHREE_SECTION7_START; i++) 
  {
    heat[i] = qsub8( heat[i],  random8(0, ((COOLING * 10) / ZONETHREE_SECTION7_END - ZONETHREE_SECTION7_START) + 2));
  }

  for( int k= ZONETHREE_SECTION7_END - ZONETHREE_SECTION7_START - 1; k >= 2; k--) 
  {
    heat[k] = (heat[k - 1] + heat[k - 2] + heat[k - 2] ) / 3;
  }
  if( random8() < SPARKING ) 
  {
    int y = random8(7);
    heat[y] = qadd8( heat[y], random8(160,255) );
  }
  for( int j = 0; j < ZONETHREE_SECTION7_END - ZONETHREE_SECTION7_START; j++) 
  {
    byte colorindex = scale8( heat[j], 240);
    CRGB color = ColorFromPalette( gPal, colorindex);
    int pixelnumber;
    if( gReverseDirection ) {
      pixelnumber = (ZONETHREE_SECTION7_END - ZONETHREE_SECTION7_START -1) - j;
    } else {
      pixelnumber = j;
    }
    int thisFlame = ((pixelnumber * firesize)/100);
    if(thisFlame <=  ZONETHREE_SECTION7_START && thisFlame <= ZONETHREE_SECTION7_END)
    
    #if ZONETHREE_SECTION7_START_FIRE == 1
    {
      thirdZone[ZONETHREE_SECTION7_START + thisFlame] = color;
    }
    #endif
    
    #if ZONETHREE_SECTION7_END_FIRE == 1
    {
      thirdZone[ZONETHREE_SECTION7_END - thisFlame] = color;
    }
    #endif
  }
}
#endif

#ifdef ZONETHREE_SECTION8_START
void fire_thirdZone_SECTION8()
{
  static byte heat[ZONETHREE_SECTION8_END - ZONETHREE_SECTION8_START];
  for( int i = 0; i < ZONETHREE_SECTION8_END - ZONETHREE_SECTION8_START; i++) 
  {
    heat[i] = qsub8( heat[i],  random8(0, ((COOLING * 10) / ZONETHREE_SECTION8_END - ZONETHREE_SECTION8_START) + 2));
  }

  for( int k= ZONETHREE_SECTION8_END - ZONETHREE_SECTION8_START - 1; k >= 2; k--) 
  {
    heat[k] = (heat[k - 1] + heat[k - 2] + heat[k - 2] ) / 3;
  }
  if( random8() < SPARKING ) 
  {
    int y = random8(7);
    heat[y] = qadd8( heat[y], random8(160,255) );
  }
  for( int j = 0; j < ZONETHREE_SECTION8_END - ZONETHREE_SECTION8_START; j++) 
  {
    byte colorindex = scale8( heat[j], 240);
    CRGB color = ColorFromPalette( gPal, colorindex);
    int pixelnumber;
    if( gReverseDirection ) {
      pixelnumber = (ZONETHREE_SECTION8_END - ZONETHREE_SECTION8_START -1) - j;
    } else {
      pixelnumber = j;
    }
    int thisFlame = ((pixelnumber * firesize)/100);
    if(thisFlame <=  ZONETHREE_SECTION8_START && thisFlame <= ZONETHREE_SECTION8_END)
    
    #if ZONETHREE_SECTION8_START_FIRE == 1
    {
      thirdZone[ZONETHREE_SECTION8_START + thisFlame] = color;
    }
    #endif
    
    #if ZONETHREE_SECTION8_END_FIRE == 1
    {
      thirdZone[ZONETHREE_SECTION8_END - thisFlame] = color;
    }
    #endif
  }
}
#endif

#ifdef ZONETHREE_SECTION9_START
void fire_thirdZone_SECTION9()
{
  static byte heat[ZONETHREE_SECTION9_END - ZONETHREE_SECTION9_START];
  for( int i = 0; i < ZONETHREE_SECTION9_END - ZONETHREE_SECTION9_START; i++) 
  {
    heat[i] = qsub8( heat[i],  random8(0, ((COOLING * 10) / ZONETHREE_SECTION9_END - ZONETHREE_SECTION9_START) + 2));
  }

  for( int k= ZONETHREE_SECTION9_END - ZONETHREE_SECTION9_START - 1; k >= 2; k--) 
  {
    heat[k] = (heat[k - 1] + heat[k - 2] + heat[k - 2] ) / 3;
  }
  if( random8() < SPARKING ) 
  {
    int y = random8(7);
    heat[y] = qadd8( heat[y], random8(160,255) );
  }
  for( int j = 0; j < ZONETHREE_SECTION9_END - ZONETHREE_SECTION9_START; j++) 
  {
    byte colorindex = scale8( heat[j], 240);
    CRGB color = ColorFromPalette( gPal, colorindex);
    int pixelnumber;
    if( gReverseDirection ) {
      pixelnumber = (ZONETHREE_SECTION9_END - ZONETHREE_SECTION9_START -1) - j;
    } else {
      pixelnumber = j;
    }
    int thisFlame = ((pixelnumber * firesize)/100);
    if(thisFlame <=  ZONETHREE_SECTION9_START && thisFlame <= ZONETHREE_SECTION9_END)
    
    #if ZONETHREE_SECTION9_START_FIRE == 1
    {
      thirdZone[ZONETHREE_SECTION9_START + thisFlame] = color;
    }
    #endif
    
    #if ZONETHREE_SECTION9_END_FIRE == 1
    {
      thirdZone[ZONETHREE_SECTION9_END - thisFlame] = color;
    }
    #endif
  }
}
#endif

#endif

/*****************  fourthZone Animations  ****************************************/
/*****************  fourthZone Animations  ****************************************/
/*****************  fourthZone Animations  ****************************************/
/*****************  fourthZone Animations  ****************************************/
/*****************  fourthZone Animations  ****************************************/

#if ZONEFOUR == 1

void Ripple_fourthZone()
{
  for (int i = 0; i < FOURTHZONE_LEDS; i++)
  {
    fourthZone[i] = CRGB((red2/75), (green2/75), (blue2/75));
  }   
  switch (step_fourthZone) 
  {
    case -1:                                                          
      center_fourthZone = random16(FOURTHZONE_LEDS);
      step_fourthZone = 0;
      break;
    case 0:
      fourthZone[center_fourthZone] = CRGB(red1, green1, blue1);                          
      step_fourthZone ++;
      break;
    case 12:                                                   
      step_fourthZone = -1;
      break;
    default:                                                             // Middle of the ripples.
      fourthZone[(center_fourthZone + step_fourthZone + FOURTHZONE_LEDS) % FOURTHZONE_LEDS] += CRGB((red1/(step_fourthZone * 5)), (green1/(step_fourthZone * 5)), (blue1/(step_fourthZone * 5)));
      fourthZone[(center_fourthZone - step_fourthZone + FOURTHZONE_LEDS) % FOURTHZONE_LEDS] += CRGB((red1/(step_fourthZone * 5)), (green1/(step_fourthZone * 5)), (blue1/(step_fourthZone * 5)));
      step_fourthZone ++;                                                         
      break;
  }
}

void RGB_fourthZone()
{
  if(startPosition < 6)
  {
    fadeToBlackBy( fourthZone, FOURTHZONE_LEDS, 80);
    for(int pixel = startPosition+1; pixel < FOURTHZONE_LEDS; pixel+=6)  
    {
      if(pixel <= FOURTHZONE_LEDS)
      {
        fourthZone[pixel] = CRGB(red1,green1,blue1);
      }
    }
    for(int pixel = startPosition+3; pixel < FOURTHZONE_LEDS; pixel+=6)
    {
      if(pixel <= FOURTHZONE_LEDS)
      {
        fourthZone[pixel] = CRGB(red2,green2,blue2);
      }
    }
    for(int pixel = startPosition+5; pixel < FOURTHZONE_LEDS; pixel+=6)
    {
      if(pixel <= FOURTHZONE_LEDS)
      {
        fourthZone[pixel] = CRGB(red3,green3,blue3);
      } 
    }
  }
  if(startPosition == 1)
  {
    fourthZone[0]=CRGB(red3,green3,blue3);
  }
  if(startPosition == 2)
  {
    fourthZone[1]=CRGB(red3,green3,blue3);
  }
  if(startPosition == 3)
  {
    fourthZone[2]=CRGB(red3,green3,blue3);
    fourthZone[0]=CRGB(red2,green2,blue2);
  }
  if(startPosition == 4)
  {
    fourthZone[3]=CRGB(red3,green3,blue3);
    fourthZone[1]=CRGB(red2,green2,blue2);
  }
  if(startPosition == 5)
  {
    fourthZone[4]=CRGB(red3,green3,blue3);
    fourthZone[2]=CRGB(red2,green2,blue2);
    fourthZone[0]=CRGB(red1,green1,blue1);
  }
}

void ColorGlitter_fourthZone( fract8 chanceOfGlitter) 
{
  fadeToBlackBy( fourthZone, FOURTHZONE_LEDS, 2);
  if(startPosition == 0)
  {
    if( random8() < chanceOfGlitter) 
    {
    fourthZone[ random16(FOURTHZONE_LEDS) ] += CRGB::Red;
    }
  }
  if(startPosition == 1)
  {
    if( random8() < chanceOfGlitter) 
    {
    fourthZone[ random16(FOURTHZONE_LEDS) ] += CRGB::Orange;
    }
  }
  if(startPosition == 2)
  {
    if( random8() < chanceOfGlitter) 
    {
    fourthZone[ random16(FOURTHZONE_LEDS) ] += CRGB::Yellow;
    }  
  }
  if(startPosition == 3)
  {
    if( random8() < chanceOfGlitter) 
    {
    fourthZone[ random16(FOURTHZONE_LEDS) ] += CRGB::Green;
    }
  }
  if(startPosition == 4)
  {
    if( random8() < chanceOfGlitter) 
    {
    fourthZone[ random16(FOURTHZONE_LEDS) ] += CRGB::Blue;
    }
  }
  if(startPosition == 5)
  {
    if( random8() < chanceOfGlitter) 
    {
    fourthZone[ random16(FOURTHZONE_LEDS) ] += CRGB::Violet;
    }
  } 
}

void SingleRace_fourthZone()
{
  fadeToBlackBy( fourthZone, FOURTHZONE_LEDS, 1);
  int pos = beatsin16( raceSpeed, 0, 474);
  if(pos > previousLED_fourthZone)
  {
    fourthZone[pos] = CRGB(red1,green1,blue1);
    previousLED_fourthZone = pos;
  }
  if(pos < previousLED_fourthZone)
  {
    fourthZone[pos] = CRGB(red2,green2,blue2);
    previousLED_fourthZone = pos;
  }                 
}

  void Crash_fourthZone()
{
  fadeToBlackBy( fourthZone, FOURTHZONE_LEDS, 15);
  #ifdef ZONEFOUR_SECTION1_START
  int pos_SECTION1 = beatsin16( raceSpeed, 0, (ZONEFOUR_SECTION1_END - ZONEFOUR_SECTION1_START) );
  fourthZone[ZONEFOUR_SECTION1_START + pos_SECTION1] = CRGB(red1,green1,blue1);
  fourthZone[ZONEFOUR_SECTION1_END - pos_SECTION1] = CRGB(red2,green2,blue2);
  #endif

  #ifdef ZONEFOUR_SECTION2_START
  int pos_SECTION2 = beatsin16( raceSpeed, 0, (ZONEFOUR_SECTION2_END - ZONEFOUR_SECTION2_START) );
  fourthZone[ZONEFOUR_SECTION2_START + pos_SECTION2] = CRGB(red2,green2,blue2);
  fourthZone[ZONEFOUR_SECTION2_END - pos_SECTION2] = CRGB(red1,green1,blue1);
  #endif
  
  #ifdef ZONEFOUR_SECTION3_START
  int pos_SECTION3 = beatsin16( raceSpeed, 0, (ZONEFOUR_SECTION3_END - ZONEFOUR_SECTION3_START) );
  fourthZone[ZONEFOUR_SECTION3_START + pos_SECTION3] = CRGB(red1,green1,blue1);
  fourthZone[ZONEFOUR_SECTION3_END - pos_SECTION3] = CRGB(red2,green2,blue2);
  #endif
  
  #ifdef ZONEFOUR_SECTION4_START
  int pos_SECTION4 = beatsin16( raceSpeed, 0, (ZONEFOUR_SECTION4_END - ZONEFOUR_SECTION4_START) );
  fourthZone[ZONEFOUR_SECTION4_START + pos_SECTION4] = CRGB(red2,green2,blue2);
  fourthZone[ZONEFOUR_SECTION4_END - pos_SECTION4] = CRGB(red1,green1,blue1);
  #endif
  
  #ifdef ZONEFOUR_SECTION5_START
  int pos_SECTION5 = beatsin16( raceSpeed, 0, (ZONEFOUR_SECTION5_END - ZONEFOUR_SECTION5_START) );
  fourthZone[ZONEFOUR_SECTION5_START + pos_SECTION5] = CRGB(red1,green1,blue1);
  fourthZone[ZONEFOUR_SECTION5_END - pos_SECTION5] = CRGB(red2,green2,blue2);
  #endif
  
  #ifdef ZONEFOUR_SECTION6_START
  int pos_SECTION6 = beatsin16( raceSpeed, 0, (ZONEFOUR_SECTION6_END - ZONEFOUR_SECTION6_START) );
  fourthZone[ZONEFOUR_SECTION6_START + pos_SECTION6] = CRGB(red2,green2,blue2);
  fourthZone[ZONEFOUR_SECTION6_END - pos_SECTION6] = CRGB(red1,green1,blue1);
  #endif
  
  #ifdef ZONEFOUR_SECTION7_START
  int pos_SECTION7 = beatsin16( raceSpeed, 0, (ZONEFOUR_SECTION7_END - ZONEFOUR_SECTION7_START) );
  fourthZone[ZONEFOUR_SECTION7_START + pos_SECTION7] = CRGB(red1,green1,blue1);
  fourthZone[ZONEFOUR_SECTION7_END - pos_SECTION7] = CRGB(red2,green2,blue2);
  #endif
  
  #ifdef ZONEFOUR_SECTION8_START
  int pos_SECTION8 = beatsin16( raceSpeed, 0, (ZONEFOUR_SECTION8_END - ZONEFOUR_SECTION8_START) );
  fourthZone[ZONEFOUR_SECTION8_START + pos_SECTION8] = CRGB(red2,green2,blue2);
  fourthZone[ZONEFOUR_SECTION8_END - pos_SECTION8] = CRGB(red1,green1,blue1);
  #endif
  
  #ifdef ZONEFOUR_SECTION9_START
  int pos_SECTION9 = beatsin16( raceSpeed, 0, (ZONEFOUR_SECTION9_END - ZONEFOUR_SECTION9_START) );
  fourthZone[ZONEFOUR_SECTION9_START + pos_SECTION9] = CRGB(red1,green1,blue1);
  fourthZone[ZONEFOUR_SECTION9_END - pos_SECTION9] = CRGB(red2,green2,blue2);
  #endif
  
}

void Rainbow_fourthZone()
{
  fill_rainbow( fourthZone, FOURTHZONE_LEDS, gHue, numberOfRainbows);
}

void Blocked_fourthZone()
{
  fadeToBlackBy( fourthZone, FOURTHZONE_LEDS, 2);
  for( int mark = 0; mark < FOURTHZONE_LEDS; mark+=30)
  {
    for( int i = 0; i < 9; i++) 
    {
      if(startPosition == 0 || startPosition == 1)
      {
        if(i+mark <= FOURTHZONE_LEDS)
        {
          fourthZone[i+mark] = CRGB(red1,green1,blue1);
        }
        if(i+10+mark <= FOURTHZONE_LEDS)
        {
          fourthZone[i+10+mark] = CRGB(red2,green2,blue2);
        }
        if(i+20+mark <= FOURTHZONE_LEDS)
        {
          fourthZone[i+20+mark] = CRGB(red3,green3,blue3);
        }
      }
      if(startPosition == 2 || startPosition == 3)
      {
        if(i+mark <= FOURTHZONE_LEDS)
        {
          fourthZone[i+mark] = CRGB(red2,green2,blue2);
        }
        if(i+10+mark <= FOURTHZONE_LEDS)
        {
          fourthZone[i+10+mark] = CRGB(red3,green3,blue3);
        }
        if(i+20+mark <= FOURTHZONE_LEDS)
        {
          fourthZone[i+20+mark] = CRGB(red1,green1,blue1);
        }
      }
      if(startPosition == 4 || startPosition == 5)
      {
        if(i+mark <= FOURTHZONE_LEDS)
        {
          fourthZone[i+mark] = CRGB(red3,green3,blue3);
        }
        if(i+10+mark <= FOURTHZONE_LEDS)
        {
          fourthZone[i+10+mark] = CRGB(red1,green1,blue1);
        }
        if(i+20+mark <= FOURTHZONE_LEDS)
        {
          fourthZone[i+20+mark] = CRGB(red2,green2,blue2);
        }
      }
    }
  }
}

void BPM_fourthZone()
{
  if((red1*2) > (green1 + blue1))
  {
    CRGBPalette16 palette_fourthZone = LavaColors_p; 
    uint8_t beat = beatsin16( BeatsPerMinute, 64, 255);
    for( int i = 0; i < FOURTHZONE_LEDS; i++) 
    {
      fourthZone[i] = ColorFromPalette(palette_fourthZone, gHue+(i*2), beat-gHue+(i*10));
    } 
  }
  if((green1*2) > (red1 + blue1))
  {
    CRGBPalette16 palette_fourthZone = ForestColors_p; 
    uint8_t beat = beatsin16( BeatsPerMinute, 64, 255);
    for( int i = 0; i < FOURTHZONE_LEDS; i++) 
    {
      fourthZone[i] = ColorFromPalette(palette_fourthZone, gHue+(i*2), beat-gHue+(i*10));
    } 
  }
  if((blue1*2) > (green1 + red1))
  {
    CRGBPalette16 palette_fourthZone = CloudColors_p; 
    uint8_t beat = beatsin16( BeatsPerMinute, 64, 255);
    for( int i = 0; i < FOURTHZONE_LEDS; i++) 
    {
      fourthZone[i] = ColorFromPalette(palette_fourthZone, gHue+(i*2), beat-gHue+(i*10));
    } 
  }
  if((blue1*2) == (green1 + red1))
  {
    CRGBPalette16 palette_fourthZone = PartyColors_p; 
    uint8_t beat = beatsin16( BeatsPerMinute, 64, 255);
    for( int i = 0; i < FOURTHZONE_LEDS; i++) 
    {
      fourthZone[i] = ColorFromPalette(palette_fourthZone, gHue+(i*2), beat-gHue+(i*10));
    } 
  }
}

void Twinkle_fourthZone()
{
  fadeToBlackBy( fourthZone, FOURTHZONE_LEDS, 80);
  for( int i = 0; i < FOURTHZONE_LEDS-5; i+=5)
  {
    if(i <= FOURTHZONE_LEDS)
    {
      if (random8() > twinkleChance)
      {
        fourthZone[i] = CRGB( red1, green1, blue1);
      }
      else
      {
        fourthZone[i] = CRGB( 150, 100, 40);
      }  
    }
  }                     
}

void Eyes_fourthZone()
{
  unsigned int chance = random8();
  if( chance > eyeChance) 
  {
    unsigned int eye = random16(FOURTHZONE_LEDS);  
    fourthZone[eye] = CRGB(red1,green1,blue1);
    fourthZone[eye-4] = CRGB(red1,green1,blue1);
  }
  if( chance > 39) 
  {
    fadeToBlackBy( fourthZone, FOURTHZONE_LEDS, 10);
  }
}

void Solid_fourthZone()
{
  fill_solid(fourthZone, FOURTHZONE_LEDS, CRGB(red1, green1, blue1));
}

void Locator_fourthZone()
{
  if(locatorLED <= FOURTHZONE_LEDS)
  {
    fill_solid(fourthZone, FOURTHZONE_LEDS, CRGB::Black); 
    fourthZone[locatorLED]=CRGB(red1, green1, blue1);
  }
}

#ifdef ZONEFOUR_SECTION1_START
void fire_fourthZone_SECTION1()
{
  static byte heat[ZONEFOUR_SECTION1_END - ZONEFOUR_SECTION1_START];
  for( int i = 0; i < ZONEFOUR_SECTION1_END - ZONEFOUR_SECTION1_START; i++) 
  {
    heat[i] = qsub8( heat[i],  random8(0, ((COOLING * 10) / ZONEFOUR_SECTION1_END - ZONEFOUR_SECTION1_START) + 2));
  }

  for( int k= ZONEFOUR_SECTION1_END - ZONEFOUR_SECTION1_START - 1; k >= 2; k--) 
  {
    heat[k] = (heat[k - 1] + heat[k - 2] + heat[k - 2] ) / 3;
  }
  if( random8() < SPARKING ) 
  {
    int y = random8(7);
    heat[y] = qadd8( heat[y], random8(160,255) );
  }
  for( int j = 0; j < ZONEFOUR_SECTION1_END - ZONEFOUR_SECTION1_START; j++) 
  {
    byte colorindex = scale8( heat[j], 240);
    CRGB color = ColorFromPalette( gPal, colorindex);
    int pixelnumber;
    if( gReverseDirection ) {
      pixelnumber = (ZONEFOUR_SECTION1_END - ZONEFOUR_SECTION1_START -1) - j;
    } else {
      pixelnumber = j;
    }
    int thisFlame = ((pixelnumber * firesize)/100);
    if(thisFlame <=  ZONEFOUR_SECTION1_START && thisFlame <= ZONEFOUR_SECTION1_END)
    
    #if ZONEFOUR_SECTION1_START_FIRE == 1
    {
      fourthZone[ZONEFOUR_SECTION1_START + thisFlame] = color;
    }
    #endif
    
    #if ZONEFOUR_SECTION1_END_FIRE == 1
    {
      fourthZone[ZONEFOUR_SECTION1_END - thisFlame] = color;
    }
    #endif
  }
}
#endif

#ifdef ZONEFOUR_SECTION2_START
void fire_fourthZone_SECTION2()
{
  static byte heat[ZONEFOUR_SECTION2_END - ZONEFOUR_SECTION2_START];
  for( int i = 0; i < ZONEFOUR_SECTION2_END - ZONEFOUR_SECTION2_START; i++) 
  {
    heat[i] = qsub8( heat[i],  random8(0, ((COOLING * 10) / ZONEFOUR_SECTION2_END - ZONEFOUR_SECTION2_START) + 2));
  }

  for( int k= ZONEFOUR_SECTION2_END - ZONEFOUR_SECTION2_START - 1; k >= 2; k--) 
  {
    heat[k] = (heat[k - 1] + heat[k - 2] + heat[k - 2] ) / 3;
  }
  if( random8() < SPARKING ) 
  {
    int y = random8(7);
    heat[y] = qadd8( heat[y], random8(160,255) );
  }
  for( int j = 0; j < ZONEFOUR_SECTION2_END - ZONEFOUR_SECTION2_START; j++) 
  {
    byte colorindex = scale8( heat[j], 240);
    CRGB color = ColorFromPalette( gPal, colorindex);
    int pixelnumber;
    if( gReverseDirection ) {
      pixelnumber = (ZONEFOUR_SECTION2_END - ZONEFOUR_SECTION2_START -1) - j;
    } else {
      pixelnumber = j;
    }
    int thisFlame = ((pixelnumber * firesize)/100);
    if(thisFlame <=  ZONEFOUR_SECTION2_START && thisFlame <= ZONEFOUR_SECTION2_END)
    
    #if ZONEFOUR_SECTION2_START_FIRE == 1
    {
      fourthZone[ZONEFOUR_SECTION2_START + thisFlame] = color;
    }
    #endif
    
    #if ZONEFOUR_SECTION2_END_FIRE == 1
    {
      fourthZone[ZONEFOUR_SECTION2_END - thisFlame] = color;
    }
    #endif
  }
}
#endif

#ifdef ZONEFOUR_SECTION3_START
void fire_fourthZone_SECTION3()
{
  static byte heat[ZONEFOUR_SECTION3_END - ZONEFOUR_SECTION3_START];
  for( int i = 0; i < ZONEFOUR_SECTION3_END - ZONEFOUR_SECTION3_START; i++) 
  {
    heat[i] = qsub8( heat[i],  random8(0, ((COOLING * 10) / ZONEFOUR_SECTION3_END - ZONEFOUR_SECTION3_START) + 2));
  }

  for( int k= ZONEFOUR_SECTION3_END - ZONEFOUR_SECTION3_START - 1; k >= 2; k--) 
  {
    heat[k] = (heat[k - 1] + heat[k - 2] + heat[k - 2] ) / 3;
  }
  if( random8() < SPARKING ) 
  {
    int y = random8(7);
    heat[y] = qadd8( heat[y], random8(160,255) );
  }
  for( int j = 0; j < ZONEFOUR_SECTION3_END - ZONEFOUR_SECTION3_START; j++) 
  {
    byte colorindex = scale8( heat[j], 240);
    CRGB color = ColorFromPalette( gPal, colorindex);
    int pixelnumber;
    if( gReverseDirection ) {
      pixelnumber = (ZONEFOUR_SECTION3_END - ZONEFOUR_SECTION3_START -1) - j;
    } else {
      pixelnumber = j;
    }
    int thisFlame = ((pixelnumber * firesize)/100);
    if(thisFlame <=  ZONEFOUR_SECTION3_START && thisFlame <= ZONEFOUR_SECTION3_END)
    
    #if ZONEFOUR_SECTION3_START_FIRE == 1
    {
      fourthZone[ZONEFOUR_SECTION3_START + thisFlame] = color;
    }
    #endif
    
    #if ZONEFOUR_SECTION3_END_FIRE == 1
    {
      fourthZone[ZONEFOUR_SECTION3_END - thisFlame] = color;
    }
    #endif
  }
}
#endif

#ifdef ZONEFOUR_SECTION4_START
void fire_fourthZone_SECTION4()
{
  static byte heat[ZONEFOUR_SECTION4_END - ZONEFOUR_SECTION4_START];
  for( int i = 0; i < ZONEFOUR_SECTION4_END - ZONEFOUR_SECTION4_START; i++) 
  {
    heat[i] = qsub8( heat[i],  random8(0, ((COOLING * 10) / ZONEFOUR_SECTION4_END - ZONEFOUR_SECTION4_START) + 2));
  }

  for( int k= ZONEFOUR_SECTION4_END - ZONEFOUR_SECTION4_START - 1; k >= 2; k--) 
  {
    heat[k] = (heat[k - 1] + heat[k - 2] + heat[k - 2] ) / 3;
  }
  if( random8() < SPARKING ) 
  {
    int y = random8(7);
    heat[y] = qadd8( heat[y], random8(160,255) );
  }
  for( int j = 0; j < ZONEFOUR_SECTION4_END - ZONEFOUR_SECTION4_START; j++) 
  {
    byte colorindex = scale8( heat[j], 240);
    CRGB color = ColorFromPalette( gPal, colorindex);
    int pixelnumber;
    if( gReverseDirection ) {
      pixelnumber = (ZONEFOUR_SECTION4_END - ZONEFOUR_SECTION4_START -1) - j;
    } else {
      pixelnumber = j;
    }
    int thisFlame = ((pixelnumber * firesize)/100);
    if(thisFlame <=  ZONEFOUR_SECTION4_START && thisFlame <= ZONEFOUR_SECTION4_END)
    
    #if ZONEFOUR_SECTION4_START_FIRE == 1
    {
      fourthZone[ZONEFOUR_SECTION4_START + thisFlame] = color;
    }
    #endif
    
    #if ZONEFOUR_SECTION4_END_FIRE == 1
    {
      fourthZone[ZONEFOUR_SECTION4_END - thisFlame] = color;
    }
    #endif
  }
}
#endif

#ifdef ZONEFOUR_SECTION5_START
void fire_fourthZone_SECTION5()
{
  static byte heat[ZONEFOUR_SECTION5_END - ZONEFOUR_SECTION5_START];
  for( int i = 0; i < ZONEFOUR_SECTION5_END - ZONEFOUR_SECTION5_START; i++) 
  {
    heat[i] = qsub8( heat[i],  random8(0, ((COOLING * 10) / ZONEFOUR_SECTION5_END - ZONEFOUR_SECTION5_START) + 2));
  }

  for( int k= ZONEFOUR_SECTION5_END - ZONEFOUR_SECTION5_START - 1; k >= 2; k--) 
  {
    heat[k] = (heat[k - 1] + heat[k - 2] + heat[k - 2] ) / 3;
  }
  if( random8() < SPARKING ) 
  {
    int y = random8(7);
    heat[y] = qadd8( heat[y], random8(160,255) );
  }
  for( int j = 0; j < ZONEFOUR_SECTION5_END - ZONEFOUR_SECTION5_START; j++) 
  {
    byte colorindex = scale8( heat[j], 240);
    CRGB color = ColorFromPalette( gPal, colorindex);
    int pixelnumber;
    if( gReverseDirection ) {
      pixelnumber = (ZONEFOUR_SECTION5_END - ZONEFOUR_SECTION5_START -1) - j;
    } else {
      pixelnumber = j;
    }
    int thisFlame = ((pixelnumber * firesize)/100);
    if(thisFlame <=  ZONEFOUR_SECTION5_START && thisFlame <= ZONEFOUR_SECTION5_END)
    
    #if ZONEFOUR_SECTION5_START_FIRE == 1
    {
      fourthZone[ZONEFOUR_SECTION5_START + thisFlame] = color;
    }
    #endif
    
    #if ZONEFOUR_SECTION5_END_FIRE == 1
    {
      fourthZone[ZONEFOUR_SECTION5_END - thisFlame] = color;
    }
    #endif
  }
}
#endif

#ifdef ZONEFOUR_SECTION6_START
void fire_fourthZone_SECTION6()
{
  static byte heat[ZONEFOUR_SECTION6_END - ZONEFOUR_SECTION6_START];
  for( int i = 0; i < ZONEFOUR_SECTION6_END - ZONEFOUR_SECTION6_START; i++) 
  {
    heat[i] = qsub8( heat[i],  random8(0, ((COOLING * 10) / ZONEFOUR_SECTION6_END - ZONEFOUR_SECTION6_START) + 2));
  }

  for( int k= ZONEFOUR_SECTION6_END - ZONEFOUR_SECTION6_START - 1; k >= 2; k--) 
  {
    heat[k] = (heat[k - 1] + heat[k - 2] + heat[k - 2] ) / 3;
  }
  if( random8() < SPARKING ) 
  {
    int y = random8(7);
    heat[y] = qadd8( heat[y], random8(160,255) );
  }
  for( int j = 0; j < ZONEFOUR_SECTION6_END - ZONEFOUR_SECTION6_START; j++) 
  {
    byte colorindex = scale8( heat[j], 240);
    CRGB color = ColorFromPalette( gPal, colorindex);
    int pixelnumber;
    if( gReverseDirection ) {
      pixelnumber = (ZONEFOUR_SECTION6_END - ZONEFOUR_SECTION6_START -1) - j;
    } else {
      pixelnumber = j;
    }
    int thisFlame = ((pixelnumber * firesize)/100);
    if(thisFlame <=  ZONEFOUR_SECTION6_START && thisFlame <= ZONEFOUR_SECTION6_END)
    
    #if ZONEFOUR_SECTION6_START_FIRE == 1
    {
      fourthZone[ZONEFOUR_SECTION6_START + thisFlame] = color;
    }
    #endif
    
    #if ZONEFOUR_SECTION6_END_FIRE == 1
    {
      fourthZone[ZONEFOUR_SECTION6_END - thisFlame] = color;
    }
    #endif
  }
}
#endif

#ifdef ZONEFOUR_SECTION7_START
void fire_fourthZone_SECTION7()
{
  static byte heat[ZONEFOUR_SECTION7_END - ZONEFOUR_SECTION7_START];
  for( int i = 0; i < ZONEFOUR_SECTION7_END - ZONEFOUR_SECTION7_START; i++) 
  {
    heat[i] = qsub8( heat[i],  random8(0, ((COOLING * 10) / ZONEFOUR_SECTION7_END - ZONEFOUR_SECTION7_START) + 2));
  }

  for( int k= ZONEFOUR_SECTION7_END - ZONEFOUR_SECTION7_START - 1; k >= 2; k--) 
  {
    heat[k] = (heat[k - 1] + heat[k - 2] + heat[k - 2] ) / 3;
  }
  if( random8() < SPARKING ) 
  {
    int y = random8(7);
    heat[y] = qadd8( heat[y], random8(160,255) );
  }
  for( int j = 0; j < ZONEFOUR_SECTION7_END - ZONEFOUR_SECTION7_START; j++) 
  {
    byte colorindex = scale8( heat[j], 240);
    CRGB color = ColorFromPalette( gPal, colorindex);
    int pixelnumber;
    if( gReverseDirection ) {
      pixelnumber = (ZONEFOUR_SECTION7_END - ZONEFOUR_SECTION7_START -1) - j;
    } else {
      pixelnumber = j;
    }
    int thisFlame = ((pixelnumber * firesize)/100);
    if(thisFlame <=  ZONEFOUR_SECTION7_START && thisFlame <= ZONEFOUR_SECTION7_END)
    
    #if ZONEFOUR_SECTION7_START_FIRE == 1
    {
      fourthZone[ZONEFOUR_SECTION7_START + thisFlame] = color;
    }
    #endif
    
    #if ZONEFOUR_SECTION7_END_FIRE == 1
    {
      fourthZone[ZONEFOUR_SECTION7_END - thisFlame] = color;
    }
    #endif
  }
}
#endif

#ifdef ZONEFOUR_SECTION8_START
void fire_fourthZone_SECTION8()
{
  static byte heat[ZONEFOUR_SECTION8_END - ZONEFOUR_SECTION8_START];
  for( int i = 0; i < ZONEFOUR_SECTION8_END - ZONEFOUR_SECTION8_START; i++) 
  {
    heat[i] = qsub8( heat[i],  random8(0, ((COOLING * 10) / ZONEFOUR_SECTION8_END - ZONEFOUR_SECTION8_START) + 2));
  }

  for( int k= ZONEFOUR_SECTION8_END - ZONEFOUR_SECTION8_START - 1; k >= 2; k--) 
  {
    heat[k] = (heat[k - 1] + heat[k - 2] + heat[k - 2] ) / 3;
  }
  if( random8() < SPARKING ) 
  {
    int y = random8(7);
    heat[y] = qadd8( heat[y], random8(160,255) );
  }
  for( int j = 0; j < ZONEFOUR_SECTION8_END - ZONEFOUR_SECTION8_START; j++) 
  {
    byte colorindex = scale8( heat[j], 240);
    CRGB color = ColorFromPalette( gPal, colorindex);
    int pixelnumber;
    if( gReverseDirection ) {
      pixelnumber = (ZONEFOUR_SECTION8_END - ZONEFOUR_SECTION8_START -1) - j;
    } else {
      pixelnumber = j;
    }
    int thisFlame = ((pixelnumber * firesize)/100);
    if(thisFlame <=  ZONEFOUR_SECTION8_START && thisFlame <= ZONEFOUR_SECTION8_END)
    
    #if ZONEFOUR_SECTION8_START_FIRE == 1
    {
      fourthZone[ZONEFOUR_SECTION8_START + thisFlame] = color;
    }
    #endif
    
    #if ZONEFOUR_SECTION8_END_FIRE == 1
    {
      fourthZone[ZONEFOUR_SECTION8_END - thisFlame] = color;
    }
    #endif
  }
}
#endif

#ifdef ZONEFOUR_SECTION9_START
void fire_fourthZone_SECTION9()
{
  static byte heat[ZONEFOUR_SECTION9_END - ZONEFOUR_SECTION9_START];
  for( int i = 0; i < ZONEFOUR_SECTION9_END - ZONEFOUR_SECTION9_START; i++) 
  {
    heat[i] = qsub8( heat[i],  random8(0, ((COOLING * 10) / ZONEFOUR_SECTION9_END - ZONEFOUR_SECTION9_START) + 2));
  }

  for( int k= ZONEFOUR_SECTION9_END - ZONEFOUR_SECTION9_START - 1; k >= 2; k--) 
  {
    heat[k] = (heat[k - 1] + heat[k - 2] + heat[k - 2] ) / 3;
  }
  if( random8() < SPARKING ) 
  {
    int y = random8(7);
    heat[y] = qadd8( heat[y], random8(160,255) );
  }
  for( int j = 0; j < ZONEFOUR_SECTION9_END - ZONEFOUR_SECTION9_START; j++) 
  {
    byte colorindex = scale8( heat[j], 240);
    CRGB color = ColorFromPalette( gPal, colorindex);
    int pixelnumber;
    if( gReverseDirection ) {
      pixelnumber = (ZONEFOUR_SECTION9_END - ZONEFOUR_SECTION9_START -1) - j;
    } else {
      pixelnumber = j;
    }
    int thisFlame = ((pixelnumber * firesize)/100);
    if(thisFlame <=  ZONEFOUR_SECTION9_START && thisFlame <= ZONEFOUR_SECTION9_END)
    
    #if ZONEFOUR_SECTION9_START_FIRE == 1
    {
      fourthZone[ZONEFOUR_SECTION9_START + thisFlame] = color;
    }
    #endif
    
    #if ZONEFOUR_SECTION9_END_FIRE == 1
    {
      fourthZone[ZONEFOUR_SECTION9_END - thisFlame] = color;
    }
    #endif
  }
}
#endif

#endif

/*****************  fifthZone Animations  ****************************************/
/*****************  fifthZone Animations  ****************************************/
/*****************  fifthZone Animations  ****************************************/
/*****************  fifthZone Animations  ****************************************/
/*****************  fifthZone Animations  ****************************************/

#if ZONEFIVE == 1

void Ripple_fifthZone()
{
  for (int i = 0; i < FIFTHZONE_LEDS; i++)
  {
    fifthZone[i] = CRGB((red2/75), (green2/75), (blue2/75));
  }   
  switch (step_fifthZone) 
  {
    case -1:                                                          
      center_fifthZone = random16(FIFTHZONE_LEDS);
      step_fifthZone = 0;
      break;
    case 0:
      fifthZone[center_fifthZone] = CRGB(red1, green1, blue1);                          
      step_fifthZone ++;
      break;
    case 12:                                                   
      step_fifthZone = -1;
      break;
    default:                                                             // Middle of the ripples.
      fifthZone[(center_fifthZone + step_fifthZone + FIFTHZONE_LEDS) % FIFTHZONE_LEDS] += CRGB((red1/(step_fifthZone * 5)), (green1/(step_fifthZone * 5)), (blue1/(step_fifthZone * 5)));
      fifthZone[(center_fifthZone - step_fifthZone + FIFTHZONE_LEDS) % FIFTHZONE_LEDS] += CRGB((red1/(step_fifthZone * 5)), (green1/(step_fifthZone * 5)), (blue1/(step_fifthZone * 5)));
      step_fifthZone ++;                                                         
      break;
  }
}

void RGB_fifthZone()
{
  if(startPosition < 6)
  {
    fadeToBlackBy( fifthZone, FIFTHZONE_LEDS, 80);
    for(int pixel = startPosition+1; pixel < FIFTHZONE_LEDS; pixel+=6)  
    {
      if(pixel <= FIFTHZONE_LEDS)
      {
        fifthZone[pixel] = CRGB(red1,green1,blue1);
      }
    }
    for(int pixel = startPosition+3; pixel < FIFTHZONE_LEDS; pixel+=6)
    {
      if(pixel <= FIFTHZONE_LEDS)
      {
        fifthZone[pixel] = CRGB(red2,green2,blue2);
      }
    }
    for(int pixel = startPosition+5; pixel < FIFTHZONE_LEDS; pixel+=6)
    {
      if(pixel <= FIFTHZONE_LEDS)
      {
        fifthZone[pixel] = CRGB(red3,green3,blue3);
      } 
    }
  }
  if(startPosition == 1)
  {
    fifthZone[0]=CRGB(red3,green3,blue3);
  }
  if(startPosition == 2)
  {
    fifthZone[1]=CRGB(red3,green3,blue3);
  }
  if(startPosition == 3)
  {
    fifthZone[2]=CRGB(red3,green3,blue3);
    fifthZone[0]=CRGB(red2,green2,blue2);
  }
  if(startPosition == 4)
  {
    fifthZone[3]=CRGB(red3,green3,blue3);
    fifthZone[1]=CRGB(red2,green2,blue2);
  }
  if(startPosition == 5)
  {
    fifthZone[4]=CRGB(red3,green3,blue3);
    fifthZone[2]=CRGB(red2,green2,blue2);
    fifthZone[0]=CRGB(red1,green1,blue1);
  }
}

void ColorGlitter_fifthZone( fract8 chanceOfGlitter) 
{
  fadeToBlackBy( fifthZone, FIFTHZONE_LEDS, 2);
  if(startPosition == 0)
  {
    if( random8() < chanceOfGlitter) 
    {
    fifthZone[ random16(FIFTHZONE_LEDS) ] += CRGB::Red;
    }
  }
  if(startPosition == 1)
  {
    if( random8() < chanceOfGlitter) 
    {
    fifthZone[ random16(FIFTHZONE_LEDS) ] += CRGB::Orange;
    }
  }
  if(startPosition == 2)
  {
    if( random8() < chanceOfGlitter) 
    {
    fifthZone[ random16(FIFTHZONE_LEDS) ] += CRGB::Yellow;
    }  
  }
  if(startPosition == 3)
  {
    if( random8() < chanceOfGlitter) 
    {
    fifthZone[ random16(FIFTHZONE_LEDS) ] += CRGB::Green;
    }
  }
  if(startPosition == 4)
  {
    if( random8() < chanceOfGlitter) 
    {
    fifthZone[ random16(FIFTHZONE_LEDS) ] += CRGB::Blue;
    }
  }
  if(startPosition == 5)
  {
    if( random8() < chanceOfGlitter) 
    {
    fifthZone[ random16(FIFTHZONE_LEDS) ] += CRGB::Violet;
    }
  } 
}

void SingleRace_fifthZone()
{
  fadeToBlackBy( fifthZone, FIFTHZONE_LEDS, 1);
  int pos = beatsin16( raceSpeed, 0, 474);
  if(pos > previousLED_fifthZone)
  {
    fifthZone[pos] = CRGB(red1,green1,blue1);
    previousLED_fifthZone = pos;
  }
  if(pos < previousLED_fifthZone)
  {
    fifthZone[pos] = CRGB(red2,green2,blue2);
    previousLED_fifthZone = pos;
  }                 
}

  void Crash_fifthZone()
{
  fadeToBlackBy( fifthZone, FIFTHZONE_LEDS, 15);
  #ifdef ZONEFIVE_SECTION1_START
  int pos_SECTION1 = beatsin16( raceSpeed, 0, (ZONEFIVE_SECTION1_END - ZONEFIVE_SECTION1_START) );
  fifthZone[ZONEFIVE_SECTION1_START + pos_SECTION1] = CRGB(red1,green1,blue1);
  fifthZone[ZONEFIVE_SECTION1_END - pos_SECTION1] = CRGB(red2,green2,blue2);
  #endif

  #ifdef ZONEFIVE_SECTION2_START
  int pos_SECTION2 = beatsin16( raceSpeed, 0, (ZONEFIVE_SECTION2_END - ZONEFIVE_SECTION2_START) );
  fifthZone[ZONEFIVE_SECTION2_START + pos_SECTION2] = CRGB(red2,green2,blue2);
  fifthZone[ZONEFIVE_SECTION2_END - pos_SECTION2] = CRGB(red1,green1,blue1);
  #endif
  
  #ifdef ZONEFIVE_SECTION3_START
  int pos_SECTION3 = beatsin16( raceSpeed, 0, (ZONEFIVE_SECTION3_END - ZONEFIVE_SECTION3_START) );
  fifthZone[ZONEFIVE_SECTION3_START + pos_SECTION3] = CRGB(red1,green1,blue1);
  fifthZone[ZONEFIVE_SECTION3_END - pos_SECTION3] = CRGB(red2,green2,blue2);
  #endif
  
  #ifdef ZONEFIVE_SECTION4_START
  int pos_SECTION4 = beatsin16( raceSpeed, 0, (ZONEFIVE_SECTION4_END - ZONEFIVE_SECTION4_START) );
  fifthZone[ZONEFIVE_SECTION4_START + pos_SECTION4] = CRGB(red2,green2,blue2);
  fifthZone[ZONEFIVE_SECTION4_END - pos_SECTION4] = CRGB(red1,green1,blue1);
  #endif
  
  #ifdef ZONEFIVE_SECTION5_START
  int pos_SECTION5 = beatsin16( raceSpeed, 0, (ZONEFIVE_SECTION5_END - ZONEFIVE_SECTION5_START) );
  fifthZone[ZONEFIVE_SECTION5_START + pos_SECTION5] = CRGB(red1,green1,blue1);
  fifthZone[ZONEFIVE_SECTION5_END - pos_SECTION5] = CRGB(red2,green2,blue2);
  #endif
  
  #ifdef ZONEFIVE_SECTION6_START
  int pos_SECTION6 = beatsin16( raceSpeed, 0, (ZONEFIVE_SECTION6_END - ZONEFIVE_SECTION6_START) );
  fifthZone[ZONEFIVE_SECTION6_START + pos_SECTION6] = CRGB(red2,green2,blue2);
  fifthZone[ZONEFIVE_SECTION6_END - pos_SECTION6] = CRGB(red1,green1,blue1);
  #endif
  
  #ifdef ZONEFIVE_SECTION7_START
  int pos_SECTION7 = beatsin16( raceSpeed, 0, (ZONEFIVE_SECTION7_END - ZONEFIVE_SECTION7_START) );
  fifthZone[ZONEFIVE_SECTION7_START + pos_SECTION7] = CRGB(red1,green1,blue1);
  fifthZone[ZONEFIVE_SECTION7_END - pos_SECTION7] = CRGB(red2,green2,blue2);
  #endif
  
  #ifdef ZONEFIVE_SECTION8_START
  int pos_SECTION8 = beatsin16( raceSpeed, 0, (ZONEFIVE_SECTION8_END - ZONEFIVE_SECTION8_START) );
  fifthZone[ZONEFIVE_SECTION8_START + pos_SECTION8] = CRGB(red2,green2,blue2);
  fifthZone[ZONEFIVE_SECTION8_END - pos_SECTION8] = CRGB(red1,green1,blue1);
  #endif
  
  #ifdef ZONEFIVE_SECTION9_START
  int pos_SECTION9 = beatsin16( raceSpeed, 0, (ZONEFIVE_SECTION9_END - ZONEFIVE_SECTION9_START) );
  fifthZone[ZONEFIVE_SECTION9_START + pos_SECTION9] = CRGB(red1,green1,blue1);
  fifthZone[ZONEFIVE_SECTION9_END - pos_SECTION9] = CRGB(red2,green2,blue2);
  #endif
  
}

void Rainbow_fifthZone()
{
  fill_rainbow( fifthZone, FIFTHZONE_LEDS, gHue, numberOfRainbows);
}

void Blocked_fifthZone()
{
  fadeToBlackBy( fifthZone, FIFTHZONE_LEDS, 2);
  for( int mark = 0; mark < FIFTHZONE_LEDS; mark+=30)
  {
    for( int i = 0; i < 9; i++) 
    {
      if(startPosition == 0 || startPosition == 1)
      {
        if(i+mark <= FIFTHZONE_LEDS)
        {
          fifthZone[i+mark] = CRGB(red1,green1,blue1);
        }
        if(i+10+mark <= FIFTHZONE_LEDS)
        {
          fifthZone[i+10+mark] = CRGB(red2,green2,blue2);
        }
        if(i+20+mark <= FIFTHZONE_LEDS)
        {
          fifthZone[i+20+mark] = CRGB(red3,green3,blue3);
        }
      }
      if(startPosition == 2 || startPosition == 3)
      {
        if(i+mark <= FIFTHZONE_LEDS)
        {
          fifthZone[i+mark] = CRGB(red2,green2,blue2);
        }
        if(i+10+mark <= FIFTHZONE_LEDS)
        {
          fifthZone[i+10+mark] = CRGB(red3,green3,blue3);
        }
        if(i+20+mark <= FIFTHZONE_LEDS)
        {
          fifthZone[i+20+mark] = CRGB(red1,green1,blue1);
        }
      }
      if(startPosition == 4 || startPosition == 5)
      {
        if(i+mark <= FIFTHZONE_LEDS)
        {
          fifthZone[i+mark] = CRGB(red3,green3,blue3);
        }
        if(i+10+mark <= FIFTHZONE_LEDS)
        {
          fifthZone[i+10+mark] = CRGB(red1,green1,blue1);
        }
        if(i+20+mark <= FIFTHZONE_LEDS)
        {
          fifthZone[i+20+mark] = CRGB(red2,green2,blue2);
        }
      }
    }
  }
}

void BPM_fifthZone()
{
  if((red1*2) > (green1 + blue1))
  {
    CRGBPalette16 palette_fifthZone = LavaColors_p; 
    uint8_t beat = beatsin16( BeatsPerMinute, 64, 255);
    for( int i = 0; i < FIFTHZONE_LEDS; i++) 
    {
      fifthZone[i] = ColorFromPalette(palette_fifthZone, gHue+(i*2), beat-gHue+(i*10));
    } 
  }
  if((green1*2) > (red1 + blue1))
  {
    CRGBPalette16 palette_fifthZone = ForestColors_p; 
    uint8_t beat = beatsin16( BeatsPerMinute, 64, 255);
    for( int i = 0; i < FIFTHZONE_LEDS; i++) 
    {
      fifthZone[i] = ColorFromPalette(palette_fifthZone, gHue+(i*2), beat-gHue+(i*10));
    } 
  }
  if((blue1*2) > (green1 + red1))
  {
    CRGBPalette16 palette_fifthZone = CloudColors_p; 
    uint8_t beat = beatsin16( BeatsPerMinute, 64, 255);
    for( int i = 0; i < FIFTHZONE_LEDS; i++) 
    {
      fifthZone[i] = ColorFromPalette(palette_fifthZone, gHue+(i*2), beat-gHue+(i*10));
    } 
  }
  if((blue1*2) == (green1 + red1))
  {
    CRGBPalette16 palette_fifthZone = PartyColors_p; 
    uint8_t beat = beatsin16( BeatsPerMinute, 64, 255);
    for( int i = 0; i < FIFTHZONE_LEDS; i++) 
    {
      fifthZone[i] = ColorFromPalette(palette_fifthZone, gHue+(i*2), beat-gHue+(i*10));
    } 
  }
}

void Twinkle_fifthZone()
{
  fadeToBlackBy( fifthZone, FIFTHZONE_LEDS, 80);
  for( int i = 0; i < FIFTHZONE_LEDS-5; i+=5)
  {
    if(i <= FIFTHZONE_LEDS)
    {
      if (random8() > twinkleChance)
      {
        fifthZone[i] = CRGB( red1, green1, blue1);
      }
      else
      {
        fifthZone[i] = CRGB( 150, 100, 40);
      }  
    }
  }                     
}

void Eyes_fifthZone()
{
  unsigned int chance = random8();
  if( chance > eyeChance) 
  {
    unsigned int eye = random16(FIFTHZONE_LEDS);  
    fifthZone[eye] = CRGB(red1,green1,blue1);
    fifthZone[eye-4] = CRGB(red1,green1,blue1);
  }
  if( chance > 39) 
  {
    fadeToBlackBy( fifthZone, FIFTHZONE_LEDS, 10);
  }
}

void Solid_fifthZone()
{
  fill_solid(fifthZone, FIFTHZONE_LEDS, CRGB(red1, green1, blue1));
}

void Locator_fifthZone()
{
  if(locatorLED <= FIFTHZONE_LEDS)
  {
    fill_solid(fifthZone, FIFTHZONE_LEDS, CRGB::Black); 
    fifthZone[locatorLED]=CRGB(red1, green1, blue1);
  }
}

#ifdef ZONEFIVE_SECTION1_START
void fire_fifthZone_SECTION1()
{
  static byte heat[ZONEFIVE_SECTION1_END - ZONEFIVE_SECTION1_START];
  for( int i = 0; i < ZONEFIVE_SECTION1_END - ZONEFIVE_SECTION1_START; i++) 
  {
    heat[i] = qsub8( heat[i],  random8(0, ((COOLING * 10) / ZONEFIVE_SECTION1_END - ZONEFIVE_SECTION1_START) + 2));
  }

  for( int k= ZONEFIVE_SECTION1_END - ZONEFIVE_SECTION1_START - 1; k >= 2; k--) 
  {
    heat[k] = (heat[k - 1] + heat[k - 2] + heat[k - 2] ) / 3;
  }
  if( random8() < SPARKING ) 
  {
    int y = random8(7);
    heat[y] = qadd8( heat[y], random8(160,255) );
  }
  for( int j = 0; j < ZONEFIVE_SECTION1_END - ZONEFIVE_SECTION1_START; j++) 
  {
    byte colorindex = scale8( heat[j], 240);
    CRGB color = ColorFromPalette( gPal, colorindex);
    int pixelnumber;
    if( gReverseDirection ) {
      pixelnumber = (ZONEFIVE_SECTION1_END - ZONEFIVE_SECTION1_START -1) - j;
    } else {
      pixelnumber = j;
    }
    int thisFlame = ((pixelnumber * firesize)/100);
    if(thisFlame <=  ZONEFIVE_SECTION1_START && thisFlame <= ZONEFIVE_SECTION1_END)
    
    #if ZONEFIVE_SECTION1_START_FIRE == 1
    {
      fifthZone[ZONEFIVE_SECTION1_START + thisFlame] = color;
    }
    #endif
    
    #if ZONEFIVE_SECTION1_END_FIRE == 1
    {
      fifthZone[ZONEFIVE_SECTION1_END - thisFlame] = color;
    }
    #endif
  }
}
#endif

#ifdef ZONEFIVE_SECTION2_START
void fire_fifthZone_SECTION2()
{
  static byte heat[ZONEFIVE_SECTION2_END - ZONEFIVE_SECTION2_START];
  for( int i = 0; i < ZONEFIVE_SECTION2_END - ZONEFIVE_SECTION2_START; i++) 
  {
    heat[i] = qsub8( heat[i],  random8(0, ((COOLING * 10) / ZONEFIVE_SECTION2_END - ZONEFIVE_SECTION2_START) + 2));
  }

  for( int k= ZONEFIVE_SECTION2_END - ZONEFIVE_SECTION2_START - 1; k >= 2; k--) 
  {
    heat[k] = (heat[k - 1] + heat[k - 2] + heat[k - 2] ) / 3;
  }
  if( random8() < SPARKING ) 
  {
    int y = random8(7);
    heat[y] = qadd8( heat[y], random8(160,255) );
  }
  for( int j = 0; j < ZONEFIVE_SECTION2_END - ZONEFIVE_SECTION2_START; j++) 
  {
    byte colorindex = scale8( heat[j], 240);
    CRGB color = ColorFromPalette( gPal, colorindex);
    int pixelnumber;
    if( gReverseDirection ) {
      pixelnumber = (ZONEFIVE_SECTION2_END - ZONEFIVE_SECTION2_START -1) - j;
    } else {
      pixelnumber = j;
    }
    int thisFlame = ((pixelnumber * firesize)/100);
    if(thisFlame <=  ZONEFIVE_SECTION2_START && thisFlame <= ZONEFIVE_SECTION2_END)
    
    #if ZONEFIVE_SECTION2_START_FIRE == 1
    {
      fifthZone[ZONEFIVE_SECTION2_START + thisFlame] = color;
    }
    #endif
    
    #if ZONEFIVE_SECTION2_END_FIRE == 1
    {
      fifthZone[ZONEFIVE_SECTION2_END - thisFlame] = color;
    }
    #endif
  }
}
#endif

#ifdef ZONEFIVE_SECTION3_START
void fire_fifthZone_SECTION3()
{
  static byte heat[ZONEFIVE_SECTION3_END - ZONEFIVE_SECTION3_START];
  for( int i = 0; i < ZONEFIVE_SECTION3_END - ZONEFIVE_SECTION3_START; i++) 
  {
    heat[i] = qsub8( heat[i],  random8(0, ((COOLING * 10) / ZONEFIVE_SECTION3_END - ZONEFIVE_SECTION3_START) + 2));
  }

  for( int k= ZONEFIVE_SECTION3_END - ZONEFIVE_SECTION3_START - 1; k >= 2; k--) 
  {
    heat[k] = (heat[k - 1] + heat[k - 2] + heat[k - 2] ) / 3;
  }
  if( random8() < SPARKING ) 
  {
    int y = random8(7);
    heat[y] = qadd8( heat[y], random8(160,255) );
  }
  for( int j = 0; j < ZONEFIVE_SECTION3_END - ZONEFIVE_SECTION3_START; j++) 
  {
    byte colorindex = scale8( heat[j], 240);
    CRGB color = ColorFromPalette( gPal, colorindex);
    int pixelnumber;
    if( gReverseDirection ) {
      pixelnumber = (ZONEFIVE_SECTION3_END - ZONEFIVE_SECTION3_START -1) - j;
    } else {
      pixelnumber = j;
    }
    int thisFlame = ((pixelnumber * firesize)/100);
    if(thisFlame <=  ZONEFIVE_SECTION3_START && thisFlame <= ZONEFIVE_SECTION3_END)
    
    #if ZONEFIVE_SECTION3_START_FIRE == 1
    {
      fifthZone[ZONEFIVE_SECTION3_START + thisFlame] = color;
    }
    #endif
    
    #if ZONEFIVE_SECTION3_END_FIRE == 1
    {
      fifthZone[ZONEFIVE_SECTION3_END - thisFlame] = color;
    }
    #endif
  }
}
#endif

#ifdef ZONEFIVE_SECTION4_START
void fire_fifthZone_SECTION4()
{
  static byte heat[ZONEFIVE_SECTION4_END - ZONEFIVE_SECTION4_START];
  for( int i = 0; i < ZONEFIVE_SECTION4_END - ZONEFIVE_SECTION4_START; i++) 
  {
    heat[i] = qsub8( heat[i],  random8(0, ((COOLING * 10) / ZONEFIVE_SECTION4_END - ZONEFIVE_SECTION4_START) + 2));
  }

  for( int k= ZONEFIVE_SECTION4_END - ZONEFIVE_SECTION4_START - 1; k >= 2; k--) 
  {
    heat[k] = (heat[k - 1] + heat[k - 2] + heat[k - 2] ) / 3;
  }
  if( random8() < SPARKING ) 
  {
    int y = random8(7);
    heat[y] = qadd8( heat[y], random8(160,255) );
  }
  for( int j = 0; j < ZONEFIVE_SECTION4_END - ZONEFIVE_SECTION4_START; j++) 
  {
    byte colorindex = scale8( heat[j], 240);
    CRGB color = ColorFromPalette( gPal, colorindex);
    int pixelnumber;
    if( gReverseDirection ) {
      pixelnumber = (ZONEFIVE_SECTION4_END - ZONEFIVE_SECTION4_START -1) - j;
    } else {
      pixelnumber = j;
    }
    int thisFlame = ((pixelnumber * firesize)/100);
    if(thisFlame <=  ZONEFIVE_SECTION4_START && thisFlame <= ZONEFIVE_SECTION4_END)
    
    #if ZONEFIVE_SECTION4_START_FIRE == 1
    {
      fifthZone[ZONEFIVE_SECTION4_START + thisFlame] = color;
    }
    #endif
    
    #if ZONEFIVE_SECTION4_END_FIRE == 1
    {
      fifthZone[ZONEFIVE_SECTION4_END - thisFlame] = color;
    }
    #endif
  }
}
#endif

#ifdef ZONEFIVE_SECTION5_START
void fire_fifthZone_SECTION5()
{
  static byte heat[ZONEFIVE_SECTION5_END - ZONEFIVE_SECTION5_START];
  for( int i = 0; i < ZONEFIVE_SECTION5_END - ZONEFIVE_SECTION5_START; i++) 
  {
    heat[i] = qsub8( heat[i],  random8(0, ((COOLING * 10) / ZONEFIVE_SECTION5_END - ZONEFIVE_SECTION5_START) + 2));
  }

  for( int k= ZONEFIVE_SECTION5_END - ZONEFIVE_SECTION5_START - 1; k >= 2; k--) 
  {
    heat[k] = (heat[k - 1] + heat[k - 2] + heat[k - 2] ) / 3;
  }
  if( random8() < SPARKING ) 
  {
    int y = random8(7);
    heat[y] = qadd8( heat[y], random8(160,255) );
  }
  for( int j = 0; j < ZONEFIVE_SECTION5_END - ZONEFIVE_SECTION5_START; j++) 
  {
    byte colorindex = scale8( heat[j], 240);
    CRGB color = ColorFromPalette( gPal, colorindex);
    int pixelnumber;
    if( gReverseDirection ) {
      pixelnumber = (ZONEFIVE_SECTION5_END - ZONEFIVE_SECTION5_START -1) - j;
    } else {
      pixelnumber = j;
    }
    int thisFlame = ((pixelnumber * firesize)/100);
    if(thisFlame <=  ZONEFIVE_SECTION5_START && thisFlame <= ZONEFIVE_SECTION5_END)
    
    #if ZONEFIVE_SECTION5_START_FIRE == 1
    {
      fifthZone[ZONEFIVE_SECTION5_START + thisFlame] = color;
    }
    #endif
    
    #if ZONEFIVE_SECTION5_END_FIRE == 1
    {
      fifthZone[ZONEFIVE_SECTION5_END - thisFlame] = color;
    }
    #endif
  }
}
#endif

#ifdef ZONEFIVE_SECTION6_START
void fire_fifthZone_SECTION6()
{
  static byte heat[ZONEFIVE_SECTION6_END - ZONEFIVE_SECTION6_START];
  for( int i = 0; i < ZONEFIVE_SECTION6_END - ZONEFIVE_SECTION6_START; i++) 
  {
    heat[i] = qsub8( heat[i],  random8(0, ((COOLING * 10) / ZONEFIVE_SECTION6_END - ZONEFIVE_SECTION6_START) + 2));
  }

  for( int k= ZONEFIVE_SECTION6_END - ZONEFIVE_SECTION6_START - 1; k >= 2; k--) 
  {
    heat[k] = (heat[k - 1] + heat[k - 2] + heat[k - 2] ) / 3;
  }
  if( random8() < SPARKING ) 
  {
    int y = random8(7);
    heat[y] = qadd8( heat[y], random8(160,255) );
  }
  for( int j = 0; j < ZONEFIVE_SECTION6_END - ZONEFIVE_SECTION6_START; j++) 
  {
    byte colorindex = scale8( heat[j], 240);
    CRGB color = ColorFromPalette( gPal, colorindex);
    int pixelnumber;
    if( gReverseDirection ) {
      pixelnumber = (ZONEFIVE_SECTION6_END - ZONEFIVE_SECTION6_START -1) - j;
    } else {
      pixelnumber = j;
    }
    int thisFlame = ((pixelnumber * firesize)/100);
    if(thisFlame <=  ZONEFIVE_SECTION6_START && thisFlame <= ZONEFIVE_SECTION6_END)
    
    #if ZONEFIVE_SECTION6_START_FIRE == 1
    {
      fifthZone[ZONEFIVE_SECTION6_START + thisFlame] = color;
    }
    #endif
    
    #if ZONEFIVE_SECTION6_END_FIRE == 1
    {
      fifthZone[ZONEFIVE_SECTION6_END - thisFlame] = color;
    }
    #endif
  }
}
#endif

#ifdef ZONEFIVE_SECTION7_START
void fire_fifthZone_SECTION7()
{
  static byte heat[ZONEFIVE_SECTION7_END - ZONEFIVE_SECTION7_START];
  for( int i = 0; i < ZONEFIVE_SECTION7_END - ZONEFIVE_SECTION7_START; i++) 
  {
    heat[i] = qsub8( heat[i],  random8(0, ((COOLING * 10) / ZONEFIVE_SECTION7_END - ZONEFIVE_SECTION7_START) + 2));
  }

  for( int k= ZONEFIVE_SECTION7_END - ZONEFIVE_SECTION7_START - 1; k >= 2; k--) 
  {
    heat[k] = (heat[k - 1] + heat[k - 2] + heat[k - 2] ) / 3;
  }
  if( random8() < SPARKING ) 
  {
    int y = random8(7);
    heat[y] = qadd8( heat[y], random8(160,255) );
  }
  for( int j = 0; j < ZONEFIVE_SECTION7_END - ZONEFIVE_SECTION7_START; j++) 
  {
    byte colorindex = scale8( heat[j], 240);
    CRGB color = ColorFromPalette( gPal, colorindex);
    int pixelnumber;
    if( gReverseDirection ) {
      pixelnumber = (ZONEFIVE_SECTION7_END - ZONEFIVE_SECTION7_START -1) - j;
    } else {
      pixelnumber = j;
    }
    int thisFlame = ((pixelnumber * firesize)/100);
    if(thisFlame <=  ZONEFIVE_SECTION7_START && thisFlame <= ZONEFIVE_SECTION7_END)
    
    #if ZONEFIVE_SECTION7_START_FIRE == 1
    {
      fifthZone[ZONEFIVE_SECTION7_START + thisFlame] = color;
    }
    #endif
    
    #if ZONEFIVE_SECTION7_END_FIRE == 1
    {
      fifthZone[ZONEFIVE_SECTION7_END - thisFlame] = color;
    }
    #endif
  }
}
#endif

#ifdef ZONEFIVE_SECTION8_START
void fire_fifthZone_SECTION8()
{
  static byte heat[ZONEFIVE_SECTION8_END - ZONEFIVE_SECTION8_START];
  for( int i = 0; i < ZONEFIVE_SECTION8_END - ZONEFIVE_SECTION8_START; i++) 
  {
    heat[i] = qsub8( heat[i],  random8(0, ((COOLING * 10) / ZONEFIVE_SECTION8_END - ZONEFIVE_SECTION8_START) + 2));
  }

  for( int k= ZONEFIVE_SECTION8_END - ZONEFIVE_SECTION8_START - 1; k >= 2; k--) 
  {
    heat[k] = (heat[k - 1] + heat[k - 2] + heat[k - 2] ) / 3;
  }
  if( random8() < SPARKING ) 
  {
    int y = random8(7);
    heat[y] = qadd8( heat[y], random8(160,255) );
  }
  for( int j = 0; j < ZONEFIVE_SECTION8_END - ZONEFIVE_SECTION8_START; j++) 
  {
    byte colorindex = scale8( heat[j], 240);
    CRGB color = ColorFromPalette( gPal, colorindex);
    int pixelnumber;
    if( gReverseDirection ) {
      pixelnumber = (ZONEFIVE_SECTION8_END - ZONEFIVE_SECTION8_START -1) - j;
    } else {
      pixelnumber = j;
    }
    int thisFlame = ((pixelnumber * firesize)/100);
    if(thisFlame <=  ZONEFIVE_SECTION8_START && thisFlame <= ZONEFIVE_SECTION8_END)
    
    #if ZONEFIVE_SECTION8_START_FIRE == 1
    {
      fifthZone[ZONEFIVE_SECTION8_START + thisFlame] = color;
    }
    #endif
    
    #if ZONEFIVE_SECTION8_END_FIRE == 1
    {
      fifthZone[ZONEFIVE_SECTION8_END - thisFlame] = color;
    }
    #endif
  }
}
#endif

#ifdef ZONEFIVE_SECTION9_START
void fire_fifthZone_SECTION9()
{
  static byte heat[ZONEFIVE_SECTION9_END - ZONEFIVE_SECTION9_START];
  for( int i = 0; i < ZONEFIVE_SECTION9_END - ZONEFIVE_SECTION9_START; i++) 
  {
    heat[i] = qsub8( heat[i],  random8(0, ((COOLING * 10) / ZONEFIVE_SECTION9_END - ZONEFIVE_SECTION9_START) + 2));
  }

  for( int k= ZONEFIVE_SECTION9_END - ZONEFIVE_SECTION9_START - 1; k >= 2; k--) 
  {
    heat[k] = (heat[k - 1] + heat[k - 2] + heat[k - 2] ) / 3;
  }
  if( random8() < SPARKING ) 
  {
    int y = random8(7);
    heat[y] = qadd8( heat[y], random8(160,255) );
  }
  for( int j = 0; j < ZONEFIVE_SECTION9_END - ZONEFIVE_SECTION9_START; j++) 
  {
    byte colorindex = scale8( heat[j], 240);
    CRGB color = ColorFromPalette( gPal, colorindex);
    int pixelnumber;
    if( gReverseDirection ) {
      pixelnumber = (ZONEFIVE_SECTION9_END - ZONEFIVE_SECTION9_START -1) - j;
    } else {
      pixelnumber = j;
    }
    int thisFlame = ((pixelnumber * firesize)/100);
    if(thisFlame <=  ZONEFIVE_SECTION9_START && thisFlame <= ZONEFIVE_SECTION9_END)
    
    #if ZONEFIVE_SECTION9_START_FIRE == 1
    {
      fifthZone[ZONEFIVE_SECTION9_START + thisFlame] = color;
    }
    #endif
    
    #if ZONEFIVE_SECTION9_END_FIRE == 1
    {
      fifthZone[ZONEFIVE_SECTION9_END - thisFlame] = color;
    }
    #endif
  }
}
#endif

#endif

/*****************  sixthZone Animations  ****************************************/
/*****************  sixthZone Animations  ****************************************/
/*****************  sixthZone Animations  ****************************************/
/*****************  sixthZone Animations  ****************************************/
/*****************  sixthZone Animations  ****************************************/

#if ZONESIX == 1

void Ripple_sixthZone()
{
  for (int i = 0; i < SIXTHZONE_LEDS; i++)
  {
    sixthZone[i] = CRGB((red2/75), (green2/75), (blue2/75));
  }   
  switch (step_sixthZone) 
  {
    case -1:                                                          
      center_sixthZone = random16(SIXTHZONE_LEDS);
      step_sixthZone = 0;
      break;
    case 0:
      sixthZone[center_sixthZone] = CRGB(red1, green1, blue1);                          
      step_sixthZone ++;
      break;
    case 12:                                                   
      step_sixthZone = -1;
      break;
    default:                                                             // Middle of the ripples.
      sixthZone[(center_sixthZone + step_sixthZone + SIXTHZONE_LEDS) % SIXTHZONE_LEDS] += CRGB((red1/(step_sixthZone * 5)), (green1/(step_sixthZone * 5)), (blue1/(step_sixthZone * 5)));
      sixthZone[(center_sixthZone - step_sixthZone + SIXTHZONE_LEDS) % SIXTHZONE_LEDS] += CRGB((red1/(step_sixthZone * 5)), (green1/(step_sixthZone * 5)), (blue1/(step_sixthZone * 5)));
      step_sixthZone ++;                                                         
      break;
  }
}

void RGB_sixthZone()
{
  if(startPosition < 6)
  {
    fadeToBlackBy( sixthZone, SIXTHZONE_LEDS, 80);
    for(int pixel = startPosition+1; pixel < SIXTHZONE_LEDS; pixel+=6)  
    {
      if(pixel <= SIXTHZONE_LEDS)
      {
        sixthZone[pixel] = CRGB(red1,green1,blue1);
      }
    }
    for(int pixel = startPosition+3; pixel < SIXTHZONE_LEDS; pixel+=6)
    {
      if(pixel <= SIXTHZONE_LEDS)
      {
        sixthZone[pixel] = CRGB(red2,green2,blue2);
      }
    }
    for(int pixel = startPosition+5; pixel < SIXTHZONE_LEDS; pixel+=6)
    {
      if(pixel <= SIXTHZONE_LEDS)
      {
        sixthZone[pixel] = CRGB(red3,green3,blue3);
      } 
    }
  }
  if(startPosition == 1)
  {
    sixthZone[0]=CRGB(red3,green3,blue3);
  }
  if(startPosition == 2)
  {
    sixthZone[1]=CRGB(red3,green3,blue3);
  }
  if(startPosition == 3)
  {
    sixthZone[2]=CRGB(red3,green3,blue3);
    sixthZone[0]=CRGB(red2,green2,blue2);
  }
  if(startPosition == 4)
  {
    sixthZone[3]=CRGB(red3,green3,blue3);
    sixthZone[1]=CRGB(red2,green2,blue2);
  }
  if(startPosition == 5)
  {
    sixthZone[4]=CRGB(red3,green3,blue3);
    sixthZone[2]=CRGB(red2,green2,blue2);
    sixthZone[0]=CRGB(red1,green1,blue1);
  }
}

void ColorGlitter_sixthZone( fract8 chanceOfGlitter) 
{
  fadeToBlackBy( sixthZone, SIXTHZONE_LEDS, 2);
  if(startPosition == 0)
  {
    if( random8() < chanceOfGlitter) 
    {
    sixthZone[ random16(SIXTHZONE_LEDS) ] += CRGB::Red;
    }
  }
  if(startPosition == 1)
  {
    if( random8() < chanceOfGlitter) 
    {
    sixthZone[ random16(SIXTHZONE_LEDS) ] += CRGB::Orange;
    }
  }
  if(startPosition == 2)
  {
    if( random8() < chanceOfGlitter) 
    {
    sixthZone[ random16(SIXTHZONE_LEDS) ] += CRGB::Yellow;
    }  
  }
  if(startPosition == 3)
  {
    if( random8() < chanceOfGlitter) 
    {
    sixthZone[ random16(SIXTHZONE_LEDS) ] += CRGB::Green;
    }
  }
  if(startPosition == 4)
  {
    if( random8() < chanceOfGlitter) 
    {
    sixthZone[ random16(SIXTHZONE_LEDS) ] += CRGB::Blue;
    }
  }
  if(startPosition == 5)
  {
    if( random8() < chanceOfGlitter) 
    {
    sixthZone[ random16(SIXTHZONE_LEDS) ] += CRGB::Violet;
    }
  } 
}

void SingleRace_sixthZone()
{
  fadeToBlackBy( sixthZone, SIXTHZONE_LEDS, 1);
  int pos = beatsin16( raceSpeed, 0, 474);
  if(pos > previousLED_sixthZone)
  {
    sixthZone[pos] = CRGB(red1,green1,blue1);
    previousLED_sixthZone = pos;
  }
  if(pos < previousLED_sixthZone)
  {
    sixthZone[pos] = CRGB(red2,green2,blue2);
    previousLED_sixthZone = pos;
  }                 
}

  void Crash_sixthZone()
{
  fadeToBlackBy( sixthZone, SIXTHZONE_LEDS, 15);
  #ifdef ZONESIX_SECTION1_START
  int pos_SECTION1 = beatsin16( raceSpeed, 0, (ZONESIX_SECTION1_END - ZONESIX_SECTION1_START) );
  sixthZone[ZONESIX_SECTION1_START + pos_SECTION1] = CRGB(red1,green1,blue1);
  sixthZone[ZONESIX_SECTION1_END - pos_SECTION1] = CRGB(red2,green2,blue2);
  #endif

  #ifdef ZONESIX_SECTION2_START
  int pos_SECTION2 = beatsin16( raceSpeed, 0, (ZONESIX_SECTION2_END - ZONESIX_SECTION2_START) );
  sixthZone[ZONESIX_SECTION2_START + pos_SECTION2] = CRGB(red2,green2,blue2);
  sixthZone[ZONESIX_SECTION2_END - pos_SECTION2] = CRGB(red1,green1,blue1);
  #endif
  
  #ifdef ZONESIX_SECTION3_START
  int pos_SECTION3 = beatsin16( raceSpeed, 0, (ZONESIX_SECTION3_END - ZONESIX_SECTION3_START) );
  sixthZone[ZONESIX_SECTION3_START + pos_SECTION3] = CRGB(red1,green1,blue1);
  sixthZone[ZONESIX_SECTION3_END - pos_SECTION3] = CRGB(red2,green2,blue2);
  #endif
  
  #ifdef ZONESIX_SECTION4_START
  int pos_SECTION4 = beatsin16( raceSpeed, 0, (ZONESIX_SECTION4_END - ZONESIX_SECTION4_START) );
  sixthZone[ZONESIX_SECTION4_START + pos_SECTION4] = CRGB(red2,green2,blue2);
  sixthZone[ZONESIX_SECTION4_END - pos_SECTION4] = CRGB(red1,green1,blue1);
  #endif
  
  #ifdef ZONESIX_SECTION5_START
  int pos_SECTION5 = beatsin16( raceSpeed, 0, (ZONESIX_SECTION5_END - ZONESIX_SECTION5_START) );
  sixthZone[ZONESIX_SECTION5_START + pos_SECTION5] = CRGB(red1,green1,blue1);
  sixthZone[ZONESIX_SECTION5_END - pos_SECTION5] = CRGB(red2,green2,blue2);
  #endif
  
  #ifdef ZONESIX_SECTION6_START
  int pos_SECTION6 = beatsin16( raceSpeed, 0, (ZONESIX_SECTION6_END - ZONESIX_SECTION6_START) );
  sixthZone[ZONESIX_SECTION6_START + pos_SECTION6] = CRGB(red2,green2,blue2);
  sixthZone[ZONESIX_SECTION6_END - pos_SECTION6] = CRGB(red1,green1,blue1);
  #endif
  
  #ifdef ZONESIX_SECTION7_START
  int pos_SECTION7 = beatsin16( raceSpeed, 0, (ZONESIX_SECTION7_END - ZONESIX_SECTION7_START) );
  sixthZone[ZONESIX_SECTION7_START + pos_SECTION7] = CRGB(red1,green1,blue1);
  sixthZone[ZONESIX_SECTION7_END - pos_SECTION7] = CRGB(red2,green2,blue2);
  #endif
  
  #ifdef ZONESIX_SECTION8_START
  int pos_SECTION8 = beatsin16( raceSpeed, 0, (ZONESIX_SECTION8_END - ZONESIX_SECTION8_START) );
  sixthZone[ZONESIX_SECTION8_START + pos_SECTION8] = CRGB(red2,green2,blue2);
  sixthZone[ZONESIX_SECTION8_END - pos_SECTION8] = CRGB(red1,green1,blue1);
  #endif
  
  #ifdef ZONESIX_SECTION9_START
  int pos_SECTION9 = beatsin16( raceSpeed, 0, (ZONESIX_SECTION9_END - ZONESIX_SECTION9_START) );
  sixthZone[ZONESIX_SECTION9_START + pos_SECTION9] = CRGB(red1,green1,blue1);
  sixthZone[ZONESIX_SECTION9_END - pos_SECTION9] = CRGB(red2,green2,blue2);
  #endif
  
}

void Rainbow_sixthZone()
{
  fill_rainbow( sixthZone, SIXTHZONE_LEDS, gHue, numberOfRainbows);
}

void Blocked_sixthZone()
{
  fadeToBlackBy( sixthZone, SIXTHZONE_LEDS, 2);
  for( int mark = 0; mark < SIXTHZONE_LEDS; mark+=30)
  {
    for( int i = 0; i < 9; i++) 
    {
      if(startPosition == 0 || startPosition == 1)
      {
        if(i+mark <= SIXTHZONE_LEDS)
        {
          sixthZone[i+mark] = CRGB(red1,green1,blue1);
        }
        if(i+10+mark <= SIXTHZONE_LEDS)
        {
          sixthZone[i+10+mark] = CRGB(red2,green2,blue2);
        }
        if(i+20+mark <= SIXTHZONE_LEDS)
        {
          sixthZone[i+20+mark] = CRGB(red3,green3,blue3);
        }
      }
      if(startPosition == 2 || startPosition == 3)
      {
        if(i+mark <= SIXTHZONE_LEDS)
        {
          sixthZone[i+mark] = CRGB(red2,green2,blue2);
        }
        if(i+10+mark <= SIXTHZONE_LEDS)
        {
          sixthZone[i+10+mark] = CRGB(red3,green3,blue3);
        }
        if(i+20+mark <= SIXTHZONE_LEDS)
        {
          sixthZone[i+20+mark] = CRGB(red1,green1,blue1);
        }
      }
      if(startPosition == 4 || startPosition == 5)
      {
        if(i+mark <= SIXTHZONE_LEDS)
        {
          sixthZone[i+mark] = CRGB(red3,green3,blue3);
        }
        if(i+10+mark <= SIXTHZONE_LEDS)
        {
          sixthZone[i+10+mark] = CRGB(red1,green1,blue1);
        }
        if(i+20+mark <= SIXTHZONE_LEDS)
        {
          sixthZone[i+20+mark] = CRGB(red2,green2,blue2);
        }
      }
    }
  }
}

void BPM_sixthZone()
{
  if((red1*2) > (green1 + blue1))
  {
    CRGBPalette16 palette_sixthZone = LavaColors_p; 
    uint8_t beat = beatsin16( BeatsPerMinute, 64, 255);
    for( int i = 0; i < SIXTHZONE_LEDS; i++) 
    {
      sixthZone[i] = ColorFromPalette(palette_sixthZone, gHue+(i*2), beat-gHue+(i*10));
    } 
  }
  if((green1*2) > (red1 + blue1))
  {
    CRGBPalette16 palette_sixthZone = ForestColors_p; 
    uint8_t beat = beatsin16( BeatsPerMinute, 64, 255);
    for( int i = 0; i < SIXTHZONE_LEDS; i++) 
    {
      sixthZone[i] = ColorFromPalette(palette_sixthZone, gHue+(i*2), beat-gHue+(i*10));
    } 
  }
  if((blue1*2) > (green1 + red1))
  {
    CRGBPalette16 palette_sixthZone = CloudColors_p; 
    uint8_t beat = beatsin16( BeatsPerMinute, 64, 255);
    for( int i = 0; i < SIXTHZONE_LEDS; i++) 
    {
      sixthZone[i] = ColorFromPalette(palette_sixthZone, gHue+(i*2), beat-gHue+(i*10));
    } 
  }
  if((blue1*2) == (green1 + red1))
  {
    CRGBPalette16 palette_sixthZone = PartyColors_p; 
    uint8_t beat = beatsin16( BeatsPerMinute, 64, 255);
    for( int i = 0; i < SIXTHZONE_LEDS; i++) 
    {
      sixthZone[i] = ColorFromPalette(palette_sixthZone, gHue+(i*2), beat-gHue+(i*10));
    } 
  }
}

void Twinkle_sixthZone()
{
  fadeToBlackBy( sixthZone, SIXTHZONE_LEDS, 80);
  for( int i = 0; i < SIXTHZONE_LEDS-5; i+=5)
  {
    if(i <= SIXTHZONE_LEDS)
    {
      if (random8() > twinkleChance)
      {
        sixthZone[i] = CRGB( red1, green1, blue1);
      }
      else
      {
        sixthZone[i] = CRGB( 150, 100, 40);
      }  
    }
  }                     
}

void Eyes_sixthZone()
{
  unsigned int chance = random8();
  if( chance > eyeChance) 
  {
    unsigned int eye = random16(SIXTHZONE_LEDS);  
    sixthZone[eye] = CRGB(red1,green1,blue1);
    sixthZone[eye-4] = CRGB(red1,green1,blue1);
  }
  if( chance > 39) 
  {
    fadeToBlackBy( sixthZone, SIXTHZONE_LEDS, 10);
  }
}

void Solid_sixthZone()
{
  fill_solid(sixthZone, SIXTHZONE_LEDS, CRGB(red1, green1, blue1));
}

void Locator_sixthZone()
{
  if(locatorLED <= SIXTHZONE_LEDS)
  {
    fill_solid(sixthZone, SIXTHZONE_LEDS, CRGB::Black); 
    sixthZone[locatorLED]=CRGB(red1, green1, blue1);
  }
}

#ifdef ZONESIX_SECTION1_START
void fire_sixthZone_SECTION1()
{
  static byte heat[ZONESIX_SECTION1_END - ZONESIX_SECTION1_START];
  for( int i = 0; i < ZONESIX_SECTION1_END - ZONESIX_SECTION1_START; i++) 
  {
    heat[i] = qsub8( heat[i],  random8(0, ((COOLING * 10) / ZONESIX_SECTION1_END - ZONESIX_SECTION1_START) + 2));
  }

  for( int k= ZONESIX_SECTION1_END - ZONESIX_SECTION1_START - 1; k >= 2; k--) 
  {
    heat[k] = (heat[k - 1] + heat[k - 2] + heat[k - 2] ) / 3;
  }
  if( random8() < SPARKING ) 
  {
    int y = random8(7);
    heat[y] = qadd8( heat[y], random8(160,255) );
  }
  for( int j = 0; j < ZONESIX_SECTION1_END - ZONESIX_SECTION1_START; j++) 
  {
    byte colorindex = scale8( heat[j], 240);
    CRGB color = ColorFromPalette( gPal, colorindex);
    int pixelnumber;
    if( gReverseDirection ) {
      pixelnumber = (ZONESIX_SECTION1_END - ZONESIX_SECTION1_START -1) - j;
    } else {
      pixelnumber = j;
    }
    int thisFlame = ((pixelnumber * firesize)/100);
    if(thisFlame <=  ZONESIX_SECTION1_START && thisFlame <= ZONESIX_SECTION1_END)
    
    #if ZONESIX_SECTION1_START_FIRE == 1
    {
      sixthZone[ZONESIX_SECTION1_START + thisFlame] = color;
    }
    #endif
    
    #if ZONESIX_SECTION1_END_FIRE == 1
    {
      sixthZone[ZONESIX_SECTION1_END - thisFlame] = color;
    }
    #endif
  }
}
#endif

#ifdef ZONESIX_SECTION2_START
void fire_sixthZone_SECTION2()
{
  static byte heat[ZONESIX_SECTION2_END - ZONESIX_SECTION2_START];
  for( int i = 0; i < ZONESIX_SECTION2_END - ZONESIX_SECTION2_START; i++) 
  {
    heat[i] = qsub8( heat[i],  random8(0, ((COOLING * 10) / ZONESIX_SECTION2_END - ZONESIX_SECTION2_START) + 2));
  }

  for( int k= ZONESIX_SECTION2_END - ZONESIX_SECTION2_START - 1; k >= 2; k--) 
  {
    heat[k] = (heat[k - 1] + heat[k - 2] + heat[k - 2] ) / 3;
  }
  if( random8() < SPARKING ) 
  {
    int y = random8(7);
    heat[y] = qadd8( heat[y], random8(160,255) );
  }
  for( int j = 0; j < ZONESIX_SECTION2_END - ZONESIX_SECTION2_START; j++) 
  {
    byte colorindex = scale8( heat[j], 240);
    CRGB color = ColorFromPalette( gPal, colorindex);
    int pixelnumber;
    if( gReverseDirection ) {
      pixelnumber = (ZONESIX_SECTION2_END - ZONESIX_SECTION2_START -1) - j;
    } else {
      pixelnumber = j;
    }
    int thisFlame = ((pixelnumber * firesize)/100);
    if(thisFlame <=  ZONESIX_SECTION2_START && thisFlame <= ZONESIX_SECTION2_END)
    
    #if ZONESIX_SECTION2_START_FIRE == 1
    {
      sixthZone[ZONESIX_SECTION2_START + thisFlame] = color;
    }
    #endif
    
    #if ZONESIX_SECTION2_END_FIRE == 1
    {
      sixthZone[ZONESIX_SECTION2_END - thisFlame] = color;
    }
    #endif
  }
}
#endif

#ifdef ZONESIX_SECTION3_START
void fire_sixthZone_SECTION3()
{
  static byte heat[ZONESIX_SECTION3_END - ZONESIX_SECTION3_START];
  for( int i = 0; i < ZONESIX_SECTION3_END - ZONESIX_SECTION3_START; i++) 
  {
    heat[i] = qsub8( heat[i],  random8(0, ((COOLING * 10) / ZONESIX_SECTION3_END - ZONESIX_SECTION3_START) + 2));
  }

  for( int k= ZONESIX_SECTION3_END - ZONESIX_SECTION3_START - 1; k >= 2; k--) 
  {
    heat[k] = (heat[k - 1] + heat[k - 2] + heat[k - 2] ) / 3;
  }
  if( random8() < SPARKING ) 
  {
    int y = random8(7);
    heat[y] = qadd8( heat[y], random8(160,255) );
  }
  for( int j = 0; j < ZONESIX_SECTION3_END - ZONESIX_SECTION3_START; j++) 
  {
    byte colorindex = scale8( heat[j], 240);
    CRGB color = ColorFromPalette( gPal, colorindex);
    int pixelnumber;
    if( gReverseDirection ) {
      pixelnumber = (ZONESIX_SECTION3_END - ZONESIX_SECTION3_START -1) - j;
    } else {
      pixelnumber = j;
    }
    int thisFlame = ((pixelnumber * firesize)/100);
    if(thisFlame <=  ZONESIX_SECTION3_START && thisFlame <= ZONESIX_SECTION3_END)
    
    #if ZONESIX_SECTION3_START_FIRE == 1
    {
      sixthZone[ZONESIX_SECTION3_START + thisFlame] = color;
    }
    #endif
    
    #if ZONESIX_SECTION3_END_FIRE == 1
    {
      sixthZone[ZONESIX_SECTION3_END - thisFlame] = color;
    }
    #endif
  }
}
#endif

#ifdef ZONESIX_SECTION4_START
void fire_sixthZone_SECTION4()
{
  static byte heat[ZONESIX_SECTION4_END - ZONESIX_SECTION4_START];
  for( int i = 0; i < ZONESIX_SECTION4_END - ZONESIX_SECTION4_START; i++) 
  {
    heat[i] = qsub8( heat[i],  random8(0, ((COOLING * 10) / ZONESIX_SECTION4_END - ZONESIX_SECTION4_START) + 2));
  }

  for( int k= ZONESIX_SECTION4_END - ZONESIX_SECTION4_START - 1; k >= 2; k--) 
  {
    heat[k] = (heat[k - 1] + heat[k - 2] + heat[k - 2] ) / 3;
  }
  if( random8() < SPARKING ) 
  {
    int y = random8(7);
    heat[y] = qadd8( heat[y], random8(160,255) );
  }
  for( int j = 0; j < ZONESIX_SECTION4_END - ZONESIX_SECTION4_START; j++) 
  {
    byte colorindex = scale8( heat[j], 240);
    CRGB color = ColorFromPalette( gPal, colorindex);
    int pixelnumber;
    if( gReverseDirection ) {
      pixelnumber = (ZONESIX_SECTION4_END - ZONESIX_SECTION4_START -1) - j;
    } else {
      pixelnumber = j;
    }
    int thisFlame = ((pixelnumber * firesize)/100);
    if(thisFlame <=  ZONESIX_SECTION4_START && thisFlame <= ZONESIX_SECTION4_END)
    
    #if ZONESIX_SECTION4_START_FIRE == 1
    {
      sixthZone[ZONESIX_SECTION4_START + thisFlame] = color;
    }
    #endif
    
    #if ZONESIX_SECTION4_END_FIRE == 1
    {
      sixthZone[ZONESIX_SECTION4_END - thisFlame] = color;
    }
    #endif
  }
}
#endif

#ifdef ZONESIX_SECTION5_START
void fire_sixthZone_SECTION5()
{
  static byte heat[ZONESIX_SECTION5_END - ZONESIX_SECTION5_START];
  for( int i = 0; i < ZONESIX_SECTION5_END - ZONESIX_SECTION5_START; i++) 
  {
    heat[i] = qsub8( heat[i],  random8(0, ((COOLING * 10) / ZONESIX_SECTION5_END - ZONESIX_SECTION5_START) + 2));
  }

  for( int k= ZONESIX_SECTION5_END - ZONESIX_SECTION5_START - 1; k >= 2; k--) 
  {
    heat[k] = (heat[k - 1] + heat[k - 2] + heat[k - 2] ) / 3;
  }
  if( random8() < SPARKING ) 
  {
    int y = random8(7);
    heat[y] = qadd8( heat[y], random8(160,255) );
  }
  for( int j = 0; j < ZONESIX_SECTION5_END - ZONESIX_SECTION5_START; j++) 
  {
    byte colorindex = scale8( heat[j], 240);
    CRGB color = ColorFromPalette( gPal, colorindex);
    int pixelnumber;
    if( gReverseDirection ) {
      pixelnumber = (ZONESIX_SECTION5_END - ZONESIX_SECTION5_START -1) - j;
    } else {
      pixelnumber = j;
    }
    int thisFlame = ((pixelnumber * firesize)/100);
    if(thisFlame <=  ZONESIX_SECTION5_START && thisFlame <= ZONESIX_SECTION5_END)
    
    #if ZONESIX_SECTION5_START_FIRE == 1
    {
      sixthZone[ZONESIX_SECTION5_START + thisFlame] = color;
    }
    #endif
    
    #if ZONESIX_SECTION5_END_FIRE == 1
    {
      sixthZone[ZONESIX_SECTION5_END - thisFlame] = color;
    }
    #endif
  }
}
#endif

#ifdef ZONESIX_SECTION6_START
void fire_sixthZone_SECTION6()
{
  static byte heat[ZONESIX_SECTION6_END - ZONESIX_SECTION6_START];
  for( int i = 0; i < ZONESIX_SECTION6_END - ZONESIX_SECTION6_START; i++) 
  {
    heat[i] = qsub8( heat[i],  random8(0, ((COOLING * 10) / ZONESIX_SECTION6_END - ZONESIX_SECTION6_START) + 2));
  }

  for( int k= ZONESIX_SECTION6_END - ZONESIX_SECTION6_START - 1; k >= 2; k--) 
  {
    heat[k] = (heat[k - 1] + heat[k - 2] + heat[k - 2] ) / 3;
  }
  if( random8() < SPARKING ) 
  {
    int y = random8(7);
    heat[y] = qadd8( heat[y], random8(160,255) );
  }
  for( int j = 0; j < ZONESIX_SECTION6_END - ZONESIX_SECTION6_START; j++) 
  {
    byte colorindex = scale8( heat[j], 240);
    CRGB color = ColorFromPalette( gPal, colorindex);
    int pixelnumber;
    if( gReverseDirection ) {
      pixelnumber = (ZONESIX_SECTION6_END - ZONESIX_SECTION6_START -1) - j;
    } else {
      pixelnumber = j;
    }
    int thisFlame = ((pixelnumber * firesize)/100);
    if(thisFlame <=  ZONESIX_SECTION6_START && thisFlame <= ZONESIX_SECTION6_END)
    
    #if ZONESIX_SECTION6_START_FIRE == 1
    {
      sixthZone[ZONESIX_SECTION6_START + thisFlame] = color;
    }
    #endif
    
    #if ZONESIX_SECTION6_END_FIRE == 1
    {
      sixthZone[ZONESIX_SECTION6_END - thisFlame] = color;
    }
    #endif
  }
}
#endif

#ifdef ZONESIX_SECTION7_START
void fire_sixthZone_SECTION7()
{
  static byte heat[ZONESIX_SECTION7_END - ZONESIX_SECTION7_START];
  for( int i = 0; i < ZONESIX_SECTION7_END - ZONESIX_SECTION7_START; i++) 
  {
    heat[i] = qsub8( heat[i],  random8(0, ((COOLING * 10) / ZONESIX_SECTION7_END - ZONESIX_SECTION7_START) + 2));
  }

  for( int k= ZONESIX_SECTION7_END - ZONESIX_SECTION7_START - 1; k >= 2; k--) 
  {
    heat[k] = (heat[k - 1] + heat[k - 2] + heat[k - 2] ) / 3;
  }
  if( random8() < SPARKING ) 
  {
    int y = random8(7);
    heat[y] = qadd8( heat[y], random8(160,255) );
  }
  for( int j = 0; j < ZONESIX_SECTION7_END - ZONESIX_SECTION7_START; j++) 
  {
    byte colorindex = scale8( heat[j], 240);
    CRGB color = ColorFromPalette( gPal, colorindex);
    int pixelnumber;
    if( gReverseDirection ) {
      pixelnumber = (ZONESIX_SECTION7_END - ZONESIX_SECTION7_START -1) - j;
    } else {
      pixelnumber = j;
    }
    int thisFlame = ((pixelnumber * firesize)/100);
    if(thisFlame <=  ZONESIX_SECTION7_START && thisFlame <= ZONESIX_SECTION7_END)
    
    #if ZONESIX_SECTION7_START_FIRE == 1
    {
      sixthZone[ZONESIX_SECTION7_START + thisFlame] = color;
    }
    #endif
    
    #if ZONESIX_SECTION7_END_FIRE == 1
    {
      sixthZone[ZONESIX_SECTION7_END - thisFlame] = color;
    }
    #endif
  }
}
#endif

#ifdef ZONESIX_SECTION8_START
void fire_sixthZone_SECTION8()
{
  static byte heat[ZONESIX_SECTION8_END - ZONESIX_SECTION8_START];
  for( int i = 0; i < ZONESIX_SECTION8_END - ZONESIX_SECTION8_START; i++) 
  {
    heat[i] = qsub8( heat[i],  random8(0, ((COOLING * 10) / ZONESIX_SECTION8_END - ZONESIX_SECTION8_START) + 2));
  }

  for( int k= ZONESIX_SECTION8_END - ZONESIX_SECTION8_START - 1; k >= 2; k--) 
  {
    heat[k] = (heat[k - 1] + heat[k - 2] + heat[k - 2] ) / 3;
  }
  if( random8() < SPARKING ) 
  {
    int y = random8(7);
    heat[y] = qadd8( heat[y], random8(160,255) );
  }
  for( int j = 0; j < ZONESIX_SECTION8_END - ZONESIX_SECTION8_START; j++) 
  {
    byte colorindex = scale8( heat[j], 240);
    CRGB color = ColorFromPalette( gPal, colorindex);
    int pixelnumber;
    if( gReverseDirection ) {
      pixelnumber = (ZONESIX_SECTION8_END - ZONESIX_SECTION8_START -1) - j;
    } else {
      pixelnumber = j;
    }
    int thisFlame = ((pixelnumber * firesize)/100);
    if(thisFlame <=  ZONESIX_SECTION8_START && thisFlame <= ZONESIX_SECTION8_END)
    
    #if ZONESIX_SECTION8_START_FIRE == 1
    {
      sixthZone[ZONESIX_SECTION8_START + thisFlame] = color;
    }
    #endif
    
    #if ZONESIX_SECTION8_END_FIRE == 1
    {
      sixthZone[ZONESIX_SECTION8_END - thisFlame] = color;
    }
    #endif
  }
}
#endif

#ifdef ZONESIX_SECTION9_START
void fire_sixthZone_SECTION9()
{
  static byte heat[ZONESIX_SECTION9_END - ZONESIX_SECTION9_START];
  for( int i = 0; i < ZONESIX_SECTION9_END - ZONESIX_SECTION9_START; i++) 
  {
    heat[i] = qsub8( heat[i],  random8(0, ((COOLING * 10) / ZONESIX_SECTION9_END - ZONESIX_SECTION9_START) + 2));
  }

  for( int k= ZONESIX_SECTION9_END - ZONESIX_SECTION9_START - 1; k >= 2; k--) 
  {
    heat[k] = (heat[k - 1] + heat[k - 2] + heat[k - 2] ) / 3;
  }
  if( random8() < SPARKING ) 
  {
    int y = random8(7);
    heat[y] = qadd8( heat[y], random8(160,255) );
  }
  for( int j = 0; j < ZONESIX_SECTION9_END - ZONESIX_SECTION9_START; j++) 
  {
    byte colorindex = scale8( heat[j], 240);
    CRGB color = ColorFromPalette( gPal, colorindex);
    int pixelnumber;
    if( gReverseDirection ) {
      pixelnumber = (ZONESIX_SECTION9_END - ZONESIX_SECTION9_START -1) - j;
    } else {
      pixelnumber = j;
    }
    int thisFlame = ((pixelnumber * firesize)/100);
    if(thisFlame <=  ZONESIX_SECTION9_START && thisFlame <= ZONESIX_SECTION9_END)
    
    #if ZONESIX_SECTION9_START_FIRE == 1
    {
      sixthZone[ZONESIX_SECTION9_START + thisFlame] = color;
    }
    #endif
    
    #if ZONESIX_SECTION9_END_FIRE == 1
    {
      sixthZone[ZONESIX_SECTION9_END - thisFlame] = color;
    }
    #endif
  }
}
#endif

#endif

/*****************  NEEDED TO MAKE NODEMCU WORK ***************************/
#define FASTLED_INTERRUPT_RETRY_COUNT 0
#define FASTLED_ESP8266_RAW_PIN_ORDER
#define NUM_LEDS 100
/******************  LIBRARY SECTION *************************************/

#include <FastLED.h>        //https://github.com/FastLED/FastLED
#include <SimpleTimer.h>    //https://github.com/marcelloromani/Arduino-SimpleTimer/tree/master/SimpleTimer
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


#define ZONEONE                                        //Comment out any unused zones, ZONEONE is pin D1
#define FIRSTZONE_LEDS 300                             //Number of LEDS in this zone (comment out if zone is unused)
#define FIRSTZONE_COLOR_ORDER GRB                      //Color orders, can be RGB, RBG, GRB, GBR, BRG, BGR (comment out if zone is unused)

#define ZONETWO                                        //Comment out any unused zones, ZONETWO is pin D2
#define SECONDZONE_LEDS 300                            //Number of LEDS in this zone (comment out if zone is unused)
#define SECONDZONE_COLOR_ORDER GRB                     //Color orders, can be RGB, RBG, GRB, GBR, BRG, BGR (comment out if zone is unused)

#define ZONETHREE                                      //Comment out any unused zones, ZONETHREE is pin D3
#define THIRDZONE_LEDS 300                             //Number of LEDS in this zone (comment out if zone is unused)
#define THIRDZONE_COLOR_ORDER GRB                      //Color orders, can be RGB, RBG, GRB, GBR, BRG, BGR (comment out if zone is unused)

#define ZONEFOUR                                       //Comment out any unused zones, ZONEFOUR is pin D5
#define FOURTHZONE_LEDS 300                            //Number of LEDS in this zone (comment out if zone is unused)
#define FOURTHZONE_COLOR_ORDER GRB                     //Color orders, can be RGB, RBG, GRB, GBR, BRG, BGR (comment out if zone is unused)

#define ZONEFIVE                                       //Comment out any unused zones, ZONEFIVE is pin D6
#define FIFTHZONE_LEDS 300                             //Number of LEDS in this zone (comment out if zone is unused)
#define FIFTHZONE_COLOR_ORDER GRB                      //Color orders, can be RGB, RBG, GRB, GBR, BRG, BGR (comment out if zone is unused)

#define ZONESIX                                        //Comment out any unused zones, ZONESIX is pin D7
#define SIXTHZONE_LEDS 300                             //Number of LEDS in this zone (comment out if zone is unused)
#define SIXTHZONE_COLOR_ORDER GRB                      //Color orders, can be RGB, RBG, GRB, GBR, BRG, BGR (comment out if zone is unused)

/*****************  ZONEONE ROOF SETUP              *********************************/
/*****************  COMMENT OUT ANY UNUSED SECTIONS *********************************/
#define ZONEONE_SECTION1_START 0
#define ZONEONE_SECTION1_END 30

#define ZONEONE_SECTION2_START 0
#define ZONEONE_SECTION2_END 30

#define ZONEONE_SECTION3_START 0
#define ZONEONE_SECTION3_END 30

#define ZONEONE_SECTION4_START 0
#define ZONEONE_SECTION4_END 30

#define ZONEONE_SECTION5_START 0
#define ZONEONE_SECTION5_END 30

#define ZONEONE_SECTION6_START 0
#define ZONEONE_SECTION6_END 30

#define ZONEONE_SECTION7_START 0
#define ZONEONE_SECTION7_END 30

#define ZONEONE_SECTION8_START 0
#define ZONEONE_SECTION8_END 30

#define ZONEONE_SECTION9_START 0
#define ZONEONE_SECTION9_END 30

/*****************  ZONETWO ROOF SETUP              *********************************/
/*****************  COMMENT OUT ANY UNUSED SECTIONS *********************************/
#define ZONETWO_SECTION1_START 0
#define ZONETWO_SECTION1_END 30

#define ZONETWO_SECTION2_START 0
#define ZONETWO_SECTION2_END 30

#define ZONETWO_SECTION3_START 0
#define ZONETWO_SECTION3_END 30

#define ZONETWO_SECTION4_START 0
#define ZONETWO_SECTION4_END 30

#define ZONETWO_SECTION5_START 0
#define ZONETWO_SECTION5_END 30

#define ZONETWO_SECTION6_START 0
#define ZONETWO_SECTION6_END 30

#define ZONETWO_SECTION7_START 0
#define ZONETWO_SECTION7_END 30

#define ZONETWO_SECTION8_START 0
#define ZONETWO_SECTION8_END 30

#define ZONETWO_SECTION9_START 0
#define ZONETWO_SECTION9_END 30

/*****************  ZONETHREE ROOF SETUP            *********************************/
/*****************  COMMENT OUT ANY UNUSED SECTIONS *********************************/
#define ZONETHREE_SECTION1_START 0
#define ZONETHREE_SECTION1_END 30

#define ZONETHREE_SECTION2_START 0
#define ZONETHREE_SECTION2_END 30

#define ZONETHREE_SECTION3_START 0
#define ZONETHREE_SECTION3_END 30

#define ZONETHREE_SECTION4_START 0
#define ZONETHREE_SECTION4_END 30

#define ZONETHREE_SECTION5_START 0
#define ZONETHREE_SECTION5_END 30

#define ZONETHREE_SECTION6_START 0
#define ZONETHREE_SECTION6_END 30

#define ZONETHREE_SECTION7_START 0
#define ZONETHREE_SECTION7_END 30

#define ZONETHREE_SECTION8_START 0
#define ZONETHREE_SECTION8_END 30

#define ZONETHREE_SECTION9_START 0
#define ZONETHREE_SECTION9_END 30

/*****************  ZONEFOUR ROOF SETUP             *********************************/
/*****************  COMMENT OUT ANY UNUSED SECTIONS *********************************/
#define ZONEFOUR_SECTION1_START 0
#define ZONEFOUR_SECTION1_END 30

#define ZONEFOUR_SECTION2_START 0
#define ZONEFOUR_SECTION2_END 30

#define ZONEFOUR_SECTION3_START 0
#define ZONEFOUR_SECTION3_END 30

#define ZONEFOUR_SECTION4_START 0
#define ZONEFOUR_SECTION4_END 30

#define ZONEFOUR_SECTION5_START 0
#define ZONEFOUR_SECTION5_END 30

#define ZONEFOUR_SECTION6_START 0
#define ZONEFOUR_SECTION6_END 30

#define ZONEFOUR_SECTION7_START 0
#define ZONEFOUR_SECTION7_END 30

#define ZONEFOUR_SECTION8_START 0
#define ZONEFOUR_SECTION8_END 30

#define ZONEFOUR_SECTION9_START 0
#define ZONEFOUR_SECTION9_END 30

/*****************  ZONEFIVE ROOF SETUP             *********************************/
/*****************  COMMENT OUT ANY UNUSED SECTIONS *********************************/
#define ZONEFIVE_SECTION1_START 0
#define ZONEFIVE_SECTION1_END 30

#define ZONEFIVE_SECTION2_START 0
#define ZONEFIVE_SECTION2_END 30

#define ZONEFIVE_SECTION3_START 0
#define ZONEFIVE_SECTION3_END 30

#define ZONEFIVE_SECTION4_START 0
#define ZONEFIVE_SECTION4_END 30

#define ZONEFIVE_SECTION5_START 0
#define ZONEFIVE_SECTION5_END 30

#define ZONEFIVE_SECTION6_START 0
#define ZONEFIVE_SECTION6_END 30

#define ZONEFIVE_SECTION7_START 0
#define ZONEFIVE_SECTION7_END 30

#define ZONEFIVE_SECTION8_START 0
#define ZONEFIVE_SECTION8_END 30

#define ZONEFIVE_SECTION9_START 0
#define ZONEFIVE_SECTION9_END 30

/*****************  ZONESIX ROOF SETUP              *********************************/
/*****************  COMMENT OUT ANY UNUSED SECTIONS *********************************/
#define ZONESIX_SECTION1_START 0
#define ZONESIX_SECTION1_END 30

#define ZONESIX_SECTION2_START 0
#define ZONESIX_SECTION2_END 30

#define ZONESIX_SECTION3_START 0
#define ZONESIX_SECTION3_END 30

#define ZONESIX_SECTION4_START 0
#define ZONESIX_SECTION4_END 30

#define ZONESIX_SECTION5_START 0
#define ZONESIX_SECTION5_END 30

#define ZONESIX_SECTION6_START 0
#define ZONESIX_SECTION6_END 30

#define ZONESIX_SECTION7_START 0
#define ZONESIX_SECTION7_END 30

#define ZONESIX_SECTION8_START 0
#define ZONESIX_SECTION8_END 30

#define ZONESIX_SECTION9_START 0
#define ZONESIX_SECTION9_END 30

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

#ifdef ZONEONE
CRGB firstZone[FIRSTZONE_LEDS];
const int Pin_firstZone = 5; //marked as D1 on the board
int center_firstZone = 0;
int step_firstZone = -1;
int previousLED_firstZone = 0;
#endif

#ifdef ZONETWO
CRGB secondZone[SECONDZONE_LEDS];
const int Pin_secondZone = 4; //marked as D2 on the board
int center_secondZone = 0;
int step_secondZone = -1;
int previousLED_secondZone = 0;
#endif

#ifdef ZONETHREE
CRGB thirdZone[THIRDZONE_LEDS];
const int Pin_thirdZone = 0; //marked as D3 on the board
int center_thirdZone = 0;
int step_thirdZone = -1;
int previousLED_thirdZone = 0;
#endif

#ifdef ZONEFOUR
CRGB fourthZone[FOURTHZONE_LEDS];
const int Pin_fourthZone = 14; //marked as D5 on the board
int center_fourthZone = 0;
int step_fourthZone = -1;
int previousLED_fourthZone = 0;
#endif

#ifdef ZONEFIVE
CRGB fifthZone[FIFTHZONE_LEDS];
const int Pin_fifthZone = 12; //marked as D6 on the board
int center_fifthZone = 0;
int step_fifthZone = -1;
int previousLED_fifthZone = 0;
#endif

#ifdef ZONESIX
CRGB sixthZone[SIXTHZONE_LEDS];
const int Pin_sixthZone = 13; //marked as D7 on the board
int center_sixthZone = 0;
int step_sixthZone = -1;
int previousLED_sixthZone = 0;
#endif



/*****************  GENERAL VARIABLES  *************************************/

CRGBPalette16 gPal;
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
byte brightness = 255;
char charPayload[50];
int maxLEDs = 0;
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
        client.subscribe(USER_MQTT_CLIENT_NAME"/effect");
        client.subscribe(USER_MQTT_CLIENT_NAME"/state");
        client.subscribe(USER_MQTT_CLIENT_NAME"/color1");
        client.subscribe(USER_MQTT_CLIENT_NAME"/color2");
        client.subscribe(USER_MQTT_CLIENT_NAME"/color3");
        client.subscribe(USER_MQTT_CLIENT_NAME"/power");
        client.subscribe(USER_MQTT_CLIENT_NAME"/brightness");
        client.subscribe(USER_MQTT_CLIENT_NAME"/addEffects");
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
  #ifdef ZONETWO
  maxLEDs = max(FIRSTZONE_LEDS, SECONDZONE_LEDS);
  #endif

  #ifdef ZONETHREE
  maxLEDs = max(maxLEDs, THIRDZONE_LEDS);
  #endif

  #ifdef ZONEFOUR
  maxLEDs = max(maxLEDs, FOURTHZONE_LEDS);
  #endif

  #ifdef ZONEFIVE
  maxLEDs = max(maxLEDs, FIFTHZONE_LEDS);
  #endif

  #ifdef ZONESIX
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
    
    #ifdef ZONEONE  
    fill_solid(firstZone, FIRSTZONE_LEDS, CRGB::Black); 
    #endif

    #ifdef ZONETWO
    fill_solid(secondZone, SECONDZONE_LEDS, CRGB::Black); 
    #endif

    #ifdef ZONETHREE
    fill_solid(thirdZone, THIRDZONE_LEDS, CRGB::Black);
    #endif

    #ifdef ZONEFOUR
    fill_solid(fourthZone, FOURTHZONE_LEDS, CRGB::Black);
    #endif

    #ifdef ZONEFIVE
    fill_solid(fifthZone, FIFTHZONE_LEDS, CRGB::Black); 
    #endif
    
    #ifdef ZONESIX
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
    client.publish(USER_MQTT_CLIENT_NAME "/color3State3", charPayload); 
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
  
  if (newTopic == USER_MQTT_CLIENT_NAME"/brightness") 
  {
    client.publish(USER_MQTT_CLIENT_NAME "/brightnessState", charPayload); 
    brightness = intPayload;
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
  if (newTopic == USER_MQTT_CLIENT_NAME"/modifier")
  {
    client.publish(USER_MQTT_CLIENT_NAME "/modifierState", charPayload); 
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
    #ifdef ZONEONE  
    RGB_firstZone();
    #endif

    #ifdef ZONETWO
    RGB_secondZone(); 
    #endif

    #ifdef ZONETHREE
    RGB_thirdZone();
    #endif

    #ifdef ZONEFOUR
    RGB_fourthZone();
    #endif

    #ifdef ZONEFIVE
    RGB_fifthZone();
    #endif
    
    #ifdef ZONESIX
    RGB_sixthZone();
    #endif 
      
   }
   if(effect == "Color_Glitter")
   {

    #ifdef ZONEONE  
    ColorGlitter_firstZone(glitterChance);
    #endif

    #ifdef ZONETWO
    ColorGlitter_secondZone(glitterChance); 
    #endif

    #ifdef ZONETHREE
    ColorGlitter_thirdZone(glitterChance);
    #endif

    #ifdef ZONEFOUR
    ColorGlitter_fourthZone(glitterChance);
    #endif

    #ifdef ZONEFIVE
    ColorGlitter_fifthZone(glitterChance);
    #endif
    
    #ifdef ZONESIX
    ColorGlitter_sixthZone(glitterChance);
    #endif  
   }
   if(effect == "Single_Race")
   {

    #ifdef ZONEONE  
    SingleRace_firstZone();
    #endif

    #ifdef ZONETWO
    SingleRace_secondZone(); 
    #endif

    #ifdef ZONETHREE
    SingleRace_thirdZone();
    #endif

    #ifdef ZONEFOUR
    SingleRace_fourthZone();
    #endif

    #ifdef ZONEFIVE
    SingleRace_fifthZone();
    #endif
    
    #ifdef ZONESIX
    SingleRace_sixthZone();
    #endif 
   }
   if(effect == "Double_Crash")
   {
    #ifdef ZONEONE  
    Crash_firstZone();
    #endif

    #ifdef ZONETWO
    Crash_secondZone(); 
    #endif

    #ifdef ZONETHREE
    Crash_thirdZone();
    #endif

    #ifdef ZONEFOUR
    Crash_fourthZone();
    #endif

    #ifdef ZONEFIVE
    Crash_fifthZone();
    #endif
    
    #ifdef ZONESIX
    Crash_sixthZone();
    #endif 
   }
   if(effect == "Rainbow")
   {
    #ifdef ZONEONE  
    Rainbow_firstZone();
    #endif

    #ifdef ZONETWO
    Rainbow_secondZone(); 
    #endif

    #ifdef ZONETHREE
    Rainbow_thirdZone();
    #endif

    #ifdef ZONEFOUR
    Rainbow_fourthZone();
    #endif

    #ifdef ZONEFIVE
    Rainbow_fifthZone();
    #endif
    
    #ifdef ZONESIX
    Rainbow_sixthZone();
    #endif 
   }
   if(effect == "Blocked_Colors")
   {
    #ifdef ZONEONE  
    Blocked_firstZone();
    #endif

    #ifdef ZONETWO
    Blocked_secondZone(); 
    #endif

    #ifdef ZONETHREE
    Blocked_thirdZone();
    #endif

    #ifdef ZONEFOUR
    Blocked_fourthZone();
    #endif

    #ifdef ZONEFIVE
    Blocked_fifthZone();
    #endif
    
    #ifdef ZONESIX
    Blocked_sixthZone();
    #endif 

   }
   if(effect == "BPM")
   {

    #ifdef ZONEONE  
    BPM_firstZone();
    #endif

    #ifdef ZONETWO
    BPM_secondZone(); 
    #endif

    #ifdef ZONETHREE
    BPM_thirdZone();
    #endif

    #ifdef ZONEFOUR
    BPM_fourthZone();
    #endif

    #ifdef ZONEFIVE
    BPM_fifthZone();
    #endif
    
    #ifdef ZONESIX
    BPM_sixthZone();
    #endif 
   }
   if(effect == "Twinkle")
   {
    #ifdef ZONEONE  
    Twinkle_firstZone();
    #endif

    #ifdef ZONETWO
    Twinkle_secondZone(); 
    #endif

    #ifdef ZONETHREE
    Twinkle_thirdZone();
    #endif

    #ifdef ZONEFOUR
    Twinkle_fourthZone();
    #endif

    #ifdef ZONEFIVE
    Twinkle_fifthZone();
    #endif
    
    #ifdef ZONESIX
    Twinkle_sixthZone();
    #endif 

   }
   if(effect == "Fill_Solid")
   {
    #ifdef ZONEONE  
    Solid_firstZone();
    #endif

    #ifdef ZONETWO
    Solid_secondZone(); 
    #endif

    #ifdef ZONETHREE
    Solid_thirdZone();
    #endif

    #ifdef ZONEFOUR
    Solid_fourthZone();
    #endif

    #ifdef ZONEFIVE
    Solid_fifthZone();
    #endif
    
    #ifdef ZONESIX
    Solid_sixthZone();
    #endif
    
   }
   if(effect == "Spooky_Eyes")
   {
    #ifdef ZONEONE  
    Eyes_firstZone();
    #endif

    #ifdef ZONETWO
    Eyes_secondZone(); 
    #endif

    #ifdef ZONETHREE
    Eyes_thirdZone();
    #endif

    #ifdef ZONEFOUR
    Eyes_fourthZone();
    #endif

    #ifdef ZONEFIVE
    Eyes_fifthZone();
    #endif
    
    #ifdef ZONESIX
    Eyes_sixthZone();
    #endif

   }
   
   if(effect == "LED_Locator")
   {
    #ifdef ZONEONE  
    Locator_firstZone();
    #endif

    #ifdef ZONETWO
    Locator_secondZone(); 
    #endif

    #ifdef ZONETHREE
    Locator_thirdZone();
    #endif

    #ifdef ZONEFOUR
    Locator_fourthZone();
    #endif

    #ifdef ZONEFIVE
    Locator_fifthZone();
    #endif
    
    #ifdef ZONESIX
    Locator_sixthZone();
    #endif

   }
   if(effect == "Ripple")
   {

    #ifdef ZONEONE  
    Ripple_firstZone();
    #endif

    #ifdef ZONETWO
    Ripple_secondZone(); 
    #endif

    #ifdef ZONETHREE
    Ripple_thirdZone();
    #endif

    #ifdef ZONEFOUR
    Ripple_fourthZone();
    #endif

    #ifdef ZONEFIVE
    Ripple_fifthZone();
    #endif
    
    #ifdef ZONESIX
    Ripple_sixthZone();
    #endif
   }
  }
  if(showLights == false)
  {
    #ifdef ZONEONE  
    fill_solid(firstZone, FIRSTZONE_LEDS, CRGB::Black); 
    #endif

    #ifdef ZONETWO
    fill_solid(secondZone, SECONDZONE_LEDS, CRGB::Black); 
    #endif

    #ifdef ZONETHREE
    fill_solid(thirdZone, THIRDZONE_LEDS, CRGB::Black);
    #endif

    #ifdef ZONEFOUR
    fill_solid(fourthZone, FOURTHZONE_LEDS, CRGB::Black);
    #endif

    #ifdef ZONEFIVE
    fill_solid(fifthZone, FIFTHZONE_LEDS, CRGB::Black); 
    #endif
    
    #ifdef ZONESIX
    fill_solid(sixthZone, SIXTHZONE_LEDS, CRGB::Black);
    #endif
  }
  addGlitter(100);
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
    #ifdef ZONEONE  
    fadeToBlackBy(firstZone, FIRSTZONE_LEDS, 1); 
    #endif

    #ifdef ZONETWO
    fadeToBlackBy(secondZone, SECONDZONE_LEDS, 1); 
    #endif

    #ifdef ZONETHREE
    fadeToBlackBy(thirdZone, THIRDZONE_LEDS, 1);
    #endif

    #ifdef ZONEFOUR
    fadeToBlackBy(fourthZone, FOURTHZONE_LEDS, 1);
    #endif

    #ifdef ZONEFIVE
    fadeToBlackBy(fifthZone, FIFTHZONE_LEDS, 1); 
    #endif
    
    #ifdef ZONESIX
    fadeToBlackBy(sixthZone, SIXTHZONE_LEDS, 1);
    #endif
    
    unsigned int chance = random8();
    if( chance == 255) 
    {
      #ifdef ZONEONE  
      fill_solid(firstZone, FIRSTZONE_LEDS, CRGB::White); 
      #endif
  
      #ifdef ZONETWO
      fill_solid(secondZone, SECONDZONE_LEDS, CRGB::White); 
      #endif
  
      #ifdef ZONETHREE
      fill_solid(thirdZone, THIRDZONE_LEDS, CRGB::White);
      #endif
  
      #ifdef ZONEFOUR
      fill_solid(fourthZone, FOURTHZONE_LEDS, CRGB::White);
      #endif
  
      #ifdef ZONEFIVE
      fill_solid(fifthZone, FIFTHZONE_LEDS, CRGB::White); 
      #endif
      
      #ifdef ZONESIX
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
        #ifdef ZONEONE  
        fadeToBlackBy(firstZone, FIRSTZONE_LEDS, 150); 
        #endif
    
        #ifdef ZONETWO
        fadeToBlackBy(secondZone, SECONDZONE_LEDS, 150); 
        #endif
    
        #ifdef ZONETHREE
        fadeToBlackBy(thirdZone, THIRDZONE_LEDS, 150);
        #endif
    
        #ifdef ZONEFOUR
        fadeToBlackBy(fourthZone, FOURTHZONE_LEDS, 150);
        #endif
    
        #ifdef ZONEFIVE
        fadeToBlackBy(fifthZone, FIFTHZONE_LEDS, 150); 
        #endif
        
        #ifdef ZONESIX
        fadeToBlackBy(sixthZone, SIXTHZONE_LEDS, 150);
        #endif

        lightning--;
      }
      if(lightning == 15)
      {

        #ifdef ZONEONE  
        fill_solid(firstZone, FIRSTZONE_LEDS, CRGB::White); 
        #endif
    
        #ifdef ZONETWO
        fill_solid(secondZone, SECONDZONE_LEDS, CRGB::White); 
        #endif
    
        #ifdef ZONETHREE
        fill_solid(thirdZone, THIRDZONE_LEDS, CRGB::White);
        #endif
    
        #ifdef ZONEFOUR
        fill_solid(fourthZone, FOURTHZONE_LEDS, CRGB::White);
        #endif
    
        #ifdef ZONEFIVE
        fill_solid(fifthZone, FIFTHZONE_LEDS, CRGB::White); 
        #endif
        
        #ifdef ZONESIX
        fill_solid(sixthZone, SIXTHZONE_LEDS, CRGB::White);
        #endif
        lightning--; 
      }
      if(lightning > 5 && lightning < 15)
      {
        #ifdef ZONEONE  
        fadeToBlackBy(firstZone, FIRSTZONE_LEDS, 150); 
        #endif
    
        #ifdef ZONETWO
        fadeToBlackBy(secondZone, SECONDZONE_LEDS, 150); 
        #endif
    
        #ifdef ZONETHREE
        fadeToBlackBy(thirdZone, THIRDZONE_LEDS, 150);
        #endif
    
        #ifdef ZONEFOUR
        fadeToBlackBy(fourthZone, FOURTHZONE_LEDS, 150);
        #endif
    
        #ifdef ZONEFIVE
        fadeToBlackBy(fifthZone, FIFTHZONE_LEDS, 150); 
        #endif
        
        #ifdef ZONESIX
        fadeToBlackBy(sixthZone, SIXTHZONE_LEDS, 150);
        #endif
        lightning--;
      }
      if(lightning == 5)
      {
        #ifdef ZONEONE  
        fill_solid(firstZone, FIRSTZONE_LEDS, CRGB::White); 
        #endif
    
        #ifdef ZONETWO
        fill_solid(secondZone, SECONDZONE_LEDS, CRGB::White); 
        #endif
    
        #ifdef ZONETHREE
        fill_solid(thirdZone, THIRDZONE_LEDS, CRGB::White);
        #endif
    
        #ifdef ZONEFOUR
        fill_solid(fourthZone, FOURTHZONE_LEDS, CRGB::White);
        #endif
    
        #ifdef ZONEFIVE
        fill_solid(fifthZone, FIFTHZONE_LEDS, CRGB::White); 
        #endif
        
        #ifdef ZONESIX
        fill_solid(sixthZone, SIXTHZONE_LEDS, CRGB::White);
        #endif
        lightning--; 
      }
      if(lightning > 0 && lightning < 5)
      {
        #ifdef ZONEONE  
        fadeToBlackBy(firstZone, FIRSTZONE_LEDS, 150); 
        #endif
    
        #ifdef ZONETWO
        fadeToBlackBy(secondZone, SECONDZONE_LEDS, 150); 
        #endif
    
        #ifdef ZONETHREE
        fadeToBlackBy(thirdZone, THIRDZONE_LEDS, 150);
        #endif
    
        #ifdef ZONEFOUR
        fadeToBlackBy(fourthZone, FOURTHZONE_LEDS, 150);
        #endif
    
        #ifdef ZONEFIVE
        fadeToBlackBy(fifthZone, FIFTHZONE_LEDS, 150); 
        #endif
        
        #ifdef ZONESIX
        fadeToBlackBy(sixthZone, SIXTHZONE_LEDS, 150);
        #endif
        lightning--;
      }
    }
  }
}

void addGlitter( fract8 chanceOfGlitter) 
{
  if(showGlitter == true)
  {
        #ifdef ZONEONE  
        if( random8() < chanceOfGlitter) 
        {
          firstZone[ random16(FIRSTZONE_LEDS) ] += CRGB::White;
        }
        #endif
    
        #ifdef ZONETWO
        {
          secondZone[ random16(SECONDZONE_LEDS) ] += CRGB::White;
        }
        #endif
    
        #ifdef ZONETHREE
        {
          thirdZone[ random16(THIRDZONE_LEDS) ] += CRGB::White;
        }
        #endif
    
        #ifdef ZONEFOUR
        {
          fourthZone[ random16(FOURTHZONE_LEDS) ] += CRGB::White;
        }
        #endif
    
        #ifdef ZONEFIVE
        {
          fifthZone[ random16(FIFTHZONE_LEDS) ] += CRGB::White;
        }
        #endif
        
        #ifdef ZONESIX
        {
          sixthZone[ random16(SIXTHZONE_LEDS) ] += CRGB::White;
        }
        #endif
        
    }
}

void setupZones()
{
    #ifdef ZONEONE  
    FastLED.addLeds<WS2812B, Pin_firstZone, FIRSTZONE_COLOR_ORDER>(firstZone, FIRSTZONE_LEDS);
    #endif

    #ifdef ZONETWO
    FastLED.addLeds<WS2812B, Pin_secondZone, SECONDZONE_COLOR_ORDER>(secondZone, SECONDZONE_LEDS);
    #endif

    #ifdef ZONETHREE
    FastLED.addLeds<WS2812B, Pin_thirdZone, THIRDZONE_COLOR_ORDER>(thirdZone, THIRDZONE_LEDS);
    #endif

    #ifdef ZONEFOUR
    FastLED.addLeds<WS2812B, Pin_fourthZone, FOURTHZONE_COLOR_ORDER>(fourthZone, FOURTHZONE_LEDS);
    #endif

    #ifdef ZONEFIVE
    FastLED.addLeds<WS2812B, Pin_fifthZone, FIFTHZONE_COLOR_ORDER>(fifthZone, FIFTHZONE_LEDS);
    #endif
    
    #ifdef ZONESIX
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

  #ifdef ZONEONE  
  FastLED[0].showLeds(brightness);
  #endif

  #ifdef ZONETWO
  FastLED[1].showLeds(brightness);
  #endif

  #ifdef ZONETHREE
  FastLED[2].showLeds(brightness);
  #endif

  #ifdef ZONEFOUR
  FastLED[3].showLeds(brightness);
  #endif

  #ifdef ZONEFIVE
  FastLED[4].showLeds(brightness);
  #endif
  
  #ifdef ZONESIX
  FastLED[5].showLeds(brightness);
  #endif
  
}



/*****************  firstZone Animations  ****************************************/
/*****************  firstZone Animations  ****************************************/
/*****************  firstZone Animations  ****************************************/
/*****************  firstZone Animations  ****************************************/
/*****************  firstZone Animations  ****************************************/

#ifdef ZONEONE  


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
  int pos_SECTION1 = beatsin8( raceSpeed, 0, (ZONEONE_SECTION1_START - ZONEONE_SECTION1_END) );
  firstZone[ZONEONE_SECTION1_START + pos_SECTION1] = CRGB(red1,green1,blue1);
  firstZone[ZONEONE_SECTION1_END - pos_SECTION1] = CRGB(red2,green2,blue2);
  #endif

  #ifdef ZONEONE_SECTION2_START
  int pos_SECTION2 = beatsin8( raceSpeed, 0, (ZONEONE_SECTION2_START - ZONEONE_SECTION2_END) );
  firstZone[ZONEONE_SECTION2_START + pos_SECTION2] = CRGB(red1,green1,blue1);
  firstZone[ZONEONE_SECTION2_END - pos_SECTION2] = CRGB(red2,green2,blue2);
  #endif
  
  #ifdef ZONEONE_SECTION3_START
  int pos_SECTION3 = beatsin8( raceSpeed, 0, (ZONEONE_SECTION3_START - ZONEONE_SECTION3_END) );
  firstZone[ZONEONE_SECTION3_START + pos_SECTION3] = CRGB(red1,green1,blue1);
  firstZone[ZONEONE_SECTION3_END - pos_SECTION3] = CRGB(red2,green2,blue2);
  #endif
  
  #ifdef ZONEONE_SECTION4_START
  int pos_SECTION4 = beatsin8( raceSpeed, 0, (ZONEONE_SECTION4_START - ZONEONE_SECTION4_END) );
  firstZone[ZONEONE_SECTION4_START + pos_SECTION4] = CRGB(red1,green1,blue1);
  firstZone[ZONEONE_SECTION4_END - pos_SECTION4] = CRGB(red2,green2,blue2);
  #endif
  
  #ifdef ZONEONE_SECTION5_START
  int pos_SECTION5 = beatsin8( raceSpeed, 0, (ZONEONE_SECTION5_START - ZONEONE_SECTION5_END) );
  firstZone[ZONEONE_SECTION5_START + pos_SECTION5] = CRGB(red1,green1,blue1);
  firstZone[ZONEONE_SECTION5_END - pos_SECTION5] = CRGB(red2,green2,blue2);
  #endif
  
  #ifdef ZONEONE_SECTION6_START
  int pos_SECTION6 = beatsin8( raceSpeed, 0, (ZONEONE_SECTION6_START - ZONEONE_SECTION6_END) );
  firstZone[ZONEONE_SECTION6_START + pos_SECTION6] = CRGB(red1,green1,blue1);
  firstZone[ZONEONE_SECTION6_END - pos_SECTION6] = CRGB(red2,green2,blue2);
  #endif
  
  #ifdef ZONEONE_SECTION7_START
  int pos_SECTION7 = beatsin8( raceSpeed, 0, (ZONEONE_SECTION7_START - ZONEONE_SECTION7_END) );
  firstZone[ZONEONE_SECTION7_START + pos_SECTION7] = CRGB(red1,green1,blue1);
  firstZone[ZONEONE_SECTION7_END - pos_SECTION7] = CRGB(red2,green2,blue2);
  #endif
  
  #ifdef ZONEONE_SECTION8_START
  int pos_SECTION8 = beatsin8( raceSpeed, 0, (ZONEONE_SECTION8_START - ZONEONE_SECTION8_END) );
  firstZone[ZONEONE_SECTION8_START + pos_SECTION8] = CRGB(red1,green1,blue1);
  firstZone[ZONEONE_SECTION8_END - pos_SECTION8] = CRGB(red2,green2,blue2);
  #endif
  
  #ifdef ZONEONE_SECTION9_START
  int pos_SECTION9 = beatsin8( raceSpeed, 0, (ZONEONE_SECTION9_START - ZONEONE_SECTION9_END) );
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
    uint8_t beat = beatsin8( BeatsPerMinute, 64, 255);
    for( int i = 0; i < FIRSTZONE_LEDS; i++) 
    {
      firstZone[i] = ColorFromPalette(palette_firstZone, gHue+(i*2), beat-gHue+(i*10));
    } 
  }
  if((green1*2) > (red1 + blue1))
  {
    CRGBPalette16 palette_firstZone = ForestColors_p; 
    uint8_t beat = beatsin8( BeatsPerMinute, 64, 255);
    for( int i = 0; i < FIRSTZONE_LEDS; i++) 
    {
      firstZone[i] = ColorFromPalette(palette_firstZone, gHue+(i*2), beat-gHue+(i*10));
    } 
  }
  if((blue1*2) > (green1 + red1))
  {
    CRGBPalette16 palette_firstZone = CloudColors_p; 
    uint8_t beat = beatsin8( BeatsPerMinute, 64, 255);
    for( int i = 0; i < FIRSTZONE_LEDS; i++) 
    {
      firstZone[i] = ColorFromPalette(palette_firstZone, gHue+(i*2), beat-gHue+(i*10));
    } 
  }
  if((blue1*2) == (green1 + red1))
  {
    CRGBPalette16 palette_firstZone = PartyColors_p; 
    uint8_t beat = beatsin8( BeatsPerMinute, 64, 255);
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

#endif

/*****************  secondZone Animations  ****************************************/
/*****************  secondZone Animations  ****************************************/
/*****************  secondZone Animations  ****************************************/
/*****************  secondZone Animations  ****************************************/
/*****************  secondZone Animations  ****************************************/

#ifdef ZONETWO  

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
  int pos_SECTION1 = beatsin8( raceSpeed, 0, (ZONETWO_SECTION1_START - ZONETWO_SECTION1_END) );
  secondZone[ZONETWO_SECTION1_START + pos_SECTION1] = CRGB(red1,green1,blue1);
  secondZone[ZONETWO_SECTION1_END - pos_SECTION1] = CRGB(red2,green2,blue2);
  #endif

  #ifdef ZONETWO_SECTION2_START
  int pos_SECTION2 = beatsin8( raceSpeed, 0, (ZONETWO_SECTION2_START - ZONETWO_SECTION2_END) );
  secondZone[ZONETWO_SECTION2_START + pos_SECTION2] = CRGB(red1,green1,blue1);
  secondZone[ZONETWO_SECTION2_END - pos_SECTION2] = CRGB(red2,green2,blue2);
  #endif
  
  #ifdef ZONETWO_SECTION3_START
  int pos_SECTION3 = beatsin8( raceSpeed, 0, (ZONETWO_SECTION3_START - ZONETWO_SECTION3_END) );
  secondZone[ZONETWO_SECTION3_START + pos_SECTION3] = CRGB(red1,green1,blue1);
  secondZone[ZONETWO_SECTION3_END - pos_SECTION3] = CRGB(red2,green2,blue2);
  #endif
  
  #ifdef ZONETWO_SECTION4_START
  int pos_SECTION4 = beatsin8( raceSpeed, 0, (ZONETWO_SECTION4_START - ZONETWO_SECTION4_END) );
  secondZone[ZONETWO_SECTION4_START + pos_SECTION4] = CRGB(red1,green1,blue1);
  secondZone[ZONETWO_SECTION4_END - pos_SECTION4] = CRGB(red2,green2,blue2);
  #endif
  
  #ifdef ZONETWO_SECTION5_START
  int pos_SECTION5 = beatsin8( raceSpeed, 0, (ZONETWO_SECTION5_START - ZONETWO_SECTION5_END) );
  secondZone[ZONETWO_SECTION5_START + pos_SECTION5] = CRGB(red1,green1,blue1);
  secondZone[ZONETWO_SECTION5_END - pos_SECTION5] = CRGB(red2,green2,blue2);
  #endif
  
  #ifdef ZONETWO_SECTION6_START
  int pos_SECTION6 = beatsin8( raceSpeed, 0, (ZONETWO_SECTION6_START - ZONETWO_SECTION6_END) );
  secondZone[ZONETWO_SECTION6_START + pos_SECTION6] = CRGB(red1,green1,blue1);
  secondZone[ZONETWO_SECTION6_END - pos_SECTION6] = CRGB(red2,green2,blue2);
  #endif
  
  #ifdef ZONETWO_SECTION7_START
  int pos_SECTION7 = beatsin8( raceSpeed, 0, (ZONETWO_SECTION7_START - ZONETWO_SECTION7_END) );
  secondZone[ZONETWO_SECTION7_START + pos_SECTION7] = CRGB(red1,green1,blue1);
  secondZone[ZONETWO_SECTION7_END - pos_SECTION7] = CRGB(red2,green2,blue2);
  #endif
  
  #ifdef ZONETWO_SECTION8_START
  int pos_SECTION8 = beatsin8( raceSpeed, 0, (ZONETWO_SECTION8_START - ZONETWO_SECTION8_END) );
  secondZone[ZONETWO_SECTION8_START + pos_SECTION8] = CRGB(red1,green1,blue1);
  secondZone[ZONETWO_SECTION8_END - pos_SECTION8] = CRGB(red2,green2,blue2);
  #endif
  
  #ifdef ZONETWO_SECTION9_START
  int pos_SECTION9 = beatsin8( raceSpeed, 0, (ZONETWO_SECTION9_START - ZONETWO_SECTION9_END) );
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
    uint8_t beat = beatsin8( BeatsPerMinute, 64, 255);
    for( int i = 0; i < SECONDZONE_LEDS; i++) 
    {
      secondZone[i] = ColorFromPalette(palette_secondZone, gHue+(i*2), beat-gHue+(i*10));
    } 
  }
  if((green1*2) > (red1 + blue1))
  {
    CRGBPalette16 palette_secondZone = ForestColors_p; 
    uint8_t beat = beatsin8( BeatsPerMinute, 64, 255);
    for( int i = 0; i < SECONDZONE_LEDS; i++) 
    {
      secondZone[i] = ColorFromPalette(palette_secondZone, gHue+(i*2), beat-gHue+(i*10));
    } 
  }
  if((blue1*2) > (green1 + red1))
  {
    CRGBPalette16 palette_secondZone = CloudColors_p; 
    uint8_t beat = beatsin8( BeatsPerMinute, 64, 255);
    for( int i = 0; i < SECONDZONE_LEDS; i++) 
    {
      secondZone[i] = ColorFromPalette(palette_secondZone, gHue+(i*2), beat-gHue+(i*10));
    } 
  }
  if((blue1*2) == (green1 + red1))
  {
    CRGBPalette16 palette_secondZone = PartyColors_p; 
    uint8_t beat = beatsin8( BeatsPerMinute, 64, 255);
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

#endif

/*****************  thirdZone Animations  ****************************************/
/*****************  thirdZone Animations  ****************************************/
/*****************  thirdZone Animations  ****************************************/
/*****************  thirdZone Animations  ****************************************/
/*****************  thirdZone Animations  ****************************************/

#ifdef ZONETHREE

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
  int pos_SECTION1 = beatsin8( raceSpeed, 0, (ZONETHREE_SECTION1_START - ZONETHREE_SECTION1_END) );
  thirdZone[ZONETHREE_SECTION1_START + pos_SECTION1] = CRGB(red1,green1,blue1);
  thirdZone[ZONETHREE_SECTION1_END - pos_SECTION1] = CRGB(red2,green2,blue2);
  #endif

  #ifdef ZONETHREE_SECTION2_START
  int pos_SECTION2 = beatsin8( raceSpeed, 0, (ZONETHREE_SECTION2_START - ZONETHREE_SECTION2_END) );
  thirdZone[ZONETHREE_SECTION2_START + pos_SECTION2] = CRGB(red1,green1,blue1);
  thirdZone[ZONETHREE_SECTION2_END - pos_SECTION2] = CRGB(red2,green2,blue2);
  #endif
  
  #ifdef ZONETHREE_SECTION3_START
  int pos_SECTION3 = beatsin8( raceSpeed, 0, (ZONETHREE_SECTION3_START - ZONETHREE_SECTION3_END) );
  thirdZone[ZONETHREE_SECTION3_START + pos_SECTION3] = CRGB(red1,green1,blue1);
  thirdZone[ZONETHREE_SECTION3_END - pos_SECTION3] = CRGB(red2,green2,blue2);
  #endif
  
  #ifdef ZONETHREE_SECTION4_START
  int pos_SECTION4 = beatsin8( raceSpeed, 0, (ZONETHREE_SECTION4_START - ZONETHREE_SECTION4_END) );
  thirdZone[ZONETHREE_SECTION4_START + pos_SECTION4] = CRGB(red1,green1,blue1);
  thirdZone[ZONETHREE_SECTION4_END - pos_SECTION4] = CRGB(red2,green2,blue2);
  #endif
  
  #ifdef ZONETHREE_SECTION5_START
  int pos_SECTION5 = beatsin8( raceSpeed, 0, (ZONETHREE_SECTION5_START - ZONETHREE_SECTION5_END) );
  thirdZone[ZONETHREE_SECTION5_START + pos_SECTION5] = CRGB(red1,green1,blue1);
  thirdZone[ZONETHREE_SECTION5_END - pos_SECTION5] = CRGB(red2,green2,blue2);
  #endif
  
  #ifdef ZONETHREE_SECTION6_START
  int pos_SECTION6 = beatsin8( raceSpeed, 0, (ZONETHREE_SECTION6_START - ZONETHREE_SECTION6_END) );
  thirdZone[ZONETHREE_SECTION6_START + pos_SECTION6] = CRGB(red1,green1,blue1);
  thirdZone[ZONETHREE_SECTION6_END - pos_SECTION6] = CRGB(red2,green2,blue2);
  #endif
  
  #ifdef ZONETHREE_SECTION7_START
  int pos_SECTION7 = beatsin8( raceSpeed, 0, (ZONETHREE_SECTION7_START - ZONETHREE_SECTION7_END) );
  thirdZone[ZONETHREE_SECTION7_START + pos_SECTION7] = CRGB(red1,green1,blue1);
  thirdZone[ZONETHREE_SECTION7_END - pos_SECTION7] = CRGB(red2,green2,blue2);
  #endif
  
  #ifdef ZONETHREE_SECTION8_START
  int pos_SECTION8 = beatsin8( raceSpeed, 0, (ZONETHREE_SECTION8_START - ZONETHREE_SECTION8_END) );
  thirdZone[ZONETHREE_SECTION8_START + pos_SECTION8] = CRGB(red1,green1,blue1);
  thirdZone[ZONETHREE_SECTION8_END - pos_SECTION8] = CRGB(red2,green2,blue2);
  #endif
  
  #ifdef ZONETHREE_SECTION9_START
  int pos_SECTION9 = beatsin8( raceSpeed, 0, (ZONETHREE_SECTION9_START - ZONETHREE_SECTION9_END) );
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
    uint8_t beat = beatsin8( BeatsPerMinute, 64, 255);
    for( int i = 0; i < THIRDZONE_LEDS; i++) 
    {
      thirdZone[i] = ColorFromPalette(palette_thirdZone, gHue+(i*2), beat-gHue+(i*10));
    } 
  }
  if((green1*2) > (red1 + blue1))
  {
    CRGBPalette16 palette_thirdZone = ForestColors_p; 
    uint8_t beat = beatsin8( BeatsPerMinute, 64, 255);
    for( int i = 0; i < THIRDZONE_LEDS; i++) 
    {
      thirdZone[i] = ColorFromPalette(palette_thirdZone, gHue+(i*2), beat-gHue+(i*10));
    } 
  }
  if((blue1*2) > (green1 + red1))
  {
    CRGBPalette16 palette_thirdZone = CloudColors_p; 
    uint8_t beat = beatsin8( BeatsPerMinute, 64, 255);
    for( int i = 0; i < THIRDZONE_LEDS; i++) 
    {
      thirdZone[i] = ColorFromPalette(palette_thirdZone, gHue+(i*2), beat-gHue+(i*10));
    } 
  }
  if((blue1*2) == (green1 + red1))
  {
    CRGBPalette16 palette_thirdZone = PartyColors_p; 
    uint8_t beat = beatsin8( BeatsPerMinute, 64, 255);
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

#endif

/*****************  fourthZone Animations  ****************************************/
/*****************  fourthZone Animations  ****************************************/
/*****************  fourthZone Animations  ****************************************/
/*****************  fourthZone Animations  ****************************************/
/*****************  fourthZone Animations  ****************************************/

#ifdef ZONEFOUR

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
  int pos_SECTION1 = beatsin8( raceSpeed, 0, (ZONEFOUR_SECTION1_START - ZONEFOUR_SECTION1_END) );
  fourthZone[ZONEFOUR_SECTION1_START + pos_SECTION1] = CRGB(red1,green1,blue1);
  fourthZone[ZONEFOUR_SECTION1_END - pos_SECTION1] = CRGB(red2,green2,blue2);
  #endif

  #ifdef ZONEFOUR_SECTION2_START
  int pos_SECTION2 = beatsin8( raceSpeed, 0, (ZONEFOUR_SECTION2_START - ZONEFOUR_SECTION2_END) );
  fourthZone[ZONEFOUR_SECTION2_START + pos_SECTION2] = CRGB(red1,green1,blue1);
  fourthZone[ZONEFOUR_SECTION2_END - pos_SECTION2] = CRGB(red2,green2,blue2);
  #endif
  
  #ifdef ZONEFOUR_SECTION3_START
  int pos_SECTION3 = beatsin8( raceSpeed, 0, (ZONEFOUR_SECTION3_START - ZONEFOUR_SECTION3_END) );
  fourthZone[ZONEFOUR_SECTION3_START + pos_SECTION3] = CRGB(red1,green1,blue1);
  fourthZone[ZONEFOUR_SECTION3_END - pos_SECTION3] = CRGB(red2,green2,blue2);
  #endif
  
  #ifdef ZONEFOUR_SECTION4_START
  int pos_SECTION4 = beatsin8( raceSpeed, 0, (ZONEFOUR_SECTION4_START - ZONEFOUR_SECTION4_END) );
  fourthZone[ZONEFOUR_SECTION4_START + pos_SECTION4] = CRGB(red1,green1,blue1);
  fourthZone[ZONEFOUR_SECTION4_END - pos_SECTION4] = CRGB(red2,green2,blue2);
  #endif
  
  #ifdef ZONEFOUR_SECTION5_START
  int pos_SECTION5 = beatsin8( raceSpeed, 0, (ZONEFOUR_SECTION5_START - ZONEFOUR_SECTION5_END) );
  fourthZone[ZONEFOUR_SECTION5_START + pos_SECTION5] = CRGB(red1,green1,blue1);
  fourthZone[ZONEFOUR_SECTION5_END - pos_SECTION5] = CRGB(red2,green2,blue2);
  #endif
  
  #ifdef ZONEFOUR_SECTION6_START
  int pos_SECTION6 = beatsin8( raceSpeed, 0, (ZONEFOUR_SECTION6_START - ZONEFOUR_SECTION6_END) );
  fourthZone[ZONEFOUR_SECTION6_START + pos_SECTION6] = CRGB(red1,green1,blue1);
  fourthZone[ZONEFOUR_SECTION6_END - pos_SECTION6] = CRGB(red2,green2,blue2);
  #endif
  
  #ifdef ZONEFOUR_SECTION7_START
  int pos_SECTION7 = beatsin8( raceSpeed, 0, (ZONEFOUR_SECTION7_START - ZONEFOUR_SECTION7_END) );
  fourthZone[ZONEFOUR_SECTION7_START + pos_SECTION7] = CRGB(red1,green1,blue1);
  fourthZone[ZONEFOUR_SECTION7_END - pos_SECTION7] = CRGB(red2,green2,blue2);
  #endif
  
  #ifdef ZONEFOUR_SECTION8_START
  int pos_SECTION8 = beatsin8( raceSpeed, 0, (ZONEFOUR_SECTION8_START - ZONEFOUR_SECTION8_END) );
  fourthZone[ZONEFOUR_SECTION8_START + pos_SECTION8] = CRGB(red1,green1,blue1);
  fourthZone[ZONEFOUR_SECTION8_END - pos_SECTION8] = CRGB(red2,green2,blue2);
  #endif
  
  #ifdef ZONEFOUR_SECTION9_START
  int pos_SECTION9 = beatsin8( raceSpeed, 0, (ZONEFOUR_SECTION9_START - ZONEFOUR_SECTION9_END) );
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
    uint8_t beat = beatsin8( BeatsPerMinute, 64, 255);
    for( int i = 0; i < FOURTHZONE_LEDS; i++) 
    {
      fourthZone[i] = ColorFromPalette(palette_fourthZone, gHue+(i*2), beat-gHue+(i*10));
    } 
  }
  if((green1*2) > (red1 + blue1))
  {
    CRGBPalette16 palette_fourthZone = ForestColors_p; 
    uint8_t beat = beatsin8( BeatsPerMinute, 64, 255);
    for( int i = 0; i < FOURTHZONE_LEDS; i++) 
    {
      fourthZone[i] = ColorFromPalette(palette_fourthZone, gHue+(i*2), beat-gHue+(i*10));
    } 
  }
  if((blue1*2) > (green1 + red1))
  {
    CRGBPalette16 palette_fourthZone = CloudColors_p; 
    uint8_t beat = beatsin8( BeatsPerMinute, 64, 255);
    for( int i = 0; i < FOURTHZONE_LEDS; i++) 
    {
      fourthZone[i] = ColorFromPalette(palette_fourthZone, gHue+(i*2), beat-gHue+(i*10));
    } 
  }
  if((blue1*2) == (green1 + red1))
  {
    CRGBPalette16 palette_fourthZone = PartyColors_p; 
    uint8_t beat = beatsin8( BeatsPerMinute, 64, 255);
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

#endif

/*****************  fifthZone Animations  ****************************************/
/*****************  fifthZone Animations  ****************************************/
/*****************  fifthZone Animations  ****************************************/
/*****************  fifthZone Animations  ****************************************/
/*****************  fifthZone Animations  ****************************************/

#ifdef ZONEFIVE

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
  int pos_SECTION1 = beatsin8( raceSpeed, 0, (ZONEFIVE_SECTION1_START - ZONEFIVE_SECTION1_END) );
  fifthZone[ZONEFIVE_SECTION1_START + pos_SECTION1] = CRGB(red1,green1,blue1);
  fifthZone[ZONEFIVE_SECTION1_END - pos_SECTION1] = CRGB(red2,green2,blue2);
  #endif

  #ifdef ZONEFIVE_SECTION2_START
  int pos_SECTION2 = beatsin8( raceSpeed, 0, (ZONEFIVE_SECTION2_START - ZONEFIVE_SECTION2_END) );
  fifthZone[ZONEFIVE_SECTION2_START + pos_SECTION2] = CRGB(red1,green1,blue1);
  fifthZone[ZONEFIVE_SECTION2_END - pos_SECTION2] = CRGB(red2,green2,blue2);
  #endif
  
  #ifdef ZONEFIVE_SECTION3_START
  int pos_SECTION3 = beatsin8( raceSpeed, 0, (ZONEFIVE_SECTION3_START - ZONEFIVE_SECTION3_END) );
  fifthZone[ZONEFIVE_SECTION3_START + pos_SECTION3] = CRGB(red1,green1,blue1);
  fifthZone[ZONEFIVE_SECTION3_END - pos_SECTION3] = CRGB(red2,green2,blue2);
  #endif
  
  #ifdef ZONEFIVE_SECTION4_START
  int pos_SECTION4 = beatsin8( raceSpeed, 0, (ZONEFIVE_SECTION4_START - ZONEFIVE_SECTION4_END) );
  fifthZone[ZONEFIVE_SECTION4_START + pos_SECTION4] = CRGB(red1,green1,blue1);
  fifthZone[ZONEFIVE_SECTION4_END - pos_SECTION4] = CRGB(red2,green2,blue2);
  #endif
  
  #ifdef ZONEFIVE_SECTION5_START
  int pos_SECTION5 = beatsin8( raceSpeed, 0, (ZONEFIVE_SECTION5_START - ZONEFIVE_SECTION5_END) );
  fifthZone[ZONEFIVE_SECTION5_START + pos_SECTION5] = CRGB(red1,green1,blue1);
  fifthZone[ZONEFIVE_SECTION5_END - pos_SECTION5] = CRGB(red2,green2,blue2);
  #endif
  
  #ifdef ZONEFIVE_SECTION6_START
  int pos_SECTION6 = beatsin8( raceSpeed, 0, (ZONEFIVE_SECTION6_START - ZONEFIVE_SECTION6_END) );
  fifthZone[ZONEFIVE_SECTION6_START + pos_SECTION6] = CRGB(red1,green1,blue1);
  fifthZone[ZONEFIVE_SECTION6_END - pos_SECTION6] = CRGB(red2,green2,blue2);
  #endif
  
  #ifdef ZONEFIVE_SECTION7_START
  int pos_SECTION7 = beatsin8( raceSpeed, 0, (ZONEFIVE_SECTION7_START - ZONEFIVE_SECTION7_END) );
  fifthZone[ZONEFIVE_SECTION7_START + pos_SECTION7] = CRGB(red1,green1,blue1);
  fifthZone[ZONEFIVE_SECTION7_END - pos_SECTION7] = CRGB(red2,green2,blue2);
  #endif
  
  #ifdef ZONEFIVE_SECTION8_START
  int pos_SECTION8 = beatsin8( raceSpeed, 0, (ZONEFIVE_SECTION8_START - ZONEFIVE_SECTION8_END) );
  fifthZone[ZONEFIVE_SECTION8_START + pos_SECTION8] = CRGB(red1,green1,blue1);
  fifthZone[ZONEFIVE_SECTION8_END - pos_SECTION8] = CRGB(red2,green2,blue2);
  #endif
  
  #ifdef ZONEFIVE_SECTION9_START
  int pos_SECTION9 = beatsin8( raceSpeed, 0, (ZONEFIVE_SECTION9_START - ZONEFIVE_SECTION9_END) );
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
    uint8_t beat = beatsin8( BeatsPerMinute, 64, 255);
    for( int i = 0; i < FIFTHZONE_LEDS; i++) 
    {
      fifthZone[i] = ColorFromPalette(palette_fifthZone, gHue+(i*2), beat-gHue+(i*10));
    } 
  }
  if((green1*2) > (red1 + blue1))
  {
    CRGBPalette16 palette_fifthZone = ForestColors_p; 
    uint8_t beat = beatsin8( BeatsPerMinute, 64, 255);
    for( int i = 0; i < FIFTHZONE_LEDS; i++) 
    {
      fifthZone[i] = ColorFromPalette(palette_fifthZone, gHue+(i*2), beat-gHue+(i*10));
    } 
  }
  if((blue1*2) > (green1 + red1))
  {
    CRGBPalette16 palette_fifthZone = CloudColors_p; 
    uint8_t beat = beatsin8( BeatsPerMinute, 64, 255);
    for( int i = 0; i < FIFTHZONE_LEDS; i++) 
    {
      fifthZone[i] = ColorFromPalette(palette_fifthZone, gHue+(i*2), beat-gHue+(i*10));
    } 
  }
  if((blue1*2) == (green1 + red1))
  {
    CRGBPalette16 palette_fifthZone = PartyColors_p; 
    uint8_t beat = beatsin8( BeatsPerMinute, 64, 255);
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

#endif

/*****************  sixthZone Animations  ****************************************/
/*****************  sixthZone Animations  ****************************************/
/*****************  sixthZone Animations  ****************************************/
/*****************  sixthZone Animations  ****************************************/
/*****************  sixthZone Animations  ****************************************/

#ifdef ZONESIX

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
  int pos_SECTION1 = beatsin8( raceSpeed, 0, (ZONESIX_SECTION1_START - ZONESIX_SECTION1_END) );
  sixthZone[ZONESIX_SECTION1_START + pos_SECTION1] = CRGB(red1,green1,blue1);
  sixthZone[ZONESIX_SECTION1_END - pos_SECTION1] = CRGB(red2,green2,blue2);
  #endif

  #ifdef ZONESIX_SECTION2_START
  int pos_SECTION2 = beatsin8( raceSpeed, 0, (ZONESIX_SECTION2_START - ZONESIX_SECTION2_END) );
  sixthZone[ZONESIX_SECTION2_START + pos_SECTION2] = CRGB(red1,green1,blue1);
  sixthZone[ZONESIX_SECTION2_END - pos_SECTION2] = CRGB(red2,green2,blue2);
  #endif
  
  #ifdef ZONESIX_SECTION3_START
  int pos_SECTION3 = beatsin8( raceSpeed, 0, (ZONESIX_SECTION3_START - ZONESIX_SECTION3_END) );
  sixthZone[ZONESIX_SECTION3_START + pos_SECTION3] = CRGB(red1,green1,blue1);
  sixthZone[ZONESIX_SECTION3_END - pos_SECTION3] = CRGB(red2,green2,blue2);
  #endif
  
  #ifdef ZONESIX_SECTION4_START
  int pos_SECTION4 = beatsin8( raceSpeed, 0, (ZONESIX_SECTION4_START - ZONESIX_SECTION4_END) );
  sixthZone[ZONESIX_SECTION4_START + pos_SECTION4] = CRGB(red1,green1,blue1);
  sixthZone[ZONESIX_SECTION4_END - pos_SECTION4] = CRGB(red2,green2,blue2);
  #endif
  
  #ifdef ZONESIX_SECTION5_START
  int pos_SECTION5 = beatsin8( raceSpeed, 0, (ZONESIX_SECTION5_START - ZONESIX_SECTION5_END) );
  sixthZone[ZONESIX_SECTION5_START + pos_SECTION5] = CRGB(red1,green1,blue1);
  sixthZone[ZONESIX_SECTION5_END - pos_SECTION5] = CRGB(red2,green2,blue2);
  #endif
  
  #ifdef ZONESIX_SECTION6_START
  int pos_SECTION6 = beatsin8( raceSpeed, 0, (ZONESIX_SECTION6_START - ZONESIX_SECTION6_END) );
  sixthZone[ZONESIX_SECTION6_START + pos_SECTION6] = CRGB(red1,green1,blue1);
  sixthZone[ZONESIX_SECTION6_END - pos_SECTION6] = CRGB(red2,green2,blue2);
  #endif
  
  #ifdef ZONESIX_SECTION7_START
  int pos_SECTION7 = beatsin8( raceSpeed, 0, (ZONESIX_SECTION7_START - ZONESIX_SECTION7_END) );
  sixthZone[ZONESIX_SECTION7_START + pos_SECTION7] = CRGB(red1,green1,blue1);
  sixthZone[ZONESIX_SECTION7_END - pos_SECTION7] = CRGB(red2,green2,blue2);
  #endif
  
  #ifdef ZONESIX_SECTION8_START
  int pos_SECTION8 = beatsin8( raceSpeed, 0, (ZONESIX_SECTION8_START - ZONESIX_SECTION8_END) );
  sixthZone[ZONESIX_SECTION8_START + pos_SECTION8] = CRGB(red1,green1,blue1);
  sixthZone[ZONESIX_SECTION8_END - pos_SECTION8] = CRGB(red2,green2,blue2);
  #endif
  
  #ifdef ZONESIX_SECTION9_START
  int pos_SECTION9 = beatsin8( raceSpeed, 0, (ZONESIX_SECTION9_START - ZONESIX_SECTION9_END) );
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
    uint8_t beat = beatsin8( BeatsPerMinute, 64, 255);
    for( int i = 0; i < SIXTHZONE_LEDS; i++) 
    {
      sixthZone[i] = ColorFromPalette(palette_sixthZone, gHue+(i*2), beat-gHue+(i*10));
    } 
  }
  if((green1*2) > (red1 + blue1))
  {
    CRGBPalette16 palette_sixthZone = ForestColors_p; 
    uint8_t beat = beatsin8( BeatsPerMinute, 64, 255);
    for( int i = 0; i < SIXTHZONE_LEDS; i++) 
    {
      sixthZone[i] = ColorFromPalette(palette_sixthZone, gHue+(i*2), beat-gHue+(i*10));
    } 
  }
  if((blue1*2) > (green1 + red1))
  {
    CRGBPalette16 palette_sixthZone = CloudColors_p; 
    uint8_t beat = beatsin8( BeatsPerMinute, 64, 255);
    for( int i = 0; i < SIXTHZONE_LEDS; i++) 
    {
      sixthZone[i] = ColorFromPalette(palette_sixthZone, gHue+(i*2), beat-gHue+(i*10));
    } 
  }
  if((blue1*2) == (green1 + red1))
  {
    CRGBPalette16 palette_sixthZone = PartyColors_p; 
    uint8_t beat = beatsin8( BeatsPerMinute, 64, 255);
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

#endif

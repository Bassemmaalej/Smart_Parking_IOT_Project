#include <LiquidCrystal_I2C.h>
#include <WiFi.h>
#include <PubSubClient.h>

const char* ssid = "Wokwi-GUEST";  
const char* password = ""; 
const char* mqtt_server="test.mosquitto.org";
WiFiClient espclient;
String temp_str; //see last code block below use these to convert the float that you get back from DHT
char temp[50];

String tempw_str; //see last code block below use these to convert the float that you get back from DHT
char tempw[50];

String temps_str; //see last code block below use these to convert the float that you get back from DHT
char temps[50];

String tempc_str; //see last code block below use these to convert the float that you get back from DHT
char tempc[50];

String tempv_str; //see last code block below use these to convert the float that you get back from DHT
char tempv[50];

String tempb_str; //see last code block below use these to convert the float that you get back from DHT
char tempb[50];

String tempn_str; //see last code block below use these to convert the float that you get back from DHT
char tempn[50];


String tempq_str; //see last code block below use these to convert the float that you get back from DHT
char tempq[50];

//--------------------------------------------------------
LiquidCrystal_I2C lcd (0x27,20,4); 
 

const int PIN_TO_SENSOR = 19;
const int PIN_TO_SENSOR1 = 13;
const int PIN_TO_SENSOR2 = 12;
const int PIN_TO_SENSOR3 = 14;
const int PIN_TO_SENSOR4 = 27;
const int PIN_TO_SENSOR5 = 26;
const int PIN_TO_SENSOR6 = 25;
const int PIN_TO_SENSOR7 = 33;
int pinStateCurrent0   = LOW;  
int pinStatePrevious0  = LOW;  
int pinStateCurrent1   = LOW;  
int pinStatePrevious1  = LOW;  
int pinStateCurrent2   = LOW;  
int pinStatePrevious2  = LOW;  
int pinStateCurrent3   = LOW;  
int pinStatePrevious3  = LOW;  
int pinStateCurrent4   = LOW;  
int pinStatePrevious4  = LOW;  
int pinStateCurrent5   = LOW;  
int pinStatePrevious5  = LOW;  
int pinStateCurrent6   = LOW;  
int pinStatePrevious6  = LOW;  
int pinStateCurrent7   = LOW;  
int pinStatePrevious7  = LOW;  
bool place1 = false;
bool place2 = false;
bool place3 = false;
bool place4 = false;
bool place5 = false;
bool place6 = false;
bool place7 = false;
bool place8 = false;
int a,z,e,r,t,y,u,i,w,x,c,v,b,n,q,s;
float temp_i,prix_a,prix_z,prix_e,prix_r,prix_t,prix_y,prix_u,prix_i;
const float prix_sec=0.3 ; 
int button1  = 0;
int button2  = LOW;
int button3  = 0;
int button4  = 0;
int button5  = 0;
int button6  = 0;
int button7  = 0;
int button8  = 0;
int button_sortir  = 0;
const int btn_place1 = 4;
const int btn_place2 = 16;
const int btn_place3 = 17;
const int btn_place4 = 18;
const int btn_place5 = 21;
const int btn_place6 = 23;
const int btn_place7 = 32;
const int btn_place8 = 6;
const int btn_place_sortir = 5;
//--------------------------------------------------------------------

//Preparing for mqtt receive
void callback(char* topic,byte* payload,unsigned int length1)
{    
Serial.print("message arrived[");
Serial.print(topic);
Serial.println("]");
for(int g=0;g<length1;g++){
  Serial.print(payload[g]); 
  if(payload[0]==49) 
    {digitalWrite(btn_place1,HIGH);    
    Serial.print("place1");}//ASCII VALUE OF '1' IS 49
  else if(payload[0]==50)
    {digitalWrite(LED_BUILTIN,LOW);
    Serial.print("place1");}//ASCII VALUE OF '2' IS 50
  Serial.println();
}
for(int g=0;g<length1;g++){
  Serial.print(payload[g]); 
  if(payload[0]==49) 
    {digitalWrite(btn_place2,HIGH);    
    Serial.print("place1");}//ASCII VALUE OF '1' IS 49
  else if(payload[0]==50)
    {digitalWrite(btn_place2,LOW);
    Serial.print("place1");}//ASCII VALUE OF '2' IS 50
  Serial.println();
}
for(int g=0;g<length1;g++){
  Serial.print(payload[g]); 
  if(payload[0]==49) 
    {digitalWrite(btn_place3,HIGH);    
    Serial.print("place1");}//ASCII VALUE OF '1' IS 49
  else if(payload[0]==50)
    {digitalWrite(btn_place3,LOW);
    Serial.print("place1");}//ASCII VALUE OF '2' IS 50
  Serial.println();
}
for(int g=0;g<length1;g++){
  Serial.print(payload[g]); 
  if(payload[0]==49) 
    {digitalWrite(btn_place4,HIGH);    
    Serial.print("place1");}//ASCII VALUE OF '1' IS 49
  else if(payload[0]==50)
    {digitalWrite(btn_place4,LOW);
    Serial.print("place1");}//ASCII VALUE OF '2' IS 50
  Serial.println();
}
for(int g=0;g<length1;g++){
  Serial.print(payload[g]); 
  if(payload[0]==49) 
    {digitalWrite(btn_place5,HIGH);    
    Serial.print("place1");}//ASCII VALUE OF '1' IS 49
  else if(payload[0]==50)
    {digitalWrite(btn_place5,LOW);
    Serial.print("place1");}//ASCII VALUE OF '2' IS 50
  Serial.println();
}
for(int g=0;g<length1;g++){
  Serial.print(payload[g]); 
  if(payload[0]==49) 
    {digitalWrite(btn_place6,HIGH);    
    Serial.print("place1");}//ASCII VALUE OF '1' IS 49
  else if(payload[0]==50)
    {digitalWrite(btn_place6,LOW);
    Serial.print("place1");}//ASCII VALUE OF '2' IS 50
  Serial.println();
}
for(int g=0;g<length1;g++){
  Serial.print(payload[g]); 
  if(payload[0]==49) 
    {digitalWrite(btn_place7,HIGH);    
    Serial.print("place1");}//ASCII VALUE OF '1' IS 49
  else if(payload[0]==50)
    {digitalWrite(btn_place7,LOW);
    Serial.print("place1");}//ASCII VALUE OF '2' IS 50
  Serial.println();
}
for(int g=0;g<length1;g++){
  Serial.print(payload[g]); 
  if(payload[0]==49) 
    {digitalWrite(btn_place8,HIGH);    
    Serial.print("place1");}//ASCII VALUE OF '1' IS 49
  else if(payload[0]==50)
    {digitalWrite(btn_place8,LOW);
    Serial.print("place1");}//ASCII VALUE OF '2' IS 50
  Serial.println();
}
}

PubSubClient client(mqtt_server,1883,callback,espclient);



void reconnect(){
  while(WiFi.status()!=WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }
 }


void setup() {
// Connect to WIFI
  Serial.print("connecting to ");
  Serial.print(ssid);
  WiFi.begin(ssid,password);      
  while(WiFi.status()!=WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }
  Serial.println();


  //------------------------------------------------------------------
   Serial.begin(9600);  
  pinMode(PIN_TO_SENSOR, INPUT); 
  pinMode(PIN_TO_SENSOR1, INPUT);
  pinMode(PIN_TO_SENSOR2, INPUT); 
  pinMode(PIN_TO_SENSOR3, INPUT);
  pinMode(PIN_TO_SENSOR4, INPUT); 
  pinMode(PIN_TO_SENSOR5, INPUT);
  pinMode(PIN_TO_SENSOR6, INPUT); 
  pinMode(PIN_TO_SENSOR7, INPUT);
  pinMode(btn_place1, INPUT);
  pinMode(btn_place2, INPUT);
  pinMode(btn_place3, INPUT);
  pinMode(btn_place4, INPUT);
  pinMode(btn_place5, INPUT);
  pinMode(btn_place6, INPUT);
  pinMode(btn_place7, INPUT);
  pinMode(btn_place8, INPUT);
  pinMode(btn_place_sortir, INPUT);

  lcd. init ();
  lcd. backlight ();
  lcd. setCursor (3, 0);
  lcd. print ( "welcome" );
}

void loop() {

  pinStatePrevious0 = pinStateCurrent0; // store old state
  pinStateCurrent0 = digitalRead(PIN_TO_SENSOR);   // read new state
  pinStatePrevious1 = pinStateCurrent1; // store old state
  pinStateCurrent1 = digitalRead(PIN_TO_SENSOR1);   // read new state
  pinStatePrevious2 = pinStateCurrent2; // store old state
  pinStateCurrent2 = digitalRead(PIN_TO_SENSOR2);   // read new state
  pinStatePrevious3 = pinStateCurrent3; // store old state
  pinStateCurrent3 = digitalRead(PIN_TO_SENSOR3);   // read new state
  pinStatePrevious4 = pinStateCurrent4; // store old state
  pinStateCurrent4 = digitalRead(PIN_TO_SENSOR4);   // read new state
  pinStatePrevious5 = pinStateCurrent5; // store old state
  pinStateCurrent5 = digitalRead(PIN_TO_SENSOR5);   // read new state
  pinStatePrevious6 = pinStateCurrent6; // store old state
  pinStateCurrent6 = digitalRead(PIN_TO_SENSOR6);   // read new state
  pinStatePrevious7 = pinStateCurrent7; // store old state
  pinStateCurrent7 = digitalRead(PIN_TO_SENSOR7);   // read new state
//----------------------------------------------------------------------
  button1 = digitalRead(btn_place1);
  button2 = digitalRead(btn_place2);
  button3 = digitalRead(btn_place3);
  button4 = digitalRead(btn_place4);
  button5 = digitalRead(btn_place5);
  button6 = digitalRead(btn_place6);
  button7 = digitalRead(btn_place7);
  button8 = digitalRead(btn_place8);
  button_sortir = digitalRead(btn_place_sortir);

//------------------------------LED1------------------------------------
    if (pinStatePrevious0 == LOW && pinStateCurrent0 == HIGH) {   // pin state change: LOW -> HIGH
    place1 = not place1;
    Serial.println("place1 = ");
    Serial.println(place1); 
    i=0;
    }
    while(place1== HIGH){
     i=i+1;
     delay(10);
     prix_i=i*prix_sec;
     Serial.println(i);
     Serial.println(prix_i);
     break;
   }
   
   x=prix_i;
   if (place1== HIGH){
      lcd. setCursor (1, 1);
   // We write the number of seconds elapsed 
    lcd. print ( "x");
    delay (100);
   }
   else
   {lcd. setCursor (1, 1);
   // We write the number of seconds elapsed 
    lcd. print ( "o");
    delay (100);}
    if(button1== HIGH){
  Serial.println(x);
}


 
//----------------------------LED2------------------------------------
if (pinStatePrevious1 == LOW && pinStateCurrent1 == HIGH) {   // pin state change: LOW -> HIGH
    place2 = not place2;
    Serial.println("place1 = ");
    Serial.println(place2);
    a=0;
    }
    while(place2== HIGH){
     a=a+1;
     delay(100);
     prix_a=a*prix_sec;
     Serial.println(a);
     Serial.println(prix_a);
     break;
   }
   w=prix_a;
   if (place2== HIGH){
      lcd. setCursor (3, 1);
   // We write the number of seconds elapsed 
    lcd. print ( "x");
    delay (100);
   }
   else
   {lcd. setCursor (3, 1);
   // We write the number of seconds elapsed 
    lcd. print ( "o");
    delay (100);}
  if(button2 == HIGH){
  Serial.println(w);
  }
     

   
//----------------------------------LED3--------------------------------------
if (pinStatePrevious2 == LOW && pinStateCurrent2 == HIGH) {   // pin state change: LOW -> HIGH
    place3 = not place3;
   
    Serial.println("place1 = ");
    Serial.println(place3); 
   
    z=0;
    
    }
   if (place3== HIGH){
      lcd. setCursor (5, 1);
   // We write the number of seconds elapsed 
    lcd. print ( "x");
    delay (100);
   }
   else
   {lcd. setCursor (5, 1);
   // We write the number of seconds elapsed 
    lcd. print ( "o");
    delay (100);}

while(place3== HIGH){
     z=z+1;
     delay(100);
     prix_z=z*prix_sec;
     Serial.println(z);
     Serial.println(prix_z);
     break;
   }
   c=prix_z;
   if(button3 != HIGH){
  Serial.println(c);
  }
   
//------------------------------------LED4---------------------------------------
if (pinStatePrevious3 == LOW && pinStateCurrent3 == HIGH) {   // pin state change: LOW -> HIGH
    place4 = not place4;
    
    Serial.println("place1 = ");
    Serial.println(place4); 
   
    e=0;
    
    }
   if (place4== HIGH){
      lcd. setCursor (7, 1);
   // We write the number of seconds elapsed 
    lcd. print ( "x");
    delay (100);
   }
   else
   {lcd. setCursor (7, 1);
   // We write the number of seconds elapsed 
    lcd. print ( "o");
    delay (100);}

while(place4== HIGH){
     e=e+1;
     delay(100);
     prix_e=e*prix_sec;
     Serial.println(e);
     Serial.println(prix_e);
     break;
   }
   v=prix_e;
    if(button4 == HIGH){
  Serial.println(v);
  }
   
//----------------------------------------LED5----------------------------------------
if (pinStatePrevious4 == LOW && pinStateCurrent4 == HIGH) {   // pin state change: LOW -> HIGH
    place5 = not place5;
   
    Serial.println("place1 = ");
    Serial.println(place5); 
   
    r=0;
    
    }
   if (place5== HIGH){
      lcd. setCursor (1, 2);
   // We write the number of seconds elapsed 
    lcd. print ( "x");
    delay (100);
   }
   else
   {lcd. setCursor (1, 2);
   // We write the number of seconds elapsed 
    lcd. print ( "o");
    delay (100);}

while(place5== HIGH){
     r=r+1;
     delay(100);
     prix_r=r*prix_sec;
     Serial.println(r);
     Serial.println(prix_r);
     break;
   }
   b=prix_r;
    if(button5 != HIGH){
  Serial.println(b);
  }
   
//--------------------------------------LED6---------------------------------
if (pinStatePrevious5 == LOW && pinStateCurrent5 == HIGH) {   // pin state change: LOW -> HIGH
    place6 = not place6;
    
    Serial.println("place1 = ");
    Serial.println(place6); 
   
    t=0;
    
    }
   if (place6== HIGH){
      lcd. setCursor (3, 2);
   // We write the number of seconds elapsed 
    lcd. print ( "x");
    delay (100);
   }
   else
   {lcd. setCursor (3, 2);
   // We write the number of seconds elapsed 
    lcd. print ( "o");
    delay (100);}

while(place6== HIGH){
     t=t+1;
     delay(100);
     prix_t=t*prix_sec;
     Serial.println(t);
     Serial.println(prix_t);
     break;
   }
   n=prix_t;
   if(button6 == HIGH){
  Serial.println(n);
  }
  
//---------------------------------------LED7--------------------------------------
if (pinStatePrevious6 == LOW && pinStateCurrent6 == HIGH) {   // pin state change: LOW -> HIGH
    place7 = not place7;
    
    Serial.println("place1 = ");
    Serial.println(place7); 
   
    y=0;
    
    }
   if (place7== HIGH){
      lcd. setCursor (5, 2);
   // We write the number of seconds elapsed 
    lcd. print ( "x");
    delay (100);
   }
   else
   {lcd. setCursor (5, 2);
   // We write the number of seconds elapsed 
    lcd. print ( "o");
    delay (100);}

    while(place7== HIGH){
     y=y+1;
     delay(100);
     prix_y=y*prix_sec;
     Serial.println(y);
     Serial.println(prix_y);
     break;
   }
   q=prix_y;
   if(button7 == HIGH){
  Serial.println(q);
  }
   
//--------------------------------------LED7---------------------------------6
if (pinStatePrevious7 == LOW && pinStateCurrent7 == HIGH) {   // pin state change: LOW -> HIGH
    place8 = not place8;
    
    Serial.println("place1 = ");
    Serial.println(place8); 
   
    u=0;
    
    }
   if (place8== HIGH){
      lcd. setCursor (7, 2);
   // We write the number of seconds elapsed 
    lcd. print ( "x");
    delay (100);
   }
   else
   {lcd. setCursor (7, 2);
   // We write the number of seconds elapsed 
    lcd. print ( "o");
    delay (100);}

while(place8== HIGH){
     u=u+1;
     delay(100);
     prix_u=u*prix_sec;
     Serial.println(u);
     Serial.println(prix_u);
     break;
   }
   s=prix_u;
   if(button8 == HIGH){
  Serial.println(s);
  }

//---------------------------------------------------------------------
if (!client.connected()) {
    reconnect();
  }
  
  client.loop();
  
  delay(2000);
   temp_str = String(x); 
   temp_str.toCharArray(temp, temp_str.length() + 1); 
   tempw_str = String(w); 
   tempw_str.toCharArray(tempw, tempw_str.length() + 1); 
  
   temps_str = String(s); 
   temps_str.toCharArray(temps, temps_str.length() + 1); 
   tempc_str = String(c); 
   tempc_str.toCharArray(tempc, tempc_str.length() + 1);

   tempv_str = String(v); 
   tempv_str.toCharArray(tempv, tempv_str.length() + 1); 
   tempb_str = String(b); 
   tempb_str.toCharArray(tempb, tempb_str.length() + 1);

   tempn_str = String(n); 
   tempn_str.toCharArray(tempn, tempn_str.length() + 1); 
   tempq_str = String(q); 
   tempq_str.toCharArray(tempq, tempq_str.length() + 1);


  // Connect to Node-RED
  if(client.connect("ESP32test1")){
    Serial.println("Connected to Node-RED");
    client.subscribe("Control");
    
    client.publish("data",temp);
    client.publish("data1",tempw);
    client.publish("data2",temps);
    client.publish("data3",tempc);
    client.publish("data4",tempv);
    client.publish("data5",tempb);
    client.publish("data6",tempn);
    client.publish("data7",tempq);
    

      }
   else{
      Serial.print("failed,rc=");
      Serial.println(client.state());
      delay(500);
    }
//--------------------------------------------------------------


}

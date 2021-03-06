
#include <ESP8266WiFi.h>

 
#define led 2 //发光二极管连接在8266的GPIO2上

const char *ssid     = "IR613z";//这里写入网络的ssid

const char *password = "613613613";//wifi密码

const char *host = "192.168.1.105";//修改为Server服务端的IP，即你电脑的IP，确保在同一网络之下。

 

WiFiClient client;

const int tcpPort = 1010;//修改为你建立的Server服务端的端口号，此端口号是创建服务器时指定的。
void setup()
{
    Serial.begin(115200);    
    pinMode(led,OUTPUT);
    delay(10);
    Serial.println();
    Serial.print("Connecting to ");//会通过usb转tll模块发送到电脑，通过ide集成的串口监视器可以获取数据。
    Serial.println(ssid);
    WiFi.begin(ssid, password);//启动
     //在这里检测是否成功连接到目标网络，未连接则阻塞。
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
    }
 //几句提示
    Serial.println("");
    Serial.println("WiFi connected");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());
}

void loop()
{
    while (!client.connected())//若未连接到服务端，则客户端进行连接。
    {
        if (!client.connect(host, tcpPort))//实际上这一步就在连接服务端，如果连接上，该函数返回true
        {
            Serial.println("connection....");
            delay(500);
        }
    }


    while (client.available())//available()表示是否可以获取到数据
    {
        char val = client.read();//read()表示从网络中读取数据。
        if(val=='L'){
           client.println("LEFT");
        }
        if(val=='R')
        {
           client.println("RIGHT");
        }
        if(val=='H'){
           client.println("FORWARD");
        }
        if(val=='B')
        {
           client.println("BACK");
        }
        if(val=='S'){
           client.println("STOP");
        }
        Serial.println(val);
    }
}


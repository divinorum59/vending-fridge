#include "SoundData3.h"
#include "XT_DAC_Audio.h"
#include "BluetoothSerial.h"
BluetoothSerial SerialBT;
#include <Preferences.h>
Preferences prefs;
#include <LCD_1602_RUS.h>
LCD_1602_RUS lcd(0x27, 20, 4);
#include <Keypad.h>
#include "GyverButton.h"
#include "GyverTimer.h"
#include "HardwareSerial.h"
#define RXD1 16 //RX1 pin
#define TXD1 17 //TX1 pin
//BluetoothSerial SerialBT;
#define PIN34 34
GButton butt(PIN34);

//переменные для программирования по bluetooth начало
int a3 = 0; //переменная для программирования по bt
String strData = "";
String enter = "введите новое значение";
String enter2 = "новое значение = ";
String enter3 = "время закрытия замка = ";

int paystat = 0;
boolean result = false;
boolean recievedFlag;

boolean choiseflag = false;
boolean choiseflag10 = false;
boolean choiseflag11 = false;
boolean choiseflag12 = false;
boolean choiseflag13 = false;
boolean choiseflag14 = false;
boolean choiseflag15 = false;
boolean choiseflag16 = false;
boolean choiseflag17 = false;
boolean choiseflag18 = false;
boolean choiseflag19 = false;
boolean choiseflag20 = false;
boolean choiseflag21 = false;
boolean choiseflag22 = false;
boolean choiseflag23 = false;
boolean choiseflag24 = false;
boolean choiseflag25 = false;
boolean choiseflag26 = false;
boolean choiseflag27 = false;
boolean choiseflag28 = false;
boolean choiseflag29 = false;
boolean choiseflag30 = false;
boolean choiseflag31 = false;
boolean choiseflag32 = false;
boolean choiseflag33 = false;
boolean choiseflag34 = false;
boolean choiseflag35 = false;
boolean choiseflag36 = false;
boolean choiseflag37 = false;
boolean choiseflag38 = false;
boolean choiseflag39 = false;
boolean choiseflag40 = false;
boolean choiseflag41 = false;
boolean choiseflag42 = false;
boolean choiseflag43 = false;
boolean choiseflag44 = false;
boolean choiseflag45 = false;
boolean choiseflag46 = false;
boolean choiseflag47 = false;
boolean choiseflag48 = false;
boolean choiseflag49 = false;
boolean choiseflag50 = false;
boolean choiseflag51 = false;
boolean choiseflag52 = false;
boolean choiseflag53 = false;
boolean choiseflag54 = false;
boolean choiseflag55 = false;
boolean choiseflag56 = false;
boolean choiseflag57 = false;
boolean choiseflag58 = false;
boolean choiseflag59 = false;
boolean choiseflag60 = false;
boolean choiseflag61 = false;
boolean choiseflag62 = false;
boolean choiseflag63 = false;
boolean choiseflag64 = false;
boolean choiseflag65 = false;
boolean choiseflag66 = false;
boolean choiseflag67 = false;
boolean choiseflag68 = false;
boolean choiseflag69 = false;
boolean choiseflag70 = false;
boolean choiseflag71 = false;
boolean choiseflag72 = false;
boolean choiseflag73 = false;
boolean choiseflag74 = false;
boolean choiseflag75 = false;
boolean choiseflag76 = false;
boolean choiseflag77 = false;
boolean choiseflag78 = false;
boolean choiseflag79 = false;
boolean choiseflag80 = false;
boolean choiseflag81 = false;
boolean choiseflag82 = false;
boolean choiseflag83 = false;
boolean choiseflag84 = false;
boolean choiseflag85 = false;
boolean choiseflag86 = false;
boolean choiseflag87 = false;
boolean choiseflag88 = false;
boolean choiseflag89 = false;
boolean choiseflag90 = false;
boolean choiseflag91 = false;
boolean choiseflag92 = false;
boolean choiseflag93 = false;
boolean choiseflag94 = false;
boolean choiseflag95 = false;
boolean choiseflag96 = false;
boolean choiseflag97 = false;
boolean choiseflag98 = false;
boolean choiseflag99 = false;

boolean sell = false;
boolean sell2 = false;
boolean first = false;
boolean second = false;

int val;
int testaudiotimer = 2300;
int choisetime = 5000;
int intVar1;
//переменные для программирования по bluetooth конец

int DelayAudio1 = 12000;  //Время второго аудио
int DelayAudio2 = 12000;  //Время второго аудио
int DelayLock = 17000;    //Время закрытия замка

int RelayLock = 33;             // Выходной пин - реле замка
int RelayLock2 = 32;
int LedR1 = 23;
int LedG1 = 15;
int LedB1 = 13;
int LedR2 = 12;
int LedG2 = 14;
int LedB2 = 27;

GTimer def(MS);
GTimer choise(MS);
GTimer GTimerAudio1(MS);
GTimer GTimerAudio2(MS);
GTimer GTimerLock(MS);
GTimer Testaudio(MS);
GTimer Pay(MS);

XT_Wav_Class Sound1(sample1);
XT_Wav_Class Sound2(sample2);
XT_DAC_Audio_Class DacAudio(25, 0);
int audiotest = 0;

String text = "";
String newchar = "";
boolean prog = false;
boolean tens = false;
char customKey;
int p10 = 0;
int p11 = 0;
int p12 = 0;
int p13 = 0;
int p14 = 0;
int p15 = 0;
int p16 = 0;
int p17 = 0;
int p18 = 0;
int p19 = 0;
int p20 = 0;
int p21 = 0;
int p22 = 0;
int p23 = 0;
int p24 = 0;
int p25 = 0;
int p26 = 0;
int p27 = 0;
int p28 = 0;
int p29 = 0;
int p30 = 0;
int p31 = 0;
int p32 = 0;
int p33 = 0;
int p34 = 0;
int p35 = 0;
int p36 = 0;
int p37 = 0;
int p38 = 0;
int p39 = 0;
int p40 = 0;
int p41 = 0;
int p42 = 0;
int p43 = 0;
int p44 = 0;
int p45 = 0;
int p46 = 0;
int p47 = 0;
int p48 = 0;
int p49 = 0;
int p50 = 0;
int p51 = 0;
int p52 = 0;
int p53 = 0;
int p54 = 0;
int p55 = 0;
int p56 = 0;
int p57 = 0;
int p58 = 0;
int p59 = 0;
int p60 = 0;
int p61 = 0;
int p62 = 0;
int p63 = 0;
int p64 = 0;
int p65 = 0;
int p66 = 0;
int p67 = 0;
int p68 = 0;
int p69 = 0;
int p70 = 0;
int p71 = 0;
int p72 = 0;
int p73 = 0;
int p74 = 0;
int p75 = 0;
int p76 = 0;
int p77 = 0;
int p78 = 0;
int p79 = 0;
int p80 = 0;
int p81 = 0;
int p82 = 0;
int p83 = 0;
int p84 = 0;
int p85 = 0;
int p86 = 0;
int p87 = 0;
int p88 = 0;
int p89 = 0;
int p90 = 0;
int p91 = 0;
int p92 = 0;
int p93 = 0;
int p94 = 0;
int p95 = 0;
int p96 = 0;
int p97 = 0;
int p98 = 0;
int p99 = 0;
String p1text = "";
int a2 = 0;
int a1 = 0;
int textint;
int price1;

const byte ROWS = 4; //four rows
const byte COLS = 3; //four columns
//define the cymbols on the buttons of the keypads
char hexaKeys[ROWS][COLS] = {
  {'3', '1', '2'},
  {'6', '4', '5'},
  {'9', '7', '8'},
  {'C', '0', 'E'}
};
byte rowPins[ROWS] = {19, 18, 5, 26}; //connect to the row pinouts of the keypad 17-20
byte colPins[COLS] = {4, 2, 0}; //connect to the column pinouts of the keypad

//initialize an instance of class NewKeypad
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);
///////////////////////////////////////////////////////////////////////  VTK

uint16_t i, tmp, crc = 0xffff;
int a = 0; //CRC0
int b = 0; //CRC1
int l = 0; //Количество переданных знаков
int ll = 0; //Количество переданных знаков
int z = 0;
uint8_t data[50];//приходящий код от терминала
uint8_t data9[50];//приходящий код от терминала
// для тестов (
//uint8_t VRP []={0x1F,0x00, 0x0F, 0x96, 0xFB,  0x01, 0x03, 0x56, 0x52, 0x50,  0x03, 0x01, 0x35,  0x04, 0x03, 0x39, 0x30, 0x30, 0x30, 0x30};
//                0   1     2      3     4     5      6     7     8     9     10     11    12     13    14    15    16    17    18    19     20    21
//uint8_t FIN []={0x1F,0x00, 0x0F, 0x96, 0xFB,  0x01, 0x03, 0x46, 0x49, 0x4E,  0x03, 0x01, 0x35,  0x04, 0x05, 0x30, 0x31, 0x30, 0x30, 0x30,  0x40, 0xB7};
//                0   1     2      3     4     5      6    7F     8I   9N     10     11    12     13    14    15    16    17    18    19     20    21
// для тестов )
uint8_t data1 [] = {0x1F, 0x00, 0x22, 0x96, 0xFB, 0x01, 0x03, 0x56, 0x52, 0x50, 0x03, 0x08,  0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x30,    0x04, 0x05,   0x30, 0x30, 0x31,   0x30, 0x30, 0x06, 0x03, 0x31, 0x32, 0x30, 0x09, 0x03, 0x30, 0x31, 0x30,  0x5C, 0x99}; //Передача кода на терминал с суммойоб оплате
//                  0    1    2    3    4    5    6    7    8    9    10   11     12   13   14   15   16   17   18   19       20   21      22   23   24      25   26   27   28   29   30   31     32   33    34    35    36    37     38
uint8_t data2 [21];//Сумма оплаты
uint8_t data3 [] = {0x1F, 0x00, 0x0A, 0x96, 0xFB, 0x01, 0x03, 0x49, 0x44, 0x4C, 0x03, 0x01, 0x30, 0xB6, 0x49}; //Начальная инициализация терминала
//                  0    1    2    3    4    5    6    7    8    9    10   11   12   13   14
uint8_t FIN [] = {0x1F, 0x00, 0x18, 0x96, 0xFB, 0x01, 0x03, 0x46, 0x49, 0x4E, 0x03, 0x08,  0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x35, 0x30,    0x04, 0x05,   0x30, 0x30, 0x31,   0x30, 0x30, 0x34, 0x51}; //Финализируем документ
//               0    1    2    3    4    5    6    F    I    N    10   11     12   13   14   15   16   17   18   19       20   21      22   23   24      25   26   27   28
uint8_t data5 [] = {0x1F, 0x00, 0x11, 0x96, 0xFB, 0x01, 0x03, 0x49, 0x44, 0x4C, 0x03, 0x08,  0x30, 0x30, 0x30, 0x30, 0x30, 0x30, 0x35, 0x31,    0xFF, 0x2C}; //Последующая инициализация терминала
//                  0    1    2    3    4    5    6    7    8    9    10   11     12   13   14   15   16   17   18   19       20   21
uint8_t cancel [] = {0x1F, 0x00, 0x07, 0x96, 0xFB, 0x01, 0x03, 0x41, 0x42, 0x52, 0x81, 0xB6}; //отмена
uint8_t disable [] = {0x1F, 0x00, 0x07, 0x96, 0xFB, 0x01, 0x03, 0x44, 0x49, 0x53, 0xA6, 0x9D}; //DISABLE

long previousMillis = 0; // время, когда состояние обновлялось
long interval = 120000; //delay (1000)


int sp = 50;//Задержка СОМ порта при чтении
int c = 0; //Количество знаков в документе
int c1 = 0;
int c2 = 0;//признак прохождения платежа если с2==1 платеж не прошел
int n[10]; //номер документа
int n1 = 0;
int n2 = 0;
int n3 = 0;
int n4 = 0;
int n5 = 0;
int n6 = 0;
int n7 = 0;
int n8 = 0;
int n9 = 0;
int n10 = 0;
int n11 = 0;
int n12 = 0;
int n13 = 0;
int n14 = 0;
int n15 = 0;
int n16 = 0;


static const uint16_t crc16_ccitt_table[ 256 ] =
{
  0x0000, 0x1021, 0x2042, 0x3063, 0x4084, 0x50A5, 0x60C6, 0x70E7,
  0x8108, 0x9129, 0xA14A, 0xB16B, 0xC18C, 0xD1AD, 0xE1CE, 0xF1EF,
  0x1231, 0x0210, 0x3273, 0x2252, 0x52B5, 0x4294, 0x72F7, 0x62D6,
  0x9339, 0x8318, 0xB37B, 0xA35A, 0xD3BD, 0xC39C, 0xF3FF, 0xE3DE,
  0x2462, 0x3443, 0x0420, 0x1401, 0x64E6, 0x74C7, 0x44A4, 0x5485,
  0xA56A, 0xB54B, 0x8528, 0x9509, 0xE5EE, 0xF5CF, 0xC5AC, 0xD58D,
  0x3653, 0x2672, 0x1611, 0x0630, 0x76D7, 0x66F6, 0x5695, 0x46B4,
  0xB75B, 0xA77A, 0x9719, 0x8738, 0xF7DF, 0xE7FE, 0xD79D, 0xC7BC,
  0x48C4, 0x58E5, 0x6886, 0x78A7, 0x0840, 0x1861, 0x2802, 0x3823,
  0xC9CC, 0xD9ED, 0xE98E, 0xF9AF, 0x8948, 0x9969, 0xA90A, 0xB92B,
  0x5AF5, 0x4AD4, 0x7AB7, 0x6A96, 0x1A71, 0x0A50, 0x3A33, 0x2A12,
  0xDBFD, 0xCBDC, 0xFBBF, 0xEB9E, 0x9B79, 0x8B58, 0xBB3B, 0xAB1A,
  0x6CA6, 0x7C87, 0x4CE4, 0x5CC5, 0x2C22, 0x3C03, 0x0C60, 0x1C41,
  0xEDAE, 0xFD8F, 0xCDEC, 0xDDCD, 0xAD2A, 0xBD0B, 0x8D68, 0x9D49,
  0x7E97, 0x6EB6, 0x5ED5, 0x4EF4, 0x3E13, 0x2E32, 0x1E51, 0x0E70,
  0xFF9F, 0xEFBE, 0xDFDD, 0xCFFC, 0xBF1B, 0xAF3A, 0x9F59, 0x8F78,
  0x9188, 0x81A9, 0xB1CA, 0xA1EB, 0xD10C, 0xC12D, 0xF14E, 0xE16F,
  0x1080, 0x00A1, 0x30C2, 0x20E3, 0x5004, 0x4025, 0x7046, 0x6067,
  0x83B9, 0x9398, 0xA3FB, 0xB3DA, 0xC33D, 0xD31C, 0xE37F, 0xF35E,
  0x02B1, 0x1290, 0x22F3, 0x32D2, 0x4235, 0x5214, 0x6277, 0x7256,
  0xB5EA, 0xA5CB, 0x95A8, 0x8589, 0xF56E, 0xE54F, 0xD52C, 0xC50D,
  0x34E2, 0x24C3, 0x14A0, 0x0481, 0x7466, 0x6447, 0x5424, 0x4405,
  0xA7DB, 0xB7FA, 0x8799, 0x97B8, 0xE75F, 0xF77E, 0xC71D, 0xD73C,
  0x26D3, 0x36F2, 0x0691, 0x16B0, 0x6657, 0x7676, 0x4615, 0x5634,
  0xD94C, 0xC96D, 0xF90E, 0xE92F, 0x99C8, 0x89E9, 0xB98A, 0xA9AB,
  0x5844, 0x4865, 0x7806, 0x6827, 0x18C0, 0x08E1, 0x3882, 0x28A3,
  0xCB7D, 0xDB5C, 0xEB3F, 0xFB1E, 0x8BF9, 0x9BD8, 0xABBB, 0xBB9A,
  0x4A75, 0x5A54, 0x6A37, 0x7A16, 0x0AF1, 0x1AD0, 0x2AB3, 0x3A92,
  0xFD2E, 0xED0F, 0xDD6C, 0xCD4D, 0xBDAA, 0xAD8B, 0x9DE8, 0x8DC9,
  0x7C26, 0x6C07, 0x5C64, 0x4C45, 0x3CA2, 0x2C83, 0x1CE0, 0x0CC1,
  0xEF1F, 0xFF3E, 0xCF5D, 0xDF7C, 0xAF9B, 0xBFBA, 0x8FD9, 0x9FF8,
  0x6E17, 0x7E36, 0x4E55, 0x5E74, 0x2E93, 0x3EB2, 0x0ED1, 0x1EF0
};

int cost100;
int cost10;
int cost1;
int total = 0;
int intVar = 0;
int paytime = 45000;
//////////////////////////////////////////////////////////////////////////

void setup()
{
  butt.setType(LOW_PULL);
  butt.setDebounce(20);
  pinMode(LedR1, OUTPUT);
  pinMode(LedG1, OUTPUT);
  pinMode(LedB1, OUTPUT);
  pinMode(LedR2, OUTPUT);
  pinMode(LedG2, OUTPUT);
  pinMode(LedB2, OUTPUT);
  digitalWrite(LedR1, HIGH);
  digitalWrite(LedG1, HIGH);
  digitalWrite(LedB1, HIGH);
  digitalWrite(LedR2, HIGH);
  digitalWrite(LedG2, HIGH);
  digitalWrite(LedB2, HIGH);
  pinMode(RelayLock, OUTPUT);
  pinMode(RelayLock2, OUTPUT);
  digitalWrite(RelayLock, LOW);
  digitalWrite(RelayLock2, LOW);

  SerialBT.begin("NEW_UH"); //Bluetooth device name

 // Serial1.begin(115200, SERIAL_8N1, RXD1, TXD1);
  Serial.begin(19200, SERIAL_8N1);

  Serial1.write(data5, sizeof(data5));

  prefs.begin("nvs", false);
  p10 = prefs.getUInt("p10", 0);
  p11 = prefs.getUInt("p11", 0);
  p12 = prefs.getUInt("p12", 0);
  p13 = prefs.getUInt("p13", 0);
  p14 = prefs.getUInt("p14", 0);
  p15 = prefs.getUInt("p15", 0);
  p16 = prefs.getUInt("p16", 0);
  p17 = prefs.getUInt("p17", 0);
  p18 = prefs.getUInt("p18", 0);
  p19 = prefs.getUInt("p19", 0);
  p20 = prefs.getUInt("p20", 0);
  p21 = prefs.getUInt("p21", 0);
  p22 = prefs.getUInt("p22", 0);
  p23 = prefs.getUInt("p23", 0);
  p24 = prefs.getUInt("p24", 0);
  p25 = prefs.getUInt("p25", 0);
  p26 = prefs.getUInt("p26", 0);
  p27 = prefs.getUInt("p27", 0);
  p28 = prefs.getUInt("p28", 0);
  p29 = prefs.getUInt("p29", 0);
  p30 = prefs.getUInt("p30", 0);
  p31 = prefs.getUInt("p31", 0);
  p32 = prefs.getUInt("p32", 0);
  p33 = prefs.getUInt("p33", 0);
  p34 = prefs.getUInt("p34", 0);
  p35 = prefs.getUInt("p35", 0);
  p36 = prefs.getUInt("p36", 0);
  p37 = prefs.getUInt("p37", 0);
  p38 = prefs.getUInt("p38", 0);
  p39 = prefs.getUInt("p39", 0);
  p40 = prefs.getUInt("p40", 0);
  p41 = prefs.getUInt("p41", 0);
  p42 = prefs.getUInt("p42", 0);
  p43 = prefs.getUInt("p43", 0);
  p44 = prefs.getUInt("p44", 0);
  p45 = prefs.getUInt("p45", 0);
  p46 = prefs.getUInt("p46", 0);
  p47 = prefs.getUInt("p47", 0);
  p48 = prefs.getUInt("p48", 0);
  p49 = prefs.getUInt("p49", 0);
  p50 = prefs.getUInt("p50", 0);
  p51 = prefs.getUInt("p51", 0);
  p52 = prefs.getUInt("p52", 0);
  p53 = prefs.getUInt("p53", 0);
  p54 = prefs.getUInt("p54", 0);
  p55 = prefs.getUInt("p55", 0);
  p56 = prefs.getUInt("p56", 0);
  p57 = prefs.getUInt("p57", 0);
  p58 = prefs.getUInt("p58", 0);
  p59 = prefs.getUInt("p59", 0);
  p60 = prefs.getUInt("p60", 0);
  p61 = prefs.getUInt("p61", 0);
  p62 = prefs.getUInt("p62", 0);
  p63 = prefs.getUInt("p63", 0);
  p64 = prefs.getUInt("p64", 0);
  p65 = prefs.getUInt("p65", 0);
  p66 = prefs.getUInt("p66", 0);
  p67 = prefs.getUInt("p67", 0);
  p68 = prefs.getUInt("p68", 0);
  p69 = prefs.getUInt("p69", 0);
  p70 = prefs.getUInt("p70", 0);
  p71 = prefs.getUInt("p71", 0);
  p72 = prefs.getUInt("p72", 0);
  p73 = prefs.getUInt("p73", 0);
  p74 = prefs.getUInt("p74", 0);
  p75 = prefs.getUInt("p75", 0);
  p76 = prefs.getUInt("p76", 0);
  p77 = prefs.getUInt("p77", 0);
  p78 = prefs.getUInt("p78", 0);
  p79 = prefs.getUInt("p79", 0);
  p80 = prefs.getUInt("p80", 0);
  p81 = prefs.getUInt("p81", 0);
  p82 = prefs.getUInt("p82", 0);
  p83 = prefs.getUInt("p83", 0);
  p84 = prefs.getUInt("p84", 0);
  p85 = prefs.getUInt("p85", 0);
  p86 = prefs.getUInt("p86", 0);
  p87 = prefs.getUInt("p87", 0);
  p88 = prefs.getUInt("p88", 0);
  p89 = prefs.getUInt("p89", 0);
  p90 = prefs.getUInt("p90", 0);
  p91 = prefs.getUInt("p91", 0);
  p92 = prefs.getUInt("p92", 0);
  p93 = prefs.getUInt("p93", 0);
  p94 = prefs.getUInt("p94", 0);
  p95 = prefs.getUInt("p95", 0);
  p96 = prefs.getUInt("p96", 0);
  p97 = prefs.getUInt("p97", 0);
  p98 = prefs.getUInt("p98", 0);
  p99 = prefs.getUInt("p99", 0);

  //cr2();

  Serial1.begin(115200, SERIAL_8N1, RXD1, TXD1);
  Serial1.write(data5, sizeof(data5));
 
  lcd.init();
  lcd.backlight();
  lcd.clear();                           ////////////////////////   начальный экран
  lcd.setCursor(5, 0);
  lcd.print("Введите код");
  lcd.setCursor(7, 1);
  lcd.print("товара");
  lcd.setCursor(0, 3);
  //lcd.print("к оплате");
  //lcd.setCursor(10, 3);
 // lcd.print(total);
  //lcd.setCursor(14, 3);
 // lcd.print("руб");                      //////////////////////     начальный экран
  DelayLock = prefs.getUInt("DelayLock", 0);
  if (DelayLock < 7000 || DelayLock > 25000) {
    DelayLock = 17000;
  }
}
void loop()
{

   z0:
  DacAudio.FillBuffer();
  if (sell == true) {
    DacAudio.FillBuffer();
    total = 0;
    lcd.clear();                           ////////////////////////   начальный экран
    lcd.setCursor(3, 1);
    lcd.print("Заберите товар");
    sell = false;
    sell2 = true;
    if (first == true) {

      DacAudio.Play(&Sound1);
      digitalWrite(LedR1, LOW);
      digitalWrite(LedB1, LOW);
      digitalWrite(LedG1, HIGH);
      GTimerAudio1.setTimeout(DelayAudio1);
      GTimerLock.setTimeout(DelayLock);
      digitalWrite(RelayLock, HIGH);

      first = false;
    }
    if (second == true) {

      DacAudio.Play(&Sound1);
      digitalWrite(LedR2, LOW);
      digitalWrite(LedB2, LOW);
      digitalWrite(LedG2, HIGH);
      GTimerAudio2.setTimeout(DelayAudio2);
      GTimerLock.setTimeout(DelayLock);
      digitalWrite(RelayLock2, HIGH);
      second = false;
    }
    
    paystat = 0;
    total = 0;
    price1 = 0;
  }

  if (GTimerAudio1.isReady()) {

    DacAudio.Play(&Sound2);
    digitalWrite(LedR1, HIGH);
    digitalWrite(LedB1, LOW);
    digitalWrite(LedG1, LOW);
  }
  if (GTimerAudio2.isReady()) {

    DacAudio.Play(&Sound2);
    digitalWrite(LedR2, HIGH);
    digitalWrite(LedB2, LOW);
    digitalWrite(LedG2, LOW);
  }
  if (GTimerLock.isReady()) {   // Закрываем замок
    digitalWrite(RelayLock, LOW);
    digitalWrite(RelayLock2, LOW);
    digitalWrite(LedR2, HIGH);
    digitalWrite(LedB2, HIGH);
    digitalWrite(LedG2, HIGH);
    digitalWrite(LedR1, HIGH);
    digitalWrite(LedB1, HIGH);
    digitalWrite(LedG1, HIGH);

    lcd.clear();                           ////////////////////////   начальный экран
    lcd.setCursor(5, 0);
    lcd.print("Введите код");
    lcd.setCursor(7, 1);
    lcd.print("товара");
    lcd.setCursor(0, 3);
    sell2 = false;
    //lcd.print("к оплате");
    //lcd.setCursor(10, 3);
   // lcd.print(total);
   // lcd.setCursor(14, 3);
   // lcd.print("руб");                      //////////////////////     начальный экран
  }

  //bt
  if (SerialBT.available() && a3 == 0)
  {
    intVar1 = SerialBT.parseInt();
    recievedFlag = true;                   // поднять флаг что получили данные
    delay(2);
  }
  if (recievedFlag) {                      // если данные получены
    if (intVar1 == 100) {
      a3 = 1;
      SerialBT.println(enter);
    }
    if (intVar1 == 101) {
      SerialBT.println(enter3 + DelayLock);
    }
    if (intVar1 == 107) {
      digitalWrite(LedR1, HIGH);
      digitalWrite(LedG1, LOW);
      digitalWrite(LedB1, LOW);
      digitalWrite(LedR2, HIGH);
      digitalWrite(LedG2, LOW);
      digitalWrite(LedB2, LOW);
      SerialBT.println("RED");
    }
    if (intVar1 == 108) {
      digitalWrite(LedR1, LOW);
      digitalWrite(LedG1, HIGH);
      digitalWrite(LedB1, LOW);
      digitalWrite(LedR2, LOW);
      digitalWrite(LedG2, HIGH);
      digitalWrite(LedB2, LOW);
      SerialBT.println("GREEN");
    }
    if (intVar1 == 109) {
      digitalWrite(LedR1, LOW);
      digitalWrite(LedG1, LOW);
      digitalWrite(LedB1, HIGH);
      digitalWrite(LedR2, LOW);
      digitalWrite(LedG2, LOW);
      digitalWrite(LedB2, HIGH);
      SerialBT.println("BLUE");
    }
    if (intVar1 == 110) {
      digitalWrite(LedR1, HIGH);
      digitalWrite(LedG1, HIGH);
      digitalWrite(LedB1, HIGH);
      digitalWrite(LedR2, HIGH);
      digitalWrite(LedG2, HIGH);
      digitalWrite(LedB2, HIGH);
      SerialBT.println("WHITE");
    }
    if (intVar1 == 111) {
      DacAudio.FillBuffer();
      DacAudio.Play(&Sound1);
      digitalWrite(LedR1, LOW);
      digitalWrite(LedB1, LOW);
      digitalWrite(LedG1, HIGH);
      GTimerAudio1.setTimeout(DelayAudio1);
      GTimerLock.setTimeout(DelayLock);
      digitalWrite(RelayLock, HIGH);
    }
    if (intVar1 == 112) {
      DacAudio.FillBuffer();
      DacAudio.Play(&Sound1);
      digitalWrite(LedR2, LOW);
      digitalWrite(LedB2, LOW);
      digitalWrite(LedG2, HIGH);
      GTimerAudio2.setTimeout(DelayAudio2);
      GTimerLock.setTimeout(DelayLock);
      digitalWrite(RelayLock2, HIGH);
    }
    if (intVar1 == 113) {
      digitalWrite(RelayLock2, HIGH);
      digitalWrite(RelayLock, HIGH);
      delay(3000);
      digitalWrite(RelayLock2, LOW);
      digitalWrite(RelayLock, LOW);
    }
    if (intVar1 == 115) {
      Testaudio.stop();
    }
    if (intVar1 == 114) {
      DacAudio.Play(&Sound1);
      Testaudio.setTimeout(testaudiotimer);       ///////////////////////
    }
    strData = "";                          // очистить
    recievedFlag = false;                  // опустить флаг
  }
  if (SerialBT.available() && a3 == 1) {
    DelayLock = SerialBT.parseInt();
    prefs.putUInt("DelayLock", DelayLock);
    recievedFlag = true;                   // поднять флаг что получили данные
    delay(2);
  }
  if (recievedFlag) {                      // если данные получены
    SerialBT.println(enter2 + DelayLock);               // вывести
    a3 = 0;
    strData = "";                          // очистить
    recievedFlag = false;                  // опустить флаг
  }
  //программирование по bluetooth конец
  DelayAudio2 = DelayLock - 5000;
  DelayAudio1 = DelayLock - 5000;
  //bt

  if (Testaudio.isReady()) {
    DacAudio.Play(&Sound1);
    Testaudio.setTimeout(testaudiotimer);
  }

  if (Pay.isReady() && sell2 == false) {
z1:
    paystat = 0;
    Serial1.write(data5, sizeof(data5));
    price1 = 0;
    total = 0;
    first = false;
    second = false;
    lcd.clear();                           ////////////////////////   начальный экран
    lcd.setCursor(5, 0);
    lcd.print("Введите код");
    lcd.setCursor(7, 1);
    lcd.print("товара");
    lcd.setCursor(0, 3);
   // lcd.print("к оплате");
    //lcd.setCursor(10, 3);
  //  lcd.print(total);
  // lcd.setCursor(14, 3);
  //  lcd.print("руб");                      //////////////////////     начальный экран
  }
  //if(Serial1.available()!=0 && paystat == 0){
  //   if(Serial1.read()==0x07){
  // price1 = total;}
  //  }

  if (paystat == 2) {
z4: customKey = customKeypad.getKey();
    newchar = String(customKey);
    if (newchar == "C") {
      Serial1.write(cancel, sizeof(cancel));
      delay(1000);
      paystat = 0;
      Serial1.write(data5, sizeof(data5));
      Pay.stop();
      price1 = 0;
      total = 0;
      first = false;
      second = false;
      lcd.clear();                           ////////////////////////   начальный экран
      lcd.setCursor(5, 0);
      lcd.print("Введите код");
      lcd.setCursor(7, 1);
      lcd.print("товара");
      }
    delay(500);
    if (Serial1.available() == 0) {
      goto z4;
    }
    l = Serial1.available();
    for ( i = 0; i < l ; i++ ) {
      data[i] = Serial1.read(); //читаем ответ терминала
    }
    for ( i = 0; i < l ; i++ ) {
      if (data[i] == 0x04) {
        c2 = data[i + 1];
        if (c2 == 0x01) {
          Pay.stop();
          lcd.clear();                           ////////////////////////   начальный экран
          lcd.setCursor(1, 1);
          lcd.print("оплата не удалась");
          delay(3000);
          goto z1;
        }
        else {
          Pay.stop();
          lcd.clear();                           ////////////////////////   начальный экран
          lcd.setCursor(2, 1);
          lcd.print("успешная оплата");
          delay(500);
          Serial1.write(FIN, sizeof(FIN));
          delay(500);
          Serial1.write(data5, sizeof(data5));
          //Serial.write(FIN, sizeof(FIN));
          sell = true;
          paystat = 0;
          total = 0;
          price1 = 0;
          goto z0;//////     начальный экран
        }

      }
    }
  }//проверяем результат транзакции если с2==0х01 платеж отклонен банком
  //Serial.write (c2); //Посылаем признак принятой (с2==0х05) или отклоненной (с2==0х01) транзакции с банком


  if (choiseflag == false ) {
    choiseflag10 = false;
    choiseflag11 = false;
    choiseflag12 = false;
    choiseflag13 = false;
    choiseflag14 = false;
    choiseflag15 = false;
    choiseflag16 = false;
    choiseflag17 = false;
    choiseflag18 = false;
    choiseflag19 = false;
    choiseflag20 = false;
    choiseflag21 = false;
    choiseflag22 = false;
    choiseflag23 = false;
    choiseflag24 = false;
    choiseflag25 = false;
    choiseflag26 = false;
    choiseflag27 = false;
    choiseflag28 = false;
    choiseflag29 = false;
    choiseflag30 = false;
    choiseflag31 = false;
        choiseflag32 = false;
    choiseflag33 = false;
    choiseflag34 = false;
    choiseflag35 = false;
    choiseflag36 = false;
    choiseflag37 = false;
    choiseflag38 = false;
    choiseflag39 = false;
    choiseflag40 = false;
    choiseflag41 = false;
    choiseflag42 = false;
    choiseflag43 = false;
    choiseflag44 = false;
    choiseflag45 = false;
    choiseflag46 = false;
    choiseflag47 = false;
    choiseflag48 = false;
    choiseflag49 = false;
    choiseflag50 = false;
    choiseflag51 = false;
    choiseflag52 = false;
    choiseflag53 = false;
        choiseflag54 = false;
    choiseflag55 = false;
    choiseflag56 = false;
    choiseflag57 = false;
    choiseflag58 = false;
    choiseflag59 = false;
    choiseflag60 = false;
    choiseflag61 = false;
    choiseflag62 = false;
    choiseflag63 = false;
    choiseflag64 = false;
    choiseflag65 = false;
    choiseflag66 = false;
    choiseflag67 = false;
    choiseflag68 = false;
    choiseflag69 = false;
    choiseflag70 = false;
    choiseflag71 = false;
    choiseflag72 = false;
    choiseflag73 = false;
    choiseflag74 = false;
        choiseflag75 = false;
    choiseflag76 = false;
    choiseflag77 = false;
    choiseflag78 = false;
    choiseflag79 = false;
    choiseflag80 = false;
    choiseflag81 = false;
    choiseflag82 = false;
    choiseflag83 = false;
    choiseflag84 = false;
    choiseflag85 = false;
    choiseflag86 = false;
    choiseflag87 = false;
    choiseflag88 = false;
    choiseflag89 = false;
    choiseflag90 = false;
    choiseflag91 = false;
    choiseflag92 = false;
    choiseflag93 = false;
    choiseflag94 = false;
    choiseflag95 = false;
    choiseflag96 = false;
    choiseflag97 = false;
    choiseflag98 = false;
    choiseflag98 = false;
  }
  if (choiseflag10 == false && choiseflag11 == false && choiseflag12 == false && choiseflag13 == false && choiseflag14 == false && choiseflag15 == false && choiseflag16 == false && choiseflag17 == false && choiseflag18 == false && choiseflag19 == false && choiseflag20 == false && choiseflag21 == false && choiseflag22 == false && choiseflag23 == false && choiseflag24 == false && choiseflag25 == false && choiseflag26 == false && choiseflag27 == false && choiseflag28 == false && choiseflag29 == false && choiseflag30 == false && choiseflag31 == false && choiseflag32 == false && choiseflag33 == false && choiseflag34 == false && choiseflag35 == false && choiseflag36 == false && choiseflag37 == false && choiseflag38 == false && choiseflag39 == false && choiseflag40 == false && choiseflag41 == false && choiseflag42 == false && choiseflag43 == false && choiseflag44 == false && choiseflag45 == false && choiseflag46 == false && choiseflag47 == false && choiseflag48 == false && choiseflag49 == false && choiseflag50 == false && choiseflag51 == false && choiseflag52 == false && choiseflag53 == false && choiseflag54 == false && choiseflag55 == false && choiseflag56 == false && choiseflag57 == false && choiseflag58 == false && choiseflag59 == false && choiseflag60 == false && choiseflag61 == false && choiseflag62 == false && choiseflag63 == false && choiseflag64 == false && choiseflag65 == false && choiseflag66 == false && choiseflag67 == false && choiseflag68 == false && choiseflag69 == false && choiseflag70 == false && choiseflag71 == false && choiseflag72 == false && choiseflag73 == false && choiseflag74 == false && choiseflag75 == false && choiseflag76 == false && choiseflag77 == false && choiseflag78 == false && choiseflag79 == false && choiseflag80 == false && choiseflag81 == false && choiseflag82 == false && choiseflag83 == false && choiseflag84 == false && choiseflag85 == false && choiseflag86 == false && choiseflag87 == false && choiseflag88 == false && choiseflag89 == false && choiseflag90 == false && choiseflag91 == false && choiseflag92 == false && choiseflag93 == false && choiseflag94 == false && choiseflag95 == false && choiseflag96 == false && choiseflag97 == false && choiseflag98 == false && choiseflag99 == false) {
    choiseflag = false;

  }
  else {
    choiseflag = true;
  }

  if (millis() - previousMillis > interval) { //Не даем терминалу заснуть (выходить на надпись "Карты не принимаются...
  if (paystat == 0){
    previousMillis = millis();
    Serial1.write(data5, sizeof(data5));
  }}

  if (choise.isReady()) {
    lcd.clear();                           ////////////////////////   начальный экран
    lcd.setCursor(5, 0);
    lcd.print("Введите код");
    lcd.setCursor(7, 1);
    lcd.print("товара");
    lcd.setCursor(0, 3);
    //lcd.print("к оплате");
  //  lcd.setCursor(10, 3);
   // lcd.print(total);
  //  lcd.setCursor(14, 3);
  //  lcd.print("руб");                      //////////////////////     начальный экран
    choiseflag = false;
    choise.stop();
    newchar = "";
    text = "";
  }
  butt.tick();
  if (butt.isClick()) {
    if (prog == false) {
      prog = true;
      lcd.clear();
      a = 10;
    }
    else if (prog == true) {
      prog = false;
      lcd.clear();                           ////////////////////////   начальный экран
      lcd.setCursor(5, 0);
      lcd.print("Введите код");
      lcd.setCursor(7, 1);
      lcd.print("товара");
      lcd.setCursor(0, 3);
   //   lcd.print("к оплате");
  //    lcd.setCursor(10, 3);
     // lcd.print(total);
   //   lcd.setCursor(14, 3);
   //   lcd.print("руб");                      //////////////////////     начальный экран
      choiseflag = false;
      a = 0;
    }
  }

  if (prog == false && choiseflag == false && paystat == 0 && sell2 == false) {    ///////////// выбор товараов
    customKey = customKeypad.getKey();
    if (isDigit(customKey)) {
      newchar = String(customKey);
      text = text + newchar;
      lcd.setCursor(9, 2);
      lcd.print(text);
      if (text == "0") {
        lcd.clear();                           ////////////////////////   начальный экран
        lcd.setCursor(5, 0);
        lcd.print("Введите код");
        lcd.setCursor(7, 1);
        lcd.print("товара");
        lcd.setCursor(0, 3);
      //  lcd.print("к оплате");
       // lcd.setCursor(10, 3);
     //   lcd.print(total);
     //   lcd.setCursor(14, 3);
    //    lcd.print("руб");                      //////////////////////     начальный экран
        text = "";
      }
      if (text == "10" && p10 > 0) {
        lcd.clear();
        lcd.setCursor(5, 0);
        lcd.print("товар 10");
        lcd.setCursor(6, 1);
        lcd.print(p10);
        lcd.setCursor(10, 1);
        lcd.print("руб.");
        lcd.setCursor(0, 3);
        lcd.print("Е выбрать   С отмена");
        choiseflag10 = true;
        choiseflag = true;
        text = "";
        choise.setTimeout(choisetime);
      }
      if (text == "10" && p10 == 0) {
        lcd.clear();
        lcd.setCursor(2, 1);
        lcd.print("Выбор недоступен");
        // Serial1.write(disable, sizeof(disable));
        delay(1000);
        lcd.clear();                           ////////////////////////   начальный экран
        lcd.setCursor(5, 0);
        lcd.print("Введите код");
        lcd.setCursor(7, 1);
        lcd.print("товара");
        lcd.setCursor(0, 3);
       // lcd.print("к оплате");
      //  lcd.setCursor(10, 3);
      //  lcd.print(total);
     //   lcd.setCursor(14, 3);
      //  lcd.print("руб");                      //////////////////////     начальный экран
        text = "";
      }
      if (text == "11" && p11 > 0) {
        lcd.clear();
        lcd.setCursor(5, 0);
        lcd.print("товар 11");
        lcd.setCursor(6, 1);
        lcd.print(p11);
        lcd.setCursor(10, 1);
        lcd.print("руб.");
        lcd.setCursor(0, 3);
        lcd.print("Е выбрать   С отмена");
        choiseflag11 = true;
        choiseflag = true;
        text = "";
        choise.setTimeout(choisetime);
      }
      if (text == "11" && p11 == 0) {
        lcd.clear();
        lcd.setCursor(2, 1);
        lcd.print("Выбор недоступен");
        delay(1000);
        lcd.clear();                           ////////////////////////   начальный экран
        lcd.setCursor(5, 0);
        lcd.print("Введите код");
        lcd.setCursor(7, 1);
        lcd.print("товара");
        lcd.setCursor(0, 3);
       // lcd.print("к оплате");
      //  lcd.setCursor(10, 3);
      //  lcd.print(total);
      //  lcd.setCursor(14, 3);
      //  lcd.print("руб");                      //////////////////////     начальный экран
        text = "";
      }
      customKey = customKeypad.getKey();
      if (text == "12" && p12 > 0) {
        lcd.clear();
        lcd.setCursor(5, 0);
        lcd.print("товар 12");
        lcd.setCursor(6, 1);
        lcd.print(p12);
        lcd.setCursor(10, 1);
        lcd.print("руб.");
        lcd.setCursor(0, 3);
        lcd.print("Е выбрать   С отмена");
        choiseflag12 = true;
        choiseflag = true;
        text = "";
        choise.setTimeout(choisetime);
      }
      if (text == "12" && p12 == 0) {
        lcd.clear();
        lcd.setCursor(2, 1);
        lcd.print("Выбор недоступен");
        delay(1000);
        lcd.clear();                           ////////////////////////   начальный экран
        lcd.setCursor(5, 0);
        lcd.print("Введите код");
        lcd.setCursor(7, 1);
        lcd.print("товара");
        lcd.setCursor(0, 3);
       // lcd.print("к оплате");
      //  lcd.setCursor(10, 3);
       // lcd.print(total);
      //  lcd.setCursor(14, 3);
     //   lcd.print("руб");                      //////////////////////     начальный экран
        text = "";
      }
      if (text == "13" && p13 > 0) {
        lcd.clear();
        lcd.setCursor(5, 0);
        lcd.print("товар 13");
        lcd.setCursor(6, 1);
        lcd.print(p13);
        lcd.setCursor(10, 1);
        lcd.print("руб.");
        lcd.setCursor(0, 3);
        lcd.print("Е выбрать   С отмена");
        choiseflag13 = true;
        choiseflag = true;
        text = "";
        choise.setTimeout(choisetime);
      }
      if (text == "13" && p13 == 0) {
        lcd.clear();
        lcd.setCursor(2, 1);
        lcd.print("Выбор недоступен");
        delay(1000);
        lcd.clear();                           ////////////////////////   начальный экран
        lcd.setCursor(5, 0);
        lcd.print("Введите код");
        lcd.setCursor(7, 1);
        lcd.print("товара");
        lcd.setCursor(0, 3);
      //  lcd.print("к оплате");
     //   lcd.setCursor(10, 3);
      //  lcd.print(total);
     //   lcd.setCursor(14, 3);
      //  lcd.print("руб");                      //////////////////////     начальный экран
        text = "";
      }
      if (text == "14" && p14 > 0) {
        lcd.clear();
        lcd.setCursor(5, 0);
        lcd.print("товар 14");
        lcd.setCursor(6, 1);
        lcd.print(p14);
        lcd.setCursor(10, 1);
        lcd.print("руб.");
        lcd.setCursor(0, 3);
        lcd.print("Е выбрать   С отмена");
        choiseflag14 = true;
        choiseflag = true;
        text = "";
        choise.setTimeout(choisetime);
      }
      if (text == "14" && p14 == 0) {
        lcd.clear();
        lcd.setCursor(2, 1);
        lcd.print("Выбор недоступен");
        delay(1000);
        lcd.clear();                           ////////////////////////   начальный экран
        lcd.setCursor(5, 0);
        lcd.print("Введите код");
        lcd.setCursor(7, 1);
        lcd.print("товара");
        lcd.setCursor(0, 3);
        text = "";
      }
      if (text == "15" && p15 > 0) {
        lcd.clear();
        lcd.setCursor(5, 0);
        lcd.print("товар 15");
        lcd.setCursor(6, 1);
        lcd.print(p15);
        lcd.setCursor(10, 1);
        lcd.print("руб.");
        lcd.setCursor(0, 3);
        lcd.print("Е выбрать   С отмена");
        choiseflag15 = true;
        choiseflag = true;
        text = "";
        choise.setTimeout(choisetime);
      }
      if (text == "15" && p15 == 0) {
        lcd.clear();
        lcd.setCursor(2, 1);
        lcd.print("Выбор недоступен");
        delay(1000);
        lcd.clear();                           ////////////////////////   начальный экран
        lcd.setCursor(5, 0);
        lcd.print("Введите код");
        lcd.setCursor(7, 1);
        lcd.print("товара");
        lcd.setCursor(0, 3);
      
        text = "";
      }
      if (text == "16" && p16 > 0) {
        lcd.clear();
        lcd.setCursor(5, 0);
        lcd.print("товар 16");
        lcd.setCursor(6, 1);
        lcd.print(p16);
        lcd.setCursor(10, 1);
        lcd.print("руб.");
        lcd.setCursor(0, 3);
        lcd.print("Е выбрать   С отмена");
        choiseflag16 = true;
        choiseflag = true;
        text = "";
        choise.setTimeout(choisetime);
      }
      if (text == "16" && p16 == 0) {
        lcd.clear();
        lcd.setCursor(2, 1);
        lcd.print("Выбор недоступен");
        delay(1000);
        lcd.clear();                           ////////////////////////   начальный экран
        lcd.setCursor(5, 0);
        lcd.print("Введите код");
        lcd.setCursor(7, 1);
        lcd.print("товара");
        lcd.setCursor(0, 3);
       
        text = "";
      }
      if (text == "17" && p17 > 0) {
        lcd.clear();
        lcd.setCursor(5, 0);
        lcd.print("товар 17");
        lcd.setCursor(6, 1);
        lcd.print(p17);
        lcd.setCursor(10, 1);
        lcd.print("руб.");
        lcd.setCursor(0, 3);
        lcd.print("Е выбрать   С отмена");
        choiseflag17 = true;
        choiseflag = true;
        text = "";
        choise.setTimeout(choisetime);
      }
      if (text == "17" && p17 == 0) {
        lcd.clear();
        lcd.setCursor(2, 1);
        lcd.print("Выбор недоступен");
        delay(1000);
        lcd.clear();                           ////////////////////////   начальный экран
        lcd.setCursor(5, 0);
        lcd.print("Введите код");
        lcd.setCursor(7, 1);
        lcd.print("товара");
        lcd.setCursor(0, 3);
      
        text = "";
      }
      if (text == "18" && p18 > 0) {
        lcd.clear();
        lcd.setCursor(5, 0);
        lcd.print("товар 18");
        lcd.setCursor(6, 1);
        lcd.print(p18);
        lcd.setCursor(10, 1);
        lcd.print("руб.");
        lcd.setCursor(0, 3);
        lcd.print("Е выбрать   С отмена");
        choiseflag18 = true;
        choiseflag = true;
        text = "";
        choise.setTimeout(choisetime);
      }
      if (text == "18" && p18 == 0) {
        lcd.clear();
        lcd.setCursor(2, 1);
        lcd.print("Выбор недоступен");
        delay(1000);
        lcd.clear();                           ////////////////////////   начальный экран
        lcd.setCursor(5, 0);
        lcd.print("Введите код");
        lcd.setCursor(7, 1);
        lcd.print("товара");
        lcd.setCursor(0, 3);
      
      }
      if (text == "19" && p19 > 0) {
        lcd.clear();
        lcd.setCursor(5, 0);
        lcd.print("товар 19");
        lcd.setCursor(6, 1);
        lcd.print(p19);
        lcd.setCursor(10, 1);
        lcd.print("руб.");
        lcd.setCursor(0, 3);
        lcd.print("Е выбрать   С отмена");
        choiseflag19 = true;
        choiseflag = true;
        text = "";
        choise.setTimeout(choisetime);
      }
      if (text == "19" && p19 == 0) {
        lcd.clear();
        lcd.setCursor(2, 1);
        lcd.print("Выбор недоступен");
        delay(1000);
        lcd.clear();                           ////////////////////////   начальный экран
        lcd.setCursor(5, 0);
        lcd.print("Введите код");
        lcd.setCursor(7, 1);
        lcd.print("товара");
        lcd.setCursor(0, 3);
      
        text = "";
      }
      if (text == "20" && p20 > 0) {
        lcd.clear();
        lcd.setCursor(5, 0);
        lcd.print("товар 20");
        lcd.setCursor(6, 1);
        lcd.print(p20);
        lcd.setCursor(10, 1);
        lcd.print("руб.");
        lcd.setCursor(0, 3);
        lcd.print("Е выбрать   С отмена");
        choiseflag20 = true;
        choiseflag = true;
        text = "";
        choise.setTimeout(choisetime);
      }
      if (text == "20" && p20 == 0) {
        lcd.clear();
        lcd.setCursor(2, 1);
        lcd.print("Выбор недоступен");
        delay(1000);
        lcd.clear();                           ////////////////////////   начальный экран
        lcd.setCursor(5, 0);
        lcd.print("Введите код");
        lcd.setCursor(7, 1);
        lcd.print("товара");
        lcd.setCursor(0, 3);
      
        text = "";
      }
      if (text == "21" && p21 > 0) {
        lcd.clear();
        lcd.setCursor(5, 0);
        lcd.print("товар 21");
        lcd.setCursor(6, 1);
        lcd.print(p21);
        lcd.setCursor(10, 1);
        lcd.print("руб.");
        lcd.setCursor(0, 3);
        lcd.print("Е выбрать   С отмена");
        choiseflag21 = true;
        choiseflag = true;
        text = "";
        choise.setTimeout(choisetime);
      }
      if (text == "21" && p21 == 0) {
        lcd.clear();
        lcd.setCursor(2, 1);
        lcd.print("Выбор недоступен");
        delay(1000);
        lcd.clear();                           ////////////////////////   начальный экран
        lcd.setCursor(5, 0);
        lcd.print("Введите код");
        lcd.setCursor(7, 1);
        lcd.print("товара");
        lcd.setCursor(0, 3);
       
        text = "";
      }
      if (text == "22" && p22 > 0) {
        lcd.clear();
        lcd.setCursor(5, 0);
        lcd.print("товар 22");
        lcd.setCursor(6, 1);
        lcd.print(p22);
        lcd.setCursor(10, 1);
        lcd.print("руб.");
        lcd.setCursor(0, 3);
        lcd.print("Е выбрать   С отмена");
        choiseflag22 = true;
        choiseflag = true;
        text = "";
        choise.setTimeout(choisetime);
      }
      if (text == "22" && p22 == 0) {
        lcd.clear();
        lcd.setCursor(2, 1);
        lcd.print("Выбор недоступен");
        delay(1000);
        lcd.clear();                           ////////////////////////   начальный экран
        lcd.setCursor(5, 0);
        lcd.print("Введите код");
        lcd.setCursor(7, 1);
        lcd.print("товара");
        lcd.setCursor(0, 3);
       
        text = "";
      }
      if (text == "23" && p23 > 0) {
        lcd.clear();
        lcd.setCursor(5, 0);
        lcd.print("товар 23");
        lcd.setCursor(6, 1);
        lcd.print(p23);
        lcd.setCursor(10, 1);
        lcd.print("руб.");
        lcd.setCursor(0, 3);
        lcd.print("Е выбрать   С отмена");
        choiseflag23 = true;
        choiseflag = true;
        text = "";
        choise.setTimeout(choisetime);
      }
      if (text == "23" && p23 == 0) {
        lcd.clear();
        lcd.setCursor(2, 1);
        lcd.print("Выбор недоступен");
        delay(1000);
        lcd.clear();                           ////////////////////////   начальный экран
        lcd.setCursor(5, 0);
        lcd.print("Введите код");
        lcd.setCursor(7, 1);
        lcd.print("товара");
        lcd.setCursor(0, 3);
       
        text = "";
      }
      if (text == "24" && p24 > 0) {
        lcd.clear();
        lcd.setCursor(5, 0);
        lcd.print("товар 24");
        lcd.setCursor(6, 1);
        lcd.print(p24);
        lcd.setCursor(10, 1);
        lcd.print("руб.");
        lcd.setCursor(0, 3);
        lcd.print("Е выбрать   С отмена");
        choiseflag24 = true;
        choiseflag = true;
        text = "";
        choise.setTimeout(choisetime);
      }
      if (text == "24" && p24 == 0) {
        lcd.clear();
        lcd.setCursor(2, 1);
        lcd.print("Выбор недоступен");
        delay(1000);
        lcd.clear();                           ////////////////////////   начальный экран
        lcd.setCursor(5, 0);
        lcd.print("Введите код");
        lcd.setCursor(7, 1);
        lcd.print("товара");
        lcd.setCursor(0, 3);
    
        text = "";
      }
      if (text == "25" && p25 > 0) {
        lcd.clear();
        lcd.setCursor(5, 0);
        lcd.print("товар 25");
        lcd.setCursor(6, 1);
        lcd.print(p25);
        lcd.setCursor(10, 1);
        lcd.print("руб.");
        lcd.setCursor(0, 3);
        lcd.print("Е выбрать   С отмена");
        choiseflag25 = true;
        choiseflag = true;
        text = "";
        choise.setTimeout(choisetime);
      }
      if (text == "25" && p25 == 0) {
        lcd.clear();
        lcd.setCursor(2, 1);
        lcd.print("Выбор недоступен");
        delay(1000);
        lcd.clear();                           ////////////////////////   начальный экран
        lcd.setCursor(5, 0);
        lcd.print("Введите код");
        lcd.setCursor(7, 1);
        lcd.print("товара");
        lcd.setCursor(0, 3);
       
        text = "";
      }
      if (text == "26" && p26 > 0) {
        lcd.clear();
        lcd.setCursor(5, 0);
        lcd.print("товар 26");
        lcd.setCursor(6, 1);
        lcd.print(p26);
        lcd.setCursor(10, 1);
        lcd.print("руб.");
        lcd.setCursor(0, 3);
        lcd.print("Е выбрать   С отмена");
        choiseflag26 = true;
        choiseflag = true;
        text = "";
        choise.setTimeout(choisetime);
      }
      if (text == "26" && p26 == 0) {
        lcd.clear();
        lcd.setCursor(2, 1);
        lcd.print("Выбор недоступен");
        delay(1000);
        lcd.clear();                           ////////////////////////   начальный экран
        lcd.setCursor(5, 0);
        lcd.print("Введите код");
        lcd.setCursor(7, 1);
        lcd.print("товара");
        lcd.setCursor(0, 3);
       
        text = "";
      }
      if (text == "27" && p27 > 0) {
        lcd.clear();
        lcd.setCursor(5, 0);
        lcd.print("товар 27");
        lcd.setCursor(6, 1);
        lcd.print(p27);
        lcd.setCursor(10, 1);
        lcd.print("руб.");
        lcd.setCursor(0, 3);
        lcd.print("Е выбрать   С отмена");
        choiseflag27 = true;
        choiseflag = true;
        text = "";
        choise.setTimeout(choisetime);
      }
      if (text == "27" && p27 == 0) {
        lcd.clear();
        lcd.setCursor(2, 1);
        lcd.print("Выбор недоступен");
        delay(1000);
        lcd.clear();                           ////////////////////////   начальный экран
        lcd.setCursor(5, 0);
        lcd.print("Введите код");
        lcd.setCursor(7, 1);
        lcd.print("товара");
        lcd.setCursor(0, 3);
       
        text = "";
      }
      if (text == "28" && p28 > 0) {
        lcd.clear();
        lcd.setCursor(5, 0);
        lcd.print("товар 28");
        lcd.setCursor(6, 1);
        lcd.print(p28);
        lcd.setCursor(10, 1);
        lcd.print("руб.");
        lcd.setCursor(0, 3);
        lcd.print("Е выбрать   С отмена");
        choiseflag28 = true;
        choiseflag = true;
        text = "";
        choise.setTimeout(choisetime);
      }
      if (text == "28" && p28 == 0) {
        lcd.clear();
        lcd.setCursor(2, 1);
        lcd.print("Выбор недоступен");
        delay(1000);
        lcd.clear();                           ////////////////////////   начальный экран
        lcd.setCursor(5, 0);
        lcd.print("Введите код");
        lcd.setCursor(7, 1);
        lcd.print("товара");
        lcd.setCursor(0, 3);
       
        text = "";
      }
      if (text == "29" && p29 > 0) {
        lcd.clear();
        lcd.setCursor(5, 0);
        lcd.print("товар 29");
        lcd.setCursor(6, 1);
        lcd.print(p29);
        lcd.setCursor(10, 1);
        lcd.print("руб.");
        lcd.setCursor(0, 3);
        lcd.print("Е выбрать   С отмена");
        choiseflag29 = true;
        choiseflag = true;
        text = "";
        choise.setTimeout(choisetime);
      }
      if (text == "29" && p29 == 0) {
        lcd.clear();
        lcd.setCursor(2, 1);
        lcd.print("Выбор недоступен");
        delay(1000);
        lcd.clear();                           ////////////////////////   начальный экран
        lcd.setCursor(5, 0);
        lcd.print("Введите код");
        lcd.setCursor(7, 1);
        lcd.print("товара");
        lcd.setCursor(0, 3);
      
        text = "";
      }
      if (text == "30" && p30 > 0) {
        lcd.clear();
        lcd.setCursor(5, 0);
        lcd.print("товар 30");
        lcd.setCursor(6, 1);
        lcd.print(p30);
        lcd.setCursor(10, 1);
        lcd.print("руб.");
        lcd.setCursor(0, 3);
        lcd.print("Е выбрать   С отмена");
        choiseflag30 = true;
        choiseflag = true;
        text = "";
        choise.setTimeout(choisetime);
      }
      if (text == "30" && p30 == 0) {
        lcd.clear();
        lcd.setCursor(2, 1);
        lcd.print("Выбор недоступен");
        delay(1000);
        lcd.clear();                           ////////////////////////   начальный экран
        lcd.setCursor(5, 0);
        lcd.print("Введите код");
        lcd.setCursor(7, 1);
        lcd.print("товара");
        lcd.setCursor(0, 3);
       
        text = "";
      }
      if (text == "31" && p31 > 0) {
        lcd.clear();
        lcd.setCursor(5, 0);
        lcd.print("товар 31");
        lcd.setCursor(6, 1);
        lcd.print(p31);
        lcd.setCursor(10, 1);
        lcd.print("руб.");
        lcd.setCursor(0, 3);
        lcd.print("Е выбрать   С отмена");
        choiseflag31 = true;
        choiseflag = true;
        text = "";
        choise.setTimeout(choisetime);
      }
      if (text == "31" && p31 == 0) {
        lcd.clear();
        lcd.setCursor(2, 1);
        lcd.print("Выбор недоступен");
        delay(1000);
        lcd.clear();                           ////////////////////////   начальный экран
        lcd.setCursor(5, 0);
        lcd.print("Введите код");
        lcd.setCursor(7, 1);
        lcd.print("товара");
        lcd.setCursor(0, 3);
       
        text = "";
      }
      if (text == "32" && p32 > 0) {
        lcd.clear();
        lcd.setCursor(5, 0);
        lcd.print("товар 32");
        lcd.setCursor(6, 1);
        lcd.print(p32);
        lcd.setCursor(10, 1);
        lcd.print("руб.");
        lcd.setCursor(0, 3);
        lcd.print("Е выбрать   С отмена");
        choiseflag32 = true;
        choiseflag = true;
        text = "";
        choise.setTimeout(choisetime);
      }
      if (text == "32" && p32 == 0) {
        lcd.clear();
        lcd.setCursor(2, 1);
        lcd.print("Выбор недоступен");
        delay(1000);
        lcd.clear();                           ////////////////////////   начальный экран
        lcd.setCursor(5, 0);
        lcd.print("Введите код");
        lcd.setCursor(7, 1);
        lcd.print("товара");
        lcd.setCursor(0, 3);
       
        text = "";
      }
      if (text == "33" && p33 > 0) {
        lcd.clear();
        lcd.setCursor(5, 0);
        lcd.print("товар 33");
        lcd.setCursor(6, 1);
        lcd.print(p33);
        lcd.setCursor(10, 1);
        lcd.print("руб.");
        lcd.setCursor(0, 3);
        lcd.print("Е выбрать   С отмена");
        choiseflag33 = true;
        choiseflag = true;
        text = "";
        choise.setTimeout(choisetime);
      }
      if (text == "33" && p33 == 0) {
        lcd.clear();
        lcd.setCursor(2, 1);
        lcd.print("Выбор недоступен");
        delay(1000);
        lcd.clear();                           ////////////////////////   начальный экран
        lcd.setCursor(5, 0);
        lcd.print("Введите код");
        lcd.setCursor(7, 1);
        lcd.print("товара");
        lcd.setCursor(0, 3);
     
        text = "";
      }
      if (text == "34" && p34 > 0) {
        lcd.clear();
        lcd.setCursor(5, 0);
        lcd.print("товар 34");
        lcd.setCursor(6, 1);
        lcd.print(p34);
        lcd.setCursor(10, 1);
        lcd.print("руб.");
        lcd.setCursor(0, 3);
        lcd.print("Е выбрать   С отмена");
        choiseflag34 = true;
        choiseflag = true;
        text = "";
        choise.setTimeout(choisetime);
      }
      if (text == "34" && p34 == 0) {
        lcd.clear();
        lcd.setCursor(2, 1);
        lcd.print("Выбор недоступен");
        delay(1000);
        lcd.clear();                           ////////////////////////   начальный экран
        lcd.setCursor(5, 0);
        lcd.print("Введите код");
        lcd.setCursor(7, 1);
        lcd.print("товара");
        lcd.setCursor(0, 3);
       
        text = "";
      }
      if (text == "35" && p35 > 0) {
        lcd.clear();
        lcd.setCursor(5, 0);
        lcd.print("товар 35");
        lcd.setCursor(6, 1);
        lcd.print(p35);
        lcd.setCursor(10, 1);
        lcd.print("руб.");
        lcd.setCursor(0, 3);
        lcd.print("Е выбрать   С отмена");
        choiseflag35 = true;
        choiseflag = true;
        text = "";
        choise.setTimeout(choisetime);
      }
      if (text == "35" && p35 == 0) {
        lcd.clear();
        lcd.setCursor(2, 1);
        lcd.print("Выбор недоступен");
        delay(1000);
        lcd.clear();                           ////////////////////////   начальный экран
        lcd.setCursor(5, 0);
        lcd.print("Введите код");
        lcd.setCursor(7, 1);
        lcd.print("товара");
        lcd.setCursor(0, 3);
       
        text = "";
      }
      if (text == "36" && p36 > 0) {
        lcd.clear();
        lcd.setCursor(5, 0);
        lcd.print("товар 36");
        lcd.setCursor(6, 1);
        lcd.print(p36);
        lcd.setCursor(10, 1);
        lcd.print("руб.");
        lcd.setCursor(0, 3);
        lcd.print("Е выбрать   С отмена");
        choiseflag36 = true;
        choiseflag = true;
        text = "";
        choise.setTimeout(choisetime);
      }
      if (text == "36" && p36 == 0) {
        lcd.clear();
        lcd.setCursor(2, 1);
        lcd.print("Выбор недоступен");
        delay(1000);
        lcd.clear();                           ////////////////////////   начальный экран
        lcd.setCursor(5, 0);
        lcd.print("Введите код");
        lcd.setCursor(7, 1);
        lcd.print("товара");
        lcd.setCursor(0, 3);
      
        text = "";
      }
      if (text == "37" && p37 > 0) {
        lcd.clear();
        lcd.setCursor(5, 0);
        lcd.print("товар 37");
        lcd.setCursor(6, 1);
        lcd.print(p37);
        lcd.setCursor(10, 1);
        lcd.print("руб.");
        lcd.setCursor(0, 3);
        lcd.print("Е выбрать   С отмена");
        choiseflag37 = true;
        choiseflag = true;
        text = "";
        choise.setTimeout(choisetime);
      }
      if (text == "37" && p37 == 0) {
        lcd.clear();
        lcd.setCursor(2, 1);
        lcd.print("Выбор недоступен");
        delay(1000);
        lcd.clear();                           ////////////////////////   начальный экран
        lcd.setCursor(5, 0);
        lcd.print("Введите код");
        lcd.setCursor(7, 1);
        lcd.print("товара");
        lcd.setCursor(0, 3);
       
        text = "";
      }
      if (text == "38" && p38 > 0) {
        lcd.clear();
        lcd.setCursor(5, 0);
        lcd.print("товар 38");
        lcd.setCursor(6, 1);
        lcd.print(p38);
        lcd.setCursor(10, 1);
        lcd.print("руб.");
        lcd.setCursor(0, 3);
        lcd.print("Е выбрать   С отмена");
        choiseflag38 = true;
        choiseflag = true;
        text = "";
        choise.setTimeout(choisetime);
      }
      if (text == "38" && p38 == 0) {
        lcd.clear();
        lcd.setCursor(2, 1);
        lcd.print("Выбор недоступен");
        delay(1000);
        lcd.clear();                           ////////////////////////   начальный экран
        lcd.setCursor(5, 0);
        lcd.print("Введите код");
        lcd.setCursor(7, 1);
        lcd.print("товара");
        lcd.setCursor(0, 3);
       
        text = "";
      }
      if (text == "39" && p39 > 0) {
        lcd.clear();
        lcd.setCursor(5, 0);
        lcd.print("товар 39");
        lcd.setCursor(6, 1);
        lcd.print(p39);
        lcd.setCursor(10, 1);
        lcd.print("руб.");
        lcd.setCursor(0, 3);
        lcd.print("Е выбрать   С отмена");
        choiseflag39 = true;
        choiseflag = true;
        text = "";
        choise.setTimeout(choisetime);
      }
      if (text == "39" && p39 == 0) {
        lcd.clear();
        lcd.setCursor(2, 1);
        lcd.print("Выбор недоступен");
        delay(1000);
        lcd.clear();                           ////////////////////////   начальный экран
        lcd.setCursor(5, 0);
        lcd.print("Введите код");
        lcd.setCursor(7, 1);
        lcd.print("товара");
        lcd.setCursor(0, 3);
      
        text = "";
      }
      if (text == "40" && p40 > 0) {
        lcd.clear();
        lcd.setCursor(5, 0);
        lcd.print("товар 40");
        lcd.setCursor(6, 1);
        lcd.print(p40);
        lcd.setCursor(10, 1);
        lcd.print("руб.");
        lcd.setCursor(0, 3);
        lcd.print("Е выбрать   С отмена");
        choiseflag40 = true;
        choiseflag = true;
        text = "";
        choise.setTimeout(choisetime);
      }
      if (text == "40" && p40 == 0) {
        lcd.clear();
        lcd.setCursor(2, 1);
        lcd.print("Выбор недоступен");
        delay(1000);
        lcd.clear();                           ////////////////////////   начальный экран
        lcd.setCursor(5, 0);
        lcd.print("Введите код");
        lcd.setCursor(7, 1);
        lcd.print("товара");
        lcd.setCursor(0, 3);
     
        text = "";
      }
      if (text == "41" && p41 > 0) {
        lcd.clear();
        lcd.setCursor(5, 0);
        lcd.print("товар 41");
        lcd.setCursor(6, 1);
        lcd.print(p41);
        lcd.setCursor(10, 1);
        lcd.print("руб.");
        lcd.setCursor(0, 3);
        lcd.print("Е выбрать   С отмена");
        choiseflag41 = true;
        choiseflag = true;
        text = "";
        choise.setTimeout(choisetime);
      }
      if (text == "41" && p41 == 0) {
        lcd.clear();
        lcd.setCursor(2, 1);
        lcd.print("Выбор недоступен");
        delay(1000);
        lcd.clear();                           ////////////////////////   начальный экран
        lcd.setCursor(5, 0);
        lcd.print("Введите код");
        lcd.setCursor(7, 1);
        lcd.print("товара");
        lcd.setCursor(0, 3);
      
        text = "";
      }
      if (text == "42" && p42 > 0) {
        lcd.clear();
        lcd.setCursor(5, 0);
        lcd.print("товар 42");
        lcd.setCursor(6, 1);
        lcd.print(p42);
        lcd.setCursor(10, 1);
        lcd.print("руб.");
        lcd.setCursor(0, 3);
        lcd.print("Е выбрать   С отмена");
        choiseflag42 = true;
        choiseflag = true;
        text = "";
        choise.setTimeout(choisetime);
      }
      if (text == "42" && p42 == 0) {
        lcd.clear();
        lcd.setCursor(2, 1);
        lcd.print("Выбор недоступен");
        delay(1000);
        lcd.clear();                           ////////////////////////   начальный экран
        lcd.setCursor(5, 0);
        lcd.print("Введите код");
        lcd.setCursor(7, 1);
        lcd.print("товара");
        lcd.setCursor(0, 3);
     
        text = "";
      }
      if (text == "43" && p43 > 0) {
        lcd.clear();
        lcd.setCursor(5, 0);
        lcd.print("товар 43");
        lcd.setCursor(6, 1);
        lcd.print(p43);
        lcd.setCursor(10, 1);
        lcd.print("руб.");
        lcd.setCursor(0, 3);
        lcd.print("Е выбрать   С отмена");
        choiseflag43 = true;
        choiseflag = true;
        text = "";
        choise.setTimeout(choisetime);
      }
      if (text == "43" && p43 == 0) {
        lcd.clear();
        lcd.setCursor(2, 1);
        lcd.print("Выбор недоступен");
        delay(1000);
        lcd.clear();                           ////////////////////////   начальный экран
        lcd.setCursor(5, 0);
        lcd.print("Введите код");
        lcd.setCursor(7, 1);
        lcd.print("товара");
        lcd.setCursor(0, 3);
       
        text = "";
      }
      if (text == "44" && p44 > 0) {
        lcd.clear();
        lcd.setCursor(5, 0);
        lcd.print("товар 44");
        lcd.setCursor(6, 1);
        lcd.print(p44);
        lcd.setCursor(10, 1);
        lcd.print("руб.");
        lcd.setCursor(0, 3);
        lcd.print("Е выбрать   С отмена");
        choiseflag44 = true;
        choiseflag = true;
        text = "";
        choise.setTimeout(choisetime);
      }
      if (text == "44" && p44 == 0) {
        lcd.clear();
        lcd.setCursor(2, 1);
        lcd.print("Выбор недоступен");
        delay(1000);
        lcd.clear();                           ////////////////////////   начальный экран
        lcd.setCursor(5, 0);
        lcd.print("Введите код");
        lcd.setCursor(7, 1);
        lcd.print("товара");
        lcd.setCursor(0, 3);
       
        text = "";
      }
      if (text == "45" && p45 > 0) {
        lcd.clear();
        lcd.setCursor(5, 0);
        lcd.print("товар 45");
        lcd.setCursor(6, 1);
        lcd.print(p45);
        lcd.setCursor(10, 1);
        lcd.print("руб.");
        lcd.setCursor(0, 3);
        lcd.print("Е выбрать   С отмена");
        choiseflag45 = true;
        choiseflag = true;
        text = "";
        choise.setTimeout(choisetime);
      }
      if (text == "45" && p45 == 0) {
        lcd.clear();
        lcd.setCursor(2, 1);
        lcd.print("Выбор недоступен");
        delay(1000);
        lcd.clear();                           ////////////////////////   начальный экран
        lcd.setCursor(5, 0);
        lcd.print("Введите код");
        lcd.setCursor(7, 1);
        lcd.print("товара");
        lcd.setCursor(0, 3);
       
        text = "";
      }
      if (text == "46" && p46 > 0) {
        lcd.clear();
        lcd.setCursor(5, 0);
        lcd.print("товар 46");
        lcd.setCursor(6, 1);
        lcd.print(p46);
        lcd.setCursor(10, 1);
        lcd.print("руб.");
        lcd.setCursor(0, 3);
        lcd.print("Е выбрать   С отмена");
        choiseflag46 = true;
        choiseflag = true;
        text = "";
        choise.setTimeout(choisetime);
      }
      if (text == "46" && p46 == 0) {
        lcd.clear();
        lcd.setCursor(2, 1);
        lcd.print("Выбор недоступен");
        delay(1000);
        lcd.clear();                           ////////////////////////   начальный экран
        lcd.setCursor(5, 0);
        lcd.print("Введите код");
        lcd.setCursor(7, 1);
        lcd.print("товара");
        lcd.setCursor(0, 3);
       
        text = "";
      }
      if (text == "47" && p47 > 0) {
        lcd.clear();
        lcd.setCursor(5, 0);
        lcd.print("товар 47");
        lcd.setCursor(6, 1);
        lcd.print(p47);
        lcd.setCursor(10, 1);
        lcd.print("руб.");
        lcd.setCursor(0, 3);
        lcd.print("Е выбрать   С отмена");
        choiseflag47 = true;
        choiseflag = true;
        text = "";
        choise.setTimeout(choisetime);
      }
      if (text == "47" && p47 == 0) {
        lcd.clear();
        lcd.setCursor(2, 1);
        lcd.print("Выбор недоступен");
        delay(1000);
        lcd.clear();                           ////////////////////////   начальный экран
        lcd.setCursor(5, 0);
        lcd.print("Введите код");
        lcd.setCursor(7, 1);
        lcd.print("товара");
        lcd.setCursor(0, 3);
      
        text = "";
      }
      if (text == "48" && p48 > 0) {
        lcd.clear();
        lcd.setCursor(5, 0);
        lcd.print("товар 48");
        lcd.setCursor(6, 1);
        lcd.print(p48);
        lcd.setCursor(10, 1);
        lcd.print("руб.");
        lcd.setCursor(0, 3);
        lcd.print("Е выбрать   С отмена");
        choiseflag48 = true;
        choiseflag = true;
        text = "";
        choise.setTimeout(choisetime);
      }
      if (text == "48" && p48 == 0) {
        lcd.clear();
        lcd.setCursor(2, 1);
        lcd.print("Выбор недоступен");
        delay(1000);
        lcd.clear();                           ////////////////////////   начальный экран
        lcd.setCursor(5, 0);
        lcd.print("Введите код");
        lcd.setCursor(7, 1);
        lcd.print("товара");
        lcd.setCursor(0, 3);
       
        text = "";
      }
      if (text == "49" && p49 > 0) {
        lcd.clear();
        lcd.setCursor(5, 0);
        lcd.print("товар 49");
        lcd.setCursor(6, 1);
        lcd.print(p49);
        lcd.setCursor(10, 1);
        lcd.print("руб.");
        lcd.setCursor(0, 3);
        lcd.print("Е выбрать   С отмена");
        choiseflag49 = true;
        choiseflag = true;
        text = "";
        choise.setTimeout(choisetime);
      }
      if (text == "49" && p49 == 0) {
        lcd.clear();
        lcd.setCursor(2, 1);
        lcd.print("Выбор недоступен");
        delay(1000);
        lcd.clear();                           ////////////////////////   начальный экран
        lcd.setCursor(5, 0);
        lcd.print("Введите код");
        lcd.setCursor(7, 1);
        lcd.print("товара");
        lcd.setCursor(0, 3);
        
        text = "";
      }
      if (text == "50" && p50 > 0) {
        lcd.clear();
        lcd.setCursor(5, 0);
        lcd.print("товар 50");
        lcd.setCursor(6, 1);
        lcd.print(p50);
        lcd.setCursor(10, 1);
        lcd.print("руб.");
        lcd.setCursor(0, 3);
        lcd.print("Е выбрать   С отмена");
        choiseflag50 = true;
        choiseflag = true;
        text = "";
        choise.setTimeout(choisetime);
      }
      if (text == "50" && p50 == 0) {
        lcd.clear();
        lcd.setCursor(2, 1);
        lcd.print("Выбор недоступен");
        delay(1000);
        lcd.clear();                           ////////////////////////   начальный экран
        lcd.setCursor(5, 0);
        lcd.print("Введите код");
        lcd.setCursor(7, 1);
        lcd.print("товара");
        lcd.setCursor(0, 3);
       
        text = "";
      }
      if (text == "51" && p51 > 0) {
        lcd.clear();
        lcd.setCursor(5, 0);
        lcd.print("товар 51");
        lcd.setCursor(6, 1);
        lcd.print(p51);
        lcd.setCursor(10, 1);
        lcd.print("руб.");
        lcd.setCursor(0, 3);
        lcd.print("Е выбрать   С отмена");
        choiseflag51 = true;
        choiseflag = true;
        text = "";
        choise.setTimeout(choisetime);
      }
      if (text == "51" && p51 == 0) {
        lcd.clear();
        lcd.setCursor(2, 1);
        lcd.print("Выбор недоступен");
        delay(1000);
        lcd.clear();                           ////////////////////////   начальный экран
        lcd.setCursor(5, 0);
        lcd.print("Введите код");
        lcd.setCursor(7, 1);
        lcd.print("товара");
        lcd.setCursor(0, 3);
        
        text = "";
      }
      if (text == "52" && p52 > 0) {
        lcd.clear();
        lcd.setCursor(5, 0);
        lcd.print("товар 52");
        lcd.setCursor(6, 1);
        lcd.print(p52);
        lcd.setCursor(10, 1);
        lcd.print("руб.");
        lcd.setCursor(0, 3);
        lcd.print("Е выбрать   С отмена");
        choiseflag52 = true;
        choiseflag = true;
        text = "";
        choise.setTimeout(choisetime);
      }
      if (text == "52" && p52 == 0) {
        lcd.clear();
        lcd.setCursor(2, 1);
        lcd.print("Выбор недоступен");
        delay(1000);
        lcd.clear();                           ////////////////////////   начальный экран
        lcd.setCursor(5, 0);
        lcd.print("Введите код");
        lcd.setCursor(7, 1);
        lcd.print("товара");
        lcd.setCursor(0, 3);
       
        text = "";
      }
      if (text == "53" && p53 > 0) {
        lcd.clear();
        lcd.setCursor(5, 0);
        lcd.print("товар 53");
        lcd.setCursor(6, 1);
        lcd.print(p53);
        lcd.setCursor(10, 1);
        lcd.print("руб.");
        lcd.setCursor(0, 3);
        lcd.print("Е выбрать   С отмена");
        choiseflag53 = true;
        choiseflag = true;
        text = "";
        choise.setTimeout(choisetime);
      }
      if (text == "53" && p53 == 0) {
        lcd.clear();
        lcd.setCursor(2, 1);
        lcd.print("Выбор недоступен");
        delay(1000);
        lcd.clear();                           ////////////////////////   начальный экран
        lcd.setCursor(5, 0);
        lcd.print("Введите код");
        lcd.setCursor(7, 1);
        lcd.print("товара");
        lcd.setCursor(0, 3);
        
        text = "";
      }
      if (text == "54" && p54 > 0) {
        lcd.clear();
        lcd.setCursor(5, 0);
        lcd.print("товар 54");
        lcd.setCursor(6, 1);
        lcd.print(p54);
        lcd.setCursor(10, 1);
        lcd.print("руб.");
        lcd.setCursor(0, 3);
        lcd.print("Е выбрать   С отмена");
        choiseflag54 = true;
        choiseflag = true;
        text = "";
        choise.setTimeout(choisetime);
      }
      if (text == "54" && p54 == 0) {
        lcd.clear();
        lcd.setCursor(2, 1);
        lcd.print("Выбор недоступен");
        delay(1000);
        lcd.clear();                           ////////////////////////   начальный экран
        lcd.setCursor(5, 0);
        lcd.print("Введите код");
        lcd.setCursor(7, 1);
        lcd.print("товара");
        lcd.setCursor(0, 3);
       
        text = "";
      }
      if (text == "55" && p55 > 0) {
        lcd.clear();
        lcd.setCursor(5, 0);
        lcd.print("товар 55");
        lcd.setCursor(6, 1);
        lcd.print(p55);
        lcd.setCursor(10, 1);
        lcd.print("руб.");
        lcd.setCursor(0, 3);
        lcd.print("Е выбрать   С отмена");
        choiseflag55 = true;
        choiseflag = true;
        text = "";
        choise.setTimeout(choisetime);
      }
      if (text == "55" && p55 == 0) {
        lcd.clear();
        lcd.setCursor(2, 1);
        lcd.print("Выбор недоступен");
        delay(1000);
        lcd.clear();                           ////////////////////////   начальный экран
        lcd.setCursor(5, 0);
        lcd.print("Введите код");
        lcd.setCursor(7, 1);
        lcd.print("товара");
        lcd.setCursor(0, 3);
      
        text = "";
      }
      if (text == "56" && p56 > 0) {
        lcd.clear();
        lcd.setCursor(5, 0);
        lcd.print("товар 56");
        lcd.setCursor(6, 1);
        lcd.print(p56);
        lcd.setCursor(10, 1);
        lcd.print("руб.");
        lcd.setCursor(0, 3);
        lcd.print("Е выбрать   С отмена");
        choiseflag56 = true;
        choiseflag = true;
        text = "";
        choise.setTimeout(choisetime);
      }
      if (text == "56" && p56 == 0) {
        lcd.clear();
        lcd.setCursor(2, 1);
        lcd.print("Выбор недоступен");
        delay(1000);
        lcd.clear();                           ////////////////////////   начальный экран
        lcd.setCursor(5, 0);
        lcd.print("Введите код");
        lcd.setCursor(7, 1);
        lcd.print("товара");
        lcd.setCursor(0, 3);
       
        text = "";
      }
      if (text == "57" && p57 > 0) {
        lcd.clear();
        lcd.setCursor(5, 0);
        lcd.print("товар 57");
        lcd.setCursor(6, 1);
        lcd.print(p57);
        lcd.setCursor(10, 1);
        lcd.print("руб.");
        lcd.setCursor(0, 3);
        lcd.print("Е выбрать   С отмена");
        choiseflag57 = true;
        choiseflag = true;
        text = "";
        choise.setTimeout(choisetime);
      }
      if (text == "57" && p57 == 0) {
        lcd.clear();
        lcd.setCursor(2, 1);
        lcd.print("Выбор недоступен");
        delay(1000);
        lcd.clear();                           ////////////////////////   начальный экран
        lcd.setCursor(5, 0);
        lcd.print("Введите код");
        lcd.setCursor(7, 1);
        lcd.print("товара");
        lcd.setCursor(0, 3);
     
        text = "";
      }
      if (text == "58" && p58 > 0) {
        lcd.clear();
        lcd.setCursor(5, 0);
        lcd.print("товар 58");
        lcd.setCursor(6, 1);
        lcd.print(p58);
        lcd.setCursor(10, 1);
        lcd.print("руб.");
        lcd.setCursor(0, 3);
        lcd.print("Е выбрать   С отмена");
        choiseflag58 = true;
        choiseflag = true;
        text = "";
        choise.setTimeout(choisetime);
      }
      if (text == "58" && p58 == 0) {
        lcd.clear();
        lcd.setCursor(2, 1);
        lcd.print("Выбор недоступен");
        delay(1000);
        lcd.clear();                           ////////////////////////   начальный экран
        lcd.setCursor(5, 0);
        lcd.print("Введите код");
        lcd.setCursor(7, 1);
        lcd.print("товара");
        lcd.setCursor(0, 3);
       
        text = "";
      }
      if (text == "59" && p59 > 0) {
        lcd.clear();
        lcd.setCursor(5, 0);
        lcd.print("товар 59");
        lcd.setCursor(6, 1);
        lcd.print(p59);
        lcd.setCursor(10, 1);
        lcd.print("руб.");
        lcd.setCursor(0, 3);
        lcd.print("Е выбрать   С отмена");
        choiseflag59 = true;
        choiseflag = true;
        text = "";
        choise.setTimeout(choisetime);
      }
      if (text == "59" && p59 == 0) {
        lcd.clear();
        lcd.setCursor(2, 1);
        lcd.print("Выбор недоступен");
        delay(1000);
        lcd.clear();                           ////////////////////////   начальный экран
        lcd.setCursor(5, 0);
        lcd.print("Введите код");
        lcd.setCursor(7, 1);
        lcd.print("товара");
        lcd.setCursor(0, 3);
       
        text = "";
      }
      if (text == "60" && p60 > 0) {
        lcd.clear();
        lcd.setCursor(5, 0);
        lcd.print("товар 60");
        lcd.setCursor(6, 1);
        lcd.print(p60);
        lcd.setCursor(10, 1);
        lcd.print("руб.");
        lcd.setCursor(0, 3);
        lcd.print("Е выбрать   С отмена");
        choiseflag60 = true;
        choiseflag = true;
        text = "";
        choise.setTimeout(choisetime);
      }
      if (text == "60" && p60 == 0) {
        lcd.clear();
        lcd.setCursor(2, 1);
        lcd.print("Выбор недоступен");
        delay(1000);
        lcd.clear();                           ////////////////////////   начальный экран
        lcd.setCursor(5, 0);
        lcd.print("Введите код");
        lcd.setCursor(7, 1);
        lcd.print("товара");
     
        text = "";
      }
      if (text == "61" && p61 > 0) {
        lcd.clear();
        lcd.setCursor(5, 0);
        lcd.print("товар 61");
        lcd.setCursor(6, 1);
        lcd.print(p61);
        lcd.setCursor(10, 1);
        lcd.print("руб.");
        lcd.setCursor(0, 3);
        lcd.print("Е выбрать   С отмена");
        choiseflag61 = true;
        choiseflag = true;
        text = "";
        choise.setTimeout(choisetime);
      }
      if (text == "61" && p61 == 0) {
        lcd.clear();
        lcd.setCursor(2, 1);
        lcd.print("Выбор недоступен");
        delay(1000);
        lcd.clear();                           ////////////////////////   начальный экран
        lcd.setCursor(5, 0);
        lcd.print("Введите код");
        lcd.setCursor(7, 1);
        lcd.print("товара");
     
        text = "";
      }
      if (text == "62" && p62 > 0) {
        lcd.clear();
        lcd.setCursor(5, 0);
        lcd.print("товар 62");
        lcd.setCursor(6, 1);
        lcd.print(p62);
        lcd.setCursor(10, 1);
        lcd.print("руб.");
        lcd.setCursor(0, 3);
        lcd.print("Е выбрать   С отмена");
        choiseflag62 = true;
        choiseflag = true;
        text = "";
        choise.setTimeout(choisetime);
      }
      if (text == "62" && p62 == 0) {
        lcd.clear();
        lcd.setCursor(2, 1);
        lcd.print("Выбор недоступен");
        delay(1000);
        lcd.clear();                           ////////////////////////   начальный экран
        lcd.setCursor(5, 0);
        lcd.print("Введите код");
        lcd.setCursor(7, 1);
        lcd.print("товара");
    
        text = "";
      }
      if (text == "63" && p63 > 0) {
        lcd.clear();
        lcd.setCursor(5, 0);
        lcd.print("товар 63");
        lcd.setCursor(6, 1);
        lcd.print(p63);
        lcd.setCursor(10, 1);
        lcd.print("руб.");
        lcd.setCursor(0, 3);
        lcd.print("Е выбрать   С отмена");
        choiseflag63 = true;
        choiseflag = true;
        text = "";
        choise.setTimeout(choisetime);
      }
      if (text == "63" && p63 == 0) {
        lcd.clear();
        lcd.setCursor(2, 1);
        lcd.print("Выбор недоступен");
        delay(1000);
        lcd.clear();                           ////////////////////////   начальный экран
        lcd.setCursor(5, 0);
        lcd.print("Введите код");
        lcd.setCursor(7, 1);
        lcd.print("товара");
   
        text = "";
      }
      if (text == "64" && p64 > 0) {
        lcd.clear();
        lcd.setCursor(5, 0);
        lcd.print("товар 64");
        lcd.setCursor(6, 1);
        lcd.print(p64);
        lcd.setCursor(10, 1);
        lcd.print("руб.");
        lcd.setCursor(0, 3);
        lcd.print("Е выбрать   С отмена");
        choiseflag64 = true;
        choiseflag = true;
        text = "";
        choise.setTimeout(choisetime);
      }
      if (text == "64" && p64 == 0) {
        lcd.clear();
        lcd.setCursor(2, 1);
        lcd.print("Выбор недоступен");
        delay(1000);
        lcd.clear();                           ////////////////////////   начальный экран
        lcd.setCursor(5, 0);
        lcd.print("Введите код");
        lcd.setCursor(7, 1);
        lcd.print("товара");
     
        text = "";
      }
      if (text == "65" && p65 > 0) {
        lcd.clear();
        lcd.setCursor(5, 0);
        lcd.print("товар 65");
        lcd.setCursor(6, 1);
        lcd.print(p65);
        lcd.setCursor(10, 1);
        lcd.print("руб.");
        lcd.setCursor(0, 3);
        lcd.print("Е выбрать   С отмена");
        choiseflag65 = true;
        choiseflag = true;
        text = "";
        choise.setTimeout(choisetime);
      }
      if (text == "65" && p65 == 0) {
        lcd.clear();
        lcd.setCursor(2, 1);
        lcd.print("Выбор недоступен");
        delay(1000);
        lcd.clear();                           ////////////////////////   начальный экран
        lcd.setCursor(5, 0);
        lcd.print("Введите код");
        lcd.setCursor(7, 1);
        lcd.print("товара");
      
        text = "";
      }
      if (text == "66" && p66 > 0) {
        lcd.clear();
        lcd.setCursor(5, 0);
        lcd.print("товар 66");
        lcd.setCursor(6, 1);
        lcd.print(p66);
        lcd.setCursor(10, 1);
        lcd.print("руб.");
        lcd.setCursor(0, 3);
        lcd.print("Е выбрать   С отмена");
        choiseflag66 = true;
        choiseflag = true;
        text = "";
        choise.setTimeout(choisetime);
      }
      if (text == "66" && p66 == 0) {
        lcd.clear();
        lcd.setCursor(2, 1);
        lcd.print("Выбор недоступен");
        delay(1000);
        lcd.clear();                           ////////////////////////   начальный экран
        lcd.setCursor(5, 0);
        lcd.print("Введите код");
        lcd.setCursor(7, 1);
        lcd.print("товара");
    
        text = "";
      }
      if (text == "67" && p67 > 0) {
        lcd.clear();
        lcd.setCursor(5, 0);
        lcd.print("товар 67");
        lcd.setCursor(6, 1);
        lcd.print(p67);
        lcd.setCursor(10, 1);
        lcd.print("руб.");
        lcd.setCursor(0, 3);
        lcd.print("Е выбрать   С отмена");
        choiseflag67 = true;
        choiseflag = true;
        text = "";
        choise.setTimeout(choisetime);
      }
      if (text == "67" && p67 == 0) {
        lcd.clear();
        lcd.setCursor(2, 1);
        lcd.print("Выбор недоступен");
        delay(1000);
        lcd.clear();                           ////////////////////////   начальный экран
        lcd.setCursor(5, 0);
        lcd.print("Введите код");
        lcd.setCursor(7, 1);
        lcd.print("товара");
      
        text = "";
      }
      if (text == "68" && p68 > 0) {
        lcd.clear();
        lcd.setCursor(5, 0);
        lcd.print("товар 68");
        lcd.setCursor(6, 1);
        lcd.print(p68);
        lcd.setCursor(10, 1);
        lcd.print("руб.");
        lcd.setCursor(0, 3);
        lcd.print("Е выбрать   С отмена");
        choiseflag68 = true;
        choiseflag = true;
        text = "";
        choise.setTimeout(choisetime);
      }
      if (text == "68" && p68 == 0) {
        lcd.clear();
        lcd.setCursor(2, 1);
        lcd.print("Выбор недоступен");
        delay(1000);
        lcd.clear();                           ////////////////////////   начальный экран
        lcd.setCursor(5, 0);
        lcd.print("Введите код");
        lcd.setCursor(7, 1);
        lcd.print("товара");
      
        text = "";
      }
      if (text == "69" && p69 > 0) {
        lcd.clear();
        lcd.setCursor(5, 0);
        lcd.print("товар 69");
        lcd.setCursor(6, 1);
        lcd.print(p69);
        lcd.setCursor(10, 1);
        lcd.print("руб.");
        lcd.setCursor(0, 3);
        lcd.print("Е выбрать   С отмена");
        choiseflag69 = true;
        choiseflag = true;
        text = "";
        choise.setTimeout(choisetime);
      }
      if (text == "69" && p69 == 0) {
        lcd.clear();
        lcd.setCursor(2, 1);
        lcd.print("Выбор недоступен");
        delay(1000);
        lcd.clear();                           ////////////////////////   начальный экран
        lcd.setCursor(5, 0);
        lcd.print("Введите код");
        lcd.setCursor(7, 1);
        lcd.print("товара");
      
        text = "";
      }
      if (text == "70" && p70 > 0) {
        lcd.clear();
        lcd.setCursor(5, 0);
        lcd.print("товар 70");
        lcd.setCursor(6, 1);
        lcd.print(p70);
        lcd.setCursor(10, 1);
        lcd.print("руб.");
        lcd.setCursor(0, 3);
        lcd.print("Е выбрать   С отмена");
        choiseflag70 = true;
        choiseflag = true;
        text = "";
        choise.setTimeout(choisetime);
      }
      if (text == "70" && p70 == 0) {
        lcd.clear();
        lcd.setCursor(2, 1);
        lcd.print("Выбор недоступен");
        delay(1000);
        lcd.clear();                           ////////////////////////   начальный экран
        lcd.setCursor(5, 0);
        lcd.print("Введите код");
        lcd.setCursor(7, 1);
        lcd.print("товара");
     
        text = "";
      }
      if (text == "71" && p71 > 0) {
        lcd.clear();
        lcd.setCursor(5, 0);
        lcd.print("товар 71");
        lcd.setCursor(6, 1);
        lcd.print(p71);
        lcd.setCursor(10, 1);
        lcd.print("руб.");
        lcd.setCursor(0, 3);
        lcd.print("Е выбрать   С отмена");
        choiseflag71 = true;
        choiseflag = true;
        text = "";
        choise.setTimeout(choisetime);
      }
      if (text == "71" && p71 == 0) {
        lcd.clear();
        lcd.setCursor(2, 1);
        lcd.print("Выбор недоступен");
        delay(1000);
        lcd.clear();                           ////////////////////////   начальный экран
        lcd.setCursor(5, 0);
        lcd.print("Введите код");
        lcd.setCursor(7, 1);
        lcd.print("товара");
      
        text = "";
      }
      if (text == "72" && p72 > 0) {
        lcd.clear();
        lcd.setCursor(5, 0);
        lcd.print("товар 72");
        lcd.setCursor(6, 1);
        lcd.print(p72);
        lcd.setCursor(10, 1);
        lcd.print("руб.");
        lcd.setCursor(0, 3);
        lcd.print("Е выбрать   С отмена");
        choiseflag72 = true;
        choiseflag = true;
        text = "";
        choise.setTimeout(choisetime);
      }
      if (text == "72" && p72 == 0) {
        lcd.clear();
        lcd.setCursor(2, 1);
        lcd.print("Выбор недоступен");
        delay(1000);
        lcd.clear();                           ////////////////////////   начальный экран
        lcd.setCursor(5, 0);
        lcd.print("Введите код");
        lcd.setCursor(7, 1);
        lcd.print("товара");
       
        text = "";
      }
      if (text == "73" && p73 > 0) {
        lcd.clear();
        lcd.setCursor(5, 0);
        lcd.print("товар 73");
        lcd.setCursor(6, 1);
        lcd.print(p73);
        lcd.setCursor(10, 1);
        lcd.print("руб.");
        lcd.setCursor(0, 3);
        lcd.print("Е выбрать   С отмена");
        choiseflag73 = true;
        choiseflag = true;
        text = "";
        choise.setTimeout(choisetime);
      }
      if (text == "73" && p73 == 0) {
        lcd.clear();
        lcd.setCursor(2, 1);
        lcd.print("Выбор недоступен");
        delay(1000);
        lcd.clear();                           ////////////////////////   начальный экран
        lcd.setCursor(5, 0);
        lcd.print("Введите код");
        lcd.setCursor(7, 1);
        lcd.print("товара");
      
        text = "";
      }
      if (text == "74" && p74 > 0) {
        lcd.clear();
        lcd.setCursor(5, 0);
        lcd.print("товар 74");
        lcd.setCursor(6, 1);
        lcd.print(p74);
        lcd.setCursor(10, 1);
        lcd.print("руб.");
        lcd.setCursor(0, 3);
        lcd.print("Е выбрать   С отмена");
        choiseflag74 = true;
        choiseflag = true;
        text = "";
        choise.setTimeout(choisetime);
      }
      if (text == "74" && p74 == 0) {
        lcd.clear();
        lcd.setCursor(2, 1);
        lcd.print("Выбор недоступен");
        delay(1000);
        lcd.clear();                           ////////////////////////   начальный экран
        lcd.setCursor(5, 0);
        lcd.print("Введите код");
        lcd.setCursor(7, 1);
        lcd.print("товара");
       
        text = "";
      }
      if (text == "75" && p75 > 0) {
        lcd.clear();
        lcd.setCursor(5, 0);
        lcd.print("товар 75");
        lcd.setCursor(6, 1);
        lcd.print(p75);
        lcd.setCursor(10, 1);
        lcd.print("руб.");
        lcd.setCursor(0, 3);
        lcd.print("Е выбрать   С отмена");
        choiseflag75 = true;
        choiseflag = true;
        text = "";
        choise.setTimeout(choisetime);
      }
      if (text == "75" && p75 == 0) {
        lcd.clear();
        lcd.setCursor(2, 1);
        lcd.print("Выбор недоступен");
        delay(1000);
        lcd.clear();                           ////////////////////////   начальный экран
        lcd.setCursor(5, 0);
        lcd.print("Введите код");
        lcd.setCursor(7, 1);
        lcd.print("товара");
        
        text = "";
      }
      if (text == "76" && p76 > 0) {
        lcd.clear();
        lcd.setCursor(5, 0);
        lcd.print("товар 76");
        lcd.setCursor(6, 1);
        lcd.print(p76);
        lcd.setCursor(10, 1);
        lcd.print("руб.");
        lcd.setCursor(0, 3);
        lcd.print("Е выбрать   С отмена");
        choiseflag76 = true;
        choiseflag = true;
        text = "";
        choise.setTimeout(choisetime);
      }
      if (text == "76" && p76 == 0) {
        lcd.clear();
        lcd.setCursor(2, 1);
        lcd.print("Выбор недоступен");
        delay(1000);
        lcd.clear();                           ////////////////////////   начальный экран
        lcd.setCursor(5, 0);
        lcd.print("Введите код");
        lcd.setCursor(7, 1);
        lcd.print("товара");
       
        text = "";
      }
      if (text == "77" && p77 > 0) {
        lcd.clear();
        lcd.setCursor(5, 0);
        lcd.print("товар 77");
        lcd.setCursor(6, 1);
        lcd.print(p77);
        lcd.setCursor(10, 1);
        lcd.print("руб.");
        lcd.setCursor(0, 3);
        lcd.print("Е выбрать   С отмена");
        choiseflag77 = true;
        choiseflag = true;
        text = "";
        choise.setTimeout(choisetime);
      }
      if (text == "77" && p77 == 0) {
        lcd.clear();
        lcd.setCursor(2, 1);
        lcd.print("Выбор недоступен");
        delay(1000);
        lcd.clear();                           ////////////////////////   начальный экран
        lcd.setCursor(5, 0);
        lcd.print("Введите код");
        lcd.setCursor(7, 1);
        lcd.print("товара");
       
        text = "";
      }
      if (text == "78" && p78 > 0) {
        lcd.clear();
        lcd.setCursor(5, 0);
        lcd.print("товар 78");
        lcd.setCursor(6, 1);
        lcd.print(p78);
        lcd.setCursor(10, 1);
        lcd.print("руб.");
        lcd.setCursor(0, 3);
        lcd.print("Е выбрать   С отмена");
        choiseflag78 = true;
        choiseflag = true;
        text = "";
        choise.setTimeout(choisetime);
      }
      if (text == "78" && p78 == 0) {
        lcd.clear();
        lcd.setCursor(2, 1);
        lcd.print("Выбор недоступен");
        delay(1000);
        lcd.clear();                           ////////////////////////   начальный экран
        lcd.setCursor(5, 0);
        lcd.print("Введите код");
        lcd.setCursor(7, 1);
        lcd.print("товара");
       
        text = "";
      }
      if (text == "79" && p79 > 0) {
        lcd.clear();
        lcd.setCursor(5, 0);
        lcd.print("товар 79");
        lcd.setCursor(6, 1);
        lcd.print(p79);
        lcd.setCursor(10, 1);
        lcd.print("руб.");
        lcd.setCursor(0, 3);
        lcd.print("Е выбрать   С отмена");
        choiseflag79 = true;
        choiseflag = true;
        text = "";
        choise.setTimeout(choisetime);
      }
      if (text == "79" && p79 == 0) {
        lcd.clear();
        lcd.setCursor(2, 1);
        lcd.print("Выбор недоступен");
        delay(1000);
        lcd.clear();                           ////////////////////////   начальный экран
        lcd.setCursor(5, 0);
        lcd.print("Введите код");
        lcd.setCursor(7, 1);
        lcd.print("товара");
       
        text = "";
      }
      if (text == "80" && p80 > 0) {
        lcd.clear();
        lcd.setCursor(5, 0);
        lcd.print("товар 80");
        lcd.setCursor(6, 1);
        lcd.print(p80);
        lcd.setCursor(10, 1);
        lcd.print("руб.");
        lcd.setCursor(0, 3);
        lcd.print("Е выбрать   С отмена");
        choiseflag80 = true;
        choiseflag = true;
        text = "";
        choise.setTimeout(choisetime);
      }
      if (text == "80" && p80 == 0) {
        lcd.clear();
        lcd.setCursor(2, 1);
        lcd.print("Выбор недоступен");
        delay(1000);
        lcd.clear();                           ////////////////////////   начальный экран
        lcd.setCursor(5, 0);
        lcd.print("Введите код");
        lcd.setCursor(7, 1);
        lcd.print("товара");
      
        text = "";
      }
      if (text == "81" && p81 > 0) {
        lcd.clear();
        lcd.setCursor(5, 0);
        lcd.print("товар 81");
        lcd.setCursor(6, 1);
        lcd.print(p81);
        lcd.setCursor(10, 1);
        lcd.print("руб.");
        lcd.setCursor(0, 3);
        lcd.print("Е выбрать   С отмена");
        choiseflag81 = true;
        choiseflag = true;
        text = "";
        choise.setTimeout(choisetime);
      }
      if (text == "81" && p81 == 0) {
        lcd.clear();
        lcd.setCursor(2, 1);
        lcd.print("Выбор недоступен");
        delay(1000);
        lcd.clear();                           ////////////////////////   начальный экран
        lcd.setCursor(5, 0);
        lcd.print("Введите код");
        lcd.setCursor(7, 1);
        lcd.print("товара");
        
        text = "";
      }
      if (text == "82" && p82 > 0) {
        lcd.clear();
        lcd.setCursor(5, 0);
        lcd.print("товар 82");
        lcd.setCursor(6, 1);
        lcd.print(p82);
        lcd.setCursor(10, 1);
        lcd.print("руб.");
        lcd.setCursor(0, 3);
        lcd.print("Е выбрать   С отмена");
        choiseflag82 = true;
        choiseflag = true;
        text = "";
        choise.setTimeout(choisetime);
      }
      if (text == "82" && p82 == 0) {
        lcd.clear();
        lcd.setCursor(2, 1);
        lcd.print("Выбор недоступен");
        delay(1000);
        lcd.clear();                           ////////////////////////   начальный экран
        lcd.setCursor(5, 0);
        lcd.print("Введите код");
        lcd.setCursor(7, 1);
        lcd.print("товара");
      
        text = "";
      }
      if (text == "83" && p83 > 0) {
        lcd.clear();
        lcd.setCursor(5, 0);
        lcd.print("товар 83");
        lcd.setCursor(6, 1);
        lcd.print(p83);
        lcd.setCursor(10, 1);
        lcd.print("руб.");
        lcd.setCursor(0, 3);
        lcd.print("Е выбрать   С отмена");
        choiseflag83 = true;
        choiseflag = true;
        text = "";
        choise.setTimeout(choisetime);
      }
      if (text == "83" && p83 == 0) {
        lcd.clear();
        lcd.setCursor(2, 1);
        lcd.print("Выбор недоступен");
        delay(1000);
        lcd.clear();                           ////////////////////////   начальный экран
        lcd.setCursor(5, 0);
        lcd.print("Введите код");
        lcd.setCursor(7, 1);
        lcd.print("товара");
      
        text = "";
      }
      if (text == "84" && p84 > 0) {
        lcd.clear();
        lcd.setCursor(5, 0);
        lcd.print("товар 80");
        lcd.setCursor(6, 1);
        lcd.print(p84);
        lcd.setCursor(10, 1);
        lcd.print("руб.");
        lcd.setCursor(0, 3);
        lcd.print("Е выбрать   С отмена");
        choiseflag84 = true;
        choiseflag = true;
        text = "";
        choise.setTimeout(choisetime);
      }
      if (text == "84" && p84 == 0) {
        lcd.clear();
        lcd.setCursor(2, 1);
        lcd.print("Выбор недоступен");
        delay(1000);
        lcd.clear();                           ////////////////////////   начальный экран
        lcd.setCursor(5, 0);
        lcd.print("Введите код");
        lcd.setCursor(7, 1);
        lcd.print("товара");
      
        text = "";
      }
      if (text == "85" && p85 > 0) {
        lcd.clear();
        lcd.setCursor(5, 0);
        lcd.print("товар 85");
        lcd.setCursor(6, 1);
        lcd.print(p85);
        lcd.setCursor(10, 1);
        lcd.print("руб.");
        lcd.setCursor(0, 3);
        lcd.print("Е выбрать   С отмена");
        choiseflag85 = true;
        choiseflag = true;
        text = "";
        choise.setTimeout(choisetime);
      }
      if (text == "85" && p85 == 0) {
        lcd.clear();
        lcd.setCursor(2, 1);
        lcd.print("Выбор недоступен");
        delay(1000);
        lcd.clear();                           ////////////////////////   начальный экран
        lcd.setCursor(5, 0);
        lcd.print("Введите код");
        lcd.setCursor(7, 1);
        lcd.print("товара");
       
        text = "";
      }
      if (text == "86" && p86 > 0) {
        lcd.clear();
        lcd.setCursor(5, 0);
        lcd.print("товар 86");
        lcd.setCursor(6, 1);
        lcd.print(p86);
        lcd.setCursor(10, 1);
        lcd.print("руб.");
        lcd.setCursor(0, 3);
        lcd.print("Е выбрать   С отмена");
        choiseflag86 = true;
        choiseflag = true;
        text = "";
        choise.setTimeout(choisetime);
      }
      if (text == "86" && p86 == 0) {
        lcd.clear();
        lcd.setCursor(2, 1);
        lcd.print("Выбор недоступен");
        delay(1000);
        lcd.clear();                           ////////////////////////   начальный экран
        lcd.setCursor(5, 0);
        lcd.print("Введите код");
        lcd.setCursor(7, 1);
        lcd.print("товара");
      
        text = "";
      }
      if (text == "87" && p87 > 0) {
        lcd.clear();
        lcd.setCursor(5, 0);
        lcd.print("товар 87");
        lcd.setCursor(6, 1);
        lcd.print(p87);
        lcd.setCursor(10, 1);
        lcd.print("руб.");
        lcd.setCursor(0, 3);
        lcd.print("Е выбрать   С отмена");
        choiseflag87 = true;
        choiseflag = true;
        text = "";
        choise.setTimeout(choisetime);
      }
      if (text == "87" && p87 == 0) {
        lcd.clear();
        lcd.setCursor(2, 1);
        lcd.print("Выбор недоступен");
        delay(1000);
        lcd.clear();                           ////////////////////////   начальный экран
        lcd.setCursor(5, 0);
        lcd.print("Введите код");
        lcd.setCursor(7, 1);
        lcd.print("товара");
       
        text = "";
      }
      if (text == "88" && p88 > 0) {
        lcd.clear();
        lcd.setCursor(5, 0);
        lcd.print("товар 88");
        lcd.setCursor(6, 1);
        lcd.print(p88);
        lcd.setCursor(10, 1);
        lcd.print("руб.");
        lcd.setCursor(0, 3);
        lcd.print("Е выбрать   С отмена");
        choiseflag88 = true;
        choiseflag = true;
        text = "";
        choise.setTimeout(choisetime);
      }
      if (text == "88" && p88 == 0) {
        lcd.clear();
        lcd.setCursor(2, 1);
        lcd.print("Выбор недоступен");
        delay(1000);
        lcd.clear();                           ////////////////////////   начальный экран
        lcd.setCursor(5, 0);
        lcd.print("Введите код");
        lcd.setCursor(7, 1);
        lcd.print("товара");
       
        text = "";
      }
      if (text == "89" && p89 > 0) {
        lcd.clear();
        lcd.setCursor(5, 0);
        lcd.print("товар 89");
        lcd.setCursor(6, 1);
        lcd.print(p89);
        lcd.setCursor(10, 1);
        lcd.print("руб.");
        lcd.setCursor(0, 3);
        lcd.print("Е выбрать   С отмена");
        choiseflag89 = true;
        choiseflag = true;
        text = "";
        choise.setTimeout(choisetime);
      }
      if (text == "89" && p89 == 0) {
        lcd.clear();
        lcd.setCursor(2, 1);
        lcd.print("Выбор недоступен");
        delay(1000);
        lcd.clear();                           ////////////////////////   начальный экран
        lcd.setCursor(5, 0);
        lcd.print("Введите код");
        lcd.setCursor(7, 1);
        lcd.print("товара");
      
        text = "";
      }
      if (text == "90" && p90 > 0) {
        lcd.clear();
        lcd.setCursor(5, 0);
        lcd.print("товар 90");
        lcd.setCursor(6, 1);
        lcd.print(p90);
        lcd.setCursor(10, 1);
        lcd.print("руб.");
        lcd.setCursor(0, 3);
        lcd.print("Е выбрать   С отмена");
        choiseflag90 = true;
        choiseflag = true;
        text = "";
        choise.setTimeout(choisetime);
      }
      if (text == "90" && p90 == 0) {
        lcd.clear();
        lcd.setCursor(2, 1);
        lcd.print("Выбор недоступен");
        delay(1000);
        lcd.clear();                           ////////////////////////   начальный экран
        lcd.setCursor(5, 0);
        lcd.print("Введите код");
        lcd.setCursor(7, 1);
        lcd.print("товара");
       
        text = "";
      }
      if (text == "91" && p91 > 0) {
        lcd.clear();
        lcd.setCursor(5, 0);
        lcd.print("товар 91");
        lcd.setCursor(6, 1);
        lcd.print(p91);
        lcd.setCursor(10, 1);
        lcd.print("руб.");
        lcd.setCursor(0, 3);
        lcd.print("Е выбрать   С отмена");
        choiseflag91 = true;
        choiseflag = true;
        text = "";
        choise.setTimeout(choisetime);
      }
      if (text == "91" && p91 == 0) {
        lcd.clear();
        lcd.setCursor(2, 1);
        lcd.print("Выбор недоступен");
        delay(1000);
        lcd.clear();                           ////////////////////////   начальный экран
        lcd.setCursor(5, 0);
        lcd.print("Введите код");
        lcd.setCursor(7, 1);
        lcd.print("товара");
        
        text = "";
      }
      if (text == "92" && p92 > 0) {
        lcd.clear();
        lcd.setCursor(5, 0);
        lcd.print("товар 92");
        lcd.setCursor(6, 1);
        lcd.print(p92);
        lcd.setCursor(10, 1);
        lcd.print("руб.");
        lcd.setCursor(0, 3);
        lcd.print("Е выбрать   С отмена");
        choiseflag92 = true;
        choiseflag = true;
        text = "";
        choise.setTimeout(choisetime);
      }
      if (text == "92" && p92 == 0) {
        lcd.clear();
        lcd.setCursor(2, 1);
        lcd.print("Выбор недоступен");
        delay(1000);
        lcd.clear();                           ////////////////////////   начальный экран
        lcd.setCursor(5, 0);
        lcd.print("Введите код");
        lcd.setCursor(7, 1);
        lcd.print("товара");
       
        text = "";
      }
      if (text == "93" && p93 > 0) {
        lcd.clear();
        lcd.setCursor(5, 0);
        lcd.print("товар 93");
        lcd.setCursor(6, 1);
        lcd.print(p93);
        lcd.setCursor(10, 1);
        lcd.print("руб.");
        lcd.setCursor(0, 3);
        lcd.print("Е выбрать   С отмена");
        choiseflag93 = true;
        choiseflag = true;
        text = "";
        choise.setTimeout(choisetime);
      }
      if (text == "93" && p93 == 0) {
        lcd.clear();
        lcd.setCursor(2, 1);
        lcd.print("Выбор недоступен");
        delay(1000);
        lcd.clear();                           ////////////////////////   начальный экран
        lcd.setCursor(5, 0);
        lcd.print("Введите код");
        lcd.setCursor(7, 1);
        lcd.print("товара");
      
        text = "";
      }
      if (text == "94" && p94 > 0) {
        lcd.clear();
        lcd.setCursor(5, 0);
        lcd.print("товар 94");
        lcd.setCursor(6, 1);
        lcd.print(p94);
        lcd.setCursor(10, 1);
        lcd.print("руб.");
        lcd.setCursor(0, 3);
        lcd.print("Е выбрать   С отмена");
        choiseflag94 = true;
        choiseflag = true;
        text = "";
        choise.setTimeout(choisetime);
      }
      if (text == "94" && p94 == 0) {
        lcd.clear();
        lcd.setCursor(2, 1);
        lcd.print("Выбор недоступен");
        delay(1000);
        lcd.clear();                           ////////////////////////   начальный экран
        lcd.setCursor(5, 0);
        lcd.print("Введите код");
        lcd.setCursor(7, 1);
        lcd.print("товара");
       
        text = "";
      }
      if (text == "95" && p95 > 0) {
        lcd.clear();
        lcd.setCursor(5, 0);
        lcd.print("товар 95");
        lcd.setCursor(6, 1);
        lcd.print(p95);
        lcd.setCursor(10, 1);
        lcd.print("руб.");
        lcd.setCursor(0, 3);
        lcd.print("Е выбрать   С отмена");
        choiseflag95 = true;
        choiseflag = true;
        text = "";
        choise.setTimeout(choisetime);
      }
      if (text == "95" && p95 == 0) {
        lcd.clear();
        lcd.setCursor(2, 1);
        lcd.print("Выбор недоступен");
        delay(1000);
        lcd.clear();                           ////////////////////////   начальный экран
        lcd.setCursor(5, 0);
        lcd.print("Введите код");
        lcd.setCursor(7, 1);
        lcd.print("товара");
     
        text = "";
      }
      if (text == "96" && p96 > 0) {
        lcd.clear();
        lcd.setCursor(5, 0);
        lcd.print("товар 96");
        lcd.setCursor(6, 1);
        lcd.print(p96);
        lcd.setCursor(10, 1);
        lcd.print("руб.");
        lcd.setCursor(0, 3);
        lcd.print("Е выбрать   С отмена");
        choiseflag96 = true;
        choiseflag = true;
        text = "";
        choise.setTimeout(choisetime);
      }
      if (text == "96" && p96 == 0) {
        lcd.clear();
        lcd.setCursor(2, 1);
        lcd.print("Выбор недоступен");
        delay(1000);
        lcd.clear();                           ////////////////////////   начальный экран
        lcd.setCursor(5, 0);
        lcd.print("Введите код");
        lcd.setCursor(7, 1);
        lcd.print("товара");
       
        text = "";
      }
      if (text == "97" && p97 > 0) {
        lcd.clear();
        lcd.setCursor(5, 0);
        lcd.print("товар 97");
        lcd.setCursor(6, 1);
        lcd.print(p97);
        lcd.setCursor(10, 1);
        lcd.print("руб.");
        lcd.setCursor(0, 3);
        lcd.print("Е выбрать   С отмена");
        choiseflag97 = true;
        choiseflag = true;
        text = "";
        choise.setTimeout(choisetime);
      }
      if (text == "97" && p97 == 0) {
        lcd.clear();
        lcd.setCursor(2, 1);
        lcd.print("Выбор недоступен");
        delay(1000);
        lcd.clear();                           ////////////////////////   начальный экран
        lcd.setCursor(5, 0);
        lcd.print("Введите код");
        lcd.setCursor(7, 1);
        lcd.print("товара");
       
        text = "";
      }
      if (text == "98" && p98 > 0) {
        lcd.clear();
        lcd.setCursor(5, 0);
        lcd.print("товар 98");
        lcd.setCursor(6, 1);
        lcd.print(p98);
        lcd.setCursor(10, 1);
        lcd.print("руб.");
        lcd.setCursor(0, 3);
        lcd.print("Е выбрать   С отмена");
        choiseflag98 = true;
        choiseflag = true;
        text = "";
        choise.setTimeout(choisetime);
      }
      if (text == "98" && p98 == 0) {
        lcd.clear();
        lcd.setCursor(2, 1);
        lcd.print("Выбор недоступен");
        delay(1000);
        lcd.clear();                           ////////////////////////   начальный экран
        lcd.setCursor(5, 0);
        lcd.print("Введите код");
        lcd.setCursor(7, 1);
        lcd.print("товара");
      
        text = "";
      }
      if (text == "99" && p99 > 0) {
        lcd.clear();
        lcd.setCursor(5, 0);
        lcd.print("товар 99");
        lcd.setCursor(6, 1);
        lcd.print(p99);
        lcd.setCursor(10, 1);
        lcd.print("руб.");
        lcd.setCursor(0, 3);
        lcd.print("Е выбрать   С отмена");
        choiseflag99 = true;
        choiseflag = true;
        text = "";
        choise.setTimeout(choisetime);
      }
      if (text == "99" && p99 == 0) {
        lcd.clear();
        lcd.setCursor(2, 1);
        lcd.print("Выбор недоступен");
        delay(1000);
        lcd.clear();                           ////////////////////////   начальный экран
        lcd.setCursor(5, 0);
        lcd.print("Введите код");
        lcd.setCursor(7, 1);
        lcd.print("товара");
      
        text = "";
      }

    }
    else {
      newchar = String(customKey);
      if (newchar == "C") {
        total = 0;
        first = false;
        second = false;
        lcd.clear();                           ////////////////////////   начальный экран
        lcd.setCursor(5, 0);
        lcd.print("Введите код");
        lcd.setCursor(7, 1);
        lcd.print("товара");
       // lcd.setCursor(0, 3);
       // lcd.print("к оплате");
      // lcd.setCursor(10, 3);
       // lcd.print(total);
       // lcd.setCursor(14, 3);
       // lcd.print("руб");                      //////////////////////     начальный экран
        choiseflag = false;
      }
    }
  }
  /////////////////////////////добавление в корхзину

  if (paystat == 2) {
    customKey = customKeypad.getKey();
    newchar = String(customKey);
    if (newchar == "C") {
      Serial1.write(cancel, sizeof(cancel));
      delay(1000);
      paystat = 0;
      Serial1.write(data5, sizeof(data5));
      Pay.stop();
      price1 = 0;
      total = 0;
      first = false;
      second = false;
      lcd.clear();                           ////////////////////////   начальный экран
      lcd.setCursor(5, 0);
      lcd.print("Введите код");
      lcd.setCursor(7, 1);
      lcd.print("товара");
      lcd.setCursor(0, 3);
      //lcd.print("к оплате");
    //  lcd.setCursor(10, 3);
     // lcd.print(total);
    //  lcd.setCursor(14, 3);
      //lcd.print("руб");                      //////////////////////     начальный экран
      newchar = "";
    }
  }
  if (def.isReady()) {
    total = 0;
    first = false;
    second = false;
    lcd.clear();                           ////////////////////////   начальный экран
    lcd.setCursor(5, 0);
    lcd.print("Введите код");
    lcd.setCursor(7, 1);
    lcd.print("товара");
    lcd.setCursor(0, 3);
  //  lcd.print("к оплате");
   // lcd.setCursor(10, 3);
   // lcd.print(total);
   // lcd.setCursor(14, 3);
   // lcd.print("руб");                      //////////////////////     начальный экран
  }
  if (prog == false && choiseflag == true  && paystat == 0) {
    customKey = customKeypad.getKey();
    newchar = String(customKey);
    if (newchar == "E") {
      if (choiseflag10 == true) {
     //   total = total + p10;
     total = p10;
        choiseflag10 = false;
        first = true;
        data1[34] = 0x30;
        data1[35] = 0x31;
        data1[36] = 0x30;

      }
      if (choiseflag11 == true) {
        total = p11;
        choiseflag11 = false;
        first = true;
        data1[34] = 0x30;
        data1[35] = 0x31;
        data1[36] = 0x31;
      }
      if (choiseflag12 == true) {
        total =  p12;
        choiseflag12 = false;
        first = true;
        data1[34] = 0x30;
        data1[35] = 0x31;
        data1[36] = 0x32;
      }
      if (choiseflag13 == true) {
        total = p13;
        choiseflag13 = false;
        first = true;
        data1[34] = 0x30;
        data1[35] = 0x31;
        data1[36] = 0x33;
      }
      if (choiseflag14 == true) {
        total = p14;
        choiseflag14 = false;
        first = true;
        data1[34] = 0x30;
        data1[35] = 0x31;
        data1[36] = 0x34;
      }
      if (choiseflag15 == true) {
        total =  p15;
        choiseflag15 = false;
        first = true;
        data1[34] = 0x30;
        data1[35] = 0x31;
        data1[36] = 0x35;
      }
      if (choiseflag16 == true) {
        total =  p16;
        choiseflag16 = false;
        first = true;
        data1[34] = 0x30;
        data1[35] = 0x31;
        data1[36] = 0x36;
      }
      if (choiseflag17 == true) {
        total =  p17;
        choiseflag17 = false;
        first = true;
        data1[34] = 0x30;
        data1[35] = 0x31;
        data1[36] = 0x37;
      }
      if (choiseflag18 == true) {
        total =  p18;
        choiseflag18 = false;
        first = true;
        data1[34] = 0x30;
        data1[35] = 0x31;
        data1[36] = 0x38;
      }
      if (choiseflag19 == true) {
        total =  p19;
        choiseflag19 = false;
        first = true;
        data1[34] = 0x30;
        data1[35] = 0x31;
        data1[36] = 0x39;
      }
      if (choiseflag20 == true) {
        total = p20;
        choiseflag20 = false;
        first = true;
        data1[34] = 0x30;
        data1[35] = 0x32;
        data1[36] = 0x30;
      }
      if (choiseflag21 == true) {
        total = p21;
        choiseflag21 = false;
        first = true;
        data1[34] = 0x30;
        data1[35] = 0x32;
        data1[36] = 0x31;
      }
      if (choiseflag22 == true) {
        total = p22;
        choiseflag22 = false;
        first = true;
        data1[34] = 0x30;
        data1[35] = 0x32;
        data1[36] = 0x32;
      }
      if (choiseflag23 == true) {
        total = p23;
        choiseflag23 = false;
        first = true;
        data1[34] = 0x30;
        data1[35] = 0x32;
        data1[36] = 0x33;
      }
      if (choiseflag24 == true) {
        total = p24;
        choiseflag24 = false;
        first = true;
        data1[34] = 0x30;
        data1[35] = 0x32;
        data1[36] = 0x34;
      }
      if (choiseflag25 == true) {
        total = p25;
        choiseflag25 = false;
        first = true;
        data1[34] = 0x30;
        data1[35] = 0x32;
        data1[36] = 0x35;
      }
      if (choiseflag26 == true) {
        total = p26;
        choiseflag26 = false;
        first = true;
        data1[34] = 0x30;
        data1[35] = 0x32;
        data1[36] = 0x36;
      }
      if (choiseflag27 == true) {
        total = p27;
        choiseflag27 = false;
        first = true;
        data1[34] = 0x30;
        data1[35] = 0x32;
        data1[36] = 0x37;
      }
      if (choiseflag28 == true) {
        total = p28;
        choiseflag28 = false;
        first = true;
        data1[34] = 0x30;
        data1[35] = 0x32;
        data1[36] = 0x38;
      }
      if (choiseflag29 == true) {
        total = p29;
        choiseflag29 = false;
        first = true;
        data1[34] = 0x30;
        data1[35] = 0x32;
        data1[36] = 0x39;
      }
      if (choiseflag30 == true) {
        total = p30;
        choiseflag30 = false;
        first = true;
        data1[34] = 0x30;
        data1[35] = 0x33;
        data1[36] = 0x30;
      }
      if (choiseflag31 == true) {
        total = p31;
        choiseflag31 = false;
        first = true;
        data1[34] = 0x30;
        data1[35] = 0x33;
        data1[36] = 0x31;
      }
      if (choiseflag32 == true) {
        total = p32;
        choiseflag32 = false;
        first = true;
        data1[34] = 0x30;
        data1[35] = 0x33;
        data1[36] = 0x32;
      }
      if (choiseflag33 == true) {
        total = p33;
        choiseflag33 = false;
        first = true;
        data1[34] = 0x30;
        data1[35] = 0x33;
        data1[36] = 0x33;
      }
      if (choiseflag34 == true) {
        total = p34;
        choiseflag34 = false;
        first = true;
        data1[34] = 0x30;
        data1[35] = 0x33;
        data1[36] = 0x34;
      }
      if (choiseflag35 == true) {
        total = p35;
        choiseflag35 = false;
        first = true;
        data1[34] = 0x30;
        data1[35] = 0x33;
        data1[36] = 0x35;
      }
      if (choiseflag36 == true) {
        total = p36;
        choiseflag36 = false;
        first = true;
        data1[34] = 0x30;
        data1[35] = 0x33;
        data1[36] = 0x36;
      }
      if (choiseflag37 == true) {
        total = p37;
        choiseflag37 = false;
        first = true;
        data1[34] = 0x30;
        data1[35] = 0x33;
        data1[36] = 0x37;
      }
      if (choiseflag38 == true) {
        total = p38;
        choiseflag38 = false;
        first = true;
        data1[34] = 0x30;
        data1[35] = 0x33;
        data1[36] = 0x38;
      }
      if (choiseflag39 == true) {
        total = p39;
        choiseflag39 = false;
        first = true;
        data1[34] = 0x30;
        data1[35] = 0x33;
        data1[36] = 0x39;
      }
      if (choiseflag40 == true) {
        total = p40;
        choiseflag40 = false;
        first = true;
        data1[34] = 0x30;
        data1[35] = 0x34;
        data1[36] = 0x30;
      }
      if (choiseflag41 == true) {
        total = p41;
        choiseflag41 = false;
        first = true;
        data1[34] = 0x30;
        data1[35] = 0x34;
        data1[36] = 0x31;
      }
      if (choiseflag42 == true) {
        total = p42;
        choiseflag42 = false;
        first = true;
        data1[34] = 0x30;
        data1[35] = 0x34;
        data1[36] = 0x32;
      }
      if (choiseflag43 == true) {
        total = p43;
        choiseflag43 = false;
        first = true;
        data1[34] = 0x30;
        data1[35] = 0x34;
        data1[36] = 0x33;
      }
      if (choiseflag44 == true) {
        total = p44;
        choiseflag44 = false;
        first = true;
        data1[34] = 0x30;
        data1[35] = 0x34;
        data1[36] = 0x34;
      }
      if (choiseflag45 == true) {
        total = p45;
        choiseflag45 = false;
        first = true;
        data1[34] = 0x30;
        data1[35] = 0x34;
        data1[36] = 0x35;
      }
      if (choiseflag46 == true) {
        total = p46;
        choiseflag40 = false;
        first = true;
        data1[34] = 0x30;
        data1[35] = 0x34;
        data1[36] = 0x36;
      }
      if (choiseflag47 == true) {
        total = p47;
        choiseflag47 = false;
        first = true;
        data1[34] = 0x30;
        data1[35] = 0x34;
        data1[36] = 0x37;
      }
      if (choiseflag48 == true) {
        total = p48;
        choiseflag48 = false;
        first = true;
        data1[34] = 0x30;
        data1[35] = 0x34;
        data1[36] = 0x38;
      }
      if (choiseflag49 == true) {
        total = p49;
        choiseflag49 = false;
        first = true;
        data1[34] = 0x30;
        data1[35] = 0x34;
        data1[36] = 0x39;
      }
      if (choiseflag50 == true) {
        total = p50;
        choiseflag50 = false;
        second = true;
        data1[34] = 0x30;
        data1[35] = 0x35;
        data1[36] = 0x30;
      }
      if (choiseflag51 == true) {
        total = p51;
        choiseflag51 = false;
        second = true;
        data1[34] = 0x30;
        data1[35] = 0x35;
        data1[36] = 0x31;
      }
      if (choiseflag52 == true) {
        total = p52;
        choiseflag52 = false;
        second = true;
        data1[34] = 0x30;
        data1[35] = 0x35;
        data1[36] = 0x32;
      }
      if (choiseflag53 == true) {
        total = p53;
        choiseflag53 = false;
        second = true;
        data1[34] = 0x30;
        data1[35] = 0x35;
        data1[36] = 0x33;
      }
      if (choiseflag54 == true) {
        total = p54;
        choiseflag54 = false;
        second = true;
        data1[34] = 0x30;
        data1[35] = 0x35;
        data1[36] = 0x34;
      }
      if (choiseflag55 == true) {
        total = p55;
        choiseflag55 = false;
        second = true;
        data1[34] = 0x30;
        data1[35] = 0x35;
        data1[36] = 0x35;
      }
      if (choiseflag56 == true) {
        total = p56;
        choiseflag56 = false;
        second = true;
        data1[34] = 0x30;
        data1[35] = 0x35;
        data1[36] = 0x36;
      }
      if (choiseflag57 == true) {
        total = p57;
        choiseflag57 = false;
        second = true;
        data1[34] = 0x30;
        data1[35] = 0x35;
        data1[36] = 0x37;
      }
      if (choiseflag58 == true) {
        total = p58;
        choiseflag58 = false;
        second = true;
        data1[34] = 0x30;
        data1[35] = 0x35;
        data1[36] = 0x38;
      }
      if (choiseflag59 == true) {
        total = p59;
        choiseflag59 = false;
        second = true;
        data1[34] = 0x30;
        data1[35] = 0x35;
        data1[36] = 0x39;
      }
      if (choiseflag60 == true) {
        total = p60;
        choiseflag60 = false;
        second = true;
        data1[34] = 0x30;
        data1[35] = 0x36;
        data1[36] = 0x30;
      }
      if (choiseflag61 == true) {
        total = p61;
        choiseflag61 = false;
        second = true;
        data1[34] = 0x30;
        data1[35] = 0x36;
        data1[36] = 0x31;
      }
      if (choiseflag62 == true) {
        total = p62;
        choiseflag62 = false;
        second = true;
        data1[34] = 0x30;
        data1[35] = 0x36;
        data1[36] = 0x32;
      }
      if (choiseflag63 == true) {
        total = total + p63;
        choiseflag63 = false;
        second = true;
        data1[34] = 0x30;
        data1[35] = 0x36;
        data1[36] = 0x33;
      }
      if (choiseflag64 == true) {
        total = total + p64;
        choiseflag64 = false;
        second = true;
        data1[34] = 0x30;
        data1[35] = 0x36;
        data1[36] = 0x34;
      }
      if (choiseflag65 == true) {
        total = total + p65;
        choiseflag65 = false;
        second = true;
        data1[34] = 0x30;
        data1[35] = 0x36;
        data1[36] = 0x35;
      }
      if (choiseflag66 == true) {
        total = total + p66;
        choiseflag66 = false;
        second = true;
        data1[34] = 0x30;
        data1[35] = 0x36;
        data1[36] = 0x36;
      }
      if (choiseflag67 == true) {
        total = total + p67;
        choiseflag67 = false;
        second = true;
        data1[34] = 0x30;
        data1[35] = 0x36;
        data1[36] = 0x37;
      }
      if (choiseflag68 == true) {
        total = total + p68;
        choiseflag68 = false;
        second = true;
        data1[34] = 0x30;
        data1[35] = 0x36;
        data1[36] = 0x38;
      }
      if (choiseflag69 == true) {
        total = total + p69;
        choiseflag69 = false;
        second = true;
        data1[34] = 0x30;
        data1[35] = 0x36;
        data1[36] = 0x39;
      }
      if (choiseflag70 == true) {
        total = total + p70;
        choiseflag70 = false;
        second = true;
        data1[34] = 0x30;
        data1[35] = 0x37;
        data1[36] = 0x30;
      }
      if (choiseflag71 == true) {
        total = total + p71;
        choiseflag71 = false;
        second = true;
        data1[34] = 0x30;
        data1[35] = 0x37;
        data1[36] = 0x31;
      }
      if (choiseflag72 == true) {
        total = total + p72;
        choiseflag72 = false;
        second = true;
        data1[34] = 0x30;
        data1[35] = 0x37;
        data1[36] = 0x32;
      }
      if (choiseflag73 == true) {
        total = total + p73;
        choiseflag73 = false;
        second = true;
        data1[34] = 0x30;
        data1[35] = 0x37;
        data1[36] = 0x33;
      }
      if (choiseflag74 == true) {
        total = total + p74;
        choiseflag74 = false;
        second = true;
        data1[34] = 0x30;
        data1[35] = 0x37;
        data1[36] = 0x34;
      }
      if (choiseflag75 == true) {
        total = total + p75;
        choiseflag75 = false;
        second = true;
        data1[34] = 0x30;
        data1[35] = 0x37;
        data1[36] = 0x35;
      }
      if (choiseflag76 == true) {
        total = total + p76;
        choiseflag76 = false;
        second = true;
        data1[34] = 0x30;
        data1[35] = 0x37;
        data1[36] = 0x36;
      }
      if (choiseflag77 == true) {
        total = total + p77;
        choiseflag77 = false;
        second = true;
        data1[34] = 0x30;
        data1[35] = 0x37;
        data1[36] = 0x37;
      }
      if (choiseflag78 == true) {
        total = total + p78;
        choiseflag78 = false;
        second = true;
        data1[34] = 0x30;
        data1[35] = 0x37;
        data1[36] = 0x38;
      }
      if (choiseflag79 == true) {
        total = total + p79;
        choiseflag79 = false;
        second = true;
        data1[34] = 0x30;
        data1[35] = 0x37;
        data1[36] = 0x39;
      }
      if (choiseflag80 == true) {
        total = p80;
        choiseflag80 = false;
        second = true;
        data1[34] = 0x30;
        data1[35] = 0x38;
        data1[36] = 0x30;
      }
      if (choiseflag81 == true) {
        total = p81;
        choiseflag81 = false;
        second = true;
        data1[34] = 0x30;
        data1[35] = 0x38;
        data1[36] = 0x31;
      }
      if (choiseflag82 == true) {
        total = p82;
        choiseflag82 = false;
        second = true;
        data1[34] = 0x30;
        data1[35] = 0x38;
        data1[36] = 0x32;
      }
      if (choiseflag83 == true) {
        total = p83;
        choiseflag83 = false;
        second = true;
        data1[34] = 0x30;
        data1[35] = 0x38;
        data1[36] = 0x33;
      }
      if (choiseflag84 == true) {
        total = p84;
        choiseflag84 = false;
        second = true;
        data1[34] = 0x30;
        data1[35] = 0x38;
        data1[36] = 0x34;
      }
      if (choiseflag85 == true) {
        total = p85;
        choiseflag85 = false;
        second = true;
        data1[34] = 0x30;
        data1[35] = 0x38;
        data1[36] = 0x35;
      }
      if (choiseflag86 == true) {
        total = p86;
        choiseflag86 = false;
        second = true;
        data1[34] = 0x30;
        data1[35] = 0x38;
        data1[36] = 0x36;
      }
      if (choiseflag87 == true) {
        total = p87;
        choiseflag87 = false;
        second = true;
        data1[34] = 0x30;
        data1[35] = 0x38;
        data1[36] = 0x37;
      }
      if (choiseflag88 == true) {
        total = p88;
        choiseflag88 = false;
        second = true;
        data1[34] = 0x30;
        data1[35] = 0x38;
        data1[36] = 0x38;
      }
      if (choiseflag89 == true) {
        total = p89;
        choiseflag89 = false;
        second = true;
        data1[34] = 0x30;
        data1[35] = 0x38;
        data1[36] = 0x39;
      }
      if (choiseflag90 == true) {
        total = p90;
        choiseflag90 = false;
        second = true;
        data1[34] = 0x30;
        data1[35] = 0x39;
        data1[36] = 0x30;
      }
      if (choiseflag91 == true) {
        total = p91;
        choiseflag91 = false;
        second = true;
        data1[34] = 0x30;
        data1[35] = 0x39;
        data1[36] = 0x31;
      }
      if (choiseflag92 == true) {
        total = p92;
        choiseflag92 = false;
        second = true;
        data1[34] = 0x30;
        data1[35] = 0x39;
        data1[36] = 0x32;
      }
      if (choiseflag93 == true) {
        total = p93;
        choiseflag93 = false;
        second = true;
        data1[34] = 0x30;
        data1[35] = 0x39;
        data1[36] = 0x33;
      }
      if (choiseflag94 == true) {
        total = p94;
        choiseflag94 = false;
        second = true;
        data1[34] = 0x30;
        data1[35] = 0x39;
        data1[36] = 0x34;
      }
      if (choiseflag95 == true) {
        total = p95;
        choiseflag95 = false;
        second = true;
        data1[34] = 0x30;
        data1[35] = 0x39;
        data1[36] = 0x35;
      }
      if (choiseflag96 == true) {
        total = p96;
        choiseflag96 = false;
        second = true;
        data1[34] = 0x30;
        data1[35] = 0x39;
        data1[36] = 0x36;
      }
      if (choiseflag97 == true) {
        total = p97;
        choiseflag97 = false;
        second = true;
        data1[34] = 0x30;
        data1[35] = 0x39;
        data1[36] = 0x37;
      }
      if (choiseflag98 == true) {
        total = p98;
        choiseflag98 = false;
        second = true;
        data1[34] = 0x30;
        data1[35] = 0x39;
        data1[36] = 0x38;
      }
      if (choiseflag99 == true) {
        total = p99;
        choiseflag99 = false;
        second = true;
        data1[34] = 0x30;
        data1[35] = 0x39;
        data1[36] = 0x39;
      }

      choise.stop();
      price1 = total;
    }
    if (newchar == "C") {
      lcd.clear();                           ////////////////////////   начальный экран
      lcd.setCursor(5, 0);
      lcd.print("Введите код");
      lcd.setCursor(7, 1);
      lcd.print("товара");
     // lcd.setCursor(0, 3);
    //  lcd.print("к оплате");
     // lcd.setCursor(10, 3);
   //  lcd.print(total);
     // lcd.setCursor(14, 3);
   //   lcd.print("руб");                      //////////////////////     начальный экран
      choiseflag = false;
      choise.stop();
      newchar = "";
    }
  }
  if (prog == true) {
    if (a == 10) {         //   // if (a == 10)
      lcd.setCursor(0, 0);
      lcd.print("цена 10");
      lcd.setCursor(0, 1);
      lcd.print(p10);
      lcd.setCursor(7, 1);
      lcd.print("руб.");
      lcd.setCursor(0, 3);
      lcd.print("Е далее    С удалить");
      customKey = customKeypad.getKey();
      if (isDigit(customKey)) {
        newchar = String(customKey);
        p1text = p1text + newchar;
        p10 = p1text.toInt();
      }
      else {
        if (customKey == 'E') {
          prefs.putUInt("p10", p10);
          p1text = "";
          lcd.clear();
          a ++;
        }
        if (customKey == 'C') {
          p10 = 0;
          p1text = "";
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("цена 10");
          lcd.setCursor(0, 1);
          lcd.print(p10);
          lcd.setCursor(7, 1);
          lcd.print("руб.");
          lcd.setCursor(0, 3);
          lcd.print("Е далее    С удалить");
        }
      }
    }   // if (a == 10)
    if (a == 11) {         //   // if (a == 11)
      lcd.setCursor(0, 0);
      lcd.print("цена 11");
      lcd.setCursor(0, 1);
      lcd.print(p11);
      lcd.setCursor(7, 1);
      lcd.print("руб.");
      lcd.setCursor(0, 3);
      lcd.print("Е далее    С удалить");
      customKey = customKeypad.getKey();
      if (isDigit(customKey)) {
        newchar = String(customKey);
        p1text = p1text + newchar;
        p11 = p1text.toInt();
      }
      else {
        if (customKey == 'E') {
          prefs.putUInt("p11", p11);
          p1text = "";
          lcd.clear();
          a ++;
        }
        if (customKey == 'C') {
          p11 = 0;
          p1text = "";
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("цена 11");
          lcd.setCursor(0, 1);
          lcd.print(p11);
          lcd.setCursor(7, 1);
          lcd.print("руб.");
          lcd.setCursor(0, 3);
          lcd.print("Е далее    С удалить");
        }
      }
    }   // if (a == 12)

    if (a == 12) {         //   // if (a == 12)
      lcd.setCursor(0, 0);
      lcd.print("цена 12");
      lcd.setCursor(0, 1);
      lcd.print(p12);
      lcd.setCursor(7, 1);
      lcd.print("руб.");
      lcd.setCursor(0, 3);
      lcd.print("Е далее    С удалить");
      customKey = customKeypad.getKey();
      if (isDigit(customKey)) {
        newchar = String(customKey);
        p1text = p1text + newchar;
        p12 = p1text.toInt();
      }
      else {
        if (customKey == 'E') {
          prefs.putUInt("p12", p12);
          p1text = "";
          lcd.clear();
          a ++;
        }
        if (customKey == 'C') {
          p12 = 0;
          p1text = "";
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("цена 12");
          lcd.setCursor(0, 1);
          lcd.print(p12);
          lcd.setCursor(7, 1);
          lcd.print("руб.");
          lcd.setCursor(0, 3);
          lcd.print("Е далее    С удалить");
        }
      }
    }
    if (a == 13) {         //   // if (a == 13)
      lcd.setCursor(0, 0);
      lcd.print("цена 13");
      lcd.setCursor(0, 1);
      lcd.print(p13);
      lcd.setCursor(7, 1);
      lcd.print("руб.");
      lcd.setCursor(0, 3);
      lcd.print("Е далее    С удалить");
      customKey = customKeypad.getKey();
      if (isDigit(customKey)) {
        newchar = String(customKey);
        p1text = p1text + newchar;
        p13 = p1text.toInt();
      }
      else {
        if (customKey == 'E') {
          prefs.putUInt("p13", p13);
          p1text = "";
          lcd.clear();
          a++;
        }
        if (customKey == 'C') {
          p13 = 0;
          p1text = "";
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("цена 13");
          lcd.setCursor(0, 1);
          lcd.print(p13);
          lcd.setCursor(7, 1);
          lcd.print("руб.");
          lcd.setCursor(0, 3);
          lcd.print("Е далее    С удалить");
        }
      }
    }
    if (a == 14) {         //   // if (a == 14)
      lcd.setCursor(0, 0);
      lcd.print("цена 14");
      lcd.setCursor(0, 1);
      lcd.print(p14);
      lcd.setCursor(7, 1);
      lcd.print("руб.");
      lcd.setCursor(0, 3);
      lcd.print("Е далее    С удалить");
      customKey = customKeypad.getKey();
      if (isDigit(customKey)) {
        newchar = String(customKey);
        p1text = p1text + newchar;
        p14 = p1text.toInt();
      }
      else {
        if (customKey == 'E') {
          prefs.putUInt("p14", p14);
          p1text = "";
          lcd.clear();
          a++;
        }
        if (customKey == 'C') {
          p14 = 0;
          p1text = "";
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("цена 14");
          lcd.setCursor(0, 1);
          lcd.print(p14);
          lcd.setCursor(7, 1);
          lcd.print("руб.");
          lcd.setCursor(0, 3);
          lcd.print("Е далее    С удалить");
        }
      }
    }   // if (a == 1)
    if (a == 15) {         //   // if (a == 15)
      lcd.setCursor(0, 0);
      lcd.print("цена 15");
      lcd.setCursor(0, 1);
      lcd.print(p15);
      lcd.setCursor(7, 1);
      lcd.print("руб.");
      lcd.setCursor(0, 3);
      lcd.print("Е далее    С удалить");
      customKey = customKeypad.getKey();
      if (isDigit(customKey)) {
        newchar = String(customKey);
        p1text = p1text + newchar;
        p15 = p1text.toInt();
      }
      else {
        if (customKey == 'E') {
          prefs.putUInt("p15", p15);
          p1text = "";
          lcd.clear();
          a ++;
        }
        if (customKey == 'C') {
          p15 = 0;
          p1text = "";
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("цена 15");
          lcd.setCursor(0, 1);
          lcd.print(p15);
          lcd.setCursor(7, 1);
          lcd.print("руб.");
          lcd.setCursor(0, 3);
          lcd.print("Е далее    С удалить");
        }
      }
    }   // if (a == 1)
    if (a == 16) {         //   // if (a == 16)
      lcd.setCursor(0, 0);
      lcd.print("цена 16");
      lcd.setCursor(0, 1);
      lcd.print(p16);
      lcd.setCursor(7, 1);
      lcd.print("руб.");
      lcd.setCursor(0, 3);
      lcd.print("Е далее    С удалить");
      customKey = customKeypad.getKey();
      if (isDigit(customKey)) {
        newchar = String(customKey);
        p1text = p1text + newchar;
        p16 = p1text.toInt();
      }
      else {
        if (customKey == 'E') {
          prefs.putUInt("p16", p16);
          p1text = "";
          lcd.clear();
          a ++;
        }
        if (customKey == 'C') {
          p16 = 0;
          p1text = "";
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("цена 16");
          lcd.setCursor(0, 1);
          lcd.print(p16);
          lcd.setCursor(7, 1);
          lcd.print("руб.");
          lcd.setCursor(0, 3);
          lcd.print("Е далее    С удалить");
        }
      }
    }   // if (a == 1)
    if (a == 17) {         //   // if (a == 17)
      lcd.setCursor(0, 0);
      lcd.print("цена 17");
      lcd.setCursor(0, 1);
      lcd.print(p17);
      lcd.setCursor(7, 1);
      lcd.print("руб.");
      lcd.setCursor(0, 3);
      lcd.print("Е далее    С удалить");
      customKey = customKeypad.getKey();
      if (isDigit(customKey)) {
        newchar = String(customKey);
        p1text = p1text + newchar;
        p17 = p1text.toInt();
      }
      else {
        if (customKey == 'E') {
          prefs.putUInt("p17", p17);
          p1text = "";
          lcd.clear();
          a ++;
        }
        if (customKey == 'C') {
          p17 = 0;
          p1text = "";
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("цена 17");
          lcd.setCursor(0, 1);
          lcd.print(p17);
          lcd.setCursor(7, 1);
          lcd.print("руб.");
          lcd.setCursor(0, 3);
          lcd.print("Е далее    С удалить");
        }
      }
    }   // if (a == 1)
    if (a == 18) {         //   // if (a == 18)
      lcd.setCursor(0, 0);
      lcd.print("цена 18");
      lcd.setCursor(0, 1);
      lcd.print(p18);
      lcd.setCursor(7, 1);
      lcd.print("руб.");
      lcd.setCursor(0, 3);
      lcd.print("Е далее    С удалить");
      customKey = customKeypad.getKey();
      if (isDigit(customKey)) {
        newchar = String(customKey);
        p1text = p1text + newchar;
        p18 = p1text.toInt();
      }
      else {
        if (customKey == 'E') {
          prefs.putUInt("p18", p18);
          p1text = "";
          lcd.clear();
          a ++;
        }
        if (customKey == 'C') {
          p18 = 0;
          p1text = "";
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("цена 18");
          lcd.setCursor(0, 1);
          lcd.print(p18);
          lcd.setCursor(7, 1);
          lcd.print("руб.");
          lcd.setCursor(0, 3);
          lcd.print("Е далее    С удалить");
        }
      }
    }   // if (a == 1)
    if (a == 19) {         //   // if (a == 19)
      lcd.setCursor(0, 0);
      lcd.print("цена 19");
      lcd.setCursor(0, 1);
      lcd.print(p19);
      lcd.setCursor(7, 1);
      lcd.print("руб.");
      lcd.setCursor(0, 3);
      lcd.print("Е далее    С удалить");
      customKey = customKeypad.getKey();
      if (isDigit(customKey)) {
        newchar = String(customKey);
        p1text = p1text + newchar;
        p19 = p1text.toInt();
      }
      else {
        if (customKey == 'E') {
          prefs.putUInt("p19", p19);
          p1text = "";
          lcd.clear();
          a ++;
        }
        if (customKey == 'C') {
          p19 = 0;
          p1text = "";
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("цена 19");
          lcd.setCursor(0, 1);
          lcd.print(p19);
          lcd.setCursor(7, 1);
          lcd.print("руб.");
          lcd.setCursor(0, 3);
          lcd.print("Е далее    С удалить");
        }
      }
    }
    if (a == 20) {         //   // if (a == 20)
      lcd.setCursor(0, 0);
      lcd.print("цена 20");
      lcd.setCursor(0, 1);
      lcd.print(p20);
      lcd.setCursor(7, 1);
      lcd.print("руб.");
      lcd.setCursor(0, 3);
      lcd.print("Е далее    С удалить");
      customKey = customKeypad.getKey();
      if (isDigit(customKey)) {
        newchar = String(customKey);
        p1text = p1text + newchar;
        p20 = p1text.toInt();
      }
      else {
        if (customKey == 'E') {
          prefs.putUInt("p20", p20);
          p1text = "";
          lcd.clear();
          a ++;
        }
        if (customKey == 'C') {
          p20 = 0;
          p1text = "";
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("цена 20");
          lcd.setCursor(0, 1);
          lcd.print(p20);
          lcd.setCursor(7, 1);
          lcd.print("руб.");
          lcd.setCursor(0, 3);
          lcd.print("Е далее    С удалить");
        }
      }
    }
    if (a == 21) {         //   // if (a == 21)
      lcd.setCursor(0, 0);
      lcd.print("цена 21");
      lcd.setCursor(0, 1);
      lcd.print(p21);
      lcd.setCursor(7, 1);
      lcd.print("руб.");
      lcd.setCursor(0, 3);
      lcd.print("Е далее    С удалить");
      customKey = customKeypad.getKey();
      if (isDigit(customKey)) {
        newchar = String(customKey);
        p1text = p1text + newchar;
        p21 = p1text.toInt();
      }
      else {
        if (customKey == 'E') {
          prefs.putUInt("p21", p21);
          p1text = "";
          lcd.clear();
          a ++;
        }
        if (customKey == 'C') {
          p21 = 0;
          p1text = "";
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("цена 21");
          lcd.setCursor(0, 1);
          lcd.print(p21);
          lcd.setCursor(7, 1);
          lcd.print("руб.");
          lcd.setCursor(0, 3);
          lcd.print("Е далее    С удалить");
        }
      }
    }
    if (a == 22) {         //   // if (a == 22)
      lcd.setCursor(0, 0);
      lcd.print("цена 22");
      lcd.setCursor(0, 1);
      lcd.print(p22);
      lcd.setCursor(7, 1);
      lcd.print("руб.");
      lcd.setCursor(0, 3);
      lcd.print("Е далее    С удалить");
      customKey = customKeypad.getKey();
      if (isDigit(customKey)) {
        newchar = String(customKey);
        p1text = p1text + newchar;
        p22 = p1text.toInt();
      }
      else {
        if (customKey == 'E') {
          prefs.putUInt("p22", p22);
          p1text = "";
          lcd.clear();
          a ++;
        }
        if (customKey == 'C') {
          p22 = 0;
          p1text = "";
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("цена 22");
          lcd.setCursor(0, 1);
          lcd.print(p22);
          lcd.setCursor(7, 1);
          lcd.print("руб.");
          lcd.setCursor(0, 3);
          lcd.print("Е далее    С удалить");
        }
      }
    }
    if (a == 23) {         //   // if (a == 23)
      lcd.setCursor(0, 0);
      lcd.print("цена 23");
      lcd.setCursor(0, 1);
      lcd.print(p23);
      lcd.setCursor(7, 1);
      lcd.print("руб.");
      lcd.setCursor(0, 3);
      lcd.print("Е далее    С удалить");
      customKey = customKeypad.getKey();
      if (isDigit(customKey)) {
        newchar = String(customKey);
        p1text = p1text + newchar;
        p23 = p1text.toInt();
      }
      else {
        if (customKey == 'E') {
          prefs.putUInt("p23", p23);
          p1text = "";
          lcd.clear();
          a ++;
        }
        if (customKey == 'C') {
          p23 = 0;
          p1text = "";
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("цена 23");
          lcd.setCursor(0, 1);
          lcd.print(p23);
          lcd.setCursor(7, 1);
          lcd.print("руб.");
          lcd.setCursor(0, 3);
          lcd.print("Е далее    С удалить");
        }
      }
    }
    if (a == 24) {         //   // if (a == 21)
      lcd.setCursor(0, 0);
      lcd.print("цена 24");
      lcd.setCursor(0, 1);
      lcd.print(p24);
      lcd.setCursor(7, 1);
      lcd.print("руб.");
      lcd.setCursor(0, 3);
      lcd.print("Е далее    С удалить");
      customKey = customKeypad.getKey();
      if (isDigit(customKey)) {
        newchar = String(customKey);
        p1text = p1text + newchar;
        p24 = p1text.toInt();
      }
      else {
        if (customKey == 'E') {
          prefs.putUInt("p24", p24);
          p1text = "";
          lcd.clear();
          a ++;
        }
        if (customKey == 'C') {
          p24 = 0;
          p1text = "";
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("цена 24");
          lcd.setCursor(0, 1);
          lcd.print(p24);
          lcd.setCursor(7, 1);
          lcd.print("руб.");
          lcd.setCursor(0, 3);
          lcd.print("Е далее    С удалить");
        }
      }
    }
    if (a == 25) {         //   // if (a == 25)
      lcd.setCursor(0, 0);
      lcd.print("цена 25");
      lcd.setCursor(0, 1);
      lcd.print(p25);
      lcd.setCursor(7, 1);
      lcd.print("руб.");
      lcd.setCursor(0, 3);
      lcd.print("Е далее    С удалить");
      customKey = customKeypad.getKey();
      if (isDigit(customKey)) {
        newchar = String(customKey);
        p1text = p1text + newchar;
        p25 = p1text.toInt();
      }
      else {
        if (customKey == 'E') {
          prefs.putUInt("p25", p25);
          p1text = "";
          lcd.clear();
          a ++;
        }
        if (customKey == 'C') {
          p25 = 0;
          p1text = "";
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("цена 25");
          lcd.setCursor(0, 1);
          lcd.print(p25);
          lcd.setCursor(7, 1);
          lcd.print("руб.");
          lcd.setCursor(0, 3);
          lcd.print("Е далее    С удалить");
        }
      }
    }
    if (a == 26) {         //   // if (a == 26)
      lcd.setCursor(0, 0);
      lcd.print("цена 26");
      lcd.setCursor(0, 1);
      lcd.print(p26);
      lcd.setCursor(7, 1);
      lcd.print("руб.");
      lcd.setCursor(0, 3);
      lcd.print("Е далее    С удалить");
      customKey = customKeypad.getKey();
      if (isDigit(customKey)) {
        newchar = String(customKey);
        p1text = p1text + newchar;
        p26 = p1text.toInt();
      }
      else {
        if (customKey == 'E') {
          prefs.putUInt("p26", p26);
          p1text = "";
          lcd.clear();
          a ++;
        }
        if (customKey == 'C') {
          p26 = 0;
          p1text = "";
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("цена 26");
          lcd.setCursor(0, 1);
          lcd.print(p26);
          lcd.setCursor(7, 1);
          lcd.print("руб.");
          lcd.setCursor(0, 3);
          lcd.print("Е далее    С удалить");
        }
      }
    }
    if (a == 27) {         //   // if (a == 27)
      lcd.setCursor(0, 0);
      lcd.print("цена 27");
      lcd.setCursor(0, 1);
      lcd.print(p27);
      lcd.setCursor(7, 1);
      lcd.print("руб.");
      lcd.setCursor(0, 3);
      lcd.print("Е далее    С удалить");
      customKey = customKeypad.getKey();
      if (isDigit(customKey)) {
        newchar = String(customKey);
        p1text = p1text + newchar;
        p27 = p1text.toInt();
      }
      else {
        if (customKey == 'E') {
          prefs.putUInt("p27", p27);
          p1text = "";
          lcd.clear();
          a ++;
        }
        if (customKey == 'C') {
          p27 = 0;
          p1text = "";
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("цена 27");
          lcd.setCursor(0, 1);
          lcd.print(p27);
          lcd.setCursor(7, 1);
          lcd.print("руб.");
          lcd.setCursor(0, 3);
          lcd.print("Е далее    С удалить");
        }
      }
    }
    if (a == 28) {         //   // if (a == 28)
      lcd.setCursor(0, 0);
      lcd.print("цена 28");
      lcd.setCursor(0, 1);
      lcd.print(p28);
      lcd.setCursor(7, 1);
      lcd.print("руб.");
      lcd.setCursor(0, 3);
      lcd.print("Е далее    С удалить");
      customKey = customKeypad.getKey();
      if (isDigit(customKey)) {
        newchar = String(customKey);
        p1text = p1text + newchar;
        p28 = p1text.toInt();
      }
      else {
        if (customKey == 'E') {
          prefs.putUInt("p28", p28);
          p1text = "";
          lcd.clear();
          a ++;
        }
        if (customKey == 'C') {
          p28 = 0;
          p1text = "";
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("цена 28");
          lcd.setCursor(0, 1);
          lcd.print(p28);
          lcd.setCursor(7, 1);
          lcd.print("руб.");
          lcd.setCursor(0, 3);
          lcd.print("Е далее    С удалить");
        }
      }
    }
    if (a == 29) {         //   // if (a == 29)
      lcd.setCursor(0, 0);
      lcd.print("цена 29");
      lcd.setCursor(0, 1);
      lcd.print(p29);
      lcd.setCursor(7, 1);
      lcd.print("руб.");
      lcd.setCursor(0, 3);
      lcd.print("Е далее    С удалить");
      customKey = customKeypad.getKey();
      if (isDigit(customKey)) {
        newchar = String(customKey);
        p1text = p1text + newchar;
        p29 = p1text.toInt();
      }
      else {
        if (customKey == 'E') {
          prefs.putUInt("p29", p29);
          p1text = "";
          lcd.clear();
          a ++;
        }
        if (customKey == 'C') {
          p29 = 0;
          p1text = "";
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("цена 29");
          lcd.setCursor(0, 1);
          lcd.print(p29);
          lcd.setCursor(7, 1);
          lcd.print("руб.");
          lcd.setCursor(0, 3);
          lcd.print("Е далее    С удалить");
        }
      }
    }
    if (a == 30) {         //   // if (a == 30)
      lcd.setCursor(0, 0);
      lcd.print("цена 30");
      lcd.setCursor(0, 1);
      lcd.print(p30);
      lcd.setCursor(7, 1);
      lcd.print("руб.");
      lcd.setCursor(0, 3);
      lcd.print("Е далее    С удалить");
      customKey = customKeypad.getKey();
      if (isDigit(customKey)) {
        newchar = String(customKey);
        p1text = p1text + newchar;
        p30 = p1text.toInt();
      }
      else {
        if (customKey == 'E') {
          prefs.putUInt("p30", p30);
          p1text = "";
          lcd.clear();
          a ++;
        }
        if (customKey == 'C') {
          p30 = 0;
          p1text = "";
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("цена 30");
          lcd.setCursor(0, 1);
          lcd.print(p30);
          lcd.setCursor(7, 1);
          lcd.print("руб.");
          lcd.setCursor(0, 3);
          lcd.print("Е далее    С удалить");
        }
      }
    }
    if (a == 31) {         //   // if (a == 31)
      lcd.setCursor(0, 0);
      lcd.print("цена 31");
      lcd.setCursor(0, 1);
      lcd.print(p31);
      lcd.setCursor(7, 1);
      lcd.print("руб.");
      lcd.setCursor(0, 3);
      lcd.print("Е далее    С удалить");
      customKey = customKeypad.getKey();
      if (isDigit(customKey)) {
        newchar = String(customKey);
        p1text = p1text + newchar;
        p31 = p1text.toInt();
      }
      else {
        if (customKey == 'E') {
          prefs.putUInt("p31", p31);
          p1text = "";
          lcd.clear();
          a ++;
        }
        if (customKey == 'C') {
          p31 = 0;
          p1text = "";
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("цена 31");
          lcd.setCursor(0, 1);
          lcd.print(p31);
          lcd.setCursor(7, 1);
          lcd.print("руб.");
          lcd.setCursor(0, 3);
          lcd.print("Е далее    С удалить");
        }
      }
    }
    if (a == 32) {         //   // if (a == 32)
      lcd.setCursor(0, 0);
      lcd.print("цена 32");
      lcd.setCursor(0, 1);
      lcd.print(p32);
      lcd.setCursor(7, 1);
      lcd.print("руб.");
      lcd.setCursor(0, 3);
      lcd.print("Е далее    С удалить");
      customKey = customKeypad.getKey();
      if (isDigit(customKey)) {
        newchar = String(customKey);
        p1text = p1text + newchar;
        p32 = p1text.toInt();
      }
      else {
        if (customKey == 'E') {
          prefs.putUInt("p32", p32);
          p1text = "";
          lcd.clear();
          a ++;
        }
        if (customKey == 'C') {
          p32 = 0;
          p1text = "";
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("цена 32");
          lcd.setCursor(0, 1);
          lcd.print(p32);
          lcd.setCursor(7, 1);
          lcd.print("руб.");
          lcd.setCursor(0, 3);
          lcd.print("Е далее    С удалить");
        }
      }
    }
    if (a == 33) {         //   // if (a == 33)
      lcd.setCursor(0, 0);
      lcd.print("цена 33");
      lcd.setCursor(0, 1);
      lcd.print(p33);
      lcd.setCursor(7, 1);
      lcd.print("руб.");
      lcd.setCursor(0, 3);
      lcd.print("Е далее    С удалить");
      customKey = customKeypad.getKey();
      if (isDigit(customKey)) {
        newchar = String(customKey);
        p1text = p1text + newchar;
        p33 = p1text.toInt();
      }
      else {
        if (customKey == 'E') {
          prefs.putUInt("p33", p33);
          p1text = "";
          lcd.clear();
          a ++;
        }
        if (customKey == 'C') {
          p33 = 0;
          p1text = "";
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("цена 33");
          lcd.setCursor(0, 1);
          lcd.print(p33);
          lcd.setCursor(7, 1);
          lcd.print("руб.");
          lcd.setCursor(0, 3);
          lcd.print("Е далее    С удалить");
        }
      }
    }
    if (a == 34) {         //   // if (a == 34)
      lcd.setCursor(0, 0);
      lcd.print("цена 34");
      lcd.setCursor(0, 1);
      lcd.print(p34);
      lcd.setCursor(7, 1);
      lcd.print("руб.");
      lcd.setCursor(0, 3);
      lcd.print("Е далее    С удалить");
      customKey = customKeypad.getKey();
      if (isDigit(customKey)) {
        newchar = String(customKey);
        p1text = p1text + newchar;
        p34 = p1text.toInt();
      }
      else {
        if (customKey == 'E') {
          prefs.putUInt("p34", p34);
          p1text = "";
          lcd.clear();
          a ++;
        }
        if (customKey == 'C') {
          p34 = 0;
          p1text = "";
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("цена 34");
          lcd.setCursor(0, 1);
          lcd.print(p34);
          lcd.setCursor(7, 1);
          lcd.print("руб.");
          lcd.setCursor(0, 3);
          lcd.print("Е далее    С удалить");
        }
      }
    }
    if (a == 35) {         //   // if (a == 35)
      lcd.setCursor(0, 0);
      lcd.print("цена 35");
      lcd.setCursor(0, 1);
      lcd.print(p35);
      lcd.setCursor(7, 1);
      lcd.print("руб.");
      lcd.setCursor(0, 3);
      lcd.print("Е далее    С удалить");
      customKey = customKeypad.getKey();
      if (isDigit(customKey)) {
        newchar = String(customKey);
        p1text = p1text + newchar;
        p35 = p1text.toInt();
      }
      else {
        if (customKey == 'E') {
          prefs.putUInt("p35", p35);
          p1text = "";
          lcd.clear();
          a ++;
        }
        if (customKey == 'C') {
          p35 = 0;
          p1text = "";
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("цена 35");
          lcd.setCursor(0, 1);
          lcd.print(p35);
          lcd.setCursor(7, 1);
          lcd.print("руб.");
          lcd.setCursor(0, 3);
          lcd.print("Е далее    С удалить");
        }
      }
    }
    if (a == 36) {         //   // if (a == 36)
      lcd.setCursor(0, 0);
      lcd.print("цена 36");
      lcd.setCursor(0, 1);
      lcd.print(p36);
      lcd.setCursor(7, 1);
      lcd.print("руб.");
      lcd.setCursor(0, 3);
      lcd.print("Е далее    С удалить");
      customKey = customKeypad.getKey();
      if (isDigit(customKey)) {
        newchar = String(customKey);
        p1text = p1text + newchar;
        p36 = p1text.toInt();
      }
      else {
        if (customKey == 'E') {
          prefs.putUInt("p36", p36);
          p1text = "";
          lcd.clear();
          a ++;
        }
        if (customKey == 'C') {
          p36 = 0;
          p1text = "";
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("цена 36");
          lcd.setCursor(0, 1);
          lcd.print(p36);
          lcd.setCursor(7, 1);
          lcd.print("руб.");
          lcd.setCursor(0, 3);
          lcd.print("Е далее    С удалить");
        }
      }
    }
    if (a == 37) {         //   // if (a == 37)
      lcd.setCursor(0, 0);
      lcd.print("цена 37");
      lcd.setCursor(0, 1);
      lcd.print(p37);
      lcd.setCursor(7, 1);
      lcd.print("руб.");
      lcd.setCursor(0, 3);
      lcd.print("Е далее    С удалить");
      customKey = customKeypad.getKey();
      if (isDigit(customKey)) {
        newchar = String(customKey);
        p1text = p1text + newchar;
        p37 = p1text.toInt();
      }
      else {
        if (customKey == 'E') {
          prefs.putUInt("p37", p37);
          p1text = "";
          lcd.clear();
          a ++;
        }
        if (customKey == 'C') {
          p37 = 0;
          p1text = "";
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("цена 37");
          lcd.setCursor(0, 1);
          lcd.print(p37);
          lcd.setCursor(7, 1);
          lcd.print("руб.");
          lcd.setCursor(0, 3);
          lcd.print("Е далее    С удалить");
        }
      }
    }
    if (a == 38) {         //   // if (a == 38)
      lcd.setCursor(0, 0);
      lcd.print("цена 38");
      lcd.setCursor(0, 1);
      lcd.print(p38);
      lcd.setCursor(7, 1);
      lcd.print("руб.");
      lcd.setCursor(0, 3);
      lcd.print("Е далее    С удалить");
      customKey = customKeypad.getKey();
      if (isDigit(customKey)) {
        newchar = String(customKey);
        p1text = p1text + newchar;
        p38 = p1text.toInt();
      }
      else {
        if (customKey == 'E') {
          prefs.putUInt("p38", p38);
          p1text = "";
          lcd.clear();
          a ++;
        }
        if (customKey == 'C') {
          p38 = 0;
          p1text = "";
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("цена 38");
          lcd.setCursor(0, 1);
          lcd.print(p38);
          lcd.setCursor(7, 1);
          lcd.print("руб.");
          lcd.setCursor(0, 3);
          lcd.print("Е далее    С удалить");
        }
      }
    }
    if (a == 39) {         //   // if (a == 39)
      lcd.setCursor(0, 0);
      lcd.print("цена 39");
      lcd.setCursor(0, 1);
      lcd.print(p39);
      lcd.setCursor(7, 1);
      lcd.print("руб.");
      lcd.setCursor(0, 3);
      lcd.print("Е далее    С удалить");
      customKey = customKeypad.getKey();
      if (isDigit(customKey)) {
        newchar = String(customKey);
        p1text = p1text + newchar;
        p39 = p1text.toInt();
      }
      else {
        if (customKey == 'E') {
          prefs.putUInt("p39", p39);
          p1text = "";
          lcd.clear();
          a ++;
        }
        if (customKey == 'C') {
          p39 = 0;
          p1text = "";
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("цена 39");
          lcd.setCursor(0, 1);
          lcd.print(p39);
          lcd.setCursor(7, 1);
          lcd.print("руб.");
          lcd.setCursor(0, 3);
          lcd.print("Е далее    С удалить");
        }
      }
    }
    if (a == 40) {         //   // if (a == 40)
      lcd.setCursor(0, 0);
      lcd.print("цена 40");
      lcd.setCursor(0, 1);
      lcd.print(p40);
      lcd.setCursor(7, 1);
      lcd.print("руб.");
      lcd.setCursor(0, 3);
      lcd.print("Е далее    С удалить");
      customKey = customKeypad.getKey();
      if (isDigit(customKey)) {
        newchar = String(customKey);
        p1text = p1text + newchar;
        p40 = p1text.toInt();
      }
      else {
        if (customKey == 'E') {
          prefs.putUInt("p40", p40);
          p1text = "";
          lcd.clear();
          a ++;
        }
        if (customKey == 'C') {
          p40 = 0;
          p1text = "";
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("цена 40");
          lcd.setCursor(0, 1);
          lcd.print(p40);
          lcd.setCursor(7, 1);
          lcd.print("руб.");
          lcd.setCursor(0, 3);
          lcd.print("Е далее    С удалить");
        }
      }
    }
    if (a == 41) {         //   // if (a == 41)
      lcd.setCursor(0, 0);
      lcd.print("цена 41");
      lcd.setCursor(0, 1);
      lcd.print(p41);
      lcd.setCursor(7, 1);
      lcd.print("руб.");
      lcd.setCursor(0, 3);
      lcd.print("Е далее    С удалить");
      customKey = customKeypad.getKey();
      if (isDigit(customKey)) {
        newchar = String(customKey);
        p1text = p1text + newchar;
        p41 = p1text.toInt();
      }
      else {
        if (customKey == 'E') {
          prefs.putUInt("p41", p41);
          p1text = "";
          lcd.clear();
          a ++;
        }
        if (customKey == 'C') {
          p41 = 0;
          p1text = "";
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("цена 41");
          lcd.setCursor(0, 1);
          lcd.print(p41);
          lcd.setCursor(7, 1);
          lcd.print("руб.");
          lcd.setCursor(0, 3);
          lcd.print("Е далее    С удалить");
        }
      }
    }
    if (a == 42) {         //   // if (a == 42)
      lcd.setCursor(0, 0);
      lcd.print("цена 42");
      lcd.setCursor(0, 1);
      lcd.print(p42);
      lcd.setCursor(7, 1);
      lcd.print("руб.");
      lcd.setCursor(0, 3);
      lcd.print("Е далее    С удалить");
      customKey = customKeypad.getKey();
      if (isDigit(customKey)) {
        newchar = String(customKey);
        p1text = p1text + newchar;
        p42 = p1text.toInt();
      }
      else {
        if (customKey == 'E') {
          prefs.putUInt("p42", p42);
          p1text = "";
          lcd.clear();
          a ++;
        }
        if (customKey == 'C') {
          p42 = 0;
          p1text = "";
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("цена 42");
          lcd.setCursor(0, 1);
          lcd.print(p42);
          lcd.setCursor(7, 1);
          lcd.print("руб.");
          lcd.setCursor(0, 3);
          lcd.print("Е далее    С удалить");
        }
      }
    }
    if (a == 43) {         //   // if (a == 43)
      lcd.setCursor(0, 0);
      lcd.print("цена 43");
      lcd.setCursor(0, 1);
      lcd.print(p43);
      lcd.setCursor(7, 1);
      lcd.print("руб.");
      lcd.setCursor(0, 3);
      lcd.print("Е далее    С удалить");
      customKey = customKeypad.getKey();
      if (isDigit(customKey)) {
        newchar = String(customKey);
        p1text = p1text + newchar;
        p43 = p1text.toInt();
      }
      else {
        if (customKey == 'E') {
          prefs.putUInt("p43", p43);
          p1text = "";
          lcd.clear();
          a ++;
        }
        if (customKey == 'C') {
          p43 = 0;
          p1text = "";
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("цена 43");
          lcd.setCursor(0, 1);
          lcd.print(p43);
          lcd.setCursor(7, 1);
          lcd.print("руб.");
          lcd.setCursor(0, 3);
          lcd.print("Е далее    С удалить");
        }
      }
    }
    if (a == 44) {         //   // if (a == 44)
      lcd.setCursor(0, 0);
      lcd.print("цена 44");
      lcd.setCursor(0, 1);
      lcd.print(p44);
      lcd.setCursor(7, 1);
      lcd.print("руб.");
      lcd.setCursor(0, 3);
      lcd.print("Е далее    С удалить");
      customKey = customKeypad.getKey();
      if (isDigit(customKey)) {
        newchar = String(customKey);
        p1text = p1text + newchar;
        p44 = p1text.toInt();
      }
      else {
        if (customKey == 'E') {
          prefs.putUInt("p44", p44);
          p1text = "";
          lcd.clear();
          a ++;
        }
        if (customKey == 'C') {
          p44 = 0;
          p1text = "";
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("цена 44");
          lcd.setCursor(0, 1);
          lcd.print(p44);
          lcd.setCursor(7, 1);
          lcd.print("руб.");
          lcd.setCursor(0, 3);
          lcd.print("Е далее    С удалить");
        }
      }
    }
    if (a == 45) {         //   // if (a == 45)
      lcd.setCursor(0, 0);
      lcd.print("цена 45");
      lcd.setCursor(0, 1);
      lcd.print(p45);
      lcd.setCursor(7, 1);
      lcd.print("руб.");
      lcd.setCursor(0, 3);
      lcd.print("Е далее    С удалить");
      customKey = customKeypad.getKey();
      if (isDigit(customKey)) {
        newchar = String(customKey);
        p1text = p1text + newchar;
        p45 = p1text.toInt();
      }
      else {
        if (customKey == 'E') {
          prefs.putUInt("p45", p45);
          p1text = "";
          lcd.clear();
          a ++;
        }
        if (customKey == 'C') {
          p45 = 0;
          p1text = "";
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("цена 45");
          lcd.setCursor(0, 1);
          lcd.print(p45);
          lcd.setCursor(7, 1);
          lcd.print("руб.");
          lcd.setCursor(0, 3);
          lcd.print("Е далее    С удалить");
        }
      }
    }
    if (a == 46) {         //   // if (a == 46)
      lcd.setCursor(0, 0);
      lcd.print("цена 46");
      lcd.setCursor(0, 1);
      lcd.print(p46);
      lcd.setCursor(7, 1);
      lcd.print("руб.");
      lcd.setCursor(0, 3);
      lcd.print("Е далее    С удалить");
      customKey = customKeypad.getKey();
      if (isDigit(customKey)) {
        newchar = String(customKey);
        p1text = p1text + newchar;
        p46 = p1text.toInt();
      }
      else {
        if (customKey == 'E') {
          prefs.putUInt("p46", p46);
          p1text = "";
          lcd.clear();
          a ++;
        }
        if (customKey == 'C') {
          p46 = 0;
          p1text = "";
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("цена 46");
          lcd.setCursor(0, 1);
          lcd.print(p46);
          lcd.setCursor(7, 1);
          lcd.print("руб.");
          lcd.setCursor(0, 3);
          lcd.print("Е далее    С удалить");
        }
      }
    }
    if (a == 47) {         //   // if (a == 47)
      lcd.setCursor(0, 0);
      lcd.print("цена 47");
      lcd.setCursor(0, 1);
      lcd.print(p47);
      lcd.setCursor(7, 1);
      lcd.print("руб.");
      lcd.setCursor(0, 3);
      lcd.print("Е далее    С удалить");
      customKey = customKeypad.getKey();
      if (isDigit(customKey)) {
        newchar = String(customKey);
        p1text = p1text + newchar;
        p47 = p1text.toInt();
      }
      else {
        if (customKey == 'E') {
          prefs.putUInt("p47", p47);
          p1text = "";
          lcd.clear();
          a ++;
        }
        if (customKey == 'C') {
          p47 = 0;
          p1text = "";
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("цена 47");
          lcd.setCursor(0, 1);
          lcd.print(p47);
          lcd.setCursor(7, 1);
          lcd.print("руб.");
          lcd.setCursor(0, 3);
          lcd.print("Е далее    С удалить");
        }
      }
    }
    if (a == 48) {         //   // if (a == 48)
      lcd.setCursor(0, 0);
      lcd.print("цена 48");
      lcd.setCursor(0, 1);
      lcd.print(p48);
      lcd.setCursor(7, 1);
      lcd.print("руб.");
      lcd.setCursor(0, 3);
      lcd.print("Е далее    С удалить");
      customKey = customKeypad.getKey();
      if (isDigit(customKey)) {
        newchar = String(customKey);
        p1text = p1text + newchar;
        p48 = p1text.toInt();
      }
      else {
        if (customKey == 'E') {
          prefs.putUInt("p48", p48);
          p1text = "";
          lcd.clear();
          a ++;
        }
        if (customKey == 'C') {
          p48 = 0;
          p1text = "";
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("цена 48");
          lcd.setCursor(0, 1);
          lcd.print(p48);
          lcd.setCursor(7, 1);
          lcd.print("руб.");
          lcd.setCursor(0, 3);
          lcd.print("Е далее    С удалить");
        }
      }
    }
    if (a == 49) {         //   // if (a == 49)
      lcd.setCursor(0, 0);
      lcd.print("цена 49");
      lcd.setCursor(0, 1);
      lcd.print(p49);
      lcd.setCursor(7, 1);
      lcd.print("руб.");
      lcd.setCursor(0, 3);
      lcd.print("Е далее    С удалить");
      customKey = customKeypad.getKey();
      if (isDigit(customKey)) {
        newchar = String(customKey);
        p1text = p1text + newchar;
        p49 = p1text.toInt();
      }
      else {
        if (customKey == 'E') {
          prefs.putUInt("p49", p49);
          p1text = "";
          lcd.clear();
          a ++;
        }
        if (customKey == 'C') {
          p49 = 0;
          p1text = "";
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("цена 49");
          lcd.setCursor(0, 1);
          lcd.print(p49);
          lcd.setCursor(7, 1);
          lcd.print("руб.");
          lcd.setCursor(0, 3);
          lcd.print("Е далее    С удалить");
        }
      }
    }
    if (a == 50) {         //   // if (a == 50)
      lcd.setCursor(0, 0);
      lcd.print("цена 50");
      lcd.setCursor(0, 1);
      lcd.print(p50);
      lcd.setCursor(7, 1);
      lcd.print("руб.");
      lcd.setCursor(0, 3);
      lcd.print("Е далее    С удалить");
      customKey = customKeypad.getKey();
      if (isDigit(customKey)) {
        newchar = String(customKey);
        p1text = p1text + newchar;
        p50 = p1text.toInt();
      }
      else {
        if (customKey == 'E') {
          prefs.putUInt("p50", p50);
          p1text = "";
          lcd.clear();
          a ++;
        }
        if (customKey == 'C') {
          p50 = 0;
          p1text = "";
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("цена 50");
          lcd.setCursor(0, 1);
          lcd.print(p50);
          lcd.setCursor(7, 1);
          lcd.print("руб.");
          lcd.setCursor(0, 3);
          lcd.print("Е далее    С удалить");
        }
      }
    }
    if (a == 51) {         //   // if (a == 51)
      lcd.setCursor(0, 0);
      lcd.print("цена 51");
      lcd.setCursor(0, 1);
      lcd.print(p51);
      lcd.setCursor(7, 1);
      lcd.print("руб.");
      lcd.setCursor(0, 3);
      lcd.print("Е далее    С удалить");
      customKey = customKeypad.getKey();
      if (isDigit(customKey)) {
        newchar = String(customKey);
        p1text = p1text + newchar;
        p51 = p1text.toInt();
      }
      else {
        if (customKey == 'E') {
          prefs.putUInt("p51", p51);
          p1text = "";
          lcd.clear();
          a ++;
        }
        if (customKey == 'C') {
          p51 = 0;
          p1text = "";
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("цена 51");
          lcd.setCursor(0, 1);
          lcd.print(p51);
          lcd.setCursor(7, 1);
          lcd.print("руб.");
          lcd.setCursor(0, 3);
          lcd.print("Е далее    С удалить");
        }
      }
    }
    if (a == 52) {         //   // if (a == 52)
      lcd.setCursor(0, 0);
      lcd.print("цена 52");
      lcd.setCursor(0, 1);
      lcd.print(p52);
      lcd.setCursor(7, 1);
      lcd.print("руб.");
      lcd.setCursor(0, 3);
      lcd.print("Е далее    С удалить");
      customKey = customKeypad.getKey();
      if (isDigit(customKey)) {
        newchar = String(customKey);
        p1text = p1text + newchar;
        p52 = p1text.toInt();
      }
      else {
        if (customKey == 'E') {
          prefs.putUInt("p52", p52);
          p1text = "";
          lcd.clear();
          a ++;
        }
        if (customKey == 'C') {
          p52 = 0;
          p1text = "";
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("цена 52");
          lcd.setCursor(0, 1);
          lcd.print(p52);
          lcd.setCursor(7, 1);
          lcd.print("руб.");
          lcd.setCursor(0, 3);
          lcd.print("Е далее    С удалить");
        }
      }
    }
    if (a == 53) {         //   // if (a == 53)
      lcd.setCursor(0, 0);
      lcd.print("цена 53");
      lcd.setCursor(0, 1);
      lcd.print(p53);
      lcd.setCursor(7, 1);
      lcd.print("руб.");
      lcd.setCursor(0, 3);
      lcd.print("Е далее    С удалить");
      customKey = customKeypad.getKey();
      if (isDigit(customKey)) {
        newchar = String(customKey);
        p1text = p1text + newchar;
        p53 = p1text.toInt();
      }
      else {
        if (customKey == 'E') {
          prefs.putUInt("p53", p53);
          p1text = "";
          lcd.clear();
          a ++;
        }
        if (customKey == 'C') {
          p53 = 0;
          p1text = "";
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("цена 53");
          lcd.setCursor(0, 1);
          lcd.print(p53);
          lcd.setCursor(7, 1);
          lcd.print("руб.");
          lcd.setCursor(0, 3);
          lcd.print("Е далее    С удалить");
        }
      }
    }
    if (a == 54) {         //   // if (a == 54)
      lcd.setCursor(0, 0);
      lcd.print("цена 54");
      lcd.setCursor(0, 1);
      lcd.print(p54);
      lcd.setCursor(7, 1);
      lcd.print("руб.");
      lcd.setCursor(0, 3);
      lcd.print("Е далее    С удалить");
      customKey = customKeypad.getKey();
      if (isDigit(customKey)) {
        newchar = String(customKey);
        p1text = p1text + newchar;
        p54 = p1text.toInt();
      }
      else {
        if (customKey == 'E') {
          prefs.putUInt("p54", p54);
          p1text = "";
          lcd.clear();
          a ++;
        }
        if (customKey == 'C') {
          p54 = 0;
          p1text = "";
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("цена 54");
          lcd.setCursor(0, 1);
          lcd.print(p54);
          lcd.setCursor(7, 1);
          lcd.print("руб.");
          lcd.setCursor(0, 3);
          lcd.print("Е далее    С удалить");
        }
      }
    }
    if (a == 55) {         //   // if (a == 55)
      lcd.setCursor(0, 0);
      lcd.print("цена 55");
      lcd.setCursor(0, 1);
      lcd.print(p55);
      lcd.setCursor(7, 1);
      lcd.print("руб.");
      lcd.setCursor(0, 3);
      lcd.print("Е далее    С удалить");
      customKey = customKeypad.getKey();
      if (isDigit(customKey)) {
        newchar = String(customKey);
        p1text = p1text + newchar;
        p55 = p1text.toInt();
      }
      else {
        if (customKey == 'E') {
          prefs.putUInt("p55", p55);
          p1text = "";
          lcd.clear();
          a ++;
        }
        if (customKey == 'C') {
          p55 = 0;
          p1text = "";
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("цена 55");
          lcd.setCursor(0, 1);
          lcd.print(p55);
          lcd.setCursor(7, 1);
          lcd.print("руб.");
          lcd.setCursor(0, 3);
          lcd.print("Е далее    С удалить");
        }
      }
    }
    if (a == 56) {         //   // if (a == 56)
      lcd.setCursor(0, 0);
      lcd.print("цена 56");
      lcd.setCursor(0, 1);
      lcd.print(p56);
      lcd.setCursor(7, 1);
      lcd.print("руб.");
      lcd.setCursor(0, 3);
      lcd.print("Е далее    С удалить");
      customKey = customKeypad.getKey();
      if (isDigit(customKey)) {
        newchar = String(customKey);
        p1text = p1text + newchar;
        p56 = p1text.toInt();
      }
      else {
        if (customKey == 'E') {
          prefs.putUInt("p56", p56);
          p1text = "";
          lcd.clear();
          a ++;
        }
        if (customKey == 'C') {
          p56 = 0;
          p1text = "";
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("цена 56");
          lcd.setCursor(0, 1);
          lcd.print(p56);
          lcd.setCursor(7, 1);
          lcd.print("руб.");
          lcd.setCursor(0, 3);
          lcd.print("Е далее    С удалить");
        }
      }
    }
    if (a == 57) {         //   // if (a == 57)
      lcd.setCursor(0, 0);
      lcd.print("цена 57");
      lcd.setCursor(0, 1);
      lcd.print(p57);
      lcd.setCursor(7, 1);
      lcd.print("руб.");
      lcd.setCursor(0, 3);
      lcd.print("Е далее    С удалить");
      customKey = customKeypad.getKey();
      if (isDigit(customKey)) {
        newchar = String(customKey);
        p1text = p1text + newchar;
        p57 = p1text.toInt();
      }
      else {
        if (customKey == 'E') {
          prefs.putUInt("p57", p57);
          p1text = "";
          lcd.clear();
          a ++;
        }
        if (customKey == 'C') {
          p57 = 0;
          p1text = "";
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("цена 57");
          lcd.setCursor(0, 1);
          lcd.print(p57);
          lcd.setCursor(7, 1);
          lcd.print("руб.");
          lcd.setCursor(0, 3);
          lcd.print("Е далее    С удалить");
        }
      }
    }
    if (a == 58) {         //   // if (a == 58)
      lcd.setCursor(0, 0);
      lcd.print("цена 58");
      lcd.setCursor(0, 1);
      lcd.print(p58);
      lcd.setCursor(7, 1);
      lcd.print("руб.");
      lcd.setCursor(0, 3);
      lcd.print("Е далее    С удалить");
      customKey = customKeypad.getKey();
      if (isDigit(customKey)) {
        newchar = String(customKey);
        p1text = p1text + newchar;
        p58 = p1text.toInt();
      }
      else {
        if (customKey == 'E') {
          prefs.putUInt("p58", p58);
          p1text = "";
          lcd.clear();
          a ++;
        }
        if (customKey == 'C') {
          p58 = 0;
          p1text = "";
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("цена 58");
          lcd.setCursor(0, 1);
          lcd.print(p58);
          lcd.setCursor(7, 1);
          lcd.print("руб.");
          lcd.setCursor(0, 3);
          lcd.print("Е далее    С удалить");
        }
      }
    }
    if (a == 59) {         //   // if (a == 59)
      lcd.setCursor(0, 0);
      lcd.print("цена 59");
      lcd.setCursor(0, 1);
      lcd.print(p59);
      lcd.setCursor(7, 1);
      lcd.print("руб.");
      lcd.setCursor(0, 3);
      lcd.print("Е далее    С удалить");
      customKey = customKeypad.getKey();
      if (isDigit(customKey)) {
        newchar = String(customKey);
        p1text = p1text + newchar;
        p59 = p1text.toInt();
      }
      else {
        if (customKey == 'E') {
          prefs.putUInt("p59", p59);
          p1text = "";
          lcd.clear();
          a ++;
        }
        if (customKey == 'C') {
          p59 = 0;
          p1text = "";
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("цена 59");
          lcd.setCursor(0, 1);
          lcd.print(p59);
          lcd.setCursor(7, 1);
          lcd.print("руб.");
          lcd.setCursor(0, 3);
          lcd.print("Е далее    С удалить");
        }
      }
    }
    if (a == 60) {         //   // if (a == 60)
      lcd.setCursor(0, 0);
      lcd.print("цена 60");
      lcd.setCursor(0, 1);
      lcd.print(p60);
      lcd.setCursor(7, 1);
      lcd.print("руб.");
      lcd.setCursor(0, 3);
      lcd.print("Е далее    С удалить");
      customKey = customKeypad.getKey();
      if (isDigit(customKey)) {
        newchar = String(customKey);
        p1text = p1text + newchar;
        p60 = p1text.toInt();
      }
      else {
        if (customKey == 'E') {
          prefs.putUInt("p60", p60);
          p1text = "";
          lcd.clear();
          a ++;
        }
        if (customKey == 'C') {
          p60 = 0;
          p1text = "";
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("цена 60");
          lcd.setCursor(0, 1);
          lcd.print(p60);
          lcd.setCursor(7, 1);
          lcd.print("руб.");
          lcd.setCursor(0, 3);
          lcd.print("Е далее    С удалить");
        }
      }
    }
    if (a == 61) {         //   // if (a == 61)
      lcd.setCursor(0, 0);
      lcd.print("цена 61");
      lcd.setCursor(0, 1);
      lcd.print(p61);
      lcd.setCursor(7, 1);
      lcd.print("руб.");
      lcd.setCursor(0, 3);
      lcd.print("Е далее    С удалить");
      customKey = customKeypad.getKey();
      if (isDigit(customKey)) {
        newchar = String(customKey);
        p1text = p1text + newchar;
        p61 = p1text.toInt();
      }
      else {
        if (customKey == 'E') {
          prefs.putUInt("p61", p61);
          p1text = "";
          lcd.clear();
          a ++;
        }
        if (customKey == 'C') {
          p61 = 0;
          p1text = "";
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("цена 61");
          lcd.setCursor(0, 1);
          lcd.print(p61);
          lcd.setCursor(7, 1);
          lcd.print("руб.");
          lcd.setCursor(0, 3);
          lcd.print("Е далее    С удалить");
        }
      }
    }
    if (a == 62) {         //   // if (a == 62)
      lcd.setCursor(0, 0);
      lcd.print("цена 62");
      lcd.setCursor(0, 1);
      lcd.print(p62);
      lcd.setCursor(7, 1);
      lcd.print("руб.");
      lcd.setCursor(0, 3);
      lcd.print("Е далее    С удалить");
      customKey = customKeypad.getKey();
      if (isDigit(customKey)) {
        newchar = String(customKey);
        p1text = p1text + newchar;
        p62 = p1text.toInt();
      }
      else {
        if (customKey == 'E') {
          prefs.putUInt("p62", p62);
          p1text = "";
          lcd.clear();
          a ++;
        }
        if (customKey == 'C') {
          p62 = 0;
          p1text = "";
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("цена 62");
          lcd.setCursor(0, 1);
          lcd.print(p62);
          lcd.setCursor(7, 1);
          lcd.print("руб.");
          lcd.setCursor(0, 3);
          lcd.print("Е далее    С удалить");
        }
      }
    }
    if (a == 63) {         //   // if (a == 63)
      lcd.setCursor(0, 0);
      lcd.print("цена 63");
      lcd.setCursor(0, 1);
      lcd.print(p63);
      lcd.setCursor(7, 1);
      lcd.print("руб.");
      lcd.setCursor(0, 3);
      lcd.print("Е далее    С удалить");
      customKey = customKeypad.getKey();
      if (isDigit(customKey)) {
        newchar = String(customKey);
        p1text = p1text + newchar;
        p63 = p1text.toInt();
      }
      else {
        if (customKey == 'E') {
          prefs.putUInt("p63", p63);
          p1text = "";
          lcd.clear();
          a ++;
        }
        if (customKey == 'C') {
          p63 = 0;
          p1text = "";
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("цена 63");
          lcd.setCursor(0, 1);
          lcd.print(p63);
          lcd.setCursor(7, 1);
          lcd.print("руб.");
          lcd.setCursor(0, 3);
          lcd.print("Е далее    С удалить");
        }
      }
    }
    if (a == 64) {         //   // if (a == 64)
      lcd.setCursor(0, 0);
      lcd.print("цена 64");
      lcd.setCursor(0, 1);
      lcd.print(p64);
      lcd.setCursor(7, 1);
      lcd.print("руб.");
      lcd.setCursor(0, 3);
      lcd.print("Е далее    С удалить");
      customKey = customKeypad.getKey();
      if (isDigit(customKey)) {
        newchar = String(customKey);
        p1text = p1text + newchar;
        p64 = p1text.toInt();
      }
      else {
        if (customKey == 'E') {
          prefs.putUInt("p64", p64);
          p1text = "";
          lcd.clear();
          a ++;
        }
        if (customKey == 'C') {
          p64 = 0;
          p1text = "";
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("цена 64");
          lcd.setCursor(0, 1);
          lcd.print(p64);
          lcd.setCursor(7, 1);
          lcd.print("руб.");
          lcd.setCursor(0, 3);
          lcd.print("Е далее    С удалить");
        }
      }
    }
    if (a == 65) {         //   // if (a == 65)
      lcd.setCursor(0, 0);
      lcd.print("цена 65");
      lcd.setCursor(0, 1);
      lcd.print(p65);
      lcd.setCursor(7, 1);
      lcd.print("руб.");
      lcd.setCursor(0, 3);
      lcd.print("Е далее    С удалить");
      customKey = customKeypad.getKey();
      if (isDigit(customKey)) {
        newchar = String(customKey);
        p1text = p1text + newchar;
        p65 = p1text.toInt();
      }
      else {
        if (customKey == 'E') {
          prefs.putUInt("p65", p65);
          p1text = "";
          lcd.clear();
          a ++;
        }
        if (customKey == 'C') {
          p65 = 0;
          p1text = "";
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("цена 65");
          lcd.setCursor(0, 1);
          lcd.print(p65);
          lcd.setCursor(7, 1);
          lcd.print("руб.");
          lcd.setCursor(0, 3);
          lcd.print("Е далее    С удалить");
        }
      }
    }
    if (a == 66) {         //   // if (a == 66)
      lcd.setCursor(0, 0);
      lcd.print("цена 66");
      lcd.setCursor(0, 1);
      lcd.print(p66);
      lcd.setCursor(7, 1);
      lcd.print("руб.");
      lcd.setCursor(0, 3);
      lcd.print("Е далее    С удалить");
      customKey = customKeypad.getKey();
      if (isDigit(customKey)) {
        newchar = String(customKey);
        p1text = p1text + newchar;
        p66 = p1text.toInt();
      }
      else {
        if (customKey == 'E') {
          prefs.putUInt("p66", p66);
          p1text = "";
          lcd.clear();
          a ++;
        }
        if (customKey == 'C') {
          p66 = 0;
          p1text = "";
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("цена 66");
          lcd.setCursor(0, 1);
          lcd.print(p66);
          lcd.setCursor(7, 1);
          lcd.print("руб.");
          lcd.setCursor(0, 3);
          lcd.print("Е далее    С удалить");
        }
      }
    }
    if (a == 67) {         //   // if (a == 67)
      lcd.setCursor(0, 0);
      lcd.print("цена 67");
      lcd.setCursor(0, 1);
      lcd.print(p67);
      lcd.setCursor(7, 1);
      lcd.print("руб.");
      lcd.setCursor(0, 3);
      lcd.print("Е далее    С удалить");
      customKey = customKeypad.getKey();
      if (isDigit(customKey)) {
        newchar = String(customKey);
        p1text = p1text + newchar;
        p67 = p1text.toInt();
      }
      else {
        if (customKey == 'E') {
          prefs.putUInt("p67", p67);
          p1text = "";
          lcd.clear();
          a ++;
        }
        if (customKey == 'C') {
          p67 = 0;
          p1text = "";
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("цена 67");
          lcd.setCursor(0, 1);
          lcd.print(p67);
          lcd.setCursor(7, 1);
          lcd.print("руб.");
          lcd.setCursor(0, 3);
          lcd.print("Е далее    С удалить");
        }
      }
    }
    if (a == 68) {         //   // if (a == 68)
      lcd.setCursor(0, 0);
      lcd.print("цена 68");
      lcd.setCursor(0, 1);
      lcd.print(p68);
      lcd.setCursor(7, 1);
      lcd.print("руб.");
      lcd.setCursor(0, 3);
      lcd.print("Е далее    С удалить");
      customKey = customKeypad.getKey();
      if (isDigit(customKey)) {
        newchar = String(customKey);
        p1text = p1text + newchar;
        p68 = p1text.toInt();
      }
      else {
        if (customKey == 'E') {
          prefs.putUInt("p68", p68);
          p1text = "";
          lcd.clear();
          a ++;
        }
        if (customKey == 'C') {
          p68 = 0;
          p1text = "";
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("цена 68");
          lcd.setCursor(0, 1);
          lcd.print(p68);
          lcd.setCursor(7, 1);
          lcd.print("руб.");
          lcd.setCursor(0, 3);
          lcd.print("Е далее    С удалить");
        }
      }
    }
    if (a == 69) {         //   // if (a == 69)
      lcd.setCursor(0, 0);
      lcd.print("цена 69");
      lcd.setCursor(0, 1);
      lcd.print(p69);
      lcd.setCursor(7, 1);
      lcd.print("руб.");
      lcd.setCursor(0, 3);
      lcd.print("Е далее    С удалить");
      customKey = customKeypad.getKey();
      if (isDigit(customKey)) {
        newchar = String(customKey);
        p1text = p1text + newchar;
        p69 = p1text.toInt();
      }
      else {
        if (customKey == 'E') {
          prefs.putUInt("p69", p69);
          p1text = "";
          lcd.clear();
          a ++;
        }
        if (customKey == 'C') {
          p69 = 0;
          p1text = "";
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("цена 69");
          lcd.setCursor(0, 1);
          lcd.print(p69);
          lcd.setCursor(7, 1);
          lcd.print("руб.");
          lcd.setCursor(0, 3);
          lcd.print("Е далее    С удалить");
        }
      }
    }
    if (a == 70) {         //   // if (a == 70)
      lcd.setCursor(0, 0);
      lcd.print("цена 70");
      lcd.setCursor(0, 1);
      lcd.print(p70);
      lcd.setCursor(7, 1);
      lcd.print("руб.");
      lcd.setCursor(0, 3);
      lcd.print("Е далее    С удалить");
      customKey = customKeypad.getKey();
      if (isDigit(customKey)) {
        newchar = String(customKey);
        p1text = p1text + newchar;
        p70 = p1text.toInt();
      }
      else {
        if (customKey == 'E') {
          prefs.putUInt("p70", p70);
          p1text = "";
          lcd.clear();
          a ++;
        }
        if (customKey == 'C') {
          p70 = 0;
          p1text = "";
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("цена 70");
          lcd.setCursor(0, 1);
          lcd.print(p70);
          lcd.setCursor(7, 1);
          lcd.print("руб.");
          lcd.setCursor(0, 3);
          lcd.print("Е далее    С удалить");
        }
      }
    }
    if (a == 71) {         //   // if (a == 71)
      lcd.setCursor(0, 0);
      lcd.print("цена 71");
      lcd.setCursor(0, 1);
      lcd.print(p71);
      lcd.setCursor(7, 1);
      lcd.print("руб.");
      lcd.setCursor(0, 3);
      lcd.print("Е далее    С удалить");
      customKey = customKeypad.getKey();
      if (isDigit(customKey)) {
        newchar = String(customKey);
        p1text = p1text + newchar;
        p71 = p1text.toInt();
      }
      else {
        if (customKey == 'E') {
          prefs.putUInt("p71", p71);
          p1text = "";
          lcd.clear();
          a ++;
        }
        if (customKey == 'C') {
          p71 = 0;
          p1text = "";
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("цена 71");
          lcd.setCursor(0, 1);
          lcd.print(p71);
          lcd.setCursor(7, 1);
          lcd.print("руб.");
          lcd.setCursor(0, 3);
          lcd.print("Е далее    С удалить");
        }
      }
    }
    if (a == 72) {         //   // if (a == 72)
      lcd.setCursor(0, 0);
      lcd.print("цена 72");
      lcd.setCursor(0, 1);
      lcd.print(p72);
      lcd.setCursor(7, 1);
      lcd.print("руб.");
      lcd.setCursor(0, 3);
      lcd.print("Е далее    С удалить");
      customKey = customKeypad.getKey();
      if (isDigit(customKey)) {
        newchar = String(customKey);
        p1text = p1text + newchar;
        p72 = p1text.toInt();
      }
      else {
        if (customKey == 'E') {
          prefs.putUInt("p72", p72);
          p1text = "";
          lcd.clear();
          a ++;
        }
        if (customKey == 'C') {
          p72 = 0;
          p1text = "";
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("цена 72");
          lcd.setCursor(0, 1);
          lcd.print(p72);
          lcd.setCursor(7, 1);
          lcd.print("руб.");
          lcd.setCursor(0, 3);
          lcd.print("Е далее    С удалить");
        }
      }
    }
    if (a == 73) {         //   // if (a == 73)
      lcd.setCursor(0, 0);
      lcd.print("цена 73");
      lcd.setCursor(0, 1);
      lcd.print(p73);
      lcd.setCursor(7, 1);
      lcd.print("руб.");
      lcd.setCursor(0, 3);
      lcd.print("Е далее    С удалить");
      customKey = customKeypad.getKey();
      if (isDigit(customKey)) {
        newchar = String(customKey);
        p1text = p1text + newchar;
        p73 = p1text.toInt();
      }
      else {
        if (customKey == 'E') {
          prefs.putUInt("p73", p73);
          p1text = "";
          lcd.clear();
          a ++;
        }
        if (customKey == 'C') {
          p73 = 0;
          p1text = "";
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("цена 73");
          lcd.setCursor(0, 1);
          lcd.print(p73);
          lcd.setCursor(7, 1);
          lcd.print("руб.");
          lcd.setCursor(0, 3);
          lcd.print("Е далее    С удалить");
        }
      }
    }
    if (a == 74) {         //   // if (a == 74)
      lcd.setCursor(0, 0);
      lcd.print("цена 74");
      lcd.setCursor(0, 1);
      lcd.print(p74);
      lcd.setCursor(7, 1);
      lcd.print("руб.");
      lcd.setCursor(0, 3);
      lcd.print("Е далее    С удалить");
      customKey = customKeypad.getKey();
      if (isDigit(customKey)) {
        newchar = String(customKey);
        p1text = p1text + newchar;
        p74 = p1text.toInt();
      }
      else {
        if (customKey == 'E') {
          prefs.putUInt("p74", p74);
          p1text = "";
          lcd.clear();
          a ++;
        }
        if (customKey == 'C') {
          p74 = 0;
          p1text = "";
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("цена 74");
          lcd.setCursor(0, 1);
          lcd.print(p74);
          lcd.setCursor(7, 1);
          lcd.print("руб.");
          lcd.setCursor(0, 3);
          lcd.print("Е далее    С удалить");
        }
      }
    }
    if (a == 75) {         //   // if (a == 75)
      lcd.setCursor(0, 0);
      lcd.print("цена 75");
      lcd.setCursor(0, 1);
      lcd.print(p75);
      lcd.setCursor(7, 1);
      lcd.print("руб.");
      lcd.setCursor(0, 3);
      lcd.print("Е далее    С удалить");
      customKey = customKeypad.getKey();
      if (isDigit(customKey)) {
        newchar = String(customKey);
        p1text = p1text + newchar;
        p75 = p1text.toInt();
      }
      else {
        if (customKey == 'E') {
          prefs.putUInt("p75", p75);
          p1text = "";
          lcd.clear();
          a ++;
        }
        if (customKey == 'C') {
          p75 = 0;
          p1text = "";
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("цена 75");
          lcd.setCursor(0, 1);
          lcd.print(p75);
          lcd.setCursor(7, 1);
          lcd.print("руб.");
          lcd.setCursor(0, 3);
          lcd.print("Е далее    С удалить");
        }
      }
    }
    if (a == 76) {         //   // if (a == 76)
      lcd.setCursor(0, 0);
      lcd.print("цена 76");
      lcd.setCursor(0, 1);
      lcd.print(p76);
      lcd.setCursor(7, 1);
      lcd.print("руб.");
      lcd.setCursor(0, 3);
      lcd.print("Е далее    С удалить");
      customKey = customKeypad.getKey();
      if (isDigit(customKey)) {
        newchar = String(customKey);
        p1text = p1text + newchar;
        p76 = p1text.toInt();
      }
      else {
        if (customKey == 'E') {
          prefs.putUInt("p76", p76);
          p1text = "";
          lcd.clear();
          a ++;
        }
        if (customKey == 'C') {
          p76 = 0;
          p1text = "";
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("цена 76");
          lcd.setCursor(0, 1);
          lcd.print(p76);
          lcd.setCursor(7, 1);
          lcd.print("руб.");
          lcd.setCursor(0, 3);
          lcd.print("Е далее    С удалить");
        }
      }
    }
    if (a == 77) {         //   // if (a == 77)
      lcd.setCursor(0, 0);
      lcd.print("цена 77");
      lcd.setCursor(0, 1);
      lcd.print(p77);
      lcd.setCursor(7, 1);
      lcd.print("руб.");
      lcd.setCursor(0, 3);
      lcd.print("Е далее    С удалить");
      customKey = customKeypad.getKey();
      if (isDigit(customKey)) {
        newchar = String(customKey);
        p1text = p1text + newchar;
        p77 = p1text.toInt();
      }
      else {
        if (customKey == 'E') {
          prefs.putUInt("p77", p77);
          p1text = "";
          lcd.clear();
          a ++;
        }
        if (customKey == 'C') {
          p77 = 0;
          p1text = "";
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("цена 77");
          lcd.setCursor(0, 1);
          lcd.print(p77);
          lcd.setCursor(7, 1);
          lcd.print("руб.");
          lcd.setCursor(0, 3);
          lcd.print("Е далее    С удалить");
        }
      }
    }
    if (a == 78) {         //   // if (a == 78)
      lcd.setCursor(0, 0);
      lcd.print("цена 78");
      lcd.setCursor(0, 1);
      lcd.print(p78);
      lcd.setCursor(7, 1);
      lcd.print("руб.");
      lcd.setCursor(0, 3);
      lcd.print("Е далее    С удалить");
      customKey = customKeypad.getKey();
      if (isDigit(customKey)) {
        newchar = String(customKey);
        p1text = p1text + newchar;
        p78 = p1text.toInt();
      }
      else {
        if (customKey == 'E') {
          prefs.putUInt("p78", p78);
          p1text = "";
          lcd.clear();
          a ++;
        }
        if (customKey == 'C') {
          p78 = 0;
          p1text = "";
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("цена 78");
          lcd.setCursor(0, 1);
          lcd.print(p78);
          lcd.setCursor(7, 1);
          lcd.print("руб.");
          lcd.setCursor(0, 3);
          lcd.print("Е далее    С удалить");
        }
      }
    }
    if (a == 79) {         //   // if (a == 79)
      lcd.setCursor(0, 0);
      lcd.print("цена 79");
      lcd.setCursor(0, 1);
      lcd.print(p79);
      lcd.setCursor(7, 1);
      lcd.print("руб.");
      lcd.setCursor(0, 3);
      lcd.print("Е далее    С удалить");
      customKey = customKeypad.getKey();
      if (isDigit(customKey)) {
        newchar = String(customKey);
        p1text = p1text + newchar;
        p79 = p1text.toInt();
      }
      else {
        if (customKey == 'E') {
          prefs.putUInt("p79", p79);
          p1text = "";
          lcd.clear();
          a ++;
        }
        if (customKey == 'C') {
          p79 = 0;
          p1text = "";
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("цена 79");
          lcd.setCursor(0, 1);
          lcd.print(p79);
          lcd.setCursor(7, 1);
          lcd.print("руб.");
          lcd.setCursor(0, 3);
          lcd.print("Е далее    С удалить");
        }
      }
    }
    if (a == 80) {         //   // if (a == 80)
      lcd.setCursor(0, 0);
      lcd.print("цена 80");
      lcd.setCursor(0, 1);
      lcd.print(p80);
      lcd.setCursor(7, 1);
      lcd.print("руб.");
      lcd.setCursor(0, 3);
      lcd.print("Е далее    С удалить");
      customKey = customKeypad.getKey();
      if (isDigit(customKey)) {
        newchar = String(customKey);
        p1text = p1text + newchar;
        p80 = p1text.toInt();
      }
      else {
        if (customKey == 'E') {
          prefs.putUInt("p80", p80);
          p1text = "";
          lcd.clear();
          a ++;
        }
        if (customKey == 'C') {
          p80 = 0;
          p1text = "";
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("цена 80");
          lcd.setCursor(0, 1);
          lcd.print(p80);
          lcd.setCursor(7, 1);
          lcd.print("руб.");
          lcd.setCursor(0, 3);
          lcd.print("Е далее    С удалить");
        }
      }
    }
    if (a == 81) {         //   // if (a == 81)
      lcd.setCursor(0, 0);
      lcd.print("цена 81");
      lcd.setCursor(0, 1);
      lcd.print(p81);
      lcd.setCursor(7, 1);
      lcd.print("руб.");
      lcd.setCursor(0, 3);
      lcd.print("Е далее    С удалить");
      customKey = customKeypad.getKey();
      if (isDigit(customKey)) {
        newchar = String(customKey);
        p1text = p1text + newchar;
        p81 = p1text.toInt();
      }
      else {
        if (customKey == 'E') {
          prefs.putUInt("p81", p81);
          p1text = "";
          lcd.clear();
          a ++;
        }
        if (customKey == 'C') {
          p81 = 0;
          p1text = "";
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("цена 81");
          lcd.setCursor(0, 1);
          lcd.print(p81);
          lcd.setCursor(7, 1);
          lcd.print("руб.");
          lcd.setCursor(0, 3);
          lcd.print("Е далее    С удалить");
        }
      }
    }
    if (a == 82) {         //   // if (a == 82)
      lcd.setCursor(0, 0);
      lcd.print("цена 82");
      lcd.setCursor(0, 1);
      lcd.print(p82);
      lcd.setCursor(7, 1);
      lcd.print("руб.");
      lcd.setCursor(0, 3);
      lcd.print("Е далее    С удалить");
      customKey = customKeypad.getKey();
      if (isDigit(customKey)) {
        newchar = String(customKey);
        p1text = p1text + newchar;
        p82 = p1text.toInt();
      }
      else {
        if (customKey == 'E') {
          prefs.putUInt("p82", p82);
          p1text = "";
          lcd.clear();
          a ++;
        }
        if (customKey == 'C') {
          p82 = 0;
          p1text = "";
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("цена 82");
          lcd.setCursor(0, 1);
          lcd.print(p82);
          lcd.setCursor(7, 1);
          lcd.print("руб.");
          lcd.setCursor(0, 3);
          lcd.print("Е далее    С удалить");
        }
      }
    }
    if (a == 83) {         //   // if (a == 83)
      lcd.setCursor(0, 0);
      lcd.print("цена 83");
      lcd.setCursor(0, 1);
      lcd.print(p83);
      lcd.setCursor(7, 1);
      lcd.print("руб.");
      lcd.setCursor(0, 3);
      lcd.print("Е далее    С удалить");
      customKey = customKeypad.getKey();
      if (isDigit(customKey)) {
        newchar = String(customKey);
        p1text = p1text + newchar;
        p83 = p1text.toInt();
      }
      else {
        if (customKey == 'E') {
          prefs.putUInt("p83", p83);
          p1text = "";
          lcd.clear();
          a ++;
        }
        if (customKey == 'C') {
          p83 = 0;
          p1text = "";
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("цена 83");
          lcd.setCursor(0, 1);
          lcd.print(p83);
          lcd.setCursor(7, 1);
          lcd.print("руб.");
          lcd.setCursor(0, 3);
          lcd.print("Е далее    С удалить");
        }
      }
    }
    if (a == 84) {         //   // if (a == 84)
      lcd.setCursor(0, 0);
      lcd.print("цена 84");
      lcd.setCursor(0, 1);
      lcd.print(p84);
      lcd.setCursor(7, 1);
      lcd.print("руб.");
      lcd.setCursor(0, 3);
      lcd.print("Е далее    С удалить");
      customKey = customKeypad.getKey();
      if (isDigit(customKey)) {
        newchar = String(customKey);
        p1text = p1text + newchar;
        p84 = p1text.toInt();
      }
      else {
        if (customKey == 'E') {
          prefs.putUInt("p84", p84);
          p1text = "";
          lcd.clear();
          a ++;
        }
        if (customKey == 'C') {
          p84 = 0;
          p1text = "";
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("цена 84");
          lcd.setCursor(0, 1);
          lcd.print(p84);
          lcd.setCursor(7, 1);
          lcd.print("руб.");
          lcd.setCursor(0, 3);
          lcd.print("Е далее    С удалить");
        }
      }
    }
    if (a == 85) {         //   // if (a == 85)
      lcd.setCursor(0, 0);
      lcd.print("цена 85");
      lcd.setCursor(0, 1);
      lcd.print(p85);
      lcd.setCursor(7, 1);
      lcd.print("руб.");
      lcd.setCursor(0, 3);
      lcd.print("Е далее    С удалить");
      customKey = customKeypad.getKey();
      if (isDigit(customKey)) {
        newchar = String(customKey);
        p1text = p1text + newchar;
        p85 = p1text.toInt();
      }
      else {
        if (customKey == 'E') {
          prefs.putUInt("p85", p85);
          p1text = "";
          lcd.clear();
          a ++;
        }
        if (customKey == 'C') {
          p85 = 0;
          p1text = "";
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("цена 85");
          lcd.setCursor(0, 1);
          lcd.print(p85);
          lcd.setCursor(7, 1);
          lcd.print("руб.");
          lcd.setCursor(0, 3);
          lcd.print("Е далее    С удалить");
        }
      }
    }
    if (a == 86) {         //   // if (a == 86)
      lcd.setCursor(0, 0);
      lcd.print("цена 86");
      lcd.setCursor(0, 1);
      lcd.print(p86);
      lcd.setCursor(7, 1);
      lcd.print("руб.");
      lcd.setCursor(0, 3);
      lcd.print("Е далее    С удалить");
      customKey = customKeypad.getKey();
      if (isDigit(customKey)) {
        newchar = String(customKey);
        p1text = p1text + newchar;
        p85 = p1text.toInt();
      }
      else {
        if (customKey == 'E') {
          prefs.putUInt("p86", p86);
          p1text = "";
          lcd.clear();
          a ++;
        }
        if (customKey == 'C') {
          p86 = 0;
          p1text = "";
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("цена 86");
          lcd.setCursor(0, 1);
          lcd.print(p86);
          lcd.setCursor(7, 1);
          lcd.print("руб.");
          lcd.setCursor(0, 3);
          lcd.print("Е далее    С удалить");
        }
      }
    }
    if (a == 87) {         //   // if (a == 87)
      lcd.setCursor(0, 0);
      lcd.print("цена 87");
      lcd.setCursor(0, 1);
      lcd.print(p87);
      lcd.setCursor(7, 1);
      lcd.print("руб.");
      lcd.setCursor(0, 3);
      lcd.print("Е далее    С удалить");
      customKey = customKeypad.getKey();
      if (isDigit(customKey)) {
        newchar = String(customKey);
        p1text = p1text + newchar;
        p87 = p1text.toInt();
      }
      else {
        if (customKey == 'E') {
          prefs.putUInt("p87", p87);
          p1text = "";
          lcd.clear();
          a ++;
        }
        if (customKey == 'C') {
          p87 = 0;
          p1text = "";
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("цена 87");
          lcd.setCursor(0, 1);
          lcd.print(p87);
          lcd.setCursor(7, 1);
          lcd.print("руб.");
          lcd.setCursor(0, 3);
          lcd.print("Е далее    С удалить");
        }
      }
    }
    if (a == 88) {         //   // if (a == 88)
      lcd.setCursor(0, 0);
      lcd.print("цена 88");
      lcd.setCursor(0, 1);
      lcd.print(p88);
      lcd.setCursor(7, 1);
      lcd.print("руб.");
      lcd.setCursor(0, 3);
      lcd.print("Е далее    С удалить");
      customKey = customKeypad.getKey();
      if (isDigit(customKey)) {
        newchar = String(customKey);
        p1text = p1text + newchar;
        p88 = p1text.toInt();
      }
      else {
        if (customKey == 'E') {
          prefs.putUInt("p88", p88);
          p1text = "";
          lcd.clear();
          a ++;
        }
        if (customKey == 'C') {
          p88 = 0;
          p1text = "";
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("цена 88");
          lcd.setCursor(0, 1);
          lcd.print(p88);
          lcd.setCursor(7, 1);
          lcd.print("руб.");
          lcd.setCursor(0, 3);
          lcd.print("Е далее    С удалить");
        }
      }
    }
    if (a == 89) {         //   // if (a == 89)
      lcd.setCursor(0, 0);
      lcd.print("цена 89");
      lcd.setCursor(0, 1);
      lcd.print(p89);
      lcd.setCursor(7, 1);
      lcd.print("руб.");
      lcd.setCursor(0, 3);
      lcd.print("Е далее    С удалить");
      customKey = customKeypad.getKey();
      if (isDigit(customKey)) {
        newchar = String(customKey);
        p1text = p1text + newchar;
        p89 = p1text.toInt();
      }
      else {
        if (customKey == 'E') {
          prefs.putUInt("p89", p89);
          p1text = "";
          lcd.clear();
          a ++;
        }
        if (customKey == 'C') {
          p89 = 0;
          p1text = "";
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("цена 89");
          lcd.setCursor(0, 1);
          lcd.print(p89);
          lcd.setCursor(7, 1);
          lcd.print("руб.");
          lcd.setCursor(0, 3);
          lcd.print("Е далее    С удалить");
        }
      }
    }
    if (a == 90) {         //   // if (a == 90)
      lcd.setCursor(0, 0);
      lcd.print("цена 90");
      lcd.setCursor(0, 1);
      lcd.print(p90);
      lcd.setCursor(7, 1);
      lcd.print("руб.");
      lcd.setCursor(0, 3);
      lcd.print("Е далее    С удалить");
      customKey = customKeypad.getKey();
      if (isDigit(customKey)) {
        newchar = String(customKey);
        p1text = p1text + newchar;
        p90 = p1text.toInt();
      }
      else {
        if (customKey == 'E') {
          prefs.putUInt("p90", p90);
          p1text = "";
          lcd.clear();
          a ++;
        }
        if (customKey == 'C') {
          p90 = 0;
          p1text = "";
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("цена 90");
          lcd.setCursor(0, 1);
          lcd.print(p90);
          lcd.setCursor(7, 1);
          lcd.print("руб.");
          lcd.setCursor(0, 3);
          lcd.print("Е далее    С удалить");
        }
      }
    }
    if (a == 91) {         //   // if (a == 91)
      lcd.setCursor(0, 0);
      lcd.print("цена 91");
      lcd.setCursor(0, 1);
      lcd.print(p91);
      lcd.setCursor(7, 1);
      lcd.print("руб.");
      lcd.setCursor(0, 3);
      lcd.print("Е далее    С удалить");
      customKey = customKeypad.getKey();
      if (isDigit(customKey)) {
        newchar = String(customKey);
        p1text = p1text + newchar;
        p91 = p1text.toInt();
      }
      else {
        if (customKey == 'E') {
          prefs.putUInt("p91", p91);
          p1text = "";
          lcd.clear();
          a ++;
        }
        if (customKey == 'C') {
          p91 = 0;
          p1text = "";
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("цена 91");
          lcd.setCursor(0, 1);
          lcd.print(p91);
          lcd.setCursor(7, 1);
          lcd.print("руб.");
          lcd.setCursor(0, 3);
          lcd.print("Е далее    С удалить");
        }
      }
    }
    if (a == 92) {         //   // if (a == 90)
      lcd.setCursor(0, 0);
      lcd.print("цена 92");
      lcd.setCursor(0, 1);
      lcd.print(p92);
      lcd.setCursor(7, 1);
      lcd.print("руб.");
      lcd.setCursor(0, 3);
      lcd.print("Е далее    С удалить");
      customKey = customKeypad.getKey();
      if (isDigit(customKey)) {
        newchar = String(customKey);
        p1text = p1text + newchar;
        p92 = p1text.toInt();
      }
      else {
        if (customKey == 'E') {
          prefs.putUInt("p92", p92);
          p1text = "";
          lcd.clear();
          a ++;
        }
        if (customKey == 'C') {
          p92 = 0;
          p1text = "";
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("цена 92");
          lcd.setCursor(0, 1);
          lcd.print(p92);
          lcd.setCursor(7, 1);
          lcd.print("руб.");
          lcd.setCursor(0, 3);
          lcd.print("Е далее    С удалить");
        }
      }
    }
    if (a == 93) {         //   // if (a == 93)
      lcd.setCursor(0, 0);
      lcd.print("цена 93");
      lcd.setCursor(0, 1);
      lcd.print(p93);
      lcd.setCursor(7, 1);
      lcd.print("руб.");
      lcd.setCursor(0, 3);
      lcd.print("Е далее    С удалить");
      customKey = customKeypad.getKey();
      if (isDigit(customKey)) {
        newchar = String(customKey);
        p1text = p1text + newchar;
        p93 = p1text.toInt();
      }
      else {
        if (customKey == 'E') {
          prefs.putUInt("p93", p93);
          p1text = "";
          lcd.clear();
          a ++;
        }
        if (customKey == 'C') {
          p93 = 0;
          p1text = "";
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("цена 93");
          lcd.setCursor(0, 1);
          lcd.print(p93);
          lcd.setCursor(7, 1);
          lcd.print("руб.");
          lcd.setCursor(0, 3);
          lcd.print("Е далее    С удалить");
        }
      }
    }
    if (a == 94) {         //   // if (a == 94)
      lcd.setCursor(0, 0);
      lcd.print("цена 94");
      lcd.setCursor(0, 1);
      lcd.print(p94);
      lcd.setCursor(7, 1);
      lcd.print("руб.");
      lcd.setCursor(0, 3);
      lcd.print("Е далее    С удалить");
      customKey = customKeypad.getKey();
      if (isDigit(customKey)) {
        newchar = String(customKey);
        p1text = p1text + newchar;
        p94 = p1text.toInt();
      }
      else {
        if (customKey == 'E') {
          prefs.putUInt("p94", p94);
          p1text = "";
          lcd.clear();
          a ++;
        }
        if (customKey == 'C') {
          p94 = 0;
          p1text = "";
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("цена 94");
          lcd.setCursor(0, 1);
          lcd.print(p94);
          lcd.setCursor(7, 1);
          lcd.print("руб.");
          lcd.setCursor(0, 3);
          lcd.print("Е далее    С удалить");
        }
      }
    }
    if (a == 95) {         //   // if (a == 95)
      lcd.setCursor(0, 0);
      lcd.print("цена 95");
      lcd.setCursor(0, 1);
      lcd.print(p95);
      lcd.setCursor(7, 1);
      lcd.print("руб.");
      lcd.setCursor(0, 3);
      lcd.print("Е далее    С удалить");
      customKey = customKeypad.getKey();
      if (isDigit(customKey)) {
        newchar = String(customKey);
        p1text = p1text + newchar;
        p95 = p1text.toInt();
      }
      else {
        if (customKey == 'E') {
          prefs.putUInt("p95", p95);
          p1text = "";
          lcd.clear();
          a ++;
        }
        if (customKey == 'C') {
          p95 = 0;
          p1text = "";
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("цена 95");
          lcd.setCursor(0, 1);
          lcd.print(p95);
          lcd.setCursor(7, 1);
          lcd.print("руб.");
          lcd.setCursor(0, 3);
          lcd.print("Е далее    С удалить");
        }
      }
    }
    if (a == 96) {         //   // if (a == 96)
      lcd.setCursor(0, 0);
      lcd.print("цена 96");
      lcd.setCursor(0, 1);
      lcd.print(p96);
      lcd.setCursor(7, 1);
      lcd.print("руб.");
      lcd.setCursor(0, 3);
      lcd.print("Е далее    С удалить");
      customKey = customKeypad.getKey();
      if (isDigit(customKey)) {
        newchar = String(customKey);
        p1text = p1text + newchar;
        p96 = p1text.toInt();
      }
      else {
        if (customKey == 'E') {
          prefs.putUInt("p96", p96);
          p1text = "";
          lcd.clear();
          a ++;
        }
        if (customKey == 'C') {
          p96 = 0;
          p1text = "";
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("цена 96");
          lcd.setCursor(0, 1);
          lcd.print(p96);
          lcd.setCursor(7, 1);
          lcd.print("руб.");
          lcd.setCursor(0, 3);
          lcd.print("Е далее    С удалить");
        }
      }
    }
    if (a == 97) {         //   // if (a == 97)
      lcd.setCursor(0, 0);
      lcd.print("цена 97");
      lcd.setCursor(0, 1);
      lcd.print(p97);
      lcd.setCursor(7, 1);
      lcd.print("руб.");
      lcd.setCursor(0, 3);
      lcd.print("Е далее    С удалить");
      customKey = customKeypad.getKey();
      if (isDigit(customKey)) {
        newchar = String(customKey);
        p1text = p1text + newchar;
        p97 = p1text.toInt();
      }
      else {
        if (customKey == 'E') {
          prefs.putUInt("p97", p97);
          p1text = "";
          lcd.clear();
          a ++;
        }
        if (customKey == 'C') {
          p97 = 0;
          p1text = "";
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("цена 97");
          lcd.setCursor(0, 1);
          lcd.print(p97);
          lcd.setCursor(7, 1);
          lcd.print("руб.");
          lcd.setCursor(0, 3);
          lcd.print("Е далее    С удалить");
        }
      }
    }
    if (a == 98) {         //   // if (a == 98)
      lcd.setCursor(0, 0);
      lcd.print("цена 98");
      lcd.setCursor(0, 1);
      lcd.print(p98);
      lcd.setCursor(7, 1);
      lcd.print("руб.");
      lcd.setCursor(0, 3);
      lcd.print("Е далее    С удалить");
      customKey = customKeypad.getKey();
      if (isDigit(customKey)) {
        newchar = String(customKey);
        p1text = p1text + newchar;
        p98 = p1text.toInt();
      }
      else {
        if (customKey == 'E') {
          prefs.putUInt("p98", p98);
          p1text = "";
          lcd.clear();
          a ++;
        }
        if (customKey == 'C') {
          p98 = 0;
          p1text = "";
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("цена 98");
          lcd.setCursor(0, 1);
          lcd.print(p98);
          lcd.setCursor(7, 1);
          lcd.print("руб.");
          lcd.setCursor(0, 3);
          lcd.print("Е далее    С удалить");
        }
      }
    }
    if (a == 99) {         //   // if (a == 99)
      lcd.setCursor(0, 0);
      lcd.print("цена 99");
      lcd.setCursor(0, 1);
      lcd.print(p99);
      lcd.setCursor(7, 1);
      lcd.print("руб.");
      lcd.setCursor(0, 3);
      lcd.print("Е далее    С удалить");
      customKey = customKeypad.getKey();
      if (isDigit(customKey)) {
        newchar = String(customKey);
        p1text = p1text + newchar;
        p99 = p1text.toInt();
      }
      else {
        if (customKey == 'E') {
          prefs.putUInt("p99", p99);
          p1text = "";
          lcd.clear();
          a ++;
        }
        if (customKey == 'C') {
          p99 = 0;
          p1text = "";
          lcd.clear();
          lcd.setCursor(0, 0);
          lcd.print("цена 99");
          lcd.setCursor(0, 1);
          lcd.print(p99);
          lcd.setCursor(7, 1);
          lcd.print("руб.");
          lcd.setCursor(0, 3);
          lcd.print("Е далее    С удалить");
        }
      }
    }


  }  // if prog == true
  if (price1 > 0) {
    intVar = price1;
    cost100 = intVar / 100 % 10;
    if (cost100 == 0) {
      data1[22] = 0x30;
    }
    if (cost100 == 1) {
      data1[22] = 0x31;
    }
    if (cost100 == 2) {
      data1[22] = 0x32;
    }
    if (cost100 == 3) {
      data1[22] = 0x33;
    }
    if (cost100 == 4) {
      data1[22] = 0x34;
    }
    if (cost100 == 5) {
      data1[22] = 0x35;
    }
    if (cost100 == 6) {
      data1[22] = 0x36;
    }
    if (cost100 == 7) {
      data1[22] = 0x37;
    }
    if (cost100 == 8) {
      data1[22] = 0x38;
    }
    if (cost100 == 9) {
      data1[22] = 0x39;
    }
    cost10 = intVar / 10 % 10;
    if (cost10 == 0) {
      data1[23] = 0x30;
    }
    if (cost10 == 1) {
      data1[23] = 0x31;
    }
    if (cost10 == 2) {
      data1[23] = 0x32;
    }
    if (cost10 == 3) {
      data1[23] = 0x33;
    }
    if (cost10 == 4) {
      data1[23] = 0x34;
    }
    if (cost10 == 5) {
      data1[23] = 0x35;
    }
    if (cost10 == 6) {
      data1[23] = 0x36;
    }
    if (cost10 == 7) {
      data1[23] = 0x37;
    }
    if (cost10 == 8) {
      data1[23] = 0x38;
    }
    if (cost10 == 9) {
      data1[23] = 0x39;
    }
    cost1 = intVar % 10 % 10;
    if (cost1 == 0) {
      data1[24] = 0x30;
    }
    if (cost1 == 1) {
      data1[24] = 0x31;
    }
    if (cost1 == 2) {
      data1[24] = 0x32;
    }
    if (cost1 == 3) {
      data1[24] = 0x33;
    }
    if (cost1 == 4) {
      data1[24] = 0x34;
    }
    if (cost1 == 5) {
      data1[24] = 0x35;
    }
    if (cost1 == 6) {
      data1[24] = 0x36;
    }
    if (cost1 == 7) {
      data1[24] = 0x37;
    }
    if (cost1 == 8) {
      data1[24] = 0x38;
    }
    if (cost1 == 9) {
      data1[24] = 0x39;
    }
    price1 = 0;
    intVar = 0;
    paystat = 1;
  }
  if (paystat == 1) {
    Pay.setTimeout(paytime);
    lcd.clear();                           ////////////////////////   начальный экран
    lcd.setCursor(2, 1);
    lcd.print("Ожидание оплаты");
    //paystat =2;
    //////////////////////     начальный экран

    //for ( i = 0; i < 3 ; i++ ){data1[22+i]=Serial.read();} //читаем сумму для оплаты
    //for ( i = 0; i < 8 ; i++ ){data1[12+i]=0x30;}// Обнуляем номер документа
    //for ( i = 0; i < c1 ; i++ ){data[i]=Serial.read();} //обнуляем порт

    //for ( i = 0; i < 5 ; i++ ){Serial.write (data[i]);}//Посылаем на контроллер готовность прнять данные

    ZND();//запрос номера текущего документа у терминала
    //Serial1.write(data5, sizeof(data5));
    // c1=Serial1.available();
    //  for ( i = 0; i < c1 ; i++ ){data[i]=Serial1.read();} //читаем ответ терминала
  }
}

void ZND () { //1F 00 0A 96 FB 01 03 49 44 4C 03 01 30 B6 49

z1:
  Serial1.write(data5, sizeof(data5));//Посылаем запрос IDL на терминал
  // Serial.println("----------");

  delay(500);
  if (Serial1.available() == 0) {
    goto z1;
  }
  l = Serial1.available();
  for ( i = 0; i < l ; i++ ) {
    data[i] = Serial1.read();
    //Serial.write(data[i]);} //читаем ответ терминала
  }

  for ( i = 0; i < data[11] ; i++ ) {
    n[i] = data[12 + i]; //вычисляем номер текущего документа в терминале
  }
  if (data[11] == 0x01) {
    if (n[0] == 0x39)                                                                                           {
      data1[19] = 0x30;
      data1[18] = 0x31;
    }                                                                                           else {
      data1[19] = (n[0] + 0x01);
      if (data1[19] == 0x3A) {
        data1[19] = 0x30;
        data1[18] = n[0] + 0x01;
      }
    }
  }
  if (data[11] == 0x02) {
    if (n[0] == 0x39 & n[1] == 0x39)                                                                              {
      data1[19] = 0x30;
      data1[18] = 0x30;
      data1[17] = 0x31;
    }                                                                            else {
      data1[19] = (n[1] + 0x01);
      data1[18] = n[0];
      if (data1[19] == 0x3A) {
        data1[19] = 0x30;
        data1[18] = n[0] + 0x01;
      }                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       else {
        data1[18] = n[0];
      }
    }
  }
  if (data[11] == 0x03) {
    if (n[0] == 0x39 & n[1] == 0x39 & n[2] == 0x39)                                                                 {
      data1[19] = 0x30;
      data1[18] = 0x30;
      data1[17] = 0x30;
      data1[16] = 0x31;
    }                                                             else {
      data1[19] = (n[2] + 0x01);
      data1[18] = n[1];
      data1[17] = n[0];
      if (data1[19] == 0x3A) {
        data1[19] = 0x30;
        data1[18] = n[1] + 0x01;
        data1[17] = n[0];
        if (data1[18] == 0x3A) {
          data1[18] = 0x30;
          data1[17] = n[0] + 0x01;
        }                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     else {
          data1[17] = n[0];
        }
      }
    }
  }
  if (data[11] == 0x04) {
    if (n[0] == 0x39 & n[1] == 0x39 & n[2] == 0x39 & n[3] == 0x39)                                                    {
      data1[19] = 0x30;
      data1[18] = 0x30;
      data1[17] = 0x30;
      data1[16] = 0x30;
      data1[15] = 0x31;
    }                                              else {
      data1[19] = (n[3] + 0x01);
      data1[18] = n[2];
      data1[17] = n[1];
      data1[16] = n[0];
      if (data1[19] == 0x3A) {
        data1[19] = 0x30;
        data1[18] = n[2] + 0x01;
        data1[17] = n[1];
        data1[16] = n[0];
        if (data1[18] == 0x3A) {
          data1[18] = 0x30;
          data1[17] = n[1] + 0x01;
          data1[16] = n[0];
          if (data1[17] == 0x3A) {
            data1[17] = 0x30;
            data1[16] = n[0] + 0x01;
          }                                                                                                                                                                                                                                                                                                                                                                                                else {
            data1[16] = n[0];
          }
        }
      }
    }
  }
  if (data[11] == 0x05) {
    if (n[0] == 0x39 & n[1] == 0x39 & n[2] == 0x39 & n[3] == 0x39 & n[4] == 0x39)                                       {
      data1[19] = 0x30;
      data1[18] = 0x30;
      data1[17] = 0x30;
      data1[16] = 0x30;
      data1[15] = 0x30;
      data1[14] = 0x31;
    }                               else {
      data1[19] = (n[4] + 0x01);
      data1[18] = n[3];
      data1[17] = n[2];
      data1[16] = n[1];
      data1[15] = n[0];
      if (data1[19] == 0x3A) {
        data1[19] = 0x30;
        data1[18] = n[3] + 0x01;
        data1[17] = n[2];
        data1[16] = n[1];
        data1[15] = n[0];
        if (data1[18] == 0x3A) {
          data1[18] = 0x30;
          data1[17] = n[2] + 0x01;
          data1[16] = n[1];
          data1[15] = n[0];
          if (data1[17] == 0x3A) {
            data1[17] = 0x30;
            data1[16] = n[1] + 0x01;
            data1[15] = n[0];
            if (data1[16] == 0x3A) {
              data1[16] = 0x30;
              data1[15] = n[0] + 0x01;
            }                                                                                                                                                                                                                                                                           else {
              data1[15] = n[0];
            }
          }
        }
      }
    }
  }
  if (data[11] == 0x06) {
    if (n[0] == 0x39 & n[1] == 0x39 & n[2] == 0x39 & n[3] == 0x39 & n[4] == 0x39 & n[5] == 0x39)                          {
      data1[19] = 0x30;
      data1[18] = 0x30;
      data1[17] = 0x30;
      data1[16] = 0x30;
      data1[15] = 0x30;
      data1[14] = 0x30;
      data1[13] = 0x31;
    }                else {
      data1[19] = (n[5] + 0x01);
      data1[18] = n[4];
      data1[17] = n[3];
      data1[16] = n[2];
      data1[15] = n[1];
      data1[14] = n[0];
      if (data1[19] == 0x3A) {
        data1[19] = 0x30;
        data1[18] = n[4] + 0x01;
        data1[17] = n[3];
        data1[16] = n[2];
        data1[15] = n[1];
        data1[14] = n[0];
        if (data1[18] == 0x3A) {
          data1[18] = 0x30;
          data1[17] = n[3] + 0x01;
          data1[16] = n[2];
          data1[15] = n[1];
          data1[14] = n[0];
          if (data1[17] == 0x3A) {
            data1[17] = 0x30;
            data1[16] = n[2] + 0x01;
            data1[15] = n[1];
            data1[14] = n[0];
            if (data1[16] == 0x3A) {
              data1[16] = 0x30;
              data1[15] = n[1] + 0x01;
              data1[14] = n[0];
              if (data1[15] == 0x3A) {
                data1[15] = 0x30;
                data1[14] = n[0] + 0x01;
              }                                                                                                                                                                   else {
                data1[14] = n[0];
              }
            }
          }
        }
      }
    }
  }
  if (data[11] == 0x07) {
    if (n[0] == 0x39 & n[1] == 0x39 & n[2] == 0x39 & n[3] == 0x39 & n[4] == 0x39 & n[5] == 0x39 & n[6] == 0x39)             {
      data1[19] = 0x30;
      data1[18] = 0x30;
      data1[17] = 0x30;
      data1[16] = 0x30;
      data1[15] = 0x30;
      data1[14] = 0x30;
      data1[13] = 0x30;
      data1[12] = 0x31;
    } else {
      data1[19] = (n[6] + 0x01);
      data1[18] = n[5];
      data1[17] = n[4];
      data1[16] = n[3];
      data1[15] = n[2];
      data1[14] = n[1];
      data1[13] = n[0];
      if (data1[19] == 0x3A) {
        data1[19] = 0x30;
        data1[18] = n[5] + 0x01;
        data1[17] = n[4];
        data1[16] = n[3];
        data1[15] = n[2];
        data1[14] = n[1];
        data1[13] = n[0];
        if (data1[18] == 0x3A) {
          data1[18] = 0x30;
          data1[17] = n[4] + 0x01;
          data1[16] = n[3];
          data1[15] = n[2];
          data1[14] = n[1];
          data1[13] = n[0];
          if (data1[17] == 0x3A) {
            data1[17] = 0x30;
            data1[16] = n[3] + 0x01;
            data1[15] = n[2];
            data1[14] = n[1];
            data1[13] = n[0];
            if (data1[16] == 0x3A) {
              data1[16] = 0x30;
              data1[15] = n[2] + 0x01;
              data1[14] = n[1];
              data1[13] = n[0];
              if (data1[15] == 0x3A) {
                data1[15] = 0x30;
                data1[14] = n[1] + 0x01;
                data1[13] = n[0];
                if (data1[14] == 0x3A) {
                  data1[14] = 0x30;
                  data1[13] = n[0] + 0x01;
                }                                                                            else {
                  data1[13] = n[0];
                }
              }
            }
          }
        }
      }
    }
  }
  if (data[11] == 0x08) {
    if (n[0] == 0x39 & n[1] == 0x39 & n[2] == 0x39 & n[3] == 0x39 & n[4] == 0x39 & n[5] == 0x39 & n[6] == 0x39 & n[7] == 0x39) {
      data1[19] = n[7];
      data1[18] = n[6];
      data1[17] = n[5];
      data1[16] = n[4];
      data1[15] = n[3];
      data1[14] = n[2];
      data1[13] = n[1];
      data1[12] = n[0];
    } else {
      data1[19] = (n[7] + 0x01);
      data1[18] = n[6];
      data1[17] = n[5];
      data1[16] = n[4];
      data1[15] = n[3];
      data1[14] = n[2];
      data1[13] = n[1];
      data1[12] = n[0];
      if (data1[19] == 0x3A) {
        data1[19] = 0x30;
        data1[18] = n[6] + 0x01;
        data1[17] = n[5];
        data1[16] = n[4];
        data1[15] = n[3];
        data1[14] = n[2];
        data1[13] = n[1];
        data1[12] = n[0];
        if (data1[18] == 0x3A) {
          data1[18] = 0x30;
          data1[17] = n[5] + 0x01;
          data1[16] = n[4];
          data1[15] = n[3];
          data1[14] = n[2];
          data1[13] = n[1];
          data1[12] = n[0];
          if (data1[17] == 0x3A) {
            data1[17] = 0x30;
            data1[16] = n[4] + 0x01;
            data1[15] = n[3];
            data1[14] = n[2];
            data1[13] = n[1];
            data1[12] = n[0];
            if (data1[16] == 0x3A) {
              data1[16] = 0x30;
              data1[15] = n[3] + 0x01;
              data1[14] = n[2];
              data1[13] = n[1];
              data1[12] = n[0];
              if (data1[15] == 0x3A) {
                data1[15] = 0x30;
                data1[14] = n[2] + 0x01;
                data1[13] = n[1];
                data1[12] = n[0];
                if (data1[14] == 0x3A) {
                  data1[14] = 0x30;
                  data1[13] = n[1] + 0x01;
                  data1[12] = n[0];
                  if (data1[13] == 0x3A) {
                    data1[13] = 0x30;
                    data1[12] = n[0] + 0x01;
                  }    else {
                    data1[12] = n[0];
                  }
                }
              }
            }
          }
        }
      }
    }
  }

  FIN[12] = data1[12];
  FIN[13] = data1[13];
  FIN[14] = data1[14];
  FIN[15] = data1[15];
  FIN[16] = data1[16];
  FIN[17] = data1[17];
  FIN[18] = data1[18];
  FIN[19] = data1[19];

  FIN[22] = data1[22];
  FIN[23] = data1[23];
  FIN[24] = data1[24];

  cr1();//Вычисляем контрольную сумму
  cr2();
  //Serial.println("_________");
z3:
  //for ( i = 0; i < 34 ; i++ ){Serial1.write (data1[i]);
  Serial1.write(data1, sizeof(data1));
  //Serial.write(data1, sizeof(data1));//Посылаем сумму на терминал
  paystat = 2;
  //delay(500);
  //Serial.write(data1, sizeof(data1));
  //Pay.stop();

  //--------------------------------------------------------------------------------------------------
  //Ожидаем ответ банка по принятой или отклоненной транзакции
  //z4:
  //delay(500);
  //if(Serial1.available()==0){goto z4;}


}
void cr1() {
  crc = 0xffff;
  for ( i = 0; i < 37 ; i++ ) { //sizeof(data)
    tmp = (crc >> 8) ^ (0x00ff & data1[i]);
    crc = ( crc << 8 ) ^ crc16_ccitt_table[ tmp ];
  }
  data1[37] = ( ( crc >> 8 ) & 0xFF);
  data1[38] = ( crc & 0xFF);
}
void cr2() {
  crc = 0xffff;
  for ( i = 0; i < 27 ; i++ ) { //sizeof(data)
    tmp = (crc >> 8) ^ (0x00ff & FIN[i]);
    crc = ( crc << 8 ) ^ crc16_ccitt_table[ tmp ];
  }
  FIN[27] = ( ( crc >> 8 ) & 0xFF);
  //Serial.print("crc");
  //Serial.print(FIN[18], HEX);
  FIN[28] = ( crc & 0xFF);
  //Serial.println(FIN[19], HEX);
}


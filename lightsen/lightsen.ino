
int inPin=4;
//設PIN腳為4
int val=1; 
//設一個變數來讀取PIN的狀態
void setup() {
  // put your setup code here, to run once:
pinMode(inPin,INPUT);
//設定腳位輸入
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
val=digitalRead(inPin);
//使用變數來讀取腳位狀態
Serial.println(val);}

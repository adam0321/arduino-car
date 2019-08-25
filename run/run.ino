int pinLF=14; 
//定義14腳位左前
int pinLB=15;
//定義15腳位左後
int pinRF=16;
//定義16腳位右前 
int pinRB=17;
//定義17腳位右後 
int PWMEN1=3;
int PWMEN2=5;
//脈衝寬度調變

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(pinLB,OUTPUT);
pinMode(pinLF,OUTPUT);
pinMode(pinRB,OUTPUT);
pinMode(pinRF,OUTPUT);
pinMode(PWMEN1,OUTPUT);
pinMode(PWMEN2,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  turnR(5);
  delay(1000);
  //右轉 
  turnL(5);
  delay(1000);
  //左轉
  advance(5); 
  delay(1000);
  //前進
  back(5);
  delay(1000);
  //後退
  stop1(5);
  delay(1000);
  //停止 
}


void advance(int a){
digitalWrite(pinRF,HIGH);
digitalWrite(pinRB,LOW);
//使右馬達啟動動作
analogWrite(PWMEN1,150);
//改變馬達旋轉快慢
analogWrite(pinRB,0);
//使腳位持續低電位
digitalWrite(pinLF,HIGH);
digitalWrite(pinLB,LOW);
//使左馬達啟動動作
analogWrite(PWMEN2,160);
//改變馬達旋轉快慢
analogWrite(pinLB,0);
//使腳位持續低電位
delay(a*100);
//工作狀態時間設定
}


void back(int g){
digitalWrite(pinRF,LOW);
digitalWrite(pinRB,HIGH);
//使右馬達啟動動作
analogWrite(pinRF,0);
//使腳位持續低電位
analogWrite(PWMEN1,155);
//改變馬達旋轉快慢
digitalWrite(pinLF,LOW);
digitalWrite(pinLB,HIGH);
//使左馬達啟動動作
analogWrite(pinLF,0);
//使腳位持續低電位
analogWrite(PWMEN2,160);
//改變馬達旋轉快慢
delay(g*100);
//工作狀態時間設定
}


void stop1(int b){
digitalWrite(pinRF,LOW);
digitalWrite(pinRB,LOW);
//使右馬達啟動動作
analogWrite(PWMEN1,140);
//改變馬達旋轉快慢
analogWrite(pinRB,0);
//使腳位持續低電位
digitalWrite(pinLF,LOW);
digitalWrite(pinLB,LOW);
//使左馬達啟動動作
analogWrite(PWMEN2,158);
//改變馬達旋轉快慢
analogWrite(pinLB,0);
//使腳位持續低電位
delay(b*100);
//工作狀態時間設定
}


void turnL(int c){
digitalWrite(pinRF,HIGH);
digitalWrite(pinRB,LOW);
//使右馬達啟動動作
analogWrite(PWMEN1,100);
//改變馬達旋轉快慢
analogWrite(pinRB,0);
//使腳位持續低電位
digitalWrite(pinLF,LOW);
digitalWrite(pinLB,LOW);
//使左馬達啟動動作
analogWrite(PWMEN2,100);
//改變馬達旋轉快慢
analogWrite(pinRB,0);
//使腳位持續低電位
delay(c*100);
//工作狀態時間設定
}


void turnR(int d){
digitalWrite(pinLF,HIGH);
digitalWrite(pinLB,LOW);
//使左馬達啟動動作
analogWrite(PWMEN1,150);
//改變馬達旋轉快慢
analogWrite(pinRB,0);
//使腳位持續低電位
digitalWrite(pinRF,LOW);
digitalWrite(pinRB,LOW);
//使右馬達啟動動作
analogWrite(PWMEN2,110);
//改變馬達旋轉快慢
analogWrite(pinRB,0);
//使腳位持續低電位
delay(d*100);
//工作狀態時間設定
}

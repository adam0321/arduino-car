int ledPin1=10;
//設定LED由第10腳位控制
int ledPin2=11;
//設定LED由第11腳位控制
int ledPin3=12;  
//設定LED由第12腳位控制 


void setup() {
  // put your setup code here, to run once:
pinMode(ledPin1, OUTPUT); 
//設定第10腳位為輸出
pinMode(ledPin2, OUTPUT);
//設定第11腳位為輸出
pinMode(ledPin3, OUTPUT);
//設定第12腳位為輸出
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(ledPin1,HIGH);
  //設定led亮
  delay(100);
  //等待(0.1秒)
  digitalWrite(ledPin1,LOW);
  //設定led暗
  delay(100);
  //等待(0.1秒)  
  digitalWrite(ledPin2,HIGH);
  //設定led亮
  delay(100);
  //等待(0.1秒)
  digitalWrite(ledPin2,LOW);
  //設定led暗
  delay(100); 
  //等待(0.1秒)
  digitalWrite(ledPin3,HIGH);
  //設定led亮 
  delay(100); 
  //等待(0.1秒)
  digitalWrite(ledPin3,LOW);  
  //設定led暗
  delay(100);
  //等待(0.1秒)
}

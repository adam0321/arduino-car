
int inputPin=9; 
//定義超音波信號接收腳位
int outputPin=8; 
//定義超音波信號發射腳位
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600); 
pinMode(inputPin,INPUT);
//定義超音波輸入腳位
pinMode(outputPin,OUTPUT); 
//定義超音波輸出腳位 
}

void loop() {
  // put your main code here, to run repeatedly:
ask_pin_F();
//讀取前方距離
delay(3000);
}


void ask_pin_F(){ 
  digitalWrite(outputPin,LOW); 
  delayMicroseconds(2); 
  //讓超聲波發射低電壓2
  digitalWrite(outputPin,HIGH); 
  delayMicroseconds(10); 
  //讓超聲波發射低電壓10
  digitalWrite(outputPin,LOW); 
  //維持超聲波發射低電壓
  float Fdistance=pulseIn(inputPin,HIGH); 
  //讀取相差時間
  Fdistance=Fdistance/5.8/10; 
  //將時間轉為距離
  Serial.print("F distance");
  //輸出距離
  Serial.println(Fdistance);}
  //顯示距離 

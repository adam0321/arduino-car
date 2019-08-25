//超音波

int inputPin=9; 
//定義超音波信號接收腳位
int outputPin=8; 
//定義超音波信號發射腳位

//LED
int ledPin1=10;
//設定LED由第10腳位控制
int ledPin2=11;
//設定LED由第11腳位控制
int ledPin3=12;  
//設定LED由第12腳位控制 



//光敏
int val=1; 
//設一個變數來讀取PIN的狀態
int ledState = 0; 
int inPin=4;
//設PIN腳為4


//蜂鳴器
int valpin=13; 
//設定腳位為13
char notes[]="ggagCbggagDCggGECbaFFECDC"; 
//寫入生日快樂歌簡譜
unsigned long beats[]={1,1,1,1,1,2,1,1,1,1,1,2,1,1,1,1,1,1,2,1,1,1,1,1,2};
//寫入每個音機的拍子 
int length =sizeof(notes); 
//利用sizeof(),算出要用多少音符
int tempo=300; 
//拍子長度

//輪子
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
pinMode(inputPin,INPUT);
//設定腳位輸入 
pinMode(outputPin,OUTPUT); 
//設定腳位輸出

pinMode(valpin,INPUT); 

pinMode(ledPin1, OUTPUT); 
//設定第10腳位為輸出
pinMode(ledPin2, OUTPUT);
//設定第11腳位為輸出
pinMode(ledPin3, OUTPUT);
//設定第12腳位為輸出
pinMode(inPin,INPUT);
}



void loop() { 
delay(3000);
//延遲3秒
val=digitalRead(inPin);
//使用變數來讀取按鍵腳位狀態
Serial.println(val);
  // 光線不足時打開 LED
  if (val==0 ) {
    digitalWrite(ledPin1, HIGH);
    //設定led1亮
    digitalWrite(ledPin2, HIGH);
    //設定led2亮
    digitalWrite(ledPin3, HIGH);
    //設定led3亮
    delay(5000);
    //等待(5秒)
    digitalWrite(ledPin1, LOW);
    //設定led1暗 
    digitalWrite(ledPin2, LOW);
    //設定led2暗 
    digitalWrite(ledPin3, LOW);
    //設定led3暗 
  }else {
    ask_pin_F();
    //執行超音波感測
    stop1(5);
    //停止,傳入參數(5)
  } 
} 



void playNote(int valoutputPin,char note,unsigned long duration){ 
  char names[]={'c','d','e','f','g','a','b','C','D','E','F','G'}; 
    //音符用矩陣來表示
  int tones[]={261,294,330,349,392,440,494,523,587,659,698,784}; 
  //對應的頻率用矩陣表示
  for (int i=0;i<12;i++){ 
    if(names[i]==note){ 
      tone(valoutputPin,tones[i],duration); 
      delay(duration); 
      noTone(valoutputPin); 
      //依據順序來對應音階符號和頻率 
    } 
  } 
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
  Serial.println(Fdistance);
  //顯示距離 

  
if (Fdistance>45){ 
  advance(5);
  //前進,傳入參數5
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

   
  if (Fdistance>20&Fdistance<45){ 
  stop1(10); 
  //停止,傳入參數10 
  val=0;
  val=digitalRead(valpin);
  //讀取腳位狀態
  if(val==0){ 
  turnR(100);  
  for(int i=0;i<length;i++){ 
  digitalWrite(ledPin1, HIGH);
  //設定led1亮
  digitalWrite(ledPin2, HIGH);
  //設定led2亮
  digitalWrite(ledPin3, HIGH);
  //設定led3亮 
  delay(250); 
  //等待(0.25秒)
  digitalWrite(ledPin1, LOW);
  //設定led1暗 
  digitalWrite(ledPin2, LOW);
  //設定led2暗 
  digitalWrite(ledPin3, LOW);
  //設定led3暗   
  delay(250); 
  //等待(0.25秒)
 for(int i=0;i<length;i++){ 
 //用for來撥放我們設定的歌曲
 if (notes[i]==' ') 
    delay(beats[i]*tempo); 
    //如果是空白就不放音樂
 else 
    playNote(valpin,notes[i],beats[i]*tempo); 
    //呼叫playNote()fuction,將音符轉換成音訊讓蜂鳴器發出聲音
    delay(tempo/10);
    //讓音符之間的間隔有連音或段音效果
  } 
    } 
   val=1;  
  } 
  }


  
  if (Fdistance<20){
  back(1);
  //後退,傳入參數1
  delay(1000);
  //延遲1秒   
  turnR(3);
  //右轉,傳入參數3
   } 
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

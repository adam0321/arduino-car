
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

void setup() {
  // put your setup code here, to run once:
pinMode(valpin,INPUT); 
}

void loop() {
  // put your main code here, to run repeatedly:
 
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



void playNote(int valoutputPin,char note,unsigned long duration){ 
  char names[]={'c','d','e','f','g','a','b','C','D','E','F','G'};
  //音符用矩陣來表示 
  int tones[]={261,294,330,349,392,440,494,523,587,659,698,784}; 
  //對應的頻率用矩陣表示
  for (int i=0;i<8;i++){ 
    if(names[i]==note){ 
      tone(valoutputPin,tones[i],duration); 
      delay(duration); 
      noTone(valoutputPin);
      //依據順序來對應音階符號和頻率 
    } 
  } 
}

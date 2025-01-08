#include <Servo.h>  // Servo kütüphanesini dahil ediyoruz

// Ultrasonik sensör pinlerinin tanımlanması
const int trigPin = 10;  // Trig pin (ultrasonik sensör için çıkış pini)
const int echoPin = 11;  // Echo pin (ultrasonik sensör için giriş pini)

long duration;  // Ultrasonik sinyalin geri dönme süresi
int distance;   // Ölçülen mesafe (cm)

Servo myServo;  // Servo motoru kontrol etmek için Servo nesnesi oluşturuyoruz

void setup() {
  pinMode(trigPin, OUTPUT);  // Trig pinini çıkış olarak ayarlıyoruz
  pinMode(echoPin, INPUT);   // Echo pinini giriş olarak ayarlıyoruz
  Serial.begin(9600);  // Seri iletişimi başlatıyoruz, veri iletimi için 9600 baud hızını kullanıyoruz
  myServo.attach(12);  // Servo motoru 12 numaralı pin'e bağlıyoruz
}

void loop() {
  // 15 derece ile 165 derece arasında servo motoru döndürme
  for(int i=15; i<=165; i++){  // i değişkeni 15'ten 165'e kadar artıyor
    myServo.write(i);  // Servo motoru i açısına döndürüyoruz
    delay(30);  // 30 ms bekliyoruz (servo motorunun hareket etmesi için)
    distance = calculateDistance();  // Ultrasonik sensör ile mesafe ölçümü yapıyoruz
    
    // Servo açısını ve ölçülen mesafeyi seri port üzerinden yazdırıyoruz
    Serial.print(i);  
    Serial.print(",");  
    Serial.print(distance);  
    Serial.print(".");  
  }
  
  // 165 derece ile 15 derece arasında geri dönüş
  for(int i=165; i>15; i--){  // i değişkeni 165'ten 15'e kadar azalıyor
    myServo.write(i);  // Servo motorunu i açısına döndürüyoruz
    delay(30);  // 30 ms bekliyoruz
    distance = calculateDistance();  // Ultrasonik sensör ile mesafe ölçümü yapıyoruz
    
    // Servo açısını ve ölçülen mesafeyi seri port üzerinden yazdırıyoruz
    Serial.print(i);
    Serial.print(",");
    Serial.print(distance);
    Serial.print(".");
  }
}

// Mesafe hesaplamayı gerçekleştiren fonksiyon
int calculateDistance(){ 
  digitalWrite(trigPin, LOW);  // Trig pinini düşük yaparak başlatıyoruz
  delayMicroseconds(2);  // 2 mikro saniye bekliyoruz

  digitalWrite(trigPin, HIGH);  // Trig pinini yüksek yapıyoruz (ultrasonik sinyal gönderimi başlıyor)
  delayMicroseconds(10);  // 10 mikro saniye bekliyoruz (ultrasonik sinyalin gönderilmesi için)
  digitalWrite(trigPin, LOW);  // Trig pinini tekrar düşük yapıyoruz
  
  // Echo pininden gelen sinyalin uzunluğunu ölçüyoruz
  duration = pulseIn(echoPin, HIGH);  // Echo pininden yüksek sinyalin süresini ölçüyoruz
  distance = duration * 0.034 / 2;  // Mesafeyi hesaplıyoruz (ses hızını 0.034 cm/mikro saniye olarak kullanıyoruz)
  
  return distance;  // Hesaplanan mesafeyi geri döndürüyoruz
}
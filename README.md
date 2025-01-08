# Yürüme-Engelli-Bireyler-İçin-Sonar-Sistemi
# Servo Motor ve Ultrasonik Sensör ile Mesafe Ölçümü

Bu proje, bir *Servo motor* ve *Ultrasonik mesafe sensörü (HC-SR04)* kullanarak, belirli bir aralıkta servo motoru döndürür ve her açı için mesafe ölçümü yaparak seri port üzerinden çıktıyı gönderir. Bu proje, robotik projelerde mesafe ölçümü yapmak ve hareketli nesneleri tespit etmek için temel bir uygulama sunmaktadır.

## İçerik

- Servo motorun belirli bir açı aralığında (15° ile 165° arasında) hareket etmesi sağlanır.
- Ultrasonik sensör (HC-SR04) ile her hareket sırasında mesafe ölçülür.
- Ölçülen mesafe ve servo motorun açı değeri seri port üzerinden yazdırılır.

## Gerekli Donanım

- 1 x *Arduino (Uno, Mega, veya başka bir model)*
- 1 x *Servo motor*
- 1 x *Ultrasonik sensör (HC-SR04)*
- Bağlantı kabloları
- *Breadboard* (isteğe bağlı)

### Donanım Bağlantıları

- *Ultrasonik sensör (HC-SR04)*:
  - *Trig Pin* → Arduino Pin 10
  - *Echo Pin* → Arduino Pin 11
  - *VCC Pin* → Arduino 5V
  - *GND Pin* → Arduino GND

- *Servo Motor*:
  - *Kontrol Pin* → Arduino Pin 12
  - *VCC Pin* → Arduino 5V
  - *GND Pin* → Arduino GND

## Yazılım Kurulumu

Arduino IDE üzerinde aşağıdaki adımları izleyerek bu projeyi çalıştırabilirsiniz:

1. *Arduino IDE'yi açın.*
2. Projenizi oluşturun ve yukarıdaki kodu kopyalayıp Arduino IDE'ye yapıştırın.
3. *Servo kütüphanesinin yüklü olduğundan emin olun*: Arduino IDE'de Sketch → Include Library → Manage Libraries... menüsüne gidin ve Servo kütüphanesini arayın ve yükleyin.
4. Arduino'nunuzu bilgisayarınıza bağlayın ve doğru portu seçin.
5. Kodu Arduino'ya yükleyin.

## Kod Açıklaması

- *Servo Motor Hareketi*: Servo motor, 15° ile 165° arasında ileri ve geri hareket eder. Her açı için ultrasonik sensör kullanılarak mesafe ölçülür.
- *Mesafe Ölçümü*: Ultrasonik sensörün trig pinine sinyal gönderilir ve echo pininden geri dönen sinyalin süresi ölçülerek mesafe hesaplanır. Ses hızı kullanılarak bu süre mesafeye dönüştürülür.
- *Seri Port Çıktısı*: Servo motorun açısı ve ölçülen mesafe, seri port üzerinden (9600 baud hızında) sürekli olarak yazdırılır. Çıktı şu formatta olacaktır:
  
  Açık Açı,Mesafe.
  

### calculateDistance() Fonksiyonu
Bu fonksiyon, ultrasonik sensör ile mesafeyi hesaplamak için trig pinine kısa bir sinyal gönderir ve echo pininden gelen geri dönüş sinyalinin süresini ölçer. Hesaplanan mesafe şu şekilde formüle edilir:

cpp
distance = duration * 0.034 / 2;


Burada, 0.034 ses hızını temsil eder (cm/mikro saniye) ve /2 mesafenin sadece bir yönünü kapsadığı için böleriz.

## Proje Yapısı

- *ServoMotorUltrasonic.ino*: Arduino kodunun bulunduğu ana dosya.
  
## Kullanım

1. Arduino'nuzu bağladıktan sonra, seri monitörü açarak servo motorun her hareketinde ölçülen mesafeyi gözlemleyebilirsiniz.
2. Servo motor her 15° ile 165° arasındaki açılarda dönerek her hareketinde mesafeyi ölçer.
3. Bu değerler seri monitörde açılarla birlikte yazdırılacaktır.

## Geliştirme Fikirleri

- Mesafe verilerini görsel bir arayüzle (grafik, ekran) görselleştirmek.
- Farklı mesafe limitlerine göre servo motoru farklı hızlarda döndürmek.
- Çoklu sensör kullanarak 360° tarama yapabilmek.

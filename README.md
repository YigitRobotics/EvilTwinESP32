## **ESP32 Evil Twin Attack Script**  

Bu proje, ESP32 kullanarak sahte bir erişim noktası (AP) oluşturur ve ağa bağlanan cihazların MAC adreslerini ve cihaz bilgilerini OLED ekrana yazdırır. Ayrıca, bağlanan kullanıcılara rahatsız edici saldırılar gerçekleştirir:  

- **Fake DNS Responses**: Kullanıcıların girmeye çalıştığı siteleri "Bu siteye ulaşılamıyor" hatasına yönlendirme.  

⚠️ **Bu proje yalnızca kişisel testler ve siber güvenlik eğitimleri için geliştirilmiştir. Yasal kullanım sorumluluğu tamamen kullanıcıya aittir.**  

---

### **📌 Donanım Gereksinimleri**  
- **ESP32**  
- **0.96” OLED Display (I2C destekli)**  
- **USB kablo**  
- **Breadboard ve jumper kablolar (isteğe bağlı)**  

---

### **📜 Kurulum**  

#### **1️⃣ Gerekli Kütüphaneleri Yükle**  
Bu kütüphaneleri **Arduino IDE** üzerinden kur:  

- **ESPAsyncWebServer**  
- **AsyncTCP**  
- **Adafruit GFX Library**  
- **Adafruit SSD1306**  

💡 **Eksik kütüphane hatası alırsan, "Library Manager" üzerinden yükleyebilirsin.**  

---

#### **2️⃣ Kodun ESP32'ye Yüklenmesi**  
1. **Arduino IDE’de ESP32 için doğru kartı seç:**  
   - **Araçlar > Kart > ESP32 Dev Module**  
2. **Doğru COM portunu seç:**  
   - **Araçlar > Port > ESP32'nin bağlı olduğu COM portu**  
3. **Kod yüklenirken BOOT butonuna basılı tut, yükleme başladığında bırak.**  
4. **Kod başarılı şekilde yüklendiğinde ESP32 kendini yeniden başlatacaktır.**  

---

### **🖥️ Kullanım**  
1. **ESP32, sahte bir Wi-Fi ağı (Evil Twin) oluşturacaktır.**  
2. **Bağlanan cihazların MAC adresleri ve bilgileri OLED ekrana yazdırılacaktır.**  
3. **Deauth saldırısı, sahte DNS yanıtları ve HTTP yönlendirmeleri otomatik olarak devreye girecektir.**  

---

### **📜 Yasal Uyarı**  
Bu proje yalnızca **eğitim ve test amaçlıdır**. Yetkisiz ağlara müdahale **yasadışıdır**. **Sadece kendi cihazlarınız üzerinde test yapın.**  

---

## **📜 Lisans**
Bu proje **MIT Lisansı** ile lisanslanmıştır. Daha fazla bilgi için `LICENSE` dosyasına bakabilirsiniz.
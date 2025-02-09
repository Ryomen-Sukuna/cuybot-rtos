# PINOUT CUYBOT Rev.0 (REFERENSI PIN PROGRAMMABLE)

| **Label**       | **GPIO Pin** | **Deskripsi**                        |
|-----------------|--------------|--------------------------------------|
| `Bat_Voltage`   | GPIO0        | Monitoring tegangan baterai         |
| `Buzzer`        | GPIO1        | Kontrol beep buzzer                 |
| `LedState1`     | GPIO2        | Indikator Mode LED Kombinasi 1      |
| `PWM_Right_1D`  | GPIO3        | PWM motor kanan (direksi 1)         |
| `PWM_Right_2D`  | GPIO4        | PWM motor kanan (direksi 2)         |
| `PWM_Left_1D`   | GPIO5        | PWM motor kiri (direksi 1)          |
| `PWM_Left_2D`   | GPIO6        | PWM motor kiri (direksi 2)          |
| `IR_Right`      | GPIO7        | Sensor IR kanan                     |
| `STBY`          | GPIO8        | Pin Standby Motor                   |
| `LedState2`     | GPIO9        | Indikator Mode LED Kombinasi 2      |
| `IR_Left`       | GPIO10       | Sensor IR kiri                      |
| `Trig`          | GPIO20       | Trigger sensor ultrasonik           |
| `Echo`          | GPIO21       | Echo sensor ultrasonik              |

---

# PINOUT CUYBOT Rev.1 (REFERENSI PIN PROGRAMMABLE)

| **Label**       | **GPIO Pin** | **Deskripsi**                        |
|-----------------|--------------|--------------------------------------|
| `Bat_Voltage`   | GPIO0        | Monitoring tegangan baterai         |
| `IR_LEFT`       | GPIO1        | Sensor IR sisi kiri                 |
| `LedState1`     | GPIO2        | Indikator Mode LED Kombinasi 1      |
| `IR_MIDDLE`     | GPIO3        | Sensor IR tengah untuk acuan PID    |
| `IR_RIGHT`      | GPIO4        | Sensor IR sisi kanan                |
| `Buzzer`        | GPIO5        | Kontrol beep buzzer                 |
| `PWM_Left_1D`   | GPIO6        | PWM motor kiri (direksi 1)          |
| `PWM_Left_2D`   | GPIO7        | PWM motor kiri (direksi 2)          |
| `LedState2`     | GPIO8        | Indikator Mode LED Kombinasi 2      |
| `PWM_Right_1D`  | GPIO9        | PWM motor kanan (direksi 1)         |
| `PWM_Right_2D`  | GPIO10       | PWM motor kanan (direksi 2)         |
| `Trig`          | GPIO20       | Trigger sensor ultrasonik           |
| `Echo`          | GPIO21       | Echo sensor ultrasonik              |

---

### Logic State 4 Indikator Mode LED (REV-1), rev-0 dicoba saja karena hanya beda urutan aja.

- LedState1 LOW  +  LedState2 LOW     = MODE 1 ON
- LedState1 HIGH +  LedState2 LOW     = MODE 2 ON
- LedState1 LOW  +  LedState2 HIGH    = MODE 3 ON
- LedState1 HIGH +  LedState2 HIGH    = MODE 4 ON

---

### Contoh Penggunaan Kode Untuk Rev.0

contoh kode arduino sederhana buat ngontrol buzzer, dinamo motor & infrared di cuybot v1:

```cpp
// Mengatur pin untuk buzzer, PWM motor kanan, dan sensor IR
#define BUZZER_PIN 1
#define PWM_RIGHT_1D_PIN 3
#define PWM_RIGHT_2D_PIN 4
#define IR_LEFT_PIN 10
#define IR_RIGHT_PIN 7

void setup() {
  // Konfigurasi pin sebagai output atau input
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(PWM_RIGHT_1D_PIN, OUTPUT);
  pinMode(PWM_RIGHT_2D_PIN, OUTPUT);
  pinMode(IR_LEFT_PIN, INPUT);
  pinMode(IR_RIGHT_PIN, INPUT);
}

void loop() {
  // Mengaktifkan buzzer
  digitalWrite(BUZZER_PIN, HIGH);
  delay(500); // Buzzer aktif selama 500ms
  digitalWrite(BUZZER_PIN, LOW);
  delay(500); // Buzzer mati selama 500ms

  // Membaca nilai sensor IR kiri dan kanan
  int irLeftState = digitalRead(IR_LEFT_PIN);
  int irRightState = digitalRead(IR_RIGHT_PIN);

  // Mengatur PWM motor kanan berdasarkan sensor IR
  if (irLeftState == HIGH && irRightState == LOW) {
    analogWrite(PWM_RIGHT_1D_PIN, 200); // Kecepatan motor kanan sedang
    analogWrite(PWM_RIGHT_2D_PIN, 0);
  } else if (irLeftState == LOW && irRightState == HIGH) {
    analogWrite(PWM_RIGHT_1D_PIN, 0);
    analogWrite(PWM_RIGHT_2D_PIN, 200); // Kecepatan motor kanan sedang (arah sebaliknya)
  } else {
    analogWrite(PWM_RIGHT_1D_PIN, 0);
    analogWrite(PWM_RIGHT_2D_PIN, 0); // Motor berhenti
  }
}

const int ledPin = 13;
const int dotDelay = 200; // Duration of dot in ms

// Morse code mapping
const char* morseTable[] = {
  ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..",  // A-I
  ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", // J-R
  "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."         // S-Z
};

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  Serial.println("Enter text to convert to Morse code:");
}

void loop() {
  if (Serial.available()) {
    String input = Serial.readStringUntil('\n');
    input.toUpperCase();

    for (int i = 0; i < input.length(); i++) {
      char c = input.charAt(i);

      if (c >= 'A' && c <= 'Z') {
        const char* morse = morseTable[c - 'A'];
        playMorse(morse);
        delay(dotDelay * 3); // Space between letters
      } else if (c == ' ') {
        delay(dotDelay * 7); // Space between words
      }
    }
    Serial.println("Done!");
  }
}

void playMorse(const char* code) {
  while (*code) {
    if (*code == '.') {
      digitalWrite(ledPin, HIGH);
      delay(dotDelay);
      digitalWrite(ledPin, LOW);
    } else if (*code == '-') {
      digitalWrite(ledPin, HIGH);
      delay(dotDelay * 3);
      digitalWrite(ledPin, LOW);
    }
    delay(dotDelay); // Space between dots and dashes
    code++;
  }
}

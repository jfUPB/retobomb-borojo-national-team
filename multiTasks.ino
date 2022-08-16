void task1()
{
    // Definición de estados y variable de estado
    enum class Task1States
    {
        INIT,
        CONFIG,
        ARMED,
        DISARMED,
        EXPLOSION,
    };
    static Task1States task1State = Task1States::INIT;

    // Definición de variables static (conservan
    // su valor entre llamadas a task1)
    static uint32_t lasTime = 0;

    // Constantes

    static uint32_t COUNT = 20000;
    constexpr uint8_t UP = 12;
    constexpr uint8_t DOWN = 13;
    constexpr uint8_t ARM = 32;
    constexpr uint8_t bombaContando = 14;
    constexpr uint8_t bombaExplosion = 27;
    static constexpr uint32_t INTERVAL = 100;
    static uint32_t defaultState = HIGH;
    static bool ledStatus = false;

    // MÁQUINA de ESTADOS

    switch (task1State)
    {
    case Task1States::INIT:
    {

        Serial.begin(115200);
        pinMode(UP, INPUT_PULLUP);
        pinMode(DOWN, INPUT_PULLUP);
        pinMode(ARM, INPUT_PULLUP);
        pinMode(bombaContando, OUTPUT);
        pinMode(bombaExplosion, OUTPUT);

        lasTime = millis();
        task1State = Task1States::CONFIG;

        break;
    }

    case Task1States::CONFIG:
    {
        uint8_t UPstate = digitalRead(UP);
        uint8_t DOWNstate = digitalRead(DOWN);
        uint8_t ARMEDstate = digitalRead(ARM);
        digitalWrite(bombaContando, HIGH);
        if ((defaultState == UPstate) && (defaultState == DOWNstate ) && (defaultState == ARMEDstate )){
            if (UPstate == LOW && COUNT < 60000)
                COUNT += 1000;
            if (DOWNstate == LOW && COUNT > 10000)
                COUNT -= 1000;
            Serial.println(COUNT);
            if (ARMEDstate == LOW)
                task1State = Task1States::ARMED;
        }
        lasTime = millis();
        break;
    }
    case Task1States::ARMED:
    {

        uint32_t currentTime = millis();

        // Evento 1:
        if ((currentTime - lasTime) >= COUNT)
        {
            task1State = Task1States::EXPLOSION;
        }
        if ((currentTime - lasTime) >= INTERVAL)
        {
            lasTime = currentTime;
            digitalWrite(bombaExplosion, HIGH);
            digitalWrite(bombaContando, LOW);
        }

        break;
    }
    case Task1States::EXPLOSION:
    {
        digitalWrite(bombaExplosion, ledStatus);
        ledStatus = !ledStatus;

        break;
    }
    default:
    {
        Serial.println("Error");
    }
    }
}

void setup()
{
    task1();
}

void loop()
{
    task1();
}
#ifndef _My_Clock_H_
#define _My_Clock_H_

/*********************************************************************************************\
 * Power Type
\*********************************************************************************************/

typedef unsigned long power_t;              // Power (Relay) type
#define POWER_MASK             0xffffffffUL // Power (Relay) full mask

/*********************************************************************************************\
 * Defines
\*********************************************************************************************/

// Changes to the following MAX_ defines will impact settings layout
#define MAX_RELAYS             8            // Max number of relays
#define MAX_LEDS               4            // Max number of leds
#define MAX_KEYS               4            // Max number of keys or buttons
#define MAX_SWITCHES           4            // Max number of switches
#define MAX_PWMS               5            // Max number of PWM channels
#define MAX_COUNTERS           4            // Max number of counter sensors
#define MAX_PULSETIMERS        8            // Max number of supported pulse timers
#define MAX_FRIENDLYNAMES      4            // Max number of Friendly names
#define MAX_DOMOTICZ_IDX       4            // Max number of Domoticz device, key and switch indices

#define MODULE                 WEMOS  //SONOFF_BASIC // [Module] Select default model

#define MQTT_TOKEN_PREFIX      "%prefix%"   // To be substituted by mqtt_prefix[x]
#define MQTT_TOKEN_TOPIC       "%topic%"    // To be substituted by mqtt_topic, mqtt_grptopic, mqtt_buttontopic, mqtt_switchtopic

#define WIFI_HOSTNAME          "%s-%04d"    // Expands to <MQTT_TOPIC>-<last 4 decimal chars of MAC address>

#define CONFIG_FILE_SIGN       0xA5         // Configuration file signature
#define CONFIG_FILE_XOR        0x5A         // Configuration file xor (0 = No Xor)

#define HLW_PREF_PULSE         12530        // was 4975us = 201Hz = 1000W
#define HLW_UREF_PULSE         1950         // was 1666us = 600Hz = 220V
#define HLW_IREF_PULSE         3500         // was 1666us = 600Hz = 4.545A

#define MQTT_RETRY_SECS        10           // Minimum seconds to retry MQTT connection
#define APP_POWER              0            // Default saved power state Off
#define WS2812_MAX_LEDS        512          // Max number of LEDs

#define PWM_RANGE              1023         // 255..1023 needs to be devisible by 256
//#define PWM_FREQ               1000         // 100..1000 Hz led refresh
//#define PWM_FREQ               910          // 100..1000 Hz led refresh (iTead value)
#define PWM_FREQ               880          // 100..1000 Hz led refresh (BN-SZ01 value)

#define MAX_POWER_HOLD         10           // Time in SECONDS to allow max agreed power (Pow)
#define MAX_POWER_WINDOW       30           // Time in SECONDS to disable allow max agreed power (Pow)
#define SAFE_POWER_HOLD        10           // Time in SECONDS to allow max unit safe power (Pow)
#define SAFE_POWER_WINDOW      30           // Time in MINUTES to disable allow max unit safe power (Pow)
#define MAX_POWER_RETRY        5            // Retry count allowing agreed power limit overflow (Pow)

#define STATES                 20           // State loops per second
#define SYSLOG_TIMER           600          // Seconds to restore syslog_level
#define SERIALLOG_TIMER        600          // Seconds to disable SerialLog
#define OTA_ATTEMPTS           10           // Number of times to try fetching the new firmware

#define INPUT_BUFFER_SIZE      250          // Max number of characters in (serial) command buffer
#define CMDSZ                  20           // Max number of characters in command
#define TOPSZ                  100          // Max number of characters in topic string
#ifdef USE_MQTT_TLS
  #define MAX_LOG_LINES        10           // Max number of lines in weblog
#else
  #define MAX_LOG_LINES        20           // Max number of lines in weblog
#endif
#define MAX_BACKLOG            16           // Max number of commands in backlog (chk backlog_index and backlog_pointer code)
#define MIN_BACKLOG_DELAY      2            // Minimal backlog delay in 0.1 seconds

#define APP_BAUDRATE           115200       // Default serial baudrate
#define MAX_STATUS             11           // Max number of status lines

#define USE_MINI_OLED

/*********************************************************************************************\
 * Enumeration
\*********************************************************************************************/

enum WeekInMonthOptions {Last, First, Second, Third, Fourth};
enum DayOfTheWeekOptions {Sun=1, Mon, Tue, Wed, Thu, Fri, Sat};
enum MonthNamesOptions {Jan=1, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec};
enum HemisphereOptions {North, South};
enum LoggingLevels {LOG_LEVEL_NONE, LOG_LEVEL_ERROR, LOG_LEVEL_INFO, LOG_LEVEL_DEBUG, LOG_LEVEL_DEBUG_MORE, LOG_LEVEL_ALL};
enum WifiConfigOptions {WIFI_RESTART, WIFI_SMARTCONFIG, WIFI_MANAGER, WIFI_WPSCONFIG, WIFI_RETRY, WIFI_WAIT, MAX_WIFI_OPTION};
enum SwitchModeOptions {TOGGLE, FOLLOW, FOLLOW_INV, PUSHBUTTON, PUSHBUTTON_INV, PUSHBUTTONHOLD, PUSHBUTTONHOLD_INV, MAX_SWITCH_OPTION};
enum LedStateOptions {LED_OFF, LED_POWER, LED_MQTTSUB, LED_POWER_MQTTSUB, LED_MQTTPUB, LED_POWER_MQTTPUB, LED_MQTT, LED_POWER_MQTT, MAX_LED_OPTION};
enum EmulationOptions {EMUL_NONE, EMUL_WEMO, EMUL_HUE, EMUL_MAX};
enum ButtonStates {PRESSED, NOT_PRESSED};
enum SettingsParmaIndex {P_HOLD_TIME, P_MAX_POWER_RETRY, P_MAX_PARAM8};

#endif  //_My_Clock_H_

#include "Arduino.h"
#include "TestHex.h"

TestHex::TestHex(int pin) 
{
  _pin = pin;
}

void TestHex::convert(const char* str,int16_t txt)
{
  if (txt >= -32768 && txt <= 32767) {
    char* hex_txt = (char*)malloc(5); // 4 characters for the hex value and 1 for the null terminator
    sprintf(hex_txt, "%04X", txt);

    size_t len = strlen(str);
    char* hex_str = (char*)malloc(2 * len + 1); // Each character becomes 2 hexadecimal characters
    if (hex_str != NULL) {
      for (size_t i = 0; i < len; i++) {
          sprintf(hex_str + 2 * i, "%02X", str[i]);
      }
    hex_str[2 * len] = '\0';
    } else {
      printf("Memory allocation failed.\n");
    }

    printf("%s -> %s : %s\n",str,hex_str,hex_txt); 
    free(hex_txt); // Free the allocated memory
    free(hex_str); // Free the allocated memory
  } else {
        // Handle the case where the input is out of range
    printf("Inavlid Value\n");
  }

}
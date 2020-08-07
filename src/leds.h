#include "stdint.h"
#include "string.h"
#include "stdio.h"

/**
 * @brief Apaga todos los leds en el reinicio
 * 
 * @param direccion 
 */
void LedsCreate(uint16_t *direccion);

/**
 * @brief Prende un led
 * 
 * @param led 
 * @return char* 
 */
char* LedsTurnOn(uint8_t led);

/**
 * @brief Apaga un led
 * 
 * @param led 
 * @return char* 
 */
char* LedsTurnOff(uint8_t led);

/**
 * @brief Prende todos los leds del puerto de 16 bits
 * 
 */
void LedsTurnAllOn(void);

/**
 * @brief Apaga todos los leds del puerto de 16 bits
 * 
 */
void LedsTurnAllOff(void);

/**
 * @brief Prende multiples leds 
 * 
 * @param arrayleds  
 */
void LedsTurnOnMultiple(char *arrayleds);

/**
 * @brief Apaga multiples leds
 * 
 * @param arrayleds 
 */
void LedsTurnOffMultiple(char *arrayleds);

/**
 * @brief Lee el estado de un led
 * 
 * @param led 
 * @return uint16_t 
 */
uint16_t LedsReadState(uint8_t led);


#include "leds.h"

#define LEDS_ALL_OFF 0x0000
#define LEDS_ALL_ON 0x1111
#define LEDS_TO_BITS_OFFSET 1
#define LEDS_BIT_ON 1
#define NUM_MAX_LEDS 16
#define NUM_MIN_LEDS 1

static uint16_t *puerto;

uint8_t LedToBit(uint8_t led)
{
    return (led - LEDS_TO_BITS_OFFSET);
}

uint16_t BitMask(uint8_t bit)
{
    return (LEDS_BIT_ON << bit);
}

void LedsCreate(uint16_t *direccion)
{
    puerto = direccion;
    *puerto = LEDS_ALL_OFF;
}

char *LedsTurnOn(uint8_t led)
{
    char *resultado = "Invalido";
    if (led <= NUM_MAX_LEDS)
    {
        *puerto |= BitMask(LedToBit(led));
        if (led == NUM_MIN_LEDS || led == (NUM_MAX_LEDS))
        {
            resultado = "Borde";
        }
        else
        {
            resultado = "OK";
        }
    }
    else
    {
        resultado = "Invalido";
    }
    return resultado;
}

char *LedsTurnOff(uint8_t led)
{
    char *resultado = "Invalido";
    if (led <= NUM_MAX_LEDS)
    {
        *puerto &= ~BitMask(LedToBit(led));
        if (led == NUM_MIN_LEDS || led == (NUM_MAX_LEDS))
        {
            resultado = "Borde";
        }
        else
        {
            resultado = "OK";
        }
    }
    else
    {
        resultado = "Invalido";
    }
    return resultado;
}

void LedsTurnAllOn(void)
{
    *puerto = LEDS_ALL_ON;
}

void LedsTurnAllOff(void)
{
    *puerto = LEDS_ALL_OFF;
}

uint16_t LedsReadState(uint8_t led)
{
    uint16_t aux = *puerto;
    aux = aux &= BitMask(LedToBit(led));
    return aux;
}

char *LedsTurnOnMultiple(char *arrayleds)
{
    uint8_t i = 0;
    uint8_t sizearray = strlen(arrayleds);
    char *result;
    for (i = 0; i <= (sizearray); i++)
    {
        result = LedsTurnOn(arrayleds[i]);
    }
    return result;
}

char *LedsTurnOffMultiple(char *arrayleds)
{
    uint8_t i = 0;
    uint8_t sizearray = strlen(arrayleds);
    char *result;
    for (i = 0; i <= (sizearray); i++)
    {
        result = LedsTurnOff(arrayleds[i]);
    }
    return result;
}

#include "unity.h"
#include "leds.h"

static uint16_t virtuales;

void setUp(void){
    LedsCreate(&virtuales);
}

//! @test Todos los leds empiezan apagados
void test_todos_los_leds_inician_apagados(void){
    uint16_t virtuales = 0xFFFF;
    LedsCreate(&virtuales);
    TEST_ASSERT_EQUAL_UINT16(0x0000,virtuales);
}

//! @test Encender un led
void test_encender_un_led(void){
    LedsTurnOn(1);
    TEST_ASSERT_EQUAL_UINT16(0x0001,virtuales);
}

//! @test Apagar un led
void test_apagar_un_led(void){
    LedsTurnOn(1);
    LedsTurnOff(1);
    TEST_ASSERT_EQUAL_UINT16(0x0000,virtuales);
}


//! @test Prender y apagar algunos leds
void test_prender_y_apagar_varios_leds(void){
    LedsTurnOn(3);
    LedsTurnOn(5);
    LedsTurnOff(3);
    TEST_ASSERT_EQUAL_UINT16(0x0010,virtuales);
}

//! @test Prender todos los leds simultaneamente
void test_prender_todos_los_leds_simultaneamente(void){
    LedsTurnOn(3);
    LedsTurnOff(5);
    LedsTurnAllOn();
    TEST_ASSERT_EQUAL_UINT16(0x1111,virtuales);
}

//! @test Apagar todos los leds simultaneamente
void test_apagar_todos_los_leds_simultaneamente(void){
    LedsTurnOn(3);
    LedsTurnOn(5);
    LedsTurnAllOff();
    TEST_ASSERT_EQUAL_UINT16(0x0000,virtuales);
}

//! @test Consultar el estado de un led
void test_consultar_estado_de_un_led(void){
    uint16_t result;
    LedsTurnOn(3);
    LedsTurnOn(4);
    LedsTurnOff(3);
    result = LedsReadState(4);
    TEST_ASSERT_EQUAL_UINT16(0x0008,result);
}

//! @test Parametros son invalidos
void test_parametros_son_invalidos(void){
    char* result;
    char* result1;
    result = LedsTurnOn(22);
    result1 = LedsTurnOff(18);
    TEST_ASSERT_EQUAL_STRING("Invalido",result);
    TEST_ASSERT_EQUAL_STRING("Invalido",result1);
}


//! @test Parametros en valores de borde
void test_parametros_en_valores_de_borde(void){
    char* result;
    char* result1;
    result = LedsTurnOn(1);
    result1 = LedsTurnOn(16);
    TEST_ASSERT_EQUAL_STRING("Borde",result);
    TEST_ASSERT_EQUAL_STRING("Borde",result1);
}

//! @test Prender multiples leds
void test_prender_y_apagar_multiples_leds(void){
    char charleds[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
    LedsTurnOnMultiple(charleds);
    TEST_ASSERT_EQUAL_HEX16(0xFFFF,virtuales);
}


//! @test Apagar multiples leds
void test_apagar_multiples_leds(void){
    char charleds[] = {1,5,16};
    LedsTurnOnMultiple(charleds);
    LedsTurnOffMultiple(charleds);
    TEST_ASSERT_EQUAL_HEX16(0x0000,virtuales);
}




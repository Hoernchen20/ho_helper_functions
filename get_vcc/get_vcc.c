#include "get_vcc.h"

void init_get_vcc(void)
{
    adc_init(ADC_LINE(ADC_VREF_INT));
}

float get_vcc(void)
{
#if defined(BOARD_BLUEPILL)
    float vbat = 4957.744 / adc_sample(ADC_VREF_INT, ADC_RES_12BIT);
#elif
    uint16_t *vref_int_cal = ((uint16_t*) ((uint32_t) 0x1FF80078));
    float vbat = 3.0 * *vref_int_cal / adc_sample(ADC_LINE(ADC_VREF_INT), ADC_RES_12BIT);
#endif
    return vbat;
}
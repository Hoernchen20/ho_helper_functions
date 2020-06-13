#ifndef GET_VCC_H_
#define GET_VCC_H_

#include "periph/adc.h"

#if defined(BOARD_BLUEPILL)
#define ADC_VREF_INT 9
#elif
#define ADC_VREF_INT 6
#define VREF_INT_CAL 0x1FF80078
#endif

void init_get_vcc(void);
float get_vcc(void);

#endif /* GET_VCC_H_ */
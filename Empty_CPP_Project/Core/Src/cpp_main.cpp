#include "cpp_main.h"
#include "main.h"

void cpp_main()
{
	while(1)
	{
		HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_7);
		HAL_Delay(1000);
	}
}

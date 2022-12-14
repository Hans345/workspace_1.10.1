#include "cpp_main.h"
#include "main.h"
#include "iostream"

enum states{
	INIT = 0,
	BLINK1HZ,
	BLINK2HZ
};

typedef states State_Type;

void state_init_function(void);
void state_blink1hz_function(void);
void state_blink2hz_function(void);

static void (*state_table[])(void) = {
		state_init_function,
		state_blink1hz_function,
		state_blink2hz_function
};

static State_Type current_State;
static int times_blinked = 0;
static int intervall1Hz = 1000; // intervall in ms
static int intervall2Hz = 500; 	// intervall in ms
uint32_t last_time;
const int blinks = 7;

void cpp_main(){
	last_time = HAL_GetTick();
	while(1){
		state_table[current_State]();
	}
}

void state_init_function(void){
	times_blinked = 0;
	current_State = BLINK1HZ;
	std::cout<<"Execution State BLINK1HZ"<<std::endl;
}
void state_blink1hz_function(void){
	if(HAL_GetTick() - intervall1Hz > last_time)
	{
		times_blinked++;
		last_time = HAL_GetTick();
		HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_7);
	}
	if(times_blinked == 2*blinks-1)
	{
		current_State = BLINK2HZ;
		std::cout<<"Execution State BLINK2HZ"<<std::endl;
		times_blinked = 0;
	}
}
void state_blink2hz_function(void){
	if(HAL_GetTick() - intervall2Hz > last_time)
	{
		times_blinked++;
		last_time = HAL_GetTick();
		HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_7);
	}
	if(times_blinked == 2*blinks)
	{
		current_State = BLINK1HZ;
		std::cout<<"Execution State BLINK1HZ"<<std::endl;
		times_blinked = 0;
	}
}

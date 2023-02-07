/*
 * cpp_main.cpp
 *
 *  Created on: Jan 11, 2023
 *      Author: raphael.baumeler
 */

// Includes
#include "cpp_main.h"
#include "main.h"					//For. HAL-Functions
#include "stm32f7xx_hal_gpio.h"
#include <iostream>					//For std::cout
#include "util_ring_allocator.h" 	//For util::ring_allocator<>
#include <numeric>					//For std::accumulate()
#include <vector>

// Defines
#define ASCII_TAB 	(0x09)
#define ASCII_LF 	(0x0A)
#define ASCII_CR	(0x0D)
#define BUFFERSIZE 6

void cpp_main(){
	// Output to console
	int a = 1;
	std::cout<< "\033c" << (char) ASCII_LF<<(char) ASCII_CR;
	std::cout<< "----------------------------------------------------------------------"<<(char) ASCII_LF<<(char) ASCII_CR;
	std::cout<<"a = "<< a << (char) ASCII_LF<<(char) ASCII_CR;
	std::cout<<"CPP-Main started! "<< (char) ASCII_LF<<(char) ASCII_CR;
	fflush(stdout);

	// Custom Memory Allocater
	int mean = 0;
	std::vector<int32_t, util::ring_allocator<int32_t>>  buffer;

	while (1)
		{
			// Toggle LED
			HAL_GPIO_TogglePin(LD1_Green_GPIO_Port, LD1_Green_Pin);
			HAL_Delay(100);

			// Custom Memory Allocater
			a = a + 1;
	        if(buffer.size()>BUFFERSIZE-1){buffer.erase(buffer.begin());}
	        buffer.push_back(a);
	        std::cout<< "----------------------------------------------------------------------"<<(char) ASCII_LF<<(char) ASCII_CR;
	        std::cout<<"a = "<< buffer[0] << (char) ASCII_LF<<(char) ASCII_CR;
	        // Create mean Value
	        mean = std::accumulate(buffer.begin(), buffer.end(), 0LL) / buffer.size();
	        std::cout<<"mean = "<< mean << (char) ASCII_LF<<(char) ASCII_CR;
	        if(a>1000){a=0;}

	        // My Code starts here
	        // My Code ends here
		}
}


#include "../../Core_CPP/Inc/cpp_main.h"

#include "main.h"
#include <stdio.h> 		//For: printf()
#include <cstdlib> 		//For: rand()
#include <stdint.h>		//For: int16_t
#include <algorithm>    //For: std::sort()
#include <vector>       //For: std::vector
#include "BlinkingLed.h"

using namespace std;

template <typename dataType>
const dataType calcAverage(const dataType *arr, const int len);

template <typename dataType>
vector<dataType> mySort(const int16_t *arr, const int len, int stEleNr);

void cpp_main(){
	printf("CPP Main started!\n");

	// Average
	const int16_t l = 6;
	int16_t arr[l];
	for (int i = 0; i < l; i++) {
	  arr[i] =  (rand() % 100) + 1; //rand() 1...100
	}
	int16_t avg = calcAverage<int16_t>(arr, l);
	printf("Average: %d\n", avg);

	// Sort Elements
	vector<int16_t> vec(arr, arr+l);
	vec = mySort<int16_t>(arr, l, l/2); //Sort last 3 Elements only!
	int16_t sorted_arr[l] = {0};
	std::copy(vec.begin(), vec.end(), sorted_arr); //vector -> array[len]
	for(int i=0 ; i<l; i++) {
		printf("%d\n", sorted_arr[i]);
	}

	// Blinking LED
	BlinkingLed LED1(LD1_green_GPIO_Port, LD1_green_Pin);
	LED1.setFrequency(2);	//PB_0:  2Hz, toggle every 250ms
	BlinkingLed LED2(LD2_blue_GPIO_Port, LD2_blue_Pin);
	LED2.setFrequency(1);	//PB_7:  1Hz, toggle every 500ms
	BlinkingLed LED3(LD3_red_GPIO_Port, LD3_red_Pin);
	LED3.setFrequency(0.5);	//PB_14: 0.5Hz, toggle every 1000ms
	while(1){
		LED1.processBlinking();
		LED2.processBlinking();
		LED3.processBlinking();
	}
}

template <typename dataType>
const dataType calcAverage(const dataType *arr, const int len)
{
	printf("Array Size: %d\n", len);
	dataType sum = 0;
	for (int i = 0; i < len; i++) {
	  sum =  sum + arr[i];
	}
	dataType avg = sum/len;
	return avg;
}

template <typename dataType>
vector<dataType> mySort(const int16_t *arr, const int len, int stEleNr){
	// Sort Vector
	vector<int16_t> myvector(arr, arr+len);
	sort(myvector.begin() + stEleNr, myvector.end()); //Sort Elements smallest first
	printf("Sorted Elements:\n");
	for_each(myvector.begin(), myvector.end(), [](int x) {
	    printf("%d\n", x);
	});
	// Return Vector
	return myvector;
}

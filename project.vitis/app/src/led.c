/******************************************************************************
* Copyright (C) 2017 - 2022 Xilinx, Inc.  All rights reserved.
* SPDX-License-Identifier: MIT
******************************************************************************/

/******************************************************************************
 * Engineer    : Brayan Lui Estalla Quinteros
 * Institution : Jicamarca Radio Observatory
 * project     : led
 * Vitis       : 2022.2
 * source:
******************************************************************************/

#include "platform.h"
#include "xgpio.h"
#include "xparameters.h"
#include <stdio.h>
#include "xil_printf.h"
#include "sleep.h"

int main() {
    // Pointer declaration
    XGpio led;
    int status;

    // Initializing GPIO LED (pointer, id)
    status = XGpio_Initialize(&led, XPAR_LED_DEVICE_ID);

    if (status != XST_SUCCESS) {
        xil_printf("Error initializing led\n");
        return XST_FAILURE;
    }

    // GPIO LED configuration (pointer, channel, out-in)
    XGpio_SetDataDirection(&led, 1, 0xF);

    while (1) {
        // Binary values ​​are displayed on the 4 LEDs
        for (int i = 0; i < 16; i++) {
            XGpio_DiscreteWrite(&led, 1, i);
            xil_printf("led : %d\r\n", i);
            usleep(100000);
        }
    }

    return 0;
}



/*
#include "platform.h"
#include "xgpio.h"
#include "xparameters.h"
#include <stdio.h>
#include "xil_printf.h"
#include "sleep.h"


int main() {

	// Pointer declaration
    XGpio led;
    int status;

    // Initializing GPIO LED (pointer, id)
    status = XGpio_Initialize(&led, XPAR_LED_DEVICE_ID);

    if (status != XST_SUCCESS) {
        xil_printf("Error initializing led\n");
        return XST_FAILURE;
    }

    // GPIO LED configuration (pointer, channel, out-in)
    XGpio_SetDataDirection(&led, 1, 0xF);

    while (1) {

        // Turn on GPIO LED (pointer, channel, data)
        XGpio_DiscreteWrite(&led, 1, 0xF);
        xil_printf("led on\r\n");
        sleep(1);

        // Turn off GPIO LED (pointer, channel, data)
        XGpio_DiscreteWrite(&led, 1, 0x0);
        xil_printf("led off\r\n");
        sleep(1);
    }

    return 0;
}
*/






/*
#include <stdio.h>
#include "platform.h"
#include "xil_printf.h"
#include "sleep.h"


int main()
{
    init_platform();

    while(1){
    	print("Hello World\n\r");
    	print("application\n\r");
    	usleep(1000000);
    }
    cleanup_platform();
    return 0;
}
*/

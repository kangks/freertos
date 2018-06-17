/* Standard includes. */
#include <stdio.h>
#include <string.h>

#include <ti/drivers/GPIO.h>

/* FreeRTOS includes. */
#include "FreeRTOS.h"
#include "task.h"
#include "Board.h"

#include "blink.h"

void LEDBlinkTask (void *pvParameters)
{
    while(1)
    {
        vTaskDelay( LED_BLINK_DELAY );
        GPIO_write(Board_GPIO_LED1, GPIO_CFG_OUT_LOW);

        vTaskDelay( LED_BLINK_DELAY );
        GPIO_write(Board_GPIO_LED1, GPIO_CFG_OUT_HIGH);
    }
}

void vStartLEDblinkTask( void )
{
    BaseType_t xReturned;
    configPRINTF( ( "Blink...\r\n" ) );

    xReturned = xTaskCreate(LEDBlinkTask, "Blink", 256, NULL, tskIDLE_PRIORITY, NULL);
    if( xReturned == pdPASS )
    {
        configPRINTF( ( "Blink task created...\r\n" ) );
    }
}

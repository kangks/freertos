** This codes have been tested on TI CC3220SF-LAUNCHXL, thus the paths are relatives to the Code Composer Studio **

1. Download the Amazon FreeRTOS from https://docs.aws.amazon.com/freertos/latest/userguide/what-is-amazon-freertos.html
2. Clone this folder into `BASE_DIR_ROOT/demos/common/`.
3. `BASE_DIR_ROOT` can be found in the CCS, right click on the project -> Properties -> Resource -> Linked Resources -> Path Variables
4. In the Project Explorer, right click on the Project
5. Add the `blink.c` and `blink.h`
6. In the popup windows for file operation, choose `BASE_DIR_ROOT`
7. Note: If it asks to adjust compiler include-paths, choose No. Otherwise you have to recreate the .cmd file
![alt text]("https://github.com/kangks/freertos/tree/master/blinky/images/Link_file_in_CCS.png")
8. You can reorganize the .c and .h by dragging them into include and source
6. Open up `aws_demo_runner.c`
7. Add the external declaration on the top, `extern void vStartLEDblinkTask(void);`
8. In the `DEMO_RUNNER_RunDemos()`, add `vStartLEDblinkTask();`, e.g.

```
#include "aws_demo_runner.h"

/* Demo declarations. */
extern void vStartOTAUpdateDemoTask( void );
extern void vStartLEDblinkTask(void);

/*-----------------------------------------------------------*/

/**
 * @brief Runs demos in the system.
 */
void DEMO_RUNNER_RunDemos( void )
{
    vStartOTAUpdateDemoTask();
    vStartLEDblinkTask();
}
```

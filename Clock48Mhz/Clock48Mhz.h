//set_sys_clock_48mhz is defined in pico/stdlib but can't find out how to get Arduino to include stdlib.h 
//#include "pico/stdlib.h" and it does not seem to be compiled into LIBMBED.A
//https://github.com/raspberrypi/pico-sdk/blob/master/src/rp2_common/pico_stdlib/stdlib.c

#include "hardware/pll.h"
#include "hardware/clocks.h"
#include "pico/binary_info.h"

// Code is described in https://raspberrypi.github.io/pico-sdk-doxygen/group__hardware__clocks.html
// everything running off the USB oscillator
void set_sys_clock_48mhz() {
        // Change clk_sys to be 48MHz. The simplest way is to take this from PLL_USB
        // which has a source frequency of 48MHz
        clock_configure(clk_sys,
                        CLOCKS_CLK_SYS_CTRL_SRC_VALUE_CLKSRC_CLK_SYS_AUX,
                        CLOCKS_CLK_SYS_CTRL_AUXSRC_VALUE_CLKSRC_PLL_USB,
                        48 * MHZ,
                        48 * MHZ);

        // Turn off PLL sys for good measure
        pll_deinit(pll_sys);

        // CLK peri is clocked from clk_sys so need to change clk_peri's freq
        clock_configure(clk_peri,
                        0,
                        CLOCKS_CLK_PERI_CTRL_AUXSRC_VALUE_CLK_SYS,
                        48 * MHZ,
                        48 * MHZ);

        //Recalibrate Delay()
        SysTick->LOAD = 48000 - 1;
}


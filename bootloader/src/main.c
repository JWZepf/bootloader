#include <microlib.h>
#include "bootloader.h"
#include "shoulder_regs.h"

uint64_t aarch64_osdtrrx_el1_get(void) { GET_SYSREG_FUNC(osdtrrx_el1) }
uint64_t aarch64_osdtrrx_el1_set(uint64_t val) { SET_SYSREG_BY_VALUE_FUNC(osdtrrx_el1, val) }

void bootloader_main(void * fdt)
{
    bfignored(fdt);
    init_bootloader();

    BOOTLOADER_INFO("Hello from EL2");

    switch_to_el1();

    BOOTLOADER_INFO("Hello from EL1");

    BOOTLOADER_INFO("VAL: %u", aarch64_osdtrrx_el1_get());

    uint64_t val = 0x8;
    aarch64_osdtrrx_el1_set(val);

    BOOTLOADER_INFO("VAL: %u", aarch64_osdtrrx_el1_get());

    panic();
}


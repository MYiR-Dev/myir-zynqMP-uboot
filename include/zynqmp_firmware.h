/* SPDX-License-Identifier: GPL-2.0 */
/*
 * Xilinx Zynq MPSoC Firmware driver
 *
 * Copyright (C) 2018-2019 Xilinx, Inc.
 */

#ifndef _ZYNQMP_FIRMWARE_H_
#define _ZYNQMP_FIRMWARE_H_

enum pm_api_id {
	PM_GET_API_VERSION = 1,
	PM_SET_CONFIGURATION,
	PM_GET_NODE_STATUS,
	PM_GET_OPERATING_CHARACTERISTIC,
	PM_REGISTER_NOTIFIER,
	PM_REQUEST_SUSPEND,
	PM_SELF_SUSPEND,
	PM_FORCE_POWERDOWN,
	PM_ABORT_SUSPEND,
	PM_REQUEST_WAKEUP,
	PM_SET_WAKEUP_SOURCE,
	PM_SYSTEM_SHUTDOWN,
	PM_REQUEST_NODE,
	PM_RELEASE_NODE,
	PM_SET_REQUIREMENT,
	PM_SET_MAX_LATENCY,
	PM_RESET_ASSERT,
	PM_RESET_GET_STATUS,
	PM_MMIO_WRITE,
	PM_MMIO_READ,
	PM_PM_INIT_FINALIZE,
	PM_FPGA_LOAD,
	PM_FPGA_GET_STATUS,
	PM_GET_CHIPID,
	PM_SECURE_SHA = 26,
	PM_SECURE_RSA,
	PM_PINCTRL_REQUEST,
	PM_PINCTRL_RELEASE,
	PM_PINCTRL_GET_FUNCTION,
	PM_PINCTRL_SET_FUNCTION,
	PM_PINCTRL_CONFIG_PARAM_GET,
	PM_PINCTRL_CONFIG_PARAM_SET,
	PM_IOCTL,
	PM_QUERY_DATA,
	PM_CLOCK_ENABLE,
	PM_CLOCK_DISABLE,
	PM_CLOCK_GETSTATE,
	PM_CLOCK_SETDIVIDER,
	PM_CLOCK_GETDIVIDER,
	PM_CLOCK_SETRATE,
	PM_CLOCK_GETRATE,
	PM_CLOCK_SETPARENT,
	PM_CLOCK_GETPARENT,
	PM_SECURE_IMAGE,
	PM_FPGA_READ = 46,
	PM_SECURE_AES,
	PM_CLOCK_PLL_GETPARAM = 49,
	PM_REGISTER_ACCESS = 52,
	PM_EFUSE_ACCESS,
	PM_FEATURE_CHECK = 63,
	PM_API_MAX,
};

enum pm_pinctrl_config_param {
	PM_PINCTRL_CONFIG_SLEW_RATE,
	PM_PINCTRL_CONFIG_BIAS_STATUS,
	PM_PINCTRL_CONFIG_PULL_CTRL,
	PM_PINCTRL_CONFIG_SCHMITT_CMOS,
	PM_PINCTRL_CONFIG_DRIVE_STRENGTH,
	PM_PINCTRL_CONFIG_VOLTAGE_STATUS,
	PM_PINCTRL_CONFIG_TRI_STATE,
	PM_PINCTRL_CONFIG_MAX,
};

enum pm_pinctrl_slew_rate {
	PM_PINCTRL_SLEW_RATE_FAST,
	PM_PINCTRL_SLEW_RATE_SLOW,
};

enum pm_pinctrl_bias_status {
	PM_PINCTRL_BIAS_DISABLE,
	PM_PINCTRL_BIAS_ENABLE,
};

enum pm_pinctrl_pull_ctrl {
	PM_PINCTRL_BIAS_PULL_DOWN,
	PM_PINCTRL_BIAS_PULL_UP,
};

enum pm_pinctrl_schmitt_cmos {
	PM_PINCTRL_INPUT_TYPE_CMOS,
	PM_PINCTRL_INPUT_TYPE_SCHMITT,
};

enum pm_pinctrl_drive_strength {
	PM_PINCTRL_DRIVE_STRENGTH_2MA,
	PM_PINCTRL_DRIVE_STRENGTH_4MA,
	PM_PINCTRL_DRIVE_STRENGTH_8MA,
	PM_PINCTRL_DRIVE_STRENGTH_12MA,
};

enum pm_pinctrl_tri_state {
	PM_PINCTRL_TRI_STATE_DISABLE = 0,
	PM_PINCTRL_TRI_STATE_ENABLE,
};

#define PM_SIP_SVC      0xc2000000

#define ZYNQMP_PM_VERSION_MAJOR         1
#define ZYNQMP_PM_VERSION_MINOR         0
#define ZYNQMP_PM_VERSION_MAJOR_SHIFT   16
#define ZYNQMP_PM_VERSION_MINOR_MASK    0xFFFF

#define ZYNQMP_PM_VERSION       \
	((ZYNQMP_PM_VERSION_MAJOR << ZYNQMP_PM_VERSION_MAJOR_SHIFT) | \
	 ZYNQMP_PM_VERSION_MINOR)

#define ZYNQMP_PM_VERSION_INVALID       ~0

#define PMUFW_V1_0      ((1 << ZYNQMP_PM_VERSION_MAJOR_SHIFT) | 0)

#define PMIO_NODE_ID_BASE	0x1410801B

unsigned int zynqmp_firmware_version(void);
void zynqmp_pmufw_load_config_object(const void *cfg_obj, size_t size);
int xilinx_pm_request(u32 api_id, u32 arg0, u32 arg1, u32 arg2,
		      u32 arg3, u32 *ret_payload);

#endif /* _ZYNQMP_FIRMWARE_H_ */

/*
 * An flicker free driver based on Qcom MDSS for OLED devices
 *
 * Copyright (C) 2012-2014, The Linux Foundation. All rights reserved.
 * Copyright (C) Sony Mobile Communications Inc. All rights reserved.
 * Copyright (C) 2014-2018, AngeloGioacchino Del Regno <kholk11@gmail.com>
 * Copyright (C) 2018, Devries <therkduan@gmail.com>
 * Copyright (C) 2019-2020, Tanish <tanish2k09.dev@gmail.com>
 * Copyright (C) 2020, shxyke <shxyke@gmail.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */

#ifndef _FLICKER_FREE_H
#define _FLICKER_FREE_H

#define FF_MAX_SCALE 32768 /* Maximum value of RGB possible */

#define FF_MIN_SCALE 5120 /* Minimum value of RGB recommended */

#define RET_WORKGROUND
#define RET_WORKGROUND_DELAY 200

#define BACKLIGHT_INDEX 66

static const int bkl_to_pcc[BACKLIGHT_INDEX] = {42, 56, 67, 75, 84, 91, 98, 104,
	109, 114, 119, 124, 128, 133, 136, 140, 143, 146, 150, 152, 156, 159,
	162, 165, 168, 172, 176, 178, 181, 184, 187, 189, 192, 194, 196, 199,
	202, 204, 206, 209, 211, 213, 215, 217, 220, 222, 224, 226, 228, 230,
	233, 236, 237, 239, 241, 241, 243, 245, 246, 249, 249, 250, 252, 254, 255, 256};

/* Constants - Customize as needed */
static int elvss_off_threshold = 66; /* Minimum backlight value that does not flicker */


/* with this function you can set the flicker free into enabled or disabled */
void set_flicker_free(bool enabled);

/* you can use this function to remap the phisical backlight level */
u32 mdss_panel_calc_backlight(u32 bl_lvl);

/* set the minimum backlight value that does not flicker on your device */
void set_elvss_off_threshold(int value);

/* get the current elvss value */
int get_elvss_off_threshold(void);

/* get the current flicker free status (enabled or disabled) */
bool if_flicker_free_enabled(void);

#endif  /* _FLICKER_FREE_H */

// Copyright 2023 mjbogusz (@mjbogusz)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

/* Indicator LEDs */
#define LED_INDICATOR_0_PIN D0
#define LED_INDICATOR_1_PIN D5
#define LED_INDICATOR_2_PIN D4

/* RGB matrix */
#define RGB_MATRIX_LED_COUNT 28
#define RGB_MATRIX_KEYPRESSES
#define RGB_DISABLE_WHEN_USB_SUSPENDED

#ifdef RGB_MATRIX_ENABLE
	// RGB Matrix Animation modes. Explicitly enabled
	// For full list of effects, see:
	// https://docs.qmk.fm/#/feature_rgb_matrix?id=rgb-matrix-effects
	#define ENABLE_RGB_MATRIX_SOLID_COLOR
	// #define ENABLE_RGB_MATRIX_ALPHAS_MODS
	// #define ENABLE_RGB_MATRIX_GRADIENT_UP_DOWN
	// #define ENABLE_RGB_MATRIX_GRADIENT_LEFT_RIGHT
	// #define ENABLE_RGB_MATRIX_BREATHING
	// #define ENABLE_RGB_MATRIX_BAND_SAT
	// #define ENABLE_RGB_MATRIX_BAND_VAL
	// #define ENABLE_RGB_MATRIX_BAND_PINWHEEL_SAT
	// #define ENABLE_RGB_MATRIX_BAND_PINWHEEL_VAL
	// #define ENABLE_RGB_MATRIX_BAND_SPIRAL_SAT
	// #define ENABLE_RGB_MATRIX_BAND_SPIRAL_VAL
	#define ENABLE_RGB_MATRIX_CYCLE_ALL
	// #define ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
	// #define ENABLE_RGB_MATRIX_CYCLE_UP_DOWN
	// #define ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
	// #define ENABLE_RGB_MATRIX_CYCLE_OUT_IN
	// #define ENABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL
	#define ENABLE_RGB_MATRIX_CYCLE_PINWHEEL
	// #define ENABLE_RGB_MATRIX_CYCLE_SPIRAL
	// #define ENABLE_RGB_MATRIX_DUAL_BEACON
	#define ENABLE_RGB_MATRIX_RAINBOW_BEACON
	// #define ENABLE_RGB_MATRIX_RAINBOW_PINWHEELS
	// #define ENABLE_RGB_MATRIX_RAINDROPS
	// #define ENABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS
	// #define ENABLE_RGB_MATRIX_HUE_BREATHING
	// #define ENABLE_RGB_MATRIX_HUE_PENDULUM
	// #define ENABLE_RGB_MATRIX_HUE_WAVE
	// #define ENABLE_RGB_MATRIX_PIXEL_FRACTAL
	// #define ENABLE_RGB_MATRIX_PIXEL_FLOW
	#define ENABLE_RGB_MATRIX_PIXEL_RAIN
	// #define ENABLE_RGB_MATRIX_TYPING_HEATMAP
	// #define ENABLE_RGB_MATRIX_DIGITAL_RAIN
#endif

// ============================================================================
//  Copyright (c)2007 Freescale Semiconductor Inc.  -- All Rights Reserved --
//
//  The code is the property of Freescale GmbH Munich
//  C&I GTM Operation
//
//  The copyright notice above does not evidence any actual or intended
//  publication of such source code.
//
//  This software is provided by Freescale "AS IS" and any expressed or implied
//  warrenties, including, but not limited to, the implied warrenties of
//  merchantability and fitness for a particular purpose are disclaimed.
//  In no event shall Freescale or its contributors be liable for any direct,
//  indirect, incidental, special, examplary, or consequential damages
//  (including, but not limited to, procurement of substitue goods or services;
//  loss of use, data, or profits; or business interruption). However caused
//  and on any theory of liability, whether in contract, strict liability, or
//  tort (including negligence or otherwise) arising in any way out of the use
//  of this software, even if advised of the possibility of such damage.
//
//  Adaptation for SSD1306 library by Sergiy Yevtushenko <Sergiy.Yevtushenko@gmail.com>
//  ---------------------------------------------------------------------------

#include "font.h"

static uint8 fontData[] = {
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // space
		0x00, 0x00, 0x3E, 0xFF, 0xFF, 0x3E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0D, 0x0D, 0x00, 0x00, 0x00, // !
		0x00, 0x04, 0x07, 0x03, 0x00, 0x04, 0x07, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // "
		0x10, 0xFE, 0xFE, 0x10, 0x10, 0xFE, 0xFE, 0x10, 0x01, 0x0F, 0x0F, 0x01, 0x01, 0x0F, 0x0F, 0x01, // #
		0x1C, 0x3E, 0x22, 0xFF, 0xFF, 0x42, 0xCE, 0x8C, 0x03, 0x07, 0x04, 0x0F, 0x0F, 0x04, 0x07, 0x03, // $
		0x00, 0x00, 0x06, 0xC6, 0xF0, 0x3C, 0x0E, 0x02, 0x00, 0x04, 0x07, 0x03, 0x00, 0x06, 0x06, 0x00, // %
		0x1E, 0x3F, 0xE1, 0xC1, 0x41, 0x21, 0x3F, 0x1E, 0x06, 0x0F, 0x09, 0x09, 0x0B, 0x0C, 0x1E, 0x16, // &
		0x00, 0x00, 0x04, 0x07, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // '
		0x00, 0x00, 0xF8, 0xFE, 0x07, 0x01, 0x00, 0x00, 0x00, 0x00, 0x01, 0x07, 0x0E, 0x08, 0x00, 0x00, // (
		0x00, 0x00, 0x01, 0x07, 0xFE, 0xF8, 0x00, 0x00, 0x00, 0x00, 0x08, 0x0E, 0x07, 0x01, 0x00, 0x00, // )
		0x20, 0xA8, 0xF8, 0x70, 0x70, 0xF8, 0xA8, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // *
		0x20, 0x20, 0x20, 0xFC, 0xFC, 0x20, 0x20, 0x20, 0x00, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00, 0x00, // +
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x3C, 0x1C, 0x00, 0x00, 0x00, // ,
		0x00, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // -
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0C, 0x0C, 0x00, 0x00, 0x00, // .
		0x00, 0x00, 0x00, 0xC0, 0xF0, 0x3C, 0x0F, 0x03, 0x00, 0x0C, 0x0F, 0x03, 0x00, 0x00, 0x00, 0x00, // /
		0xFE, 0xFF, 0x01, 0x01, 0x01, 0xFF, 0xFE, 0x00, 0x07, 0x0F, 0x08, 0x08, 0x08, 0x0F, 0x07, 0x00, // 0
		0x00, 0x04, 0x06, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x08, 0x08, 0x0F, 0x0F, 0x08, 0x08, 0x00, // 1
		0x03, 0x81, 0xC1, 0x61, 0x31, 0x1F, 0x0E, 0x00, 0x0F, 0x09, 0x08, 0x08, 0x08, 0x08, 0x0C, 0x00, // 2
		0x03, 0x01, 0x21, 0x21, 0x21, 0xFF, 0xDE, 0x00, 0x0C, 0x08, 0x08, 0x08, 0x08, 0x0F, 0x07, 0x00, // 3
		0xE0, 0xF0, 0x98, 0x8C, 0x86, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x0F, 0x0F, 0x08, // 4
		0x3F, 0x3F, 0x21, 0x21, 0x21, 0xE1, 0xC1, 0x00, 0x04, 0x0C, 0x08, 0x08, 0x08, 0x0F, 0x07, 0x00, // 5
		0xFC, 0xFE, 0x23, 0x21, 0x21, 0xE0, 0xC0, 0x00, 0x07, 0x0F, 0x08, 0x08, 0x08, 0x0F, 0x07, 0x00, // 6
		0x03, 0x01, 0x81, 0xE1, 0x79, 0x1F, 0x07, 0x00, 0x00, 0x00, 0x0F, 0x0F, 0x00, 0x00, 0x00, 0x00, // 7
		0xDE, 0xFF, 0x21, 0x21, 0x21, 0xFF, 0xDE, 0x00, 0x07, 0x0F, 0x08, 0x08, 0x08, 0x0F, 0x07, 0x00, // 8
		0x1E, 0x3F, 0x21, 0x21, 0x21, 0xFF, 0xFE, 0x00, 0x00, 0x08, 0x08, 0x08, 0x0C, 0x07, 0x03, 0x00, // 9
		0x00, 0x00, 0x00, 0x18, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x06, 0x00, 0x00, 0x00, // :
		0x00, 0x00, 0x00, 0x18, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x1E, 0x0E, 0x00, 0x00, 0x00, // ;
		0x40, 0xE0, 0xB0, 0x18, 0x0C, 0x06, 0x02, 0x00, 0x00, 0x00, 0x01, 0x03, 0x06, 0x0C, 0x08, 0x00, // <
		0x00, 0xA0, 0xA0, 0xA0, 0xA0, 0xA0, 0xA0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // =
		0x00, 0x02, 0x06, 0x0C, 0x18, 0xB0, 0xE0, 0x40, 0x00, 0x08, 0x0C, 0x06, 0x03, 0x01, 0x00, 0x00, // >
		0x02, 0x03, 0x01, 0xC1, 0xE1, 0x31, 0x1F, 0x0E, 0x00, 0x00, 0x00, 0x0D, 0x0D, 0x00, 0x00, 0x00, // ?
		0x02, 0x03, 0x01, 0xC1, 0xE1, 0x31, 0x1F, 0x0E, 0x00, 0x00, 0x00, 0x0D, 0x0D, 0x00, 0x00, 0x00, // @
		0xF8, 0xFC, 0x86, 0x83, 0x83, 0x86, 0xFC, 0xF8, 0x0F, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x0F, 0x0F, // A
		0xFF, 0xFF, 0x21, 0x21, 0x21, 0x21, 0xFF, 0xDE, 0x0F, 0x0F, 0x08, 0x08, 0x08, 0x08, 0x0F, 0x07, // B
		0xFC, 0xFE, 0x03, 0x01, 0x01, 0x03, 0x06, 0x00, 0x03, 0x07, 0x0C, 0x08, 0x08, 0x0C, 0x06, 0x00, // C
		0x01, 0xFF, 0xFF, 0x01, 0x01, 0x03, 0xFE, 0xFC, 0x08, 0x0F, 0x0F, 0x08, 0x08, 0x0C, 0x07, 0x03, // D
		0x01, 0xFF, 0xFF, 0x21, 0x21, 0x71, 0x03, 0x00, 0x08, 0x0F, 0x0F, 0x08, 0x08, 0x08, 0x0C, 0x00, // E
		0x01, 0xFF, 0xFF, 0x21, 0x21, 0x71, 0x03, 0x00, 0x08, 0x0F, 0x0F, 0x08, 0x00, 0x00, 0x00, 0x00, // F
		0xFC, 0xFE, 0x03, 0x01, 0x41, 0x41, 0xC3, 0xC6, 0x03, 0x07, 0x0C, 0x08, 0x08, 0x08, 0x07, 0x0F, // G
		0xFF, 0xFF, 0x20, 0x20, 0x20, 0xFF, 0xFF, 0x00, 0x0F, 0x0F, 0x00, 0x00, 0x00, 0x0F, 0x0F, 0x00, // H
		0x00, 0x01, 0x01, 0xFF, 0xFF, 0x01, 0x01, 0x00, 0x00, 0x08, 0x08, 0x0F, 0x0F, 0x08, 0x08, 0x00, // I
		0x00, 0x00, 0x00, 0x00, 0x01, 0xFF, 0xFF, 0x01, 0x06, 0x0E, 0x08, 0x08, 0x08, 0x0F, 0x07, 0x00, // J
		0x01, 0xFF, 0xFF, 0x70, 0xD8, 0x8C, 0x07, 0x03, 0x08, 0x0F, 0x0F, 0x00, 0x00, 0x01, 0x0F, 0x0E, // K
		0x01, 0xFF, 0xFF, 0x01, 0x00, 0x00, 0x00, 0x00, 0x08, 0x0F, 0x0F, 0x08, 0x08, 0x08, 0x0C, 0x0C, // L
		0xFF, 0xFF, 0x0C, 0x78, 0x0C, 0xFF, 0xFF, 0x00, 0x0F, 0x0F, 0x00, 0x00, 0x00, 0x0F, 0x0F, 0x00, // M
		0xFF, 0xFF, 0x1C, 0x38, 0x70, 0xE0, 0xFF, 0xFF, 0x0F, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x0F, 0x0F, // N
		0xFE, 0xFF, 0x01, 0x01, 0x01, 0xFF, 0xFE, 0x00, 0x07, 0x0F, 0x08, 0x08, 0x08, 0x0F, 0x07, 0x00, // O
		0x01, 0xFF, 0xFF, 0x21, 0x21, 0x3F, 0x1E, 0x00, 0x08, 0x0F, 0x0F, 0x08, 0x00, 0x00, 0x00, 0x00, // P
		0xFE, 0xFF, 0x01, 0x01, 0x01, 0xFF, 0xFE, 0x01, 0x07, 0x0F, 0x0E, 0x1C, 0x38, 0x2F, 0x07, 0x00, // Q
		0x01, 0xFF, 0xFF, 0x21, 0x21, 0x61, 0xFF, 0x9E, 0x08, 0x0F, 0x0F, 0x08, 0x00, 0x00, 0x0F, 0x0F, // R
		0x0E, 0x1F, 0x31, 0x21, 0x21, 0x61, 0xC7, 0x86, 0x06, 0x0E, 0x08, 0x08, 0x08, 0x08, 0x0F, 0x07, // S
		0x03, 0x03, 0x01, 0xFF, 0xFF, 0x01, 0x03, 0x03, 0x00, 0x00, 0x08, 0x0F, 0x0F, 0x08, 0x00, 0x00, // T
		0xFF, 0xFF, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x07, 0x0F, 0x08, 0x08, 0x08, 0x0F, 0x07, 0x00, // U
		0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x01, 0x03, 0x06, 0x0C, 0x0C, 0x06, 0x03, 0x01, // V
		0xFF, 0xFF, 0x00, 0xE0, 0x00, 0xFF, 0xFF, 0x00, 0x01, 0x0F, 0x0E, 0x03, 0x0E, 0x0F, 0x01, 0x00, // W
		0x07, 0x0F, 0x98, 0xF0, 0xF0, 0x98, 0x0F, 0x07, 0x0E, 0x0F, 0x01, 0x00, 0x00, 0x01, 0x0F, 0x0E, // X
		0x0F, 0x1F, 0x30, 0xE0, 0xE0, 0x30, 0x1F, 0x0F, 0x00, 0x00, 0x08, 0x0F, 0x0F, 0x08, 0x00, 0x00, // Y
		0x03, 0x83, 0xC1, 0x61, 0x31, 0x19, 0x0F, 0x07, 0x0F, 0x0F, 0x08, 0x08, 0x08, 0x08, 0x0C, 0x0C, // Z
		0x00, 0x00, 0xFF, 0xFF, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x0F, 0x0F, 0x08, 0x08, 0x00, 0x00, // [
		0x00, 0x03, 0x0F, 0x3C, 0xF0, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x0F, 0x0C, // backslash
		0x00, 0x00, 0x01, 0x01, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x08, 0x08, 0x0F, 0x0F, 0x00, 0x00, // ]
		0x08, 0x0C, 0x06, 0x03, 0x03, 0x06, 0x0C, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // ^
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, 0x40, // _
		0x00, 0x00, 0x08, 0x0F, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // '
		0x00, 0x90, 0x90, 0x90, 0x90, 0xF0, 0xE0, 0x00, 0x07, 0x0F, 0x08, 0x08, 0x08, 0x07, 0x0F, 0x08, // a
		0x01, 0xFF, 0xFF, 0x10, 0x10, 0x30, 0xE0, 0xC0, 0x08, 0x0F, 0x07, 0x08, 0x08, 0x08, 0x0F, 0x07, // b
		0xE0, 0xF0, 0x10, 0x10, 0x10, 0x10, 0x30, 0x20, 0x07, 0x0F, 0x08, 0x08, 0x08, 0x08, 0x0C, 0x04, // c
		0xC0, 0xE0, 0x30, 0x10, 0x11, 0xFF, 0xFF, 0x00, 0x07, 0x0F, 0x08, 0x08, 0x08, 0x07, 0x0F, 0x08, // d
		0xE0, 0xF0, 0x90, 0x90, 0x90, 0x90, 0xF0, 0xE0, 0x07, 0x0F, 0x08, 0x08, 0x08, 0x08, 0x0C, 0x04, // e
		0x00, 0x10, 0xFE, 0xFF, 0x11, 0x11, 0x03, 0x02, 0x00, 0x08, 0x0F, 0x0F, 0x08, 0x00, 0x00, 0x00, // f
		0xE0, 0xF0, 0x10, 0x10, 0x10, 0xE0, 0xF0, 0x10, 0x27, 0x6F, 0x48, 0x48, 0x48, 0x7F, 0x3F, 0x00, // g
		0x01, 0xFF, 0xFF, 0x20, 0x10, 0x10, 0xF0, 0xE0, 0x08, 0x0F, 0x0F, 0x00, 0x00, 0x00, 0x0F, 0x0F, // h
		0x00, 0x10, 0x10, 0xF6, 0xF6, 0x00, 0x00, 0x00, 0x00, 0x08, 0x08, 0x0F, 0x0F, 0x08, 0x08, 0x00, // i
		0x00, 0x00, 0x10, 0x10, 0xF6, 0xF6, 0x00, 0x00, 0x30, 0x60, 0x40, 0x40, 0x7F, 0x3F, 0x00, 0x00, // j
		0x01, 0xFF, 0xFF, 0xC0, 0xC0, 0x60, 0x30, 0x10, 0x08, 0x0F, 0x0F, 0x00, 0x01, 0x03, 0x0E, 0x0C, // k
		0x00, 0x01, 0x01, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x08, 0x08, 0x0F, 0x0F, 0x08, 0x08, 0x00, // l
		0xF0, 0xF0, 0x30, 0xE0, 0xE0, 0x30, 0xF0, 0xE0, 0x0F, 0x0F, 0x00, 0x07, 0x07, 0x00, 0x0F, 0x0F, // m
		0x10, 0xF0, 0xE0, 0x10, 0x10, 0x10, 0xF0, 0xE0, 0x00, 0x0F, 0x0F, 0x00, 0x00, 0x00, 0x0F, 0x0F, // n
		0xE0, 0xF0, 0x10, 0x10, 0x10, 0x10, 0xF0, 0xE0, 0x07, 0x0F, 0x08, 0x08, 0x08, 0x08, 0x0F, 0x07, // o
		0x10, 0xF0, 0xE0, 0x10, 0x10, 0x10, 0xF0, 0xE0, 0x40, 0x7F, 0x7F, 0x48, 0x08, 0x08, 0x0F, 0x07, // p
		0xE0, 0xF0, 0x10, 0x10, 0x10, 0xE0, 0xF0, 0x10, 0x07, 0x0F, 0x08, 0x08, 0x48, 0x7F, 0x7F, 0x40, // q
		0x10, 0xF0, 0xE0, 0x10, 0x10, 0x10, 0x30, 0x20, 0x00, 0x0F, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, // r
		0x60, 0xF0, 0x90, 0x90, 0x90, 0x10, 0x30, 0x20, 0x04, 0x0C, 0x08, 0x08, 0x09, 0x09, 0x0F, 0x06, // s
		0x10, 0x10, 0xFE, 0xFF, 0x10, 0x10, 0x00, 0x00, 0x00, 0x00, 0x07, 0x0F, 0x08, 0x0C, 0x04, 0x00, // t
		0xF0, 0xF0, 0x00, 0x00, 0x00, 0xF0, 0xF0, 0x00, 0x07, 0x0F, 0x08, 0x08, 0x08, 0x07, 0x0F, 0x08, // u
		0xF0, 0xF0, 0x00, 0x00, 0x00, 0x00, 0xF0, 0xF0, 0x01, 0x03, 0x06, 0x0C, 0x0C, 0x06, 0x03, 0x01, // v
		0xF0, 0xF0, 0x00, 0x80, 0x80, 0x00, 0xF0, 0xF0, 0x07, 0x0F, 0x0C, 0x07, 0x07, 0x0C, 0x0F, 0x07, // w
		0x10, 0x30, 0x60, 0xC0, 0xC0, 0x60, 0x30, 0x10, 0x08, 0x0C, 0x06, 0x03, 0x03, 0x06, 0x0C, 0x08, // x
		0xF0, 0xF0, 0x00, 0x00, 0x00, 0x00, 0xF0, 0xF0, 0x47, 0x4F, 0x48, 0x48, 0x48, 0x68, 0x3F, 0x1F, // y
		0x30, 0x30, 0x10, 0x90, 0xD0, 0x70, 0x30, 0x10, 0x0C, 0x0E, 0x0B, 0x09, 0x08, 0x08, 0x0C, 0x0C, // z
		0x60, 0x60, 0xFE, 0x9F, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x07, 0x0F, 0x08, 0x08, 0x00, 0x00, // {
		0x00, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0F, 0x0F, 0x00, 0x00, 0x00, // |
		0x00, 0x00, 0x01, 0x01, 0x9E, 0xFE, 0x60, 0x00, 0x00, 0x00, 0x08, 0x08, 0x0F, 0x07, 0x00, 0x00, // }
		0x00, 0x20, 0x10, 0x20, 0x40, 0x20, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // ~
};

Font freeScale7x15 =
{
		8,	// width
		16,  // height
		' ',
		0x7E,
		fontData
};
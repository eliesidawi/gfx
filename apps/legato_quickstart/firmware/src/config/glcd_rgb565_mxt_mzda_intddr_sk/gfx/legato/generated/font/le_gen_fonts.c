#include "gfx/legato/generated/le_gen_assets.h"

/*********************************
 * Legato Font Asset
 * Name:         NotoSans_Regular
 * Height:       28
 * Baseline:     20
 * Style:        Antialias
 * Glyph Count:  10
 * Range Count:  7
 * Glyph Ranges: 0x2E
                 0x45-0x46
                 0x53
                 0x61
                 0x6D
                 0x72-0x74
                 0x79
 *********************************/
/*********************************
 * font glyph kerning table description
 *
 * unsigned int - number of glyphs
 * for each glyph:
 *     unsigned short - codepoint         * the glyph's codepoint
 *     short          - width             * the glyph's width in pixels
 *     short          - height            * the glyph's height in pixels
 *     short          - advance           * the glyph's advance value in pixels
 *     short          - bearingX          * the glyph's bearing value in pixels on the X axis
 *     short          - bearingY          * the glyph's bearing value in pixels on the Y axis
 *     unsigned short - flags             * status flags for this glyph
 *     unsigned short - data row width    * the size of a row of glyph data in bytes
 *     unsigned int   - data table offset * the offset into the corresponding font data table
 ********************************/
const uint8_t NotoSans_Regular_data[204] =
{
    0x0A,0x00,0x00,0x00,0x2E,0x00,0x04,0x00,0x04,0x00,0x08,0x00,0x02,0x00,0x04,0x00,
    0x00,0x00,0x04,0x00,0x00,0x00,0x00,0x00,0x45,0x00,0x0C,0x00,0x14,0x00,0x10,0x00,
    0x02,0x00,0x14,0x00,0x00,0x00,0x0C,0x00,0x10,0x00,0x00,0x00,0x46,0x00,0x0C,0x00,
    0x14,0x00,0x0F,0x00,0x02,0x00,0x14,0x00,0x00,0x00,0x0C,0x00,0x00,0x01,0x00,0x00,
    0x53,0x00,0x0E,0x00,0x14,0x00,0x0F,0x00,0x01,0x00,0x14,0x00,0x00,0x00,0x0E,0x00,
    0xF0,0x01,0x00,0x00,0x61,0x00,0x0D,0x00,0x0F,0x00,0x10,0x00,0x01,0x00,0x0F,0x00,
    0x00,0x00,0x0D,0x00,0x08,0x03,0x00,0x00,0x6D,0x00,0x16,0x00,0x0F,0x00,0x1A,0x00,
    0x02,0x00,0x0F,0x00,0x00,0x00,0x16,0x00,0xCC,0x03,0x00,0x00,0x72,0x00,0x0A,0x00,
    0x0F,0x00,0x0C,0x00,0x02,0x00,0x0F,0x00,0x00,0x00,0x0A,0x00,0x18,0x05,0x00,0x00,
    0x73,0x00,0x0C,0x00,0x0F,0x00,0x0D,0x00,0x01,0x00,0x0F,0x00,0x00,0x00,0x0C,0x00,
    0xB0,0x05,0x00,0x00,0x74,0x00,0x0A,0x00,0x13,0x00,0x0A,0x00,0x00,0x00,0x13,0x00,
    0x00,0x00,0x0A,0x00,0x64,0x06,0x00,0x00,0x79,0x00,0x0F,0x00,0x16,0x00,0x0E,0x00,
    0x00,0x00,0x0F,0x00,0x00,0x00,0x0F,0x00,0x24,0x07,0x00,0x00,
};

/*********************************
 * raw font glyph data
 ********************************/
const uint8_t NotoSans_Regular_glyphs[2160] =
{
    0x6E,0xF2,0xC8,0x12,0xEB,0xFF,0xFF,0x6A,0xE9,0xFF,0xFF,0x68,0x6A,0xF2,0xC6,0x11,
    0x48,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xE4,0x48,0xFF,0xFF,0xFF,
    0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xE4,0x48,0xFF,0xFF,0x3F,0x04,0x04,0x04,0x04,
    0x04,0x04,0x04,0x03,0x48,0xFF,0xFF,0x3C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x48,0xFF,0xFF,0x3C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x48,0xFF,0xFF,0x3C,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x48,0xFF,0xFF,0x3C,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x48,0xFF,0xFF,0x3C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x48,0xFF,0xFF,0x3F,0x04,0x04,0x04,0x04,0x04,0x04,0x04,0x01,0x48,0xFF,0xFF,0xFF,
    0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x64,0x48,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
    0xFF,0xFF,0xFF,0x64,0x48,0xFF,0xFF,0x3C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x48,0xFF,0xFF,0x3C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x48,0xFF,0xFF,0x3C,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x48,0xFF,0xFF,0x3C,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x48,0xFF,0xFF,0x3C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x48,0xFF,0xFF,0x3C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x48,0xFF,0xFF,0x3F,
    0x04,0x04,0x04,0x04,0x04,0x04,0x04,0x03,0x48,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
    0xFF,0xFF,0xFF,0xE4,0x48,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xE4,
    0x48,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xE4,0x48,0xFF,0xFF,0xFF,
    0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xE4,0x48,0xFF,0xFF,0x3F,0x04,0x04,0x04,0x04,
    0x04,0x04,0x04,0x03,0x48,0xFF,0xFF,0x3C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x48,0xFF,0xFF,0x3C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x48,0xFF,0xFF,0x3C,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x48,0xFF,0xFF,0x3C,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x48,0xFF,0xFF,0x3C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x48,0xFF,0xFF,0x3C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x48,0xFF,0xFF,0x3F,
    0x04,0x04,0x04,0x04,0x04,0x04,0x04,0x01,0x48,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
    0xFF,0xFF,0xFF,0x5C,0x48,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x5C,
    0x48,0xFF,0xFF,0x3C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x48,0xFF,0xFF,0x3C,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x48,0xFF,0xFF,0x3C,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x48,0xFF,0xFF,0x3C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x48,0xFF,0xFF,0x3C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x48,0xFF,0xFF,0x3C,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x48,0xFF,0xFF,0x3C,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x48,0xFF,0xFF,0x3C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x41,0x9E,0xDB,0xF3,0xFA,0xED,0xCC,0x96,0x4C,0x0A,0x00,0x00,0x05,
    0xA5,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x66,0x00,0x00,0x92,0xFF,0xFF,
    0xA5,0x38,0x14,0x0C,0x27,0x5E,0xB5,0xF4,0x11,0x00,0x13,0xF9,0xFF,0xA7,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x0B,0x00,0x00,0x3E,0xFF,0xFF,0x4F,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x47,0xFF,0xFF,0x4F,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x1F,0xFF,0xFF,0xAF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0xC3,0xFF,0xFF,0xA5,0x15,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x26,0xE9,0xFF,0xFF,0xF5,0x98,0x34,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x1F,0xBA,0xFF,0xFF,0xFF,0xFF,0xCE,0x5F,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x40,0xAB,0xFA,0xFF,0xFF,0xFF,0xD1,0x2A,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x16,0x78,0xE8,0xFF,0xFF,0xEE,0x24,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x0B,0x9B,0xFF,0xFF,0xA9,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,
    0xC6,0xFF,0xF3,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x83,0xFF,
    0xFF,0x09,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x91,0xFF,0xF3,0x00,
    0x0A,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1B,0xEB,0xFF,0xAC,0x00,0x93,0xC8,
    0x7E,0x46,0x1D,0x0B,0x09,0x24,0x6A,0xE5,0xFF,0xF5,0x28,0x00,0x94,0xFF,0xFF,0xFF,
    0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xE1,0x3B,0x00,0x00,0x21,0x79,0xB3,0xD2,0xE5,0xF8,
    0xF7,0xE3,0xB4,0x66,0x0A,0x00,0x00,0x00,0x00,0x00,0x09,0x5A,0xA7,0xDC,0xF5,0xF9,
    0xE2,0xA9,0x3B,0x00,0x00,0x00,0x01,0xDA,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFE,
    0x62,0x00,0x00,0x00,0x8F,0xCF,0x70,0x2C,0x0C,0x18,0x56,0xE2,0xFF,0xF1,0x0D,0x00,
    0x00,0x04,0x00,0x00,0x00,0x00,0x00,0x00,0x42,0xFF,0xFF,0x4A,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x05,0xFF,0xFF,0x67,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x02,0x04,0x04,0xF8,0xFF,0x70,0x00,0x00,0x17,0x79,0xBD,0xE4,0xF8,0xFF,0xFF,0xFF,
    0xFF,0xFF,0x70,0x00,0x56,0xF4,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x70,
    0x2D,0xFA,0xFF,0xEC,0x74,0x2E,0x0E,0x03,0x00,0x00,0xFF,0xFF,0x70,0x8F,0xFF,0xFF,
    0x34,0x00,0x00,0x00,0x00,0x00,0x07,0xFF,0xFF,0x70,0xB1,0xFF,0xE1,0x00,0x00,0x00,
    0x00,0x00,0x00,0x35,0xFF,0xFF,0x70,0xA3,0xFF,0xF8,0x09,0x00,0x00,0x00,0x00,0x05,
    0xBA,0xFF,0xFF,0x70,0x61,0xFF,0xFF,0xB3,0x2F,0x0B,0x23,0x5B,0xD3,0xF3,0xEB,0xFF,
    0x70,0x05,0xC1,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xF0,0x3F,0xA8,0xFF,0x70,0x00,0x06,
    0x74,0xCF,0xF7,0xF5,0xDC,0x95,0x1E,0x00,0x75,0xFF,0x70,0x00,0xA0,0xFF,0x73,0x00,
    0x41,0xB0,0xE9,0xF8,0xE1,0xA2,0x2E,0x00,0x00,0x17,0x89,0xD6,0xF6,0xF4,0xCE,0x78,
    0x07,0x00,0xA0,0xFF,0x9C,0x78,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xF6,0x41,0x37,0xEC,
    0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xC0,0x04,0xA0,0xFF,0xEE,0xFE,0xA2,0x31,0x0C,0x20,
    0x75,0xF8,0xFF,0xE0,0xE5,0xE7,0x61,0x1A,0x0D,0x35,0xBF,0xFF,0xFF,0x63,0xA0,0xFF,
    0xFF,0xAD,0x00,0x00,0x00,0x00,0x00,0x87,0xFF,0xFF,0xFB,0x2E,0x00,0x00,0x00,0x00,
    0x0D,0xEC,0xFF,0xB3,0xA0,0xFF,0xFF,0x39,0x00,0x00,0x00,0x00,0x00,0x35,0xFF,0xFF,
    0xB1,0x00,0x00,0x00,0x00,0x00,0x00,0xA9,0xFF,0xD9,0xA0,0xFF,0xF9,0x04,0x00,0x00,
    0x00,0x00,0x00,0x18,0xFF,0xFF,0x77,0x00,0x00,0x00,0x00,0x00,0x00,0x8C,0xFF,0xE6,
    0xA0,0xFF,0xE1,0x00,0x00,0x00,0x00,0x00,0x00,0x14,0xFF,0xFF,0x60,0x00,0x00,0x00,
    0x00,0x00,0x00,0x88,0xFF,0xE8,0xA0,0xFF,0xD8,0x00,0x00,0x00,0x00,0x00,0x00,0x14,
    0xFF,0xFF,0x5C,0x00,0x00,0x00,0x00,0x00,0x00,0x88,0xFF,0xE8,0xA0,0xFF,0xD8,0x00,
    0x00,0x00,0x00,0x00,0x00,0x14,0xFF,0xFF,0x5C,0x00,0x00,0x00,0x00,0x00,0x00,0x88,
    0xFF,0xE8,0xA0,0xFF,0xD8,0x00,0x00,0x00,0x00,0x00,0x00,0x14,0xFF,0xFF,0x5C,0x00,
    0x00,0x00,0x00,0x00,0x00,0x88,0xFF,0xE8,0xA0,0xFF,0xD8,0x00,0x00,0x00,0x00,0x00,
    0x00,0x14,0xFF,0xFF,0x5C,0x00,0x00,0x00,0x00,0x00,0x00,0x88,0xFF,0xE8,0xA0,0xFF,
    0xD8,0x00,0x00,0x00,0x00,0x00,0x00,0x14,0xFF,0xFF,0x5C,0x00,0x00,0x00,0x00,0x00,
    0x00,0x88,0xFF,0xE8,0xA0,0xFF,0xD8,0x00,0x00,0x00,0x00,0x00,0x00,0x14,0xFF,0xFF,
    0x5C,0x00,0x00,0x00,0x00,0x00,0x00,0x88,0xFF,0xE8,0xA0,0xFF,0xD8,0x00,0x00,0x00,
    0x00,0x00,0x00,0x14,0xFF,0xFF,0x5C,0x00,0x00,0x00,0x00,0x00,0x00,0x88,0xFF,0xE8,
    0xA0,0xFF,0xD8,0x00,0x00,0x00,0x00,0x00,0x00,0x14,0xFF,0xFF,0x5C,0x00,0x00,0x00,
    0x00,0x00,0x00,0x88,0xFF,0xE8,0x00,0x00,0xA0,0xFF,0x6F,0x00,0x16,0x91,0xDE,0xFD,
    0xFF,0x13,0xA0,0xFF,0x88,0x26,0xE2,0xFF,0xFF,0xFF,0xF3,0x00,0xA0,0xFF,0xAC,0xD8,
    0xF0,0x70,0x1E,0x0F,0x37,0x00,0xA0,0xFF,0xFF,0xF1,0x2A,0x00,0x00,0x00,0x00,0x00,
    0xA0,0xFF,0xFF,0x6E,0x00,0x00,0x00,0x00,0x00,0x00,0xA0,0xFF,0xFD,0x10,0x00,0x00,
    0x00,0x00,0x00,0x00,0xA0,0xFF,0xE5,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xA0,0xFF,
    0xD8,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xA0,0xFF,0xD8,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0xA0,0xFF,0xD8,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xA0,0xFF,0xD8,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0xA0,0xFF,0xD8,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0xA0,0xFF,0xD8,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xA0,0xFF,0xD8,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0xA0,0xFF,0xD8,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x38,0xA0,0xD4,0xF0,0xF9,0xE6,0xB9,0x6E,0x1D,0x00,0x00,0x99,0xFF,0xFF,
    0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xA3,0x00,0x4D,0xFF,0xFF,0x9B,0x2E,0x0D,0x0F,0x37,
    0x82,0xDF,0x3A,0x00,0x8A,0xFF,0xDD,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x00,0x00,
    0x7C,0xFF,0xEF,0x13,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x25,0xF8,0xFF,0xDF,
    0x5A,0x05,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x45,0xE7,0xFF,0xFF,0xE9,0x8D,0x2B,
    0x00,0x00,0x00,0x00,0x00,0x00,0x0C,0x70,0xD9,0xFF,0xFF,0xFF,0xBB,0x31,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x3F,0xA8,0xFC,0xFF,0xFB,0x50,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x2C,0xDA,0xFF,0xE6,0x03,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x51,0xFF,0xFF,0x1D,0x05,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x69,0xFF,0xFF,0x12,
    0x89,0xB8,0x67,0x2E,0x0F,0x07,0x1D,0x65,0xF3,0xFF,0xC2,0x00,0x8C,0xFF,0xFF,0xFF,
    0xFF,0xFF,0xFF,0xFF,0xFF,0xDF,0x25,0x00,0x12,0x69,0xBC,0xE7,0xF9,0xFB,0xEA,0xBE,
    0x70,0x0B,0x00,0x00,0x00,0x00,0x00,0x3F,0x80,0x06,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0xB8,0xFF,0x0C,0x00,0x00,0x00,0x00,0x00,0x00,0x0B,0xF8,0xFF,0x0C,0x00,0x00,
    0x00,0x00,0x00,0x00,0x5A,0xFF,0xFF,0x0C,0x00,0x00,0x00,0x00,0x30,0xB3,0xFE,0xFF,
    0xFF,0xFF,0xFF,0xFF,0xFF,0x60,0x8C,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x60,
    0x02,0x04,0x6E,0xFF,0xFF,0x0F,0x04,0x04,0x04,0x01,0x00,0x00,0x6C,0xFF,0xFF,0x0C,
    0x00,0x00,0x00,0x00,0x00,0x00,0x6C,0xFF,0xFF,0x0C,0x00,0x00,0x00,0x00,0x00,0x00,
    0x6C,0xFF,0xFF,0x0C,0x00,0x00,0x00,0x00,0x00,0x00,0x6C,0xFF,0xFF,0x0C,0x00,0x00,
    0x00,0x00,0x00,0x00,0x6C,0xFF,0xFF,0x0C,0x00,0x00,0x00,0x00,0x00,0x00,0x6C,0xFF,
    0xFF,0x0C,0x00,0x00,0x00,0x00,0x00,0x00,0x6C,0xFF,0xFF,0x0C,0x00,0x00,0x00,0x00,
    0x00,0x00,0x68,0xFF,0xFF,0x12,0x00,0x00,0x00,0x00,0x00,0x00,0x53,0xFF,0xFF,0x40,
    0x00,0x00,0x00,0x00,0x00,0x00,0x1B,0xFD,0xFF,0xD3,0x35,0x0A,0x1B,0x1F,0x00,0x00,
    0x00,0x92,0xFF,0xFF,0xFF,0xFF,0xFF,0x7C,0x00,0x00,0x00,0x03,0x6C,0xCE,0xF5,0xF4,
    0xD6,0x50,0x00,0x00,0xC6,0xFF,0xD7,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x8E,
    0xFF,0xFD,0x1A,0x60,0xFF,0xFF,0x37,0x00,0x00,0x00,0x00,0x00,0x00,0x02,0xE5,0xFF,
    0xB8,0x00,0x0A,0xF0,0xFF,0x97,0x00,0x00,0x00,0x00,0x00,0x00,0x43,0xFF,0xFF,0x58,
    0x00,0x00,0x96,0xFF,0xEF,0x08,0x00,0x00,0x00,0x00,0x00,0x9E,0xFF,0xF0,0x08,0x00,
    0x00,0x31,0xFF,0xFF,0x57,0x00,0x00,0x00,0x00,0x07,0xF0,0xFF,0x99,0x00,0x00,0x00,
    0x00,0xCC,0xFF,0xB7,0x00,0x00,0x00,0x00,0x53,0xFF,0xFF,0x39,0x00,0x00,0x00,0x00,
    0x66,0xFF,0xFC,0x1A,0x00,0x00,0x00,0xAE,0xFF,0xD8,0x00,0x00,0x00,0x00,0x00,0x0D,
    0xF4,0xFF,0x77,0x00,0x00,0x0F,0xF8,0xFF,0x79,0x00,0x00,0x00,0x00,0x00,0x00,0x9C,
    0xFF,0xD6,0x00,0x00,0x62,0xFF,0xFD,0x1C,0x00,0x00,0x00,0x00,0x00,0x00,0x37,0xFF,
    0xFF,0x30,0x00,0xB7,0xFF,0xBA,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xD1,0xFF,
    0x87,0x10,0xFA,0xFF,0x5A,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x6C,0xFF,0xD3,
    0x5A,0xFF,0xF1,0x09,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x10,0xF6,0xFF,0xBD,
    0xFF,0x9B,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xA2,0xFF,0xFF,0xFF,
    0x3B,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3D,0xFF,0xFF,0xDA,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0D,0xFC,0xFF,0x7B,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x65,0xFF,0xFD,0x1E,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xCE,0xFF,0xB5,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x5F,0xFF,0xFF,0x3D,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x14,0x0A,0x19,0x6E,0xF7,0xFF,0xAF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0xB0,0xFF,0xFF,0xFF,0xFF,0xDB,0x11,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x96,
    0xF4,0xFB,0xE0,0x92,0x14,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
};

leRasterFont NotoSans_Regular =
{
    {
        {
            LE_STREAM_LOCATION_ID_INTERNAL, // data location id
            (void*)NotoSans_Regular_glyphs, // glyph table variable pointer
            2160, // data size
        },
        LE_RASTER_FONT,
    },
    28,
    20,
    LE_FONT_BPP_8, // bits per pixel
    NotoSans_Regular_data, // kerning table
};


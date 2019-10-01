#include "gfx/legato/generated/le_gen_assets.h"

/*****************************************************************************
 * Legato String Table
 * Encoding        UTF16
 * Language Count: 2
 * String Count:   16
*****************************************************************************/

/*****************************************************************************
 * string table data
 * 
 * this table contains the raw character data for each string
 * 
 * unsigned short - number of indices in the table
 * unsigned byte - size of each index
 * unsigned byte - number of languages in the table
 * 
 * index array (size = number of indices * number of languages
 * 
 * for each index in the array:
 *   unsigned byte - the font ID for the index
 *   unsigned (index size) - a value of length 'index size' that contains
 *                           the offset of the string codepoint data in
 *                           the table
 * 
 * string data is found by jumping to the index offset from the start
 * of the table
 * 
 * string data entry:
 * unsigned short : length of the string in bytes:
 * 'length' number of codepoints - the string data (encoding dependent
 ****************************************************************************/

const uint8_t stringTable_data[1574] =
{
    0x10,0x00,0x02,0x02,0x04,0x64,0x00,0x01,0x9E,0x00,0x04,0xD6,0x00,0x01,0x00,0x01,
    0x04,0x2A,0x01,0x01,0x52,0x01,0x04,0x7A,0x01,0x01,0xA2,0x01,0x04,0xCA,0x01,0x01,
    0xF6,0x01,0x00,0x20,0x02,0x01,0x3E,0x02,0x00,0x40,0x02,0x01,0x6C,0x02,0x00,0x82,
    0x02,0x01,0x98,0x02,0x00,0xAA,0x02,0x01,0xBE,0x02,0x00,0xCE,0x02,0x01,0xEA,0x02,
    0x00,0x02,0x03,0x01,0x30,0x03,0x00,0x42,0x03,0x01,0x3E,0x02,0x02,0x54,0x03,0x02,
    0x90,0x03,0x00,0xA0,0x03,0x01,0x3E,0x04,0x02,0x62,0x04,0x02,0x82,0x05,0x02,0x82,
    0x05,0x02,0x62,0x04,0x38,0x00,0x64,0x00,0x69,0x00,0x72,0x00,0x65,0x00,0x63,0x00,
    0x74,0x00,0x20,0x00,0x62,0x00,0x6C,0x00,0x69,0x00,0x74,0x00,0x20,0x00,0x75,0x00,
    0x6E,0x00,0x63,0x00,0x6F,0x00,0x6D,0x00,0x70,0x00,0x72,0x00,0x65,0x00,0x73,0x00,
    0x73,0x00,0x65,0x00,0x64,0x00,0x20,0x00,0x52,0x00,0x41,0x00,0x57,0x00,0x36,0x00,
    0x3F,0x00,0x3F,0x00,0x3F,0x00,0x44,0x00,0x69,0x00,0x72,0x00,0x65,0x00,0x63,0x00,
    0x74,0x00,0x20,0x00,0x42,0x00,0x6C,0x00,0x69,0x00,0x74,0x00,0x3F,0x00,0x3F,0x00,
    0x3F,0x00,0x3F,0x00,0x3F,0x00,0x3F,0x00,0x3F,0x00,0x3F,0x00,0x52,0x00,0x41,0x00,
    0x57,0x00,0x3F,0x00,0x3F,0x00,0x28,0x00,0x64,0x00,0x72,0x00,0x61,0x00,0x77,0x00,
    0x20,0x00,0x4A,0x00,0x50,0x00,0x45,0x00,0x47,0x00,0x20,0x00,0x63,0x00,0x6F,0x00,
    0x6D,0x00,0x70,0x00,0x72,0x00,0x65,0x00,0x73,0x00,0x73,0x00,0x65,0x00,0x64,0x00,
    0x28,0x00,0x3F,0x00,0x3F,0x00,0x3F,0x00,0x3F,0x00,0x3F,0x00,0x3F,0x00,0x3F,0x00,
    0x3F,0x00,0x3F,0x00,0x3F,0x00,0x3F,0x00,0x3F,0x00,0x4A,0x00,0x50,0x00,0x45,0x00,
    0x47,0x00,0x3F,0x00,0x3F,0x00,0x3F,0x00,0x3F,0x00,0x26,0x00,0x64,0x00,0x72,0x00,
    0x61,0x00,0x77,0x00,0x20,0x00,0x50,0x00,0x4E,0x00,0x47,0x00,0x20,0x00,0x63,0x00,
    0x6F,0x00,0x6D,0x00,0x70,0x00,0x72,0x00,0x65,0x00,0x73,0x00,0x73,0x00,0x65,0x00,
    0x64,0x00,0x26,0x00,0x3F,0x00,0x3F,0x00,0x3F,0x00,0x3F,0x00,0x3F,0x00,0x3F,0x00,
    0x3F,0x00,0x3F,0x00,0x3F,0x00,0x3F,0x00,0x3F,0x00,0x3F,0x00,0x50,0x00,0x4E,0x00,
    0x47,0x00,0x3F,0x00,0x3F,0x00,0x3F,0x00,0x3F,0x00,0x26,0x00,0x64,0x00,0x72,0x00,
    0x61,0x00,0x77,0x00,0x20,0x00,0x52,0x00,0x4C,0x00,0x45,0x00,0x20,0x00,0x63,0x00,
    0x6F,0x00,0x6D,0x00,0x70,0x00,0x72,0x00,0x65,0x00,0x73,0x00,0x73,0x00,0x65,0x00,
    0x64,0x00,0x26,0x00,0x3F,0x00,0x3F,0x00,0x3F,0x00,0x3F,0x00,0x3F,0x00,0x3F,0x00,
    0x3F,0x00,0x3F,0x00,0x3F,0x00,0x3F,0x00,0x3F,0x00,0x3F,0x00,0x52,0x00,0x4C,0x00,
    0x45,0x00,0x3F,0x00,0x3F,0x00,0x3F,0x00,0x3F,0x00,0x2A,0x00,0x64,0x00,0x72,0x00,
    0x61,0x00,0x77,0x00,0x20,0x00,0x75,0x00,0x6E,0x00,0x63,0x00,0x6F,0x00,0x6D,0x00,
    0x70,0x00,0x72,0x00,0x65,0x00,0x73,0x00,0x73,0x00,0x65,0x00,0x64,0x00,0x20,0x00,
    0x52,0x00,0x41,0x00,0x57,0x00,0x28,0x00,0x3F,0x00,0x3F,0x00,0x3F,0x00,0x3F,0x00,
    0x3F,0x00,0x3F,0x00,0x3F,0x00,0x3F,0x00,0x3F,0x00,0x3F,0x00,0x3F,0x00,0x3F,0x00,
    0x3F,0x00,0x3F,0x00,0x3F,0x00,0x52,0x00,0x41,0x00,0x57,0x00,0x3F,0x00,0x3F,0x00,
    0x1C,0x00,0x69,0x00,0x6D,0x00,0x61,0x00,0x67,0x00,0x65,0x00,0x20,0x00,0x66,0x00,
    0x72,0x00,0x6F,0x00,0x6D,0x00,0x20,0x00,0x53,0x00,0x51,0x00,0x49,0x00,0x00,0x00,
    0x2A,0x00,0x44,0x00,0x69,0x00,0x72,0x00,0x65,0x00,0x63,0x00,0x74,0x00,0x20,0x00,
    0x42,0x00,0x6C,0x00,0x69,0x00,0x74,0x00,0x20,0x00,0x52,0x00,0x41,0x00,0x57,0x00,
    0x20,0x00,0x49,0x00,0x6D,0x00,0x61,0x00,0x67,0x00,0x65,0x00,0x14,0x00,0x3F,0x00,
    0x3F,0x00,0x3F,0x00,0x3F,0x00,0x3F,0x00,0x52,0x00,0x41,0x00,0x57,0x00,0x3F,0x00,
    0x3F,0x00,0x14,0x00,0x4A,0x00,0x50,0x00,0x45,0x00,0x47,0x00,0x20,0x00,0x49,0x00,
    0x6D,0x00,0x61,0x00,0x67,0x00,0x65,0x00,0x10,0x00,0x4A,0x00,0x50,0x00,0x45,0x00,
    0x47,0x00,0x3F,0x00,0x3F,0x00,0x3F,0x00,0x3F,0x00,0x12,0x00,0x50,0x00,0x4E,0x00,
    0x47,0x00,0x20,0x00,0x49,0x00,0x6D,0x00,0x61,0x00,0x67,0x00,0x65,0x00,0x0E,0x00,
    0x50,0x00,0x4E,0x00,0x47,0x00,0x3F,0x00,0x3F,0x00,0x3F,0x00,0x3F,0x00,0x1A,0x00,
    0x52,0x00,0x41,0x00,0x57,0x00,0x2B,0x00,0x52,0x00,0x4C,0x00,0x45,0x00,0x20,0x00,
    0x49,0x00,0x6D,0x00,0x61,0x00,0x67,0x00,0x65,0x00,0x16,0x00,0x52,0x00,0x41,0x00,
    0x57,0x00,0x2B,0x00,0x52,0x00,0x4C,0x00,0x45,0x00,0x3F,0x00,0x3F,0x00,0x3F,0x00,
    0x3F,0x00,0x2C,0x00,0x55,0x00,0x6E,0x00,0x63,0x00,0x6F,0x00,0x6D,0x00,0x70,0x00,
    0x72,0x00,0x65,0x00,0x73,0x00,0x73,0x00,0x65,0x00,0x64,0x00,0x20,0x00,0x52,0x00,
    0x41,0x00,0x57,0x00,0x20,0x00,0x49,0x00,0x6D,0x00,0x61,0x00,0x67,0x00,0x65,0x00,
    0x10,0x00,0x3F,0x00,0x3F,0x00,0x3F,0x00,0x52,0x00,0x41,0x00,0x57,0x00,0x3F,0x00,
    0x3F,0x00,0x10,0x00,0x50,0x00,0x72,0x00,0x65,0x00,0x73,0x00,0x73,0x00,0x20,0x00,
    0x74,0x00,0x6F,0x00,0x3A,0x00,0x50,0x00,0x72,0x00,0x65,0x00,0x73,0x00,0x73,0x00,
    0x20,0x00,0x54,0x00,0x6F,0x00,0x20,0x00,0x4C,0x00,0x6F,0x00,0x61,0x00,0x64,0x00,
    0x20,0x00,0x45,0x00,0x78,0x00,0x74,0x00,0x65,0x00,0x72,0x00,0x6E,0x00,0x61,0x00,
    0x6C,0x00,0x20,0x00,0x41,0x00,0x73,0x00,0x73,0x00,0x65,0x00,0x74,0x00,0x73,0x00,
    0x0E,0x00,0x3F,0x00,0x3F,0x00,0x3F,0x00,0x3F,0x00,0x3F,0x00,0x3F,0x00,0x3F,0x00,
    0x9C,0x00,0x50,0x00,0x72,0x00,0x65,0x00,0x73,0x00,0x73,0x00,0x20,0x00,0x74,0x00,
    0x68,0x00,0x65,0x00,0x20,0x00,0x69,0x00,0x6D,0x00,0x61,0x00,0x67,0x00,0x65,0x00,
    0x20,0x00,0x74,0x00,0x6F,0x00,0x20,0x00,0x63,0x00,0x68,0x00,0x61,0x00,0x6E,0x00,
    0x67,0x00,0x65,0x00,0x20,0x00,0x74,0x00,0x68,0x00,0x65,0x00,0x20,0x00,0x6C,0x00,
    0x61,0x00,0x6E,0x00,0x67,0x00,0x75,0x00,0x61,0x00,0x67,0x00,0x65,0x00,0x5C,0x00,
    0x6E,0x00,0x20,0x00,0x61,0x00,0x6E,0x00,0x64,0x00,0x20,0x00,0x72,0x00,0x65,0x00,
    0x74,0x00,0x72,0x00,0x69,0x00,0x65,0x00,0x76,0x00,0x65,0x00,0x20,0x00,0x65,0x00,
    0x78,0x00,0x74,0x00,0x65,0x00,0x72,0x00,0x6E,0x00,0x61,0x00,0x6C,0x00,0x6C,0x00,
    0x79,0x00,0x20,0x00,0x73,0x00,0x74,0x00,0x6F,0x00,0x72,0x00,0x65,0x00,0x64,0x00,
    0x20,0x00,0x67,0x00,0x6C,0x00,0x79,0x00,0x70,0x00,0x68,0x00,0x73,0x00,0x22,0x00,
    0x3F,0x00,0x3F,0x00,0x3F,0x00,0x3F,0x00,0x3F,0x00,0x3F,0x00,0x3F,0x00,0x3F,0x00,
    0x3F,0x00,0x3F,0x00,0x3F,0x00,0x3F,0x00,0x3F,0x00,0x3F,0x00,0x3F,0x00,0x3F,0x00,
    0x3F,0x00,0x1E,0x01,0x50,0x00,0x6C,0x00,0x65,0x00,0x61,0x00,0x73,0x00,0x65,0x00,
    0x20,0x00,0x63,0x00,0x6F,0x00,0x6E,0x00,0x6E,0x00,0x65,0x00,0x63,0x00,0x74,0x00,
    0x20,0x00,0x27,0x00,0x54,0x00,0x61,0x00,0x72,0x00,0x67,0x00,0x65,0x00,0x74,0x00,
    0x20,0x00,0x55,0x00,0x53,0x00,0x42,0x00,0x27,0x00,0x20,0x00,0x74,0x00,0x6F,0x00,
    0x20,0x00,0x50,0x00,0x43,0x00,0x2E,0x00,0x5C,0x00,0x6E,0x00,0x43,0x00,0x6F,0x00,
    0x6E,0x00,0x66,0x00,0x69,0x00,0x72,0x00,0x6D,0x00,0x20,0x00,0x66,0x00,0x69,0x00,
    0x6C,0x00,0x65,0x00,0x73,0x00,0x20,0x00,0x27,0x00,0x49,0x00,0x6D,0x00,0x61,0x00,
    0x67,0x00,0x65,0x00,0x73,0x00,0x2E,0x00,0x62,0x00,0x69,0x00,0x6E,0x00,0x27,0x00,
    0x2C,0x00,0x20,0x00,0x27,0x00,0x46,0x00,0x6F,0x00,0x6E,0x00,0x74,0x00,0x73,0x00,
    0x31,0x00,0x2E,0x00,0x62,0x00,0x69,0x00,0x6E,0x00,0x27,0x00,0x20,0x00,0x61,0x00,
    0x6E,0x00,0x64,0x00,0x20,0x00,0x27,0x00,0x46,0x00,0x6F,0x00,0x6E,0x00,0x74,0x00,
    0x73,0x00,0x32,0x00,0x2E,0x00,0x62,0x00,0x69,0x00,0x6E,0x00,0x27,0x00,0x20,0x00,
    0x65,0x00,0x78,0x00,0x69,0x00,0x73,0x00,0x74,0x00,0x2E,0x00,0x5C,0x00,0x6E,0x00,
    0x46,0x00,0x6F,0x00,0x72,0x00,0x6D,0x00,0x61,0x00,0x74,0x00,0x20,0x00,0x64,0x00,
    0x72,0x00,0x69,0x00,0x76,0x00,0x65,0x00,0x20,0x00,0x61,0x00,0x6E,0x00,0x64,0x00,
    0x20,0x00,0x63,0x00,0x6F,0x00,0x70,0x00,0x79,0x00,0x20,0x00,0x66,0x00,0x69,0x00,
    0x6C,0x00,0x65,0x00,0x73,0x00,0x20,0x00,0x69,0x00,0x66,0x00,0x20,0x00,0x6E,0x00,
    0x65,0x00,0x63,0x00,0x65,0x00,0x73,0x00,0x73,0x00,0x61,0x00,0x72,0x00,0x79,0x00,
    0x2E,0x00,0xA2,0x00,0x3F,0x00,0x3F,0x00,0x1C,0x20,0x3F,0x00,0x3F,0x00,0x55,0x00,
    0x53,0x00,0x42,0x00,0x1D,0x20,0x3F,0x00,0x3F,0x00,0x3F,0x00,0x50,0x00,0x43,0x00,
    0x3F,0x00,0x20,0x00,0x5C,0x00,0x6E,0x00,0x3F,0x00,0x3F,0x00,0x3F,0x00,0x3F,0x00,
    0x27,0x00,0x49,0x00,0x6D,0x00,0x61,0x00,0x67,0x00,0x65,0x00,0x73,0x00,0x2E,0x00,
    0x62,0x00,0x69,0x00,0x6E,0x00,0x27,0x00,0x3F,0x00,0x27,0x00,0x46,0x00,0x6F,0x00,
    0x6E,0x00,0x74,0x00,0x73,0x00,0x31,0x00,0x2E,0x00,0x62,0x00,0x69,0x00,0x6E,0x00,
    0x27,0x00,0x3F,0x00,0x27,0x00,0x46,0x00,0x6F,0x00,0x6E,0x00,0x74,0x00,0x73,0x00,
    0x32,0x00,0x2E,0x00,0x62,0x00,0x69,0x00,0x6E,0x00,0x27,0x00,0x3F,0x00,0x3F,0x00,
    0x3F,0x00,0x20,0x00,0x5C,0x00,0x6E,0x00,0x3F,0x00,0x3F,0x00,0x3F,0x00,0x3F,0x00,
    0x3F,0x00,0x3F,0x00,0x3F,0x00,0x3F,0x00,0x3F,0x00,0x3F,0x00,0x3F,0x00,0x3F,0x00,
    0x3F,0x00,0x3F,0x00,0x3F,0x00,
};

/* font asset pointer list */
leFont* fontList[5] =
{
    (leFont*)&NotoSansCJKsc_Regular,
    (leFont*)&NotoSansCJKsc_Regular_Large1,
    (leFont*)&NotoSansCJKsc_Regular_Internal,
    (leFont*)&NotoSansCJKsc_Regular_Large2,
    (leFont*)&NotoSansCJKsc_Regular_Bold,
};

const leStringTable stringTable =
{
    {
        LE_STREAM_LOCATION_ID_INTERNAL, // data location id
        (void*)stringTable_data, // data address pointer
        1574, // data size
    },
    (void*)stringTable_data, // string table data
    fontList, // font lookup table
    LE_STRING_ENCODING_UTF16 // encoding standard
};
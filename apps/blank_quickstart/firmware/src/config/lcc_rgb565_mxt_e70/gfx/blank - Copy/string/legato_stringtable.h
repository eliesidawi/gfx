#ifndef LEGATO_STRINGTABLE_H
#define LEGATO_STRINGTABLE_H

#include "gfx/blank/common/legato_common.h"
#include "gfx/blank/font/legato_font.h"

// defines meta data sizes for the string table, don't change!
#define LE_STRING_ARRAY_SIZE      4
#define LE_STRING_ENTRY_SIZE      2
#define LE_STRING_MAX_CHAR_WIDTH  6

// *****************************************************************************
/* Enumeration:
    leStringEncodingMode

  Summary:
    Indicates the string encoding mode type.  Any characters above 255 must use
    UTF8 or UTF16
*/
typedef enum leStringEncodingMode
{
    LE_STRING_ENCODING_ASCII,
    LE_STRING_ENCODING_UTF8,
    LE_STRING_ENCODING_UTF16
} leStringEncodingMode;

// *****************************************************************************
/* Structure:
    leStringTable

  Summary:
    Describes a string table asset.  There is typically only ever one of these
    defined at any one time.
    
    header - standard asset header
    languageCount - the number of languages in the string table
    stringCount - the number of strings in the string table
    stringIndexTable - the pointer to the string index table.  the string index
                       table is a table that contains all of the unique strings
                       defined in the string table.
    fontTable - the font table contains an array of pointers to all defined
                font assets that the string table references
    fontIndexTable - the font index table is a table that maps strings to font
                     indices which can then be used to get an actual font pointer
                     from the font table
    encodingMode - indicates how strings are encoded in the stringIndexTable
*/
typedef struct leStringTable
{
    leStreamDescriptor header;
    uint8_t* stringTableData;
    leFont** fontTable;
    leStringEncodingMode encodingMode;
} leStringTable;

// *****************************************************************************
/* Structure:
    struct leStringInfo

  Summary:
    Struct containing the details of a string table entry

  Remarks:
    None.
*/
typedef struct leStringInfo
{
    uint32_t stringIndex;
    uint32_t languageID;
    uint32_t offset;
    uint8_t* data;
    uint32_t dataSize;
    uint32_t length;
} leStringInfo;

// *****************************************************************************
/* Function:
    uint32_t  leStringTable_GetStringCount(const leStringTable* table)

  Summary:
     Gets the number of strings in a string table

  Description:
     Gets the number of strings in a string table

  Parameters:
    const leStringTable* table - the table to query

  Remarks:

  Returns:
    uint32_t - the number of strings in the table
*/
LIB_EXPORT uint32_t leStringTable_GetStringCount(const leStringTable* table);

// *****************************************************************************
/* Function:
    uint32_t  leStringTable_GetLanguageCount(const leStringTable* table)

  Summary:
     Gets the number of languages in a string table

  Description:
     Gets the number of languages in a string table

  Parameters:
    const leStringTable* table - the table to query

  Remarks:

  Returns:
    uint32_t - the number of languages in the table
*/

LIB_EXPORT uint32_t leStringTable_GetLanguageCount(const leStringTable* table);

// *****************************************************************************
/* Function:
    uint32_t  leStringTable_GetStringOffset(const leStringTable* table                                            const leStringTable* table,
                                            uint32_t stringID,
                                            uint32_t languageID)

  Summary:
     gets the offset of a string in the string table given a string ID and a
     language ID

  Description:
     gets the offset of a string in the string table given a string ID and a
     language ID

  Parameters:
    const leStringTable* table - the table to query
    uint32_t stringID - the string to query
    uint32_t languageID - the language to query

  Remarks:

  Returns:
    uint32_t - the offset of the string in bytes
*/
LIB_EXPORT uint32_t leStringTable_GetStringOffset(const leStringTable* table,
                                                  uint32_t stringID,
                                                  uint32_t languageID);

// *****************************************************************************
/* Function:
    uint32_t  leStringTable_GetActiveStringOffset(const leStringTable* table                                                  const leStringTable* table,
                                                  uint32_t stringID)

  Summary:
     Gets the offset of a string in the string table using an the active global
     language

  Description:
     Gets the offset of a string in the string table using an the active global
     language

  Parameters:
    const leStringTable* table - the table to query
    uint32_t stringID - the string to query

  Remarks:

  Returns:
    uint32_t - the offset of the string in bytes
*/
LIB_EXPORT uint32_t leStringTable_GetActiveStringOffset(const leStringTable* table,
                                                        uint32_t stringID);

// *****************************************************************************
/* Function:
    leFont*  leStringTable_GetStringFont(const leStringTable* table                                         const leStringTable* table,
                                         uint32_t stringID,
                                         uint32_t languageID)

  Summary:
     Gets the font for a string table string

  Description:
     Gets the font for a string table string

  Parameters:
    const leStringTable* table - the table to query
    uint32_t stringID - the string to query
    uint32_t languageID - the language to query

  Remarks:

  Returns:
    leFont* - the font for the string
*/
LIB_EXPORT leFont* leStringTable_GetStringFont(const leStringTable* table,
                                               uint32_t stringID,
                                               uint32_t languageID);

// *****************************************************************************
/* Function:
    leResult  leStringTable_StringLookup(const leStringTable* table                                         const leStringTable* table,
                                         leStringInfo* info)

  Summary:
     Gets the info for a string table string

  Description:
     Gets the info for a string table string

  Parameters:
    const leStringTable* table - the table to query
    leStringInfo* info - a filled leStringInfo structure

  Remarks:

  Returns:
    leResult - the result of the operation
*/
LIB_EXPORT leResult leStringTable_StringLookup(const leStringTable* table,
                                               leStringInfo* info);

// *****************************************************************************
/* Function:
    leResult  leStringTable_GetStringLength(const leStringTable* table                                            const leStringTable* table,
                                            leStringInfo* info)

  Summary:
     Gets the length of a string in the string table in codepoints

  Description:
     Gets the length of a string in the string table in codepoints

  Parameters:
    const leStringTable* table - the table to query
    leStringInfo* info - a valid leStringInfo structure

  Remarks:
    The provided info pointer will have its length value set

  Returns:
    leResult - the result of the operation
*/

LIB_EXPORT leResult leStringTable_GetStringLength(const leStringTable* table,
                                                  leStringInfo* info);


#endif /* LEGATO_STRINGTABLE_H */
/*
Copyright 2020 Ben Roesner (keycapsss.com)
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.
This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.
You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "lily58.h"

#ifdef RGB_MATRIX_ENABLE

// Physical layout
// X 0   16  32  48  64  80  96    112 128 144 160 176 208 224
//   -----------------------------------------------------------|  Y
//   12  11  10  09  08  07            07  08  09  10  11  12   |  0
//       03      02      01            01      02      03       |  2
//   13  14  15  16  17  18            18  17  16  15  14  13   |  16
//   24  23  22  21  20  19            19  20  21  22  23  24   |  32
//       04                                            04       |  34
//   25  26  27  28  29  30  31    31  30  29  28  27  26  25   |  48
//               05      06            06      05               |  50
//               35  34  33  32    32  33  34  35               |  64
led_config_t g_led_config = { {
    // Key Matrix to LED Index
    {  11,  10,  9,   8,   7,   6 },
    {  12,  13,  14,  15,  16,  17 },
    {  23,  22,  21,  20,  19,  18 },
    {  24,  25,  26,  27,  28,  29 },
    { NO_LED, 34, 33, 32,  31,  30 },
    {  46,  45,  44,  43,  42,  41 },
    {  47,  48,  49,  50,  51,  53 },
    {  58,  57,  56,  55,  54,  53 },
    {  59,  60,  61,  62,  63,  64 },
    { NO_LED, 69, 68, 67,  66,  65 }
}, {
    // LED Index to Physical Position
    // left
    { 80, 2 },  { 48, 2 },  { 16, 2 },  { 16, 34 }, { 48, 50 }, { 80, 50 }, // underglow
    { 80, 0 },  { 64, 0 },  { 48, 0 },  { 32, 0 },  { 16, 0 },  { 0, 0 },
    { 0, 16 },  { 16, 16 }, { 32, 16 }, { 48, 16 }, { 64, 16 }, { 80, 16 },
    { 80, 32 }, { 64, 32 }, { 48, 32 }, { 32, 32 }, { 16, 32 }, { 0, 32 },
    { 0, 48 },  { 16, 48 }, { 32, 48 }, { 48, 48 }, { 64, 48 }, { 80, 48 },
    { 96, 48 }, { 96, 64 }, { 80, 64 }, { 64, 64 }, { 48, 64 },
    // right
    { 128, 2 },  { 160, 2 },  { 208, 2 },  { 208, 34 }, { 160, 50 }, { 128, 50 }, // underglow
    { 128, 0 }, { 144, 0 }, { 160, 0 }, { 176, 0 }, { 208, 0 }, { 224, 0 },
    { 224, 16 }, { 208, 16 }, { 176, 16 }, { 160, 16 }, { 144, 16 }, { 128, 16 },
    { 128, 32 }, { 144, 32 }, { 160, 32 }, { 176, 32 }, { 208, 32 }, { 224, 32 },
    { 224, 48 }, { 208, 48 }, { 176, 48 }, { 160, 48 }, { 144, 48 }, { 128, 48 },
    { 112, 48 }, { 112, 64 }, { 128, 64 }, { 144, 64 }, { 160, 64 },
}, {
    // LED Index to Flag
    // 1 = modifier key
    // 2 = underglow
    // 4 = key backlight
    // 8 = keyboard state indication
    // left
    2, 2, 2, 2, 2, 2,
    4, 4, 4, 4, 4, 1,
    1, 4, 4, 4, 4, 4,
    4, 4, 4, 4, 4, 1,
    1, 4, 4, 4, 4, 4,
    4, 1, 1, 1, 1,
    // right
    2, 2, 2, 2, 2, 2,
    4, 4, 4, 4, 4, 1,
    1, 4, 4, 4, 4, 4,
    4, 4, 4, 4, 4, 1,
    1, 4, 4, 4, 4, 4,
    4, 1, 1, 1, 1
} };

#endif // RGB_MATRIX_ENABLE

// Copyright © 2014 Michael Jung
// 
// This file is part of Panga.
// 
// Panga is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// Panga is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with Panga.  If not, see <http://www.gnu.org/licenses/>.


#include <cmath>

#include "colormap.h"

ColorMap::ColorMap()
    : QwtLinearColorMap(QColor(Qt::black), QColor(Qt::white))
{
    for (unsigned i = 0; i < COLORMAP.size() / 3; ++i)
        addColorStop(double(i) / (COLORMAP.size() / 3. - 1),
                     QColor(COLORMAP[3 * i    ], 
                            COLORMAP[3 * i + 1],
                            COLORMAP[3 * i + 2]));
}

QRgb LogarithmicColorMap::rgb(const QwtInterval& interval, double value) const
{
    return QwtLinearColorMap::rgb(QwtInterval(std::log(interval.minValue()),
                                              std::log(interval.maxValue())),
                                  std::log(value));
}

QRgb HistogramColorMap::rgb(const QwtInterval& interval, double value) const
{
    if (value >= interval.minValue())
        return QwtLinearColorMap::rgb(interval, value);
    else
        return QColor(0, 0, 0, 0).rgba();
}

const std::vector<int> ColorMap::COLORMAP = {
    0 , 0 , 0 ,
    3 , 0 , 0 ,
    6 , 0 , 0 ,
    9 , 0 , 0 ,
    12 , 0 , 0 ,
    15 , 0 , 0 ,
    18 , 0 , 0 ,
    21 , 0 , 0 ,
    24 , 0 , 0 ,
    28 , 0 , 0 ,
    31 , 0 , 0 ,
    34 , 1 , 0 ,
    37 , 1 , 0 ,
    40 , 1 , 0 ,
    43 , 1 , 0 ,
    46 , 2 , 0 ,
    49 , 2 , 0 ,
    52 , 2 , 0 ,
    55 , 3 , 0 ,
    58 , 3 , 0 ,
    61 , 3 , 0 ,
    64 , 4 , 0 ,
    68 , 4 , 0 ,
    71 , 5 , 0 ,
    74 , 5 , 0 ,
    77 , 5 , 0 ,
    79 , 6 , 0 ,
    82 , 6 , 0 ,
    85 , 7 , 0 ,
    88 , 7 , 0 ,
    91 , 8 , 0 ,
    94 , 9 , 0 ,
    97 , 9 , 0 ,
    100 , 10 , 0 ,
    103 , 10 , 0 ,
    106 , 11 , 0 ,
    109 , 12 , 0 ,
    111 , 12 , 0 ,
    114 , 13 , 0 ,
    117 , 14 , 0 ,
    120 , 15 , 0 ,
    122 , 15 , 0 ,
    125 , 16 , 0 ,
    128 , 17 , 0 ,
    131 , 18 , 0 ,
    133 , 18 , 0 ,
    136 , 19 , 0 ,
    139 , 20 , 0 ,
    141 , 21 , 0 ,
    144 , 22 , 0 ,
    146 , 23 , 0 ,
    149 , 24 , 0 ,
    151 , 25 , 0 ,
    154 , 26 , 0 ,
    156 , 26 , 0 ,
    159 , 27 , 0 ,
    161 , 28 , 0 ,
    164 , 29 , 0 ,
    166 , 30 , 0 ,
    168 , 31 , 0 ,
    171 , 33 , 0 ,
    173 , 34 , 0 ,
    175 , 35 , 0 ,
    178 , 36 , 0 ,
    180 , 37 , 0 ,
    182 , 38 , 0 ,
    184 , 39 , 0 ,
    186 , 40 , 0 ,
    188 , 41 , 0 ,
    191 , 43 , 0 ,
    193 , 44 , 0 ,
    195 , 45 , 0 ,
    197 , 46 , 0 ,
    199 , 47 , 0 ,
    201 , 49 , 0 ,
    202 , 50 , 0 ,
    204 , 51 , 0 ,
    206 , 52 , 0 ,
    208 , 54 , 0 ,
    210 , 55 , 0 ,
    212 , 56 , 0 ,
    213 , 57 , 0 ,
    215 , 59 , 0 ,
    217 , 60 , 0 ,
    218 , 61 , 0 ,
    220 , 63 , 0 ,
    221 , 64 , 0 ,
    223 , 66 , 0 ,
    224 , 67 , 0 ,
    226 , 68 , 0 ,
    227 , 70 , 0 ,
    229 , 71 , 0 ,
    230 , 72 , 0 ,
    231 , 74 , 0 ,
    233 , 75 , 0 ,
    234 , 77 , 0 ,
    235 , 78 , 0 ,
    236 , 80 , 0 ,
    237 , 81 , 0 ,
    239 , 83 , 0 ,
    240 , 84 , 0 ,
    241 , 86 , 0 ,
    242 , 87 , 0 ,
    243 , 88 , 0 ,
    244 , 90 , 0 ,
    244 , 91 , 0 ,
    245 , 93 , 0 ,
    246 , 95 , 0 ,
    247 , 96 , 0 ,
    248 , 98 , 0 ,
    248 , 99 , 0 ,
    249 , 101 , 0 ,
    250 , 102 , 0 ,
    250 , 104 , 0 ,
    251 , 105 , 0 ,
    251 , 107 , 0 ,
    252 , 108 , 0 ,
    252 , 110 , 0 ,
    253 , 111 , 0 ,
    253 , 113 , 0 ,
    253 , 115 , 0 ,
    254 , 116 , 0 ,
    254 , 118 , 0 ,
    254 , 119 , 0 ,
    254 , 121 , 0 ,
    254 , 122 , 0 ,
    254 , 124 , 0 ,
    254 , 125 , 0 ,
    255 , 127 , 0 ,
    255 , 129 , 0 ,
    255 , 130 , 0 ,
    255 , 132 , 0 ,
    255 , 133 , 0 ,
    255 , 135 , 0 ,
    255 , 136 , 0 ,
    255 , 138 , 0 ,
    255 , 139 , 1 ,
    255 , 141 , 1 ,
    255 , 143 , 1 ,
    255 , 144 , 2 ,
    255 , 146 , 2 ,
    255 , 147 , 3 ,
    255 , 149 , 3 ,
    255 , 150 , 4 ,
    255 , 152 , 4 ,
    255 , 153 , 5 ,
    255 , 155 , 6 ,
    255 , 156 , 6 ,
    255 , 158 , 7 ,
    255 , 159 , 8 ,
    255 , 161 , 9 ,
    255 , 163 , 10 ,
    255 , 164 , 10 ,
    255 , 166 , 11 ,
    255 , 167 , 12 ,
    255 , 168 , 13 ,
    255 , 170 , 14 ,
    255 , 171 , 15 ,
    255 , 173 , 17 ,
    255 , 174 , 18 ,
    255 , 176 , 19 ,
    255 , 177 , 20 ,
    255 , 179 , 21 ,
    255 , 180 , 23 ,
    255 , 182 , 24 ,
    255 , 183 , 25 ,
    255 , 184 , 27 ,
    255 , 186 , 28 ,
    255 , 187 , 30 ,
    255 , 188 , 31 ,
    255 , 190 , 33 ,
    255 , 191 , 34 ,
    255 , 193 , 36 ,
    255 , 194 , 37 ,
    255 , 195 , 39 ,
    255 , 197 , 41 ,
    255 , 198 , 42 ,
    255 , 199 , 44 ,
    255 , 200 , 46 ,
    255 , 202 , 48 ,
    255 , 203 , 50 ,
    255 , 204 , 52 ,
    255 , 205 , 53 ,
    255 , 207 , 55 ,
    255 , 208 , 57 ,
    255 , 209 , 59 ,
    255 , 210 , 61 ,
    255 , 211 , 63 ,
    255 , 213 , 66 ,
    255 , 214 , 68 ,
    255 , 215 , 70 ,
    255 , 216 , 72 ,
    255 , 217 , 74 ,
    255 , 218 , 76 ,
    255 , 219 , 79 ,
    255 , 220 , 81 ,
    255 , 221 , 83 ,
    255 , 223 , 86 ,
    255 , 224 , 88 ,
    255 , 225 , 90 ,
    255 , 226 , 93 ,
    255 , 227 , 95 ,
    255 , 228 , 98 ,
    255 , 228 , 100 ,
    255 , 229 , 103 ,
    255 , 230 , 105 ,
    255 , 231 , 108 ,
    255 , 232 , 110 ,
    255 , 233 , 113 ,
    255 , 234 , 115 ,
    255 , 235 , 118 ,
    255 , 236 , 121 ,
    255 , 236 , 123 ,
    255 , 237 , 126 ,
    255 , 238 , 129 ,
    255 , 239 , 132 ,
    255 , 239 , 134 ,
    255 , 240 , 137 ,
    255 , 241 , 140 ,
    255 , 242 , 143 ,
    255 , 242 , 145 ,
    255 , 243 , 148 ,
    255 , 244 , 151 ,
    255 , 244 , 154 ,
    255 , 245 , 157 ,
    255 , 245 , 160 ,
    255 , 246 , 163 ,
    255 , 247 , 166 ,
    255 , 247 , 169 ,
    255 , 248 , 172 ,
    255 , 248 , 175 ,
    255 , 249 , 177 ,
    255 , 249 , 180 ,
    255 , 249 , 183 ,
    255 , 250 , 186 ,
    255 , 250 , 190 ,
    255 , 251 , 193 ,
    255 , 251 , 196 ,
    255 , 251 , 199 ,
    255 , 252 , 202 ,
    255 , 252 , 205 ,
    255 , 252 , 208 ,
    255 , 253 , 211 ,
    255 , 253 , 214 ,
    255 , 253 , 217 ,
    255 , 253 , 220 ,
    255 , 254 , 223 ,
    255 , 254 , 226 ,
    255 , 254 , 230 ,
    255 , 254 , 233 ,
    255 , 254 , 236 ,
    255 , 254 , 239 ,
    255 , 254 , 242 ,
    255 , 254 , 245 ,
    255 , 254 , 248 ,
    255 , 254 , 251 ,
    255 , 255 , 254
};
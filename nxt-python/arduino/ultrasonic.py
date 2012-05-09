# Protocol description file for the Ultrasonic Sensor
# Copyright (C) 2010  Marcus Wanner
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.

from enum import *

startmem = [0 for i in range(256)]
startmem[0x40] = 1
startmem[0x41] = 2

specs = {
    'addr': 0x2,
    'ident': {
        'version': 'V1.0',
        'maker': 'LEGO',
        'type': 'Sonar',
        },
    'memory': startmem,
    'generators': {
        '42cont': {'addr': 0x42, 'groups': ['cont'], 'contents': ('seq', [0, 256, 0]),},
        '43cont': {'addr': 0x43, 'groups': ['cont'], 'contents': ('seq', [0, 256, 1]),},
        '44cont': {'addr': 0x44, 'groups': ['cont'], 'contents': ('seq', [0, 256, 2]),},
        '45cont': {'addr': 0x45, 'groups': ['cont'], 'contents': ('seq', [0, 256, 3]),},
        '46cont': {'addr': 0x46, 'groups': ['cont'], 'contents': ('seq', [0, 256, 4]),},
        '47cont': {'addr': 0x47, 'groups': ['cont'], 'contents': ('seq', [0, 256, 5]),},
        '48cont': {'addr': 0x48, 'groups': ['cont'], 'contents': ('seq', [0, 256, 6]),},
        '49cont': {'addr': 0x49, 'groups': ['cont'], 'contents': ('seq', [0, 256, 7]),},
        'upperzero': {
            'addr': 0x43,
            'length': 7,
            'contents': ('static', 0),
            },
        TICKDELAY: 300,
        },
    'modes': {
        0x41: {
            'length': 1,
            'values': {
                0x0: [], #off mode
                0x1: [['42cont', True], ['upperzero', True]],
                0x2: [[GROUP, 'cont', True]],
                0x4: [[MEMRESET]],
                'other': [[CODE, 'Serial.println("Invalid Mode!");\n'], [MEMRESET]],
                },
            },
        },
    'code': {
        'setup': '//Serial.begin();\n',
        },
    }

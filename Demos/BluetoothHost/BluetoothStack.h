/*
             LUFA Library
     Copyright (C) Dean Camera, 2009.
              
  dean [at] fourwalledcubicle [dot] com
      www.fourwalledcubicle.com
*/

/*
  Copyright 2009  Dean Camera (dean [at] fourwalledcubicle [dot] com)

  Permission to use, copy, modify, and distribute this software
  and its documentation for any purpose and without fee is hereby
  granted, provided that the above copyright notice appear in all
  copies and that both that the copyright notice and this
  permission notice and warranty disclaimer appear in supporting
  documentation, and that the name of the author not be used in
  advertising or publicity pertaining to distribution of the
  software without specific, written prior permission.

  The author disclaim all warranties with regard to this
  software, including all implied warranties of merchantability
  and fitness.  In no event shall the author be liable for any
  special, indirect or consequential damages or any damages
  whatsoever resulting from loss of use, data or profits, whether
  in an action of contract, negligence or other tortious action,
  arising out of or in connection with the use or performance of
  this software.
*/

#ifndef _BLUETOOTH_STACK_
#define _BLUETOOTH_STACK_

	/* Includes: */
		#include <LUFA/Drivers/USB/USB.h>
		#include <LUFA/Scheduler/Scheduler.h>
		
		#include "BluetoothHCICommands.h"
		#include "BluetoothACLPackets.h"
		
	/* Type Defines: */
		typedef struct
		{
			bool    IsConnected;
			uint8_t DeviceAddress[6];
		} Bluetooth_Connection_t;
		
		typedef struct
		{
			uint32_t Class;
			char     Name[];
		} Bluetooth_Device_t;
		
	/* Tasks: */
		TASK(Bluetooth_Task);

	/* External Variables: */
		extern Bluetooth_Device_t     Bluetooth_DeviceConfiguration;
		extern Bluetooth_Connection_t Bluetooth_Connection;

#endif
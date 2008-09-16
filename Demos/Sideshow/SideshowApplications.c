/*
             MyUSB Library
     Copyright (C) Dean Camera, 2008.
              
  dean [at] fourwalledcubicle [dot] com
      www.fourwalledcubicle.com
*/

/*
  Copyright 2008  Dean Camera (dean [at] fourwalledcubicle [dot] com)

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

#include "SideshowApplications.h"

SideShow_Application_t InstalledApplications[MAX_APPLICATIONS];


uint8_t SideShow_GetTotalApplications(void)
{
	uint8_t TotalInstalledApps = 0;
	
	for (uint8_t App = 0; App < ARRAY_ELEMENTS(InstalledApplications); App++)
	{
		if (InstalledApplications[App].InUse)
		  TotalInstalledApps++;
	}
	
	return TotalInstalledApps;	
}

SideShow_Application_t* SideShow_GetFreeApplication(void)
{
	for (uint8_t App = 0; App < ARRAY_ELEMENTS(InstalledApplications); App++)
	{
		if (!(InstalledApplications[App].InUse))
		  return &InstalledApplications[App];
	}
	
	return NULL;
}

SideShow_Application_t* SideShow_GetApplicationFromGUID(GUID_t* GUID)
{
	for (uint8_t App = 0; App < ARRAY_ELEMENTS(InstalledApplications); App++)
	{
		if (InstalledApplications[App].InUse)
		{
			if (memcmp(&InstalledApplications[App].ApplicationID, GUID, sizeof(GUID_t)) == 0)
			  return &InstalledApplications[App];
		}
	}
	
	return NULL;
}

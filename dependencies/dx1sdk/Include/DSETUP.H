/*==========================================================================
 *
 *  Copyright (C) 1995 Microsoft Corporation.  All Rights Reserved.
 *
 *  File:       dsetup.h
 *  Content:    DirectXSetup, error codes and flags
 ***************************************************************************/

#ifndef __DSETUP_H__
#define __DSETUP_H__

#ifdef _WIN32
#define COM_NO_WINDOWS_H
#include <objbase.h>
#else
#define GUID void
#endif

#ifdef __cplusplus
extern "C" {
#endif

#define DSETUPERR_BADWINDOWSVERSION     -1
#define DSETUPERR_SOURCEFILENOTFOUND    -2
#define DSETUPERR_BADSOURCESIZE         -3
#define DSETUPERR_BADSOURCETIME         -4
#define DSETUPERR_NOCOPY                -5
#define DSETUPERR_OUTOFDISKSPACE        -6
#define DSETUPERR_CANTFINDINF           -7
#define DSETUPERR_CANTFINDDIR           -8
#define DSETUPERR_INTERNAL              -9


#define MAX_INFLINE             (16*1024)
#define MAX_DESCRIPTION         256

#define DSETUP_DDRAW            0x00000001      /* install DirectDraw           */
#define DSETUP_DSOUND           0x00000002      /* install DirectSound          */
#define DSETUP_DPLAY            0x00000004      /* install DirectPlay           */
#define DSETUP_DDRAWDRV         0x00000008      /* install DirectDraw Drivers   */
#define DSETUP_DSOUNDDRV        0x00000010      /* install DirectSound Drivers  */
#define DSETUP_DPLAYSP          0x00000020      /* install DirectPlay Providers */
#define DSETUP_DIRECTX          DSETUP_DDRAW | DSETUP_DSOUND | DSETUP_DPLAY | DSETUP_DDRAWDRV | DSETUP_DSOUNDDRV | DSETUP_DPLAYSP
#define DSETUP_REINSTALL        0x00000080      /* install DirectX even if existing components have the same version */

int WINAPI DirectXSetup( HWND hwnd, LPSTR root_path, DWORD flags );
int WINAPI DirectXDeviceDriverSetup( HWND hwnd, LPSTR driver_class, LPSTR inf_path, LPSTR driver_path, DWORD flags );

typedef int (WINAPI * LPDIRECTXSETUP)( HWND, LPSTR, DWORD );
typedef int (WINAPI * LPDIRECTXDEVICEDRIVERSETUP)( HWND, LPSTR, LPSTR, LPSTR, DWORD );

#ifdef __cplusplus
};
#endif

#endif

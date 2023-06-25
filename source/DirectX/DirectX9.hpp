#ifndef LDL_DirectX_DirectX9_hpp
#define LDL_DirectX_DirectX9_hpp

#include <windows.h>

#if _MSC_VER <= 1200

typedef unsigned long ULONG_PTR, * PULONG_PTR;
typedef ULONG_PTR DWORD_PTR, * PDWORD_PTR;

#define _In_
#define _Outptr_
#define _Pre_null_
#define _In_opt_
#define _Out_opt_
#define _Out_writes_bytes_opt_(x)
#define _Out_
#define _Outptr_result_bytebuffer_(x)
#define _Outptr_opt_result_bytebuffer_(x)
#define _In_reads_bytes_(x)
#define _In_reads_bytes_opt_(x)
#define _In_reads_opt_(x)
#define _Out_writes_(x)
#define _Out_writes_opt_(x)
#endif

#define DIRECTSOUND_VERSION 0x0900

#define DSBCAPS_CTRLVOLUME          0x00000080  
#define DSBCAPS_PRIMARYBUFFER       0x00000001  

#define DSBVOLUME_MAX               0   

#define DSSCL_PRIORITY              0x00000002 

typedef const GUID* LPCGUID;

typedef /* [unique] */ IUnknown* LPUNKNOWN;

typedef struct IDirectSound8* LPDIRECTSOUND8;
typedef struct IDirectSound* LPDIRECTSOUND;
typedef struct IDirectSoundBuffer* LPDIRECTSOUNDBUFFER;

//DEFINE_GUID(IID_IDirectSoundBuffer8, 0x6825a449, 0x7524, 0x4d82, 0x92, 0x0f, 0x50, 0xe3, 0x6a, 0xb3, 0xab, 0x1e);

const GUID IID_IDirectSoundBuffer8 = { 0x6825a449, 0x7524, 0x4d82, 0x92, 0x0f, 0x50, 0xe3, 0x6a, 0xb3, 0xab, 0x1e };

typedef struct _DSBCAPS
{
    DWORD           dwSize;
    DWORD           dwFlags;
    DWORD           dwBufferBytes;
    DWORD           dwUnlockTransferRate;
    DWORD           dwPlayCpuOverhead;
} DSBCAPS, * LPDSBCAPS;

typedef struct _DSBUFFERDESC
{
    DWORD           dwSize;
    DWORD           dwFlags;
    DWORD           dwBufferBytes;
    DWORD           dwReserved;
    LPWAVEFORMATEX  lpwfxFormat;
#if DIRECTSOUND_VERSION >= 0x0700
    GUID            guid3DAlgorithm;
#endif
} DSBUFFERDESC, * LPDSBUFFERDESC;

typedef const DSBUFFERDESC* LPCDSBUFFERDESC;

typedef struct _DSCAPS
{
    DWORD           dwSize;
    DWORD           dwFlags;
    DWORD           dwMinSecondarySampleRate;
    DWORD           dwMaxSecondarySampleRate;
    DWORD           dwPrimaryBuffers;
    DWORD           dwMaxHwMixingAllBuffers;
    DWORD           dwMaxHwMixingStaticBuffers;
    DWORD           dwMaxHwMixingStreamingBuffers;
    DWORD           dwFreeHwMixingAllBuffers;
    DWORD           dwFreeHwMixingStaticBuffers;
    DWORD           dwFreeHwMixingStreamingBuffers;
    DWORD           dwMaxHw3DAllBuffers;
    DWORD           dwMaxHw3DStaticBuffers;
    DWORD           dwMaxHw3DStreamingBuffers;
    DWORD           dwFreeHw3DAllBuffers;
    DWORD           dwFreeHw3DStaticBuffers;
    DWORD           dwFreeHw3DStreamingBuffers;
    DWORD           dwTotalHwMemBytes;
    DWORD           dwFreeHwMemBytes;
    DWORD           dwMaxContigFreeHwMemBytes;
    DWORD           dwUnlockTransferRateHwBuffers;
    DWORD           dwPlayCpuOverheadSwBuffers;
    DWORD           dwReserved1;
    DWORD           dwReserved2;
} DSCAPS, * LPDSCAPS;

typedef struct _DSEFFECTDESC
{
    DWORD       dwSize;
    DWORD       dwFlags;
    GUID        guidDSFXClass;
    DWORD_PTR   dwReserved1;
    DWORD_PTR   dwReserved2;
} DSEFFECTDESC, * LPDSEFFECTDESC;

typedef const DSEFFECTDESC* LPCDSEFFECTDESC;

DECLARE_INTERFACE_(IDirectSound, IUnknown)
{
    // IUnknown methods
    STDMETHOD(QueryInterface)       (THIS_ _In_ REFIID, _Outptr_ LPVOID*) PURE;
    STDMETHOD_(ULONG, AddRef)        (THIS) PURE;
    STDMETHOD_(ULONG, Release)       (THIS) PURE;

    // IDirectSound methods
    STDMETHOD(CreateSoundBuffer)    (THIS_ _In_ LPCDSBUFFERDESC pcDSBufferDesc, _Outptr_ LPDIRECTSOUNDBUFFER * ppDSBuffer, _Pre_null_ LPUNKNOWN pUnkOuter) PURE;
    STDMETHOD(GetCaps)              (THIS_ _Out_ LPDSCAPS pDSCaps) PURE;
    STDMETHOD(DuplicateSoundBuffer) (THIS_ _In_ LPDIRECTSOUNDBUFFER pDSBufferOriginal, _Outptr_ LPDIRECTSOUNDBUFFER * ppDSBufferDuplicate) PURE;
    STDMETHOD(SetCooperativeLevel)  (THIS_ HWND hwnd, DWORD dwLevel) PURE;
    STDMETHOD(Compact)              (THIS) PURE;
    STDMETHOD(GetSpeakerConfig)     (THIS_ _Out_ LPDWORD pdwSpeakerConfig) PURE;
    STDMETHOD(SetSpeakerConfig)     (THIS_ DWORD dwSpeakerConfig) PURE;
    STDMETHOD(Initialize)           (THIS_ _In_opt_ LPCGUID pcGuidDevice) PURE;
};

DECLARE_INTERFACE_(IDirectSound8, IDirectSound)
{
    // IUnknown methods
    STDMETHOD(QueryInterface)       (THIS_ _In_ REFIID, _Outptr_ LPVOID*) PURE;
    STDMETHOD_(ULONG, AddRef)        (THIS) PURE;
    STDMETHOD_(ULONG, Release)       (THIS) PURE;

    // IDirectSound methods
    STDMETHOD(CreateSoundBuffer)    (THIS_ _In_ LPCDSBUFFERDESC pcDSBufferDesc, _Out_ LPDIRECTSOUNDBUFFER * ppDSBuffer, _Pre_null_ LPUNKNOWN pUnkOuter) PURE;
    STDMETHOD(GetCaps)              (THIS_ _Out_ LPDSCAPS pDSCaps) PURE;
    STDMETHOD(DuplicateSoundBuffer) (THIS_ _In_ LPDIRECTSOUNDBUFFER pDSBufferOriginal, _Out_ LPDIRECTSOUNDBUFFER * ppDSBufferDuplicate) PURE;
    STDMETHOD(SetCooperativeLevel)  (THIS_ HWND hwnd, DWORD dwLevel) PURE;
    STDMETHOD(Compact)              (THIS) PURE;
    STDMETHOD(GetSpeakerConfig)     (THIS_ _Out_ LPDWORD pdwSpeakerConfig) PURE;
    STDMETHOD(SetSpeakerConfig)     (THIS_ DWORD dwSpeakerConfig) PURE;
    STDMETHOD(Initialize)           (THIS_ _In_opt_ LPCGUID pcGuidDevice) PURE;

    // IDirectSound8 methods
    STDMETHOD(VerifyCertification)  (THIS_ _Out_ LPDWORD pdwCertified) PURE;
};

DECLARE_INTERFACE_(IDirectSoundBuffer, IUnknown)
{
    // IUnknown methods
    STDMETHOD(QueryInterface)       (THIS_ _In_ REFIID, _Outptr_ LPVOID*) PURE;
    STDMETHOD_(ULONG, AddRef)        (THIS) PURE;
    STDMETHOD_(ULONG, Release)       (THIS) PURE;

    // IDirectSoundBuffer methods
    STDMETHOD(GetCaps)              (THIS_ _Out_ LPDSBCAPS pDSBufferCaps) PURE;
    STDMETHOD(GetCurrentPosition)   (THIS_ _Out_opt_ LPDWORD pdwCurrentPlayCursor, _Out_opt_ LPDWORD pdwCurrentWriteCursor) PURE;
    STDMETHOD(GetFormat)            (THIS_ _Out_writes_bytes_opt_(dwSizeAllocated) LPWAVEFORMATEX pwfxFormat, DWORD dwSizeAllocated, _Out_opt_ LPDWORD pdwSizeWritten) PURE;
    STDMETHOD(GetVolume)            (THIS_ _Out_ LPLONG plVolume) PURE;
    STDMETHOD(GetPan)               (THIS_ _Out_ LPLONG plPan) PURE;
    STDMETHOD(GetFrequency)         (THIS_ _Out_ LPDWORD pdwFrequency) PURE;
    STDMETHOD(GetStatus)            (THIS_ _Out_ LPDWORD pdwStatus) PURE;
    STDMETHOD(Initialize)           (THIS_ _In_ LPDIRECTSOUND pDirectSound, _In_ LPCDSBUFFERDESC pcDSBufferDesc) PURE;
    STDMETHOD(Lock)                 (THIS_ DWORD dwOffset, DWORD dwBytes,
        _Outptr_result_bytebuffer_(*pdwAudioBytes1) LPVOID * ppvAudioPtr1, _Out_ LPDWORD pdwAudioBytes1,
        _Outptr_opt_result_bytebuffer_(*pdwAudioBytes2) LPVOID * ppvAudioPtr2, _Out_opt_ LPDWORD pdwAudioBytes2, DWORD dwFlags) PURE;
    STDMETHOD(Play)                 (THIS_ DWORD dwReserved1, DWORD dwPriority, DWORD dwFlags) PURE;
    STDMETHOD(SetCurrentPosition)   (THIS_ DWORD dwNewPosition) PURE;
    STDMETHOD(SetFormat)            (THIS_ _In_ LPCWAVEFORMATEX pcfxFormat) PURE;
    STDMETHOD(SetVolume)            (THIS_ LONG lVolume) PURE;
    STDMETHOD(SetPan)               (THIS_ LONG lPan) PURE;
    STDMETHOD(SetFrequency)         (THIS_ DWORD dwFrequency) PURE;
    STDMETHOD(Stop)                 (THIS) PURE;
    STDMETHOD(Unlock)               (THIS_ _In_reads_bytes_(dwAudioBytes1) LPVOID pvAudioPtr1, DWORD dwAudioBytes1,
        _In_reads_bytes_opt_(dwAudioBytes2) LPVOID pvAudioPtr2, DWORD dwAudioBytes2) PURE;
    STDMETHOD(Restore)              (THIS) PURE;
};

DECLARE_INTERFACE_(IDirectSoundBuffer8, IDirectSoundBuffer)
{
    // IUnknown methods
    STDMETHOD(QueryInterface)       (THIS_ _In_ REFIID, _Outptr_ LPVOID*) PURE;
    STDMETHOD_(ULONG, AddRef)        (THIS) PURE;
    STDMETHOD_(ULONG, Release)       (THIS) PURE;

    // IDirectSoundBuffer methods
    STDMETHOD(GetCaps)              (THIS_ _Out_ LPDSBCAPS pDSBufferCaps) PURE;
    STDMETHOD(GetCurrentPosition)   (THIS_ _Out_opt_ LPDWORD pdwCurrentPlayCursor, _Out_opt_ LPDWORD pdwCurrentWriteCursor) PURE;
    STDMETHOD(GetFormat)            (THIS_ _Out_writes_bytes_opt_(dwSizeAllocated) LPWAVEFORMATEX pwfxFormat, DWORD dwSizeAllocated, _Out_opt_ LPDWORD pdwSizeWritten) PURE;
    STDMETHOD(GetVolume)            (THIS_ _Out_ LPLONG plVolume) PURE;
    STDMETHOD(GetPan)               (THIS_ _Out_ LPLONG plPan) PURE;
    STDMETHOD(GetFrequency)         (THIS_ _Out_ LPDWORD pdwFrequency) PURE;
    STDMETHOD(GetStatus)            (THIS_ _Out_ LPDWORD pdwStatus) PURE;
    STDMETHOD(Initialize)           (THIS_ _In_ LPDIRECTSOUND pDirectSound, _In_ LPCDSBUFFERDESC pcDSBufferDesc) PURE;
    STDMETHOD(Lock)                 (THIS_ DWORD dwOffset, DWORD dwBytes,
        _Outptr_result_bytebuffer_(*pdwAudioBytes1) LPVOID * ppvAudioPtr1, _Out_ LPDWORD pdwAudioBytes1,
        _Outptr_opt_result_bytebuffer_(*pdwAudioBytes2) LPVOID * ppvAudioPtr2, _Out_opt_ LPDWORD pdwAudioBytes2, DWORD dwFlags) PURE;
    STDMETHOD(Play)                 (THIS_ DWORD dwReserved1, DWORD dwPriority, DWORD dwFlags) PURE;
    STDMETHOD(SetCurrentPosition)   (THIS_ DWORD dwNewPosition) PURE;
    STDMETHOD(SetFormat)            (THIS_ _In_ LPCWAVEFORMATEX pcfxFormat) PURE;
    STDMETHOD(SetVolume)            (THIS_ LONG lVolume) PURE;
    STDMETHOD(SetPan)               (THIS_ LONG lPan) PURE;
    STDMETHOD(SetFrequency)         (THIS_ DWORD dwFrequency) PURE;
    STDMETHOD(Stop)                 (THIS) PURE;
    STDMETHOD(Unlock)               (THIS_ _In_reads_bytes_(dwAudioBytes1) LPVOID pvAudioPtr1, DWORD dwAudioBytes1,
        _In_reads_bytes_opt_(dwAudioBytes2) LPVOID pvAudioPtr2, DWORD dwAudioBytes2) PURE;
    STDMETHOD(Restore)              (THIS) PURE;

    // IDirectSoundBuffer8 methods
    STDMETHOD(SetFX)                (THIS_ DWORD dwEffectsCount, _In_reads_opt_(dwEffectsCount) LPDSEFFECTDESC pDSFXDesc, _Out_writes_opt_(dwEffectsCount) LPDWORD pdwResultCodes) PURE;
    STDMETHOD(AcquireResources)     (THIS_ DWORD dwFlags, DWORD dwEffectsCount, _Out_writes_(dwEffectsCount) LPDWORD pdwResultCodes) PURE;
    STDMETHOD(GetObjectInPath)      (THIS_ _In_ REFGUID rguidObject, DWORD dwIndex, _In_ REFGUID rguidInterface, _Outptr_ LPVOID * ppObject) PURE;
};

typedef HRESULT(WINAPI* PFNDirectSoundCreate8)(_In_opt_ LPCGUID pcGuidDevice, _Outptr_ LPDIRECTSOUND8* ppDS8, _Pre_null_ LPUNKNOWN pUnkOuter);

extern PFNDirectSoundCreate8 DirectSoundCreate8;

#endif  
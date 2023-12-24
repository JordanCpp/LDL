
typedef struct _GUID
{
    unsigned long  Data1;
    unsigned short Data2;
    unsigned short Data3;
    unsigned char  Data4[8];
} GUID;

typedef GUID IID;
typedef GUID* LPGUID;

typedef char CHAR;
typedef CHAR* LPSTR;

typedef float FLOAT;

typedef unsigned char BYTE;

typedef unsigned short      WORD;
typedef unsigned long DWORD;
typedef unsigned long HRESULT;
typedef long LONG;
typedef double LONGLONG;
typedef unsigned long ULONG;
typedef int BOOL;

typedef BOOL* LPBOOL;
typedef DWORD * LPDWORD;
typedef void* LPVOID;
typedef long * LPLONG;
typedef WORD * LPWORD;

typedef void* HWND;
typedef void* HANDLE;
typedef void* HDC;

typedef struct tagRECT
{
    LONG    left;
    LONG    top;
    LONG    right;
    LONG    bottom;
} RECT, * PRECT, * NPRECT, * LPRECT;

typedef struct _RGNDATAHEADER {
    DWORD   dwSize;
    DWORD   iType;
    DWORD   nCount;
    DWORD   nRgnSize;
    RECT    rcBound;
} RGNDATAHEADER, * PRGNDATAHEADER;

typedef struct _RGNDATA {
    RGNDATAHEADER   rdh;
    char            Buffer[1];
} RGNDATA, * PRGNDATA, * NPRGNDATA, * LPRGNDATA;

struct IUnknown
{
public:
    virtual HRESULT LDL_CALL QueryInterface(const IID& riid, void** ppvObject) = 0;
    virtual ULONG LDL_CALL AddRef(void) = 0;
    virtual ULONG LDL_CALL Release(void) = 0;
};

typedef /* [unique] */ IUnknown* LPUNKNOWN;

//
// Success codes
//
const HRESULT S_OK    = ((HRESULT)0L);
const HRESULT S_FALSE = ((HRESULT)1L);

const HRESULT E_INVALIDARG  = (HRESULT)(0x80070057L);
const HRESULT E_OUTOFMEMORY = (HRESULT)(0x8007000EL);
const HRESULT E_NOTIMPL     = (HRESULT)(0x80004001L);
const HRESULT E_FAIL        = (HRESULT)(0x80004005L);

const HRESULT CO_E_NOTINITIALIZED = (HRESULT)(0x800401F0L);

typedef union _LARGE_INTEGER {
    struct {
        DWORD LowPart;
        LONG HighPart;
    } DUMMYSTRUCTNAME;
    struct {
        DWORD LowPart;
        LONG HighPart;
    } u;
    LONGLONG QuadPart;
} LARGE_INTEGER;

typedef struct tagPALETTEENTRY {
    BYTE        peRed;
    BYTE        peGreen;
    BYTE        peBlue;
    BYTE        peFlags;
} PALETTEENTRY, * PPALETTEENTRY, * LPPALETTEENTRY;

inline HRESULT MAKE_HRESULT(DWORD sev, DWORD fac, DWORD code)
{
    return ((HRESULT)(((DWORD)(sev) << 31) | ((DWORD)(fac) << 16) | ((DWORD)(code))));
}

inline bool SUCCEEDED(HRESULT hr)
{
    return hr >= 0;
}

inline bool FAILED(HRESULT hr)
{
    return hr < 0;
}

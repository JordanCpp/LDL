#include "DirectX9.hpp"

PFNDirectSoundCreate8 DirectSoundCreate8 = NULL;
PFNDirect3DCreate9    Direct3DCreate9    = NULL;

const GUID GUID_NULL = { 0, 0, 0, { 0, 0, 0, 0, 0, 0, 0, 0 } };
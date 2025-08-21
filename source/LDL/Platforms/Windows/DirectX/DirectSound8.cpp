#include "DirectSound8.hpp"

PFNDirectSoundCreate8 DirectSoundCreate8 = NULL;

const GUID GUID_NULL = { 0, 0, 0, { 0, 0, 0, 0, 0, 0, 0, 0 } };

#include <LDL/Loaders/SoundLoader.hpp>
#include "../dependencies/stb/stb_vorbis.c"

using namespace LDL::Loaders;
using namespace LDL::Allocators;

SoundLoader::SoundLoader(LDL::Allocators::Allocator* allocator) :
    _Allocator(allocator),
    _Channels(0),
    _Rate(0),
    _Samples(0),
    _Bytes(NULL)
{
}

SoundLoader::~SoundLoader()
{
}

void SoundLoader::Clear()
{
    _Allocator->Reset();

    _Channels = 0;
    _Rate     = 0;
    _Samples  = 0;
    _Bytes    = NULL;
}

bool SoundLoader::LoadOgg(const std::string& path)
{
    Clear();

    int error = 0;

    stb_vorbis* file = stb_vorbis_open_filename((path.c_str()), &error, NULL);

    if (!file)
        return false;

    stb_vorbis_info info = stb_vorbis_get_info(file);

    _Channels = info.channels;
    _Rate     = info.sample_rate;
    _Samples  = stb_vorbis_stream_length_in_samples(file) * info.channels;
    _Bytes    = (uint8_t*)_Allocator->Allocate(_Samples);

    stb_vorbis_get_samples_short_interleaved(file, (int)info.channels, (short*)_Bytes, (int)_Samples);

    stb_vorbis_close(file);

    return true;
}

bool SoundLoader::Load(const std::string& path)
{
    return LoadOgg(path);
}

Allocator* SoundLoader::Allocator()
{
    return _Allocator;
}

size_t SoundLoader::Channels()
{
    return _Channels;
}

size_t SoundLoader::Rate()
{
    return _Rate;
}

size_t SoundLoader::Samples()
{
    return _Samples;
}

uint8_t* SoundLoader::Bytes()
{
    return _Bytes;
}
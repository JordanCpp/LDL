// Copyright 2023-present Evgeny Zoshchuk (JordanCpp).
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at
// https://www.boost.org/LICENSE_1_0.txt)

#include <LDL/Loaders/SoundLoader.hpp>

#if defined(__BORLANDC__)
#include <malloc.h>
#include <cstdlib>
#define qsort std::qsort
#endif
#include "../dependencies/stb/stb_vorbis.c"

#define DR_WAV_IMPLEMENTATION
#include "../dependencies/dr_libs/dr_wav.h"

#define DR_FLAC_IMPLEMENTATION
#include "../dependencies/dr_libs/dr_flac.h"

#define DR_MP3_IMPLEMENTATION
#include "../dependencies/dr_libs/dr_mp3.h"

using namespace LDL::Loaders;
using namespace LDL::Allocators;

SoundLoader::SoundLoader(LDL::Allocators::Allocator* allocator) :
    _allocator(allocator),
    _channels(0),
    _rate(0),
    _samples(0),
    _bytes(NULL)
{
}

SoundLoader::~SoundLoader()
{
}

void SoundLoader::Clear()
{
    _allocator->Reset();

    _channels = 0;
    _rate     = 0;
    _samples  = 0;
    _bytes    = NULL;
}

bool SoundLoader::LoadOgg(const std::string& path)
{
    Clear();

    int error = 0;

    stb_vorbis* file = stb_vorbis_open_filename((path.c_str()), &error, NULL);

    if (!file)
        return false;

    stb_vorbis_info info = stb_vorbis_get_info(file);

    _channels = info.channels;
    _rate     = info.sample_rate;
    _samples  = stb_vorbis_stream_length_in_samples(file) * info.channels;
    _bytes    = (uint8_t*)_allocator->Allocate(_samples);

    stb_vorbis_get_samples_short_interleaved(file, (int)info.channels, (short*)_bytes, (int)_samples);

    stb_vorbis_close(file);

    return true;
}

bool SoundLoader::LoadWav(const std::string& path)
{
    unsigned int channels        = 0;
    unsigned int sampleRate      = 0;
    drwav_uint64 totalFrameCount = 0;

    float* data = drwav_open_file_and_read_pcm_frames_f32(path.c_str(), &channels, &sampleRate, &totalFrameCount, NULL);

    if (data != NULL)
    {
        _channels = channels;
        _rate     = sampleRate;
        _samples  = (size_t)totalFrameCount;
        _bytes    = (uint8_t*)data;

        return true;
    }

    return false;
}

bool SoundLoader::LoadMp3(const std::string& path)
{
    drmp3_config config;
    drmp3_uint64 totalFrameCount;

    float* data = drmp3_open_file_and_read_pcm_frames_f32(path.c_str(), &config, &totalFrameCount, NULL);

    _channels = config.channels;
    _rate     = config.sampleRate;
    _samples  = (size_t)totalFrameCount;
    _bytes    = (uint8_t*)data;

    return true;
}

bool SoundLoader::LoadFlac(const std::string& path)
{
    return false;
}

bool SoundLoader::Load(const std::string& path)
{
    return LoadOgg(path);
}

Allocator* SoundLoader::Allocator()
{
    return _allocator;
}

size_t SoundLoader::Channels()
{
    return _channels;
}

size_t SoundLoader::Rate()
{
    return _rate;
}

size_t SoundLoader::Samples()
{
    return _samples;
}

uint8_t* SoundLoader::Bytes()
{
    return _bytes;
}

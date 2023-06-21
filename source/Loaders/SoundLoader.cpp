#include <LDL/Loaders/SoundLoader.hpp>
#include "../dependencies/stb/stb_vorbis.c"

#define DR_WAV_IMPLEMENTATION
#include "../dependencies/dr_libs/dr_wav.h"

#define DR_FLAC_IMPLEMENTATION
#include "../dependencies/dr_libs/dr_flac.h"

#define DR_MP3_IMPLEMENTATION
#include "../dependencies/dr_libs/dr_mp3.h"

using namespace LDL::Loaders;
using namespace LDL::Allocators;

struct WaveHeaderType
{
    char chunkId[4];
    unsigned long chunkSize;
    char format[4];
    char subChunkId[4];
    unsigned long subChunkSize;
    unsigned short audioFormat;
    unsigned short numChannels;
    unsigned long sampleRate;
    unsigned long bytesPerSecond;
    unsigned short blockAlign;
    unsigned short bitsPerSample;
    char dataChunkId[4];
    unsigned long dataSize;
};

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

bool SoundLoader::LoadWav(const std::string& path)
{
    unsigned int channels = 0;
    unsigned int sampleRate = 0;
    drwav_uint64 totalPCMFrameCount = 0;

    float* data = drwav_open_file_and_read_pcm_frames_f32(path.c_str(), &channels, &sampleRate, &totalPCMFrameCount, NULL);

    if (data != NULL)
    {
        _Channels = channels;
        _Rate = sampleRate;
        _Samples = totalPCMFrameCount;
        _Bytes = (uint8_t*)data;

        return true;
        //drwav_free(data, NULL);
    }

    return false;
}

bool SoundLoader::LoadMp3(const std::string& path)
{
    int error;
    FILE* filePtr;
    unsigned int count;
    WaveHeaderType waveFileHeader;
    unsigned char* waveData;
    unsigned char* bufferPtr;
    unsigned long bufferSize;

    error = fopen_s(&filePtr, path.c_str(), "rb");
    if (error != 0)
    {
        return false;
    }

    // Read in the wave file header.
    count = fread(&waveFileHeader, sizeof(waveFileHeader), 1, filePtr);
    if (count != 1)
    {
        return false;
    }

    // Check that the chunk ID is the RIFF format.
    if ((waveFileHeader.chunkId[0] != 'R') || (waveFileHeader.chunkId[1] != 'I') ||
        (waveFileHeader.chunkId[2] != 'F') || (waveFileHeader.chunkId[3] != 'F'))
    {
        return false;
    }

    // Check that the file format is the WAVE format.
    if ((waveFileHeader.format[0] != 'W') || (waveFileHeader.format[1] != 'A') ||
        (waveFileHeader.format[2] != 'V') || (waveFileHeader.format[3] != 'E'))
    {
        return false;
    }

    // Check that the sub chunk ID is the fmt format.
    if ((waveFileHeader.subChunkId[0] != 'f') || (waveFileHeader.subChunkId[1] != 'm') ||
        (waveFileHeader.subChunkId[2] != 't') || (waveFileHeader.subChunkId[3] != ' '))
    {
        return false;
    }

    // Check that the audio format is WAVE_FORMAT_PCM.
    if (waveFileHeader.audioFormat != 1)
    {
        return false;
    }

    // Check that the wave file was recorded in stereo format.
    if (waveFileHeader.numChannels != 2)
    {
        return false;
    }

    // Check that the wave file was recorded at a sample rate of 44.1 KHz.
    if (waveFileHeader.sampleRate != 44100)
    {
        return false;
    }

    // Ensure that the wave file was recorded in 16 bit format.
    if (waveFileHeader.bitsPerSample != 16)
    {
        return false;
    }

    // Check for the data chunk header.
    if ((waveFileHeader.dataChunkId[0] != 'd') || (waveFileHeader.dataChunkId[1] != 'a') ||
        (waveFileHeader.dataChunkId[2] != 't') || (waveFileHeader.dataChunkId[3] != 'a'))
    {
        return false;
    }

    // Move to the beginning of the wave data which starts at the end of the data chunk header.
    fseek(filePtr, sizeof(WaveHeaderType), SEEK_SET);

    // Create a temporary buffer to hold the wave file data.
    waveData = new unsigned char[waveFileHeader.dataSize];
    if (!waveData)
    {
        return false;
    }

    // Read in the wave file data into the newly created buffer.
    count = fread(waveData, 1, waveFileHeader.dataSize, filePtr);
    if (count != waveFileHeader.dataSize)
    {
        return false;
    }

    // Close the file once done reading.
    error = fclose(filePtr);
    if (error != 0)
    {
        return false;
    }

    _Channels = 2;
    _Rate = 44100;
    _Samples = waveFileHeader.dataSize;
    _Bytes = (uint8_t*)&waveData;

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
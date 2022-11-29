#include <LDL/Creators/CoreCreator.hpp>
#include "../Platforms/Windows/Core/Directory.hpp"
#include <assert.h>

LDL::Core::IDirectory* LDL::Creators::CoreCreator::CreateDir()
{
	return new LDL::Core::Windows::Directory;
}

void LDL::Creators::CoreCreator::Destroy(LDL::Core::IDirectory* directory)
{
	assert(directory != NULL);

	delete directory;
}
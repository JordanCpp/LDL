#include "Formats.hpp"
#include <stdio.h>

int main()
{
	ArtFile* file = new ArtFile;
	ArtFrame* frame = new ArtFrame;

	printf("%d\n", file->Load("grsbse0c.ART"));

	file->Frame(frame);

	printf("%d\n", frame->_Header.size);

	return 0;
}
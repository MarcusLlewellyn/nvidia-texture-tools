// Copyright NVIDIA Corporation 2007 -- Ignacio Castaño <icastano@nvidia.com>
// 
// Permission is hereby granted, free of charge, to any person
// obtaining a copy of this software and associated documentation
// files (the "Software"), to deal in the Software without
// restriction, including without limitation the rights to use,
// copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the
// Software is furnished to do so, subject to the following
// conditions:
// 
// The above copyright notice and this permission notice shall be
// included in all copies or substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
// EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
// OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
// NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
// HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
// WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
// OTHER DEALINGS IN THE SOFTWARE.

#include <nvcore/StrLib.h>
#include <nvcore/StdStream.h>

#include <nvimage/Image.h>
#include <nvimage/DirectDrawSurface.h>

#include "cmdline.h"


int main(int argc, char *argv[])
{
	MyAssertHandler assertHandler;
	MyMessageHandler messageHandler;

	if (argc != 2)
	{
		printf("NVIDIA Texture Tools - Copyright NVIDIA Corporation 2007\n\n");
		printf("usage: nvddsinfo ddsfile\n\n");
		return 1;
	}

	// Load surface.
	nv::DirectDrawSurface dds;
    if (!dds.load(argv[1]) || !dds.isValid())
	{
		printf("The file '%s' is not a valid DDS file.\n", argv[1]);
		return 1;
	}
	
	dds.printInfo();

	return 0;
}


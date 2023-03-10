// -*- mode: C++; tab-width: 4 -*-
// vi: ts=4

/*
 * Copyright (c) 2010, Patrick A. Palmer and Leszek Godlewski.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *   - Redistributions of source code must retain the above copyright notice,
 *     this list of conditions and the following disclaimer.
 *
 *   - Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 *
 *   - Neither the name of Patrick A. Palmer nor the names of its
 *     contributors may be used to endorse or promote products derived from
 *     this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#include <cineon.imageio/Cineon.h>
#include <cineon.imageio/Codec.h>
#include <cineon.imageio/ElementReadStream.h>
#include <cineon.imageio/ReaderInternal.h>




cineon::Codec::Codec() : scanline(0)
{
}


cineon::Codec::~Codec()
{
	if (this->scanline)
		delete [] scanline;
}


void cineon::Codec::Reset()
{
	if (this->scanline)
	{
		delete [] scanline;
		this->scanline = 0;
	}
}


bool cineon::Codec::Read(const Header &dpxHeader, ElementReadStream *fd, const Block &block, void *data, const DataSize size)
{
	// scanline buffer
	if (this->scanline == 0)
	{
		// FIXME: make this flexible enough to change per-channel differences!

		// get the number of components for this element descriptor
		const int numberOfComponents = dpxHeader.NumberOfElements();

		// bit depth of the image element
		const int bitDepth = dpxHeader.BitDepth(0);

		// size of the scanline buffer is image width * number of components * bytes per component
		int slsize = ((numberOfComponents * dpxHeader.Width() *
					  (bitDepth / 8 + (bitDepth % 8 ? 1 : 0))) / sizeof(U32))+1;

		this->scanline = new U32[slsize];
	}


	// read the image block
	return ReadImageBlock<ElementReadStream>(dpxHeader, this->scanline, fd, block, data, size);
}


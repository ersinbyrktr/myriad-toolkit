/*
 * Copyright 2010-2011 DIMA Research Group, TU Berlin
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 * @author: Alexander Alexandrov <alexander.alexandrov@tu-berlin.de>
 */

#include "RNG.h"
#include "CompoundEICG.h"
#include "HashRandomStream.h"

namespace Myriad {

// init periods method
CompoundEICG::Seed compoundEICGInitPeriods()
{
    CompoundEICG::Seed tmp;

    // [ 2147483647, 2147483629, 2147483587, 2147483579, 2147483563, 2147483549 ]
    tmp.v[0] = 2147483647;
    tmp.v[1] = 2147483629;
    tmp.v[2] = 2147483587;
    tmp.v[3] = 2147483579;
    tmp.v[4] = 2147483563;
    tmp.v[5] = 2147483549;

    return tmp;
}

CompoundEICG::Seed compoundEICGInitSubstreamOffset()
{
    CompoundEICG::Seed tmp;

    // [ 1073741824, 1073745244, 1073855284, 1073906044, 1074048844, 1074226924 ] = 4951760157141521099596496896 = 2^94
    tmp.v[0] = 1073741824;
    tmp.v[1] = 1073745244;
    tmp.v[2] = 1073855284;
    tmp.v[3] = 1073906044;
    tmp.v[4] = 1074048844;
    tmp.v[5] = 1074226924;

    return tmp;
}

CompoundEICG::Seed compoundEICGInitChunkOffset()
{
    CompoundEICG::Seed tmp;

    // [ 1073741824, 1073741824, 1073741824, 1073741824, 1073741824, 1073741824 ] = 1073741824 = 2^30
    tmp.v[0] = 1073741824;
    tmp.v[1] = 1073741824;
    tmp.v[2] = 1073741824;
    tmp.v[3] = 1073741824;
    tmp.v[4] = 1073741824;
    tmp.v[5] = 1073741824;

    return tmp;
}

CompoundEICG::Seed compoundEICGInitElementOffset()
{
    CompoundEICG::Seed tmp;

    // [ 1, 1, 1, 1, 1, 1 ] = 1
    tmp.v[0] = 1;
    tmp.v[1] = 1;
    tmp.v[2] = 1;
    tmp.v[3] = 1;
    tmp.v[4] = 1;
    tmp.v[5] = 1;

    return tmp;
}

HashRandomStream::Seed hashRandomStreamInitSubstreamOffset()
{
    HashRandomStream::Seed tmp;

    // 281474976710656 = 2^48
    tmp.v[0] = 281474976710656ULL;

    return tmp;
}

HashRandomStream::Seed hashRandomStreamInitChunkOffset()
{
    HashRandomStream::Seed tmp;

    // 256 = 2^8
    tmp.v[0] = 256ULL;

    return tmp;
}

HashRandomStream::Seed hashRandomStreamInitElementOffset()
{
    HashRandomStream::Seed tmp;

    // 1 = 2^0
    tmp.v[0] = 1ULL;

    return tmp;
}

// set periods for the EICG components
const CompoundEICG::Seed CompoundEICG::PERIOD(compoundEICGInitPeriods());
const CompoundEICG::Seed CompoundEICG::OFFSET_SUBSTREAM(compoundEICGInitSubstreamOffset());
const CompoundEICG::Seed CompoundEICG::OFFSET_CHUNK(compoundEICGInitChunkOffset());
const CompoundEICG::Seed CompoundEICG::OFFSET_ELEMENT(compoundEICGInitElementOffset());

// set periods for the HashRandomStream
const HashRandomStream::Seed HashRandomStream::OFFSET_SUBSTREAM(hashRandomStreamInitSubstreamOffset());
const HashRandomStream::Seed HashRandomStream::OFFSET_CHUNK(hashRandomStreamInitChunkOffset());
const HashRandomStream::Seed HashRandomStream::OFFSET_ELEMENT(hashRandomStreamInitElementOffset());
const double HashRandomStream::D_2_POW_NEG_64 = 5.4210108624275221700e-20;

//const CompoundEICG::SeedBitmap CompoundEICG::BITMAP_SUBSTREAM = 0x03;
//const CompoundEICG::SeedBitmap CompoundEICG::BITMAP_CHUNK = 0x0C;
//const CompoundEICG::SeedBitmap CompoundEICG::BITMAP_ELEMENT = 0x30;
//const CompoundEICG::SeedBitmap CompoundEICG::BITMAP_ALL = 0x3F;
//const CompoundEICG::SeedBitmap CompoundEICG::BITMAP_NONE = 0x00;

}  // namespace Myriad

#ifndef BITMAPINFOHEADER_H_
#define BITMAPINFOHEADER_H_
#include<cstdint>

using namespace std;
#pragma pack(push,2)
namespace caveofprogramming
{
  struct BitmapInfoHeader
  {
    int32_t headerSize{40};//Header Size-Must be at least 40
    int32_t width;//Image width in pixels
    int32_t height;//Image height in pixels
    int16_t planes{1};//Must be 1;
    int16_t bitsPerPixel{24};//depends on number of colors - 1, 4, 8,16, 24, or 32
    int32_t compression{0};//no compression
    int32_t dataSize{0};//Image Size-may be zero for uncompressed images
    int32_t horizontalResolution{2400};//Preferred resolution in pixels per meter
    int32_t verticalResolution{2400};
    int32_t colors{0};//Number color Map entries that actually used
    int32_t importantColors{0};//Number of significant colors
  };
}
#pragma pack(pop);
#endif/*BITMAPINFOHEADER_H_*/

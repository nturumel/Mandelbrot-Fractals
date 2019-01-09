#ifndef BITMAPHEADER_H_
#define BITMAPHEADER_H_
#include<cstdint>
using namespace std;
#pragma pack(push,2)
namespace caveofprogramming
{
  struct BitmapFileHeader
  {
    char header[2]{'B','M'};
    int32_t fileSize;
    int32_t reserved{0};
    int32_t dataOffset;
  };
}
#pragma pack(pop)
#endif

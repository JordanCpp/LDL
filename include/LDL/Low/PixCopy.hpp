#ifndef LDL_PixelCopier_hpp
#define LDL_PixelCopier_hpp

#include <LDL/Low/Surface.hpp>

class LDL_PixelCopier
{
public:
	void Draw(LDL_Surface& dst, const LDL_Point2u& pos, LDL_Surface& src);
private:
};

#endif

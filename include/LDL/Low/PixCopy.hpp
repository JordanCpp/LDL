#ifndef LDL_PixelCopier_hpp
#define LDL_PixelCopier_hpp

#include <LDL/Low/SoftSurf.hpp>

class LDL_PixelCopier
{
public:
	void Draw(LDL_ISurface* dst, const LDL_Point2u& pos, LDL_ISurface* src);
private:
};

#endif

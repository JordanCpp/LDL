#include <LDL/Text/RasterizerContext.hpp>
#include "RasterizerContextImpl.hpp"

using namespace LDL::Text;

RasterizerContext::RasterizerContext() :
	_RasterizerContextImpl(new RasterizerContextImpl)
{
}

RasterizerContext::~RasterizerContext()
{
	delete _RasterizerContextImpl;
}

RasterizerContextImpl* RasterizerContext::GetRasterizerContextImpl()
{
	return _RasterizerContextImpl;
}

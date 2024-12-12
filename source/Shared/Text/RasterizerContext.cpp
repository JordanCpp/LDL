#include <LDL/Text/RasterizerContext.hpp>
#include "RasterizerContextImpl.hpp"

using namespace LDL::Text;

RasterizerContext::RasterizerContext() :
	_impl(new RasterizerContextImpl)
{
}

RasterizerContext::~RasterizerContext()
{
	delete _impl;
}

RasterizerContextImpl* RasterizerContext::GetRasterizerContextImpl()
{
	return _impl;
}

#ifndef LDL_Core_RuntimeError_hpp
#define LDL_Core_RuntimeError_hpp

#include <stdexcept>

namespace LDL
{
    namespace Core
    {
        class RuntimeError: public std::runtime_error
        {
        public:
            RuntimeError(const std::string& message);
        private:
        };
    }
}

#endif
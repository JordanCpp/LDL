#ifndef LDL_Core_RuntimeError_hpp
#define LDL_Core_RuntimeError_hpp

#include <LDL/Config.hpp>
#include <string>

namespace LDL
{
    namespace Core
    {
        class LDL_EXPORT RuntimeError
        {
        public:
            RuntimeError(const std::string& message);
            const char* what() const;
        private:
            std::string _Message;
        };
    }
}

#endif
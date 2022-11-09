#ifndef LDL_Core_RuntimeError_hpp
#define LDL_Core_RuntimeError_hpp

#include <string>

namespace LDL
{
    namespace Core
    {
        class RuntimeError
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
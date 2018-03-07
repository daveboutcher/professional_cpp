#ifndef CDL_EXCEPTION_H_
#define CDL_EXCEPTION_H_

#include <stdexcept> 
namespace cdl {
class exception: public std::runtime_error {
public:
	explicit exception(const std::string& what_arg) : std::runtime_error(what_arg) {}
	explicit exception(const char* what_arg) : std::runtime_error(what_arg) {}
};

}

#endif /* CDL_EXCEPTION_H_ */

#include "nulldecorator.h"

template <class DECORATE=nulldecorator>
class Suite: DECORATE<Suite> {
    
    
};

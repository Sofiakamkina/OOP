#include "Operator.h"
#include "OperatorFactory.h"
#include <string>

template<typename T>
class OperatorTypeMaker : public IOperatorTypeMaker {
public:
    OperatorTypeMaker(const std::string &key) {
        OperatorFactory::Instance().registerOperationTypeMaker(key, this);
    }

    virtual Operator *Create() const {
        return new T();
    }
};

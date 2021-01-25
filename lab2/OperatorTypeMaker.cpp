template<typename T>
class OperatorTypeMaker : public IOperatorTypeMaker
{
public:
    OperatorTypeMaker(const std::string& key)
    {
        OperatorFactory::Instance().RegisterMaker(key, this);
    }

    virtual Operator* Create() const
    {
        return new T();
    }
};

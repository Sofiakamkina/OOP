class IOperatorTypeMaker
{
public:
    virtual Operator * Create() const = 0;
    virtual ~IOperatorTypeMaker() {}
};

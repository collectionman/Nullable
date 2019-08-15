template <typename ObjectType>
class Nullable {
public:
    Nullable(void) : _value(), _isSet(false) {}
    Nullable(ObjectType* value) : _value(value), _isSet(false) {}
    Nullable(const Nullable& nullable) : _value(nullable._value), _isSet(nullable._isSet) {}
    ~Nullable(void) { reset() ; }

    Nullable& operator = (const Nullable& nullable) {
        set(nullable._value) ;
        return *this ;
    }

    ObjectType operator = (ObjectType* value) {
        set(value) ;
        return *(_value) ;
    }

    ObjectType& operator * (void) {
        if (_isSet) return *(_value) ;
    }

    ObjectType* operator -> (void) {
        if (_isSet) return _value ;
    }

    bool operator == (const Nullable& nullable) const {
        return ((nullable._isSet && _isSet) && (*(nullable._value) == *(_value))) ;
    }

    bool operator == (const ObjectType& value) const {
        return (_isSet && (value == *(_value))) ;
    }

    friend bool operator == (const ObjectType& value, const Nullable& nullable) {
        return (nullable._isSet && (value == *(nullable._value))) ;
    }

    operator ObjectType() const {
        return get() ;
    }

    operator bool() const {
        return isSet() ;
    }

    friend void swap(Nullable& a, Nullable& b) {
        using std::swap ;
        swap(a._isSet, b._isSet) ;
        swap(a._value, b._value) ;
    }

private:
    ObjectType* _value ;
    bool _isSet ;

    void set(ObjectType* value) {
        _value = value ;
        _isSet = true ;
    }

    ObjectType get() const {
        if (_isSet) return *(_value) ;
        throw std::logic_error("Value of nullable is not set.") ;
    }

    void reset() {
        _isSet = false ;
        _value = new ObjectType() ;
    }

    bool isSet(void) const {
        return _isSet ;
    }
} ;
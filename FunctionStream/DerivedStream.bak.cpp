
class FStream {

public:
    FStream();
    ~FStream();
};


FStream::FStream() {
}


FStream::~FStream() {
}



class DerivedFStream : FStream {
public:
    DerivedFStream();
    ~DerivedFStream();
    static DerivedFStream& my_endl(DerivedFStream& dfs);
    DerivedFStream& operator<<(DerivedFStream& (*m)(DerivedFStream&));
};


DerivedFStream::DerivedFStream() : FStream() {
}


DerivedFStream::~DerivedFStream() {
}

DerivedFStream& DerivedFStream::my_endl(DerivedFStream& dfs) {

return dfs;
};

DerivedFStream& DerivedFStream::operator<<(DerivedFStream& (*m)(DerivedFStream&)) {
    return (*m)(*this);
};


int main() {
    DerivedFStream f = DerivedFStream();
    DerivedFStream& rf = f;

    rf << DerivedFStream::my_endl;

    return 0;
};

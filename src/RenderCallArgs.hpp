#include <string>

enum RENDER_CALL_ARGUMENT_TYPES{
    BOOL,
    INT,
    FLOAT,
    VEC2,
    VEC3,
    VEC4,
    MAT4,
    SAMPLER
};  

class RenderCallArgs{
    public:

    RENDER_CALL_ARGUMENT_TYPES argument_type;
    std::string name;
    void * data;
    RenderCallArgs(std::string name, RENDER_CALL_ARGUMENT_TYPES type, void * data);
};
#include "RenderCall.hpp"

void RenderCall::call(){
    std::list<RenderCallArgs*>::iterator it;
    for(it = uniform_arguments.begin(); it != uniform_arguments.end(); ++it){
        RenderCallArgs* argument = (*it);
        switch((*it)->argument_type){
            case BOOL:
                shader.setBool(argument->name, *((bool*)argument->data));
                break;
            case INT:
                shader.setInt(argument->name, *((int*)argument->data));
                break;
            case FLOAT:
                shader.setFloat(argument->name, *((float*)argument->data));
                break;
            case VEC2:
                shader.setVec2(argument->name, (double*)argument->data);
                break;
            case VEC3:
                shader.setVec3(argument->name, (double*)argument->data);
                break;
            case VEC4:
                shader.setVec4(argument->name, (double*)argument->data);
                break;
            case MAT4: 
                shader.setMat4(argument->name, *((glm::mat4*)argument->data));
                break;
            case SAMPLER:
                glActiveTexture(GL_TEXTURE0);
                ((OpenGLAPI::Texture*)argument->data)->bind();
                shader.setSampler(argument->name, 0);
                break;
        }
    }
    //TODO: CREATE VAO OBJECT
    glBindVertexArray(this->VAO);
    //TODO: CHANGE INDEXES TO MATCH VAO OBJECT INDEXES OR PASS IN INDEXES ON RENDER CALL CREATION
    glDrawArrays(this->mode, 0, 6);
    glBindVertexArray(0);
}
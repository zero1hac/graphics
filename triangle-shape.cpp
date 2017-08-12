#include<stdio.h>
#include<stdlib.h>
#include<GL/glew.h>
#include<GLFW/glfw3.h>

int main(){
    if(!glfwInit()){
        fprintf(stderr, "Failed to initialize GLFW");
        return -1;
    }
    glfwWindowHint(GLFW_SAMPLES, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); 
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window;
    window = glfwCreateWindow( 1024, 768, "Window1", NULL, NULL);
    if( window == NULL ){
            fprintf( stderr, "Failed to open GLFW window.\n" );
                glfwTerminate();
                    return -1;
    }
    glfwMakeContextCurrent(window);
    glewExperimental=true; 
    if (glewInit() != GLEW_OK) {
            fprintf(stderr, "Failed to initialize GLEW\n");
                return -1;
    }
    GLuint VertexArrayID;
    glGenVertexArrays(1, &VertexArrayID);
    glBindVertexArray(VertexArrayID);
    static const GLfloat g_vertex_buffer_data[] = {
           -1.0f, -1.0f, 0.0f,
              1.0f, -1.0f, 0.0f,
                 0.0f,  1.0f, 0.0f,
    };
    GLuint vertexbuffer;
    glGenBuffers(1, &vertexbuffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);
    glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
    do{
        glEnableVertexAttribArray(0);
        glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
        glVertexAttribPointer(
                   0,               
                      3,                  
                         GL_FLOAT,           
                            GL_FALSE,           
                               0,                  
                                  (void*)0            
                );
        glDrawArrays(GL_TRIANGLES, 0, 3); // Starting from vertex 0; 3 vertices total -> 1 triangle
        glDisableVertexAttribArray(0);
        glClear(GL_COLOR_BUFFER_BIT);
         glfwSwapBuffers(window);
         glfwPollEvents();
        }while( glfwGetKey(window, GLFW_KEY_ESCAPE ) != GLFW_PRESS && glfwWindowShouldClose(window) == 0 );
    return 0;
    }
    
    


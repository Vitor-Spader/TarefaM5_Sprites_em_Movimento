#pragma once

//GLM
#include <glm/glm.hpp> 
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <vector>
#include "Shader.h"

class Sprite
{
    public:
    Sprite() {} //Método construtor padrão
    ~Sprite(); //Método destrutor

    void inicializar(vector<GLuint> texID, int nAnimations = 1, int nFrames = 1, glm::vec3 pos=glm::vec3(0), glm::vec3 escala = glm::vec3(1), float angulo = 0.0, glm::vec3 cor = glm::vec3(1.0, 1.0, 0.0), int xLimitMax=0, int yLimitMax=0, int xLimitMin=0, int yLimitMin=0, int moveDefault=100);
    void atualizar(bool changeFrame);
    void desenhar(bool changeFrame);
    void Sprite::moveUp();
    void Sprite::moveDown();
    void Sprite::moveLeft();
    void Sprite::moveRight();

    inline void setShader(Shader *shader) { this->shader = shader; }
    inline void setAngulo(float angulo) { this->angulo = angulo; }
    protected:

    GLuint VAO; //Identificador do buffer de geometria VAO
    vector<GLuint> texIDs; //Coleção de identificadores de textura pos:0 left, pos:1 right
    int currentTexID; // Identificador atual de textura

    //Transformações na geometria
    glm::vec3 pos, escala;
    float angulo;

    //Limites de movimentação do personagem
    int xLimitMax, yLimitMax, xLimitMin, yLimitMin;
    //Quantidade de movimento da imagem
    int moveDefault;

    //Animação por sprite
    int nAnimations, nFrames, iAnimation, iFrame;
    glm::vec2 offsetTex; //ds e dt 

    Shader *shader;

    float lastTime;
    float FPS;
};
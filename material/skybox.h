#pragma once

#include "material/planet.h"

#include <QOpenGLTexture>

class Skybox  : public PlanetMaterial {

public:
    // constructor requires existing shader program
    Skybox(std::shared_ptr<QOpenGLShaderProgram> prog) : PlanetMaterial(prog)
    {

    }

    // bind underlying shader program and set required uniforms
    void apply(unsigned int light_pass = 0) override;

    QMatrix4x4 transformationMatrix;
    QMatrix4x4 projectionMatrix;
    QMatrix4x4 viewMatrix;
    QVector3D lightPosition;

   QVector2D modelTexture;
    QVector3D  lightColour;
    float shineDamper;
     float reflectivity;

};



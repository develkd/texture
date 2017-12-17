#include "skybox.h"

void Skybox::apply(unsigned int light_pass)
{
  prog_->bind();

   PlanetMaterial::apply(light_pass);

   prog_->setUniformValue("transformationMatrix",  transformationMatrix);
   prog_->setUniformValue("projectionMatrix",  projectionMatrix);
   prog_->setUniformValue("viewMatrix", viewMatrix);
   prog_->setUniformValue("lightPosition",  lightPosition);
   prog_->setUniformValue("shineDamper",  shineDamper);
   prog_->setUniformValue("reflectivity",  reflectivity);
}

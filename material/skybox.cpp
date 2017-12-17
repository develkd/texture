#include "skybox.h"

void Skybox::apply(unsigned int light_pass)
{
  prog_->bind();

   PlanetMaterial::apply(light_pass);
}

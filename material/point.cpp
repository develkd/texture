#include "point.h"

void PointMaterial::apply(unsigned int light_pass)
{
   PhongMaterial::apply(light_pass);

}

QString
PointMaterial::getAppliedShader(){
    return "point";
}

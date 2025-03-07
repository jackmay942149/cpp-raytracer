#include "material.h"

float N_Material::shlick(float cos, float refIndx){
    float r0 = (1-refIndx)/(1+refIndx);
    r0 = r0*r0;
    return r0 + (1.0f-r0)*pow((1-cos), 5);
}

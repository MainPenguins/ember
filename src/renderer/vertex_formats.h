#ifndef EMBER_RENDERER_VERTEX_FORMATS_H
#define EMBER_RENDERER_VERTEX_FORMATS_H
#include <cglm/cglm.h>
typedef struct
{
    vec3 pos;
    vec2 uv;
} ember_VertexPU;
typedef struct
{
    vec3 pos;
    vec3 normal;
    vec2 uv;
} ember_VertexPNU;
#endif

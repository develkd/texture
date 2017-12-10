#pragma once

#include <memory> // std::shared_ptr
#include <string>
#include <array>
#include <QOpenGLTexture>


class Cumbemap
{
public:
    Cumbemap();

    std::shared_ptr<QOpenGLTexture>
    makeCubeMap();
};


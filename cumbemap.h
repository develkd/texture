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
    makeCubeMap(std::string path_to_images, std::array<std::string,6> sides =
            {{":/textures/terrain/right.jpg", ":/textures/terrain/top.jpg", ":/textures/terrain/front.jpg", ":/textures/terrain/left.jpg", ":/textures/terrain/bottom.jpg", ":/textures/terrain/back.jpg"}});
};


#include "cumbemap.h"
using namespace std;
Cumbemap::Cumbemap()
{

}


std::shared_ptr<QOpenGLTexture>
Cumbemap::makeCubeMap()
{
       std::array<std::string, 6> sides =
                {{":/textures/terrain/right.jpg", ":/textures/terrain/top.jpg",
                  ":/textures/terrain/front.jpg", ":/textures/terrain/left.jpg",
                  ":/textures/terrain/bottom.jpg", ":/textures/terrain/back.jpg"}};

    // load six images for the six sides of the cube
    std::vector<QImage> images;
    for(auto side : sides) {
        QString filename = ( side).c_str();
        images.push_back( QImage(filename)./*mirrored().*/
                          convertToFormat(QImage::Format_RGBA8888) );
    }

    // create and allocate cube map texture
    std::shared_ptr<QOpenGLTexture> tex_;
    tex_ = std::make_shared<QOpenGLTexture>(QOpenGLTexture::TargetCubeMap);
    tex_->create();
    tex_->setSize(images[0].width(), images[0].height(), images[0].depth());
    tex_->setFormat(QOpenGLTexture::RGBA8_UNorm);
    tex_->allocateStorage();

    // the file names in array sides must match this order of cube faces (!)
    std::array<QOpenGLTexture::CubeMapFace, 6> faces =
        {{QOpenGLTexture::CubeMapPositiveX, QOpenGLTexture::CubeMapPositiveY,
          QOpenGLTexture::CubeMapPositiveZ, QOpenGLTexture::CubeMapNegativeX,
          QOpenGLTexture::CubeMapNegativeY, QOpenGLTexture::CubeMapNegativeZ }};

    // set texture image data for each side
    for(auto i : {0,1,2,3,4,5})
        tex_->setData( 0, 0, faces[i],
                      QOpenGLTexture::RGBA, QOpenGLTexture::UInt8,
                      (const void*)images[i].constBits(), 0 );

    // texture parameters and mip-map generation
    tex_->setWrapMode(QOpenGLTexture::ClampToEdge);
    tex_->setMagnificationFilter(QOpenGLTexture::Linear);
    tex_->setMinificationFilter(QOpenGLTexture::LinearMipMapLinear);
    tex_->generateMipMaps();

    return tex_;
}
